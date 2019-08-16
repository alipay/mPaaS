//
// OpenSecurityGuardSDK version 2.1.0
//

#import <Foundation/Foundation.h>

/**
 *  安全凭证加解密模块使用加密算法
 */



/**
 *  aes128算法
 */
extern NSInteger const OPEN_CIPHER_AES128;



/**
 *  aes192算法
 */
extern NSInteger const OPEN_CIPHER_AES192;



/**
 *  aes256算法
 */
extern NSInteger const OPEN_CIPHER_AES256;


/**
 *  无效算法
 */
extern NSInteger const OPEN_CIPHER_INVALID;

/**
 *  安全凭证加解密模块使用的错误码
 */

/**
 *  seedSecret存储失败
 */
extern NSInteger const OPEN_SAVE_FAILED;



/**
 *  seedSecret覆盖成功
 */
extern NSInteger const OPEN_OVERRIDE_SUCCESS;



/**
 *  seedSecret存储成功
 */
extern NSInteger const OPEN_SAVE_SUCCESS;



/**
 *  删除 seedSecret失败
 */
extern NSInteger const OPEN_REMOVE_FAILED;



/**
 *  删除 seedSecret成功
 */
extern NSInteger const OPEN_REMOVE_SUCCESS;



/**
 *  删除失败，没有此项 
 */
extern NSInteger const OPEN_NO_SUCH_ITEM;