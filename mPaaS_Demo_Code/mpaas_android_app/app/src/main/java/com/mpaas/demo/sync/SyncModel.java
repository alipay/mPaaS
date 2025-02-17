package com.mpaas.demo.sync;


import com.alibaba.j256.ormlite.field.DatabaseField;
import com.alibaba.j256.ormlite.table.DatabaseTable;

@DatabaseTable
public class SyncModel {
    @DatabaseField(generatedId = true)
    private int index;
    @DatabaseField
    private String msg;

    public SyncModel() {
    }

    public int getIndex() {
        return index;
    }

    public void setIndex(int index) {
        this.index = index;
    }

    public String getMsg() {
        return msg;
    }

    public void setMsg(String msg) {
        this.msg = msg;
    }

    @Override
    public String toString() {
        return "SyncModel{" +
                "index=" + index +
                ", msg='" + msg + '\'' +
                '}';
    }
}
