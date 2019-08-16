//
//  TEXView.h
//  Texel
//
//  Created by Cloud on 2017/5/1.
//  Copyright © 2017年 Alipay. All rights reserved.
//

#import "TEXFunctor.h"
typedef void (^TEXViewCompleteHandler)(BOOL result);  //埋点使用

@interface TEXView : UIView <TEXInput>

@property (nonatomic, strong) TEXViewCompleteHandler completeHandler; //埋点使用

/**
 *  输入纹理方向是否是OpenGL坐标系，默认为YES。如果是图像坐标系中，则会翻转至显示方向
 */
@property (nonatomic, assign, getter=isInputTextureOpenGLCoordinatesSystem) BOOL inputTextureOpenGLCoordinatesSystem;

@end
