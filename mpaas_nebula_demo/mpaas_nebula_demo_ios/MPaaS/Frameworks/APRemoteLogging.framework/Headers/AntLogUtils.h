//
//  AntLogUtils.h
//  APRemoteLogging
//
//  Created by 卡迩 on 2017/12/13.
//  Copyright © 2017年 Alipay. All rights reserved.
//

#import <Foundation/Foundation.h>

extern NSString *APLogURLEncoding(NSString * string);

extern NSString* APLogMD5String(NSString *string);

extern NSData* APLogGZipCompress(NSData *data);

extern NSString* APLogPathForFile(NSString * name);

extern NSString* SLFilterString(NSString * string);

extern NSString* APStringFromDate(NSDate *date);

extern NSString* SLFilterKeyString(NSString * string);
