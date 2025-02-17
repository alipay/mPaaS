package com.mpaas.demo.model;

public class UserBindAdkBean {
    private String nicName;
    private String avatarUrl;
    private String avatarAftsId;
    private String userAttachInfo;

    public UserBindAdkBean() {
    }

    public UserBindAdkBean(String var1, String var2, String var3) {
        this.nicName = var1;
        this.avatarUrl = var2;
        this.userAttachInfo = var3;
    }

    public String getNicName() {
        return this.nicName;
    }

    public void setNicName(String var1) {
        this.nicName = var1;
    }

    public String getAvatarUrl() {
        return this.avatarUrl;
    }

    public void setAvatarUrl(String var1) {
        this.avatarUrl = var1;
    }

    public String getAvatarAftsId() {
        return this.avatarAftsId;
    }

    public void setAvatarAftsId(String var1) {
        this.avatarAftsId = var1;
    }

    public String getUserAttachInfo() {
        return this.userAttachInfo;
    }

    public void setUserAttachInfo(String var1) {
        this.userAttachInfo = var1;
    }
}
