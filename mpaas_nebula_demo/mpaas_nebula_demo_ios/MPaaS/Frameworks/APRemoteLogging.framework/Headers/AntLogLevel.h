//
//  AntLogLevel.h
//  AntLog
//
//  Created by 卡迩 on 2017/1/28.
//  Copyright © 2017年 Alipay. All rights reserved.
//

#ifndef AntLogLevel_h
#define AntLogLevel_h

/**
 * 日志等级
 */
typedef NS_ENUM(NSInteger,AntLogLevel) {
    AntLogLevelHigh   = 1,  //级别最高
    AntLogLevelNormal = 2,  //默认级别
    AntLogLevelLow    = 3   //级别最低
};

#ifdef __cplusplus
extern "C" {
#endif
    /**
     * 将字符串类型的等级转换成枚举
     * @param str 字符串类型的logLevel,支持@"1"或者@"level1"
     */
    AntLogLevel AntLogLevelFromString(NSString *str);
    
#ifdef SDK_IS4_ALIPAY
    /**
     * 将枚举类型的logLevel转换成字符串
     * @param level logLevel
     * @return level对应的字符串,@"1"、@"2"、@"3"中的一个
     */
    NSString *AntLogLevelToString(AntLogLevel level);
#endif
    /**
     * 兼容老接口,从扩展Map中获取logLevel值
     * @param dict 扩展Map
     */
    AntLogLevel AntLogLevelFromFormatterDict(NSDictionary *dict);
#ifdef __cplusplus
}
#endif


#endif /* AntLogLevel_h */
