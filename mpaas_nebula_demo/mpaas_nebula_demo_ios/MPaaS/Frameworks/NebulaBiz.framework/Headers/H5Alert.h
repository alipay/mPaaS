//
//  H5Alert.h
//  H5Service
//
//  Created by noahlu on 14-3-3.
//  Copyright (c) 2014年 Alipay. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <AntUI/AUNoticeDialog.h>

@interface H5Alert : NSObject <AUDialogDelegate>

@property(nonatomic, strong) AUNoticeDialog *noticeDialog;


/**
 *  创建和显示一个UIAlertView
 *
 *  @param params   格式如下\n
 *       {
 *        title: '标题',
 *        message: '内容',
 *        buttons: ['左按钮标题','右按钮标题']
 *       }
 *  @param callback 处理弹出框点击事件的回调，入参`index`为被点击的按钮序号
 */
- (id)showAlertWithParams:(NSDictionary *)params callback:(void (^)(NSInteger index))callback;

/**
 *  创建和显示一个alert框
 *
 *  @param params   格式如下\n
 *       {
 *        title: '标题',
 *        message: '内容',
 *        button: '确定'
 *       }
 *  @param callback 用户点击了"确定"
 */
- (id)alertWithParams:(NSDictionary *)params callback:(void (^)(void))callback;

/**
 *  创建和显示一个confirm框
 *
 *  @param params   格式如下\n
 *       {
 *        title: '标题',
 *        message: '内容',
 *        okButton: '确定',
 *        cancelButton: '取消',
 *       }
 *  @param callback 处理弹出框点击事件的回调，入参`ok`表示是否点击了确定按钮
*/
- (id)confirmWithParams:(NSDictionary *)params callback:(void (^)(BOOL ok))callback;

@end
