//
//  PSDViewEvent.h
//  Poseidon
//
//  Created by chenwenhong on 14-8-11.
//  Copyright (c) 2014年 Alipay. All rights reserved.
//

#import "PSDEvent.h"

typedef enum {
    PSDAlertPanel,
    PSDConfirmPanel,
    PSDPromptPanel
} PSDPanelType;

@interface PSDViewEvent : PSDEvent

@property(nonatomic, readonly, assign) CGRect newFrame;
@property(nonatomic, strong) WKWebViewConfiguration *wkConfiguration;
@property(nonatomic, assign) PSDPanelType panelType;
@property(nonatomic, copy) NSString *panelTitle;
@property(nonatomic, copy) NSString *injectJs;
@property(nonatomic, copy) NSDictionary *expandParams;
@property(nonatomic, weak) PSDKernel *parentObject;


+ (instancetype)allEvent;

+ (instancetype)createEvent;

+ (instancetype)resizeEvent:(CGRect)newFrame;

+ (instancetype)destroyEvent;

+ (instancetype)configEvent;

+ (instancetype)showPanelEvent;

+ (instancetype)injectJSEvent;

+ (instancetype)reloadFailEvent;
@end
