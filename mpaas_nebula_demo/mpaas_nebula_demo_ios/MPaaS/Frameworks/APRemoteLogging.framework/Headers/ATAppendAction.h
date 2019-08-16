//
//  ATAppendAction.h
//  ATrack
//
//  Created by 卡迩 on 2018/4/26.
//  Copyright © 2018年 Alipay. All rights reserved.
//

#import "ATActionMgr.h"
#import "ATEvent.h"
#import "ATLayout.h"

/**
 * Append操作
 */
@interface ATAppendAction : ATAction

//@property (nonatomic, strong) ATEvent *event;    /**<埋点事件参数对象*/
//@property (nonatomic, strong) ATLayout *layout;  /**<埋点事件对应的渲染器*/

/**
 * 初始化一个Append操作
 * @param event 埋点事件参数对象
 * @param layout 渲染器
 */
- (instancetype)initWithEvent:(ATEvent *)event
                       layout:(ATLayout *)layout NS_DESIGNATED_INITIALIZER;

@end
