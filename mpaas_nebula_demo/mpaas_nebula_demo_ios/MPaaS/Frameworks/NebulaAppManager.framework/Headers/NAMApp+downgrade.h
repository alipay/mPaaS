//
//  NAMApp+downgrade.h
//  NebulaAppManager
//
//  Created by nico on 2018/11/30.
//  Copyright © 2018 Alipay. All rights reserved.
//

#import <NebulaAppManager/NebulaAppManager.h>

NS_ASSUME_NONNULL_BEGIN

@interface NAMApp (downgrade)
-(NSDictionary *)appDowngradeSceneParams;
@end

NS_ASSUME_NONNULL_END
