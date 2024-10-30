//
//  UITableViewCell+MP_Create.m
//  mPaas_Poc_Demo
//
//  Created by wyy on 2021/7/5.
//

#import "UITableViewCell+MP_Create.h"

@implementation UITableViewCell (MP_Create)

+ (instancetype)createCellWithTableView:(UITableView *)tableView
{
    NSString *className = NSStringFromClass([self class]);
    UITableViewCell *cell = [tableView dequeueReusableCellWithIdentifier:className];
    if (cell == nil) {
        cell = [[self alloc] initWithStyle:UITableViewCellStyleDefault reuseIdentifier:className];
        cell.selectionStyle = UITableViewCellSelectionStyleNone;
    }
    return cell;
}

@end
