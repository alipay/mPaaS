#import "AUUILoadDefine.h"//程序自动生成
#ifdef ANTUI_UI_bladeView_AUBladeView//程序自动生成
//
//  indexBar.h
//
//  Created by Craig Merchant on 07/04/2011.
//  Copyright 2011 RaptorApps. All rights reserved.
//

#import <Foundation/Foundation.h>


//#########################################################
//文档地址 : https://yuque.antfin-inc.com/antui/auidoc/ios_aubladeview
//#########################################################


#define UI_AUBladeView



@protocol AUBladeViewDelegate;
/*！
 @class       AUBladeView
 @abstract    UIView
 @discussion  字母索引的View
 */
@interface AUBladeView : UIView

- (id)init;
- (id)initWithFrame:(CGRect)frame;
- (void)clearIndex;

@property (nonatomic, weak) id<AUBladeViewDelegate> delegate;
@property (nonatomic, strong) UIColor *highlightedBackgroundColor;
@property (nonatomic, strong) UIColor *textColor;
@property (nonatomic, strong) UIFont *textFont;
@property (nonatomic, strong) NSArray * iconImageNames;
@property (nonatomic, strong) NSArray * iconTitles;
@property (nonatomic, assign) BOOL enableSearch;
@property (nonatomic, strong) NSArray * defaultIndexes;


- (void)updateIndexes;

@end

@protocol AUBladeViewDelegate<NSObject>
@optional
- (void)indexSelectionDidChange:(AUBladeView *)indexBar index:(NSInteger)index title:(NSString*)title;
@end

#endif//程序自动生成
