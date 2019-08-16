//
//  H5FilePreloadManager.h
//  H5Service
//
//  Created by chenwenhong on 15-2-2.
//  Copyright (c) 2015年 Alipay. All rights reserved.
//

#import <Foundation/Foundation.h>

// error page type
typedef NS_ENUM(NSInteger, EH5ErrorPageType){
    EH5ErrorPageTypeNormal = 0,
    EH5ErrorPageTypeTransparent
};

@interface H5FilePreloadManager : NSObject

+ (NSString *)jsH5PerformanceFileContentString;

+ (NSString *)jsH5ShareFileContentString;

+ (NSString *)jsH5BizlogPreFileContentString;

+ (NSString *)jsH5GeoFileContentString;

+ (NSString *)jsBridgeFileContentString;

+ (NSString *)errorHtmlFileContentString:(EH5ErrorPageType)type;

+ (NSString *)errorHtmlFileContentStringNew;

+ (NSString *)jsNBComponentContentString;

+ (NSString *)jsKeyBoardJS;

+ (NSString *)jsInjectToJSCWithVc:(H5WebViewController *)vc url:(NSString *)url;

+ (NSString *)jsDynamicInjectToJSCWithVc:(H5WebViewController *)vc url:(NSString *)url;

+ (NSString *)jsDynamicConfigJSStringWithVc:(H5WebViewController *)vc url:(NSString *)url;

@end
