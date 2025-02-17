package com.mpaas.antui.viewdemo.fragment;

import android.content.Intent;
import android.os.Bundle;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;

import androidx.fragment.app.Fragment;

import com.mpaas.antui.R;
import com.mpaas.antui.viewdemo.APBladeViewActivity;
import com.mpaas.antui.viewdemo.AUAmountInputBoxActivity;
import com.mpaas.antui.viewdemo.AUCardOptionViewActivity;
import com.mpaas.antui.viewdemo.AUImagePickerActivity;
import com.mpaas.antui.viewdemo.AUSegmentActivity;
import com.mpaas.antui.viewdemo.AUTabBarActivity;
import com.mpaas.antui.viewdemo.CardMenuActivity;
import com.mpaas.antui.viewdemo.ChangeSkinActivity;
import com.mpaas.antui.viewdemo.DatePickActivity;
import com.mpaas.antui.viewdemo.DividerListActivity;
import com.mpaas.antui.viewdemo.EmptyPageLoadingActivity;
import com.mpaas.antui.viewdemo.ImageActivity;
import com.mpaas.antui.viewdemo.InputActivity;
import com.mpaas.antui.viewdemo.ListItemViewActivity;
import com.mpaas.antui.viewdemo.NetErrorViewActivity;
import com.mpaas.antui.viewdemo.PullRefreshActivity;
import com.mpaas.antui.viewdemo.QRCodeActivity;
import com.mpaas.antui.viewdemo.ScrollTitleBarActivity;
import com.mpaas.antui.viewdemo.SearchBarActivity;
import com.mpaas.antui.viewdemo.StatusActivity;
import com.mpaas.antui.viewdemo.TitleBarActivity;
import com.mpaas.antui.viewdemo.action.DialogActivity;
import com.mpaas.antui.viewdemo.action.ToastActivity;
import com.mpaas.antui.viewdemo.common.ButtonActivity;

/**
 * Created by xuanmu on 17/7/18.
 */

public class OriginalFragment extends Fragment implements View.OnClickListener{

    private View contentView;

    @Override
    public View onCreateView(LayoutInflater inflater, ViewGroup container, Bundle savedInstanceState) {
        contentView = super.onCreateView(inflater, container, savedInstanceState);
        if (contentView == null) {
            contentView = inflater.inflate(R.layout.fragment_scene, container, false);
            contentView.findViewById(R.id.title_demo).setOnClickListener(this);
            contentView.findViewById(R.id.search_demo).setOnClickListener(this);
            contentView.findViewById(R.id.change_skin).setOnClickListener(this);
            contentView.findViewById(R.id.card_demo).setOnClickListener(this);
            contentView.findViewById(R.id.float_demo).setOnClickListener(this);
            contentView.findViewById(R.id.list_demo).setOnClickListener(this);
            contentView.findViewById(R.id.divider_demo).setOnClickListener(this);
            contentView.findViewById(R.id.button_demo).setOnClickListener(this);
            contentView.findViewById(R.id.text_demo).setOnClickListener(this);
            contentView.findViewById(R.id.segment_demo).setOnClickListener(this);
            contentView.findViewById(R.id.toast_demo).setOnClickListener(this);
            contentView.findViewById(R.id.alert_demo).setOnClickListener(this);
            contentView.findViewById(R.id.pullloading_demo).setOnClickListener(this);
            contentView.findViewById(R.id.loading_demo).setOnClickListener(this);
            contentView.findViewById(R.id.blade_demo).setOnClickListener(this);
            contentView.findViewById(R.id.date_demo).setOnClickListener(this);
            contentView.findViewById(R.id.result_demo).setOnClickListener(this);
            contentView.findViewById(R.id.neterror_demo).setOnClickListener(this);
            contentView.findViewById(R.id.tab_demo).setOnClickListener(this);
            contentView.findViewById(R.id.card_option_demo).setOnClickListener(this);
            contentView.findViewById(R.id.amount_demo).setOnClickListener(this);
            contentView.findViewById(R.id.roundimage_demo).setOnClickListener(this);
            contentView.findViewById(R.id.code_demo).setOnClickListener(this);
            contentView.findViewById(R.id.imagepicker_demo).setOnClickListener(this);
        }
        return contentView;
    }

    private void startDemo(String className) {
        Intent intent = new Intent();
        intent.setClassName(getActivity(), className);
        startActivity(intent);
    }

    public void onAUTitleBar(View view) {
        startDemo(TitleBarActivity.class.getName());
    }

    public void onAUSearchBar(View view) {
        startDemo(SearchBarActivity.class.getName());
    }

