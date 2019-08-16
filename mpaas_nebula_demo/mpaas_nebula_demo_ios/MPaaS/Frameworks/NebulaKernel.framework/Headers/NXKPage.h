//
//  NXKScene.h
//  NebulaKernel
//
//  Created by theone on 2018/8/28.
//  Copyright © 2018年 Alipay. All rights reserved.
//

#import <NebulaPoseidon/NebulaPoseidon.h>
#import "NXKNode.h"

@protocol ViewControllerProtocol;

/**
 scene中修改最大的，就是移除ViewController的关联，
 由于暴露的依旧是父类PSDScene, 当使用者（如plugin）使用psdViewController以期获得viewController，
 则由本类覆盖getter方法，传给caller 正确的viewControllelr
 */
@interface NXKPage : PSDScene <NXKNodeProtocol>
@property (nonatomic, strong) PSDSceneParam *sceneParamOverride;
@property(nonatomic, assign)  BOOL isNXKNode;
@property (nonatomic) UIViewController<ViewControllerProtocol> *nxViewController;

@end
