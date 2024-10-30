/*
 *
 * PermissionUtils.java
 * 
 * Created by Wuwang on 2016/11/14
 * Copyright © 2016年 深圳哎吖科技. All rights reserved.
 */
package com.mpaas.demo;

import android.Manifest.permission;
import android.app.Activity;
import android.content.pm.PackageManager;
import android.os.Build;

import androidx.core.app.ActivityCompat;
import androidx.core.content.ContextCompat;

import java.util.ArrayList;
import java.util.List;

/**
 * Description:
 */
public class PermissionUtils {
    private static final String[] PERSMISSION = new String[] {
            permission.WRITE_EXTERNAL_STORAGE,
            permission.READ_EXTERNAL_STORAGE,
            permission.CAMERA,};

    public static boolean askPermission(Activity context, int req){
        if(Build.VERSION.SDK_INT>= Build.VERSION_CODES.M){
                return requestPermissions(context, req);
        }
        return true;
    }

    private static boolean requestPermissions(Activity context,int req) {
        List<String> unGrantedPermssion = new ArrayList<>();
        for (String permission : PERSMISSION) {
            if (ContextCompat.checkSelfPermission(context, permission)
                != PackageManager.PERMISSION_GRANTED) {
                unGrantedPermssion.add(permission);
            }
        }

        if (unGrantedPermssion.isEmpty()) {
            return true;
        }

        String[] needPermissions = new String[unGrantedPermssion.size()];
        int index = 0;
        for (String permission : unGrantedPermssion) {
            needPermissions[index] = permission;
            index ++;
        }

        ActivityCompat.requestPermissions(context,
            needPermissions,
                req);

        return false;
    }

}
