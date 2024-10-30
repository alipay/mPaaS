//
//  PickerDemoViewController.m
//  AntUI
//
//  Created by zhaolei on 2017/8/30.
//  Copyright © 2017年 Alipay. All rights reserved.
//

#import "PickerDemoViewController.h"

@interface PickerDemoViewController ()<AUCustomDatePickerDelegate,AUDatePickerDelegate,AUCascadePickerDelegate,UIPickerViewDelegate>

@property(nonatomic,strong)AUCustomDatePicker* timePicker;
@property(nonatomic,strong)AUCustomDatePicker* datePicker;
@property(nonatomic,strong)AUDatePicker* textPicker;
@property(nonatomic,strong)AUCascadePicker *cascadePickerView;
@property(nonatomic,strong)AUImplDatePicker *embedDatePicker;
@property(nonatomic,strong)UILabel *timeLabel;
@property(nonatomic,strong)UILabel *dateLabel;
@property(nonatomic,strong)UILabel *textLabel;
@property(nonatomic,strong)UILabel *cascadeLabel;
@property(nonatomic,strong)NSArray *textArray;

@end

@implementation PickerDemoViewController{
    UIWindow *_window;
}

- (void)viewDidLoad {
    [super viewDidLoad];
    [self initData];
    [self initPicker];
    NSMutableArray *models = [[NSMutableArray alloc] init];
    [self addModelWithTimePicker:models];
    [self addModelWithDatePicker:models];
    [self addModelWithTextPicker:models];
    [self addModelWithCascadePicker:models];
    [self addModelWithEmbedDatePicker:models];
    self.contentModelList = [NSArray arrayWithArray:models];
    
    //    [[NSNotificationCenter defaultCenter] addObserver:self selector:@selector(enterBackgroundMode) name:UIApplicationDidEnterBackgroundNotification object:nil];
    
}

- (void)addModelWithTimePicker:(NSMutableArray *) mutableArray
{
    DemoContentModel *model = [[DemoContentModel alloc] init];
    model.headerTitle = @"时间选择器";
    self.timeLabel = [self buildLabel];
    model.contentView = [self buildViewWithTitle:@"当前选择"
                                    contentLabel:self.timeLabel
                                          picker:self.timePicker
                                          tapSEL:@selector(showTimePicker)];
    [mutableArray addObject:model];
}

- (void)addModelWithDatePicker:(NSMutableArray *) mutableArray
{
    DemoContentModel *model = [[DemoContentModel alloc] init];
    model.headerTitle = @"日期选择器";
    self.dateLabel = [self buildLabel];
    model.contentView = [self buildViewWithTitle:@"当前选择"
                                    contentLabel:self.dateLabel
                                          picker:self.datePicker
                                          tapSEL:@selector(showDatePicker)];
    [mutableArray addObject:model];
}

- (void)addModelWithTextPicker:(NSMutableArray *) mutableArray
{
    DemoContentModel *model = [[DemoContentModel alloc] init];
    model.headerTitle = @"单项选择器";
    self.textLabel = [self buildLabel];
    model.contentView = [self buildViewWithTitle:@"当前选择"
                                    contentLabel:self.textLabel
                                          picker:self.textPicker
                                          tapSEL:@selector(showTextPicker)];
    [mutableArray addObject:model];
}

- (void)addModelWithCascadePicker:(NSMutableArray *) mutableArray
{
    DemoContentModel *model = [[DemoContentModel alloc] init];
    model.headerTitle = @"级联选择器";
    self.cascadeLabel = [self buildLabel];
    model.contentView = [self buildViewWithTitle:@"当前选择"
                                    contentLabel:self.cascadeLabel
                                          picker:self.cascadePickerView
                                          tapSEL:@selector(showCascadePicker)];
    [mutableArray addObject:model];
}

- (void)addModelWithEmbedDatePicker:(NSMutableArray *) mutableArray
{
    DemoContentModel *model = [[DemoContentModel alloc] init];
    model.headerTitle = @"页面嵌入时间选择器选择器";
    self.cascadeLabel = [self buildLabel];
    model.contentView = [self buildViewWithTitle:@"当前选择"
                                    contentLabel:self.cascadeLabel
                                          picker:self.embedDatePicker
                                          tapSEL:@selector(showEmbedDatePicker)];
    [mutableArray addObject:model];
}


- (UIView *)buildViewWithTitle:(NSString *) title
                  contentLabel:(UILabel *)contentLabel
                        picker:(id)picker
                        tapSEL:(SEL)tapSEL
{
    UIView *view = [self getNewWrapView];
    UILabel *titleLabel = [self buildLabel];
    titleLabel.text = title;
    [titleLabel sizeToFit];
    titleLabel.left = kDemoGlobalMargin;
    titleLabel.top = (view.height - titleLabel.height)/2;
    [view addSubview:titleLabel];
    
    contentLabel.left = 100;
    contentLabel.top = titleLabel.top;
    [view addSubview:contentLabel];
    
    UITapGestureRecognizer *gesture = [[UITapGestureRecognizer alloc]initWithTarget:self action:tapSEL];
    [view addGestureRecognizer:gesture];
    
    return view;
}

