//
//  TEXFunctor.h
//  Texel
//
//  Created by Cloud on 2017/4/27.
//  Copyright © 2017年 Alipay. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <CoreMedia/CoreMedia.h>

#import "TEXOutput.h"
#import "TEXProgram.h"

@interface TEXFunctor : TEXOutput <TEXInput> {
    GLfloat _imageVertices[8];
    GLfloat _textureCoordinates[8];
    GLint _inputTextureCoordinateAttribute;
    GLint _inputImageTextureUniform;
    TEXProgram *_program;
    GLuint _positionAttribte;
}

@property (nonatomic, strong, readonly) NSPointerArray *predecessors;
@property (nonatomic, assign) BOOL enable; // 如果为NO，则直接传到下一个functor，不做任何处理，默认为YES

- (instancetype)initWithVertexShaderString:(NSString *)vertexShaderString fragmentShaderString:(NSString *)fragmentShaderString;
- (void)renderFrameBuffer:(TEXFramebuffer *)framebuffer;

// for subclass
- (void)initFrameBuffer:(TEXFramebuffer *)framebuffer;
- (void)initProgramInContext;
- (void)initAttributes;
- (void)updateExtraBindings;
- (void)updateImageVertices;
- (void)updateTextureCoordinates;

@end
