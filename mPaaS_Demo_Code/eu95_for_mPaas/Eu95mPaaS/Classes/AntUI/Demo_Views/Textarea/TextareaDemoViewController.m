//
//  TextareaDemoViewController.m
//  AntUI
//
//  Created by 莜阳 on 2017/8/23.
//  Copyright © 2017年 Alipay. All rights reserved.
//

#import "TextareaDemoViewController.h"
#import "AssistDemoDefaultLabelUtil.h"

@implementation TextareaDemoViewController

- (void)viewDidLoad
{
    [super viewDidLoad];
    
    CGFloat topmargin = self.headerView.bottom;
    {
        UILabel *label = [AssistDemoDefaultLabelUtil createDefaultLabelStyle1:@"输入框高度固定，自动聚焦的textarea"];
        label.font = [UIFont systemFontOfSize:14];
        [label sizeToFit];
        label.frame = CGRectMake(kDemoGlobalMargin, topmargin, label.width, label.height);
        [self.view addSubview:label];
        topmargin = label.bottom + 8;
    }
    
    {
        AUParagraphInputBox *_paragraphInputBox = [[AUParagraphInputBox alloc] init];
        _paragraphInputBox.frame = CGRectMake(0, topmargin, AUCommonUIGetScreenWidth(), 10);
        _paragraphInputBox.maxInputLen = 240;
        _paragraphInputBox.textView.delegate = self;
        [_paragraphInputBox setPlaceHolder:@"请输入不少于10个字的描述"];
        [self.view addSubview:_paragraphInputBox];
    }
}

#pragma mark - UITextViewDelegate

- (BOOL)textView:(UITextView *)textView shouldChangeTextInRange:(NSRange)range replacementText:(NSString *)text
{
    return [AUParagraphInputBox textView:textView shouldChangeRange:range replacementString:text maxLength:240];
}

@end
