
//  SearchCoreManager.h
//  APContact
//
//  Created by 逆仞 on 14-3-22.
//  Copyright (c) 2014年 Alipay. All rights reserved.


// CLASS DECLARATION


#define KSeparateWord '/'
#define KStringNull @""

@protocol APSearchDataProtocol <NSObject>
@required
- (NSString *)primarySearchData;    //搜索主字段
@optional
- (NSString *)secondarySearchData;  //搜索副字段
@end

/**
 @brief 搜索字符串的回调
 @param searchText: 搜索串
 @param primaryMatchArrayWithPosition: 主字段匹配出来的数据，数组中的对象是APSearchPosition
 @param secondaryMatchArray: 副字段的匹配出来的数据，数组中的对象是NSIndexPath
 @param error:预留字段
 */
typedef void (^APSearchCallback) (NSString * searchText, NSMutableArray * primaryMatchArrayWithPosition, NSMutableArray * secondaryMatchArray ,NSError * error);

@interface APSearchManager :NSObject

@property (nonatomic , retain) NSString * separateWord;
@property (nonatomic , retain) NSString * matchFunction;

/**
 @brief 获取字符串的拼音串
 @param text: 输入的字符串
 @return 返回拼音串(Ex:逆仞-NiRen)
 */
+ (NSString *)getPinYinWithText:(NSString *)text;

/**
 @brief 建立搜索索引
 @param dict: 实现协议的数据  (Ex: {A:[contact1,contact2,contact3], B:[contact4,contact5]})
 @param indexChar: 数据Dictionary的有序keys Ex:[A,B]
 */
- (void)buildSearchIndexWithDataDict:(NSDictionary *)dict indexChar:(NSArray *)indexChar;

/**
 @brief 建立搜索索引
 @param array: 数据Array
 */
- (void)buildSearchIndexWithDataArray:(NSArray *)array;

/**
 @brief 重置搜索索引
 */
- (void)resetSearchTree;

/**
 @brief 搜索数据,优先主字段，主字段拼音匹配，主字段、副字段匹配数据不重复
 @param searchText: 搜索串
 @param owner: 调用的owner, 为取消使用
 @param callBack: 搜索结果的回调
 */
- (void)search:(NSString*)searchText owner:(id)owner completionBlock:(APSearchCallback)callback;

/**
 @brief 取消响应搜索操作
 @param owner: 搜索方法调用者
 */
- (void)cancelSearchForOwner:(id)owner;

@end
