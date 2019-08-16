//
//  DatePickerPopView.h
//  BeeLocationPicker
//
//  Created by 莜阳 on 16/7/25.
//  Copyright © 2016年 Alipay. All rights reserved.
//

#import "AUDatePicker.h"

@protocol AUOptionPickerDataProtocol <NSObject>

@required
- (NSString *)name;

@end

@interface AUOptionPickerDataModel : NSObject <AUOptionPickerDataProtocol>

@property(nonatomic,copy) NSString* name;

@end

@interface AUOptionPickerColumnModel : NSObject

@property(nonatomic,assign) NSUInteger selectedIndex;
@property (nonatomic, strong) NSArray<id<AUOptionPickerDataProtocol>> *pickerDataArray;

@end

//点击完成按钮回调
@protocol AUOptionPickerDelegate <NSObject>

/*
根据datas数组顺序，返回简单的选中信息

array:(
       {
           //datas[0],
           //[key:"name" value:NSString],[key:"selectedIndex",value:NSValue]
           name = "one_7";
           selectedIndex = 7;
       },
       {
           //datas[1]
           name = "two_5";
           selectedIndex = 5;
       },
       {
           //datas[2]
           name = "three_0";
           selectedIndex = 0;
       }
    )
*/
- (void)pickerConfirmSelectedInfo:(NSArray *) selectedInfo;

//返回完整datas，AUOptionPickerColumnModel.selectedIndex会根据选择变化
- (void)pickerConfirmDatas:(NSArray<AUOptionPickerColumnModel *> *) datas;

@end

@interface AUOptionPicker : UIView <AUDatePickerDelegate, UIPickerViewDataSource, UIPickerViewDelegate>

@property (nonatomic, strong) AUDatePicker *datePickerView;
@property (nonatomic, weak) id<AUOptionPickerDelegate> delegate;

- (instancetype)initWithDatas:(NSArray<AUOptionPickerColumnModel *> *) datas
                        title:(NSString *) title;

/*
默认button文案为：完成，取消
需要自定义button文案可使用此接口，其余使用上面接口初始化即可
 */
- (instancetype)initWithDatas:(NSArray<AUOptionPickerColumnModel *> *) datas
                        title:(NSString *) title
                finishBtnText:(NSString *) finishBtnText
                cancelBtnText:(NSString *) cancelBtnText;

- (void)showDatePicker;
- (void)hideDatePicker;

@end
