//
//  DemoBasicViewController.m
//  AntUI
//
//  Created by 莜阳 on 2017/7/27.
//  Copyright © 2017年 Alipay. All rights reserved.
//

#import "DemoComponentViewController.h"

@implementation DemoComponentViewController

- (void)viewWillAppear:(BOOL)animated
{
    [super viewWillAppear:animated];
    // 数据列表，说明：AU_DEMO(类别名称, 条目列表, 类别logo路径)
    AU_DEMO(@"导航",
            (@{
//               @"NavBar" : @"NavigationBarDemoViewController",
//               @"TabBar" : @"DemoTabBarViewController",
               @"Segment" : @"SegmentHomeDemoViewController"
               }),
            @"home_navigation");
    
    AU_DEMO(@"搜索",
            (@{@"SearchBar" : @"SearchHomeDemoViewController"}),
            @"home_search");
    
    AU_DEMO(@"基础组件",
            (@{
               @"Font" : @"FontDemoViewController",
//               @"Article" : @"",
//               @"Badge" : @"BadgeDemoViewController",
               @"IconFont" : @"DemoIconFontViewController",//@"DemoIconFontViewController",//
//               @"IconFont2" : @"DemoIcon2FontViewController",//@"IconfontDemoViewController",
               @"Load" : @"LoadDemoViewController",
               @"Button" : @"ButtonDemoViewViewController",
               @"Carousel" :
                   //                   @"DemoAUBannerViewViewController",
               @"CarouselDemoViewController",
               @"Lists" : @"ListDemoViewController",
               @"AutoLayoutLists" : @"ListAutoLayoutViewController",
               @"Footer" : @"FooterDemoViewController",
               @"Result" : @"ResultViewController",
//               @"LargeResult" : @"AULargeResultViewDemoViewController",
//               @"Screening" : @"",
               @"KeyBoards" : @"KeyboardsDemoViewController",
               @"Color" : @"ColorDemoViewController",
               @"LoadIndicator" : @"LoadIndicatorDemoViewController",
//               @"agreement" : @"DemoAgreementViewViewController",
//               @"AUBladeView": @"bladeViewController"
               }),
            
            @"home_base");
    
    AU_DEMO(@"表单",
            (@{
               @"checkBox" : @"CheckboxDemoViewCotroller",
//               @"Radio" : @"RadioDemoViewController",
               
               @"Input" :
                   @"InputDemoViewController",
//               @"DemoAUInputBoxViewController",
               @"Picker" : @"PickerDemoViewController", // @"APPickerViewViewController", //
               @"Switch" : @"SwitchDemoViewViewController", // @"ListItemsViewController", //
               
               @"TextArea" : @"TextareaDemoViewController"
               }),
            @"home_form");
    
    AU_DEMO(@"操作反馈",
            (@{
               @"Actionsheet" : @"ActionSheetDemoViewController",
               @"Dialog" : @"DialogDemoViewController",
               @"Toast" : @"ToastDemoViewController",
//               @"PopOver" : @"PopoverDemoViewController",
//               @"PopTip" : @"PopTipDemoViewController",
//               @"FilterMenu" : @"DemoFilterMenuViewController",
//               @"BubbleView" : @"DemoBubbleViewViewController",
//               @"APAlertView" : @"DemoAPAlertViewController"
               }),
            @"home_feedback");
    
//    AU_DEMO(@"底层规则",
//            (@{
//               @"Flex" : @"",
//               @"Layer" : @""
//               }),
//            @"home_layout");
}

@end
