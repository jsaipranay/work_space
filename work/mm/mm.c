xamples of using the Multimedia library

This section contains code examples of using the Multimedia library.
Example 1: Initializing the Multimedia library, and creating a new multimedia graph



#include <aoi/aoi.h>
...
 // initialize the Multimedia library using default addon paths
MmInitialize(NULL);

 // create a new graph context
graph=MmCreateGraph("sample app");
...
 // Creating a filter for a given stream:
 // (assuming the multimedia has already been initialized, and a graph created.)

MmFilter_t *create_filter_for_stream(MmGraph_t *graph, AOIStream_t *stream)
{
         MmFilter_t *sf;
         MmFilter_t *df;
         MmChannel_t *sc;

         // Find the media reader to use with the stream
         // (usually turns out to be stream_reader)
         if (!(sf=MmFindMediaReader(graph, stream))) return 0;

         // Now grab a compressed output channel from the
         // stream_reader filter. (It always assumes it's
         // compressed, because it doesn't know anything
         // about the filter.)
         if (!(sc=MmAcquireOutputChannel(sf, MEDIA_TYPE_COMPRESSED)))
         {
                  MmDestroyFilter(sf);
                  return 0;
         }
         // Finally, find the best filter that can attach one
         // of its input channels to our output channel.
         if (!(df=MmFindChannelsFilter(graph, sc)))
         {
                  MmReleaseChannel(sc);
                  MmDestroyFilter(sf);
                  return 0;
         }
         return df;
}
*************************************************************************************
Example 2: Creating a filter for a given channel

This example assumes the Multimedia library is initialized, and a graph exists.

This task is easier than creating a filter for a given stream, since you skip the MmFindMediaReader() call. The simple approach is to call MmFindChannelsFilter() directly.

MmFilter_t *create_filter_for_channel(MmGraph_t *graph,
                                      MmChannel_t *channel)
{
         MmFilter_t *df;

         // Find the best filter that can attach one of its
         // input channels to our output channel.

         if (!(df=MmFindChannelsFilter(graph,channel)))
            return 0;

         return df;
}
********************************************************************************************


Example 3: Creating a one-stream audio playback graph

In this example, the input is some type of compressed audio file, and the output is an audio device.

Start with a stream reader, and go from most complex (unknown compressed) to less complex (audio compressed), to least complex (raw audio). You put each complexity level in a loop to catch any multilevel complexity decoding.

MmGraph_t *create_graph_for_compressed_audio_stream(AOIStream_t *stream)
{
        MmGraph_t *graph;
        MmFilter_t *nf;
        MmChannel_t *sc;

        if (!(graph=MmCreateGraph("Audio Player")))
                return 0;

        if (!(sf=MmFindMediaReader(graph,stream)))
        {
                MmDestroyGraph(graph);
                return 0;
        }

        // connect compressed unknown channels
        while (sc=MmAcquireOutputChannel(sf,MEDIA_TYPE_COMPRESSED))
        {
                MmFilter_t *nf;

                // if we cannot find a filter for the channel,
                // release it, and break out of the loop.
                if (!(nf=MmFindChannelsFilter(graph,sc)))
                {
                        MmReleaseChannel(sc);
                        break;
                }
                sf=nf;
        }

        // connect compressed audio channels
        while (sc=MmAcquireOutputChannel(sf, MEDIA_TYPE_COMPRESSED|MEDIA_TYPE_AUDIO))
        {
                MmFilter_t *nf;

                if (!(nf=MmFindChannelsFilter(graph,sc)))
                {
                        MmReleaseChannel(sc);
                        break;
                }
                sf=nf;
        }

        // connect uncompressed audio channels
        while (sc=MmAcquireOutputChannel(sf,MEDIA_TYPE_AUDIO))
        {
                MmFilter_t *nf;

                if (!(nf=MmFindChannelsFilter(graph,sc)))
                {
                        MmReleaseChannel(sc);
                        break;
                }
                sf=nf;
        }

        // return the graph
        return graph;
}


********************************************************************

xample 4: Playing MP3s

This example shows the complete code for running an MP3.

The graph created in this example looks like this: 


MP3 Graph.

#include <stdio.h>
#include <mmedia/mmedia.h>