#ifdef DEBUG_MOCK
- (void)enterBackgroundMode
{
    [self performSelector:@selector(showDatePicker) withObject:nil afterDelay:2.0];
    
    UIViewController *inputVC= [[NSClassFromString(@"InputDemoViewController") alloc] init];
    [self.navigationController pushViewController:inputVC animated:NO];
}
#endif

- (void)showTimePicker
{
    [self.timePicker show];
}

- (void) showEmbedDatePicker
{
    if(!self.embedDatePicker) {
        self.embedDatePicker = [[AUImplDatePicker alloc]initWithFrame:CGRectMake(0, 50, self.view.width, 216.0)];
        self.embedDatePicker.datePickerMode = AUDatePickerModeDate;
        //self.embedDatePicker.delegate = self.embedDatePicker;
        //self.embedDatePicker.dataSource = self.embedDatePicker;
        self.embedDatePicker.pickerDelegate = self;
        [self.embedDatePicker reloadData];
        [self.embedDatePicker reloadAllComponents];
        if(!_window){
            _window = [[UIWindow alloc]initWithFrame:CGRectMake(0, 0, self.view.width, self.view.height)];
            _window.backgroundColor = RGB(0xFFFFFF);
        }
        [_window addSubview:self.embedDatePicker];
        [_window makeKeyAndVisible];
        [_window addGestureRecognizer:({
            UITapGestureRecognizer *tap = [[UITapGestureRecognizer alloc]initWithTarget:self  action:@selector(showEmbedDatePicker)];
            tap;
        })];
    }
    else {
        [[UIApplication sharedApplication].keyWindow makeKeyAndVisible];
        _window = nil;
        [self.embedDatePicker removeFromSuperview];
        self.embedDatePicker = nil;
    }
}

- (void)showDatePicker
{
    [self.datePicker showOnSuperView:self.view];
    //    [self.datePicker show];
}

-(void) didSelectDatePickerView:(AUImplDatePicker *) picker
{
    NSDate *data = picker.selectedDate;
    NSLog(@"%@",data);
    
}

//
- (void)showCascadePicker
{
    [self.cascadePickerView showInView:self.view];
}

