package com.mpaas.demo;

import android.os.Bundle;
import android.support.v7.app.AppCompatActivity;
import android.view.View;
import android.widget.Toast;

import com.mpaas.nebula.adapter.api.MPNebula;
import com.mpaas.nebula.adapter.api.MpaasNebulaUpdateCallback;


public class MainActivity extends AppCompatActivity {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        findViewById(R.id.start_app_btn).setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                MPNebula.startApp("80000000");
            }
        });

        findViewById(R.id.update_app_btn).setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                MPNebula.updateAllApp(new MpaasNebulaUpdateCallback() {
                    @Override
                    public void onResult(final boolean success, final boolean isLimit) {
                        // success 为是否成功
                        runOnUiThread(new Runnable() {
                            @Override
                            public void run() {
                                Toast.makeText(MainActivity.this, success ? "离线包更新成功" : "离线包更新失败", Toast.LENGTH_SHORT).show();
                            }
                        });
                    }
                });
            }
        });
    }
}
