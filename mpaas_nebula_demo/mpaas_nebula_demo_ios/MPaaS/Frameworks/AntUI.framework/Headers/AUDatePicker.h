#import "AUUILoadDefine.h"//程序自动生成
#ifdef ANTUI_UI_pickerView_AUDatePicker//程序自动生成
//
//  ALPPicketView.h
//  TestCell
//
//  Created by zhiyuan.yzy on 13-4-19.
//  Copyright (c) 2013年 Alipay. All rights reserved.
//

#import <UIKit/UIKit.h>

typedef void (^AUDatePickerHideBlock)();

//#########################################################
//文档地址 : https://yuque.antfin-inc.com/antui/auidoc/ios_audatepicker
//#########################################################


#define UI_AUDatePicker

@class AUDatePicker;

@protocol AUDatePickerDelegate <UIPickerViewDataSource, UIPickerViewDelegate>

/*
 * 点取消息时回调
 */
- (void)cancelPickerView:(AUDatePicker *)pickerView;

/*
 * 点完成时回调，选中项可通过pickerView/Users/zhuwei/ios-phone-antui/ANTUI/Sources/Views/pickerView/AUDatePicker.h selectedRowInComponent返回
 */
- (void)selectedPickerView:(AUDatePicker *)pickerView;

@end
/*！
 @class       AUDatePicker
 @abstract    UIView
 @discussion  原框架封装的选择器，在原来系统控件上加上的去掉和完成按钮
 */

@interface AUDatePicker : UIView

@property(nonatomic, strong) UIPickerView *pickerView;      //通用事务选择器
@property(nonatomic, strong) UIDatePicker *datePickerView;  //时间选择器

@property(nonatomic, assign) BOOL       isDatePicker;   // 当前是否是时间选择器，默认为NO不是

@property(nonatomic, weak) id<AUDatePickerDelegate> delegate;


/*
 * 创建组件
 *
 * @param title 标题，可为nil
 * @return 创建的组件，默认不显示，需调用show
 */
+ (AUDatePicker *)pickerViewWithTitle:(NSString *)title;

/*
 * 初始化对象
 *
 * @param frame 显示位置
 * @param title 显示标题，不显示可设nil
 * @return 默认返回对象不显示，要显示需要调show
 */
- (id)initWithFrame:(CGRect)frame withTitle:(NSString *)title;

- (id)initWithFrame:(CGRect)frame
          withTitle:(NSString *)title
      finishBtnText:(NSString *) finishBtnText
      cancelBtnText:(NSString *) cancelBtnText;

/*
 * 显示
 */
- (void)show;

/*
 * 隐藏
 */
- (void)hide;

/*
 * 隐藏动画完成后调用block
 */
- (void)hide:(AUDatePickerHideBlock) block;

/**
 * 重载数据
 */
- (void)reload;


/**
 当isDatePicker为YES时，使用datePickerView选择时间

 @param minDate 最小时间
 @param maxDate 最大时间
 */
- (void) setTimeDateminDate:(NSDate *)minDate MaxDate:(NSDate *)maxDate;



/**
 当isDatePicker为YES时，设置datePickerView的当前时间
 
 @param currentDate 设置当前的时间
 */
- (void) setCurrentDate:(NSDate *) currentDate;


/**
 当isDatePicker为YES时，设置时间选择器中选择的时间

 @param date     选中的日期
 @param animated 是否包含动画
 */
- (void)setAUDatePickerDate:(NSDate *)date animated:(BOOL)animated; // if animated is YES, animate the wheels of time to display the new date

@end

#endif//程序自动生成
