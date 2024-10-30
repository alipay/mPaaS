//
//  ALPAlertView.m
//  CommonUI
//
//  Created by tgf on 13-4-23.
//  Copyright (c) 2013年 Alipay. All rights reserved.
//

#import "APAlertView.h"

@interface APModelAlertViewDelegate : NSObject <UIAlertViewDelegate>

@property(nonatomic, assign) NSInteger clickedButtonIndex;

@end

@interface APAlertView ()

@property(nonatomic, strong) APModelAlertViewDelegate *modelAlertViewDelegate;

@end

@implementation APAlertView

- (NSInteger)showModel
{
    self.modelAlertViewDelegate = [[APModelAlertViewDelegate alloc] init];
    self.delegate = self.modelAlertViewDelegate;
    
    [self show];
    
    while (self.modelAlertViewDelegate.clickedButtonIndex == -1) {
        [[NSRunLoop currentRunLoop] runMode:NSDefaultRunLoopMode beforeDate:[NSDate distantFuture]];
    }
    
    return self.modelAlertViewDelegate.clickedButtonIndex;
}

+(id) alloc
{
    if([[AUConfigShell configForKey:@"ap_commonui_apalertview_rollback"] isEqualToString:@"true"])
    {
        return [super alloc];
    }
    return [AUAlertViewAdapter alloc];
}

/*
 // 覆盖父类方法, 调整按钮frame
 // FIXME: 苹果建议不这么干
 - (void)layoutSubviews
 {
 [super layoutSubviews];
 
 if (self.frame.size.height < 88) {
 return;
 }
 
 NSMutableArray *buttons = [NSMutableArray array];
 for (UIView *subview in self.subviews) {
 if ([subview isKindOfClass:[UIButton class]]) {
 [buttons addObject:subview];
 }
 }
 // 只对处理两个按钮的情况
 if (buttons.count != 2) {
 return;
 }
 
 UIButton *actionButton = buttons[self.firstOtherButtonIndex];
 UIButton *cancelButton = buttons[1 - self.firstOtherButtonIndex];
 
 // 已调整过, 直接返回
 if (actionButton.frame.origin.x == cancelButton.frame.origin.x) {
 return;
 }
 
 CGFloat startX = MIN(CGRectGetMinX(actionButton.frame), CGRectGetMinX(cancelButton.frame));
 CGFloat width = MAX(CGRectGetMaxX(actionButton.frame), CGRectGetMaxX(cancelButton.frame)) - startX;
 CGFloat startY = MIN(CGRectGetMinY(actionButton.frame), CGRectGetMinY(cancelButton.frame));
 CGFloat height = CGRectGetHeight(actionButton.frame);
 
 // 动作按钮在上, 取消按钮在下
 actionButton.frame = CGRectMake(startX, startY, width, height);
 cancelButton.frame = CGRectOffset(actionButton.frame, 0, height + 15);
 self.frame = CGRectInset(self.frame, 0, -(height + 30) / 2);
 }
 */

@end

@implementation APModelAlertViewDelegate

- (id)init
{
    self = [super init];
    if (self) {
        self.clickedButtonIndex = -1;
    }
    return self;
}

- (void)alertView:(UIAlertView *)alertView clickedButtonAtIndex:(NSInteger)buttonIndex
{
    self.clickedButtonIndex = buttonIndex;
}

@end

@interface AUAlertViewAdapterDelegate : NSObject<AUDialogDelegate>

-(id) initWithRealDelegate:(NSObject<UIAlertViewDelegate> *)realDelegate;

@end

AUAlertViewAdapterDelegate *AUAlertViewAdapterMaker(NSObject<UIAlertViewDelegate> *realOne)
{
    AUAlertViewAdapterDelegate *delegate = [[AUAlertViewAdapterDelegate alloc]initWithRealDelegate:realOne];
    return delegate;
}

@implementation AUAlertViewAdapterDelegate
{
    NSObject<UIAlertViewDelegate> *_realDelegate;
}

-(id) initWithRealDelegate:(NSObject<UIAlertViewDelegate> *)realDelegate
{
    self = [super init];
    _realDelegate = realDelegate;
    return self;
}

- (void)dialogView:(AUDialogBaseView *)dialogView clickedButtonAtIndex:(NSInteger)buttonIndex
{
    if([_realDelegate respondsToSelector:@selector(alertView:clickedButtonAtIndex:)])
    {
        [_realDelegate alertView:dialogView clickedButtonAtIndex:buttonIndex];
    }
}


@end

@implementation AUAlertViewAdapter

- (NSInteger)showModel
{
    return 0;
}

/**
 *@brief 初始化方法
 */
- (id)initWithTitle:(NSString *)title message:(NSString *)message
{
    self = [super initWithTitle:title message:message];
    return self;
}

-(id) initWithTitle:(NSString *)title message:(NSString *)message delegate:(id<UIAlertViewDelegate>)delegate buttonTitles:(NSString *)buttonTitle, ...
{
    self = [super initWithTitle:title message:message delegate:AUAlertViewAdapterMaker(delegate) buttonTitles:buttonTitle, nil];
    return self;
}

- (instancetype)initWithTitle:(nullable NSString *)title message:(nullable NSString *)message delegate:(nullable id /*<UIAlertViewDelegate>*/)delegate cancelButtonTitle:(nullable NSString *)cancelButtonTitle otherButtonTitles:(nullable NSString *)otherButtonTitles, ...
{
    self = [super initWithTitle:title message:message delegate:AUAlertViewAdapterMaker(delegate) cancelButtonTitle:cancelButtonTitle otherButtonTitles:otherButtonTitles, nil];
    return self;    
}


/**
 @brief 添加Button 和回调
 @param title: 按钮title
 @param callback: 回调的callback
 */
- (NSInteger)addButtonWithTitle:(NSString *)title callback:(void (^)(int index, NSString *title))callback
{
    return [super addButtonWithTitle:title callback:callback];
}

/**
 @brief 添加取消Button和回调
 @param title: 按钮title
 @param callback: 回调的callback
 */
- (NSInteger)addCancelButtonWithTitle:(NSString *)title callback:(void (^)(int index, NSString *title))callback
{
    return [super addCancelButtonWithTitle:title callback:callback];
}

/**
 @brief 添加Button
 @param title: 按钮title
 */
- (NSInteger)addButtonWithTitle:(NSString *)title
{
    return [super addButtonWithTitle:title];
}

/**
 @brief 添加取消button
 @param title: 按钮title
 */
- (NSInteger)addCancelButtonWithTitle:(NSString *)title
{
    return [super addCancelButtonWithTitle:title];
}

-(BOOL) isKindOfClass:(Class)aClass
{
    NSString *className = NSStringFromClass(aClass);
    if([className isEqualToString:@"APAlertView"] || [className isEqualToString:@"APAlertBase"])
    {
        return YES;
    }
    return [super isKindOfClass:aClass];
}
@end
