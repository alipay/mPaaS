//
//  TEXProgram.h
//  CameraPreview
//
//  Created by Cloud on 2017/4/19.
//  Copyright © 2017年 aspling. All rights reserved.
//

#import <Foundation/Foundation.h>

#import <OpenGLES/ES2/gl.h>
#import <OpenGLES/ES2/glext.h>

@interface TEXProgram : NSObject

- (instancetype)initWithVertexShaderString:(NSString *)vertexShaderString
                      fragmentShaderString:(NSString *)fragmentShaderString;

- (void)use;
- (void)link;

- (void)addAttribute:(NSString *)attribute;
- (GLuint)getAttribute:(NSString *)attribute;
- (GLuint)getUniform:(NSString *)uniform;

@end
