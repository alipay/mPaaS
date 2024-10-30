//
//  APAlertViewManager.m
//  MobileFoundation
//
//  Created by 朱建 on 13-4-9.
//  Copyright (c) 2013年 Alipay. All rights reserved.
//

#import "APAlertViewManager.h"
#import "APAlertView.h"
#import "APAlertViewPrivate.h"
#import <UIKit/UIKit.h>
#define Dismiss_ButtonIndex - 100
@interface APAlertViewManager ()

@property(nonatomic, strong) NSMutableArray *backGroundAlertviews;
@property(nonatomic,strong) NSMutableArray *showedAlertviews;

@end

@implementation APAlertViewManager

+ (APAlertViewManager *)sharedAPAlertViewManager
{
    static dispatch_once_t once;
    static id instance;
    dispatch_once(&once, ^{instance = self.new;});
    return instance;
    
}
    
#pragma mark - Member Functions
- (void)removeAllAlertView
{
    // 先消除仍然存在的AlertView界面窗口
    NSMutableArray *tempArray = [[NSMutableArray alloc]initWithArray:self.showedAlertviews];
    for (int x = 0; x<tempArray.count; x++) {
        APAlertView *alertview = [tempArray objectAtIndex:x];
        //if (alertview.isVisible)
        [alertview dismissWithClickedButtonIndex:Dismiss_ButtonIndex animated:NO];
    }
    // 清空数组中的对象
    [self.showedAlertviews removeAllObjects];
    
    // 清空后台预备的alerview
    [self.backGroundAlertviews removeAllObjects];
}

- (void)pushAPAlertView:(APAlertView *)alertview
{
    if (alertview==nil) {
        return;
    }
    if (self.isBackGroundMode==YES) {
//        NSLog(@"insert alertview in background.tag:%d",alertview.tag);
        //后台模式
        [self addToBackgroudPool:alertview];
    }else{
//        NSLog(@"show alert.tag:%d",alertview.tag);
        [alertview showAlert];
        alertview.delegate=self;
        [self addToShowedPool:alertview];
    }
}

-(void)setIsBackGroundMode:(bool)isBackGroundMode
{
    if (_isBackGroundMode!=isBackGroundMode) {
        _isBackGroundMode = isBackGroundMode;
        if (isBackGroundMode==YES) {
            //进入后台模式
            NSLog(@"==Begin in background.==");
            if (self.showedAlertviews.count>0) {
                //所有当前显示的alerview加入backgroundPool
                for (int x=0; x<self.showedAlertviews.count; x++) {
                    APAlertView *alerView = [self.showedAlertviews objectAtIndex:x];
                    [self addToBackgroudPool:alerView];
                }
                
                //Note:这里需要根据alerview的顺序倒着调用删除否则无法达到预期效果
                NSMutableArray *tempViews = [[NSMutableArray alloc]initWithArray:self.showedAlertviews];
                for (int x = 0; x<tempViews.count; x++) {
                    APAlertView *alerView = [tempViews objectAtIndex:x];
                    [alerView dismissWithClickedButtonIndex:Dismiss_ButtonIndex animated:NO];//会引起
                    
                }
            }
        }else{
            //进入前台模式
                NSLog(@"==Begin in foreground.==");
            if (self.backGroundAlertviews) {
                for (int x=0; x<self.backGroundAlertviews.count; x++) {
                    APAlertView *alertView = [self.backGroundAlertviews objectAtIndex:x];
                    [alertView showAlert];
                    alertView.delegate=self;
                    [self addToShowedPool:alertView];
                }
                [self.backGroundAlertviews removeAllObjects];
            }
        }
    }
}

-(void)addToBackgroudPool:(APAlertView*)alertView
{
    if (alertView) {
        if (self.backGroundAlertviews==nil) {
            self.backGroundAlertviews = [[NSMutableArray alloc]initWithCapacity:0];
        }
        [self.backGroundAlertviews addObject:alertView];
    }
}

-(void)addToShowedPool:(APAlertView*)alertView
{
    if (alertView) {
        //加入前台队列
        if (self.showedAlertviews==nil) {
            self.showedAlertviews = [[NSMutableArray alloc]initWithCapacity:0];
        }
        if (![self.showedAlertviews containsObject:alertView]) {
//            NSLog(@"insert to showed pool.tag:%d",alertView.tag);
            [self.showedAlertviews addObject:alertView];
        }
    }
}


