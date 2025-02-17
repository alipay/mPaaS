package com.mpaas.gdmap;


import android.Manifest;
import android.app.Activity;
import android.content.Intent;
import android.content.pm.PackageManager;
import android.location.Location;
import android.os.Bundle;
import android.util.Log;
import android.view.View;

import androidx.core.app.ActivityCompat;
import androidx.core.content.ContextCompat;

import com.amap.api.maps.AMap;
import com.amap.api.maps.model.MyLocationStyle;

import java.util.concurrent.TimeUnit;


public class GdMapActivity extends Activity implements AMap.OnMyLocationChangeListener {
    private static final int PERMISSION_REQUEST_CODE = 0X01;
    private static final long DEFAULT_LOCATION_INTERVAL = TimeUnit.SECONDS.toMillis(30L);
    private static final long LOCATION_TIME_OUT = TimeUnit.SECONDS.toMillis(31L);

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_gd_map);

        checkPermission();
        findView();
        initView();
    }

    private void findView() {
        findViewById(R.id.lbs_request_lbs_btn).setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                onClickGoTest();
            }
        });
    }

    private void onClickGoTest() {
        startActivity(new Intent(this, MapImpMethodActivity.class));
    }

    private void initView() {
        setTitle(getString(R.string.lbs));
        //设置SDK 自带定位消息监听
    }

    protected void checkPermission() {
        if (ContextCompat.checkSelfPermission(this, Manifest.permission.READ_EXTERNAL_STORAGE)
                != PackageManager.PERMISSION_GRANTED
                || ContextCompat.checkSelfPermission(this, Manifest.permission.WRITE_EXTERNAL_STORAGE)
                != PackageManager.PERMISSION_GRANTED
                || ContextCompat.checkSelfPermission(this, Manifest.permission.ACCESS_FINE_LOCATION)
                != PackageManager.PERMISSION_GRANTED
        ) {
            ActivityCompat.requestPermissions(this,
                    new String[]{Manifest.permission.READ_EXTERNAL_STORAGE, Manifest.permission.WRITE_EXTERNAL_STORAGE,
                            Manifest.permission.ACCESS_COARSE_LOCATION, Manifest.permission.ACCESS_FINE_LOCATION},
                    0);
        }
    }

    @Override
    public void onMyLocationChange(Location location) {
        // 定位回调监听
        if (location != null) {
            Log.e("amap", "onMyLocationChange" + getString(R.string.lbs_success) + "， lat: " + location.getLatitude() + " lon: " + location.getLongitude());
            Bundle bundle = location.getExtras();
            if (bundle != null) {
                int errorCode = bundle.getInt(MyLocationStyle.ERROR_CODE);
                String errorInfo = bundle.getString(MyLocationStyle.ERROR_INFO);
                // 定位类型，可能为GPS WIFI等，具体可以参考官网的定位SDK介绍
                int locationType = bundle.getInt(MyLocationStyle.LOCATION_TYPE);

                /*
                errorCode
                errorInfo
                locationType
                */
                Log.e("amap", getString(R.string.lbs_informaion)+"， code: " + errorCode + " errorInfo: " + errorInfo + " locationType: " + locationType);
            } else {
                Log.e("amap", getString(R.string.lbs_informaion)+"， bundle is null ");

            }

        } else {
            Log.e("amap", getString(R.string.lbs_error));
        }
    }
}