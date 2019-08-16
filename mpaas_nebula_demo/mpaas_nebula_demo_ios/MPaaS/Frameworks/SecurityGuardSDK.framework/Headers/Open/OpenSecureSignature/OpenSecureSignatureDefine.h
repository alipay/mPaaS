//
// OpenSecurityGuardSDK version 2.1.0
//

/**
 *  签名调用中，OpenSecurityGuardParamContex中paramDict参数中使用到的key
 */

/**
 *  签名接口入参key，top, umid签名使用
 */
extern NSString* const OPEN_KEY_SIGN_INPUT;


/**
 *  seedkey，top 签名使用
 */
extern NSString* const OPEN_KEY_SIGN_SEEDKEY;

/**
 *  atlaskey，atlas 签名使用
 */
extern NSString* const OPEN_KEY_SIGN_ATLAS;

/**
 *  签名调用中，OpenSecurityGuardParamContex中requestType参数中使用到的值
 */

/**
 *  top签名
 */
extern NSInteger const OPEN_ENUM_SIGN_TOP;

/**
 *  umid签名
 */
extern NSInteger const OPEN_ENUM_SIGN_UMID;

/**
 *  原始top签名(无seekKey)
 */
extern NSInteger const OPEN_ENUM_SIGN_TOP_OLD;

/**
 *  common hmac sha1签名
 */
extern NSInteger const OPEN_ENUM_SIGN_COMMON_HMAC_SHA1;

/**
 *  common md5签名
 */
extern NSInteger const OPEN_ENUM_SIGN_COMMON_MD5;

/**
 *  atlas签名
 */
extern NSInteger const OPEN_ENUM_SIGN_ATLAS;

/**
 *  带模拟器检测功能的hmac-sha1签名
 */
extern NSInteger const OPEN_ENUM_SIGN_SIM_HMAC_SHA1;

/**
 *  Fast atlas签名 签名String长度50
 */
extern NSInteger const OPEN_ENUM_SIGN_ATLAS_FAST;

/**
 *  Fast atlas签名2
 */
extern NSInteger const OPEN_ENUM_SIGN_ATLAS_FAST2;

/**
 *  xiami签名
 */
extern NSInteger const OPEN_ENUM_SIGN_XIAMI;


/**
 *  无效签名类型
 */
extern NSInteger const OPEN_ENUM_SIGN_INVALID;
