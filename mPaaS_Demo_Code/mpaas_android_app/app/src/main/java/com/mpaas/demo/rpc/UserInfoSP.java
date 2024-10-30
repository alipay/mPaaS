package com.mpaas.demo.rpc;

import android.content.Context;
import android.content.SharedPreferences;
import android.text.TextUtils;
import android.util.Log;

import com.alibaba.fastjson.JSON;
import com.mpaas.demo.MainApplication;
import com.mpaas.demo.model.UserInfoResult;
import com.mpaas.mps.adapter.api.MPPush;

import alipay.yunpushcore.rpc.ResultPbPB;

public class UserInfoSP {
    public static UserInfoSP userInfoSP = new UserInfoSP();
    private SharedPreferences mCacheSp;
    private String USER_INFO = "userInfo";
    private String SP_KYE = "mmga_user_info";

    private String SP_USER_ID = "user_id";
    private String SP_USER_TOKEN = "user_token";
    private String SP_PRIVACY = "privacy_dialog";

    private String SP_USER_HEAD = "user_head";
    private String SP_USER_NAME = "user_name";
    private String SP_PHONE_NUMNER= "phoneNumber";
    private String SP_NOTIFI_DIALOG_SHOW= "notifi_dialog";

    public static String USER_TOKEN = "";
    public static String USER_ID = "";
    public static boolean privacy_dialog_show = false;
    public static String USER_FILE = "";//头像
    public static String USER_NAME = "";//昵称
    public static String AVATARAFTSID ="";//头像的id
    public static String PHONE_NUMNER ="";//手机号
    public static String ADTOKEN ="";//推送的token

    public static boolean NOTIFI_DIALOG_SHOW = false;//通知权限提示弹框

    public static UserInfoSP getInstance() {
        return userInfoSP;
    }

    /**
     * 保存用户信息
     *
     * @param context
     * @param userInfoResult
     */
    public void setUserInfo(Context context, UserInfoResult userInfoResult) {
        if (userInfoResult == null) return;
//        USER_TOKEN = userInfoResult.userToken;
        mCacheSp = context.getSharedPreferences(SP_KYE, Context.MODE_PRIVATE);
        SharedPreferences.Editor editor = mCacheSp.edit();
        editor.putString(USER_INFO, JSON.toJSONString(userInfoResult));
        editor.apply();
    }

    /**
     * 获取用户信息
     *
     * @param context
     */
    public UserInfoResult getUserInfo(Context context) {

        mCacheSp = context.getSharedPreferences(SP_KYE, Context.MODE_PRIVATE);
        String userInfo = mCacheSp.getString(USER_INFO, "");
        if (TextUtils.isEmpty(userInfo)) {
            return null;
        }
        UserInfoResult userInfoResult = JSON.parseObject(userInfo, UserInfoResult.class);
        if (userInfoResult == null) return null;

        getUserResponse();

        return userInfoResult;
    }

    /**
     *  保存用户请求使用的数据
     * @param userId
     * @param userToken
     */
    public void setUserResponse(String userId,String userToken) {
        Context context= MainApplication.getContext().getApplicationContext();
        mCacheSp = context.getSharedPreferences(SP_KYE, Context.MODE_PRIVATE);
        SharedPreferences.Editor editor = mCacheSp.edit();
        if (!TextUtils.isEmpty(userId)){
            editor.putString(SP_USER_ID, userId);
        }
        if (!TextUtils.isEmpty(userToken)){
            editor.putString(SP_USER_TOKEN, userToken);
        }
        editor.apply();
    }



    /**
     * 获取用户请求需要的数据
     */
    public void getUserResponse() {
        Context context= MainApplication.getContext().getApplicationContext();
        mCacheSp = context.getSharedPreferences(SP_KYE, Context.MODE_PRIVATE);
        USER_ID=mCacheSp.getString(SP_USER_ID, "");
        USER_TOKEN=mCacheSp.getString(SP_USER_TOKEN, "");
    }


    /**
     *  保存用户隐私权限
     * @param privacyDialog
     */
    public void setPrivacyDialog(boolean privacyDialog) {
        Context context= MainApplication.getContext().getApplicationContext();
        mCacheSp = context.getSharedPreferences(SP_KYE, Context.MODE_PRIVATE);
        SharedPreferences.Editor editor = mCacheSp.edit();
        editor.putBoolean(SP_PRIVACY, privacyDialog);
        editor.apply();
    }



    /**
     * 获取用户请求需要的数据
     */
    public void getPrivacyDialog() {
        Context context= MainApplication.getContext().getApplicationContext();
        mCacheSp = context.getSharedPreferences(SP_KYE, Context.MODE_PRIVATE);
        privacy_dialog_show = mCacheSp.getBoolean(SP_PRIVACY, false);
    }


