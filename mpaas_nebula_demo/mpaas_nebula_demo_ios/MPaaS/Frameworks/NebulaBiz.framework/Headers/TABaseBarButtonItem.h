//
//  TABarButtonItem.h
//  TinyappService
//
//  Created by 闻蹊 on 2018/4/26.
//  Copyright © 2018年 Alipay. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface TABaseBarButtonItem : UIView
//
@property (nonatomic, strong) UIButton *optionButton;

- (void)changeTintColor:(BOOL)isLight;


@end
