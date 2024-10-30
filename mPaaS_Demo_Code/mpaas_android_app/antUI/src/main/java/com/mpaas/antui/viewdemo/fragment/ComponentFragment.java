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

import com.alipay.mobile.antui.basic.AUToast;
import com.mpaas.antui.R;
import com.mpaas.antui.viewdemo.AULinearLayoutActivity;
import com.mpaas.antui.viewdemo.AUSegmentActivity;
import com.mpaas.antui.viewdemo.AUTabBarActivity;
import com.mpaas.antui.viewdemo.AUVerticalTabViewActivity;
import com.mpaas.antui.viewdemo.ActionSheetActivity;
import com.mpaas.antui.viewdemo.BubbleViewActivity;
import com.mpaas.antui.viewdemo.ButtonActivity;
import com.mpaas.antui.viewdemo.ListItemViewActivity;
import com.mpaas.antui.viewdemo.NavBarActivity;
import com.mpaas.antui.viewdemo.PopTipsActivity;
import com.mpaas.antui.viewdemo.PopoverActivity;
import com.mpaas.antui.viewdemo.action.DialogActivity;
import com.mpaas.antui.viewdemo.action.TipsActivity;
import com.mpaas.antui.viewdemo.action.ToastActivity;
import com.mpaas.antui.viewdemo.common.BadgeActivity;
import com.mpaas.antui.viewdemo.common.CarouselActivity;
import com.mpaas.antui.viewdemo.common.FooterActivity;
import com.mpaas.antui.viewdemo.common.IconActivity;
import com.mpaas.antui.viewdemo.common.LoadingActivity;
import com.mpaas.antui.viewdemo.common.ResultActivity;
import com.mpaas.antui.viewdemo.common.ScreenActivity;
import com.mpaas.antui.viewdemo.form.AUAgreementActivity;
import com.mpaas.antui.viewdemo.form.CheckBoxActivity;
import com.mpaas.antui.viewdemo.form.InputBoxActivity;
import com.mpaas.antui.viewdemo.form.PickerActivity;
import com.mpaas.antui.viewdemo.form.RadioActivity;
import com.mpaas.antui.viewdemo.form.SwitchActivity;
import com.mpaas.antui.viewdemo.form.TextAreaActivity;
import com.mpaas.antui.viewdemo.search.SearchActivity;
import com.mpaas.antui.viewdemo.view.ComponentGroupModel;
import com.mpaas.antui.viewdemo.view.ComponentModel;
import com.mpaas.antui.viewdemo.view.HomeExpandableListAdapter;

import java.util.ArrayList;
import java.util.List;

/**
 * Created by xuanmu on 17/7/18.
 */

public class ComponentFragment extends Fragment implements ExpandableListView.OnChildClickListener {

    private View contentView;
    private HomeExpandableListAdapter adapter;

