#import "AUUILoadDefine.h"//程序自动生成
#ifdef ANTUI_UI_textfields_AUParagraphInputBox//程序自动生成
//
//  AUParagraphInputBox.h
//  AntUI
//
//  Created by niki on 17/4/17.
//  Copyright © 2017年 Alipay. All rights reserved.
//



//#########################################################
//文档地址 : https://yuque.antfin-inc.com/antui/auidoc/ios_auparagraphinputbox
//#########################################################


#define UI_AUParagraphInputBox


// 段落输入框

 /* 补充说明
  if 设置了 maxInputLen
  {
      if 没有实现 delegate(textView:shouldChangeTextInRange:replacementText:))
      {
          // 则控件在该 delegate 中判断输入字数是否超过 maxInputLen，
               超过则将 textView.text 进行截断同时返回 NO , 否则返回 YES; (中文按一个字符计算)
      }
      else
      {
         // 执行业务逻辑
      }
  }
  */

@interface AUParagraphInputBox : UIView 

@property (nonatomic, strong) UITextView *textView;      // 输入框
@property (nonatomic, assign) NSInteger maxInputLen;    // 设置最大输入字数
@property (nonatomic, strong) UIView *topSplitLine;    // 顶部分隔线
@property (nonatomic, strong) UIView *bottomSplitLine;    // 底部分隔线
@property (nonatomic, strong) UILabel *inputLenLabel;  //底部字数统计器

// 初始化
- (instancetype)initWithFrame:(CGRect)frame placeHolder:(NSString *)placeHolder;

// 设置 placeHolder 文本
- (void)setPlaceHolder:(NSString *)placeHolder;

// 限制最大输入字数
+ (BOOL)textView:(UITextView *)textView
shouldChangeRange:(NSRange)range
replacementString:(NSString *)string
       maxLength:(int)maxLength;

@end


#endif//程序自动生成
