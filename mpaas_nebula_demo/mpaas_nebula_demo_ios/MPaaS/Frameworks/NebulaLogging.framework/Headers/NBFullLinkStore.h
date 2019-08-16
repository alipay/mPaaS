//
//  NBFullLinkStore.h
//  NebulaLogging
//
//  Created by 张光宇 on 2018/12/19.
//  Copyright © 2018 Alipay. All rights reserved.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@interface NBFullLinkStore : NSObject
@property(nonatomic,weak)UIViewController *currentViewController;

+ (instancetype)appStore:(NSString *)appId;

- (void)addTimeStub:(NSString *)phase withTime:(CFTimeInterval)mediaTime;

- (void)addTimeStub:(NSString *)phase;

- (void)addCostAttr:(NSString *)key value:(NSUInteger)costInMs;

- (void)addBizAttr:(NSString *)key value:(NSString *)value;

- (void)addAttributesFromDictionary:(NSDictionary *)dictionary;

- (NSString *)appId;

- (NSDictionary *)gatherDataAndClearCache;

+ (void)clearStore:(NSString *)appId;

@end

NS_ASSUME_NONNULL_END
