#import "AUUILoadDefine.h"//程序自动生成
#ifdef ANTUI_UI_ResultView_AUResultView//程序自动生成
//
//  AUResultView.h
//  AntUI
//
//  Created by QiXin on 2016/10/11.
//  Copyright © 2016年 Alipay. All rights reserved.
//

#import <UIKit/UIKit.h>


//#########################################################
//文档地址 : https://yuque.antfin-inc.com/antui/auidoc/ios_auresultview
//#########################################################


#define UI_AUResultView

/**
 显示状态的结果视图
 文档:http://idoc.alipay.net/article/57fc6a3e22ec746a42030502
 */
@interface AUResultView : UIView

/**
 顶部图像
 */
@property (nonatomic, strong) UIImage *icon;

/**
 文本区域顶部的黑色中尺寸标题
 */
@property (nonatomic, strong) NSString *mainTitleText;

/**
 中间的黑色大尺寸标题
 */
@property (nonatomic, strong) NSString *midTitleText;

/**
 底部的灰色消息
 */
@property (nonatomic, strong) NSString *bottomMessage;

/**
 底部消息是否加贯穿线
 */
@property (nonatomic, assign) BOOL messageThrough;

/**
 视图期望的高度，初始化完成即可获取
 */
@property (nonatomic, assign, readonly) CGFloat expectHeight;

@property (nonatomic, assign) BOOL hideShadow;//隐藏viwe阴影.默认NO

/**
 ResultView 实例化方法

 @param icon 图像
 @param mainTitleText 第一个标题
 @param midTitleText 中间大标题
 @param bottomMessage 底部灰色消息
 @param messageThrough 是否加横线贯穿
 @return AUResultView 实例
 */
- (instancetype)initWithIcon:(UIImage *)icon
               mainTitleText:(NSString *)mainTitleText
                midTitleText:(NSString *)midTitleText
               bottomMessage:(NSString *)bottomMessage
              messageThrough:(BOOL)messageThrough;

- (instancetype)initWithFrame:(CGRect)frame NS_UNAVAILABLE;

@end

#endif//程序自动生成
