package com.mpaas.demo.nebula;

import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.TextView;

import com.alipay.mobile.nebula.view.H5NavMenuItem;
import com.alipay.mobile.nebula.view.H5NavMenuView;

import java.util.List;

/**
 * Created by xingcheng on 2018/10/8.
 */

public class H5NavMenuViewImpl implements H5NavMenuView {

    private List<H5NavMenuItem> menuList;

    /**
     * 设置菜单数据
     * <p>
     * 该方法由容器调用，用户需在h5中调用相关JSApi传递数据
     * 参考：
     * http://jsapi.alipay.net/jsapi/events/pop-menu-click.html
     */
    @Override
    public void setList(List<H5NavMenuItem> list) {
        menuList = list;
    }

    @Override
    public int getListCount() {
        return menuList == null ? 0 : menuList.size();
    }

    @Override
    public View getItemView(int position, ViewGroup parent) {
        if (menuList == null) {
            return null;
        }
        View contentView = LayoutInflater.from(parent.getContext())
                .inflate(R.layout.h5_navigation_menu_item, parent, false);
        TextView name = (TextView) contentView.findViewById(R.id.tv_name);

        H5NavMenuItem menuItem = menuList.get(position);
        name.setText(menuItem.name);

        return contentView;
    }
}
