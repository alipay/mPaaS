package com.mpaas.demo.nebula;

import android.content.Context;
import android.graphics.Bitmap;
import android.graphics.drawable.Drawable;
import android.view.LayoutInflater;
import android.view.View;
import android.view.animation.Animation;
import android.view.animation.TranslateAnimation;
import android.widget.LinearLayout;
import android.widget.TextView;

import com.alipay.mobile.h5container.api.H5ViewCache;
import com.alipay.mobile.nebula.refresh.H5PullContainer;
import com.alipay.mobile.nebula.util.H5Log;
import com.alipay.mobile.nebula.view.H5LoadingView;
import com.alipay.mobile.nebula.view.H5Progress;
import com.alipay.mobile.nebula.view.H5WebContentView;

import java.util.concurrent.atomic.AtomicBoolean;

/**
 * Created by xingcheng on 2018/10/19.
 */
public class H5WebContentImpl implements H5WebContentView {

    private static String TAG = "H5WebContentImpl";

    private View contentView;
    private View webContent;
    private H5PullContainer pullContainer;
    private H5Progress h5Progress;
    private View hDivider;
    private LinearLayout h5ProviderLayout;
    private H5LoadingView h5LoadingView;

    private AtomicBoolean isShowProgress = new AtomicBoolean(false);

    public H5WebContentImpl(Context context) {
        contentView = H5ViewCache.getCachedViewById(R.layout.h5_web_content);
        if (contentView == null) {
            contentView = LayoutInflater.from(context).inflate(R.layout.h5_web_content,
                    null);
        }
        webContent = contentView.findViewById(R.id.h5_web_content);
        h5ProviderLayout = (LinearLayout) contentView.findViewById(R.id.h5_ly_provider_layout);
        hDivider = contentView.findViewById(R.id.h5_h_divider);
        h5Progress = (H5Progress) contentView.findViewById(R.id.h5_pb_progress);
        h5LoadingView = (H5LoadingView) contentView.findViewById(R.id.h5_loading_view);

        h5Progress.setNotifier(new H5Progress.ProgressNotifier() {
            @Override
            public void onProgressBegin() {
                H5Log.d(TAG, "isShowProgress:" + isShowProgress + " visible:" + h5Progress
                        .getVisibility());
                isShowProgress.set(true);
            }

            @Override
            public void onProgressEnd() {
                H5Log.d(TAG, "isShowProgress:" + isShowProgress + " visible:" + h5Progress
                        .getVisibility());
                if (isShowProgress.compareAndSet(true, false) && h5Progress
                        .getVisibility() == View.VISIBLE) {
                    // when view gone,add animaiton.
                    TranslateAnimation mHiddenAction =
                            new TranslateAnimation(Animation.RELATIVE_TO_SELF,
                                    0.0f, Animation.RELATIVE_TO_SELF, 0.0f,
                                    Animation.RELATIVE_TO_SELF, 0.0f,
                                    Animation.RELATIVE_TO_SELF,
                                    -1.0f);
                    mHiddenAction.setDuration(300);
                    h5Progress.startAnimation(mHiddenAction);
                    h5Progress.setVisibility(View.GONE);
                }
            }
        });
        pullContainer = (H5PullContainer) contentView.findViewById(R.id.h5_pc_container);
    }

    @Override
    public H5PullContainer getPullContainer() {
        return pullContainer;
    }

    @Override
    public H5Progress getProgress() {
        return h5Progress;
    }

    @Override
    public View getContentView() {
        return contentView;
    }

    @Override
    public void setProviderText(String provider) {
    }

    @Override
    public void setProviderLogo(Drawable drawable) {
    }

    @Override
    public void setProviderUc(String providerUc) {
    }

    @Override
    public void showProviderVisibility(boolean show) {
    }

    @Override
    public boolean isCustomBackground() {
        return false;
    }

    @Override
    public View getHdivider() {
        return hDivider;
    }

    @Override
    public LinearLayout getProviderLayout() {
        return h5ProviderLayout;
    }

    @Override
    public void switchCustomContentBg(int color, Drawable ucLogo, boolean includeLogo) {
        if (color != 0xFF000000) {
            color = color | 0xFF000000;
        }
        webContent.setBackgroundColor(color);
    }

    @Override
    public void swicthDefaultContentBg(Drawable ucLogo, boolean includeLogo) {
    }

    @Override
    public TextView getH5ProviderDomain() {
        return null;
    }

    @Override
    public H5LoadingView getH5LoadingView() {
        return h5LoadingView;
    }

    @Override
    public void setBackgroundImageColor(int i) {

    }

    @Override
    public void setBackgroundImage(Bitmap bitmap) {

    }

    @Override
    public void hideBackgroundImage() {

    }
}
