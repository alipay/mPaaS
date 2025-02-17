package com.example.share.share;

import android.content.Context;
import android.os.Bundle;
import android.text.ClipboardManager;
import android.view.View;
import android.widget.AdapterView;
import android.widget.RadioButton;
import android.widget.RadioGroup;
import android.widget.Toast;

import com.alipay.android.shareassist.constants.ShareExtraInfoConstant;
import com.alipay.mobile.antui.basic.AUButton;
import com.alipay.mobile.antui.basic.AUTitleBar;
import com.alipay.mobile.antui.dialog.AUListDialog;
import com.alipay.mobile.common.share.ShareContent;
import com.alipay.mobile.common.share.constant.ShareType;
import com.alipay.mobile.framework.app.ui.BaseActivity;
import com.alipay.mobile.framework.service.ShareService;
import com.alipay.mobile.h5container.api.H5Bundle;
import com.alipay.mobile.h5container.api.H5Param;
import com.alipay.mobile.h5container.service.H5Service;
import com.example.share.R;
import com.mpaas.framework.adapter.api.MPFramework;

import java.io.ByteArrayOutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.util.ArrayList;
import java.util.HashMap;

public class ShareActivity1 extends BaseActivity {
    private AUButton mShareBtn;
    private AUButton mGetInstructionsBtn;

    private final ArrayList<String> mData = new ArrayList<>();

    private H5Service mH5Service;
    private ShareService service;

    private ShareListener mShareListener;

    private byte[] mWechatDefaultIconBytes;

