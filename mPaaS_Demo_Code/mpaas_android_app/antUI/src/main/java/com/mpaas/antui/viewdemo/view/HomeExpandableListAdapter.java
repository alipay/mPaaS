package com.mpaas.antui.viewdemo.view;

import android.content.Context;
import android.view.View;
import android.view.ViewGroup;
import android.widget.BaseExpandableListAdapter;

import com.alipay.mobile.antui.api.AULineGroupItemInterface;
import com.alipay.mobile.antui.tablelist.AUSingleTitleListItem;

import java.util.ArrayList;
import java.util.List;

/**
 * Created by xuanmu on 17/7/12.
 */

public class HomeExpandableListAdapter extends BaseExpandableListAdapter {

    private List<ComponentGroupModel> componentGroupModels = new ArrayList<ComponentGroupModel>();
    private Context mContext;

    public HomeExpandableListAdapter(Context context){
        mContext = context;
    }

    public void setComponentModel(List<ComponentGroupModel> groupModelList) {
        this.componentGroupModels.clear();
        this.componentGroupModels.addAll(groupModelList);
        notifyDataSetChanged();
    }

    @Override
    public int getGroupCount() {
        return componentGroupModels.size();
    }

    @Override
    public int getChildrenCount(int groupPosition) {
        return componentGroupModels.get(groupPosition).modelList.size();
    }

    @Override
    public List<ComponentModel> getGroup(int groupPosition) {
        return componentGroupModels.get(groupPosition).modelList;
    }

    @Override
    public ComponentModel getChild(int groupPosition, int childPosition) {
        return getGroup(groupPosition).get(childPosition);
    }

    @Override
    public long getGroupId(int groupPosition) {
        return 0;
    }

    @Override
    public long getChildId(int groupPosition, int childPosition) {
        return 0;
    }

    @Override
    public boolean hasStableIds() {
        return false;
    }

    @Override
    public View getGroupView(int groupPosition, boolean isExpanded, View convertView, ViewGroup parent) {
        if (convertView == null){
            convertView = new ExpaGroupItem(mContext);
        }
        ((ExpaGroupItem)convertView).setInfo(componentGroupModels.get(groupPosition).titleModel);
        ((ExpaGroupItem)convertView).setArrowVisible(!isExpanded);
        return convertView;
    }

    @Override
    public View getChildView(int groupPosition, int childPosition, boolean isLastChild, View convertView, ViewGroup parent) {
        if (convertView == null){
            convertView = new AUSingleTitleListItem(mContext);
        }
        ((AUSingleTitleListItem)convertView).setLeftText(getChild(groupPosition, childPosition).title);
        if (childPosition == getChildrenCount(groupPosition) - 1){
            ((AUSingleTitleListItem)convertView).setItemPositionStyle(AULineGroupItemInterface.NONE);
        } else {
            ((AUSingleTitleListItem)convertView).setItemPositionStyle(AULineGroupItemInterface.CENTER);
        }
        return convertView;
    }

    @Override
    public boolean isChildSelectable(int groupPosition, int childPosition) {
        return true;
    }
}
