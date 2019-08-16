#import "AUUILoadDefine.h"//程序自动生成
#ifdef ANTUI_UI_refreshLoadingView_AUDragLoadingView//程序自动生成
//
//  AUDragLoadingView.h
//  AntUI
//
//  Created by 祝威 on 16/9/30.
//  Copyright © 2016年 Alipay. All rights reserved.
//

#import <AntUI/AntUI.h>

//#########################################################
//文档地址 : https://yuque.antfin-inc.com/antui/auidoc/ios_audragloadingview
//#########################################################


#define kDragLoading_Height ([AUDragLoadingView dragLoadingViewHeight]) // 视图高度

typedef NS_ENUM(NSUInteger, AUDragLoadingState) {
    AUDragLoadingStateNormal,
    AUDragLoadingStateLoading,
    AUDragLoadingStateEnd
};

@interface AUDragLoadingConfig : NSObject

@property (nonatomic, assign) BOOL      attachedBottomIfHalfContentView; // 当内容达不到满屏时，是否吸附在底部（默认为NO）
@property (nonatomic, strong) NSString *normalTips;      // 等待加载下一页的文案（默认为点击加载更多）
@property (nonatomic, strong) NSString *loadingTips;     // 加载中的文案（加载中...）

@property (nonatomic, strong) UIView   *endStateView;    // 结束态（自定义结束态视图，不设置使用预置的）
@property (nonatomic, assign) BOOL      endTipsEnable;   // 只有设置endTipsEnable为YES的时候，endTips才会生效
@property (nonatomic, strong) NSString *endTips;         // 默认为没有更多

@end

/*！
 @class       AURefreshLoadingView
 @abstract    UIView
 */
@interface AUDragLoadingView : UIView

AU_UNAVAILABLE_INIT

// 当前状态
@property (nonatomic, assign) AUDragLoadingState state;

// 加载block
@property (nonatomic, copy)   void(^loadingBlock)(void);

// 初始化方法，会将自己添加到tableview的tableFooterView上面
- (instancetype)initWithTableView:(UITableView *)tableView
                          bizType:(NSString *)bizType
                       makeConfig:(void(^)(AUDragLoadingConfig *config))makeConfig;

// 初始化方法，会将自己添加到collectionView的footerView上面
// 需在layout之后调用
- (instancetype)initWithCollectionView:(UICollectionView *)collectionView
                               bizType:(NSString *)bizType
                            makeConfig:(void(^)(AUDragLoadingConfig *config))makeConfig;

// UIScrollView的delegate里面回调这个方法
- (void)scrollViewDidScroll:(UIScrollView *)scrollView;

// UICollectionView回调该方法
- (CGSize)collectionView:(UICollectionView *)collectionView layout:(UICollectionViewLayout*)collectionViewLayout referenceSizeForFooterInSection:(NSInteger)section;

// UICollectionView回调该方法
- (UICollectionReusableView *)collectionView:(UICollectionView *)collectionView viewForSupplementaryElementOfKind:(NSString *)kind atIndexPath:(nonnull NSIndexPath *)indexPath;

// 高度
+ (CGFloat)dragLoadingViewHeight;

@end

#endif//程序自动生成
