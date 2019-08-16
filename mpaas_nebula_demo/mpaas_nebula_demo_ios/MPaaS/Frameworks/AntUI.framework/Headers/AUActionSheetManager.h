#import "AUUILoadDefine.h"//程序自动生成
#ifdef ANTUI_UI_actionSheet_AUActionSheet//程序自动生成
//
//  AUActionSheetManager.h
//  AntUI
//
//  Created by QiXin on 2016/9/28.
//  Copyright © 2016年 Alipay. All rights reserved.
//

#import <Foundation/Foundation.h>

@class AUActionSheet;
@interface AUActionSheetManager : NSObject

@property(nonatomic,assign)bool backGroundMode;//是否为后台模式

/**
 *  创建AUActionSheetManager对象，用来管理屏幕上所有的actionSheet
 *
 *  @return 初始化的AUActionSheetManager
 */
+ (AUActionSheetManager *)sharedAUActionSheetManager;

/**
 *  删除所有的actionSheet
 */
-(void)dismissAllUIActionSheet;

/**
 *  显示actionSheet，若为后台模式，押入后台池保存；否则立即前台显示
 *
 *  @param actionSheet 需要显示的actionSheet
 */
-(void)addToShowedPool:(AUActionSheet*)actionSheet;

@end

#endif//程序自动生成
