//
//  AssistDemoDefaultLabelUtil.m
//  AntUI
//
//  Created by 莜阳 on 2017/8/23.
//  Copyright © 2017年 Alipay. All rights reserved.
//

#import "AssistDemoDefaultLabelUtil.h"


@implementation AssistDemoDefaultLabelUtil

+ (UILabel *)createDefaultLabelStyle1:(NSString *)title
{
    UILabel *label = [[UILabel alloc] init];
    label.text = title;
    label.textColor = [UIColor colorWithRGB:0x999999];
    label.font = [UIFont systemFontOfSize:14];
    [label sizeToFit];
    return label;
}

@end


