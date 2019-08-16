//
//  H5Configs+convenience.h
//  NebulaBiz
//
//  Created by Glance on 2018/3/7.
//  Copyright © 2018年 Alipay. All rights reserved.
//

#import <Nebula/Nebula.h>

/*　方法声明移至H5Configs.h对外部暴露
BOOL          H5ConfigServiceBool(NSString *key);    // BOOLEAN类型开关
NSInteger     H5ConfigServiceInteger(NSString *key); // 整型类型开关
double        H5ConfigServiceDouble(NSString *key);  // 浮点类型开关
NSString     *H5ConfigServiceString(NSString *key);  // 字符串类型开关
NSArray      *H5ConfigServiceArray(NSString *key);   // 数组类型开关
NSDictionary *H5ConfigServiceDict(NSString *key);    // 字典类型开关
*/
/**
 使用方法：
 在initConfigServiceConvenience方法实现中，追加要添加的开关名称和开关属性
 */
@interface H5Configs(convenience)

- (void)initConfigServiceConvenience;

@end
