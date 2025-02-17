//
//  KeyboardsDemoViewController.m
//  AntUIDemo
//
//  Created by maizhelun on 2017/9/25.
//  Copyright © 2017年 Alipay. All rights reserved.
//

#import "KeyboardsDemoViewController.h"

@interface KeyboardsDemoViewController ()
{
    AUNumKeyboards *_keyboard;
}

@property (nonatomic,weak) AUNumKeyboards *weakK;

@end

@implementation KeyboardsDemoViewController

- (UIView *)addCheckBoxUnder:(UIView *)underView
                     originX:(CGFloat)originX
                       title:(NSString *)title
                       block:(void(^)(AUCheckBox *checkbox, AULabel *titleLabel))actionBlock
{
    AUCheckBox *checkbox1 = [[AUCheckBox alloc] initWithStyle:AUCheckBoxStyleDefault];
    checkbox1.left = 10;
    checkbox1.top = 0;
    checkbox1.userInteractionEnabled = NO;
    AULabel *label = [[AULabel alloc] init];
    label.text = title;
    label.font = [UIFont systemFontOfSize:14];
    [label sizeToFit];
    label.left = checkbox1.right + 5;
    label.centerY = checkbox1.centerY;
    
    UIView *view = [[UIView alloc] init];
    view.auviewActionBlock = ^{
        checkbox1.checked = !checkbox1.checked;
        if (actionBlock) {
            actionBlock(checkbox1, label);
        }
    };
    view.left = originX;
    view.top = underView.bottom + 5;
    
    view.width = label.right;
    view.height = MAX(checkbox1.bottom, label.bottom);
    
    [view addSubview:checkbox1];
    [view addSubview:label];
    
    [self.view addSubview:view];
    return view;
}

- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view.

    CGFloat topmargin = self.headerView.bottom;

    // 普通键盘
    {
        AUNumKeyboards *keyboard = [AUNumKeyboards sharedKeyboard];
        AUTextField *textField = [[AUTextField alloc] initWithFrame:CGRectMake(0, 0, 200, 30)];
        textField.placeholder = @"点击唤起自定义数字键盘";
        textField.origin_mp = CGPointMake(kDemoGlobalMargin, topmargin);
        textField.inputView = keyboard;
        
        
        [self.view addSubview:textField];
        
        __weak KeyboardsDemoViewController *weakSelf = self;
        UIView *checkbox1 = [self addCheckBoxUnder:textField originX:10 title:@"“点”隐藏"
                                             block:^(AUCheckBox *checkbox, AULabel *titleLabel){
                                                 weakSelf.weakK.dotHidden = checkbox.checked;
                                             }];
        UIView *checkbox2 = [self addCheckBoxUnder:textField originX:checkbox1.right + 10 title:@"“提交”可点"
                                             block:^(AUCheckBox *checkbox, AULabel *titleLabel){
                                                 weakSelf.weakK.submitEnable = checkbox.checked;
                                             }];
        UIView *checkbox3 = [self addCheckBoxUnder:checkbox1 originX:10 title:@"“收起键盘”隐藏"
                                             block:^(AUCheckBox *checkbox, AULabel *titleLabel){
                                                 weakSelf.weakK.dismissHidden = checkbox.checked;
                                             }];
        UIView *checkbox4 = [self addCheckBoxUnder:checkbox2 originX:checkbox3.right + 10 title:@"“身份证x”显示"
                                             block:^(AUCheckBox *checkbox, AULabel *titleLabel){
                                                 weakSelf.weakK.idNumber = checkbox.checked;
                                             }];
        UIView *checkbox5 = [self addCheckBoxUnder:checkbox4 originX:10 title:@"更改“提交”文案"
                                             block:^(AUCheckBox *checkbox, AULabel *titleLabel){
                                                 weakSelf.weakK.submitText = checkbox.checked ? @"自定义" : @"确定";
                                             }];
        UIView *checkbox6 = [self addCheckBoxUnder:checkbox4 originX:checkbox5.right + 10 title:@"乱序键盘排列"
                                             block:^(AUCheckBox *checkbox, AULabel *titleLabel){
                                                 [weakSelf.weakK setNumKeyRandom:checkbox.checked];
                                             }];
        topmargin = checkbox6.bottom + 10;
    }

    // 社交键盘
    {
        AUNumKeyboards *keyboard =  [self createIfNeeded:AUNumKeyboardModeChat];

        AUTextField *textField = [[AUTextField alloc] initWithFrame:CGRectMake(0, 0, 200, 30)];
        textField.delegate = self;
        textField.placeholder = @"点击唤起自定义社交数字键盘";
        textField.origin_mp = CGPointMake(kDemoGlobalMargin, topmargin);
        textField.inputView = keyboard;
        [self.view addSubview:textField];
        topmargin += 30;
    }
    
    // H5电话键盘
    {
         AUNumKeyboards *keyboard  =[self createIfNeeded: AUNumKeyboardModePhone];
        
        AUTextField *textField = [[AUTextField alloc] initWithFrame:CGRectMake(0, 0, 200, 30)];
        textField.delegate = self;
        textField.placeholder = @"点击唤起电话键盘(H5)";
        textField.origin_mp = CGPointMake(kDemoGlobalMargin, topmargin);
        textField.inputView = keyboard;
        [self.view addSubview:textField];
        topmargin += 30;
    }
    //
    {
//        AUNumKeyboards *keyboards = [AUNumKeyboards sharedKeyboardWithMode:AUNumKeyboardModePhone];
        
        UITextField *textField = [[UITextField alloc] initWithFrame:CGRectMake(0, 0, 200, 30)];
        textField.delegate = self;
        textField.placeholder = @"点击唤起系统键盘";
        textField.origin_mp = CGPointMake(kDemoGlobalMargin, topmargin);
//        textField.inputView = ;
        textField.enablesReturnKeyAutomatically = YES;
        textField.returnKeyType = UIReturnKeySearch;
        [self.view addSubview:textField];
        topmargin += 30;
    }
    
    //小程序键盘
    {
        //        AUNumKeyboards *keyboards = [AUNumKeyboards sharedKeyboardWithMode:AUNumKeyboardModePhone];
        AUNumKeyboards *keyboard = [self createIfNeeded:AUNumKeyboardModeTinyAppNumber];

        UITextField *textField = [[UITextField alloc] initWithFrame:CGRectMake(0, 0, 200, 30)];
        textField.delegate = self;
        textField.inputView = keyboard;
        textField.placeholder = @"点击唤起小程序数字键盘";
        textField.origin_mp = CGPointMake(kDemoGlobalMargin, topmargin);
        //        textField.inputView = ;
        textField.enablesReturnKeyAutomatically = YES;
        textField.returnKeyType = UIReturnKeySearch;
        [self.view addSubview:textField];
            topmargin += 30;
    }
    
    //小程序电话键盘
    {
        //        AUNumKeyboards *keyboards = [AUNumKeyboards sharedKeyboardWithMode:AUNumKeyboardModePhone];
        AUNumKeyboards *keyboard = [self createIfNeeded:AUNumKeyboardModeTinyAppPhone];
        
        UITextField *textField = [[UITextField alloc] initWithFrame:CGRectMake(0, 0, 200, 30)];
        textField.delegate = self;
        textField.inputView = keyboard;
        textField.placeholder = @"点击唤起小程序电话键盘";
        textField.origin_mp = CGPointMake(kDemoGlobalMargin, topmargin);
        //        textField.inputView = ;
        textField.enablesReturnKeyAutomatically = YES;
        textField.returnKeyType = UIReturnKeySearch;
        [self.view addSubview:textField];
        topmargin += 30;
    }
    
    // 普通数字键盘
    {
        AUNumKeyboards *keyboard  =[self createIfNeeded: AUNumKeyboardModeCommon];
        
        AUTextField *textField = [[AUTextField alloc] initWithFrame:CGRectMake(0, 0, 200, 30)];
        textField.delegate = self;
        textField.placeholder = @"点击唤起数字键盘";
        textField.origin_mp = CGPointMake(kDemoGlobalMargin, topmargin);
        textField.inputView = keyboard;
        [self.view addSubview:textField];
        topmargin += 30;
    }
    
    
}

-(AUNumKeyboards *) createIfNeeded:(AUNumKeyboardMode)mode
{
    if(_keyboard.mode == mode &&  _keyboard) {
        return _keyboard;
    }
    return [AUNumKeyboards sharedKeyboardWithMode:mode];
}

- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

-(void) fillKeyBoardParams:(AUNumKeyboards *)keyboard
{
    
}

- (void)textFieldDidBeginEditing:(UITextField *)textField
{
    _keyboard = textField.inputView;
    self.weakK = _keyboard;
}
/*
#pragma mark - Navigation

// In a storyboard-based application, you will often want to do a little preparation before navigation
- (void)prepareForSegue:(UIStoryboardSegue *)segue sender:(id)sender {
    // Get the new view controller using [segue destinationViewController].
    // Pass the selected object to the new view controller.
}
*/

@end
