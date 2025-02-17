//
//  cardMenuController.m
//  AntUI
//
//  Created by 祝威 on 16/9/29.
//  Copyright © 2016年 Alipay. All rights reserved.
//

#import "cardMenuController.h"
//#import "AUCardMenu.h"
//#import "AUCellDataModel.h"
//#import "AUMultiStyleCellView.h"

@interface cardMenuController ()<AUMultiStyleCellDelegate>

@property (nonatomic,strong)     AUCardMenu * popMenuView;

@end

@implementation cardMenuController

- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view.
    self.view.backgroundColor = RGB(0xF5F5F9);
    UIButton * button = [UIButton buttonWithType:UIButtonTypeCustom];
    [button setFrame:CGRectMake(0, 100, self.view.width, 100)];
    [button setTitle:@"弹出菜单/多行组合样式" forState:UIControlStateNormal];
    [button setTitleColor:RGB(0x999999) forState:UIControlStateNormal];
    [button addTarget:self
               action:@selector(handleButton:)
     forControlEvents:UIControlEventTouchUpInside];
    [button.titleLabel setTextAlignment:NSTextAlignmentLeft];
    [button.titleLabel setFont:[UIFont systemFontOfSize:14]];
    [button setTitleEdgeInsets:UIEdgeInsetsMake(0, 5, 0, 0)];
    [button setContentHorizontalAlignment:UIControlContentHorizontalAlignmentLeft];

    [self.view addSubview:button];
    
    UIButton * button2 = [UIButton buttonWithType:UIButtonTypeCustom];
    [button2 setFrame:CGRectMake(0, 220, self.view.width, 100)];
    [button2 setTitle:@"弹出菜单/按压效果" forState:UIControlStateNormal];
    [button2 addTarget:self
               action:@selector(handleButton2:)
     forControlEvents:UIControlEventTouchUpInside];
    [button2.titleLabel setTextAlignment:NSTextAlignmentLeft];
    [button2 setTitleEdgeInsets:UIEdgeInsetsMake(0, 5, 0, 0)];
    [button2 setContentMode:UIViewContentModeLeft];
    [button2 setContentHorizontalAlignment:UIControlContentHorizontalAlignmentLeft];

    [button2 setTitleColor:RGB(0x999999) forState:UIControlStateNormal];
    [button2.titleLabel setFont:[UIFont systemFontOfSize:14]];

    [self.view addSubview:button2];
    
    UIButton * button3 = [UIButton buttonWithType:UIButtonTypeCustom];
    [button3 setFrame:CGRectMake(0, 320, self.view.width, 100)];
    [button3 setTitle:@"弹出菜单/双行" forState:UIControlStateNormal];
    [button3 addTarget:self
                action:@selector(handleButton3:)
      forControlEvents:UIControlEventTouchUpInside];
    [button3.titleLabel setTextAlignment:NSTextAlignmentLeft];
    [button3 setTitleEdgeInsets:UIEdgeInsetsMake(0, 5, 0, 0)];
    [button3 setContentHorizontalAlignment:UIControlContentHorizontalAlignmentLeft];
    [button3.titleLabel setFont:[UIFont systemFontOfSize:14]];


    [button3 setTitleColor:RGB(0x999999) forState:UIControlStateNormal];

    [self.view addSubview:button3];


    UIButton * button4 = [UIButton buttonWithType:UIButtonTypeCustom];
    [button4 setFrame:CGRectMake(0, 420, self.view.width, 100)];
    [button4 setTitle:@"弹出菜单+选择按钮" forState:UIControlStateNormal];
    [button4 addTarget:self
                action:@selector(handleButton4:)
      forControlEvents:UIControlEventTouchUpInside];
    [button4.titleLabel setTextAlignment:NSTextAlignmentLeft];
    [button4 setTitleEdgeInsets:UIEdgeInsetsMake(0, 5, 0, 0)];
    [button4 setContentHorizontalAlignment:UIControlContentHorizontalAlignmentLeft];
    [button4.titleLabel setFont:[UIFont systemFontOfSize:14]];

    [button4 setTitleColor:RGB(0x999999) forState:UIControlStateNormal];

    [self.view addSubview:button4];

}

- (void)handleButton4:(UIButton *)button
{
    AUCellDataModel * model = [[AUCellDataModel alloc] init];
    model.iconUrl = @"APCommonUI_ForDemo.bundle/hc_popmenu_dislike";
    model.titleText = @"我不感兴趣";
    model.buttonsArray = @[@"过时",@"看过了",@"质量差"];
    model.extendDic = @{@"type":@"reject",@"cardId":@"201609261515032720200000091128291606950000902688",@"CCard":@""};
    

    AUCardMenu *tmpView=[[AUCardMenu alloc]initWithData:@[model] location:CGPointMake(button.width - 20, button.centerY) offset:13];
    tmpView.cellView.delegate=self;
    [tmpView showPopMenu:button animation:YES];
    self.popMenuView=tmpView;
    
}

