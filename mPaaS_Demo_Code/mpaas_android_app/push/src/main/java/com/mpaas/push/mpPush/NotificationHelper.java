package com.mpaas.push.mpPush;


import android.annotation.TargetApi;
import android.app.Notification;
import android.app.NotificationChannel;
import android.app.NotificationManager;
import android.content.Context;
import android.content.ContextWrapper;
import android.graphics.BitmapFactory;
import android.graphics.Color;
import android.os.Build;

import androidx.core.app.NotificationCompat;

import com.mpaas.push.R;

public class NotificationHelper extends ContextWrapper {
    private NotificationManager mManager;
    private static final String CHANNEL_ID = "pushChannel";
    private static final String CHANNEL_NAME = "push渠道";

    public NotificationHelper(Context context) {
        super(context);
        if (Build.VERSION.SDK_INT >= Build.VERSION_CODES.O) {
            int importance = NotificationManager.IMPORTANCE_HIGH;
            createNotificationChannel(CHANNEL_ID, getString(R.string.push_channel), importance);
        }
    }

    @TargetApi(Build.VERSION_CODES.O)
    private void createNotificationChannel(String channelId, String channelName, int importance) {
        NotificationChannel channel = new NotificationChannel(channelId, channelName, importance);
        channel.setLightColor(Color.GRAY);
        channel.setLockscreenVisibility(Notification.VISIBILITY_PUBLIC);
        getManager().createNotificationChannel(channel);
    }

    private Notification getNotification(String title, String body) {
        Notification notification;
        if (Build.VERSION.SDK_INT >= Build.VERSION_CODES.O) {
            notification = new Notification.Builder(this)
                    .setContentTitle(title)
                    .setContentText(body)
                    .setWhen(System.currentTimeMillis())
                    .setChannelId(CHANNEL_ID)
                    .setSmallIcon(getApplicationContext().getApplicationInfo().icon)
                    .setLargeIcon(BitmapFactory.decodeResource(getResources(), R.drawable.appicon))
                    .setAutoCancel(true)
                    .build();
        }else {
            notification = new NotificationCompat.Builder(getApplicationContext())
                    .setContentTitle(title)
                    .setContentText(body)
                    .setWhen(System.currentTimeMillis())
                    .setSmallIcon(getApplicationContext().getApplicationInfo().icon)
                    .setLargeIcon(BitmapFactory.decodeResource(getResources(), R.drawable.appicon))
                    .setAutoCancel(true)
                    .build();
        }
        return notification;
    }

    public void notify(String title, String body) {
        getManager().notify(1, getNotification(title, body));
    }

    private NotificationManager getManager() {
        if (mManager == null) {
            mManager = (NotificationManager) getSystemService(Context.NOTIFICATION_SERVICE);
        }
        return mManager;
    }
}
