package com.mpaas.demo.uicontrol.storage.api;


import com.alibaba.j256.ormlite.field.DatabaseField;
import com.alibaba.j256.ormlite.table.DatabaseTable;

// 数据库表名，默认为类名
@DatabaseTable
public class User {
    // 主键
    @DatabaseField(generatedId = true)
    public int id;
    // name字段唯一
    @DatabaseField(unique = true)
    public String name;
    @DatabaseField
    public int color;
    @DatabaseField
    public long timestamp;
}

