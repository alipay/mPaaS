//
//  InputDemoViewController.m
//  AntUI
//
//  Created by zhaolei on 2017/8/28.
//  Copyright © 2017年 Alipay. All rights reserved.
//

#import "InputDemoViewController.h"
//#import "AUSixPwdInputBox.h"
#import <AntUI/AUSixPwdInputBox.h>
//#import "AUTextCodeInputBox.h"
#import <AntUI/AUTextCodeInputBox.h>

@interface InputDemoViewController () <UITextFieldDelegate,AUCustomDatePickerDelegate,AUDatePickerDelegate>

@property(nonatomic,strong)AUDatePicker* apPickerViewDate;
@property(nonatomic,strong)AUCustomDatePicker *apCustomDatePickerView;
@property(nonatomic,strong)UILabel *dateLabel;
@property(nonatomic,strong)UILabel *dateTimeLabel;

@property (nonatomic, assign) CGRect originalFrame;

@end

@implementation InputDemoViewController

- (void)dealloc
{
    [[NSNotificationCenter defaultCenter] removeObserver:self];
}

- (void)viewDidLoad {
    [super viewDidLoad];

    [[NSNotificationCenter defaultCenter] addObserver:self
                                             selector:@selector(checkInput:)
                                                 name:UITextFieldTextDidBeginEditingNotification
                                               object:nil];
    
    [[NSNotificationCenter defaultCenter] addObserver:self
                                             selector:@selector(highKeyBoard:)
                                                 name:UITextFieldTextDidEndEditingNotification
                                               object:nil];
    
    [[NSNotificationCenter defaultCenter] addObserver:self
                                             selector:@selector(showKeyBoard:)
                                                 name:@"demoKeyboardEvent"
                                               object:nil];
    
    self.footerView.hidden = YES;
    [self initPicker];
    
    UITapGestureRecognizer *gesture = [[UITapGestureRecognizer alloc]initWithTarget:self action:@selector(touchEvent)];
    [self.tableView addGestureRecognizer:gesture];
    
    NSMutableArray *models = [[NSMutableArray alloc] init];
    [self addModelWithAutoFocus:models];
    [self addModelWithMaxLength:models];
    [self addModelWithNumberic:models];
    [self addModelWithPW:models];
    [self addModelWithIDCard:models];
    [self addModelWithLongTitle:models];
    [self addModelWithCombine:models];
    self.contentModelList = [NSArray arrayWithArray:models];
}

- (void)touchEvent
{
    [self.view endEditing:YES];
}

// 获取键盘的输入目标, 并设置相应标志
- (void)checkInput:(NSNotification *)notification
{
    UITextField *field = notification.object;
    
    [[NSNotificationCenter defaultCenter] postNotificationName:@"demoKeyboardEvent"
                                                        object:nil
                                                      userInfo:@{@"scroller":field.superview,
                                                                 @"textField":field}];
}

- (void)initPicker
{
    //日期选择器
    self.apPickerViewDate = [AUDatePicker pickerViewWithTitle:@"请选择日期"];
    self.apPickerViewDate.tag = 1002;
    self.apPickerViewDate.isDatePicker = YES;
    self.apPickerViewDate.delegate = self;
    NSDate * curretntDate = [NSDate date];
    NSDate * minxDate = [NSDate dateWithTimeInterval:-(3600*24*3000) sinceDate:curretntDate];
    NSDate * maxDate = [NSDate dateWithTimeInterval:3600*24*3000 sinceDate:curretntDate];
    [self.apPickerViewDate setTimeDateminDate:minxDate MaxDate:maxDate];
    [self.apPickerViewDate setCurrentDate:maxDate];
    [self.view addSubview:self.apPickerViewDate];
    
    //自定义日期时间选择器
    NSCalendar *calendar = [[NSCalendar alloc]initWithCalendarIdentifier:NSCalendarIdentifierGregorian];
    
    NSDateComponents *components = [[NSDateComponents alloc]init];
    [components setYear:2014];
    [components setMonth:2];
    [components setDay:14];
    [components setHour:2];
    [components setMinute:04];
    NSDate *from = [calendar dateFromComponents:components];
    
    NSDateComponents *endComponents = [[NSDateComponents alloc]init];
    [endComponents setYear:2019];
    [endComponents setMonth:10];
    [endComponents setDay:14];
    [endComponents setHour:14];
    [endComponents setMinute:4];
    [endComponents setSecond:9];
    NSDate *to = [calendar dateFromComponents:endComponents];
    
    
    NSDateComponents *nowComponents = [[NSDateComponents alloc]init];
    [nowComponents setYear:2017];
    [nowComponents setMonth:8];
    [nowComponents setDay:14];
    [nowComponents setHour:13];
    [nowComponents setMinute:3];
    [nowComponents setSecond:9];
    NSDate *now = [calendar dateFromComponents:nowComponents];
    
    self.apCustomDatePickerView = [AUCustomDatePicker pickerViewWithTitle:@"AUDatePickerYearMonth" pickerMode:AUDatePickerModeDateAndTime];
    [self.apCustomDatePickerView setTimeDateminDate:from MaxDate:to];
    [self.apCustomDatePickerView setCurrentDate:now animated:NO];
    self.apCustomDatePickerView.delegate = self;
    [self.view addSubview:self.apCustomDatePickerView];
}