int main(int argc,char *argv[])
{
    AOIStream_t *file;
    MmGraph_t *graph;
    MmFilter_t *rf,*mpf,*xf,*af;
    MmChannel_t *rc,*mpic,*mpoc,*xic,*xoc,*ac;

    // make sure we have one argument
    if (argc!=2)
    {
        printf("Usage: playmp3 <mp3 file>\n");
        exit(-1);
    }

    // initialize the Multimedia library
    MmInitialize(NULL);

    // open the streamer
    if (!(file=AoOpenFilespec(argv[1],"rb")))
    {
        printf("Unable to open '%s'.\n",argv[1]);
        exit(-2);
    }

    graph=MmCreateGraph("mp3 player");

    // we should always be able to find the MediaReader filter
    if (!(rf=MmFindMediaReader(graph,file)))
    {
        printf("Couldn't find the MediaReader filter.\n");
        MmDestroyGraph(graph);
        exit(-3);
    }

    // grab the compressed output chaExample 5: Playing MPEG-1 System

This example builds a graph specific to an MPEG-1 System stream, and plays the video on a Photon window. It adds a callback to the window to handle any movement or resize events.

#include <stdlib.h>
#include <stdio.h>
#include <mmedia/mmedia.h>
#include <Pt.h>

#define EVENT_SIZE (sizeof(PhEvent_t)+1000)

int OnWindowEvent(PtWidget_t *window, void *data, PtCallbackInfo_t *cbinfo) {

    // When the window moves, the window_writer filter needs
    // to be updated - otherwise the video won't resize or
    // move.

    PhArea_t rarea;
    short winx,winy;
    MmFilter_t *win_writer = (MmFilter_t*)data;
    PhWindowEvent_t *wev=(PhWindowEvent_t*)cbinfo->cbdata;
    PhDim_t *odim;

    PtGetResource(window,Pt_ARG_DIM,&odim,0);
    PtGetResource(window,Pt_ARG_AREA,&rarea,0);
    PtGetAbsPosition(window,&winx,&winy);

    rarea.pos.x=winx;
    rarea.pos.y=winy;
    rarea.size.w=odim->w;
    rarea.size.h=odim->h;
    MmSetResourceValue(win_writer,"DisplayArea", &rarea);


  return( Pt_CONTINUE );
}

int main(int argc,char *argv[])
{
    AOIStream_t *file;
    MmGraph_t *graph;
    MmFilter_t *media_reader,*mpegs_parser,*mpv_decoder,*win_writer, *mpa_decoder,
      *audio_writer;
    MmChannel_t *mr_out,*mps_in,*mpsv_out,*mpv_in,*mpv_out,*win_in, *mpsa_out,
      *mpa_in, *mpa_out, *audio_in;
    int32_t width, height;
    PhEvent_t *event;


   PtWidget_t *window;
   PtArg_t    args[3];

    // make sure we have one argument
    if (argc!=2)
    {
        printf("Usage: mpeg_play <mpeg file>\n");
        exit(-1);
    }

    // initialize the Multimedia library
    MmInitialize(NULL);

    // open the streamer
    if (!(file=AoOpenFilespec(argv[1],"rb")))
    {
        printf("Unable to open '%s'.\n",argv[1]);
        exit(-2);
    }

    graph=MmCreateGraph("mpeg player");

    // we should always be able to find the MediaReader filter
    if (!(media_reader=MmFindMediaReader(graph,file)))
    {
        printf("Couldn't find the MediaReader filter.\n");
        MmDestroyGraph(graph);
        exit(-3);
    }

    // Get the MPEG system parser
    if (!(mpegs_parser=MmFindFilter(graph,"mpegs_parser")))
    {
        printf("Couldn't get the mpeg system parser.\n");
        MmDestroyGraph(graph);
        exit(-4);
    }

    // Get the reader output channel
    if (!(mr_out=MmAcquireOutputChannel(media_reader,MEDIA_TYPE_COMPRESSED)))
    {
        printf("Couldn't get an  output channel from MediaReader.\n");
        MmDestroyGraph(graph);
        exit(-5);
    }

        // Get the mpeg system parser's input channel
    if (!(mps_in=MmAcquireInputChannel(mpegs_parser,MEDIA_TYPE_UNKNOWN)))
    {
        printf("Couldn't get a compressed input channel from mpega_parser.\n");
        MmDestroyGraph(graph);
        exit(-4);
    }

      // connect the two channels
    if (MmAttachChannels(mr_out,mps_in)!=0)
    {
        printf("Couldn't attach MediaReader and mpegs_parser channels.\n");
        MmDestroyGraph(graph);
        exit(-5);
    }

        // get the MPEG video decoder
    if (!(mpv_decoder=MmFindFilter(graph,"ff_mpegv_decoder")))
    {
        printf("Couldn't grab the mpeg video decoder.\n");
        MmDestroyGraph(graph);
        exit(-6);
    }

        // Get the parser output channel
    if (!(mpsv_out=MmAcquireOutputChannel(mpegs_parser,MEDIA_TYPE_COMPRESSED|MEDIA_TYPE_VIDEO)))
    {
        printf("Couldn't get a compressed output channel from MPEG system parser.\n");
        if (!(mpsv_out=MmAcquireOutputChannel(mpegs_parser,MEDIA_TYPE_VIDEO)))
        {
            printf("Couldn't get an uncompressed output channel from MPEG system parser either.\n");
            MmDestroyGraph(graph);
            exit(-7);
        }
    }

        // Get the mpeg video decoder's  input channel
    if (!(mpv_in=MmAcquireInputChannel(mpv_decoder,MEDIA_TYPE_VIDEO)))
    {
        printf("Couldn't get a input channel from mpegv_decoder.\n");
        MmDestroyGraph(graph);
        exit(-8);
    }

      // connect the two channels
    if (MmAttachChannels(mpsv_out,mpv_in)!=0)
    {
        printf("Couldn't attach MediaReader and mpega_parser channels.\n");
        MmDestroyGraph(graph);
        exit(-9);
    }


    // find the video writer filter and channel, and attach the two channels
    if (PtInit("/dev/photon")!=0){
        printf("Error: couldn't connect to photon\n");
        PtExit(EXIT_FAILURE);
    }
    if( !(win_writer=MmFindFilter(graph,"window_writer")) )
    {
        printf("Couldn't find video_writer.\n");
        MmDestroyGraph(graph);
        exit(-10);

    }
    // Create a window for the win_writer
    // we just use an arbitrary size, but you could
    // query the video for the right size to use

    PtSetArg(&args[0], Pt_ARG_HEIGHT, 200, 0);
    PtSetArg(&args[1], Pt_ARG_WIDTH, 300, 0);
    PtSetArg(&args[2], Pt_ARG_WINDOW_NOTIFY_FLAGS, Ph_WM_RESIZE|Ph_WM_MOVE,
        Ph_WM_RESIZE|Ph_WM_MOVE);
    window = PtCreateWidget(PtWindow, Pt_NO_PARENT, 3, args);

    // this callback handles resize and move:
    PtAddCallback(window, Pt_CB_WINDOW, OnWindowEvent, win_writer);
    PtRealizeWidget(window);


    MmSetResourceValue(win_writer, "PtWidget_t", window);

    if( !(win_in=MmAcquireInputChannel(win_writer,MEDIA_TYPE_VIDEO)) )
    {
        printf("Couldn't get video_writer's input channel.\n");
        MmDestroyGraph(graph);
        exit(-10);
    }

    if( !(mpv_out=MmAcquireOutputChannel(mpv_decoder,MEDIA_TYPE_VIDEO)) )
    {
        printf("Couldn't get video_decoder's output channel.\n");
        MmDestroyGraph(graph);
        exit(-10);
    }

    if( MmAttachChannels(mpv_out,win_in) != 0 )
    {
        printf("Couldn't attach to video_writer's input channel.\n");
        MmDestroyGraph(graph);
        exit(-10);
    }

    // Get the mpeg system parser audio output channel
    if (!(mpsa_out=MmAcquireOutputChannel(mpegs_parser,MEDIA_TYPE_COMPRESSED|MEDIA_TYPE_AUDIO)))
    {
        printf("Couldn't get an audio output channel from MPEG system parser.\n");
        MmDestroyGraph(graph);
        exit(-7);
    }

        // grab the mpeg audio decoder
    if (!(mpa_decoder=MmFindFilter(graph,"xing_mpega_decoder")))
    {
        printf("Couldn't grab the xing mpeg audio decoder.\n");
        MmDestroyGraph(graph);
        exit(-7);
    }

    // grab the mpeg audio decoder input channel
    if (!(mpa_in=MmAcquireInputChannel(mpa_decoder,MEDIA_TYPE_COMPRESSED|MEDIA_TYPE_AUDIO)))
    {
        printf("Couldn't get a compressed input channel from xing_mpega_decoder.\n");
        MmDestroyGraph(graph);
        exit(-8);
    }

    // connect the two channels
    if (MmAttachChannels(mpsa_out,mpa_in)!=0)
    {
        printf("Couldn't attach system parser and mpega_parser channels.\n");
        MmDestroyGraph(graph);
        exit(-5);
    }

    // grab the xing_mpega_decoder filter output channel
    if (!(mpa_out=MmAcquireOutputChannel(mpa_decoder,MEDIA_TYPE_AUDIO)))
    {
        printf("Couldn't get a audio output channel from xing_mpega_decoder.\n");
        MmDestroyGraph(graph);
        exit(-10);
    }

    // grab the audio_writer filter
    if (!(audio_writer=MmFindFilter(graph,"audio_writer")))
    {
        printf("Couldn't grab the audio_writer filter.\n");
        MmDestroyGraph(graph);
        exit(-11);
    }

    // grab the audio input channel
    if (!(audio_in=MmAcquireInputChannel(audio_writer,MEDIA_TYPE_AUDIO)))
    {
        printf("Couldn't get an audio input channel from audio_writer.\n");
        MmDestroyGraph(graph);
        exit(-12);
    }

    // connect the two channels
    if (MmAttachChannels(mpa_out,audio_in)!=0)
    {
        printf("Couldn't attach xing_mpega_decoder and audio_writer channels.\n");
        MmDestroyGraph(graph);
        exit(-13);
    }

    // set our default clock
    MmSetDefaultClock(graph);

    // print graph, starting at reader
    MmPrintGraph(media_reader,0);

    // start the graph playing
    MmStart(graph,0);
    MmResume(graph);

    // We're not using PtMainLoop(), because then we wouldn't know
    // when to stop the app and destroy the graph
    // Instead we do our own loop:

    event = malloc(EVENT_SIZE);

    while (MmStatus(graph)==MM_STATUS_PLAYING) {

        switch (PhEventPeek(event, EVENT_SIZE)){
            case Ph_EVENT_MSG:
                PtEventHandler(event);
                break;
            case 0:
                // give the video filter a chance to render:
                PtLeave(Pt_EVENT_PROCESS_PREVENT);
                delay(500);
                PtEnter(Pt_EVENT_PROCESS_PREVENT);
                PgFlush();
                break;

            case -1:
                printf("Ack! error.\n");
                exit(0);
                break;

        }
    }

    free(event);

    // stop and destroy the graph
    MmStop(graph);
    printf("Done playing, destroying the graph.\n");
    MmDestroyGraph(graph);

    // close the input streamer
    file->streamer->Close(file);

    return (EXIT_SUCCESS);

}nnel
    if (!(rc=MmAcquireOutputChannel(rf,MEDIA_TYPE_COMPRESSED)))
    {
        printf("Couldn't get a compressed output channel from MediaReader.\n");
        MmDestroyGraph(graph);
        exit(-4);
    }

    // grab the mpeg audio parser
    if (!(mpf=MmFindFilter(graph,"mpega_parser")))
    {
        printf("Couldn't grab the mpeg audio parser.\n");
        MmDestroyGraph(graph);
        exit(-5);
    }

    // grab the mpeg audio parsers input channel
    if (!(mpic=MmAcquireInputChannel(mpf,MEDIA_TYPE_COMPRESSED)))
    {
        printf("Couldn't get a compressed input channel from mpega_parser.\n");
        MmDestroyGraph(graph);
        exit(-4);
    }

    // connect the two channels
    if (MmAttachChannels(rc,mpic)!=0)
    {
        printf("Couldn't attach MediaReader and mpega_parser channels.\n");
        MmDestroyGraph(graph);
        exit(-5);
    }

    // grab the mpega_parser filter output channel
    if (!(mpoc=MmAcquireOutputChannel(mpf,MEDIA_TYPE_COMPRESSED|MEDIA_TYPE_AUDIO)))
    {
        printf("Couldn't get a compressed audio output channel from mpega_parser.\n");
        MmDestroyGraph(graph);
        exit(-6);
    }

    // grab the mpeg audio decoder
    if (!(xf=MmFindFilter(graph,"xing_mpega_decoder")))
    {
        printf("Couldn't grab the xing mpeg audio decoder.\n");
        MmDestroyGraph(graph);
        exit(-7);
    }

    // grab the mpeg audio decoder input channel
    if (!(xic=MmAcquireInputChannel(xf,MEDIA_TYPE_COMPRESSED|MEDIA_TYPE_AUDIO)))
    {
        printf("Couldn't get a compressed input channel from xing_mpega_decoder.\n");
        MmDestroyGraph(graph);
        exit(-8);
    }

    // connect the two channels
    if (MmAttachChannels(mpoc,xic)!=0)
    {
        printf("Couldn't attach mpega_parser and xing_mpega_decoder channels.\n");
        MmDestroyGraph(graph);
        exit(-9);
    }

    // grab the xing_mpega_decoder filter output channel
    if (!(xoc=MmAcquireOutputChannel(xf,MEDIA_TYPE_AUDIO)))
    {
        printf("Couldn't get a audio output channel from xing_mpega_decoder.\n");
        MmDestroyGraph(graph);
        exit(-10);
    }

    // grab the audio_writer filter
    if (!(af=MmFindFilter(graph,"audio_writer")))
    {
        printf("Couldn't grab the audio_writer filter.\n");
        MmDestroyGraph(graph);
        exit(-11);
    }

    // grab the audio input channel
    if (!(ac=MmAcquireInputChannel(af,MEDIA_TYPE_AUDIO)))
    {
        printf("Couldn't get an audio input channel from audio_writer.\n");
        MmDestroyGraph(graph);
        exit(-12);
    }

    // connect the two channels
    if (MmAttachChannels(xoc,ac)!=0)
    {
        printf("Couldn't attach xing_mpega_decoder and audio_writer channels.\n");
        MmDestroyGraph(graph);
        exit(-13);
    }

    // set our default clock
    MmSetDefaultClock(graph);

    // start the graph playing
    MmStart(graph,0);
    MmResume(graph);

    // wait for the graph to finish playing
    while (MmStatus(graph)==MM_STATUS_PLAYING) delay(500);

    // stop destroy the graph
    MmStop(graph);
    MmDestroyGraph(graph);

    // close the input streamer
    file->streamer->Close(file);

    return 0;
}


