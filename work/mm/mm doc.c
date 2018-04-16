

PDF Documents

        QNX Neutrino RTOS
        Quickstart Guide
        System Architecture Guide
        Standard Support User's Guide
        Priority Support User's Guide

[Previous] 	[Contents] 	[Index] 	[Next]
Caution: 	This version of this document is no longer maintained. For the latest documentation, see http://www.qnx.com/developers/docs.
Using the Multimedia Library

This chapter describes how you can use the Multimedia library to create an application. To see a detailed description of any of the functions mentioned here, see the Multimedia library function reference.

To use the Multimedia library, an application has to do a couple of things:

    Initialize the library and create a graph. A graph is an abstract object that encapsulates the components needed to process a multimedia stream. A graph is stored as a MmGraph_t structure.
    Add the filters required to process the stream to the graph.
    Control the graph to provide the ability to start, stop, pause, and seek within the stream.

In addition:

    Your application may need to get or set resources for a graph, filter, or channel.
    You may wish to link your application statically if your target system has slow disk access or limited memory.
    The examples at the end of this chapter put all these steps together. The examples are:
        Create a graph, add a stream reader, and get its output channel.
        Find a filter for a specific output channel.
        Create a one stream audio playback graph.
        Play MP3s
        Play MPEG System 1

Note: 	Some of the code samples below are from the source code for mmplay, a sample application that's included with the Multimedia TDK.

Let's look at each step in more detail:
Initializing the library and creating a graph

Before you can create your graph and start working with it, you need to initialize the Multimedia library with a call to MmInitialize(). Typically you pass NULL to use the standard multimedia DLLs located in /lib/dll/mmedia. However, if you want to use a different set of filters, you can pass the path to those filters to MmInitialize().

Next, you create a graph using MmCreateGraph(), passing it an arbitrary string to set the graph's ID. This returns a pointer to an opaque MmGraph_t structure that represents your multimedia graph. Make sure your application calls MmDestroyGraph() for each MmCreateGraph() call to clean up any resources associated with the graph.

Once you've created the graph and added filters to it, you need to set the sychronization clock for the Multimedia library by calling MmSetDefaultClock().
Adding filters to the graph

Once you've created a graph, you need to add the filters that will process some multimedia data from the input stream to output. Generally you'll need at least a reader and writer filter, though you'll probably also require filters to parse and or decode the data as well. Filters are connected by channels -- the output channel on one filter connects to the input channel on the next filter in the graph.

How you find the filters you need and attach their channels depends on how much you know about the input stream format, and how flexible you require your application to be.

In the case where your application needs to handle only a single data format, and you know all the filters required for end-to-end processing, you first find a reader filter for the file, and attach it to the graph with MmFindMediaReader(). Then:

    Get the next filter by name and attach it to the graph with MmFindFilter().
    Get the output channel for the reader filter with MmAcquireOutputChannel() and the input channel for the next filter with MmAcquireInputChannel().
    Connect the two channels with MmAttachChannels().
    Repeat these steps until you've attached the input channel for the writer filter.

In the example of the MP3 player below, we know that the file format requires a file reader, Mpeg audio parser (mpega_parser.so), Xing Mpeg audio decoder (xing_mpega_decoder.so), and an audio writer.

In the case where your application should handle more than one media format (for example, an audio player that can play MP3 and WAV files), you build your graph a bit differently. You first find a reader filter for the file, and attach it to the graph with MmFindMediaReader(). Then:

    Get an output channel from the filter with MmAcquireOutputChannel().
    Get the filter that has the best rating for the output channel with MmFindChannelsFilter(). This function finds the best-rated filter for an output channel, creates its input channel, attaches the two channels, and returns the filter.
    Repeat these steps until you've connected a writer filter.

See Example 3 for an example of using this approach. Another example is the graph-creation function for mmplay, which can handle all the media formats supported by the Multimedia library.
Note: 	If you create your graph this way, and link your application dynamically, your application will be able to use any of the filters in the Multimedia library directory, which is /lib/dll/mmedia by default. If you link your application statically (see below), it will be able to use only the filters built into the application at compile time.

If your application acquires a channel but for some reason can't use it (and you want to continue building the graph), you should release it with MmReleaseChannel(), as illustrated in this example from mmplay:

if( (sc=MmAcquireOutputChannel(sf,MEDIA_TYPE_COMPRESSED|MEDIA_TYPE_UNKNOWN)))
{
    MmFilter_t *tsf;
    if( !(tsf=MmFindChannelsFilter(graph,sc)) )
    {
        //printf("Couldn't find filter for compressed stream.\n");
        MmReleaseChannel(sc);
    }
    else
        sf=tsf;
}

Similarly, if you create a filter that the application won't use (and you want to continue to build the graph), you should destroy it with MmDestroyFilter(), as illustrated in this example from mmplay:

// if we failed to connect the audio output, destroy the
// audio_writer filter instance. (Otherwise it'll still be used.)
if( !mmplay.audioout )
{
    if( asc )
        MmReleaseChannel(asc);
    if( asf )
    MmDestroyFilter(asf);
    if( df )
        MmDestroyFilter(df);
}

Working with graphs

