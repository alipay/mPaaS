//
//  LBSContinuousLocationManager.h
//  APMobileLBS
//
//  Created by 去疾 on 16/12/5.
//  Copyright © 2016年 Alipay. All rights reserved.
//

#import <Foundation/Foundation.h>

extern NSString *const errorDomainContinuousLocation;
extern NSString *const kContinuousOptionInterval;

typedef NS_ENUM(NSInteger, APContinuousLocationErrorCode) {
    APContinuousLocationErrorCodeNoBiztype = 0,
    APContinuousLocationErrorCodeNotAuth ,
    APContinuousLocationErrorCodeBiztypeInBlacklist,
    APContinuousLocationErrorCodeUnknown,
};

@protocol LBSContinuousLocationDelegate <NSObject>

- (void)locationFailWithError:(NSError *)error;

- (void)locationSucceedWithData:(CLLocation *)location;

@end

@interface LBSContinuousLocationManager : NSObject

+(LBSContinuousLocationManager*)sharedInstance;

-(void)startContinuousLocation:(NSString*)bizType delegate:(id<LBSContinuousLocationDelegate>)delegate andOptions:(NSDictionary*)options;

-(void)stopContinuousLocation:(NSString*)bizType;

@end
