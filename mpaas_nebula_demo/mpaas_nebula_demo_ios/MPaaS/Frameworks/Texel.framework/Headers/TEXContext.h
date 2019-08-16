//
//  TEXContext.h
//  Texel
//
//  Created by Cloud on 2017/4/30.
//  Copyright © 2017年 Alipay. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <OpenGLES/EAGL.h>
#import <OpenGLES/ES2/gl.h>
#import <OpenGLES/ES2/glext.h>
#import <CoreVideo/CoreVideo.h>

#import "TEXSingleThread.h"

#define STRINGIZE(x) #x
#define STRINGIZE2(x) STRINGIZE(x)
#define SHADER_STRING(text) @ STRINGIZE2(text)

extern NSString *const kTEXVertexShaderString;

@interface TEXContext : NSObject

@property (nonatomic, strong) EAGLContext *context;
@property (nonatomic, strong) EAGLSharegroup *sharegroup;
@property (nonatomic, strong, readonly) TEXSingleThread *contextThread;
@property (nonatomic, assign, readonly) CVOpenGLESTextureCacheRef textureCache;

+ (instancetype)sharedContext;

- (instancetype)initWithName:(NSString *)name;
- (void)useSharegroup:(EAGLSharegroup *)sharegroup; // 在调用context之前设置
- (void)use;
+ (CGSize)sizeThatFitsWithinATextureForSize:(CGSize)inputSize;
+ (float)scale;

@end
