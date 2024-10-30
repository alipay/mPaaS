package com.mpaas.antui.viewdemo.view;

/**
 * Created by xuanmu on 17/7/12.
 */

public class ComponentModel {

    public int iconResId;
    public String title;
    public String activityName;


    public ComponentModel(String title){
        this.title = title;
    }

    public ComponentModel(int iconResId, String title){
        this.title = title;
        this.iconResId = iconResId;
    }

    public ComponentModel(String title, String activityName){
        this.title = title;
        this.activityName = activityName;
    }
}