*****************************************************************




Example 5: Playing MPEG-1 System

This example builds a graph specific to an MPEG-1 System stream, and plays the video on a Photon window. It adds a callback to the window to handle any movement or resize events.

#include <stdlib.h>
#include <stdio.h>
#include <mmedia/mmedia.h>
#include <Pt.h>

#define EVENT_SIZE (sizeof(PhEvent_t)+1000)

int OnWindowEvent(PtWidget_t *window, void *data, PtCallbackInfo_t *cbinfo) {

    // When the window moves, the window_writer filter needs
    // to be updated - otherwise the video won't resize or
    // move.

    PhArea_t rarea;
    short winx,winy;
    MmFilter_t *win_writer = (MmFilter_t*)data;
    PhWindowEvent_t *wev=(PhWindowEvent_t*)cbinfo->cbdata;
    PhDim_t *odim;

    PtGetResource(window,Pt_ARG_DIM,&odim,0);
    PtGetResource(window,Pt_ARG_AREA,&rarea,0);
    PtGetAbsPosition(window,&winx,&winy);

    rarea.pos.x=winx;
    rarea.pos.y=winy;
    rarea.size.w=odim->w;
    rarea.size.h=odim->h;
    MmSetResourceValue(win_writer,"DisplayArea", &rarea);


  return( Pt_CONTINUE );
}

