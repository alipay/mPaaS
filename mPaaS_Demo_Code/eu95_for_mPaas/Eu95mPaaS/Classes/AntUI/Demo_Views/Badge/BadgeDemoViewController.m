//
//  BadgeDemoViewController.m
//  AntUI
//
//  Created by zhaolei on 2017/8/31.
//  Copyright © 2017年 Alipay. All rights reserved.
//

#import "BadgeDemoViewController.h"
#import "AUSingleTitleListItem.h"
#import "AUBadgeView.h"
#import "AUBadgeView0.h"
#import <objc/runtime.h>
#import "UIFont+CustomFont.h"

#define buildBadge(style,content1,view) [self buildBageViewWithStyle:style content:content1 bageView:view]

@interface BadgeDemoViewController (){

}

@property(nonatomic,strong) AUBadgeView* bageView;
@property(nonatomic,assign) double top;
@property(nonatomic,assign) double left;
//@property(nonatomic,strong) AUSingleTitleListItem* item;

@end

@implementation BadgeDemoViewController

- (instancetype)init
{
    self = [super init];
    if (self) {
        
    }
    return self;
}

- (void)viewDidLoad {
    [super viewDidLoad];
    
    self.view.backgroundColor = RGB(0x000000);
    CGFloat top = 120;
    CGFloat left = 50;
    
    AUBadgeView* badegView = buildBadge(AUBadgeViewStyleRedDot,nil,nil);
    badegView.top = top;
    badegView.left = left;
    [self.view addSubview:badegView];
    
    top+=badegView.height;
    top+=10;

    //addRedDot
    UIButton *button = [UIButton buttonWithType:UIButtonTypeSystem];
    [button setTitle:@"RedDot" forState:UIControlStateNormal];
    [button setAu_action:^{
        buildBadge(AUBadgeViewStyleRedDot,nil,badegView);
    }];
    [button sizeToFit];
    button.top = top;
    button.left = left;
    [self.view addSubview:button];
    top+=button.height;
    top+=10;

    //addText
    button = [UIButton buttonWithType:UIButtonTypeSystem];
    [button setTitle:@"Text" forState:UIControlStateNormal];
    button.backgroundColor = [UIColor whiteColor];

    UITextField *textField = [[UITextField alloc] init];
    [button setAu_action:^{
        buildBadge(AUBadgeViewStyleText,textField.text,badegView);
    }];
    textField.backgroundColor = [UIColor whiteColor];
    
    [button sizeToFit];
    button.top = top;
    button.left = left;
    [self.view addSubview:button];
    top+=button.height;
    top+=10;
    textField.size_mp = CGSizeMake(150, 30);
    textField.top = button.top;
    textField.left = button.right + 50;
    textField.text = @"我爱我家bbbb";  
    textField.font = [UIFont systemFontOfSize:12];
    textField.borderStyle = UITextBorderStyleLine;
    [self.view addSubview:textField];
        top+=10;
    
    
    
    //addText
    button = [UIButton buttonWithType:UIButtonTypeSystem];
    [button setTitle:@"Digit" forState:UIControlStateNormal];
    button.backgroundColor = [UIColor whiteColor];
    
    textField = [[UITextField alloc] init];
    [button setAu_action:^{
        buildBadge(AUBadgeViewStyleNumber,textField.text,badegView);
    }];
    textField.backgroundColor = [UIColor whiteColor];
    
    
    [button sizeToFit];
    button.top = top;
    button.left = left;
    [self.view addSubview:button];
    top+=button.height;
    top+=10;
    textField.size_mp = CGSizeMake(150, 30);
    textField.top = button.top;
    textField.left = button.right + 50;
    textField.text = @"4";
    textField.font = [UIFont systemFontOfSize:12];
    textField.borderStyle = UITextBorderStyleLine;
    [self.view addSubview:textField];

//    //addNumber
//    button = [UIButton buttonWithType:UIButtonTypeSystem];
//    [button setTitle:@"Number" forState:UIControlStateNormal];
//
//    textField = [[UITextField alloc] init];
//    [button setAu_action:^{
//        buildBadge(AUBadgeViewStyleNumber,textField.text,badegView);
//    }];
//    [button sizeToFit];
//    button.top = top;
//    button.left = left;
//    [self.view addSubview:button];
//    top+=button.height;
//    top+=10;
//    textField.size = CGSizeMake(100, 30);
//    textField.top = button.top;
//    textField.left = button.right + 50;
//    textField.text = @"1";
//    textField.font = [UIFont systemFontOfSize:12];
//    textField.borderStyle = UITextBorderStyleLine;
//    [self.view addSubview:textField];
//
//    //addnone
//    button = [UIButton buttonWithType:UIButtonTypeSystem];
//    [button setTitle:@"none" forState:UIControlStateNormal];
//    [button setAu_action:^{
//        buildBadge(AUBadgeViewStyleNone,nil,badegView);
//    }];
//    [button sizeToFit];
//    button.top = top;
//    button.left = left;
//    [self.view addSubview:button];
//    top+=button.height;
//    top+=10;
}
- (AUBadgeView *)buildBageViewWithStyle:(int)style
                                content:(NSString *)content
                               bageView:(AUBadgeView *)bageView
{
    if(bageView == nil){
        bageView = [[AUBadgeView alloc] init];
    }
    
    switch (style) {
        case AUBadgeViewStyleText:
            [bageView drawBadgeWithStyle:AUBadgeViewStyleText attributes:@{kAUBadgeViewAttributeKeyText:content}];
            break;
        case AUBadgeViewStyleNumber:
            [bageView drawBadgeWithStyle:AUBadgeViewStyleNumber attributes:@{kAUBadgeViewAttributeKeyNumber:@([content integerValue])}];
            break;
        case AUBadgeViewStyleRedDot:
            [bageView drawBadgeWithStyle:AUBadgeViewStyleRedDot attributes:nil];
            break;
        case AUBadgeViewStyleNone:
            [bageView drawBadgeWithStyle:AUBadgeViewStyleNone attributes:nil];
            break;
        default:
            break;
    }
    return bageView;
}

@end
