#import "AUUILoadDefine.h"//程序自动生成
#ifdef ANTUI_UI_PopMenu_AUPopMenu//程序自动生成
//
//  AUPopMenu.h
//  AntUI
//
//  Created by niki on 2017/6/14.
//  Copyright © 2017年 Alipay. All rights reserved.
//

#import "AUPopItemView.h"


//#########################################################
//文档地址 : https://yuque.antfin-inc.com/antui/auidoc/ios_aupopmenu
//#########################################################

@class AUPopMenu;

@protocol AUPopMenuDelegate <NSObject>

@optional
- (void)DidClickPopItemView:(AUPopItemModel *)viewModel;
- (void)DidClickPopItemViewAtIndex:(NSInteger)index itemModel:(AUPopItemModel *)viewModel;
- (void)WillHidePopMenu:(AUPopMenu *)menun;

@end

@interface AUPopMenu : UIView

@property (nonatomic, weak) id<AUPopMenuDelegate> delegate;
@property (nonatomic, assign) BOOL isArchViewUp;             // 方向角朝向，默认向上
@property (nonatomic, strong) NSString *bizType;            // 业务标识，须传
@property (nonatomic, assign,readonly) BOOL display;        //是否展示
@property (nonatomic, assign) CGPoint destPosition;


/*  datas是 AUPopItemModel 对象列表
 *  position 方向尖角所在位置
 *  superView 所在父view
 */
- (instancetype)initWithDatas:(NSArray<AUPopItemModel *> *)datas
                     position:(CGPoint)position
                    superView:(UIView *)superView;

/*  默认带动画展示和隐藏
 */
- (void)showMenu;

/**
 * 建议使用该接口
 * superView:会覆盖掉init时候的superView
 * position:覆盖init时候的position
 */
- (void)showMenuOnSuperView:(UIView*) superView atPosition:(CGPoint) position;

//
- (void)hideMenu;

/* 更新数据北荣比如红点或者icon，注意：
如果事先调用initWithDatas传入datas再通过该接口来更新数据的时候必须确保：此接口data的个数和顺序与initWithDatas时传入的保持一致
 */
//- (void)updateDatas:(NSArray<AUPopItemModel *> *)datas;

@end

#endif//程序自动生成
