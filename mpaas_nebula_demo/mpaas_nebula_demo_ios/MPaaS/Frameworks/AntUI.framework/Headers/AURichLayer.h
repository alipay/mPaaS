#import "AUUILoadDefine.h"//程序自动生成
#ifdef ANTUI_UI_Label_AURichLayer//程序自动生成
//
//  APRichLayer.h
//  APCommonUI
//
//  支付宝最有钱(Rich) 的 layer
//  Created by 天作 on 14-5-20.
//  Copyright (c) 2014年 Alipay. All rights reserved.
//


#import <QuartzCore/QuartzCore.h>

#define UI_AURichLayer

typedef enum : NSUInteger {
    RichLayerBreakByWordWrapping = 0,
    RichLayerBreakByCharWrapping,
    RichLayerBreakByEllipsising,
} RichLayerBreakMode;


// Rich Layer 文字样式定义
// 定义文字字体大小
#define kRichLayerFontSize     @"font-size"      // NSInteger
// 定义文字是否粗体
#define kRichLayerFontWeight   @"font-weight"
#define kRichLayerFontWeightBold  @"bold"
// 定义文字对齐方式
#define kRichLayerTextAlign    @"text-align"
#define kRichLayerTextAlignLeft   @"left"
#define kRichLayerTextAlignCenter @"center"
#define kRichLayerTextAlignRight  @"right"
// 文字颜色
#define kRichLayerColor        @"color"          // UIColor
// 行高，最后一次设置生效
#define kRichLayerLineHeight   @"line-height"    // NSInteger
// 设置文字附加装饰效果
#define kRichLayerTextDecoration @"text-decoration"
#define kRichLayerTextDecorationLineThrough @"line-through"  // 删除线贯穿文字
#define kRichLayerTextDecorationUnderline   @"underline"     // 在文字下方渲染下划线


@interface AURichLayer : CATextLayer

/**
 * 控制文字渲染自动换行模式，见 RichLayerBreakMode 定义
 */
@property   (nonatomic) RichLayerBreakMode breakMode;

/**
 * 向 RichLayer 添加带样式的文字
 * 
 * @param  string     添加的文字
 * @param  style      文字 css 样式，样式见定义
 */
- (instancetype)appendString:(NSString*)string withStyle:(NSDictionary*)style;

/**
 * 清理当前 append 的所有 string
 */
- (void)clearString;

/**
 * 当前 string 最终渲染尺寸
 */
- (CGSize)boundingSize;

/**
 * 固定宽度后，当前 string 的渲染尺寸
 */
- (CGSize)boundingSizeWithWidth:(CGFloat)widthConstraint;

/**
 * 计算 attributedString 渲染区域大小
 *
 * @param  attributedString
 */
- (CGSize)boundingSizeOfAtrributedString:(NSAttributedString*)attributedString;

/**
 * 根据文字内容自动设置区域大小
 */
- (void)sizeToFits;

@end
#endif//程序自动生成

