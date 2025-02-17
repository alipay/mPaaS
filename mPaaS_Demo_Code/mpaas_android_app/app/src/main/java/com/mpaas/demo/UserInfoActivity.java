package com.mpaas.demo;

import android.app.Activity;
import android.content.Intent;
import android.content.pm.PackageManager;
import android.net.Uri;
import android.os.Bundle;
import android.os.Handler;
import android.os.Looper;
import android.text.TextUtils;
import android.util.Log;
import android.view.View;
import android.widget.ImageView;
import android.widget.TextView;
import android.widget.Toast;

import androidx.annotation.NonNull;

import com.alipay.android.phone.mobilecommon.multimedia.api.MultimediaFileService;
import com.alipay.android.phone.mobilecommon.multimedia.api.data.APMultimediaTaskModel;
import com.alipay.android.phone.mobilecommon.multimedia.api.data.video.CompressLevel;
import com.alipay.android.phone.mobilecommon.multimedia.file.APFileUploadCallback;
import com.alipay.android.phone.mobilecommon.multimedia.file.data.APFileReq;
import com.alipay.android.phone.mobilecommon.multimedia.file.data.APFileUploadRsp;
import com.alipay.android.phone.mobilecommon.multimediabiz.biz.utils.AppUtils;
import com.alipay.mobile.beehive.photo.ui.VideoPreviewActivity;
import com.alipay.mobile.beehive.plugins.utils.GeneralUtils;
import com.alipay.mobile.beehive.service.PhotoInfo;
import com.alipay.mobile.beehive.service.PhotoParam;
import com.alipay.mobile.beehive.service.PhotoSelectListener;
import com.alipay.mobile.beehive.service.PhotoService;
import com.alipay.mobile.beehive.util.Logger;
import com.alipay.mobile.beehive.util.MicroServiceUtil;
import com.alipay.mobile.common.transport.utils.IOUtil;
import com.alipay.xmedia.alipayadapter.config.AlipayAdapterCloudConfig;
import com.bumptech.glide.Glide;
import com.bumptech.glide.load.resource.bitmap.CircleCrop;
import com.bumptech.glide.request.RequestOptions;
import com.mpaas.demo.model.UpdateUserInfoRequest;
import com.mpaas.demo.model.UpdateUserInfoResponse;
import com.mpaas.demo.model.UserBindAdkBean;
import com.mpaas.demo.model.UserInfoResult;
import com.mpaas.demo.request.WebapiMpaasMeetingUserinfoLoginPostReq;
import com.mpaas.demo.request.WebapiMpaasMeetingUserinfoUpdateuserinfoPostReq;
import com.mpaas.demo.rpc.LoginRequest;
import com.mpaas.demo.rpc.LoginResonse;
import com.mpaas.demo.rpc.MeetingManager;
import com.mpaas.demo.rpc.UserInfoSP;
import com.mpaas.demo.uicontrol.AeestesUtils;
import com.ta.utdid2.device.UTDevice;

import org.json.JSONException;
import org.json.JSONObject;

import java.io.File;
import java.util.List;

public class UserInfoActivity extends Activity implements View.OnClickListener {
    TextView tvName;
    TextView tvAccount;
    TextView tvPhone;
    TextView tvStart;
    TextView tvSkip;
    ImageView ivHeadPortrait;
    private UserInfoResult userInfo;
    private String type;
    public  String TAG="UserInfoActivity";
    private PhotoSelectListener mPhotoSelectListener;
    private int requestCodeWR=110;
    private String nickname;
    private String path;
    private String avatarAftsId;//选择跳过时userInfo为空
    String userId;

