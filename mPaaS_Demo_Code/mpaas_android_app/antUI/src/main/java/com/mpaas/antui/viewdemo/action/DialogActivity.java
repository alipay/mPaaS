package com.mpaas.antui.viewdemo.action;

import android.app.Activity;
import android.content.Context;
import android.content.DialogInterface;
import android.graphics.Color;
import android.os.Bundle;
import android.view.View;
import android.view.ViewGroup;
import android.widget.Toast;

import com.alipay.mobile.antui.badge.AUBadgeView;
import com.alipay.mobile.antui.basic.AUButton;
import com.alipay.mobile.antui.basic.AUImageView;
import com.alipay.mobile.antui.basic.AUToast;
import com.alipay.mobile.antui.basic.AUToastPopupWindow;
import com.alipay.mobile.antui.clickspan.UrlClickableSpanListener;
import com.alipay.mobile.antui.dialog.AUAuthorizeDialog;
import com.alipay.mobile.antui.dialog.AUCustomDialog;
import com.alipay.mobile.antui.dialog.AUImageDialog;
import com.alipay.mobile.antui.dialog.AUInputDialog;
import com.alipay.mobile.antui.dialog.AUListDialog;
import com.alipay.mobile.antui.dialog.AUMaskLayer;
import com.alipay.mobile.antui.dialog.AUNoticeDialog;
import com.alipay.mobile.antui.dialog.AUOperationResultDialog;
import com.alipay.mobile.antui.dialog.AURecordFloatTip;
import com.alipay.mobile.antui.dialog.PopMenuItem;
import com.alipay.mobile.antui.iconfont.model.IconInfo;
import com.alipay.mobile.antui.iconfont.model.MessagePopItem;
import com.alipay.mobile.antui.utils.HtmlParser;
import com.alipay.mobile.antui.utils.PublicResources;
import com.mpaas.antui.R;

import java.util.ArrayList;
import java.util.HashMap;