    /**
     *   推送通知的弹框
     */
    public void setNotifiDialog(boolean isShowNotifiDialog) {
        Context context= MainApplication.getContext().getApplicationContext();
        mCacheSp = context.getSharedPreferences(SP_KYE, Context.MODE_PRIVATE);
        SharedPreferences.Editor editor = mCacheSp.edit();
        editor.putBoolean(SP_NOTIFI_DIALOG_SHOW, isShowNotifiDialog);
        editor.apply();
    }



    /**
     * 获取用户请求需要的数据
     */
    public void getNotifiDialog() {
        Context context= MainApplication.getContext().getApplicationContext();
        mCacheSp = context.getSharedPreferences(SP_KYE, Context.MODE_PRIVATE);
        NOTIFI_DIALOG_SHOW = mCacheSp.getBoolean(SP_NOTIFI_DIALOG_SHOW, false);
    }


    /**
     *  保存用户头像的本地file地址
     */
    public void setUserHead(String headStr ,String name ,String phonenum) {
        Context context= MainApplication.getContext().getApplicationContext();
        mCacheSp = context.getSharedPreferences(SP_KYE, Context.MODE_PRIVATE);
        SharedPreferences.Editor editor = mCacheSp.edit();
        if(!TextUtils.isEmpty(headStr)){
            editor.putString(SP_USER_HEAD, headStr);
        }

        if(!TextUtils.isEmpty(name)){
            editor.putString(SP_USER_NAME, name);
        }

       /* if(!TextUtils.isEmpty(avatarAftsId)){
            editor.putString(SP_USER_HEAD_AVATARAFTSID, avatarAftsId);
        }*/

        if(!TextUtils.isEmpty(phonenum)){
            editor.putString(SP_PHONE_NUMNER, phonenum);
        }

        editor.apply();
    }

    public void cleanUserInfo() {
        Context context= MainApplication.getContext().getApplicationContext();
        mCacheSp = context.getSharedPreferences(SP_KYE, Context.MODE_PRIVATE);
        SharedPreferences.Editor editor = mCacheSp.edit();


        editor.putString(SP_USER_ID, "");
        editor.putString(SP_USER_TOKEN, "");
        editor.putString(SP_USER_HEAD, "");
        editor.putString(SP_USER_NAME, "");
        editor.putString(SP_PHONE_NUMNER, "");
        editor.apply();
    }



    /**
     * 获取用户头像的本地file地址,name
     */
    public void getUserHead() {
        Context context= MainApplication.getContext().getApplicationContext();
        mCacheSp = context.getSharedPreferences(SP_KYE, Context.MODE_PRIVATE);
        USER_FILE = mCacheSp.getString(SP_USER_HEAD,"");
        USER_NAME = mCacheSp.getString(SP_USER_NAME,"");
        PHONE_NUMNER = mCacheSp.getString(SP_PHONE_NUMNER,"");
    }

    /**
     * 清空sp 缓存数据
     */
    public void clear() {

        //推送解除绑定

        USER_ID="";
        USER_TOKEN="";
        USER_NAME ="";
        USER_FILE="";
        ADTOKEN ="";
        privacy_dialog_show = false;
        AVATARAFTSID ="";//头像的id
        PHONE_NUMNER ="";//手机号

        Context context= MainApplication.getContext().getApplicationContext();
        mCacheSp = context.getSharedPreferences(SP_KYE, Context.MODE_PRIVATE);
        SharedPreferences.Editor editor = mCacheSp.edit();
        editor.clear();
        editor.apply();
    }

    /**
     * 清空sp 缓存数据
     */
    public void clearUser() {

        //推送解除绑定

        USER_ID="";
        USER_TOKEN="";
        PHONE_NUMNER ="";
        AVATARAFTSID ="";
        USER_NAME ="";
        cleanUserInfo();
    }


    /*推送解除绑定*/
    public void unbindPush(Context context){
        new Thread(new Runnable() {
            @Override
            public void run() {
                // ResultPbPB unbindResult = MPPush.unbind(context, USER_ID, ADTOKEN);
                //Log.d("pushTag","解除绑定 userId " + (unbindResult.success ? "成功" : ("错误：" + unbindResult.code)));
            }
        }).start();
    }


    /*推送*/
    public void bindPush(Context context){
        new Thread(new Runnable() {
            @Override
            public void run() {
                try {
                    ResultPbPB bindResult = MPPush.bind(context, USER_ID, ADTOKEN);
                    Log.d("pushTag","绑定 userId " + (bindResult.success ? "成功" : ("错误：" + bindResult.code)));
                } catch (Exception e) {
                    e.printStackTrace();
                }
            }
        }).start();
    }
}
