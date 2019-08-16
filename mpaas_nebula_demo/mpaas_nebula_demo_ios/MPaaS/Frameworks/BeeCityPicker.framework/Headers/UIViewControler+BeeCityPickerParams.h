//
//  UIViewControler+BeeCityPickerParams.h
//  BeeCityPicker
//
//  Created by 莜阳 on 2017/12/29.
//  Copyright © 2017年 Alipay. All rights reserved.
//

#import <UIKit/UIKit.h>
//#import <NebulaHeader/H5WebViewController.h>
//#import <NebulaHeader/H5Service.h>
#import <AntUI/AntUI.h>

@interface UIViewController (BeeCityPickerParams)

- (NSDictionary *)BeeCityPickerSPMParams;

@end

#define UIScreenWidth()      AUCommonUIGetScreenWidth()


//NS_INLINE CGFloat UIValueAfterScale(CGFloat value)
//{
//    if (AUIsPad()) {
//        return value;
//    }
//    
//    if (AUCommonUIGetScreenHeight() > 480) {
//        CGFloat minFactor = MIN(AUCommonUIGetScreenWidth() / 320, AUCommonUIGetScreenHeight() / 568);
//        return value * minFactor;
//    }
//    return value;
//}
//
//NS_INLINE UIColor *UIColorWithRGB(NSUInteger rgb)
//{
//    return [UIColor colorWithRed:((rgb & 0x00FF0000) >> 16) / 255.0
//                           green:((rgb & 0x0000FF00) >> 8) / 255.0
//                            blue:((rgb & 0x000000FF)) / 255.0
//                           alpha:1.f];
//}
//
//NS_INLINE CGSize SizeWithTextAndFont(NSString *text, UIFont *font)
//{
//    CGRect frame = [UIScreen mainScreen].bounds;
//    CGSize avaliableSize = [text sizeWithFont:font
//                            constrainedToSize:frame.size
//                                lineBreakMode:NSLineBreakByWordWrapping];
//    return avaliableSize;
//}
//
//
//NS_INLINE UIColor *UIColorWithHexString(NSString *hexString)
//{
//    UIColor *retColor = [UIColor blackColor];
//    if (hexString.length > 0) {
//        const char *hexChar;
//        if ([[hexString substringToIndex:1] isEqualToString:@"#"]) {
//            hexChar = [hexString substringFromIndex:1].UTF8String;
//        } else if ([[hexString substringToIndex:2].lowercaseString isEqualToString:@"0x"]) {
//            hexChar = [hexString substringFromIndex:2].UTF8String;
//        } else {
//            hexChar = hexString.UTF8String;
//        }
//        int color = (int) strtol(hexChar, NULL, 16);
//        retColor = UIColorWithRGB(color);
//    }
//    return retColor;
//}
//
//
//NS_INLINE CGFloat UIThinLineHeight()
//{
//    return 1/[UIScreen mainScreen].scale;
//}
//
//NS_INLINE UIView *UILineWithFrame(CGRect frame)
//{
//    frame.size.height = UIThinLineHeight();
//    UIView *line = [[UIView alloc] initWithFrame:frame];
//    line.backgroundColor = [UIColor colorWithRed:0xDD/255.0 green:0xDD/255.0 blue:0xDD/255.0 alpha:1];
//    return line;
//}
//
//NS_INLINE UIView *UIFindSubview(UIView *view, Class viewClass)
//{
//    for (UIView *subview in view.subviews)
//    {
//        if ([subview isKindOfClass:viewClass])
//        {
//            return subview;
//        }
//        else
//        {
//            UIView *ret = UIFindSubview(subview, viewClass);
//            if (ret)
//            {
//                return ret;
//            }
//        }
//    }
//    
//    return nil;
//}
//
////
//NS_INLINE UIView *UIViewWithColor(CGRect frame, UIColor *color)
//{
//    UIView *view = [[UIView alloc] initWithFrame:frame];
//    view.backgroundColor = color;
//    return view;
//}
//
//NS_INLINE BOOL UIOpenUrl(NSString *url)
//{
//    if (url.length == 0) return NO;
//    BOOL ret = [UIApplication.sharedApplication openURL:[NSURL URLWithString:url]];
//    if (ret == NO)
//    {
//        AUNoticeDialog *alertView = [[AUNoticeDialog alloc] initWithTitle:[url hasPrefix:@"tel"] ? NSLocalizedString(@"Could not make call", @"无法拨打电话") : NSLocalizedString(@"Could not open", @"无法打开")
//                                                                  message:url
//                                                                 delegate:nil
//                                                        cancelButtonTitle:NSLocalizedString(@"OK", @"确定")
//                                                        otherButtonTitles:nil];
//        [alertView show];
//    }
//    return ret;
//}
//
//NS_INLINE BOOL BEEOpenUrl(NSString *url)
//{
//    if ([url hasPrefix:@"http"])
//    {
//        H5WebViewController *controller = [H5Service createWebViewController:@{@"url":url} JSApis:nil withDelegate:nil];
//
//        UINavigationController *navigator = [DTContextGet() navigationController];
//        UINavigationController *presentedNavigator;
//        while ((presentedNavigator = navigator.presentedViewController.navigationController))
//        {
//            navigator = presentedNavigator;
//        }
//        [navigator pushViewController:controller animated:YES];
//        return YES;
//    }
//    return UIOpenUrl(url);
//}








