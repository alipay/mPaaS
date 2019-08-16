//
// OpenSecurityGuardSDK version 2.1.0
//

#import <Foundation/Foundation.h>

@protocol IOpenDataCollectionComponent <NSObject>

/**
 *  设置用户昵称
 *  @param nick, 用户昵称
 *  @return YES, 设置后值发生改变, NO, 设置失败或值未发生改变
 */
- (BOOL) setNick:(NSString*) nick;


/**
 *  获取用户昵称
 *
 *  @return 用户昵称，获取失败返回nil
 */
- (NSString*) getNick;

@end
