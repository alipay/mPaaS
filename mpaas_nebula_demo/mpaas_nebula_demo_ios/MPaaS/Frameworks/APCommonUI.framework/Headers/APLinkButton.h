//
//  APLinkButton.h
//  APCommonUI
//
//  Created by WenBi on 14-1-20.
//  Copyright (c) 2014年 WenBi. All rights reserved.
//

#import <Foundation/Foundation.h>

/**
 *  超链接风格的按钮。
 */
@interface APLinkButton : UIControl

/** A view that displays the title of the link button. */
@property(nonatomic, readonly) UILabel *titleLabel;

/** The title of the link button. */
@property(nonatomic, strong) NSString *title;

/** A boolean value indicates whether display a line under link-button's title. */
@property(nonatomic, assign) BOOL underline;

/**
 *  Sets the title's color used for the specified state.
 *
 *  @param color The color to use for specified state.
 *  @param state The control state that uses the specified color.
 */
- (void)setTitleColor:(UIColor *)color forState:(UIControlState)state;

/**
 *  Gets the color used for specified state.
 *
 *  @param state The control state that uses the color.
 *
 *  @return The color used for the specified state.
 */
- (UIColor *)titleColorForState:(UIControlState)state;

@end

