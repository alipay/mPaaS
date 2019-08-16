//
//  APStartAppSchemeExceptionHandler.h
//  APMobileFramework
//
//  Created by liangbao.llb on 16/4/12.
//  Copyright © 2016年 Alipay. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface APStartAppSchemeExceptionHandler : NSObject

/**
 *  根据指定的名称判断是否可以启动一个应用。
 *
 *  @param name       要启动的应用名
 *  @param params     启动应用时，需要转递给应用的参数
 *  @param completion 处理结果回调，YES表示已经处理不需要后续处理，否则继续处理。
 */
- (void)canHandleStartApplicationException:(NSString *)name
                                    params:(NSDictionary *)params
                                completion:(void (^)(BOOL finished))completion;

@end
