#import "AUUILoadDefine.h"//程序自动生成
#ifdef ANTUI_UI_Tableview_AUAssitLableView//程序自动生成
//
//  AUAssitLableView.h
//  AntUI
//
//  Created by niki on 17/2/15.
//  Copyright © 2017年 Alipay. All rights reserved.
//

#import "TTTAttributedLabel.h"

// 一般可用于 tableview 的header 或者 footerview

typedef NS_ENUM(NSInteger, AUAssitLableViewType) {
    AUAssitLableViewTypeHeader,            // 头部，默认是头部
    AUAssitLableViewTypeFooter,            // 尾部
    AUAssitLableViewTypeHeaderStyle168,     // 头部， 32px+TextLabel+16px;
    AUAssitLableViewTypeHeaderStyle248,     // 头部， 48px+TextLabel+16px;
    AUAssitLableViewTypeStyle824      //间距,   16px+TextLabel+48px;
};


@interface AUAssitLableView : UIView
{
    AUAssitLableViewType _type;
}
@property (nonatomic, strong) UILabel *describeLabel; // 默认自动换行，行数不限
@property (nonatomic, strong) TTTAttributedLabel *tttLabel; // 富文本形式

// 实例化控件，同时设置 type 及文案内容
- (instancetype)initWithViewType:(AUAssitLableViewType)type
                    describeText:(NSString *)describeText;

// 获取当前view的高度
- (CGFloat)viewHeight __deprecated_msg("已经废弃，请勿直接使用");

/* 内容允许换行
 type: 类型
 text: 文案
 width: 当前 AUAssitLableView 的实例的宽度
 */
+ (CGFloat)viewHeightForType:(AUAssitLableViewType)type
                        text:(NSString *)text
                  totalWidth:(CGFloat)totalWidth;

// 单行的默认高度
+ (CGFloat)viewHeight;

@end

// 富文本样式
@interface AUAssitLableView (TTTLabelStyle)

- (instancetype)initWithViewType:(AUAssitLableViewType)type
                         tttText:(NSString *)tttText
                        linkText:(NSString *)linkText;

@end

#endif//程序自动生成
