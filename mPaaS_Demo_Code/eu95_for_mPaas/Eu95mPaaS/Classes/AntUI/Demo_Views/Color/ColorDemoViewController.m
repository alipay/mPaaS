//
//  ColorDemoViewController.m
//  AntUIDemo
//
//  Created by 沫竹 on 2017/10/30.
//  Copyright © 2017年 Alipay. All rights reserved.
//

#import "ColorDemoViewController.h"

@interface ColorDemoViewController ()

@end

@implementation ColorDemoViewController {
    AUInputBox *_textField;
    UIView *_colorView;
}

- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view.
    
    CGFloat topmargin = self.headerView.bottom;
    
    // 普通键盘
    {
        _textField = [AUInputBox inputboxWithOriginY:topmargin inputboxType:AUInputBoxTypeNone];
        _textField.origin_mp = CGPointMake(kDemoGlobalMargin, topmargin);
        
        UILabel *prefixLabel = [[UILabel alloc] init];
        prefixLabel.font = [UIFont systemFontOfSize:12];
        prefixLabel.text = @"# ";
        [prefixLabel sizeToFit];
        prefixLabel.height = _textField.textField.height;
        prefixLabel.textColor = _textField.textField.textColor;
        
        _textField.textField.font = [UIFont systemFontOfSize:12];
        _textField.textField.placeholder = @"输入ARGB测试颜色";
        _textField.textField.text = @"FF000000";
        _textField.textField.leftView = prefixLabel;
        _textField.textField.leftViewMode = UITextFieldViewModeAlways;
        _textField.titleLabel.text = @"ARGB";
        [ _textField.textField addTarget:self action:@selector(textFieldDidChange:) forControlEvents:UIControlEventEditingChanged];
        [self.view addSubview:_textField];
        topmargin += 30;
        
        AUButton *button = [AUButton buttonWithStyle:AUButtonStyle3];
        button.frame = _textField.frame;
        button.width = 50;
        button.height = 30;
        [button setTitle:@"吸色" forState:UIControlStateNormal];
        [button setTitleColor:[UIColor blackColor] forState:UIControlStateNormal];
        [button addTarget:self action:@selector(readColor:) forControlEvents:UIControlEventTouchUpInside];
        button.x = kDemoGlobalMargin;
        button.y = CGRectGetMaxY(_textField.frame) + 10;
        [self.view addSubview:button];
        
        _colorView = [[UIView alloc] initWithFrame:button.frame];
        _colorView.x = CGRectGetMaxX(button.frame) + 20;
        _colorView.y = CGRectGetMaxY(_textField.frame) + 10;
        _colorView.width = _colorView.height;
        [self.view addSubview:_colorView];
    }
    
}

- (void)readColor:(UIButton *)button
{
    UIColor *color = [UIColor colorFromHexString:_textField.textField.text];
    _colorView.backgroundColor = color;
}


- (void) textFieldDidChange:(UITextField *)textField
{
    NSInteger kMaxLength = 8;
    NSString *toBeString = textField.text;
    NSString *lang = [[UIApplication sharedApplication]textInputMode].primaryLanguage; //ios7之前使用[UITextInputMode currentInputMode].primaryLanguage
    if ([lang isEqualToString:@"zh-Hans"]) { //中文输入
        UITextRange *selectedRange = [textField markedTextRange];
        //获取高亮部分
        UITextPosition *position = [textField positionFromPosition:selectedRange.start offset:0];
        if (!position) {// 没有高亮选择的字，则对已输入的文字进行字数统计和限制
            if (toBeString.length > kMaxLength) {
                textField.text = [toBeString substringToIndex:kMaxLength];
            }
        }
        else{//有高亮选择的字符串，则暂不对文字进行统计和限制
        }
    }else{//中文输入法以外的直接对其统计限制即可，不考虑其他语种情况
        if (toBeString.length > kMaxLength) {
            textField.text = [toBeString substringToIndex:kMaxLength];
        }
    }
}

- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
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
