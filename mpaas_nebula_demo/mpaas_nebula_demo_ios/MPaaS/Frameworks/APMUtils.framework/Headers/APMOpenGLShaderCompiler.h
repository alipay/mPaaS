//
//  OpenGLShaderCompiler.h
//  APMultimedia
//
//  Created by Cloud on 16/6/24.
//  Copyright © 2016年 Alipay. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <OpenGLES/ES2/gl.h>

extern NSString *const kAPMVertexShaderString;
extern NSString *const kAPMPassthroughFragmentShaderString;

extern const char *kAPMShaderPositionName;
extern const char *kAPMShaderInputTextureCoordinateName;
extern const char *kAPMShaderInputImageTextureName;

@interface APMOpenGLShaderCompiler : NSObject

+ (BOOL)compileShader:(GLuint *)shader
                 type:(GLenum)type
               string:(NSString *)shaderString;

@end