    private AUTitleBar mTitle;
    private RadioGroup rgRoot;
    private RadioButton rbUrl;
    private RadioButton rbImg;
    private RadioButton rbTxt;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_share);
        initData();
        initService();
        initListener();
        initWechatDefaultIcon();
        findView();
        initView();
    }

    /**
     * 初始化数据
     */
    private void initData() {
        mData.clear();
        mData.add(getString(R.string.alipay));
        mData.add(getString(R.string.wechat));
        mData.add(getString(R.string.wechat_timeline));
        mData.add(getString(R.string.weibo));
        mData.add(getString(R.string.qq));
        mData.add(getString(R.string.qzone));
        mData.add(getString(R.string.dingding));
        mData.add(getString(R.string.sms));
        mData.add(getString(R.string.copylink));
    }

    /**
     * 初始化Img数据
     */
    private void initImgData() {
        mData.clear();
        mData.add(getString(R.string.alipay));
        mData.add(getString(R.string.wechat));
        mData.add(getString(R.string.wechat_timeline));
        mData.add(getString(R.string.weibo));
//        mData.add(getString(R.string.qq));
//        mData.add(getString(R.string.qzone));
//        mData.add(getString(R.string.dingding));
        mData.add(getString(R.string.sms));
    }

    /**
     * 初始化Txt数据
     */
    private void initTxtData() {
        mData.clear();
//        mData.add(getString(R.string.alipay));
        mData.add(getString(R.string.wechat));
        mData.add(getString(R.string.wechat_timeline));
        mData.add(getString(R.string.weibo));
//        mData.add(getString(R.string.qq));
//        mData.add(getString(R.string.qzone));
//        mData.add(getString(R.string.dingding));
        mData.add(getString(R.string.sms));
    }

    /**
     * 初始化service
     */
    private void initService() {
        mH5Service = MPFramework.getExternalService(H5Service.class.getName());
        service = MPFramework.getExternalService(ShareService.class.getName());
    }

    /**
     * 初始化分享回调
     */
    private void initListener() {
        mShareListener = new ShareListener(this);
    }

    private void initWechatDefaultIcon() {
        ByteArrayOutputStream outputStream = null;
        try {
            InputStream inputStream = getResources().getAssets().open("share/appicon.png");
            outputStream = new ByteArrayOutputStream();
            byte[] bytes = new byte[1024];
            while (inputStream.read(bytes) != -1) {
                outputStream.write(bytes, 0, bytes.length);
            }
            outputStream.close();
            inputStream.close();
        } catch (IOException e) {
            e.printStackTrace();
        }
        mWechatDefaultIconBytes = outputStream.toByteArray();
    }

    private void findView() {
        rgRoot = ((RadioGroup) findViewById(R.id.rg_root));
        rbUrl = ((RadioButton) findViewById(R.id.rb_url));
        rbImg = ((RadioButton) findViewById(R.id.rb_img));
        rbTxt = ((RadioButton) findViewById(R.id.rb_txt));
        mTitle = ((AUTitleBar) findViewById(R.id.title_atb));
        mShareBtn = (AUButton) findViewById(R.id.share_share_btn);
        mGetInstructionsBtn = (AUButton) findViewById(R.id.share_get_instructions_btn);
        rgRoot.setOnCheckedChangeListener(new RadioGroup.OnCheckedChangeListener() {
            @Override
            public void onCheckedChanged(RadioGroup group, int checkedId) {
                if (checkedId == R.id.rb_url) {
                    initData();
                    return;
                }
                if (checkedId == R.id.rb_img) {
                    initImgData();
                    return;
                }
                if (checkedId == R.id.rb_txt) {
                    initTxtData();
                    return;
                }
            }
        });
    }

    private void initView() {
        mTitle.setTitleText(getString(R.string.share));
        mTitle.getRightButtonIconView().setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                Toast.makeText(ShareActivity1.this, "hhhhhhhh", Toast.LENGTH_SHORT).show();
//                MenuPopupWindow popupWindow = new MenuPopupWindow(ShareActivity.this);
//                popupWindow.showAsDropDown(mTitle.getRightButtonIconView(), 0, 0);
            }
        });
        mShareBtn.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                initShareDialog();
            }
        });
        mGetInstructionsBtn.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                // 启动H5容器，打开mPaaS社交分享文档网页
                Bundle param = new Bundle();
                param.putString(H5Param.LONG_URL, "https://www.cloud.alipay.com/docs/2/49577");
                H5Bundle bundle = new H5Bundle();
                bundle.setParams(param);
                mH5Service.startPage(MPFramework.getMicroApplicationContext().findTopRunningApp(), bundle);
            }
        });
    }

    //初始化分享弹窗
    private void initShareDialog() {
        AUListDialog mShareDialog = new AUListDialog(ShareActivity1.this, mData);
        mShareDialog.show();
        mShareDialog.setOnItemClickListener(new AdapterView.OnItemClickListener() {
            @Override
            public void onItemClick(AdapterView<?> adapterView, View view, int i, long l) {
                String shareMsg = mData.get(i);
                if (getString(R.string.alipay).equals(shareMsg)) {
                    shareToAlipay();
                    return;
                }
                if (getString(R.string.wechat).equals(shareMsg)) {
                    shareToWechat();
                    return;
                }
                if (getString(R.string.wechat_timeline).equals(shareMsg)) {
                    shareToWechatTimeline();
                    return;
                }
                if (getString(R.string.weibo).equals(shareMsg)) {
                    shareToWeibo();
                    return;
                }
                if (getString(R.string.qq).equals(shareMsg)) {
                    shareToQQ();
                    return;
                }
                if (getString(R.string.qzone).equals(shareMsg)) {
                    shareToQZone();
                    return;
                }
                if (getString(R.string.dingding).equals(shareMsg)) {
                    shareToDingDing();
                    return;
                }
                if (getString(R.string.sms).equals(shareMsg)) {
                    shareToSms();
                    return;
                }
                if (getString(R.string.copylink).equals(shareMsg)) {
                    try {
                        ClipboardManager clipboardManager = (ClipboardManager) getSystemService(Context.CLIPBOARD_SERVICE);
                        clipboardManager.setText("https://www.aliyun.com");
                        Toast.makeText(ShareActivity1.this, "已复制到粘贴板", Toast.LENGTH_SHORT).show();
                    } catch (Exception e) {
                        e.printStackTrace();
                    }
                    return;
                }
            }
        });
    }

    /**
     * 分享到支付宝
     */
    private void shareToAlipay() {
        service.initAlipayContact("2016111102737103");
        ShareContent content = createShareContent(ShareType.SHARE_TYPE_ALIPAY);
        service.setShareActionListener(mShareListener);
        service.silentShare(content, ShareType.SHARE_TYPE_ALIPAY, "test");
    }

    /**
     * 分享到微信好友
     */
    private void shareToWechat() {
        service.initWeixin("wxa077a4686304b04a", "e9c754349381d16cd88a1df19592cc23");
        ShareContent content = createShareContent(ShareType.SHARE_TYPE_WEIXIN);
//        setWechatDefaultIcon(content);
        service.setShareActionListener(mShareListener);
        service.silentShare(content, ShareType.SHARE_TYPE_WEIXIN, "test");
    }

    /**
     * 分享到微信朋友圈
     */
    private void shareToWechatTimeline() {
        service.initWeixin("wxa077a4686304b04a", "e9c754349381d16cd88a1df19592cc23");
        ShareContent content = createShareContent(ShareType.SHARE_TYPE_WEIXIN_TIMELINE);
        setWechatDefaultIcon(content);
        service.setShareActionListener(mShareListener);
        service.silentShare(content, ShareType.SHARE_TYPE_WEIXIN_TIMELINE, "test");
    }

    /**
     * 分享到微博
     */
    private void shareToWeibo() {
        service.initWeiBo("1095133729", "eba90f2ef316f8106fd8b6507b44fcb5", "http://alipay.com");
        ShareContent content = createShareContent(ShareType.SHARE_TYPE_WEIBO);
        service.setShareActionListener(mShareListener);
        service.silentShare(content, ShareType.SHARE_TYPE_WEIBO, "test");
    }

    /**
     * 分享到QQ
     */
    private void shareToQQ() {
        service.initQQ("1104122330");
        ShareContent content = createShareContent(ShareType.SHARE_TYPE_QQ);
        content.setFileProviderAuthority("com.mpaas.demo.fileprovider");
        service.setShareActionListener(mShareListener);
        service.silentShare(content, ShareType.SHARE_TYPE_QQ, "test");
    }

    /**
     * 分享到QZone
     */
    private void shareToQZone() {
        service.initQZone("1104122330");
        ShareContent content = createShareContent(ShareType.SHARE_TYPE_QZONE);
        service.setShareActionListener(mShareListener);
        service.silentShare(content, ShareType.SHARE_TYPE_QZONE, "test");
    }

    /**
     * 分享到钉钉
     */
    private void shareToDingDing() {
        service.initDingDing("dingoa7rxo7sxowhwpg5ke");
        ShareContent content = createShareContent(ShareType.SHARE_TYPE_DINGDING);
        service.setShareActionListener(mShareListener);
        service.silentShare(content, ShareType.SHARE_TYPE_DINGDING, "test");
    }


    /**
     * 分享到短信
     */
    private void shareToSms() {
        ShareContent content = createShareContent(ShareType.SHARE_TYPE_SMS);
        service.setShareActionListener(mShareListener);
        service.silentShare(content, ShareType.SHARE_TYPE_SMS, "test");
    }

    /**
     * 生成分享内容
     *
     * @return 分享内容
     */
    private ShareContent createShareContent(int shareType) {
        if (rbImg.isChecked()) {
            return linkImg(shareType);
        } else if (rbTxt.isChecked()) {
            return linkTxt(shareType);
        }
        return linkUrl();
    }

    private ShareContent linkUrl() {
        final ShareContent content = new ShareContent();
        // 设置分享内容
        content.setContent("mPaaS share content");
        // 设置分享类型，分享链接请选择"url"
        content.setContentType("url");
        // 设置分享标题
        content.setTitle("mPaaS share title");
        // 设置分享图片地址，微信分享请保证图片小于32KB
        content.setImgUrl("https://gw.alipayobjects.com/zos/rmsportal/WqYuuhbhRSCdtsyNOKPv.png");
        // 此image url为一张超过32KB的大图，用于测试微信分享超过32KB时，默认icon的功能
//        content.setImgUrl("http://seopic.699pic.com/photo/00026/7248.jpg_wh1200.jpg");
        // 设置分享链接
//        content.setUrl("https://www.cloud.alipay.com/products/MPAAS");
        // QZone分享会默认屏蔽alipay.com的域名，测试QZone时，请注释掉上面代码，改为百度首页即可。
        content.setUrl("https://www.aliyun.com");
        return content;
    }

    private ShareContent linkImg(int shareType) {
        final ShareContent content = new ShareContent();
        // 设置分享类型，分享链接请选择"url"
        content.setContentType("image");
        // 设置分享标题
        content.setTitle("mPaaS share title");
        // 设置分享内容
        content.setContent("mPaaS share content");
        content.setUrl(null);
        content.setImgUrl("https://img2.baidu.com/it/u=2351089872,2261950289&fm=253&fmt=auto&app=138&f=JPEG?w=281&h=500");
//        if (shareType == ShareType.SHARE_TYPE_QZONE) {
////         设置分享图片地址，微信分享请保证图片小于32KB
////            content.setImgUrl("https://gw.alipayobjects.com/zos/rmsportal/WqYuuhbhRSCdtsyNOKPv.png");
//            content.setImgUrl("https://static.www.tencent.com/uploads/2020/11/19/1da49ef5c90e991fcdda77fab8d8f15c.png");
////            content.setImgUrl("file:///storage/emulated/0/Pictures/Screenshots/01.jpg");
//        } else {
//            content.setImage(mWechatDefaultIconBytes);
//        }
        return content;
    }

    private ShareContent linkTxt(int shareType) {
        final ShareContent content = new ShareContent();
        // 设置分享类型，分享链接请选择"url"
        if (shareType == ShareType.SHARE_TYPE_WEIBO) {
            content.setUrl(" ");
            content.setImage(null);
            content.setImgUrl(null);
        } else if (shareType == ShareType.SHARE_TYPE_WEIXIN
                || shareType == ShareType.SHARE_TYPE_WEIXIN_TIMELINE) {
            content.setUrl(null);
            content.setImage(null);
            content.setImgUrl(null);
        }
        // 设置分享标题
        content.setTitle("mPaaS share title");
        // 设置分享内容
        content.setContent("mPaaS share content");
        return content;
    }

    private void setWechatDefaultIcon(ShareContent content) {
        HashMap<String, Object> extraInfo = content.getExtraInfo();
        if (null == extraInfo) {
            extraInfo = new HashMap<>();
        }
        if (null == extraInfo.get(ShareExtraInfoConstant.DEFAULT_ICON)
                || !(extraInfo.get(ShareExtraInfoConstant.DEFAULT_ICON) instanceof byte[])) {
            extraInfo.put(ShareExtraInfoConstant.DEFAULT_ICON, mWechatDefaultIconBytes);
        }
        content.setExtraInfo(extraInfo);
    }

}
