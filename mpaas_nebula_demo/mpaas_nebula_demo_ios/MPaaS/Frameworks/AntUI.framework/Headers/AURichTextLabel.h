#import "AUUILoadDefine.h"//程序自动生成
#ifdef ANTUI_UI_Label_AURichTextLabel//程序自动生成
//
//  AURichTextLabel.h
//
//
/**
 * Copyright (c) 2010 Muh Hon Cheng
 * Created by honcheng on 1/6/11.
 *
 * Permission is hereby granted, free of charge, to any person obtaining
 * a copy of this software and associated documentation files (the
 * "Software"), to deal in the Software without restriction, including
 * without limitation the rights to use, copy, modify, merge, publish,
 * distribute, sublicense, and/or sell copies of the Software, and to
 * permit persons to whom the Software is furnished to do so, subject
 * to the following conditions:
 *
 * The above copyright notice and this permission notice shall be
 * included in all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT
 * WARRANTY OF ANY KIND, EXPRESS OR IMPLIED,
 * INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR
 * PURPOSE AND NONINFRINGEMENT. IN NO EVENT
 * SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE
 * LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT,
 * TORT OR OTHERWISE, ARISING FROM, OUT OF OR
 * IN CONNECTION WITH THE SOFTWARE OR
 * THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 *
 * @author 		Muh Hon Cheng <honcheng@gmail.com>
 * @copyright	2011	Muh Hon Cheng
 * @version
 *
 */

#import <UIKit/UIKit.h>
#import <CoreText/CoreText.h>

#define UI_AURichTextLabel

typedef enum
{
	RTTextAlignmentRight = kCTRightTextAlignment,
	RTTextAlignmentLeft = kCTLeftTextAlignment,
	RTTextAlignmentCenter = kCTCenterTextAlignment,
	RTTextAlignmentJustify = kCTJustifiedTextAlignment
} RTTextAlignment;

typedef enum
{
	RTTextLineBreakModeWordWrapping = kCTLineBreakByWordWrapping,
	RTTextLineBreakModeCharWrapping = kCTLineBreakByCharWrapping,
	RTTextLineBreakModeClip = kCTLineBreakByClipping,
}RTTextLineBreakMode;

@protocol AURichTextLabelDelegate <NSObject>

@optional
- (void)rtLabel:(id)rtLabel didSelectLinkWithURL:(NSURL*)url;   // 这个是URL对象
- (void)rtLabel:(id)rtLabel didSelectLink:(NSString *)link;     // 这个是string对象
@end

@interface AURichTextLabelComponent : NSObject
@property (nonatomic, assign) int componentIndex;
@property (nonatomic, copy) NSString *text;
@property (nonatomic, copy) NSString *tagLabel;
@property (nonatomic, strong) NSMutableDictionary *attributes;
@property (nonatomic, assign) int position;

- (id)initWithString:(NSString*)aText tag:(NSString*)aTagLabel attributes:(NSMutableDictionary*)theAttributes;
+ (id)componentWithString:(NSString*)aText tag:(NSString*)aTagLabel attributes:(NSMutableDictionary*)theAttributes;
- (id)initWithTag:(NSString*)aTagLabel position:(int)_position attributes:(NSMutableDictionary*)_attributes;
+ (id)componentWithTag:(NSString*)aTagLabel position:(int)aPosition attributes:(NSMutableDictionary*)theAttributes;

@end

@interface AURichTextLabelExtractedComponent : NSObject
@property (nonatomic, strong) NSMutableArray *textComponents;
@property (nonatomic, copy) NSString *plainText;
+ (AURichTextLabelExtractedComponent*)rtLabelExtractComponentsWithTextComponent:(NSMutableArray*)textComponents plainText:(NSString*)plainText;
@end

@interface AURichTextLabel : UIView
@property (nonatomic, copy) NSString *text, *plainText, *highlightedText;
@property (nonatomic, strong) UIColor *textColor;
@property (nonatomic, strong) UIFont *font;
@property (nonatomic, strong) NSDictionary *linkAttributes;
@property (nonatomic, strong) NSDictionary *selectedLinkAttributes;
@property (nonatomic, weak) id<AURichTextLabelDelegate> delegate;
@property (nonatomic, copy) NSString *paragraphReplacement;
@property (nonatomic, strong) NSMutableArray *textComponents, *highlightedTextComponents;
@property (nonatomic, assign) RTTextAlignment textAlignment;
@property (nonatomic, assign) CGSize optimumSize;
@property (nonatomic, assign) RTTextLineBreakMode lineBreakMode;
@property (nonatomic, assign) CGFloat lineSpacing;
@property (nonatomic, assign) int currentSelectedButtonComponentIndex;
@property (nonatomic, assign) CFRange visibleRange;
@property (nonatomic, assign) BOOL highlighted;

// set text
- (void)setText:(NSString*)text;
+ (AURichTextLabelExtractedComponent*)extractTextStyleFromText:(NSString*)data paragraphReplacement:(NSString*)paragraphReplacement;
// get the visible text
- (NSString*)visibleText;

// alternative
// from susieyy http://github.com/susieyy
// The purpose of this code is to cache pre-create the textComponents, is to improve the performance when drawing the text.
// This improvement is effective if the text is long.
- (void)setText:(NSString *)text extractedTextComponent:(AURichTextLabelExtractedComponent*)extractedComponent;
- (void)setHighlightedText:(NSString *)text extractedTextComponent:(AURichTextLabelExtractedComponent*)extractedComponent;
- (void)setText:(NSString *)text extractedTextStyle:(NSDictionary*)extractTextStyle __attribute__((deprecated));
+ (NSDictionary*)preExtractTextStyle:(NSString*)data __attribute__((deprecated));

@end

#endif//程序自动生成
