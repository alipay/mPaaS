//
//  AMMAudioMessage.h
//  MobileFoundation
//
//  Created by Monster on 10/3/13.
//  Copyright (c) 2013 Alipay. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CommonCrypto/CommonCrypto.h>

#define KEY_SUFFIX_WAV      @"#WAV"
#define KEY_SUFFIX_SLK      @"#SLK"

@interface AMMAudioMessage : NSObject


@property (nonatomic,retain) NSString *localId;
@property (nonatomic,retain) NSNumber *audioTime;   //音频时长，double类型
@property (nonatomic,retain) NSData   *audioData;   //音频数据

/**
 *  通过localId获取message对象
 *
 *  @param localId
 *
 *  @return message
 */
+ (AMMAudioMessage*)getMessageWithLocalId:(NSString*)localId;

@end