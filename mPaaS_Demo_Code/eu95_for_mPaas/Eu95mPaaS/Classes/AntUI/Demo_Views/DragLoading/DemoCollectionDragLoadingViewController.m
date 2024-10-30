//
//  DemoCollectionDragLoadingViewController.m
//  AntUIDemo
//
//  Created by 沫竹 on 2017/11/1.
//  Copyright © 2017年 Alipay. All rights reserved.
//

#import "DemoCollectionDragLoadingViewController.h"

@interface DemoCollectionDragLoadingViewController ()

@property (nonatomic, strong) UICollectionView *collectionView;
@property (nonatomic, strong) AUDragLoadingView *loadingView;

@end

@implementation DemoCollectionDragLoadingViewController {
    NSInteger _sectionCount;
    NSInteger _maxPage;
}

static NSString * const reuseIdentifier = @"Cell";

- (UICollectionViewFlowLayout *)followLayout
{
    // 创建瀑布流对象,设置cell的尺寸和位置
    UICollectionViewFlowLayout *layout = [[UICollectionViewFlowLayout alloc] init];
    layout.scrollDirection = UICollectionViewScrollDirectionVertical;// 设置滚动的方向
    CGSize size = [UIScreen mainScreen].bounds.size;// 设置cell的尺寸
    layout.itemSize = size;// 设置cell之间的间距
    layout.minimumInteritemSpacing = 10;
    layout.minimumLineSpacing = 10;// 设置行距
    return layout;
}




- (void)viewDidLoad {
    [super viewDidLoad];
    
    
    // Uncomment the following line to preserve selection between presentations
    // self.clearsSelectionOnViewWillAppear = NO;
    
    // Register cell classes
    _sectionCount = 1;
    
    UICollectionViewFlowLayout *layout = [self followLayout];
    self.collectionView = [[UICollectionView alloc] initWithFrame:self.view.bounds collectionViewLayout:layout];
    self.collectionView.autoresizingMask = (UIViewAutoresizingFlexibleWidth | UIViewAutoresizingFlexibleHeight);
    [self.collectionView registerClass:[UICollectionViewCell class] forCellWithReuseIdentifier:reuseIdentifier];
    self.collectionView.pagingEnabled = YES;
    self.collectionView.bounces = NO; // 是否有边距
    self.collectionView.showsHorizontalScrollIndicator = NO;
    self.collectionView.delegate = (id<UICollectionViewDelegate>)self;
    self.collectionView.dataSource = (id<UICollectionViewDataSource>)self;
    [self.view addSubview:self.collectionView];
    self.collectionView.backgroundColor = RGB(0xf5f5f5);
    
    self.loadingView = [[AUDragLoadingView alloc] initWithCollectionView:self.collectionView bizType:@"demo" makeConfig:^(AUDragLoadingConfig *config) {
        config.endTipsEnable = YES;
        config.attachedBottomIfHalfContentView = YES;
    }];
    self.loadingView.state = AUDragLoadingStateNormal; // 普通态（存在下一页，实际业务要考虑初始化的时候是否有下一页的情况）
    __weak typeof(self) weakSelf = self;
    self.loadingView.loadingBlock = ^{
        [weakSelf startRpc];
    };
    
    // Do any additional setup after loading the view.
}

- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}


#pragma mark <UICollectionViewDataSource>

- (NSInteger)numberOfSectionsInCollectionView:(UICollectionView *)collectionView {
    return _sectionCount;
}


- (NSInteger)collectionView:(UICollectionView *)collectionView numberOfItemsInSection:(NSInteger)section {
    return 10;
}

- (UICollectionViewCell *)collectionView:(UICollectionView *)collectionView cellForItemAtIndexPath:(NSIndexPath *)indexPath {
    UICollectionViewCell *cell = [collectionView dequeueReusableCellWithReuseIdentifier:reuseIdentifier forIndexPath:indexPath];
    if (indexPath.section == 0) {
        cell.backgroundColor = [UIColor redColor];
    } else {
        cell.backgroundColor = [UIColor greenColor];
    }
    
    return cell;
}

#pragma mark - UICollectionViewDelegateFlowLayout
- (CGSize)collectionView:(UICollectionView *)collectionView layout:(UICollectionViewLayout *)collectionViewLayout sizeForItemAtIndexPath:(NSIndexPath *)indexPath
{
    return CGSizeMake(96, 100);
}

- (UIEdgeInsets)collectionView:(UICollectionView *)collectionView layout:(UICollectionViewLayout *)collectionViewLayout insetForSectionAtIndex:(NSInteger)section
{
    return UIEdgeInsetsMake(5, 5, 5, 5);
}



#pragma mark - 代理方法

- (CGSize)collectionView:(UICollectionView *)collectionView layout:(UICollectionViewLayout*)collectionViewLayout referenceSizeForFooterInSection:(NSInteger)section
{
//    if (section == collectionView.numberOfSections - 1) {
    return [self.loadingView collectionView:collectionView layout:collectionViewLayout referenceSizeForFooterInSection:section];
//    }
}

// 设置headerView和footerView的
- (UICollectionReusableView *)collectionView:(UICollectionView *)collectionView viewForSupplementaryElementOfKind:(NSString *)kind atIndexPath:(NSIndexPath *)indexPath
{
//    if (section == collectionView.numberOfSections - 1) {
    return [self.loadingView collectionView:collectionView viewForSupplementaryElementOfKind:kind atIndexPath:indexPath];
//    }
}

- (void)scrollViewDidScroll:(UIScrollView *)scrollView
{
    [self.loadingView scrollViewDidScroll:self.collectionView];
}


#pragma mark - 模拟RPC的情况

- (void)startRpc
{
    [self performSelector:@selector(completeRpc) withObject:nil afterDelay:3];
}

- (void)completeRpc
{
    _sectionCount += 1;
    [self.collectionView reloadData];
    
    _maxPage++;
    // 无下一页
    if (_maxPage >= 3) {
        self.loadingView.state = AUDragLoadingStateEnd;
    }
    // 还有下一页
    else {
        self.loadingView.state = AUDragLoadingStateNormal;
    }
}

/*
#pragma mark - Navigation

// In a storyboard-based application, you will often want to do a little preparation before navigation
- (void)prepareForSegue:(UIStoryboardSegue *)segue sender:(id)sender {
    // Get the new view controller using [segue destinationViewController].
    // Pass the selected object to the new view controller.
}
*/

@end
