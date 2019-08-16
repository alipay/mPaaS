//
//  H5AuthManager.h
//  H5Service
//
//  Created by theone on 15/4/29.
//  Copyright (c) 2015年 Alipay. All rights reserved.
//

#import <Foundation/Foundation.h>
typedef void(^h5AuthCallback)(NSURL *result,BOOL shouldchangeurl);
typedef void(^h5AuthcodeCallback)(id data);

@interface H5AuthManager : NSObject
+ (instancetype)sharedInstance;
- (void)authWithOriginUrl:(NSURL *)url callback:(h5AuthCallback)callback;
- (void)authWithParams:(NSDictionary *)params  callback:(h5AuthcodeCallback)callback;
- (void)auth:(PSDContext *)context withParams:(NSDictionary *)params  callback:(h5AuthcodeCallback)callback supportH5Mode:(BOOL)supportH5Mode;

@end
