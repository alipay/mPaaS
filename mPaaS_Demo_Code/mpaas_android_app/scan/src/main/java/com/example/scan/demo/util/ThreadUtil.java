package com.example.scan.demo.util;

import android.os.Handler;
import android.os.Looper;

import java.util.concurrent.ExecutorService;
import java.util.concurrent.Executors;

/**
 * Created by xingcheng on 2019/3/5.
 */
public class ThreadUtil {
    private static Handler handler;
    private static boolean sleeping;
    private static ExecutorService cachedThreadPool;

    public static void sleep() {
        sleeping = true;
        while (sleeping) {
            try {
                Thread.sleep(100);
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
        }
    }

    public static void wake() {
        sleeping = false;
    }

    public static void sleep(int second) {
        try {
            Thread.sleep(second * 1000);
        } catch (InterruptedException e) {
            e.printStackTrace();
        }
    }

    public static void runOnMainThread(Runnable runnable) {
        if (handler == null) {
            handler = new Handler(Looper.getMainLooper());
        }
        handler.post(runnable);
    }

    public static void runOnMainThread(Runnable runnable, long delayMillis) {
        if (handler == null) {
            handler = new Handler(Looper.getMainLooper());
        }
        handler.postDelayed(runnable, delayMillis);
    }

    public static void runOnSubThread(Runnable runnable) {
        if (cachedThreadPool == null) {
            cachedThreadPool = Executors.newCachedThreadPool();
        }
        cachedThreadPool.execute(runnable);
    }
}
