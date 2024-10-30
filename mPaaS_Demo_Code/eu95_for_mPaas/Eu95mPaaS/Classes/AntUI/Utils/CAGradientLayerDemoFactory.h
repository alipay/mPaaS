//
//  AUCAGradientLayer.h
//  AntUI
//
//  Created by 莜阳 on 2017/8/23.
//  Copyright © 2017年 Alipay. All rights reserved.
//


@interface AUCAGradientLayer : CAGradientLayer

@end


@interface CAGradientLayerDemoFactory : NSObject

+ (AUCAGradientLayer *)createDemoDefaultLayer:(UINavigationBar *)navigationBar;

+ (void)removeCurrentNaviLayer:(UINavigationBar *)navigationBar;

@end
