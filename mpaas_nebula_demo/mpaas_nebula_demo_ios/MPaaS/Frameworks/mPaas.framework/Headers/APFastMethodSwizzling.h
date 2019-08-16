//
//  APFastMethodSwizzling.h
//  APMobileFoundation
//
//  Created by myy on 2017/4/21.
//  Copyright © 2017年 Alipay. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <objc/runtime.h>


#ifdef __cplusplus
extern "C" {
#endif // __cplusplus

    
/**
 * instance使用method_exchangeImplementations的替代方法，更快！
 * 参考：https://www.atatech.org/articles/56564
 *
 * 注意：只能替换instance方法，不能替换class方法！！！
 */
BOOL instanceMethod_fastExchangeImplementations(Class origCls, SEL origSEL, Class newCls, SEL newSEL);



#ifdef __cplusplus
}
#endif // __cplusplus

