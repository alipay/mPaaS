#import "AUUILoadDefine.h"//程序自动生成
#ifdef ANTUI_UI_pickerView_PickerBaseView//程序自动生成
//
//  AUPickerBaseView.h
//  AntUI
//
//  Created by 莜阳 on 2017/9/4.
//  Copyright © 2017年 Alipay. All rights reserved.
//

@class AUPickerBaseView;

@protocol AUPickerBaseViewDelegate <NSObject>

/*
 * 点取消息时回调
 */
- (void)cancelPickerView:(AUPickerBaseView *)pickerView;

- (void)selectedPickerView:(AUPickerBaseView *)pickerView;


@end

@interface AUPickerBaseView : UIView

@property (nonatomic, strong) UIPickerView *pickerView;      //通用事务选择器
@property (nonatomic, strong) UIView *backgroundView;       // 背景色层
@property (nonatomic, strong) UIView *containerView;        // 底部容器层
@property (nonatomic, weak) id <AUPickerBaseViewDelegate> delegate;

// 初始化函数
- (id)initWithFrame:(CGRect)frame withTitle:(NSString *)title;

/*
 * 显示
 */
//- (void)show;

-(void)showInView:(UIView *)superview;

/*
 * 隐藏
 */
- (void)hide;


/*
 * 重刷数据
 */
-(void)reload;

@end


@interface AUPickerBaseView ()

// 需要子类重写覆盖
// private method
- (void)_cancel;

// private method 
- (void)_finish;

@end

#endif//程序自动生成
