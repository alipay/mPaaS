

#import <Foundation/Foundation.h>

/**
 * User ID 的BizType
 * */
extern const unsigned char BIZ_UID[];

/**
 * Item ID 的BizType
 * */
extern const unsigned char BIZ_IID[];

/**
 * Trade ID 的BizType
 * */
extern const unsigned char BIZ_TID[];


@protocol IOpenOpenSDKComponent <NSObject>
/**
 * 分析 Open ID
 *
 * @param openId        openId的数值
 *
 * @param appIdKey      appId对应的key值
 *
 * @param saltKey       salt对应的key值
 *
 * @param bizType       解析类型
 *
 * @param authCode SDK的授权码，不传或为空串，使用默认加密文件
 *
 * @return	openId中包含的指定内容，传人非法参数时返回nil
 */
- (NSNumber*) analyzeOpenId:(NSString*) openId
                   appIdKey: (NSString*) appIdKey
                    saltKey: (NSString*) saltKey
                    bizType: (NSData*) bizType
                    authCode: (NSString*) authCode;

@end