- (void)addModelWithAutoFocus:(NSMutableArray *) mutableArray
{
    DemoContentModel *model = [[DemoContentModel alloc] init];
    model.headerTitle = @"input自动聚焦";
    UIView *wrapView = [self getNewWrapView];
    AUInputBox *inputBox = [AUInputBox inputboxWithOriginY:0
                                              inputboxType:AUInputBoxTypeNone];
    inputBox.style = AUInputBoxStyleNone;
    [wrapView addSubview:inputBox];
    
    
    
    model.contentView = wrapView;
    
    [inputBox.textField becomeFirstResponder];
    
    [mutableArray addObject:model];
}

- (void)addModelWithMaxLength:(NSMutableArray *) mutableArray
{
    DemoContentModel *model = [[DemoContentModel alloc] init];
    model.headerTitle = @"Input最大输入长度";
    UIView *wrapView = [self getNewWrapView];
    AUInputBox *inputBox = [AUInputBox inputboxWithOriginY:0
                                              inputboxType:AUInputBoxTypeNone];
    inputBox.style = AUInputBoxStyleNone;
    inputBox.textField.placeholder = @"Input最大输入长度为10";
    inputBox.textField.delegate = self;
    [wrapView addSubview:inputBox];
    model.contentView = wrapView;
    [mutableArray addObject:model];
}

- (void)addModelWithNumberic:(NSMutableArray *) mutableArray
{
    DemoContentModel *model = [[DemoContentModel alloc] init];
    model.headerTitle = @"输入数字的Input";
    UIView *wrapView = [self getNewWrapView];
    AUInputBox *inputBox = [AUInputBox inputboxWithOriginY:0
                                              inputboxType:AUInputBoxTypeNone];
    inputBox.style = AUInputBoxStyleNone;
    inputBox.textField.placeholder = @"这是一个数字输入框";
    inputBox.textField.inputView = [AUNumKeyboards sharedKeyboardWithMode:AUNumKeyboardModeCommon];
    [wrapView addSubview:inputBox];
    model.contentView = wrapView;
    [mutableArray addObject:model];
}

- (void)addModelWithPW:(NSMutableArray *) mutableArray
{
    DemoContentModel *model = [[DemoContentModel alloc] init];
    model.headerTitle = @"输入密码的Input";
    UIView *wrapView = [self getNewWrapView];
    AUSixPwdInputBox *pwdInputBox = [[AUSixPwdInputBox alloc] initWithQuadWidth:35 quadHeight:40];
    wrapView.top = 2;
    pwdInputBox.numericPassword = NO;
    [pwdInputBox setBackgroundImage:nil];
    [wrapView addSubview:pwdInputBox];
    model.contentView = wrapView;
    [mutableArray addObject:model];
}

- (void)addModelWithIDCard:(NSMutableArray *) mutableArray
{
    DemoContentModel *model = [[DemoContentModel alloc] init];
    model.headerTitle = @"输入身份证的Input";
    UIView *wrapView = [self getNewWrapView];
    AUInputBox *inputBox = [AUInputBox inputboxWithOriginY:0
                                              inputboxType:AUInputBoxTypeIDNumber];
    inputBox.style = AUInputBoxStyleNone;
    inputBox.textField.placeholder = @"身份证输入键盘";
    [wrapView addSubview:inputBox];
    model.contentView = wrapView;
    [mutableArray addObject:model];
}

