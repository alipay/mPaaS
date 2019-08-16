#import "AUUILoadDefine.h"//程序自动生成
#ifdef ANTUI_UI_alert//程序自动生成
//
//  AUDialogHandler.h
//  AntUI
//
//  Created by 莜阳 on 17/3/2.
//  Copyright © 2017年 Alipay. All rights reserved.
//

@class AUDialogBaseView;

@interface AUDialogManager : NSObject

+ (AUDialogManager *)shareInstance;

@property(nonatomic,assign)bool isBackGroundMode;//是否是后台模式

// 设置白名单不受 BackGroundMode 的压制影响
- (void)addWhiteListWithDiaog:(UIView *)dialog;

// 清空白名单
- (void)clearWhiteList;

// 检测弹窗实例是否在白名单列表内
- (BOOL)whiteListIsContainDialog:(UIView *)dialog;

@end

#endif//程序自动生成
