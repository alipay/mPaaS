//
//  bladeViewController.m
//  AntUI
//
//  Created by 祝威 on 16/9/29.
//  Copyright © 2016年 Alipay. All rights reserved.
//

#import "bladeViewController.h"
//#import "AUBladeView.h"

@interface bladeViewController ()<AUBladeViewDelegate,UITableViewDelegate,UITableViewDataSource>
@property (nonatomic,strong)     AUBladeView * bladeView;
@property (nonatomic,strong)    NSArray * sectionArr;
@property (nonatomic,strong)    NSArray * mainDataIndexChar;
@property (nonatomic,strong)    UITableView * tableView;
@end

@implementation bladeViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    self.title = @"城市选择";
    // Do any additional setup after loading the view.
    self.tableView = [[UITableView alloc] initWithFrame:CGRectMake(0, 0, self.view.frame.size.width, self.view.frame.size.height) style:UITableViewStylePlain];
    self.tableView.delegate = self;
    self.tableView.dataSource = self;
    [self.view addSubview:self.tableView];
    self.bladeView = [[AUBladeView alloc] initWithFrame:CGRectMake(self.view.frame.size.width-16.0, 80, 16.0, self.view.bounds.size.height-60)];
    self.bladeView.delegate = self;
    self.bladeView.textColor = [UIColor colorWithRGB:0x108ee9];

   NSString * plistStr = [[NSBundle mainBundle] pathForResource:@"APCommonUI_ForDemo.bundle/citydict" ofType:@"plist"];
    NSDictionary * srcPlistDic = [NSDictionary dictionaryWithContentsOfFile:plistStr];
    NSMutableArray * citysList = [[NSMutableArray alloc] initWithCapacity:27];
    [citysList addObject:@{@"热门城市":@[@"上海",@"杭州",@"广州",@"北京",@"深圳"]}];
  
    NSMutableArray * indexArrList = [[NSMutableArray alloc] initWithCapacity:27];
    [indexArrList addObject:@"热"];
    NSArray * keyList = [srcPlistDic allKeys];
    NSArray * sortedList = [keyList sortedArrayUsingComparator:^NSComparisonResult(id       _Nonnull obj1, id  _Nonnull obj2) {
        return [(NSString *)obj1 compare:obj2];
        
    }];
    [sortedList enumerateObjectsUsingBlock:^(id  _Nonnull obj, NSUInteger idx, BOOL * _Nonnull stop) {
        if (obj) {
            
            NSDictionary * tmpDic = [[NSDictionary alloc] initWithObjectsAndKeys:[srcPlistDic objectForKey:obj],obj, nil];
            [citysList addObject:tmpDic];
            [indexArrList addObject:obj];
        }

    }];
    self.sectionArr = citysList;
    self.mainDataIndexChar = indexArrList;
//    self.bladeView.iconTitles = secondaryIndexsTitles;
//    self.bladeView.iconImageNames = secondaryIndexsIcons;
    self.bladeView.defaultIndexes = self.mainDataIndexChar;
    [self.bladeView updateIndexes];
    [self.view addSubview:self.bladeView];
    self.tableView.showsVerticalScrollIndicator = NO;
    self.tableView.showsHorizontalScrollIndicator = NO ;
    [self.view bringSubviewToFront:self.bladeView];


}


#pragma mark -----UITableViewDelegate
// Display customization
// Variable height support

- (CGFloat)tableView:(UITableView *)tableView heightForRowAtIndexPath:(NSIndexPath *)indexPath
{
    return 44;
}// Use the estimatedHeight methods to quickly calcuate guessed values which will allow for fast load times of the table.

- (CGFloat)tableView:(UITableView *)tableView heightForHeaderInSection:(NSInteger)section
{
    return 35;
}
#pragma mark -----UITableViewDataSource
- (NSInteger)tableView:(UITableView *)tableView numberOfRowsInSection:(NSInteger)section
{
    NSDictionary * test = [self.sectionArr objectAtIndex:section] ;
    NSArray * valueArr = [test objectForKey:([[test allKeys] firstObject])];

    return [valueArr count];

}

- (nullable NSString *)tableView:(UITableView *)tableView titleForHeaderInSection:(NSInteger)section
{
    NSDictionary * test = [self.sectionArr objectAtIndex:section] ;

    return [[test allKeys] firstObject];
}

- (UITableViewCell *)tableView:(UITableView *)tableView cellForRowAtIndexPath:(NSIndexPath *)indexPath
{
    UITableViewCell *cell = [tableView dequeueReusableCellWithIdentifier:@"BladeTableViewCell"];
    if (!cell) {
        cell = [[UITableViewCell alloc] initWithStyle:UITableViewCellStyleDefault reuseIdentifier:@"BladeTableViewCell"];
    }
    NSInteger section = [indexPath section];
    NSInteger row = [indexPath row];
    NSDictionary * test = [self.sectionArr objectAtIndex:section] ;
    NSArray * valueArr = [test objectForKey:([[test allKeys] firstObject])];
    NSString * text = [valueArr objectAtIndex:row];
    cell.textLabel.text =text ;
    return cell;
 
}
- (NSInteger)numberOfSectionsInTableView:(UITableView *)tableView
{
    return [self.sectionArr count];
}// Default is 1 if not implemented

- (void)dealloc
{
    self.tableView.delegate = nil;
    self.tableView.dataSource = nil;
    self.bladeView.delegate = nil;
    self.bladeView = nil;

}
- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

/*
#pragma mark - Navigation

// In a storyboard-based application, you will often want to do a little preparation before navigation
- (void)prepareForSegue:(UIStoryboardSegue *)segue sender:(id)sender {
    // Get the new view controller using [segue destinationViewController].
    // Pass the selected object to the new view controller.
}
*/

#pragma mark ---- AUBladeViewDelegate
- (void)indexSelectionDidChange:(AUBladeView *)indexBar index:(NSInteger)index title:(NSString*)title
{
    if (self.tableView){
        NSInteger ret = 0;
        if ([title isEqualToString:kIndexSearchTitle]){
            [self.tableView scrollToRowAtIndexPath:[NSIndexPath indexPathForRow:0 inSection:ret]
                                  atScrollPosition:UITableViewScrollPositionBottom
                                          animated:NO];
            return;
        }
        else {
            ret = [self findIndexSection:title];
            if (ret != NSNotFound) {
                [self.tableView scrollToRowAtIndexPath:[NSIndexPath indexPathForRow:0 inSection:ret]
                                      atScrollPosition:UITableViewScrollPositionTop
                                              animated:NO];
            }
        }
    }
    
}

- (NSInteger)findIndexSection:(NSString *)title {
    NSInteger ret = NSNotFound;
    int beginIndex = 0;
    /*
     以下为自定义的section计算规则
    beginIndex += self.customSectionCount;
    if (self.secondarySectionCount > 0 ){
        for (NSInteger i = 0 ; i < [self.secondarySectionTitles count]; i++) {
            NSString * secondaryTitle = [self.secondarySectionTitles objectOrNilAtIndex:i];
            if ([secondaryTitle isEqualToString:title]) {
                ret = beginIndex + i;
                return ret;
            }
        }
        beginIndex += self.secondarySectionCount;
    }
     */
    if ([self.mainDataIndexChar count] > 0){
        for(NSInteger i = 0; i < [self.mainDataIndexChar count]; i++) {
            NSString * indexChar = [self.mainDataIndexChar objectAtIndex:i];
            if ([indexChar isEqualToString:title]) {
                ret = i;
                break;
            }
        }
    }
    if (ret != NSNotFound) {
        ret = ret + beginIndex;
    }
    return ret;
}

@end
