//
//  DemoBasicViewContriller.h
//  AntUI
//
//  Created by 莜阳 on 2017/8/16.
//  Copyright © 2017年 Alipay. All rights reserved.
//

#import "DemoPageHeaderView.h"
#import "DemoPageFooterView.h"

@interface DemoBaseViewController : UIViewController

@property (nonatomic, strong) DemoPageHeaderView *headerView;
@property (nonatomic, strong) DemoPageFooterView *footerView;
@property (nonatomic, strong) UIView *contentView;
@property (nonatomic, assign) CGFloat topMargin;

- (void)updateFooterView;

- (UIView *)getANewSpliteLineWithTop:(CGFloat) top
                                left:(CGFloat) left;

@end
