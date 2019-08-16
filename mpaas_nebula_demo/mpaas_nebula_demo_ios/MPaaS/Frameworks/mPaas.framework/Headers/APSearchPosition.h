//
//  APContactSearchPosition.h
//  APContact
//
//  Created by 逆仞 on 14-3-19.
//  Copyright (c) 2014年 Alipay. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface APSearchPosition : NSObject

/**
 @brief 名称匹配开始的位置
 */
@property (nonatomic, assign) int matchStart;
/**
 @brief 名称匹配结束的位置
 */
@property (nonatomic, assign) int matchEnd;
/**
 @brief 是否是全拼匹配
 */
@property (nonatomic, assign) BOOL matchAllInPy;
/**
 @brief 是否是所有word匹配
 */
@property (nonatomic, assign) BOOL matchAllInWord;
/**
 @brief 搜索数据对应IndexPath 如果是字典，对应section:key的位置 row:数据在value的位置   如果是数组，对应section:0, row:数组中的位置
 */
@property (nonatomic, retain) NSIndexPath * indexPath;


/**
 @brief 搜索对应的ID
 */
@property (nonatomic, assign) int searchID;

@end
