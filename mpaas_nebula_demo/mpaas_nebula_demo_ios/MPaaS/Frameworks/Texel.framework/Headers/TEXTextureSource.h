//
//  TEXSceneSource.h
//  Texel
//
//  Created by Cloud on 2017/4/28.
//  Copyright © 2017年 Alipay. All rights reserved.
//

#import "TEXSource.h"

@interface TEXTextureSource : TEXSource

- (instancetype)initWithSize:(CGSize)size;
- (void)setTexture:(GLuint)texture;

@end
