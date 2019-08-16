//
//  NBLogPagePerformanceEvent.h
//  NebulaBiz
//
//  Created by Glance on 2017/8/4.
//  Copyright © 2017年 Alipay. All rights reserved.
//

#import <NebulaPoseidon/NebulaPoseidon.h>

#define kEvent_Performance_Submit_Before @"performance.submit.before" //通报性事件，从eventData[@"value"]中可以获取NBLogPerformace对象，可调用- [NBLogPerformace reportValue:(id)value forKey:(NSString *) key]在performance中新增字段对

#define kEvent_Performance_DomReady      @"performance.domReady" //通报性事件，从eventData[@"value"]中可以获取domReady时间
#define kEvent_Performance_PageLoad      @"performance.pageLoad" //通报性事件，从eventData[@"value"]中可以获取pageLoad时间
#define kEvent_Performance_JsError       @"performance.jsError" //通报性事件，从eventData[@"value"]中可以获取该条jsError信息，fileName=%@^line=%@^colno=%@^desc=%@
#define kEvent_Performance_BizReady      @"performance.bizeReady" //通报性事件，从eventData[@"value"]中可以获取业务上报的bizeReady时间


@interface NBLogPagePerformanceEvent : PSDEvent

@property (nonatomic, copy) NSDictionary *eventData;

@end
