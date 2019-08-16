//
//  TEXFramebuffer.h
//  Texel
//
//  Created by Cloud on 2017/4/28.
//  Copyright © 2017年 Alipay. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import <OpenGLES/ES2/gl.h>
#import <OpenGLES/ES2/glext.h>

@interface TEXFramebuffer : NSObject

@property (nonatomic, assign) GLuint texture;
@property (nonatomic, assign) CGSize size;
@property (nonatomic, assign) CGRect roi; // 归一化的感兴趣区域，OpenGL坐标系，左下角原点，默认是全屏

- (instancetype)initWithSize:(CGSize)size;
- (instancetype)initWithSize:(CGSize)size onlyTexture:(BOOL)onlyTexture;
- (instancetype)initWithSize:(CGSize)size texture:(GLuint)texture;
- (void)use;
- (void)generateTexture;

- (BOOL)lock;
- (BOOL)unlock;
- (BOOL)tryLock;

@end
