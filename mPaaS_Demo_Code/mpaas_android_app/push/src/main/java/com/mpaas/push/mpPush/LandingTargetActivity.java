package com.mpaas.push.mpPush;


import android.content.Intent;
import android.os.Bundle;
import android.widget.TextView;

import androidx.annotation.Nullable;
import androidx.fragment.app.FragmentActivity;

import com.mpaas.push.R;

public class LandingTargetActivity extends FragmentActivity {

    @Override
    protected void onCreate(@Nullable Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_landing);
        Intent intent = getIntent();
        if (intent != null) {
            String uri = intent.getStringExtra("uri");
            String params = intent.getStringExtra("data");
            ((TextView)findViewById(R.id.uri)).setText(uri);
            ((TextView)findViewById(R.id.params)).setText(params);
        }
    }
}