Once you've created the graph, added all the required filters, and connected them with channels, your application can start to control the multimedia playback. These are the Multimedia library functions that control graph playback:

    MmStart()
    MmStop()
    MmPause()
    MmResume()
    MmSeek()
    MmStatus()

Your application should call MmStart() once, after the graph is created and you want to start playback. Likewise, your application calls MmStop() once for a graph, before you call MmDestroyGraph() to destroy the graph and release its resources. MmStart() starts the graph in a paused state, so you need to call MmResume() to begin playback.

After the graph is playing, use MmPause(), MmSeek() and MmResume() to pause, change the playback time, and resume playback. For example, to "stop" playback, you could do something like this:

MmPause( graph );
MmSeek( graph, 0 );

Use MmStatus() to determine the status of a graph or filter. The most common use is to deterimine whether the graph has finished playing the input stream, in which case the status returned is MM_STATUS_EOF.
Getting information about a graph, filter, or channel

Use these functions to manipulate a graph's resources:

    MmGetResourceValue()
    MmSetResourceValue()

Every filter in a graph has a set of resources. When you call MmGetResourceValue() (or one of the convenience macros, such as MmGetResourceINT32()) on a filter, you get the value for that resource, if it exists. If you call these functions on a graph, the last filter in the graph is queried for the resource, and if it has the resource, the value is returned. If not, the next filter in the graph is queried.

Some resources are read-only, while others can be set by the application with MmSetResourceValue().

QNX-provided filters have these resources:

Common:

    Duration -- int64_t value containing the duration in nanoseconds. Read-only.
    Position -- int64_t value containing the current position in nanoseconds. Read-only.

Audio writer:

    Volume -- int32_t value containing the volume, from 0 to 100. Read / write.
    Balance -- int32_t value containing the balance, from 0 to 100 (50 is "normal"). Read / write.

MPEG audio parser:

    IcyInfo -- a string containing any icecast embedded information (streaming audio information). Read-only.
    ID3 -- an ID3 tag structure containing any ID3 embedded information. Read-only.

Video writer:

    Width -- int32_t value containing the width of a video or image. Read-only.
    Height -- int32_t value containing the height of a video or image. Read-only.
    DisplayArea -- PhArea_t * value containing the current video widget position and dimension. Read / write.

CDDA reader:

    TracksCount -- int32_t value containing the number of tracks a media stream contains. Read-only.
    Tracks -- int32_t value containing the number of the current track. Read / write.
    CDDA_MILLISECONDS -- int32_t value containing the amount of read-ahead buffer the CDDA reader is using. This value can be between 300 milliseconds and 1 minute. Read / write.
    Error -- string value containing an error message. Read-only.

Miscellaneous functions

Use MmPrintGraph() to print a graph and all its filters to the display. This function is useful for debugging an application.
Linking an application statically

In general, dynamically linking an application has many benefits, including the ability to upgrade DLLs later without having to relink the application, and reduced memory footprint (provided that you unload the DLLs when you don't need them). In an embedded system where disk access is slow, however, you may find that statically linking an application against the Multimedia library is a better choice. This is because the library searches the DLL directory (by default /lib/dll/mmedia) and loads, queries, and unloads every DLL it finds. It does the same thing each time a new graph is constructed using MmFindChannelsFilter(). In addition, you avoid the additional memory overhead required for each dynamically loaded DLL, which can add up when you load several DLLs.
Note: 	If you want to link your application dynamically, you can also reduce its startup time by putting only the DLLs it requires into the Multimedia library directory.

If your application is linked statically, all the DLLs are loaded into memory, and the application never needs to read from the disk to query them after startup.

To link your multimedia application statically, you need to follow these steps:

    In your makefile (common.mk), add these settings:

    LIBS += stream_reader   xing_mpega_decoder mpega_parser wav_parser\
    audio_writer fildes_streamer http_streamer  other_filters... \
    mmedia mmconvenienceS mmedia aoi  m  asound socket

    LIBPREF_mmedia= -Bstatic
    LIBPOST_mmedia= -Bdynamic

    This links the Multimedia filters statically.
    Declare the external filters in your application source code. For example:

      extern AOInterface_t stream_reader_interfaces[];
      extern AOInterface_t ogg_decoder_interfaces[];
      extern AOInterface_t xing_mpega_decoder_interfaces[];
      extern AOInterface_t mpega_parser_interfaces[];
      extern AOInterface_t wav_parser_interfaces[];
      extern AOInterface_t audio_writer_interfaces[];
      extern AOInterface_t http_interfaces[];
      extern AOInterface_t fildes_interfaces[];
      

    Note that the names of the filters have a _interfaces[] added.
    In your application's main() function, call AoAddStatic() for each imported filter to add its interfaces statically. For example:

        AoAddStatic(stream_reader_interfaces);
        AoAddStatic(mpega_parser_interfaces);
        AoAddStatic(wav_parser_interfaces);
        AoAddStatic(xing_mpega_decoder_interfaces);
        AoAddStatic(ogg_decoder_interfaces);
        AoAddStatic(audio_writer_interfaces);
        AoAddStatic(fildes_interfaces);
        AoAddStatic(http_interfaces);
      

The Multimedia Framework TDK ships with several sample applications. You can look at the playaudio example to see an application that is linked statically. 