#pragma mark - UIAlertViewDelegate
- (void)alertView:(UIAlertView *)alertView willDismissWithButtonIndex:(NSInteger)buttonIndex
{
    if ([alertView isKindOfClass:[APAlertView class]]) {
        APAlertView *dtAlertView = (APAlertView*)alertView;
        //从后台队列中移除
//        NSLog(@"remove from pool.tag:%d",alertView.tag);
        [self.showedAlertviews removeObject:dtAlertView];
        if (buttonIndex!=Dismiss_ButtonIndex) {
            if ([dtAlertView.dtDelegate respondsToSelector:@selector(alertView: willDismissWithButtonIndex:)]) {
                [dtAlertView.dtDelegate alertView:dtAlertView willDismissWithButtonIndex:buttonIndex];
            }
        }
    }
}

////////////////////////////简单的delegate定向///////////////////////////////
- (void)didPresentAlertView:(UIAlertView *)alertView
{
    if ([alertView isKindOfClass:[APAlertView class]]) {
        APAlertView *dtAlertView = (APAlertView*)alertView;
        //dtDelegate
        if ([dtAlertView.dtDelegate respondsToSelector:@selector(didPresentAlertView:)]) {
            [dtAlertView.dtDelegate didPresentAlertView:dtAlertView];
        }
    }
}

- (void)alertView:(UIAlertView *)alertView clickedButtonAtIndex:(NSInteger)buttonIndex
{
    if ([alertView isKindOfClass:[APAlertView class]]) {
        APAlertView *dtAlertView = (APAlertView*)alertView;
        if ( [dtAlertView.dtDelegate respondsToSelector:@selector(alertView: clickedButtonAtIndex:)]) {
            [dtAlertView.dtDelegate alertView:dtAlertView clickedButtonAtIndex:buttonIndex];
        }
       
    }
}

- (void)alertView:(UIAlertView *)alertView didDismissWithButtonIndex:(NSInteger)buttonIndex
{
    if ([alertView isKindOfClass:[APAlertView class]]) {
        APAlertView *dtAlertView = (APAlertView*)alertView;
        
        //dtDelegate
        if ([dtAlertView.dtDelegate respondsToSelector:@selector(alertView: didDismissWithButtonIndex:)]) {
            [dtAlertView.dtDelegate alertView:dtAlertView didDismissWithButtonIndex:buttonIndex];
        }
        if (buttonIndex >= 0 && buttonIndex < dtAlertView.callbacks.count) {
            void (^callback)() = [dtAlertView.callbacks objectAtIndex:buttonIndex];
            if (callback) {
                callback(buttonIndex, [dtAlertView buttonTitleAtIndex:buttonIndex]);
            }
        }
    }
}

- (void)alertViewCancel:(UIAlertView *)alertView
{
    if ([alertView isKindOfClass:[APAlertView class]]) {
        APAlertView *dtAlertView = (APAlertView*)alertView;
        if ([dtAlertView.dtDelegate respondsToSelector:@selector(alertViewCancel:)]) {
            [dtAlertView.dtDelegate alertViewCancel:dtAlertView];
        }
    }
}

- (void)willPresentAlertView:(UIAlertView *)alertView
{
    if ([alertView isKindOfClass:[APAlertView class]]) {
        APAlertView *dtAlertView = (APAlertView*)alertView;
        if ([dtAlertView.dtDelegate respondsToSelector:@selector(willPresentAlertView:)]) {
            [dtAlertView.dtDelegate willPresentAlertView:dtAlertView];
        }
    }
}

- (BOOL)alertViewShouldEnableFirstOtherButton:(UIAlertView *)alertView
{
    if ([alertView isKindOfClass:[APAlertView class]]) {
        APAlertView *dtAlertView = (APAlertView*)alertView;
        if ([dtAlertView.dtDelegate respondsToSelector:@selector(alertViewShouldEnableFirstOtherButton:)]) {
            return [dtAlertView.dtDelegate alertViewShouldEnableFirstOtherButton:alertView];
        }
    }
    
    //返回该按钮原状态
    
    NSMutableArray *buttons = [NSMutableArray array];
	for (UIView *subview in alertView.subviews) {
		if ([subview isKindOfClass:[UIButton class]]) {
			[buttons addObject:subview];
		}
	}
    
    NSInteger buttonIndex = alertView.firstOtherButtonIndex;
    if (buttonIndex < buttons.count) {
        UIButton *aButton = buttons[buttonIndex];
        return aButton.isEnabled;
    }else{
        return YES;
    }
}

@end
