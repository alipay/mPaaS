//
//  H5ActionSheet.h
//  H5Service
//
//  Created by Jason on 4/21/14.
//  Copyright (c) 2014 Alipay. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface H5ActionSheet : NSObject<UIActionSheetDelegate>

@property(nonatomic, assign) BOOL isShow;

- (void)removeActionSheet;

- (void)showActionSheet:(NSDictionary *)data callBack:(PSDJsApiResponseCallbackBlock)callBack view:(UIView *)view;

// 重置指定index下的item
- (void)setActionSheetButton:(NSString *)title atIndex:(NSInteger)index;

@end
