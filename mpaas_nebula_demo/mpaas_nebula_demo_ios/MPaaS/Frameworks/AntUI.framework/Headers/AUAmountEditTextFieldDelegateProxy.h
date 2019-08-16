#import "AUUILoadDefine.h"//程序自动生成
#ifdef ANTUI_UI_amountInputBox//程序自动生成
//
//  AUAmountEditTextFieldDelegateProxy.h
//  AntUI
//
//  Created by zhaolei on 2017/8/24.
//  Copyright © 2017年 Alipay. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface AUAmountEditTextFieldDelegateProxy : NSProxy

@property(nonatomic,weak) id target;
@property(nonatomic,weak) id proxy;


/**
 target优先,如果target没有提供实现,则使用proxy

 @param target
 @param proxy
 @return
 */
-(instancetype)initWithTarget:(id)target
                        proxy:(id)proxy;

@end

#endif//程序自动生成
