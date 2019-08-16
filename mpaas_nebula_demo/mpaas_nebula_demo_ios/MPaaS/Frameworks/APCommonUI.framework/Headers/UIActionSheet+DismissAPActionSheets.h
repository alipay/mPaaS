//
//  UIActionSheet+DismissAPActionSheets.h
//  APCommonUI
//
//  Created by liangbao.llb on 10/22/15.
//  Copyright © 2015 Alipay. All rights reserved.
//

#import <UIKit/UIKit.h>

//__deprecated_msg("请直接使用 UIActionSheet+DismissAUActionSheet.h 提供的方法")
@interface UIActionSheet (DismissAPActionSheets)

/**
 *  清除所有APActionSheet的显示。
 *  注意：对系统类做category时，加alipay前缀防止和系统函数冲突。
 */
+ (void)alipayDismissAllAPActionSheets;

@end