- (void)addModelWithLongTitle:(NSMutableArray *) mutableArray
{
    DemoContentModel *model = [[DemoContentModel alloc] init];
    model.headerTitle = @"标题超长";
    UIView *wrapView = [self getNewWrapView];
    AUInputBox *inputBox = [AUInputBox inputboxWithOriginY:0
                                              inputboxType:AUInputBoxTypeNone];
    inputBox.style = AUInputBoxStyleNone;
    inputBox.titleLabel.text = @"双项输入";
    inputBox.textField.placeholder = @"暗提示";
    [wrapView addSubview:inputBox];
    
    [wrapView addSubview:[self getANewSpliteLineWithTop:inputBox.bottom left:kDemoGlobalMargin]];
    
    inputBox = [AUInputBox inputboxWithOriginY:inputBox.bottom
                                              inputboxType:AUInputBoxTypeNone];
    inputBox.style = AUInputBoxStyleNone;
    inputBox.titleLabel.text = @"最长可六个字";
    inputBox.textField.placeholder = @"暗提示右移与标题间隔10px";
    
    CGSize titleSize = [inputBox.titleLabel.text sizeWithAttributes:@{NSFontAttributeName : inputBox.titleLabel.font}];
    inputBox.titleLabelWidth = titleSize.width + 5;
    
    
    [wrapView addSubview:inputBox];
    wrapView.height = inputBox.bottom;
    
    model.contentView = wrapView;
    [mutableArray addObject:model];
}

- (void)addModelWithCombine:(NSMutableArray *) mutableArray
{
    DemoContentModel *model = [[DemoContentModel alloc] init];
    model.headerTitle = @"组合输入";
    UIView *wrapView = [self getNewWrapView];
    AUInputBox *inputBox = [AUInputBox inputboxWithOriginY:0
                                              inputboxType:AUInputBoxTypeNone];
    inputBox.style = AUInputBoxStyleNone;
    inputBox.titleLabel.text = @"姓名";
    inputBox.textField.placeholder = @"请输入真实姓名";
    [wrapView addSubview:inputBox];
    
    [wrapView addSubview:[self getANewSpliteLineWithTop:inputBox.bottom left:kDemoGlobalMargin]];
    
    AUTextCodeInputBox *smsInputBox = [[AUTextCodeInputBox alloc] initWithOriginY:inputBox.bottom
                                                                         interval:60];
    smsInputBox.bShowBorder = NO;
    [smsInputBox.actionButton addTarget:self
                                 action:@selector(onSmsButtonClicked:)
                       forControlEvents:UIControlEventTouchUpInside];
    [wrapView addSubview:smsInputBox];
    
    [wrapView addSubview:[self getANewSpliteLineWithTop:smsInputBox.bottom left:kDemoGlobalMargin]];
    
    UIView *dateTimeView = [self buildDateTimeView:0];
    dateTimeView.top = smsInputBox.bottom+1;
    [wrapView addSubview:dateTimeView];
    
    [wrapView addSubview:[self getANewSpliteLineWithTop:dateTimeView.bottom left:kDemoGlobalMargin]];
    CGFloat top = dateTimeView.bottom + 1;
    dateTimeView = [self buildDateTimeView:1];
    dateTimeView.top = top;
    [wrapView addSubview:dateTimeView];
    
    wrapView.height = dateTimeView.bottom;
    model.contentView = wrapView;
    [inputBox.textField becomeFirstResponder];
    
    [mutableArray addObject:model];
}

- (void)onSmsButtonClicked:(id)sender
{
    
}

- (BOOL)textField:(UITextField *)textField shouldChangeCharactersInRange:(NSRange)range replacementString:(NSString *)string
{
    if ([textField.placeholder isEqualToString:@"Input最大输入长度为10"]) {
        AUInputBox *inputBox = (AUInputBox *)textField.superview;
        return [inputBox shouldChangeRange:range replacementString:string withFormatStringMaxLength:10];
    }
    return YES;
}

- (UILabel *)buildLabel
{
    UILabel *titleLabel = [[UILabel alloc] init];
    titleLabel.textAlignment = NSTextAlignmentLeft;
    titleLabel.userInteractionEnabled = NO;
    titleLabel.textColor = RGB(0x333333);
    titleLabel.font = [UIFont systemFontOfSize:AU_TEXTSIZE6];//AU_FONT6;
    titleLabel.backgroundColor = [UIColor clearColor];
    titleLabel.text = @"点击选择";
    [titleLabel sizeToFit];
    return titleLabel;
}

