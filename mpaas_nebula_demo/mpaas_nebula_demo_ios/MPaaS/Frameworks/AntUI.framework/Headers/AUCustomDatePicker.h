#import "AUUILoadDefine.h"//程序自动生成
#ifdef ANTUI_UI_pickerView_AUCustomDatePicker//程序自动生成


/**
 *  日期选择控件
 *  和系统控件不同之处：在minDate ~ maxDate之外的日期不可见，也不可选
 *
 */

@class AUCustomDatePicker;

@protocol AUCustomDatePickerDelegate <NSObject>

/*
 * 点取消时回调
 */
- (void)cancelPickerView:(AUCustomDatePicker *)pickerView;

/*
 * 点完成时回调，选中项可通过 selectedRowInComponent返回
 */
- (void)selectedPickerView:(AUCustomDatePicker *)pickerView;

@end



typedef NS_ENUM(NSInteger, AUCustomDatePickerMode) {
    AUDatePickerModeTime,           // 小时/分，24小时制
    AUDatePickerModeDate,           // 年/月/日
    AUDatePickerModeDateAndTime,    // 月/日/星期 小时/分/,24小时制，注意年是按照minimumDate定义,默认是个2000闰年，存在2/29
    AUDatePickerYearMonth,           // 年/月
    AUDatePickerYear                // 年
    
};

@class AUImplDatePicker;

@protocol AUImplDatePickerDelegate

@required

-(void) didSelectDatePickerView:(AUImplDatePicker *) picker;

@end

@interface AUImplDatePicker : UIPickerView

@property (nonatomic) AUCustomDatePickerMode datePickerMode; // 默认AUDatePickerModeDate

@property (nonatomic,assign) BOOL skipRefreshOnWindow;
@property (nullable, nonatomic, strong) NSLocale   *locale;  // 默认手机设定的区域
@property (nullable, nonatomic, copy)   NSCalendar *calendar;// 默认公元日历
@property (nullable, nonatomic, strong) NSTimeZone *timeZone;// 默认手机设定
@property (nullable, nonatomic, strong) NSDate *date;
@property (nullable, nonatomic, strong) NSDate *minimumDate; // 最小日期，默认2000年1月1日 00:00:00,闭
@property (nullable, nonatomic, strong) NSDate *maximumDate; // 最大日期, 默认2050年12月31日 23:59:59闭

@property (nullable, nonatomic,weak) id<AUImplDatePickerDelegate> pickerDelegate;

// 设定需要选中的时间,如果不设置，默认今天。
- (void) setCurrentDate:(nullable NSDate *) currentDate animated:(BOOL) animated;

-(void) reloadData;

-(NSDate*_Nullable)selectedDate;

@end

@interface AUCustomDatePicker : UIView

@property (nullable,nonatomic,weak) id<AUCustomDatePickerDelegate> delegate;

@property (nullable,nonatomic,readonly) NSDate *selectedDate;

//自定义底部View
@property (nullable,nonatomic,strong) UIView *bottomView;
// 
@property (nullable,nonatomic,strong) UIView *backgroundView;
@property (nullable,nonatomic,strong) UIView *containerView;


/**
 * 创建Picker，默认使用AUDatePickerModeDate模式
 *
 */
+ (AUCustomDatePicker *)pickerViewWithTitle:(NSString *)title;

+ (AUCustomDatePicker *)pickerViewWithTitle:(NSString *)title pickerMode:(AUCustomDatePickerMode)mode;

/**
 * 设定可选择的日期区间
 @param minDate 最小时间,默认2000年1月1日 00:00:00,闭
 @param maxDate 最大时间,默认2050年12月31日 23:59:59闭
 */
- (void) setTimeDateminDate:(NSDate *)minDate MaxDate:(NSDate *)maxDate;



/** 
 @param currentDate 设置默认选中的时间
 */
- (void) setCurrentDate:(NSDate *) currentDate animated:(BOOL) animated;



/**
 展示日期选择控件
 */
-(void) show __deprecated_msg("废弃，业务请勿继续使用");

/**
 展示日期选择控件，指定展示在的superview
 */
- (void)showOnSuperView:(UIView *)superView;

/**
 隐藏日期选择控件
 */
-(void) hide;

@end


#endif