    @Override
    public View onCreateView(LayoutInflater inflater, ViewGroup container, Bundle savedInstanceState) {
        contentView = super.onCreateView(inflater, container, savedInstanceState);
        if (contentView == null) {
            contentView = inflater.inflate(R.layout.fragment_common, container, false);
            View headview = inflater.inflate(R.layout.view_expa_head, null);
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
        modelList1.add(new ComponentModel("NavBar", NavBarActivity.class.getName()));
        modelList1.add(new ComponentModel("TabBar", AUTabBarActivity.class.getName()));
        modelList1.add(new ComponentModel("Segment", AUSegmentActivity.class.getName()));
        modelList1.add(new ComponentModel("VerticalTabView", AUVerticalTabViewActivity.class.getName()));

        List<ComponentModel> modelList2 = new ArrayList<ComponentModel>();
        modelList2.add(new ComponentModel("SearchBar", SearchActivity.class.getName()));

        List<ComponentModel> modelList3 = new ArrayList<ComponentModel>();
        modelList3.add(new ComponentModel("Article"));
        modelList3.add(new ComponentModel("Badge", BadgeActivity.class.getName()));
        modelList3.add(new ComponentModel("Icon", IconActivity.class.getName()));
        modelList3.add(new ComponentModel("Load", LoadingActivity.class.getName()));
        modelList3.add(new ComponentModel("Button", ButtonActivity.class.getName()));
        modelList3.add(new ComponentModel("Carousel", CarouselActivity.class.getName()));
        modelList3.add(new ComponentModel("Lists", ListItemViewActivity.class.getName()));
        modelList3.add(new ComponentModel("Footer", FooterActivity.class.getName()));
        modelList3.add(new ComponentModel("Result", ResultActivity.class.getName()));
        modelList3.add(new ComponentModel("Screening", ScreenActivity.class.getName()));
        modelList3.add(new ComponentModel("Banner", CarouselActivity.class.getName()));
        modelList3.add(new ComponentModel("Bubble", BubbleViewActivity.class.getName()));


        List<ComponentModel> modelList4 = new ArrayList<ComponentModel>();
        modelList4.add(new ComponentModel("Checkbox", CheckBoxActivity.class.getName()));
        modelList4.add(new ComponentModel("Agreement", AUAgreementActivity.class.getName()));
        modelList4.add(new ComponentModel("Radio", RadioActivity.class.getName()));
        modelList4.add(new ComponentModel("Input", InputBoxActivity.class.getName()));
        modelList4.add(new ComponentModel("Picker", PickerActivity.class.getName()));
        modelList4.add(new ComponentModel("Slider"));
        modelList4.add(new ComponentModel("Switch", SwitchActivity.class.getName()));
        modelList4.add(new ComponentModel("TextArea", TextAreaActivity.class.getName()));

        List<ComponentModel> modelList5 = new ArrayList<ComponentModel>();
        modelList5.add(new ComponentModel("ActionSheet", ActionSheetActivity.class.getName()));
        modelList5.add(new ComponentModel("Dialog", DialogActivity.class.getName()));
        modelList5.add(new ComponentModel("Toast", ToastActivity.class.getName()));
        modelList5.add(new ComponentModel("Tips", TipsActivity.class.getName()));
        modelList5.add(new ComponentModel("Progress"));
        modelList5.add(new ComponentModel("PopOver", PopoverActivity.class.getName()));
        modelList5.add(new ComponentModel("PopTips", PopTipsActivity.class.getName()));

        List<ComponentModel> modelList6 = new ArrayList<ComponentModel>();
        modelList6.add(new ComponentModel("Fiex"));
        modelList6.add(new ComponentModel("Layer"));

        List<ComponentModel> modelList7 = new ArrayList<ComponentModel>();
        modelList7.add(new ComponentModel("LinearLayout", AULinearLayoutActivity.class.getName()));

        componentGroupModels.add(new ComponentGroupModel(new ComponentModel(R.drawable.navigation, "导航"), modelList1));
        componentGroupModels.add(new ComponentGroupModel(new ComponentModel(R.drawable.search, "搜索"), modelList2));
        componentGroupModels.add(new ComponentGroupModel(new ComponentModel(R.drawable.basic, "基础组件"), modelList3));
        componentGroupModels.add(new ComponentGroupModel(new ComponentModel(R.drawable.form, "表单"), modelList4));
        componentGroupModels.add(new ComponentGroupModel(new ComponentModel(R.drawable.action, "操作反馈"), modelList5));
//        componentGroupModels.add(new ComponentGroupModel(new ComponentModel(R.drawable.layer,"层级规则"), modelList6));
        componentGroupModels.add(new ComponentGroupModel(new ComponentModel(R.drawable.action, "屏幕适配"), modelList7));
        return componentGroupModels;
    }

    @Override
    public boolean onChildClick(ExpandableListView parent, View v, int groupPosition, int childPosition, long id) {
        startDemo(adapter.getChild(groupPosition, childPosition).activityName);
        return true;
    }

    private void startDemo(String className) {
        if (TextUtils.isEmpty(className)) {
            AUToast.makeToast(getActivity(), 0, "建设中，敬请期待！", Toast.LENGTH_SHORT).show();
        } else {
            Intent intent = new Intent();
            intent.setClassName(getActivity(), className);
            startActivity(intent);
        }
    }
}
