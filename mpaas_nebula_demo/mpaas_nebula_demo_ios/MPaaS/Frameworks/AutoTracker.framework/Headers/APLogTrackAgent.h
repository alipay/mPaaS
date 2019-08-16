//
//  APLogTrackAgent.h
//  APRemoteLogging
//
//  Created by majie on 16/10/27.
//  Copyright © 2016年 Alipay. All rights reserved.
//

#import <Foundation/Foundation.h>


typedef NS_ENUM(int, APLogTrackUpdateType){
    APLogTrackUpdateTypeAll = 0,
    APLogTrackUpdateTypeNeed
};

@interface APLogTrackContext : NSObject

//abtest标示
@property (atomic, copy) NSString *abTestInfo;

//数据回流
@property (atomic, copy) NSString *entityId;

//spmId
@property (atomic, copy) NSString *spmId;

//日志级别
@property (atomic, copy) NSString *level;

//业务类型
@property (atomic, copy) NSString *bizType;

//xpath
@property (atomic, copy) NSString *xPath;

//扩展参数4（数据回流，兼容手动spm支持设置）
@property (atomic, strong) NSDictionary *param;

//是否上传pageId
@property (atomic, assign) BOOL needRpc;

//扩展参数数组
@property (atomic, copy) NSArray *params;

+ (void)filterContext:(APLogTrackContext *)context;

@end

@interface APLogTrackAgent : NSObject

+ (void)viewController:(UIViewController *)viewController
               context:(APLogTrackContext *)context
            updateType:(APLogTrackUpdateType)updateType;

+ (void)willAppearViewController:(UIViewController *)viewController context:(APLogTrackContext *)context;

+ (void)willDisappearViewController:(UIViewController *)viewController;

+ (void)didAppearViewController:(UIViewController *)viewController context:(APLogTrackContext *)context;

+ (void)didDisappearViewController:(UIViewController *)viewController;

+ (void)control:(UIControl *)control events:(UIControlEvents)events context:(APLogTrackContext *)context;

+ (void)view:(UIView *)view gestureRecognizer:(UIGestureRecognizer *)gestureRecognizer context:(APLogTrackContext *)context;

+ (void)selectTableCell:(UITableViewCell *)cell context:(APLogTrackContext *)context;

@end