- (void)handleButton3:(UIButton *)button
{
    AUCellDataModel * model = [[AUCellDataModel alloc] init];
    model.iconUrl = @"APCommonUI_ForDemo.bundle/hc_popmenu_ignore";
    model.titleText = @"忽略";
    //    model.buttonsArray = @[@"你好",@"口吃吗",@"我不饿",@"你好吗",@"我很好"];
    model.extendDic = @{@"type":@"reject",@"cardId":@"201609261515032720200000091128291606950000902688",@"CCard":@""};

    AUCellDataModel * model4 = [[AUCellDataModel alloc] init];
    model4.iconUrl = @"APCommonUI_ForDemo.bundle/hc_popmenu_reject";
    model4.titleText = @"不再接受此类消息";
    model4.descText = @"减少此类消息的接收";
    model4.extendDic = @{@"type":@"reject",@"cardId":@"201609261515032720200000091128291606950000902688",@"CCard":@""};
    AUCardMenu *tmpView=[[AUCardMenu alloc]initWithData:@[model,model4] location:CGPointMake(button.width - 20, button.centerY) offset:13];
    tmpView.cellView.delegate=self;
    [tmpView showPopMenu:button animation:YES];
    self.popMenuView=tmpView;

}

- (void)handleButton2:(UIButton *)button
{
    AUCellDataModel * model = [[AUCellDataModel alloc] init];
    model.iconUrl = @"APCommonUI_ForDemo.bundle/hc_popmenu_ignore";
    model.titleText = @"忽略";
    //    model.buttonsArray = @[@"你好",@"口吃吗",@"我不饿",@"你好吗",@"我很好"];
    model.extendDic = @{@"type":@"reject",@"cardId":@"201609261515032720200000091128291606950000902688",@"CCard":@""};
    AUCellDataModel * model2 = [[AUCellDataModel alloc] init];
    model2.iconUrl = @"APCommonUI_ForDemo.bundle/hc_popmenu_dislike";
    model2.titleText = @"我不感兴趣";
    model2.extendDic = @{@"type":@"reject",@"cardId":@"201609261515032720200000091128291606950000902688",@"CCard":@""};
    model2.highlightState = YES;
    AUCellDataModel * model3 = [[AUCellDataModel alloc] init];
    model3.iconUrl = @"APCommonUI_ForDemo.bundle/hc_popmenu_inform";
    model3.titleText = @"投诉";
    model3.extendDic = @{@"type":@"reject",@"cardId":@"201609261515032720200000091128291606950000902688",@"CCard":@""};
    AUCellDataModel * model4 = [[AUCellDataModel alloc] init];
    model4.iconUrl = @"APCommonUI_ForDemo.bundle/hc_popmenu_reject";
    model4.titleText = @"不再接受此类消息";
    model4.descText = @"减少此类消息的接收";
    model4.extendDic = @{@"type":@"reject",@"cardId":@"201609261515032720200000091128291606950000902688",@"CCard":@""};
    AUCardMenu *tmpView=[[AUCardMenu alloc]initWithData:@[model,model2,model3,model4] location:CGPointMake(button.width - 20, button.centerY) offset:13];
    tmpView.cellView.delegate=self;
    [tmpView showPopMenu:button animation:YES];
    self.popMenuView=tmpView;

}
- (void)handleButton:(UIButton *)button
{
    AUCellDataModel * model = [[AUCellDataModel alloc] init];
    model.iconUrl = @"APCommonUI_ForDemo.bundle/hc_popmenu_ignore";
    model.titleText = @"忽略";
//    model.buttonsArray = @[@"你好",@"口吃吗",@"我不饿",@"你好吗",@"我很好"];
    model.extendDic = @{@"type":@"reject",@"cardId":@"201609261515032720200000091128291606950000902688",@"CCard":@""};
    AUCellDataModel * model2 = [[AUCellDataModel alloc] init];
    model2.iconUrl = @"APCommonUI_ForDemo.bundle/hc_popmenu_dislike";
    model2.titleText = @"我不感兴趣";
    model2.extendDic = @{@"type":@"reject",@"cardId":@"201609261515032720200000091128291606950000902688",@"CCard":@""};
    AUCellDataModel * model3 = [[AUCellDataModel alloc] init];
    model3.iconUrl = @"APCommonUI_ForDemo.bundle/hc_popmenu_inform";
    model3.titleText = @"投诉";
    model3.extendDic = @{@"type":@"reject",@"cardId":@"201609261515032720200000091128291606950000902688",@"CCard":@""};
    AUCardMenu *tmpView=[[AUCardMenu alloc]initWithData:@[model,model2,model3] location:CGPointMake(button.width - 20, button.centerY) offset:13];
    tmpView.cellView.delegate=self;
    [tmpView showPopMenu:button animation:YES];
    self.popMenuView=tmpView;
    

}


- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

- (void)hidePopMenu
{
    if (self.popMenuView) {
        [self.popMenuView hidePopMenuWithAnimation:YES];
        self.popMenuView.cellView.delegate = nil;
        self.popMenuView = nil;
        
    }
}


#pragma mark --- AUMultiStyleCellDelegate
/**
 *  点击事件回调
 *
 *  @param dataModel 点击的view对应的数据模型
 *  @param indexPath 点击的view在CellDataModel中的下标(若 CellDataModel.buttonsArray == nil ,则 row 默认取值为 -1)
 */
- (void)DidClickCellView:(AUCellDataModel *)dataModel ForRowAtIndexpath:(NSIndexPath *)indexPath
{
    [self hidePopMenu];
}
- (void)DidClickCellButton:(AUCellDataModel *)dataModel ForRowAtIndexpath:(NSIndexPath *)indexPath
{
    [self hidePopMenu];
}
- (void)DidClickCellView:(AUCellDataModel *)dataModel ForRowAtIndexpath:(NSIndexPath *)indexPath cellView:(AUMultiStyleCellView *)cellView
{
    [self hidePopMenu];
}


- (void)dealloc
{
    self.popMenuView = nil;

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
