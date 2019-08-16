#import "AUUILoadDefine.h"//程序自动生成
#ifdef ANTUI_UI_alert//程序自动生成
//
//  AUPopupManager.h
//  AntUI
//
//  Created by Wang on 2018/4/24.
//  Copyright © 2018年 Alipay. All rights reserved.
//

#import <Foundation/Foundation.h>



typedef NS_ENUM(NSUInteger,AUPopupType){
    AUPopupTypeBindController,
    AUPopupTypeGlobal //全局性的，任何界面都可以弹，比如吱口令
};

typedef NS_ENUM(NSInteger,AUPopupEvent) {
    AUPopupEventShow, //展示
    AUPopupEventDismiss, //消失
    AUPopupEventPause, //暂存，在亚后台以及Alert出现时进行，有机会会恢复
    AUPopupEventContinue //恢复
};

#define kAUPopupProtocolControllerKey  @"kAUPopupProtocolControllerKey"

/**
 * 优先级排序（从高到低):
 * 业务
 * ShareToken
 * CDP
 */
typedef NS_ENUM(NSInteger,AUPopupPriority)
{
    AUPopupPriorityUndefined = 0,
    AUPopupPriorityBiz = 100,//业务
    AUPopupPriorityShareToken = 60,
    AUPopupPriorityBetweenCDP_ShareToken =  55,//比CDP高，比ShareToken低
    AUPopupPriorityCDP = 50,
    AUPopupPriorityBelowCDP = 40
}
;
@protocol AUPopupProtocol

@required

-(void) handlePopupEvent:(AUPopupEvent)event options:(NSDictionary*)options;

@optional

-(NSString *) bizId; //业务定义

-(AUPopupPriority) defaultPriorityForPopup; // 返回业务默认优先级

-(UIViewController *)linkedController;

@end

//具体的实现类，如果没有该Key，则认为是view。
static NSString *AUPopupManagerLogImplementationKey = @"ImplementationKey";

@interface AUPopupManager : NSObject

+(instancetype) sharedInstant;

-(void) showOrQueue:(UIView<AUPopupProtocol> *)view type:(AUPopupType)type;

-(void) showOrQueue:(UIView<AUPopupProtocol> *)view type:(AUPopupType)type logParam:(NSDictionary *)logParam;

-(void) showNextIfNeeded;

-(void) hidePopupView:(UIView<AUPopupProtocol> *)view;

-(void) hidePopupView:(UIView<AUPopupProtocol> *)view logParam:(NSDictionary *)logParam;

+(BOOL) isAUPopUpManagedEnable:(NSString*)bizId;

+(BOOL) isAUPopUpManagedEnable:(NSString*)bizId defaultPriority:(AUPopupPriority)prority;

-(void) dismissAllPopup;

-(void) queueAllPopup;

//将优先级<=priority的都压栈
//并且后续低于priority的弹窗直接压栈，知道调用popUpWindowIfNeeded。
-(void) queueAllPopupBelowPrioproty:(AUPopupPriority)priority;

-(void) recoveryPopup;
//-(void) popUpWindowIfNeeded;
//-(void) resumeAllPopup;

@end

NSDictionary *AUDictionaryCombine(NSDictionary *d1,NSDictionary *d2) ;

void AUPopLogEvent(NSString *action,NSObject *implementClass,NSDictionary *content);



#endif//程序自动生成
