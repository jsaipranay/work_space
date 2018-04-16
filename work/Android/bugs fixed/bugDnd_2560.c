
ConditionManager.get(context).getCondition(DndCondition.class);
              if (condition != null) {
                    condition.refreshState();
               }
           }
        }
    }
 @Override
  protected boolean shouldAlwaysListenToBroadcast() {
      return true;
  }
}



The similar issue is in AOSP and it is FIXED with android 8
(https://issuetracker.google.com/issues/37138192),and Following code changes
are made in DNDCondition.java file which has fixed the issue.
changes made in the code

  public static class Receiver extends BroadcastReceiver {
       @Override
       public void onReceive(Context context, Intent intent) {
            if (NotificationManager.ACTION_INTERRUPTION_FILTER_CHANGED_INTERNAL
                   .equals(intent.getAction())) {
              final Condition condition =
                      
ConditionManager.get(context).getCondition(DndCondition.class);
              if (condition != null) {
                    condition.refreshState();
                }
            }
        }
   }

    @Override
   public void onResume() {
        if (!mRegistered) {
           mManager.getContext().registerReceiver(mReceiver, DND_FILTER);
           mRegistered = true;
        }
    }

    @Override
    public void onPause() {
        mManager.getContext().unregisterReceiver(mReceiver);
        mRegistered = false;
    }
}
This issue is fixed in android 8.
http://androidxref.com/8.0.0_r4/xref/packages/apps/Settings/src/com/android/settings/dashboard/conditional/DndCondition.java#DND_FILTER