    private UserBindAdkBean mUserBindAdkBean;
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.mmga_activity_userinfo);
        userInfo = (UserInfoResult) getIntent().getSerializableExtra("UserInfo");
        type=getIntent().getStringExtra("type");
        toLogin(new Runnable() {
            @Override
            public void run() {
                runOnUiThread(new Runnable() {
                    @Override
                    public void run() {
                        initView();
                        initData();
                    }
                });
            }
        });

    }

    private void initData() {
        UserInfoSP.getInstance().getUserHead();
        if ("login".equals(type)){
            tvSkip.setVisibility(View.VISIBLE);
        }

        String phone=UserInfoSP.PHONE_NUMNER;
        if (!TextUtils.isEmpty(phone) && phone.length()>=11){
            phone = phone.substring(0, 3) + "****" + phone.substring(7, 11);
            tvPhone.setText(phone);
        }

        tvName.setText(UserInfoSP.USER_NAME);

        if(!TextUtils.isEmpty(UserInfoSP.USER_FILE)){
            Glide.with(UserInfoActivity.this)
                    .load(UserInfoSP.USER_FILE)
                    .apply(RequestOptions.bitmapTransform(new CircleCrop()))
                    .into(ivHeadPortrait);
        }
    }

    private void initView() {
        tvName = findViewById(R.id.tv_name);
        tvAccount = findViewById(R.id.tv_account);
        tvPhone = findViewById(R.id.tv_phone);
        tvStart = findViewById(R.id.tv_start);
        ivHeadPortrait = findViewById(R.id.iv_head_portrait);
        tvSkip = findViewById(R.id.tv_skip);
        findViewById(R.id.rl_name).setOnClickListener(this);
        tvSkip.setOnClickListener(this);
        tvStart.setOnClickListener(this);
        tvName.setOnClickListener(this);
        tvPhone.setOnClickListener(this);
        ivHeadPortrait.setOnClickListener(this);

    }

    @Override
    public void onClick(View v) {
        switch (v.getId()) {
            case R.id.tv_name:
            case R.id.rl_name:
                //if (userInfo==null)return;
//                Intent intent = new Intent(this, SetNicknameActivity.class);
//                if ("login".equals(type)){
//                    intent.putExtra("type","login");
//                }
//                if(!TextUtils.isEmpty(tvName.getText().toString())){
//                    userInfo.nickName = tvName.getText().toString();
//                }
//
//                intent.putExtra("UserInfo", userInfo);
//                startActivityForResult(intent,100);
                break;
            case R.id.tv_phone:
                break;
            case R.id.iv_head_portrait:
                if (PermissionUtils.askPermission(this, requestCodeWR)) {
                    //修改头像
                    selectPhoto(false, 60 * 1000, false, true);

                }
                break;
            case R.id.tv_start:
                toLogin(new Runnable() {
                    @Override
                    public void run() {
                    }
                });
//                if(tvSkip.getVisibility() ==View.VISIBLE){
//                    //第一次进入
//                    if(TextUtils.isEmpty(avatarAftsId)){
//                        //上传默认头像到后台
//                        upLoadDefuatURL();
//                    }else{
//                        //更新
//                        update();
//                    }
//
//                }else{
//                    //重复进入
//                    update();
//                }
                break;
             case R.id.tv_skip:
                /* if("login".equals(type)){
                     startActivity(new Intent(UserInfoActivity.this, MainActivity.class));
                 }*/

                 if(TextUtils.isEmpty("")){
                     //上传默认头像到后台
                     upLoadDefuatURL();
                 }else{
                     //更新
                     update();
                 }

                 /* if(LoginActivity.loginActivity!=null){
                     LoginActivity.loginActivity.finish();
                 }
                  finish();*/
                break;

        }

    }

    /**
     * 提交数据
     */
    public void update(){

        new Handler(Looper.getMainLooper()).post(new Runnable() {
            @Override
            public void run() {
                nickname=tvName.getText().toString().trim();

                if (TextUtils.isEmpty(nickname)){
                    if(tvSkip.getVisibility() ==View.VISIBLE){
                        nickname ="会小助"+UserInfoSP.PHONE_NUMNER;
                    }else{
                        ToastUtils.showToast(UserInfoActivity.this,"请编辑昵称");
                        return;
                    }
                }
                if ("login".equals(type) && userInfo!=null){
                    userInfo.nickName=nickname;
                    userInfo.userId=UserInfoSP.USER_ID;
                    userInfo.profilePhotoUrl=avatarAftsId;
                    userInfo.userToken=UserInfoSP.USER_TOKEN;
                }


                MeetingManager manager = MeetingManager.getInstance();
                manager.initRpc();
                manager.initRpcConfig();


                manager.taskService.parallelExecute(new Runnable() {
                    @Override
                    public void run() {
                        UpdateUserInfoRequest userBean = new UpdateUserInfoRequest();

                        if(TextUtils.isEmpty(avatarAftsId)){
                            // 没有选择图片, 用http头像
                            userBean.avatarAftsId = UserInfoSP.USER_FILE;
                            userBean.profilePhotoUrl = UserInfoSP.USER_FILE;
                        }else{
                            //选择了图片
                            userBean.avatarAftsId = avatarAftsId;
                            userBean.profilePhotoUrl = avatarAftsId;

                        }
                        userBean.phoneNumber =UserInfoSP.PHONE_NUMNER;
                        userBean.nickName = nickname;

                        Log.d(TAG,"profilePhotoUrl="+userBean.profilePhotoUrl +" avatarAftsId="+ userBean.avatarAftsId +" phoneNumber "+userBean.phoneNumber +"nickName="+userBean.nickName);

                        WebapiMpaasMeetingUserinfoUpdateuserinfoPostReq req = new WebapiMpaasMeetingUserinfoUpdateuserinfoPostReq();
                        req._requestBody = userBean;
                        UpdateUserInfoResponse updateUserInfo = manager.client.webapiMpaasMeetingUserinfoUpdateuserinfoPost(req);

                        if (updateUserInfo == null) return;
                        Log.d(TAG,updateUserInfo.toString());
                        runOnUiThread(new Runnable() {
                            @Override
                            public void run() {
                                if (updateUserInfo.success) {
//                                    MyFragment.isRefurbish = true;
                                    UserBindAdkBean userBindAdkBean = new UserBindAdkBean();

                                    String s= updateUserInfo.result;
                                    Log.d(TAG,s);
                                    String profilePhotoUrl ="";
                                    String nickName ="";
                                    String phoneNumber ="";
                                    try {
                                        JSONObject jsonObject = new JSONObject(s);
                                        if(jsonObject.has("nickName")){
                                            nickName  = jsonObject.getString("nickName");
                                        }
                                        if(jsonObject.has("phoneNumber")){
                                            phoneNumber  = jsonObject.getString("phoneNumber");
                                        }

                                        if(jsonObject.has("profilePhotoUrl")){
                                            profilePhotoUrl  = jsonObject.getString("profilePhotoUrl");
                                        }


                                        if(jsonObject.has("userId")){
                                            userId  = jsonObject.getString("userId");
                                        }

                                    } catch (JSONException e) {
                                        e.printStackTrace();
                                    }

                                    userBindAdkBean.setNicName(nickName);
                                    userBindAdkBean.setAvatarUrl(profilePhotoUrl);
                                    //userBindAdkBean.setUserAttachInfo(phoneNumber);
//                                    if (userBindAdkBean != null){
//                                        UserBindAsk.getInstance().setUpUserBindAsk(userBindAdkBean.getNicName(), var2.getAvatarUrl(), var2.getAvatarAftsId(), var2.getUserAttachInfo());
//                                    }
//
//                                    MPContent.getInstance().resetUserId(UserInfoSP.USER_ID);


                                    UserInfoSP.getInstance().setUserInfo(UserInfoActivity.this,userInfo);
                                    if("login".equals(type)){
                                        startActivity(new Intent(UserInfoActivity.this, MainActivity.class));
                                    }

                                    //这里没
                                    UserInfoSP.getInstance().setUserHead(profilePhotoUrl,nickName,"");
//                                    if(LoginActivity.loginActivity!=null){
//                                        LoginActivity.loginActivity.finish();
//                                    }
                                    finish();

                                } else {

//                                    Toast.makeText(UserInfoActivity.this, updateUserInfo.errorMsg, Toast.LENGTH_SHORT).show();
                                }
                            }
                        });


                    }
                }, "rpc-get-webapiMpaasMeetingUserinfoUpdateuserinfoPost");
            }
        });

    }

    @Override
    protected void onActivityResult(int requestCode, int resultCode, Intent data) {
        super.onActivityResult(requestCode, resultCode, data);
        if (requestCode == 100 && resultCode == Activity.RESULT_OK) {
            if (data != null) {
                 nickname = data.getStringExtra("nickname");
                 tvName.setText(nickname);
            }
        }
    }
    private void selectPhoto(boolean isVideoEditEnable, int maxDuration, boolean isCompressed, boolean isShowVideoTimeIndicator) {

        mPhotoSelectListener = new PhotoSelectListener() {
            @Override
            public void onPhotoSelected(List<PhotoInfo> imageList, Bundle bundle) {
                //释放资源
                mPhotoSelectListener = null;
                if (imageList == null || imageList.size() < 1) {
                    return;
                }
                PhotoInfo videoInfo = imageList.get(0);
                Log.d(TAG, "onPhotoSelected: " + imageList.size() + "张");
                for (PhotoInfo v: imageList) {
                    Log.d(TAG, "onPhotoSelected: " + v.getPhotoPath());
                }
                MultimediaFileService multimediaFileService = AppUtils.getFileService();
                APFileReq fileReq = new APFileReq();
                path = Uri.parse(videoInfo.getPhotoPath()).getPath();

                File imgFile=new File(path);

                Log.d(TAG, "onPhotoSelected: path: " + path);
                AlipayAdapterCloudConfig.getConf().fulllinkTrackerUnavailable = 0;
                fileReq.setUploadData(IOUtil.fileToByte(imgFile));
                multimediaFileService.upLoad(fileReq, new APFileUploadCallback() {
                    @Override
                    public void onUploadStart(APMultimediaTaskModel apMultimediaTaskModel) {
                        Log.d(TAG, "onUploadStart() called with: apMultimediaTaskModel = [" + apMultimediaTaskModel + "]");
                    }

                    @Override
                    public void onUploadProgress(APMultimediaTaskModel apMultimediaTaskModel, int i, long l, long l1) {
                        Log.d(TAG, "onUploadProgress() called with: apMultimediaTaskModel = [" + apMultimediaTaskModel + "], i = [" + i + "], l = [" + l + "], l1 = [" + l1 + "]");
                    }

                    @Override
                    public void onUploadFinished(APMultimediaTaskModel apMultimediaTaskModel, APFileUploadRsp apFileUploadRsp) {
                        Log.d(TAG, "onUploadFinished() called with: apMultimediaTaskModel = [" + apMultimediaTaskModel + "], apFileUploadRsp = [" + apFileUploadRsp + "]");
                      /* if(userInfo ==null){
                           avatarAftsId = apFileUploadRsp.getFileReq().getCloudId();
                       }else {
                           userInfo.avatarAftsId = apFileUploadRsp.getFileReq().getCloudId();
                       }*/

                        avatarAftsId = apFileUploadRsp.getFileReq().getCloudId();

                        runOnUiThread(new Runnable() {
                            @Override
                            public void run() {
                                //在这里设置了两遍图片是因为第一次不显示，第二次才显示。我也很懵逼先这样解决吧
                                Glide.with(UserInfoActivity.this)
                                        .load(imgFile)
                                        .apply(RequestOptions.bitmapTransform(new CircleCrop()))
                                        .into(ivHeadPortrait);

                                Glide.with(UserInfoActivity.this)
                                        .load(imgFile)
                                        .apply(RequestOptions.bitmapTransform(new CircleCrop()))
                                        .into(ivHeadPortrait);



                            }
                        });


                    }

                    @Override
                    public void onUploadError(APMultimediaTaskModel apMultimediaTaskModel, APFileUploadRsp apFileUploadRsp) {
                        Log.d(TAG, "onUploadError() called with: apMultimediaTaskModel = [" + apMultimediaTaskModel + "], apFileUploadRsp = [" + apFileUploadRsp + "]");
                    }
                });
            }

            @Override
            public void onSelectCanceled() {
                //释放资源
                mPhotoSelectListener = null;


            }
        };

        Bundle params = new Bundle();
        //宫格选图页面不展示拍摄入口
        params.putBoolean(PhotoParam.ENABLE_CAMERA, false);
        params.putInt(PhotoParam.MAX_SELECT,1);

        params.putString("businessId", "MCMP");
        if (isCompressed) {
            //如果要压缩，就都走编辑预览
            if (!isVideoEditEnable) {
                //如果要压缩又不编辑，那就在编辑预览隐藏编辑入口；复用编辑预览的压缩功能
                params.putBoolean(VideoPreviewActivity.KEY_HIDE_EDIT, true);
            }
            isVideoEditEnable = true;//这里还是要走预览逻辑
            params.putInt(PhotoParam.KEY_VIDEO_COMPRESS_LEVEL, CompressLevel.V720P.getValue());//
        }
        if (isVideoEditEnable) {
            params.putBoolean(PhotoParam.ENABLE_VIDEO_CUT, true);
            params.putInt(PhotoParam.VIDEO_TIME_LIMIT, maxDuration);
        }
        try {
            //选择照片
            params.putString(PhotoParam.FINISH_TEXT, GeneralUtils.getBeehiveBundleResources().getString(com.alipay.mobile.beephoto.R.string.str_default_choose_img));
        } catch (Throwable tr) {
            Logger.w(TAG, "Get string res exception." + tr.getMessage());
        }

        PhotoService ps = MicroServiceUtil.getMicroService(PhotoService.class);
        if (ps == null) {
//            notifyFail(bridgeContext, ERROR_INTERNAL, "Can't get PhotoService.");
            return;
        }
        ps.selectPhoto(GeneralUtils.getTopApplication(), params, mPhotoSelectListener);
    }

    @Override
    public void onRequestPermissionsResult(int requestCode, @NonNull String[] permissions, @NonNull int[] grantResults) {
        super.onRequestPermissionsResult(requestCode, permissions, grantResults);
        if(requestCode == requestCodeWR){
            if (grantResults[0] == PackageManager.PERMISSION_GRANTED) {
                //修改头像
                selectPhoto(false, 60 * 1000, false, true);
            } else {
//                CheckPermissionDialog dialog = CheckPermissionDialog.getInstance(this);
//                dialog.init().show();
            }
        }

    }

    @Override
    protected void onDestroy() {
        super.onDestroy();
        if (mPhotoSelectListener!=null){
            mPhotoSelectListener = null;
        }
    }

    /*上传默默头像*/
    private void upLoadDefuatURL(){
        MultimediaFileService multimediaFileService = AppUtils.getFileService();
        APFileReq fileReq = new APFileReq();


        AlipayAdapterCloudConfig.getConf().fulllinkTrackerUnavailable = 0;

        fileReq.setUploadData(AeestesUtils.getDefaultIcon(UserInfoActivity.this));

        multimediaFileService.upLoad(fileReq, new APFileUploadCallback() {
            @Override
            public void onUploadStart(APMultimediaTaskModel apMultimediaTaskModel) {
                Log.d(TAG, "onUploadStart() called with: apMultimediaTaskModel = [" + apMultimediaTaskModel + "]");
            }

            @Override
            public void onUploadProgress(APMultimediaTaskModel apMultimediaTaskModel, int i, long l, long l1) {
                Log.d(TAG, "onUploadProgress() called with: apMultimediaTaskModel = [" + apMultimediaTaskModel + "], i = [" + i + "], l = [" + l + "], l1 = [" + l1 + "]");
            }

            @Override
            public void onUploadFinished(APMultimediaTaskModel apMultimediaTaskModel, APFileUploadRsp apFileUploadRsp) {
                avatarAftsId = apFileUploadRsp.getFileReq().getCloudId();

                update();
            }

            @Override
            public void onUploadError(APMultimediaTaskModel apMultimediaTaskModel, APFileUploadRsp apFileUploadRsp) {
                Log.d(TAG, "onUploadError() called with: apMultimediaTaskModel = [" + apMultimediaTaskModel + "], apFileUploadRsp = [" + apFileUploadRsp + "]");
            }
        });
    }

    /**
     * 登录
     */
    private void toLogin(Runnable runnable) {

        String phone = "15600000000";
        String code = "123456";
        //如果没有手机号就不请求
        if (TextUtils.isEmpty(phone)) {
            ToastUtils.showToast(this, "请输入11位手机号");
            return;
        }
        if(TextUtils.isEmpty(code)){
            ToastUtils.showToast(this, "请输入6位验证码");
            return;
        }
        //登录
        MeetingManager manager = MeetingManager.getInstance();
        if (manager.client == null || manager.taskService == null) {
            manager.initRpc();
            manager.initRpcConfig();
        }
        manager.taskService.parallelExecute(new Runnable() {
            @Override
            public void run() {
                LoginRequest loginRequest = new LoginRequest();
                loginRequest.phoneNumber = phone;
                loginRequest.smsCode = code;
                loginRequest.pushId = "mpaas_push_demo";
                Log.d("upload_request", "requestUrl: {" +
                        "nickName: " + nickname + "\n" +
                        "phoneNum: " + phone + "\n" +
                        "profileAftsId: " + avatarAftsId + "\n" +
                        "userId: " + userId + " }");
                WebapiMpaasMeetingUserinfoLoginPostReq req = new WebapiMpaasMeetingUserinfoLoginPostReq();
                req._requestBody = loginRequest;
                LoginResonse loginResonse = manager.client.webapiMpaasMeetingUserinfoLoginPost(req);
                if (loginResonse == null) return;
                runOnUiThread(new Runnable() {
                    @Override
                    public void run() {
                        if (loginResonse.success) {

                            if (loginResonse.result != null) {
                                // 保存用户数据
                                UserInfoResult userInfoResult=loginResonse.result;
                                userInfoResult.phoneNumber=phone;
                                UserInfoSP.getInstance().setUserInfo(UserInfoActivity.this,userInfoResult);
                                UserBindAdkBean userBindAdkBean = new UserBindAdkBean();
                                userBindAdkBean.setNicName(userInfoResult.nickName);
                                userBindAdkBean.setAvatarUrl(userInfoResult.profilePhotoUrl);

                                userBindAdkBean.setUserAttachInfo(userInfoResult.phoneNumber);
                                mUserBindAdkBean = userBindAdkBean;
                                //同步头像昵称

                                Log.d("upload_request", "requestUrl: {" +
                                        "nickName: " + userInfoResult.nickName + "\n" +
                                        "phoneNum: " + userInfoResult.phoneNumber + "\n" +
                                        "profilePhotoUrl: " + userInfoResult.profilePhotoUrl + "\n" +
                                        "userId: " + userInfoResult.userId + " }");
                                userId = userInfoResult.userId;
                                UserInfoSP.getInstance().setUserHead(userInfoResult.profilePhotoUrl ,userInfoResult.nickName ,userInfoResult.phoneNumber);
                                //进入主页
//                                startActivity(new Intent(UserInfoActivity.this, MainActivity.class));
//                                finish();

                                runnable.run();

                            }
//                            else {
//                                //是否需要进入编辑昵称
//                                UserInfoResult userInfoResult=new UserInfoResult();
//                                userInfoResult.phoneNumber=  phone;
//                                UserInfoSP.getInstance().setUserHead("" ,"",userInfoResult.phoneNumber);
//                                Intent intent = new Intent(LoginActivity.this, UserInfoActivity.class);
//                                intent.putExtra("type","login");
//                                intent.putExtra("UserInfo", userInfoResult);
//                                startActivity(intent);
//                            }

                        } else {
                            Toast.makeText(UserInfoActivity.this, loginResonse.errorMsg, Toast.LENGTH_SHORT).show();
                        }
                    }
                });


            }
        }, "rpc-get-webapiMpaasMeetingUserinfoLoginPost");
    }
}