- (UIView *)buildDateTimeView:(int) type;
{
    UIView *view = [self getNewWrapView];
    UILabel *titleLabel = [self buildLabel];
    
    if (type == 0) {
        titleLabel.text = @"日期";
    }else{
        titleLabel.text = @"时间";
    }
    
    [titleLabel sizeToFit];
    titleLabel.left = kDemoGlobalMargin;
    titleLabel.top = (view.height - titleLabel.height)/2;
    [view addSubview:titleLabel];
    
    if (type == 0) {
        if (!self.dateLabel) {
            self.dateLabel = [self buildLabel];
        }
        self.dateLabel.left = 100;
        self.dateLabel.top = titleLabel.top;
        [view addSubview:self.dateLabel];
        
        UITapGestureRecognizer *gesture = [[UITapGestureRecognizer alloc]initWithTarget:self action:@selector(showPicker)];
        [view addGestureRecognizer:gesture];
    }else{
        if (!self.dateTimeLabel) {
            self.dateTimeLabel = [self buildLabel];
        }
        self.dateTimeLabel.left = 100;
        self.dateTimeLabel.top = titleLabel.top;
        [view addSubview:self.dateTimeLabel];
        
        UITapGestureRecognizer *gesture = [[UITapGestureRecognizer alloc]initWithTarget:self action:@selector(showCustomPicker)];
        [view addGestureRecognizer:gesture];
    }

    return view;
}

- (void)showPicker
{
    [self.apPickerViewDate show];
}

- (void)showCustomPicker
{
    [self.apCustomDatePickerView show];
}

- (void)selectedPickerView:(AUDatePicker *)pickerView
{
    if (pickerView.tag == 1002) {
        NSDate *selectedDate = pickerView.datePickerView.date;
        NSDateFormatter *formatter = [[NSDateFormatter alloc]init];
        formatter.dateFormat = @"YYYY-MM-dd";
        [self.dateLabel setText:[formatter stringFromDate:selectedDate]];
        [self.dateLabel sizeToFit];
        [pickerView hide];
    }else{
        AUCustomDatePicker *picker = (AUCustomDatePicker*)pickerView;
        NSDate *selectedDate = picker.selectedDate;
        NSDateFormatter *formatter = [[NSDateFormatter alloc]init];
        formatter.dateFormat = @"MM-dd HH:mm:ss";
        [self.dateTimeLabel setText:[formatter stringFromDate:selectedDate]];
        [self.dateTimeLabel sizeToFit];
        [picker hide];
    }
}

/*
 * 点取消时回调
 */
- (void)cancelPickerView:(AUDatePicker *)pickerView
{
    if (pickerView.tag == 1002) {
        [pickerView hide];
    }else{
        AUCustomDatePicker *picker = (AUCustomDatePicker*)pickerView;
        [picker hide];
    }
}

#pragma mark -------------------- 键盘事件处理
- (void)showKeyBoard:(NSNotification *) notification
{
    if (!CGRectEqualToRect(self.originalFrame, CGRectZero)) {
        return;
    }
    
    if ([notification.userInfo objectForKey:@"scroller"] == nil
        || [notification.userInfo objectForKey:@"textField"] == nil) {
        return;
    }

    UITextField *textField = [notification.userInfo objectForKey:@"textField"];
    
    CGPoint point = [self.view convertPoint:textField.frame.origin fromView:textField];
    
    NSLog(@"%f,%f",(self.view.bottom - 258),(point.y + textField.height));
    
    if ((self.view.bottom - 258) < (point.y + textField.height)) {
        self.originalFrame = self.tableView.frame;
        
        CGFloat offset = (self.view.bottom - 258) - (point.y + textField.height) - 44;//44是随便加的 -.-
        
        NSTimeInterval animationDuration = 0.30f;
        [UIView beginAnimations:nil context:nil];
        [UIView setAnimationDuration:animationDuration];
        float width = self.tableView.width;
        float height = self.tableView.height;
        
        CGRect rect = CGRectMake(0.0f, offset,width,height);
        self.tableView.frame = rect;
        
        [UIView commitAnimations];
    }
}

- (void)highKeyBoard:(NSNotification *) notification
{
    if (!CGRectEqualToRect(self.originalFrame, CGRectZero)) {
        [UIView animateWithDuration:0.3 animations:^{
            self.tableView.frame = self.originalFrame;
        } completion:^(BOOL finished) {
            self.originalFrame = CGRectZero;
        }];
    }
}

@end
