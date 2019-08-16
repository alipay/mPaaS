//
//  APTableViewDataSource.h
//  APCommonUI
//
//  Created by WenBi on 13-12-4.
//  Copyright (c) 2013年 WenBi. All rights reserved.
//

@class APTableSection;
@class APTableRow;


@protocol APTableSection <NSObject>

- (UITableViewHeaderFooterView *)viewForHeaderInTableView:(UITableView *)tableView;
- (UITableViewHeaderFooterView *)viewForFooterInTableView:(UITableView *)tableView;

- (CGFloat)heightForHeaderInTableView:(UITableView *)tableView inSection:(NSInteger)section;
- (CGFloat)heightForFooterInTableView:(UITableView *)tableView inSection:(NSInteger)section;

@end


@protocol APTableViewDataSource <NSObject>

/**
 * A convenient utility method for retrieving the row at specified index path.
 *
 * @param indexPath An index path locating a row in data source.
 * @return The row at specified index path.
 */
- (id)rowAtIndexPath:(NSIndexPath *)indexPath;

- (NSArray *)allSections;

@end
