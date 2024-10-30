package com.mpaas.demo.uicontrol;

import android.content.Context;
import android.content.res.AssetManager;

import com.seiginonakama.res.utils.IOUtils;

import java.io.IOException;
import java.io.InputStream;

public class AeestesUtils {
    public static  byte[] getDefaultIcon(Context context) {
        AssetManager assetManager =context.getAssets();
        InputStream inputStream = null;
        byte[] bytesLogo = null;
        try {
            inputStream = assetManager.open("default_avatar.png");
            bytesLogo = IOUtils.toByteArray(inputStream);
        } catch (IOException e) {
            e.printStackTrace();
        }
        return bytesLogo;

    }
}
