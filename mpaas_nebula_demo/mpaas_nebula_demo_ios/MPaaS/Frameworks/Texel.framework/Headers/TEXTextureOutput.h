//
//  TEXTextureOutput.h
//  Texel
//
//  Created by Cloud on 2017/5/22.
//  Copyright © 2017年 Alipay. All rights reserved.
//

#import "TEXFunctor.h"

@interface TEXTextureOutput : NSObject <TEXInput>
// 如果没有设置的话，就直接在当前线程里面处理，不自己创建
@property (nonatomic, strong) TEXContext *context;
@property (nonatomic, assign) BOOL noFlip;
- (instancetype)initWithSize:(CGSize)size dstTexture:(GLuint)dstTexture;


// 复用处理链路时修改size和目标纹理
- (void)updateSize:(CGSize)size dstTexture:(GLuint)dstTexture;
@end
