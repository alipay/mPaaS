//
//  APTextureView.h
//  APMultimedia
//
//  Created by Cloud on 15/9/15.
//  Copyright (c) 2015年 Alipay. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface APMTextureView : UIView

/**
 *  要展示的texture的长和宽
 */
@property (nonatomic, assign) CGSize dimension;

/**
 *  输入纹理方向是否是OpenGL坐标系，默认为YES。如果是图像坐标系中，则会翻转至显示方向
 */
@property (nonatomic, assign, getter=isInputTextureOpenGLCoordinatesSystem) BOOL inputTextureOpenGLCoordinatesSystem;

/**
 *  因为GPU在后台时无法使用，所以此时如果还继续render的话，需要传入NO，禁止render
 *  默认是YES
 */
@property (nonatomic, assign) BOOL renderingEnabled;

/**
 *  渲染纹理到view上
 *
 *  @param texture 需要渲染的纹理
 *  @param context 和纹理绑定的context
 */
- (void)render:(GLuint)texture context:(EAGLContext *)context;

/**
 *  清理opengl，需要与render在同一个线程处理，否则容易出现crash
 */
- (void)reset;

@end
