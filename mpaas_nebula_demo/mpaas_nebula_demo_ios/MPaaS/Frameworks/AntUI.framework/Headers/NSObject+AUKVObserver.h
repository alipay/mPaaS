//
//  AUKVObserver.h
//  AntUI
//
//  Created by 沫竹 on 2018/6/11.
//  Copyright © 2018年 Alipay. All rights reserved.
//

#import <Foundation/Foundation.h>



NS_ASSUME_NONNULL_BEGIN


typedef void(^KVChangeBlock)(NSDictionary<NSKeyValueChangeKey,id> *change);

@interface NSObject (AUKVObserver)

// 开始KVO监听
// 注意：
//      1、多次添加同一个监听，前面添加的会失效
//      2、你不需要主动移除KVO监听，系统会在observer释放后自动移除
- (void)startObserveObject:(NSObject *)object keyPath:(NSString *)keyPath options:(NSKeyValueObservingOptions)options block:(KVChangeBlock)block;

// 移除KVO监听
// 注意：
//      1、除非真的需要在对象dealloc之前移除KVO，才需要调用此方法
//      2、多次移除不会引发crash
- (void)endObserveObject:(NSObject *)object keyPath:(NSString *)keyPath;


// 内部方法，请勿调用
+ (BOOL)isDeallocEndObserveEnaled;

@end


NS_ASSUME_NONNULL_END
