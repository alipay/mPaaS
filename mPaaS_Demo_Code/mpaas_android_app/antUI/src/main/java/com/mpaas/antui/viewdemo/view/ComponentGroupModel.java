package com.mpaas.antui.viewdemo.view;

import java.util.List;

/**
 * Created by xuanmu on 17/7/19.
 */

public class ComponentGroupModel {
    public ComponentModel titleModel;
    public List<ComponentModel> modelList;

    public ComponentGroupModel(ComponentModel model, List<ComponentModel> list){
        this.titleModel = model;
        this.modelList = list;
    }
}
