//
//  DTMobileFrameworkClass+MPaaS.h
//  APMPaaS
//
//  Created by qiwei on 29/06/2017.
//  Copyright © 2017 Alipay. All rights reserved.
//

@protocol DTMobileFrameworkClass <NSObject>

@required

/**
 获取当前MicroApp的ID

 @return 可能为nil
 */
+ (NSString*) currentMicroApplicationId;

@end
