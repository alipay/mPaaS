//
//  PopMenuDemoViewController.m
//  AntUI
//
//  Created by zhaolei on 2017/8/18.
//  Copyright © 2017年 Alipay. All rights reserved.
//

#import "PopMenuDemoViewController.h"

@interface PopMenuDemoViewController () <AUPopMenuDelegate>
{
    AUPopMenu *_menu;
    UIView* _mHeaderView;
    UIView* _mFooterView;
}

@end

@implementation PopMenuDemoViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    self.headerView.hidden = YES;
    self.footerView.hidden = YES;
//    _mHeaderView = [[UIView alloc] initWithFrame:CGRectMake(0, 64, AUCommonUIGetScreenWidth(), 50.0)];
//    _mHeaderView.tag = 2;
//    [self addButtonWithView:_mHeaderView];
    
    _mFooterView = [[UIView alloc] initWithFrame:CGRectMake(0, self.view.height - 50.0, AUCommonUIGetScreenWidth(), 50.0)];
    _mFooterView.tag = 2;
    [self addButtonWithView:_mFooterView];
    
//    [self.view addSubview:_mHeaderView];
    [self.view addSubview:_mFooterView];
}

-(void)viewDidLayoutSubviews
{
    NSLog(@"");
}

- (void)addButtonWithView:(UIView *) view
{
    UIButton *tempButton;
    CGFloat tag = 0;
    for (int i = 0; i < 3; i++) {
        tag = i;
        NSString *chineseNumber = @"";
        if (i == 0) {
            chineseNumber = @"一";
        }else if(i == 1){
            chineseNumber = @"二";
        }else{
            chineseNumber = @"三";
        }
        
        tempButton = [UIButton buttonWithType:UIButtonTypeSystem];
        [tempButton setTitle:[NSString stringWithFormat:@"选项%@",chineseNumber]
                    forState:UIControlStateNormal];
        
        [tempButton setTitleColor:RGB(0x333333) forState:UIControlStateNormal];
        
        tempButton.layer.borderWidth = 0.5;
        tempButton.layer.borderColor = RGB(0xdddddd).CGColor;

        tempButton.frame = CGRectMake((view.width/3)*i,0,(view.width/3),view.height);
        tempButton.tag = tag;
        [view addSubview:tempButton];
        [tempButton addTarget:self
                       action:@selector(buttonClicked:)
             forControlEvents:UIControlEventTouchUpInside];
    }
}

- (void)buttonClicked:(UIButton *)button
{
    if (_menu.superview)
    {
        [_menu hideMenu];
        _menu = nil;
        return;
    }
    
    
    NSMutableArray *array = [[NSMutableArray alloc] init];
    
    AUPopItemModel *model = [[AUPopItemModel alloc] init];
    model.titleString = @"检查更新";
//    model.iconImage = [UIImage imageNamed:@"footer_icon"];
    if (button.tag == 1) {
        model.badgeNumber = @"1";
    } else if (button.tag == 0) {
        model.titleString = @"联系";
        model.badgeNumber = @"3";
    }
    
    [array addObject:model];
    
    model = [[AUPopItemModel alloc] init];
    model.titleString = @"建议反馈";
//    model.iconImage = [UIImage imageNamed:@"footer_icon"];
    if (button.tag == 1) {
        model.badgeNumber = @"7";
    } else if (button.tag == 2) {
        model.badgeNumber = @"7";
        model.titleString = @"建议反馈建议反馈建议反馈建议反馈建议反馈建议反馈建议反馈建议反馈建议反馈建议反馈";
    }
    [array addObject:model];
    
    model = [[AUPopItemModel alloc] init];
    model.titleString = @"EEEEEEEEEEEEEEE联系我们";
    if (button.tag == 1) {
        model.badgeNumber = @"99";
    } else if (button.tag == 0) {
        model.titleString = @"联系我们";
    }
    [array addObject:model];
    
    BOOL isArchViewUp = NO;
    CGFloat offset = -5;
//    if(button.tag == 1){
//        isArchViewUp = NO;
//        offset = 5;
//    }
    
    CGPoint point = [self.view convertPoint:CGPointMake(CGRectGetMidX(button.frame), CGRectGetMinY(button.frame) + offset)
                                   fromView:button.superview];
    _menu = [[AUPopMenu alloc] initWithDatas:array
                                    position:point
                                   superView:self.view];
    _menu.isArchViewUp = isArchViewUp;
    _menu.delegate = self;
    [_menu showMenu];
    
//    [self performSelector:@selector(updateDatas:) withObject:array afterDelay:3.f];
}

//- (void)updateDatas:(id)sender
//{
//    if ([sender isKindOfClass:[NSArray class]]) {
//        AUPopItemModel *model = [sender lastObject];
//        model.iconImage = [UIImage imageNamed:@"footer_icon"];
//        model.badgeNumber = @"7";
//        [_menu updateDatas:sender];
//    }
//}

- (void)DidClickPopItemViewAtIndex:(NSInteger)index itemModel:(AUPopItemModel *)viewModel
{
    NSLog(@"index:%d",(int)index);
}

@end
