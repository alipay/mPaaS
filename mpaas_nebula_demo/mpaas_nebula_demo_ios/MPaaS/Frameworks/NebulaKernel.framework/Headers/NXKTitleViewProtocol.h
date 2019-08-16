//
//  NXKTitleViewProtocol.h
//  NebulaKernel
//
//  Created by theone on 2018/9/10.
//  Copyright © 2018年 Alipay. All rights reserved.
//

#import <Foundation/Foundation.h>

@protocol NXKTitleViewProtocol <NSObject>
- (void)titleViewCreateAfterWithMainTitle:(NSString *)mainTitle
                                 subTitle:(NSString *)subTitle
                                titleView:(UIView *)titleView;
@end
