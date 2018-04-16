As per analysis,

In Android 7, mplayer instance is created through Nuplayer class using pid.
So video and whatsapp call are two independent instances so after giving whats
app miss call the video is starting from beginning. But in Android 8 instead of
mplayer,
MediaAnalyticsItem instance is used so both are dependent.


code level anaysis:

NuPlayerDriver::NuPlayerDriver(pid_t pid)
    : mState(STATE_IDLE),
      mIsAsyncPrepare(false),
      mAsyncResult(UNKNOWN_ERROR),
      mSetSurfaceInProgress(false),
      mDurationUs(-1),
      mPositionUs(-1),
      mSeekInProgress(false),
      mLooper(new ALooper),
      mPlayerFlags(0),
      mAtEOS(false),
      mLooping(false),
      mAutoLoop(false) {
    ALOGV("NuPlayerDriver(%p)", this);
    mLooper->setName("NuPlayerDriver Looper");

    mLooper->start(
            false, /* runOnCallingThread */
            true,  /* canCallJava */
            PRIORITY_AUDIO);

    mPlayer = new NuPlayer(pid);
    mLooper->registerHandler(mPlayer);

    mPlayer->setDriver(this);
}

code analysis in android 8:
NuPlayerDriver::NuPlayerDriver(pid_t pid)
    : mState(STATE_IDLE),
      mIsAsyncPrepare(false),
      mAsyncResult(UNKNOWN_ERROR),
      mSetSurfaceInProgress(false),
      mDurationUs(-1),
      mPositionUs(-1),
      mSeekInProgress(false),
      mPlayingTimeUs(0),
      mLooper(new ALooper),
      mPlayer(new NuPlayer(pid)),
      mPlayerFlags(0),
      mAnalyticsItem(NULL),
      mAtEOS(false),
      mLooping(false),
      mAutoLoop(false) {
    ALOGD("NuPlayerDriver(%p) created, clientPid(%d)", this, pid);
    mLooper->setName("NuPlayerDriver Looper");

    // set up an analytics record
    mAnalyticsItem = new MediaAnalyticsItem(kKeyPlayer);
    mAnalyticsItem->generateSessionID();

    mLooper->start(
            false, /* runOnCallingThread */
            true,  /* canCallJava */
            PRIORITY_AUDIO);

    mLooper->registerHandler(mPlayer);

    mPlayer->setDriver(this);
}

These are the code level changes done in android 8.
