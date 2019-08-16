#import "AUUILoadDefine.h"//程序自动生成
#ifdef ANTUI_UI_pickerView_AUCascadePicker//程序自动生成
//
//  AUCascadePicker.h
//  AntUI
//
//  Created by 莜阳 on 2017/8/22.
//  Copyright © 2017年 Alipay. All rights reserved.
//

#import "AUPickerBaseView.h"


//#########################################################
//文档地址 : https://yuque.antfin-inc.com/antui/auidoc/ios_aucascadepicker
//#########################################################


@class AUCascadePicker;
@class AUCascadePickerSelectedRowItem;

@protocol AUCascadePickerDelegate <AUPickerBaseViewDelegate>

/*
 * 点取消息时回调
 */
//- (void)cancelPickerView:(AUCascadePicker *)pickerView;
//
//- (void)selectedPickerView:(AUCascadePicker *)pickerView;

@end

// 设置选择器的选中项
@interface AUCascadePickerSelectedRowItem : NSObject

@property (nonatomic, strong) NSString *selectedLeftTitle;      // 当前第一子列表选中的title
@property (nonatomic, strong) NSString *selectedMiddleTitle;   // 当前第二子列表选中的title
@property (nonatomic, strong) NSString *selectedRightTitle;   //  当前第三子列表选中的title

@end

@interface  AUCascadePickerRowItemModel : NSObject

@property (nonatomic, strong) NSString *rowTitle;
@property (nonatomic, strong) NSArray<AUCascadePickerRowItemModel *> *rowSubList;

@end

// 联动效果所需要的数据模型
@interface AUCascadePickerModel : NSObject

@property (nonatomic,strong) AUCascadePickerSelectedRowItem            *preSelected; // 业务方传进来的选中项
@property (nonatomic, strong) AUCascadePickerSelectedRowItem           *selectedItem;     // 当前组件内自行记录的选中数据列表
@property (nonatomic, strong) NSArray<AUCascadePickerRowItemModel *>   *dataList ;        // 数据列表
@property (nonatomic, strong) NSString *title;          // 选择器标题

@end


@interface AUCascadePicker : AUPickerBaseView <UIPickerViewDataSource, UIPickerViewDelegate>

@property (nonatomic, strong) AUCascadePickerModel *dataModel;
@property (nonatomic, assign) NSInteger numberOfComponents;
@property (nonatomic, weak) id <AUCascadePickerDelegate> linkageDelegate;
@property (nonatomic, assign) CGFloat miniScale; // 每列中的字体是否自适应缩小

- (instancetype)initWithPickerModel:(AUCascadePickerModel *)model;

@end


@interface AUCascadePicker (dataFormat)

+ (NSArray<AUCascadePickerRowItemModel *> *)changeParamsToDataModel:(NSArray *)datas;

+ (void)handleModelData:(NSArray<AUCascadePickerRowItemModel *> *)datas selectedItem:(AUCascadePickerSelectedRowItem *)item level:(NSInteger)level;

+ (void)handleData:(NSArray *)datas selectedItem:(AUCascadePickerSelectedRowItem *)item level:(NSInteger)level;

+ (NSArray *)changeSelectedRowInComponentToArray:(AUCascadePicker *)pickerView;

@end

#endif//程序自动生成
