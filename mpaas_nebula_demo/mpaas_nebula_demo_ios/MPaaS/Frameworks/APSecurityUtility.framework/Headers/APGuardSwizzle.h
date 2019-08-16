//
//  APGuardSwizzle.h
//  APSecurityUtility
//
//  Created by NianXi on 14-9-26.
//  Copyright (c) 2014年 Alipay. All rights reserved.
//

#import <objc/runtime.h>

#define APSetNSErrorFor(FUNC, ERROR_VAR, FORMAT,...)	\
if (ERROR_VAR) {	\
NSString *errStr = [NSString stringWithFormat:@"%s: " FORMAT,FUNC,##__VA_ARGS__]; \
*ERROR_VAR = [NSError errorWithDomain:@"NSCocoaErrorDomain" \
code:-1	\
userInfo:[NSDictionary dictionaryWithObject:errStr forKey:NSLocalizedDescriptionKey]]; \
}
#define APSetNSError(ERROR_VAR, FORMAT,...) APSetNSErrorFor(__func__, ERROR_VAR, FORMAT, ##__VA_ARGS__)

BOOL APSwizzleClassMethod(Class cls,
                          SEL originalSelector,
                          SEL overrideSelector,
                          NSError **error);

BOOL APSwizzleInstanceMethod(Class cls,
                             SEL originalSelector,
                             SEL overrideSelector,
                             NSError **error);
