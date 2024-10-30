package com.mpaas.antui.viewdemo.fragment;

import android.content.Intent;
import android.os.Bundle;
import android.text.TextUtils;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.ExpandableListView;
import android.widget.Toast;

import androidx.fragment.app.Fragment;

import com.mpaas.antui.R;
import com.alipay.mobile.antui.basic.AUToast;
import com.mpaas.antui.viewdemo.AUAmountInputBoxActivity;
import com.mpaas.antui.viewdemo.FullScreenActivity;
import com.mpaas.antui.viewdemo.QRCodeActivity;
import com.mpaas.antui.viewdemo.StatusActivity;
import com.mpaas.antui.viewdemo.list.ListViewActivity;
import com.mpaas.antui.viewdemo.view.ComponentGroupModel;
import com.mpaas.antui.viewdemo.view.ComponentModel;
import com.mpaas.antui.viewdemo.view.HomeExpandableListAdapter;

import java.util.ArrayList;
import java.util.List;

/**
 * Created by xuanmu on 17/9/1.
 */

public class SceneFragment extends Fragment implements ExpandableListView.OnChildClickListener {

    private View contentView;
    private HomeExpandableListAdapter adapter;

    @Override
    public View onCreateView(LayoutInflater inflater, ViewGroup container, Bundle savedInstanceState) {
        contentView = super.onCreateView(inflater, container, savedInstanceState);
        if (contentView == null) {
            contentView = inflater.inflate(R.layout.fragment_common, container, false);
            View headview = inflater.inflate(R.layout.view_expa_scene_head, null);
            ExpandableListView listView = (ExpandableListView) contentView.findViewById(R.id.expand_list);
            adapter = new HomeExpandableListAdapter(getActivity());
            listView.addHeaderView(headview);
            listView.setAdapter(adapter);
            listView.setOnChildClickListener(this);
            adapter.setComponentModel(initialData());
        }
        return contentView;
    }


    private List<ComponentGroupModel> initialData() {
        List<ComponentGroupModel> componentGroupModels = new ArrayList<ComponentGroupModel>();
        List<ComponentModel> modelList1 = new ArrayList<ComponentModel>();
        modelList1.add(new ComponentModel("资金输入", AUAmountInputBoxActivity.class.getName()));
        modelList1.add(new ComponentModel("二维码", QRCodeActivity.class.getName()));
        modelList1.add(new ComponentModel("刷新", ListViewActivity.class.getName()));
        modelList1.add(new ComponentModel("底部button"));
        modelList1.add(new ComponentModel("横向滚动式选择列表"));
        modelList1.add(new ComponentModel("结果页", StatusActivity.class.getName()));
        modelList1.add(new ComponentModel("全屏页面", FullScreenActivity.class.getName()));

        List<ComponentModel> modelList2 = new ArrayList<ComponentModel>();
        modelList2.add(new ComponentModel("图片上传"));
        modelList2.add(new ComponentModel("选择文件"));
        modelList2.add(new ComponentModel("视频"));
        modelList2.add(new ComponentModel("录音"));


        List<ComponentModel> modelList3 = new ArrayList<ComponentModel>();
        modelList3.add(new ComponentModel("动态换肤"));

        componentGroupModels.add(new ComponentGroupModel(new ComponentModel(R.drawable.scene_screen, "界面"), modelList1));
        componentGroupModels.add(new ComponentGroupModel(new ComponentModel(R.drawable.scene_multimedia,"媒体"), modelList2));
        componentGroupModels.add(new ComponentGroupModel(new ComponentModel(R.drawable.scene_skin,"换肤"), modelList3));
        return componentGroupModels;
    }

    @Override
    public boolean onChildClick(ExpandableListView parent, View v, int groupPosition, int childPosition, long id) {
        startDemo(adapter.getChild(groupPosition,childPosition).activityName);
        return true;
    }

    private void startDemo(String className) {
        if (TextUtils.isEmpty(className)){
            AUToast.makeToast(getActivity(), 0, "建设中，敬请期待！", Toast.LENGTH_SHORT).show();
        } else {
            Intent intent = new Intent();
            intent.setClassName(getActivity(), className);
            startActivity(intent);
        }
    }
}
