#import "AUUILoadDefine.h"//程序自动生成
#ifdef ANTUI_UI_pickerView_AUImagePicker//程序自动生成
//#import "AUUILoadDefine.h"//程序自动生成
//#ifdef ANTUI_UI_pickerView_AUImagePicker//程序自动生成
//
//  AUImagePicker.h
//  AntUI
//
//  Created by zhaolei on 2017/6/30.
//  Copyright © 2017年 Alipay. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <Foundation/Foundation.h>
#import "UImageView+AUMarker.h"


//#########################################################
//文档地址 : https://yuque.antfin-inc.com/antui/auidoc/ios_auimagepickerskeleton
//#########################################################

NS_ASSUME_NONNULL_BEGIN

@protocol AUImagePickerSkeletonDelegate;

@protocol AUImagePickerDataProtocol <NSObject>

@optional
// 展示动图角标
- (void)fetchMarkerView:(void (^)(UIView *markerView, AUImageViewPostion position)) block;

@required
/**
 同步获取缩略图
 
 */
- (void)fetchThumbImage:(void (^)(UIImage *image)) block;

@end

@interface AUImagePickerSkeleton : UIView


/**
 初始化相册选择组件.最简版本.每行四列,上下间距为0.
 
 概念图:
 口口口田

 @param maxNumberOfImages 可选上限
 @param business 业务key,例如"everywhere"
 @return AUImagePickerSkeleton
 */
- (AUImagePickerSkeleton *)initWithMaxNumberOfImages:(NSUInteger)maxNumberOfImages
                                            business:(NSString *)business;

/**
 带header,上下边距的完整相册选择组件.

 概念图:
 title  3/4
 口 口 口 田
 
 @param maxNumberOfImages 可选上限
 @param business 业务key,例如"everywhere"
 @return AUImagePickerSkeleton
 */
- (AUImagePickerSkeleton *)initWithHeaderTitle:(nullable NSString *)title
                             maxNumberOfImages:(NSUInteger)maxNumberOfImages
                                      business:(NSString *)business;

@property(nonatomic, assign) BOOL canDrag;//是否可以拖拽,默认NO
@property(nonatomic, assign, readonly) NSUInteger maxNumberOfImages;
@property(nonatomic, weak, nullable) id<AUImagePickerSkeletonDelegate> delegate;
@property(nonatomic, strong, readonly, nullable) NSArray<id<AUImagePickerDataProtocol>> *imagePickerDatas;

- (void)updateImagePickerDatas:(NSArray <id<AUImagePickerDataProtocol>>*) datas;

- (void)updateImagePickerDatasAfterDrag:(NSArray<id<AUImagePickerDataProtocol>> *)datas;

- (CGRect)viewRectOnScreenWithIndex:(NSUInteger) index;

- (void)reloadCollectView;

@end

@protocol AUImagePickerSkeletonDelegate <NSObject>

@required
- (void)imagePickerSkeletonAddButtonClick:(AUImagePickerSkeleton *)imagePickerSkeleton;

@optional
- (void)imagePickerSkeletonImageClick:(AUImagePickerSkeleton *)imagePickerSkeleton
                            clickData:(id<AUImagePickerDataProtocol>)clickData;

-(void)imagePickerSkeletonDataChanged;

- (void)imagePickerSkeleton:(AUImagePickerSkeleton *)imagePickerSkeleton
        moveItemAtIndexPath:(NSIndexPath *)sourceIndexPath
                toIndexPath:(NSIndexPath *)destinationIndexPath;

/**
 图片将要开始拖拽
 */
-(void)imagePickerSkeletonWillBeginDragging;

/**
 图片已完成拖拽
 */
-(void)imagePickerSkeletonDidEndDragging;
@end

NS_ASSUME_NONNULL_END

//#endif//程序自动生成

#endif//程序自动生成
