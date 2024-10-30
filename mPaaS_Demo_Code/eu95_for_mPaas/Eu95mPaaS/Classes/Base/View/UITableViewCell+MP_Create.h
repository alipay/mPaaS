//
//  UITableViewCell+MP_Create.h
//  mPaas_Poc_Demo
//
//  Created by wyy on 2021/7/5.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@interface UITableViewCell (MP_Create)

+ (instancetype)createCellWithTableView:(UITableView *)tableView;

@end

NS_ASSUME_NONNULL_END
