//
//  AUPopMsgContainerView.h
//  AntUI
//
//  Created by niki on 2018/11/21.
//  Copyright © 2018年 Alipay. All rights reserved.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSInteger, MsgContainerLabelAlignment) {
    MsgContainerLabelAlignmentLeft = 1,
    MsgContainerLabelAlignmentCenter = 2,
};

@interface AUPopMsgContainerView : AUPopContentView

@property (nonatomic, assign) MsgContainerLabelAlignment labelAligment;

- (instancetype)initWithText:(NSString *)text
                        desc:(NSString *)desc
                        icon:(UIImage *)icon;

@end

NS_ASSUME_NONNULL_END
