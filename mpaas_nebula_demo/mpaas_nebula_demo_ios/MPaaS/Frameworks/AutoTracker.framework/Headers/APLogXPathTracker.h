//
//  APLogXPathTracker.h
//  APMonitor
//
//  Created by majie on 16/11/5.
//  Copyright © 2016年 Alipay. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

@interface APLogXPathTracker : NSObject

/**
 获取 \c view 的XPath.
 
 @description
    XPath的组成: //所在ViewController类名/SuperView类名[i]:${id}/.../当前View类名[0]:${id}|${ViewIndex}
    其中 ${id}取值顺序为:
        尝试取view的spmId值->然后尝试取view.actionName->尝试取view.senderAction->占位符"-"
    ${ViewIndex}生成规则为:
        当 \c view 所在的视图链中不存在 \c UITableViewCell 或 \c UICollectionViewCell 的子类时, ${ViewIndex} 为 -1
        当 \c view 所在的视图链中存在 \c UITableViewCell 或 \c UICollectionViewCell 的子类时, ${ViewIndex} 为 [section][row]
        当 \c view 所在的视图链中同时存在多个 \c UITableViewCell 和 \c UICollectionViewCell 的子类时, ${ViewIndex} 为 [section_0][row_0]|[section_1][row_1]|...
 @note 请保证该View已经有superview时才调用,否则无法正确获得XPath.
 @return \c view 对应的XPath. 当 view == nil 时,返回 \c nil.
 */
+ (NSString *)xpathForView:(UIView *)view
                     spmId:(NSString *)spmId
                actionName:(NSString *)actionName;

//Convenience
+ (NSString *)xpathForView:(UIView *)view;

@end