public class DialogActivity extends Activity {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.view_dialog);
    }

    /**
     * AUNoticeDialog start
     **/
    // 基础文本弹窗
    public void noticeDialogSingle(View view) {
        AUNoticeDialog dialog = new AUNoticeDialog(this, "标题单行",
                "描述文字的字数尽量控制在三行内。",
                "确认", "", true);
        dialog.show();
    }

    // 自定义内容区域文本弹窗
    public void noticeDialogMulti(View view) {
        View view1 = new View(this);
        view1.setBackgroundColor(Color.BLUE);
        view1.setLayoutParams(new ViewGroup.LayoutParams(300, 300));
        AUNoticeDialog dialog = new AUNoticeDialog(this, "",
                "描述文字的字数",
                "确定", "取消", true, view1);
        dialog.show();
    }


    // 按钮超长文本弹窗
    public void noticeDialogAction(View view) {
        AUNoticeDialog dialog = new AUNoticeDialog(this, "标题单行",
                "描述文字的字数尽量控制在三行内，并且单行最右侧尽量不要是标点符号。描述文字的字数尽量控制在三行内，并且单行最右侧尽量不要是标点符号。描述文字的字数尽量控制在三行内，并且单行最右侧尽量不要是标点符号。描述文字的字数尽量控制在三行内，并且单行最右侧尽量不要是标点符号。描述文字的字数尽量控制在三行内，并且单行最右侧尽量不要是标点符号。描述文字的字数尽量控制在三行内，并且单行最右侧尽量不要是标点符号。描述文字的字数尽量控制在三行内，并且单行最右侧尽量不要是标点符号。描述文字的字数尽量控制在三行内，并且单行最右侧尽量不要是标点符号。描述文字的字数尽量控制在三行内，并且单行最右侧尽量不要是标点符号。描述文字的字数尽量控制在三行内，并且单行最右侧尽量不要是标点符号。描述文字的字数尽量控制在三行内，并且单行最右侧尽量不要是标点符号。描述文字的字数尽量控制在三行内，并且单行最右侧尽量不要是标点符号。描述文字的字数尽量控制在三行内，并且单行最右侧尽量不要是标点符号。描述文字的字数尽量控制在三行内，并且单行最右侧尽量不要是标点符号。描述文字的字数尽量控制在三行内，并且单行最右侧尽量不要是标点符号。",
                "去设置开启通知", "去去去去去设通知", true);
        dialog.setNegativeListener(new AUNoticeDialog.OnClickNegativeListener() {
            @Override
            public void onClick() {
                AUToast.makeToast(DialogActivity.this, 0, "negative", Toast.LENGTH_SHORT).show();
            }
        });
        dialog.show();
    }

    // 无标题文本弹窗
    public void noticeDialogNoTitle(View view) {
        AUNoticeDialog dialog = new AUNoticeDialog(this, "",
                "描述文字的字数尽量控制在三行内，并且单行最右侧尽量不要是标点符号。",
                "确认", "取消", true);
        dialog.show();
    }

    /**
     * AUNoticeDialog end
     **/


    public void clickAUInputDialog(View view) {
        AUInputDialog dialog = new AUInputDialog(this, "标题单行", "描述文字的字数尽量控制在三行内，并且单行最右侧尽量不要是标点符号。",
                "确认", "取消", true);
        dialog.show();
    }

    /**
     * AUListDialog start
     **/

    // 普通列表
    public void clickAUListDialog(View view) {
        new AUListDialog(this, getData(3)).show();
    }

    // 标题列表
    public void clickAUListDialog1(View view) {
        ArrayList<MessagePopItem> items = new ArrayList<MessagePopItem>();
        items.add(new MessagePopItem("选项文本"));
        items.add(new MessagePopItem("选项文本"));
        items.add(new MessagePopItem("选项文本"));
        items.add(new MessagePopItem("选项文本"));
        items.add(new MessagePopItem("选项文本"));
        items.add(new MessagePopItem("选项文本"));
        items.add(new MessagePopItem("选项文本"));
        items.add(new MessagePopItem("选项文本"));
        items.add(new MessagePopItem("选项文本"));
        new AUListDialog(this, "标题文字", "副标题文案副标题文案副标题文案副标题文案副标题文案", items).show();
    }

    // 图标红点列表
    public void clickAUListDialog2(View view) {
        ArrayList<MessagePopItem> items = new ArrayList<MessagePopItem>();
        IconInfo info = new IconInfo(getResources().getString(PublicResources.String_iconfont_group_chat));
        MessagePopItem item = new MessagePopItem(info, "选项文本");
        HashMap<String, Object> externParam = new HashMap<>();
        externParam.put(AUBadgeView.KEY_BADGE_STYLE, AUBadgeView.Style.fromString("text"));
        externParam.put(AUBadgeView.KEY_BADGE_CONTENT, "很多很多");
        item.externParam = externParam;
        items.add(item);


        IconInfo info1 = new IconInfo(getResources().getString(PublicResources.String_iconfont_group_chat));
        MessagePopItem item1 = new MessagePopItem(info1, "选项文本很长很长很长很长很长很长很长很长很长很长很长很长");
        HashMap<String, Object> externParam1 = new HashMap<>();
        externParam1.put(AUBadgeView.KEY_BADGE_STYLE, AUBadgeView.Style.TEXT);
        externParam1.put(AUBadgeView.KEY_BADGE_CONTENT, "很多很多很多很多很多很多很多很多很多很多");
        item1.externParam = externParam1;
        items.add(item1);


        MessagePopItem item2 = new MessagePopItem("选项文本很长很长很长很长很长很长很长很长很长很长很长很长");
        HashMap<String, Object> externParam2 = new HashMap<>();
        externParam2.put(AUBadgeView.KEY_BADGE_STYLE, AUBadgeView.Style.POINT);
        item2.externParam = externParam2;
        items.add(item2);


        items.add(new MessagePopItem("选项文本"));
        items.add(new MessagePopItem("选项文本"));
        items.add(new MessagePopItem("选项文本选项文本选项文本选项文本选项文本选项文本"));
        items.add(new MessagePopItem("选项文本选项文本选项文本选项文本选项文本选项文本"));
        items.add(new MessagePopItem("选项文本选项文本选项文本选项文本选项文本选项文本"));
        items.add(new MessagePopItem("选项文本选项文本选项文本选项文本选项文本选项文本"));
        items.add(new MessagePopItem("选项文本选项文本选项文本选项文本选项文本选项文本"));

        new AUListDialog(DialogActivity.this, items).show();
    }

    /**
     * AUListDialog end
     **/

    public void clickAUMaskLayer(View view) {
        new AUMaskLayer(this, new View(this)).show();
    }


    public void clickAUListDialog5(View view) {
        ArrayList<PopMenuItem> items = new ArrayList<PopMenuItem>();
        items.add(new PopMenuItem("选项文本", null));
        items.add(new PopMenuItem("选项文本", null));
        items.add(new PopMenuItem("选项文本", null));
        AUListDialog listDialog = new AUListDialog("标题单行", "描述文字的字数。", items, this);
        listDialog.setOnItemClickListener(new AUListDialog.OnItemClickListener() {
            @Override
            public void onItemClick(int index) {
                AUToast.makeToast(DialogActivity.this, 0, String.valueOf(index), Toast.LENGTH_SHORT).show();
            }
        });
        listDialog.show();
    }

    public void clickAUListDialog6(View view) {
        ArrayList<PopMenuItem> items = new ArrayList<PopMenuItem>();
        items.add(new PopMenuItem("选项文本", null));
        items.add(new PopMenuItem("选项文本", null));
        items.add(new PopMenuItem("选项文本", null));
        new AUListDialog("", "描述文字的字数尽量控制在三行内，并且单行最右侧尽量不要是标点符号。", items, this).show();
    }

    public void clickAUImageDialogShowTimer(View view) {
        AUImageDialog dialog = new AUImageDialog(this);
        dialog.showWithTimer(5, null, null);
    }

    public void clickAUImageDialogNomal(View view) {
        AUImageDialog dialog = AUImageDialog.getInstance(this);
        dialog.setCanceledOnTouch(true);
        dialog.setTitle("标题单行");
        dialog.setSubTitle("说明当前状态、提示用户解决方案，最好不要超过两行。");
        dialog.setConfirmBtnText("行动按钮");
        dialog.setLogoBackgroundResource(R.drawable.image_dialog);
        dialog.showWithoutAnim();
    }

    private Boolean isSHowAURecordFloatTip = false;
    private AURecordFloatTip mAURecordFloatTip;

    public void clickAURecordFloatTip(View view) {
        if (!isSHowAURecordFloatTip) {
            ((AUButton) view).setText("关闭AURecordFloatTip");
            if (mAURecordFloatTip == null) {
                mAURecordFloatTip = new AURecordFloatTip(this, "正在录音");
            }
            mAURecordFloatTip.show();
            isSHowAURecordFloatTip = true;
        } else {
            ((AUButton) view).setText("显示AURecordFloatTip");
            if (mAURecordFloatTip != null) {
                mAURecordFloatTip.dismiss();
            }
            isSHowAURecordFloatTip = false;
        }
    }

    public void clickAUImageDialogProtocolStyle(View view) {
        AUImageDialog dialog = new AUImageDialog(this);
        dialog.setCanceledOnTouch(true);
        dialog.setTitle("一级文案二级文案二级文案二级文案二级文案");
        dialog.setSubTitle("二级文案二级文案二级文案二级文案二级文案二级文案");
        dialog.setThirdTitleText("同意xxx协同意xxx协议同意xxx协议同意xxx协议同意xxx协议同意xxx协议同意xxx协议议");
        dialog.setConfirmBtnText("行动按钮");
        dialog.changeComfirmBtnStyleToMain();
        dialog.showWithoutAnim();
    }

    public void imageDialogActionList(View view) {
        final AUImageDialog dialog = AUImageDialog.getInstance(this);
        dialog.setCanceledOnTouch(true);
        dialog.setTitle("标题单行");
        dialog.setSubTitle("描述文字的字数尽量控制在三行内，并且单行最右侧尽量不要是标点符号。");
        dialog.setImageSmallType();
        dialog.setButtonListInfo(getData(1), new AUImageDialog.OnItemClickListener() {
            @Override
            public void onItemClick(int index) {
                dialog.setButtonListInfo(getData(2), new AUImageDialog.OnItemClickListener() {
                    @Override
                    public void onItemClick(int index) {

                    }
                });
            }
        });
        dialog.showWithoutAnim();
    }

    public void clickAUImageDialogBigImage(View view) {
        AUImageDialog dialog = new AUImageDialog(this);
        dialog.setImageMatchType();
        dialog.setTitle("标题单行");
        dialog.setSubTitle("说明当前状态、提示用户解决方案，最好不要超过两行。");
        dialog.setConfirmBtnText("行动按钮");
        dialog.setBigImageResource(R.drawable.image);
        dialog.setOnCancelListener(new DialogInterface.OnCancelListener() {
            @Override
            public void onCancel(DialogInterface dialog) {
                Toast.makeText(DialogActivity.this, "取消", Toast.LENGTH_SHORT).show();
            }
        });
        dialog.showWithoutAnim();
    }


    public void clickAUOperationResultDialog(View view) {
        AUOperationResultDialog dialog = new AUOperationResultDialog(this, "标题文字", getData(9));
        dialog.getIconView().setImageDrawable(getResources().getDrawable(R.drawable.image));
        dialog.setTitle("标题单行");
        dialog.show();
    }

    public void clickAUCustomDialog(View view) {
        /** AUCustomDialog start **/
        AUImageView imageView = new AUImageView(this);
        ViewGroup.LayoutParams layoutParams = new ViewGroup.LayoutParams(ViewGroup.LayoutParams.MATCH_PARENT, 400);
        imageView.setBackgroundColor(Color.BLUE);
        imageView.setLayoutParams(layoutParams);
        AUCustomDialog dialog = new AUCustomDialog(this, imageView);
        dialog.show();
        /** AUCustomDialog end **/
    }

    public void clickAUToastDialog(View view) {
        AUToastPopupWindow dialog = new AUToastPopupWindow(this);
        dialog.setMessage("测试Toast");
        dialog.show();
    }

    private ArrayList<String> getData(int size) {
        ArrayList<String> data = new ArrayList<String>();
        for (int i = 1; i <= size; i++) {
            data.add("选项文本" + String.valueOf(i));
        }
        return data;
    }

    public void clickAUAuthorizeDialog(View view) {
        AUAuthorizeDialog dialog = new AUAuthorizeDialog(this);

        UrlClickableSpanListener onLinkClickedListener = new UrlClickableSpanListener() {
            @Override
            public void onClick(Context mContext, String url) {
                Toast.makeText(DialogActivity.this, url, Toast.LENGTH_SHORT).show();
            }
        };

        dialog.setTitle("服务授权")
                .setConfirmButtonText("确认授权")
                .setAuthTitle("授权 <b>ofo小黄车</b> 获取以下信息为您服务")
                .setAuthDetails(new String[]{"获取你的公开信息（昵称、头像、性别等）", "使用身份信息（姓名、手机号、证件）办理业务", "查询您的芝麻分等信用信息，如尚未开通芝麻信用服务，则予以开通"})
                .appendProtocolMessage(HtmlParser.parseALabel("同意<a href='http://antui.com1'>《用户授权协议》</a><a href='http://antui.com2'>《芝麻服务协议及相关授权协议》</a><a href='http://antui.com3'>《骑行用户信息授权协议》</a><a href='http://antui.com4'>《单车方用户服务协议》</a>"), onLinkClickedListener)
                .setOnAuthListener(new AUAuthorizeDialog.OnAuthListener() {
                    @Override
                    public void onConfirm() {
                        Toast.makeText(DialogActivity.this, "确认授权", Toast.LENGTH_SHORT).show();
                    }

                    @Override
                    public void onCancel() {
                        Toast.makeText(DialogActivity.this, "取消授权", Toast.LENGTH_SHORT).show();
                    }
                })
                .show();

    }
}
