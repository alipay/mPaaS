package com.mpaas.demo.uicontrol;

import androidx.appcompat.app.AppCompatActivity;

import android.content.Intent;
import android.os.Bundle;
import android.view.View;

import com.mpaas.demo.R;
import com.mpaas.demo.uicontrol.storage.DBStorageActivity;
import com.mpaas.demo.uicontrol.storage.FileStorageActivity;
import com.mpaas.demo.uicontrol.storage.KVStorageActivity;

public class StroageActivity extends AppCompatActivity {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_stroage_ui);
        setTitle("统一存储");

        findViewById(R.id.btn_db).setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                startActivity(new Intent(StroageActivity.this, DBStorageActivity.class));
            }
        });

        findViewById(R.id.btn_kv).setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                startActivity(new Intent(StroageActivity.this, KVStorageActivity.class));
            }
        });

        findViewById(R.id.btn_file).setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                startActivity(new Intent(StroageActivity.this, FileStorageActivity.class));
            }
        });
    }
}