    public void onChangeSkin(View view) {
        startDemo(ChangeSkinActivity.class.getName());
    }

    public void onAUCardMenu(View view) {
        startDemo(CardMenuActivity.class.getName());
    }

    public void onAUFloatMenu(View view) {
        startDemo(ScrollTitleBarActivity.class.getName());
    }

    public void onAUListItems(View view) {
        startDemo(ListItemViewActivity.class.getName());
    }

    public void onDividerListView(View view){
        startDemo(DividerListActivity.class.getName());
    }

    public void onAUButton(View view) {
        startDemo(ButtonActivity.class.getName());
    }

    public void onAUTextFields(View view) {
        startDemo(InputActivity.class.getName());
    }

    public void onAUSegment(View view) {
        startDemo(AUSegmentActivity.class.getName());
    }

    public void onAUCheckbox(View view) {
        startDemo(StatusActivity.class.getName());
    }

    public void onAUToast(View view) {
        startDemo(ToastActivity.class.getName());
    }

    public void onAlerts(View view) {
        startDemo(DialogActivity.class.getName());
    }

    public void onAUPullloadingView(View view) {
        startDemo(PullRefreshActivity.class.getName());
    }

    public void onAULoadingView(View view) {
        startDemo(EmptyPageLoadingActivity.class.getName());
    }

    public void onAUBladeView(View view) {
        startDemo(APBladeViewActivity.class.getName());
    }

    public void onAUDatePicker(View view) {
        startDemo(DatePickActivity.class.getName());
    }

    public void onAUResultView(View view) {
        startDemo(StatusActivity.class.getName());
    }

    public void onAUNetErrorView(View view) {
        startDemo(NetErrorViewActivity.class.getName());
    }

    public void onAUTabBar(View view) {
        startDemo(AUTabBarActivity.class.getName());
    }

    public void onAUCardOptionView(View view) {
        startDemo(AUCardOptionViewActivity.class.getName());
    }

    public void onAUAmountInputBox(View view){
        startDemo(AUAmountInputBoxActivity.class.getName());
    }

    public void onImageView(View view){
        startDemo(ImageActivity.class.getName());
    }

    public void onAUQRCodeView(View view){
        startDemo(QRCodeActivity.class.getName());
    }

    public void onImagePicker(View view){
        startDemo(AUImagePickerActivity.class.getName());
    }

    @Override
    public void onClick(View v) {
        if (v.getId() == R.id.title_demo) {
            onAUTitleBar(v);
        } else if (v.getId() == R.id.search_demo) {
            onAUSearchBar(v);
        } else if (v.getId() == R.id.change_skin) {
            onChangeSkin(v);
        } else if (v.getId() == R.id.card_demo) {
            onAUCardMenu(v);
        } else if (v.getId() == R.id.float_demo) {
            onAUFloatMenu(v);
        } else if (v.getId() == R.id.list_demo) {
            onAUListItems(v);
        } else if (v.getId() == R.id.divider_demo) {
            onDividerListView(v);
        } else if (v.getId() == R.id.button_demo) {
            onAUButton(v);
        } else if (v.getId() == R.id.text_demo) {
            onAUTextFields(v);
        } else if (v.getId() == R.id.segment_demo) {
            onAUSegment(v);
        } else if (v.getId() == R.id.toast_demo) {
            onAUToast(v);
        } else if (v.getId() == R.id.alert_demo) {
            onAlerts(v);
        } else if (v.getId() == R.id.pullloading_demo) {
            onAUPullloadingView(v);
        } else if (v.getId() == R.id.loading_demo) {
            onAULoadingView(v);
        } else if (v.getId() == R.id.blade_demo) {
            onAUBladeView(v);
        } else if (v.getId() == R.id.date_demo) {
            onAUDatePicker(v);
        } else if (v.getId() == R.id.result_demo) {
            onAUResultView(v);
        } else if (v.getId() == R.id.neterror_demo) {
            onAUNetErrorView(v);
        } else if (v.getId() == R.id.tab_demo) {
            onAUTabBar(v);
        } else if (v.getId() == R.id.card_option_demo) {
            onAUCardOptionView(v);
        } else if (v.getId() == R.id.amount_demo) {
            onAUAmountInputBox(v);
        } else if (v.getId() == R.id.roundimage_demo) {
            onImageView(v);
        } else if (v.getId() == R.id.code_demo) {
            onAUQRCodeView(v);
        } else if (v.getId() == R.id.imagepicker_demo) {
            onImagePicker(v);
        }
    }
}
