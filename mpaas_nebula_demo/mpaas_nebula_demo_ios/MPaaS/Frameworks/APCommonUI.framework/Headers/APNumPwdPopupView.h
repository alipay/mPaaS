//
//  ALPNumPwdPopupView.h
//  CommonUI
//
//  Created by shaobin on 11/6/13.
//  Copyright (c) 2013 Alipay. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "APNumPwdInputView.h"

@class APNumPwdPopupView;
@class APButton;

typedef void(^APNumPwdPopupViewBlock) (APNumPwdPopupView *sender, int buttonIndex);
typedef void(^APNumPwdPopupViewCallback) (APNumPwdPopupView *sender, int buttonIndex);

@interface APNumPwdPopupView : UIView<APNumPwdInputViewDelegate>

@property (nonatomic, copy) APNumPwdPopupViewBlock cancelBlock;
@property (nonatomic, copy) APNumPwdPopupViewBlock confirmBlock;

@property (nonatomic, weak) APButton *cancelBtn;
@property (nonatomic, weak) APButton *confirmBtn;
@property (nonatomic, weak) APNumPwdInputView *pwdInputView;

- (id)initWithTitle:(NSString*)title
  cancelButtonTitle:(NSString*)cancelButtonTitle
 confirmButtonTitle:(NSString*)confirmButtonTitle;

- (id)initWithTitle:(NSString*)title
       subtitleView:(UIView  *)subtitleView
  cancelButtonTitle:(NSString*)cancelButtonTitle
 confirmButtonTitle:(NSString*)confirmButtonTitle;

- (void)presentWithinWindow:(UIWindow*)window;
- (void)presentWithinWindow:(UIWindow*)window onComplete:(APNumPwdPopupViewCallback)onComplete;

/**如果没有设置target或者selector，执行默认行为*/
- (void)addLeftBackButtonTarget:(id)target selector:(SEL)selector events:(UIControlEvents)events;

/**获取subtitle的固定宽度*/
+ (CGFloat )subtitleViewWidth;

/**手动添加title的说明文字*/
- (void)showSubtitleView:(UIView *)subtitleView;

/*
 和UIAlertView不同，按钮点击后不会自动dismiss，需要在alpNumPwdPopupViewCallback回调里手动调用。
 */
- (void)dismiss;
- (void)dismissWithCompletionBlock:(void (^)(void))block;
- (void)clearBlock;

@end
