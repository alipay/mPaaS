//
// OpenSecurityGuardSDK version 2.1.0
//

#ifndef OpenSecurityGuardSDK_IOpenInitializeComponent_h
#define OpenSecurityGuardSDK_IOpenInitializeComponent_h



/**
 *  初始化component protocal
 */
@protocol IOpenInitializeComponent <NSObject>



/**
 *  初始化接口
 *
 *  @return 初始化结果
 */
- (NSInteger) initialize;

/**
 *  初始化接口
 *
 *  @return 初始化结果
 */
- (NSInteger) initialize: (void *)authCode;


@end



#endif