int main(int argc,char *argv[])
{
    AOIStream_t *file;
    MmGraph_t *graph;
    MmFilter_t *media_reader,*mpegs_parser,*mpv_decoder,*win_writer, *mpa_decoder,
      *audio_writer;
    MmChannel_t *mr_out,*mps_in,*mpsv_out,*mpv_in,*mpv_out,*win_in, *mpsa_out,
      *mpa_in, *mpa_out, *audio_in;
    int32_t width, height;
    PhEvent_t *event;


   PtWidget_t *window;
   PtArg_t    args[3];

    // make sure we have one argument
    if (argc!=2)
    {
        printf("Usage: mpeg_play <mpeg file>\n");
        exit(-1);
    }

    // initialize the Multimedia library
    MmInitialize(NULL);

    // open the streamer
    if (!(file=AoOpenFilespec(argv[1],"rb")))
    {
        printf("Unable to open '%s'.\n",argv[1]);
        exit(-2);
    }

    graph=MmCreateGraph("mpeg player");

    // we should always be able to find the MediaReader filter
    if (!(media_reader=MmFindMediaReader(graph,file)))
    {
        printf("Couldn't find the MediaReader filter.\n");
        MmDestroyGraph(graph);
        exit(-3);
    }

    // Get the MPEG system parser
    if (!(mpegs_parser=MmFindFilter(graph,"mpegs_parser")))
    {
        printf("Couldn't get the mpeg system parser.\n");
        MmDestroyGraph(graph);
        exit(-4);
    }

    // Get the reader output channel
    if (!(mr_out=MmAcquireOutputChannel(media_reader,MEDIA_TYPE_COMPRESSED)))
    {
        printf("Couldn't get an  output channel from MediaReader.\n");
        MmDestroyGraph(graph);
        exit(-5);
    }

        // Get the mpeg system parser's input channel
    if (!(mps_in=MmAcquireInputChannel(mpegs_parser,MEDIA_TYPE_UNKNOWN)))
    {
        printf("Couldn't get a compressed input channel from mpega_parser.\n");
        MmDestroyGraph(graph);
        exit(-4);
    }

      // connect the two channels
    if (MmAttachChannels(mr_out,mps_in)!=0)
    {
        printf("Couldn't attach MediaReader and mpegs_parser channels.\n");
        MmDestroyGraph(graph);
        exit(-5);
    }

        // get the MPEG video decoder
    if (!(mpv_decoder=MmFindFilter(graph,"ff_mpegv_decoder")))
    {
        printf("Couldn't grab the mpeg video decoder.\n");
        MmDestroyGraph(graph);
        exit(-6);
    }

        // Get the parser output channel
    if (!(mpsv_out=MmAcquireOutputChannel(mpegs_parser,MEDIA_TYPE_COMPRESSED|MEDIA_TYPE_VIDEO)))
    {
        printf("Couldn't get a compressed output channel from MPEG system parser.\n");
        if (!(mpsv_out=MmAcquireOutputChannel(mpegs_parser,MEDIA_TYPE_VIDEO)))
        {
            printf("Couldn't get an uncompressed output channel from MPEG system parser either.\n");
            MmDestroyGraph(graph);
            exit(-7);
        }
    }

        // Get the mpeg video decoder's  input channel
    if (!(mpv_in=MmAcquireInputChannel(mpv_decoder,MEDIA_TYPE_VIDEO)))
    {
        printf("Couldn't get a input channel from mpegv_decoder.\n");
        MmDestroyGraph(graph);
        exit(-8);
    }

      // connect the two channels
    if (MmAttachChannels(mpsv_out,mpv_in)!=0)
    {
        printf("Couldn't attach MediaReader and mpega_parser channels.\n");
        MmDestroyGraph(graph);
        exit(-9);
    }


    // find the video writer filter and channel, and attach the two channels
    if (PtInit("/dev/photon")!=0){
        printf("Error: couldn't connect to photon\n");
        PtExit(EXIT_FAILURE);
    }
    if( !(win_writer=MmFindFilter(graph,"window_writer")) )
    {
        printf("Couldn't find video_writer.\n");
        MmDestroyGraph(graph);
        exit(-10);

    }
    // Create a window for the win_writer
    // we just use an arbitrary size,Example 5: Playing MPEG-1 System

This example builds a graph specific to an MPEG-1 System stream, and plays the video on a Photon window. It adds a callback to the window to handle any movement or resize events.

#include <stdlib.h>
#include <stdio.h>
#include <mmedia/mmedia.h>
#include <Pt.h>

#define EVENT_SIZE (sizeof(PhEvent_t)+1000)

int OnWindowEvent(PtWidget_t *window, void *data, PtCallbackInfo_t *cbinfo) {

    // When the window moves, the window_writer filter needs
    // to be updated - otherwise the video won't resize or
    // move.

    PhArea_t rarea;
    short winx,winy;
    MmFilter_t *win_writer = (MmFilter_t*)data;
    PhWindowEvent_t *wev=(PhWindowEvent_t*)cbinfo->cbdata;
    PhDim_t *odim;

    PtGetResource(window,Pt_ARG_DIM,&odim,0);
    PtGetResource(window,Pt_ARG_AREA,&rarea,0);
    PtGetAbsPosition(window,&winx,&winy);

    rarea.pos.x=winx;
    rarea.pos.y=winy;
    rarea.size.w=odim->w;
    rarea.size.h=odim->h;
    MmSetResourceValue(win_writer,"DisplayArea", &rarea);


  return( Pt_CONTINUE );
}

int main(int argc,char *argv[])
{
    AOIStream_t *file;
    MmGraph_t *graph;
    MmFilter_t *media_reader,*mpegs_parser,*mpv_decoder,*win_writer, *mpa_decoder,
      *audio_writer;
    MmChannel_t *mr_out,*mps_in,*mpsv_out,*mpv_in,*mpv_out,*win_in, *mpsa_out,
      *mpa_in, *mpa_out, *audio_in;
    int32_t width, height;
    PhEvent_t *event;


   PtWidget_t *window;
   PtArg_t    args[3];

    // make sure we have one argument
    if (argc!=2)
    {
        printf("Usage: mpeg_play <mpeg file>\n");
        exit(-1);
    }

    // initialize the Multimedia library
    MmInitialize(NULL);

    // open the streamer
    if (!(file=AoOpenFilespec(argv[1],"rb")))
    {
        printf("Unable to open '%s'.\n",argv[1]);
        exit(-2);
    }

    graph=MmCreateGraph("mpeg player");

    // we should always be able to find the MediaReader filter
    if (!(media_reader=MmFindMediaReader(graph,file)))
    {
        printf("Couldn't find the MediaReader filter.\n");
        MmDestroyGraph(graph);
        exit(-3);
    }

    // Get the MPEG system parser
    if (!(mpegs_parser=MmFindFilter(graph,"mpegs_parser")))
    {
        printf("Couldn't get the mpeg system parser.\n");
        MmDestroyGraph(graph);
        exit(-4);
    }

    // Get the reader output channel
    if (!(mr_out=MmAcquireOutputChannel(media_reader,MEDIA_TYPE_COMPRESSED)))
    {
        printf("Couldn't get an  output channel from MediaReader.\n");
        MmDestroyGraph(graph);
        exit(-5);
    }

        // Get the mpeg system parser's input channel
    if (!(mps_in=MmAcquireInputChannel(mpegs_parser,MEDIA_TYPE_UNKNOWN)))
    {
        printf("Couldn't get a compressed input channel from mpega_parser.\n");
        MmDestroyGraph(graph);
        exit(-4);
    }

      // connect the two channels
    if (MmAttachChannels(mr_out,mps_in)!=0)
    {
        printf("Couldn't attach MediaReader and mpegs_parser channels.\n");
        MmDestroyGraph(graph);
        exit(-5);
    }

        // get the MPEG video decoder
    if (!(mpv_decoder=MmFindFilter(graph,"ff_mpegv_decoder")))
    {
        printf("Couldn't grab the mpeg video decoder.\n");
        MmDestroyGraph(graph);
        exit(-6);
    }

        // Get the parser output channel
    if (!(mpsv_out=MmAcquireOutputChannel(mpegs_parser,MEDIA_TYPE_COMPRESSED|MEDIA_TYPE_VIDEO)))
    {
        printf("Couldn't get a compressed output channel from MPEG system parser.\n");
        if (!(mpsv_out=MmAcquireOutputChannel(mpegs_parser,MEDIA_TYPE_VIDEO)))
        {
            printf("Couldn't get an uncompressed output channel from MPEG system parser either.\n");
            MmDestroyGraph(graph);
            exit(-7);
        }
    }

        // Get the mpeg video decoder's  input channel
    if (!(mpv_in=MmAcquireInputChannel(mpv_decoder,MEDIA_TYPE_VIDEO)))
    {
        printf("Couldn't get a input channel from mpegv_decoder.\n");
        MmDestroyGraph(graph);
        exit(-8);
    }

      // connect the two channels
    if (MmAttachChannels(mpsv_out,mpv_in)!=0)
    {
        printf("Couldn't attach MediaReader and mpega_parser channels.\n");
        MmDestroyGraph(graph);
        exit(-9);
    }


    // find the video writer filter and channel, and attach the two channels
    if (PtInit("/dev/photon")!=0){
        printf("Error: couldn't connect to photon\n");
        PtExit(EXIT_FAILURE);
    }
    if( !(win_writer=MmFindFilter(graph,"window_writer")) )
    {
        printf("Couldn't find video_writer.\n");
        MmDestroyGraph(graph);
        exit(-10);

    }
    // Create a window for the win_writer
    // we just use an arbitrary size, but you could
    // query the video for the right size to use

    PtSetArg(&args[0], Pt_ARG_HEIGHT, 200, 0);
    PtSetArg(&args[1], Pt_ARG_WIDTH, 300, 0);
    PtSetArg(&args[2], Pt_ARG_WINDOW_NOTIFY_FLAGS, Ph_WM_RESIZE|Ph_WM_MOVE,
        Ph_WM_RESIZE|Ph_WM_MOVE);
    window = PtCreateWidget(PtWindow, Pt_NO_PARENT, 3, args);

    // this callback handles resize and move:
    PtAddCallback(window, Pt_CB_WINDOW, OnWindowEvent, win_writer);
    PtRealizeWidget(window);


    MmSetResourceValue(win_writer, "PtWidget_t", window);

    if( !(win_in=MmAcquireInputChannel(win_writer,MEDIA_TYPE_VIDEO)) )
    {
        printf("Couldn't get video_writer's input channel.\n");
        MmDestroyGraph(graph);
        exit(-10);
    }

    if( !(mpv_out=MmAcquireOutputChannel(mpv_decoder,MEDIA_TYPE_VIDEO)) )
    {
        printf("Couldn't get video_decoder's output channel.\n");
        MmDestroyGraph(graph);
        exit(-10);
    }

    if( MmAttachChannels(mpv_out,win_in) != 0 )
    {
        printf("Couldn't attach to video_writer's input channel.\n");
        MmDestroyGraph(graph);
        exit(-10);
    }

    // Get the mpeg system parser audio output channel
    if (!(mpsa_out=MmAcquireOutputChannel(mpegs_parser,MEDIA_TYPE_COMPRESSED|MEDIA_TYPE_AUDIO)))
    {
        printf("Couldn't get an audio output channel from MPEG system parser.\n");
        MmDestroyGraph(graph);
        exit(-7);
    }

        // grab the mpeg audio decoder
    if (!(mpa_decoder=MmFindFilter(graph,"xing_mpega_decoder")))
    {
        printf("Couldn't grab the xing mpeg audio decoder.\n");
        MmDestroyGraph(graph);
        exit(-7);
    }

    // grab the mpeg audio decoder input channel
    if (!(mpa_in=MmAcquireInputChannel(mpa_decoder,MEDIA_TYPE_COMPRESSED|MEDIA_TYPE_AUDIO)))
    {
        printf("Couldn't get a compressed input channel from xing_mpega_decoder.\n");
        MmDestroyGraph(graph);
        exit(-8);
    }

    // connect the two channels
    if (MmAttachChannels(mpsa_out,mpa_in)!=0)
    {
        printf("Couldn't attach system parser and mpega_parser channels.\n");
        MmDestroyGraph(graph);
        exit(-5);
    }

    // grab the xing_mpega_decoder filter output channel
    if (!(mpa_out=MmAcquireOutputChannel(mpa_decoder,MEDIA_TYPE_AUDIO)))
    {
        printf("Couldn't get a audio output channel from xing_mpega_decoder.\n");
        MmDestroyGraph(graph);
        exit(-10);
    }

    // grab the audio_writer filter
    if (!(audio_writer=MmFindFilter(graph,"audio_writer")))
    {
        printf("Couldn't grab the audio_writer filter.\n");
        MmDestroyGraph(graph);
        exit(-11);
    }

    // grab the audio input channel
    if (!(audio_in=MmAcquireInputChannel(audio_writer,MEDIA_TYPE_AUDIO)))
    {
        printf("Couldn't get an audio input channel from audio_writer.\n");
        MmDestroyGraph(graph);
        exit(-12);
    }

    // connect the two channels
    if (MmAttachChannels(mpa_out,audio_in)!=0)
    {
        printf("Couldn't attach xing_mpega_decoder and audio_writer channels.\n");
        MmDestroyGraph(graph);
        exit(-13);
    }

    // set our default clock
    MmSetDefaultClock(graph);

    // print graph, starting at reader
    MmPrintGraph(media_reader,0);

    // start the graph playing
    MmStart(graph,0);
    MmResume(graph);

    // We're not using PtMainLoop(), because then we wouldn't know
    // when to stop the app and destroy the graph
    // Instead we do our own loop:

    event = malloc(EVENT_SIZE);

    while (MmStatus(graph)==MM_STATUS_PLAYING) {

        switch (PhEventPeek(event, EVENT_SIZE)){
            case Ph_EVENT_MSG:
                PtEventHandler(event);
                break;
            case 0:
                // give the video filter a chance to render:
                PtLeave(Pt_EVENT_PROCESS_PREVENT);
                delay(500);
                PtEnter(Pt_EVENT_PROCESS_PREVENT);
                PgFlush();
                break;

            case -1:
                printf("Ack! error.\n");
                exit(0);
                break;

        }
    }

    free(event);

    // stop and destroy the graph
    MmStop(graph);
    printf("Done playing, destroying the graph.\n");
    MmDestroyGraph(graph);

    // close the input streamer
    file->streamer->Close(file);

    return (EXIT_SUCCESS);

} but you could
    // query the video for the right size to use

    PtSetArg(&args[0], Pt_ARG_HEIGHT, 200, 0);
    PtSetArg(&args[1], Pt_ARG_WIDTH, 300, 0);
    PtSetArg(&args[2], Pt_ARG_WINDOW_NOTIFY_FLAGS, Ph_WM_RESIZE|Ph_WM_MOVE,
        Ph_WM_RESIZE|Ph_WM_MOVE);
    window = PtCreateWidget(PtWindow, Pt_NO_PARENT, 3, args);

    // this callback handles resize and move:
    PtAddCallback(window, Pt_CB_WINDOW, OnWindowEvent, win_writer);
    PtRealizeWidget(window);


    MmSetResourceValue(win_writer, "PtWidget_t", window);

    if( !(win_in=MmAcquireInputChannel(win_writer,MEDIA_TYPE_VIDEO)) )
    {
        printf("Couldn't get video_writer's input channel.\n");
        MmDestroyGraph(graph);
        exit(-10);
    }

    if( !(mpv_out=MmAcquireOutputChannel(mpv_decoder,MEDIA_TYPE_VIDEO)) )
    {
        printf("Couldn't get video_decoder's output channel.\n");
        MmDestroyGraph(graph);
        exit(-10);
    }

    if( MmAttachChannels(mpv_out,win_in) != 0 )
    {
        printf("Couldn't attach to video_writer's input channel.\n");
        MmDestroyGraph(graph);
        exit(-10);
    }

    // Get the mpeg system parser audio output channel
    if (!(mpsa_out=MmAcquireOutputChannel(mpegs_parser,MEDIA_TYPE_COMPRESSED|MEDIA_TYPE_AUDIO)))
    {
        printf("Couldn't get an audio output channel from MPEG system parser.\n");
        MmDestroyGraph(graph);
        exit(-7);
    }

        // grab the mpeg audio decoder
    if (!(mpa_decoder=MmFindFilter(graph,"xing_mpega_decoder")))
    {
        printf("Couldn't grab the xing mpeg audio decoder.\n");
        MmDestroyGraph(graph);
        exit(-7);
    }

    // grab the mpeg audio decoder input channel
    if (!(mpa_in=MmAcquireInputChannel(mpa_decoder,MEDIA_TYPE_COMPRESSED|MEDIA_TYPE_AUDIO)))
    {
        printf("Couldn't get a compressed input channel from xing_mpega_decoder.\n");
        MmDestroyGraph(graph);
        exit(-8);
    }

    // connect the two channels
    if (MmAttachChannels(mpsa_out,mpa_in)!=0)
    {
        printf("Couldn't attach system parser and mpega_parser channels.\n");
        MmDestroyGraph(graph);
        exit(-5);
    }

    // grab the xing_mpega_decoder filter output channel
    if (!(mpa_out=MmAcquireOutputChannel(mpa_decoder,MEDIA_TYPE_AUDIO)))
    {
        printf("Couldn't get a audio output channel from xing_mpega_decoder.\n");
        MmDestroyGraph(graph);
        exit(-10);
    }

    // grab the audio_writer filter
    if (!(audio_writer=MmFindFilter(graph,"audio_writer")))
    {
        printf("Couldn't grab the audio_writer filter.\n");
        MmDestroyGraph(graph);
        exit(-11);
    }

    // grab the audio input channel
    if (!(audio_in=MmAcquireInputChannel(audio_writer,MEDIA_TYPE_AUDIO)))
    {
        printf("Couldn't get an audio input channel from audio_writer.\n");
        MmDestroyGraph(graph);
        exit(-12);
    }

    // connect the two channels
    if (MmAttachChannels(mpa_out,audio_in)!=0)
    {
        printf("Couldn't attach xing_mpega_decoder and audio_writer channels.\n");
        MmDestroyGraph(graph);
        exit(-13);
    }

    // set our default clock
    MmSetDefaultClock(graph);

    // print graph, starting at reader
    MmPrintGraph(media_reader,0);

    // start the graph playing
    MmStart(graph,0);
    MmResume(graph);

    // We're not using PtMainLoop(), because then we wouldn't know
    // when to stop the app and destroy the graph
    // Instead we do our own loop:

    event = malloc(EVENT_SIZE);

    while (MmStatus(graph)==MM_STATUS_PLAYING) {

        switch (PhEventPeek(event, EVENT_SIZE)){
            case Ph_EVENT_MSG:
                PtEventHandler(event);
                break;
            case 0:
                // give the video filter a chance to render:
                PtLeave(Pt_EVENT_PROCESS_PREVENT);
                delay(500);
                PtEnter(Pt_EVENT_PROCESS_PREVENT);
                PgFlush();
                break;

            case -1:
                printf("Ack! error.\n");
                exit(0);
                break;

        }
    }

    free(event);

    // stop and destroy the graph
    MmStop(graph);
    printf("Done playing, destroying the graph.\n");
    MmDestroyGraph(graph);

    // close the input streamer
    file->streamer->Close(file);

    return (EXIT_SUCCESS);

}
