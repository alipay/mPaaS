#import "AUUILoadDefine.h"//程序自动生成
#ifdef ANTUI_UI_refreshLoadingView_AULoadingView//程序自动生成
//
//  AULoadingView.h
//  AntUI
//
//  Created by 祝威 on 16/10/10.
//  Copyright © 2016年 Alipay. All rights reserved.
//

#import <UIKit/UIKit.h>


//#########################################################
//文档地址 : https://yuque.antfin-inc.com/antui/auidoc/ios_auloadingview
//#########################################################


#define UI_AULoadingView

/**
  中间加载的loading控件中间含数字
 */
@interface AULoadingView : UIView

@property (nonatomic,assign) BOOL isShowProgressPer; //是否显示进度百分比默认为NO
@property (nonatomic,assign) BOOL isShowLoadingText; //是否显示加载文案默认为NO


/**
  设置进度百分比

 @param progress 百分比的值
 */
- (void) setProgressPer:(CGFloat) progress;


@end

#endif//程序自动生成
