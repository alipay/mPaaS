
#import <Foundation/Foundation.h>

@protocol IOpenStaticKeyEncryptComponent <NSObject>

/**
 *  存储安全凭证到本地存储
 *
 *  @param key 数据对应的Key
 *
 *  @param value 要存储的安全凭证
 *
 *  @return 保存状态  1，保存成功 2，覆盖保存 0，保存失败
 */
- (int) saveSecret: (NSString*) key value: (NSData*) value;



/**
 *  key对应的安全凭证是否存在
 *
 *  @param key 安全凭证对应的key
 *
 *  @return 存在状态 true，存在。false，不存在
 */
- (BOOL) isSecretExist: (NSString*) key;



/**
 *  删除安全凭证项
 *
 *  @param key 数据对应的key
 *
 *  @return 删除结果状态码 1,没有需要被删除的项 2，删除成功 0，删除失败
 */
- (int) removeSecret: (NSString*) key;



/**
 *  加密秘钥数据
 *
 *  @param mode 加密算法
 *
 *  @param key 加密使用的key
 *
 *  @param data 需要加密的数据
 *
 *  @return 加密结果数组
 */
- (NSData*) encrypt: (NSInteger) mode key: (NSString*) key data: (NSData*) data;



/**
 *  解密秘钥数据
 *
 *  @param mode 解密算法
 *
 *  @param key 解密使用的key
 *
 *  @param data 需要解密的数据
 *
 *  @return 解密结果数组
 */
- (NSData*) decrypt: (NSInteger) mode key: (NSString*) key data: (NSData*) data;



/**
 *  使用key获取对应的value，再作为key，加密dataKey对应的value
 *
 *  @param mode 加密算法
 *
 *  @param key 保存到NSUserdefault里面的key-value对的key值
 *
 *  @param dataKey 保存到NSUserdefault里面的key-value对的key值
 *
 *  @return 加密结果byte数组
 */
- (NSData*) encryptSecretData: (NSInteger) mode key: (NSString*) key dataKey: (NSString*) dataKey;

@end
