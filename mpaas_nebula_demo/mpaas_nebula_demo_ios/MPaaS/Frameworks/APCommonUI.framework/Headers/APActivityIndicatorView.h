//
//  APActivityIndicatorView.h
//  APCommonUI
//
//  Created by yangwei on 16/4/12.
//  Copyright © 2016年 Alipay. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <AntUI/AULoadingIndicatorView.h>


__deprecated_msg("APActivityIndicatorViewStyle 已经废弃，请直接使用 AULoadingIndicatorViewStyle")
typedef AULoadingIndicatorViewStyle APActivityIndicatorViewStyle;

__deprecated_msg("APActivityIndicatorView 已经废弃，请直接使用 AULoadingIndicatorView")
@interface APActivityIndicatorView : AULoadingIndicatorView //UIView

- (instancetype)initWithActivityIndicatorStyle:(APActivityIndicatorViewStyle)style;

@end