- (void)showTextPicker
{
    [self.textPicker show];
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


- (void)initData
{
    self.textArray = @[@"居民户口簿",@"身份证",@"临时居住证",@"军官证",];
}

- (void)clickBottmView:(id)sender
{
    [AUToast presentToastWithin:self.view withIcon:AUToastIconNone text:@"点击了底部按钮" duration:2.0 logTag:@"Demo"];
}

- (void)setupCascadePicker
{
    AUCascadePickerModel *model = [[AUCascadePickerModel alloc] init];
    
    NSMutableArray *modelList = [[NSMutableArray alloc] init];
    for (int i=0; i<6; i++)
    {
        AUCascadePickerRowItemModel *item = [[AUCascadePickerRowItemModel alloc] init];
        item.rowTitle = [NSString stringWithFormat:@"第一层的%d", i];
        NSMutableArray *array = [[NSMutableArray alloc] init];
        for (int j=0; j<7; j++)
        {
            if (i == 0)
            {
                break;
            }
            AUCascadePickerRowItemModel *item1 = [[AUCascadePickerRowItemModel alloc] init];
            item1.rowTitle = [NSString stringWithFormat:@"第二层的%d", j];
            NSMutableArray *array1 = [[NSMutableArray alloc] init];
            for (int k=0; k<5; k++) {
                AUCascadePickerRowItemModel *item2 = [[AUCascadePickerRowItemModel alloc] init];
                item2.rowTitle = [NSString stringWithFormat:@"第三层的%d", k];
                [array1 addObject:item2];
                if (j == 1 || j== 2) {
                    break;
                }
            }
            item1.rowSubList = array1;
            [array addObject:item1];
            if (i == 3 || i== 5) {
                break;
            }
        }
        item.rowSubList = array;
        [modelList addObject:item];
    }
    
    model.dataList = modelList;
    
    
    AUCascadePickerSelectedRowItem *item = [[AUCascadePickerSelectedRowItem alloc] init];
    item.selectedLeftTitle = @"第一层的0";
    item.selectedMiddleTitle = @"第二层的0";
    item.selectedRightTitle = @"第三层的0";
    
    model.selectedItem = item;
    //#endif
    
    // 级联选择器
    self.cascadePickerView = [[AUCascadePicker alloc] initWithPickerModel:model];
    self.cascadePickerView.tag = 1004;
    self.cascadePickerView.linkageDelegate = self;
    [self.view addSubview:self.cascadePickerView];
}

- (void)initPicker
{
    self.timePicker = [AUCustomDatePicker pickerViewWithTitle:@"" pickerMode:AUDatePickerModeTime];
    self.timePicker.tag = 1001;
    self.timePicker.delegate = self;
    [self.view addSubview:self.timePicker];
    
    self.datePicker = [AUCustomDatePicker pickerViewWithTitle:@"有效期" pickerMode:AUDatePickerModeDate];
    self.datePicker.tag = 1002;
    self.datePicker.delegate = self;
    
    UIButton *button = [[UIButton alloc] initWithFrame:CGRectMake(0, 0, self.view.width, 30)];
    [button setTitle:@"底部按钮" forState:UIControlStateNormal];
    [button setTitleColor:AU_COLOR9 forState:UIControlStateNormal];
    [button addTarget:self action:@selector(clickBottmView:) forControlEvents:UIControlEventTouchUpInside];
    [self.datePicker setBottomView:button];
    
    //自定义日期时间选择器
    NSCalendar *calendar = [[NSCalendar alloc]initWithCalendarIdentifier:NSCalendarIdentifierGregorian];
    
    NSDateComponents *components = [[NSDateComponents alloc]init];
    [components setYear:2014];
    [components setMonth:1];
    [components setDay:1];
    [components setHour:1];
    [components setMinute:01];
    NSDate *from = [calendar dateFromComponents:components];
    
    NSDateComponents *endComponents = [[NSDateComponents alloc]init];
    [endComponents setYear:2019];
    [endComponents setMonth:12];
    [endComponents setDay:30];
    [endComponents setHour:23];
    [endComponents setMinute:59];
    [endComponents setSecond:59];
    NSDate *to = [calendar dateFromComponents:endComponents];
    
    [self.datePicker setTimeDateminDate:from MaxDate:to];
    
    [self.view addSubview:self.datePicker];
    
    
    //类方法创建的pickerView
    self.textPicker = [AUDatePicker pickerViewWithTitle:nil];
    self.textPicker.delegate = self;
    self.textPicker.tag = 1003;
    [self.view addSubview:self.textPicker];
    
    // 级联选择器
    [self setupCascadePicker];
}

- (void)selectedPickerView:(AUCustomDatePicker *)pickerView
{
    if (pickerView.tag == 1001) {
        AUCustomDatePicker *picker = (AUCustomDatePicker*)pickerView;
        NSDate *selectedDate = picker.selectedDate;
        NSDateFormatter *formatter = [[NSDateFormatter alloc]init];
        formatter.dateFormat = @"HH:mm";
        [self.timeLabel setText:[formatter stringFromDate:selectedDate]];
        [self.timeLabel sizeToFit];
    }else if(pickerView.tag == 1002){
        AUCustomDatePicker *picker = (AUCustomDatePicker*)pickerView;
        NSDate *selectedDate = picker.selectedDate;
        NSDateFormatter *formatter = [[NSDateFormatter alloc]init];
        formatter.dateFormat = @"YYYY-MM-dd";
        [self.dateLabel setText:[formatter stringFromDate:selectedDate]];
        [self.dateLabel sizeToFit];
    }else if (pickerView.tag == 1004) {
        AUCascadePicker *picker = (AUCascadePicker*)pickerView;
        NSString *text = [NSString stringWithFormat:@"%@-%@-%@", picker.dataModel.selectedItem.selectedLeftTitle, picker.dataModel.selectedItem.selectedMiddleTitle, picker.dataModel.selectedItem.selectedRightTitle];
        [self.cascadeLabel setText:text];
        [self.cascadeLabel sizeToFit];
    } else{
        AUDatePicker *picker = (AUDatePicker*)pickerView;
        NSInteger index = [picker.pickerView selectedRowInComponent:0];
        NSString *result = [self.textArray objectAtIndex:index];
        [self.textLabel setText:result];
        [self.textLabel sizeToFit];
    }
    
    [pickerView hide];
}

- (void)cancelPickerView:(AUDatePicker *)pickerView
{
    if ([pickerView isKindOfClass:[AUDatePicker class]]) {
        AUDatePicker *picker = (AUDatePicker*)pickerView;
        [picker hide];
    }else{
        [pickerView hide];
    }
}

#pragma UIPickerView delegate
- (NSString *)pickerView:(UIPickerView *)pickerView titleForRow:(NSInteger)row forComponent:(NSInteger)component
{
    return [self.textArray objectAtIndex:row];
}

- (NSInteger)numberOfComponentsInPickerView:(UIPickerView *)pickerView
{
    return 1;
}

- (NSInteger)pickerView:(UIPickerView *)pickerView numberOfRowsInComponent:(NSInteger)component
{
    return [self.textArray count];
}

@end
