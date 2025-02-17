//
//  APAlertView.m
//  MobileFoundation
//
//  Created by 朱建 on 13-4-9.
//  Copyright (c) 2013年 Alipay. All rights reserved.
//
#import "APAlertViewPrivate.h"
#import "APAlertViewBase.h"
#import "APAlertViewManager.h"
//#import "APLimitView.h"

@implementation APAlertViewBase

- (id)initWithFrame:(CGRect)frame
{
    self = [super initWithFrame:frame];
    if (self) {
        self.dtAlertManager = [APAlertViewManager sharedAPAlertViewManager];
    }
    return self;
}

- (id)init
{
    self = [super init];
    if (self) {
        self.dtAlertManager = [APAlertViewManager sharedAPAlertViewManager];
    }
    return self;
}

- (void)setDelegate:(id)delegate
{
    if (delegate == nil) {
        [super setDelegate:nil];
        self.dtDelegate = nil;
        return;
    }
    
    if (delegate == self.dtAlertManager) {
        [super setDelegate:delegate];
    }
    else {
        self.dtDelegate = delegate;
    }
}

- (void)dealloc
{
    self.callbacks = nil;
    [self setDelegate:nil];
}

-(void)show
{
     [[APAlertViewManager sharedAPAlertViewManager] pushAPAlertView:self];
}

- (void)showAlert
{
	// 兼容iOS8上，alert界面显示不正常问题
    if ( ([[[UIDevice currentDevice] systemVersion] floatValue]) >= 8.0 && self.title == nil) {
        self.title = @"";
    }
    [super show];
}

+(void)setBackgroundMode:(BOOL)isBackMode
{
    [APAlertViewManager sharedAPAlertViewManager].isBackGroundMode = isBackMode;
    [[AUDialogManager shareInstance] setIsBackGroundMode:isBackMode];
}

+(void)removeAllAlerviews
{
    [[APAlertViewManager sharedAPAlertViewManager] removeAllAlertView];
//    if ([APLimitView isShowing]) {
//        [APLimitView dismiss];
//    }
    [AUDialogBaseView dismissAll];
}


#pragma mark - Call Back Add By Niren
- (id)initWithTitle:(NSString *)title message:(NSString *)message {
    self = [self initWithTitle:title message:message delegate:self cancelButtonTitle:nil otherButtonTitles:nil];
    if (self) {
        NSMutableArray *callbacks = [[NSMutableArray alloc] init];
        self.callbacks = callbacks;
    }
    return self;
}

- (NSInteger)addButtonWithTitle:(NSString *)title callback:(void (^)(int index, NSString *title))callback {
    if (!title) {
        return - 1;
    }
    
    if (!callback) {
        callback = ^(int index, NSString *title) {
        };
    }
    callback = [callback copy];
    if(callback) {
        [self.callbacks addObject:callback];
    }
    
    return [super addButtonWithTitle:title];
}

- (NSInteger)addCancelButtonWithTitle:(NSString *)title callback:(void (^)(int index, NSString *title))callback {
    NSInteger index = [self addButtonWithTitle:title callback:callback];
    if (index >= 0) {
        self.cancelButtonIndex = index;
    }
    return index;
}

- (NSInteger)addButtonWithTitle:(NSString *)title {
    return [self addButtonWithTitle:title callback:nil];
}

- (NSInteger)addCancelButtonWithTitle:(NSString *)title {
    return [self addCancelButtonWithTitle:title callback:nil];
}


@end
