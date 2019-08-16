//
//  MASSMethod.h
//  MASSProxy
//
//  Created by cuinacai on 16/2/24.
//  Copyright © 2016年 Alipay. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "MASSMethod.h"
#import "MASSProxyDefine.h"
#import <MASSChannel/NBNetDownloadCommon.h>

@interface MASSDownBaseMethod : MASSMethod
@property(nonatomic)MASSDownReturnType downReturnType;      //返回文件还是内存
@property(nonatomic, strong) NSString *saveFilePath;        //返回的如果是文件，保存的绝对路径
@property(nonatomic, strong) NSData* mmdpBizParam;          //mmdp协议业务协议数据
@property(nonatomic, assign) BOOL   backgroundTask;         //是否是后台自动触发，比如一些预推资源
@end


@interface MASSDownMethod : MASSDownBaseMethod
@property(nonatomic, strong) NSString *fileId;              //文件ID
@property(nonatomic, assign) BOOL isPicture;                //是否是图片下载
@property(nonatomic, strong) NSString *zoom;                //对应django协议的zoom参数
@property(nonatomic) BOOL isGradual;                        //是否需要渐显
@property(nonatomic, strong) NSDictionary* extraUrlParams;  //额外要填的url参数
@property(nonatomic, strong) NSDictionary<NSString*,NSString*>* extralMMDPParams;
@end

@interface MASSTFSDownMethod : MASSDownBaseMethod
@property(nonatomic, strong) NSString *url;                 //资源的url
@property(nonatomic, strong) NSDictionary* externHeaders;   //私有头
@property(nonatomic) BOOL   otherUrl;                       //非图片下载的一些扩展，主要是给ATS审核使用
@property(nonatomic) BOOL   isGradual;                      //是否需要渐显
@property(nonatomic) BOOL   isPost;                         //是否是post请求
@property(nonatomic) NSData*    postBody;                   //post请求的body
@property(nonatomic) BOOL   needContinueLoad;               //该资源下载是文件下载的情况下，是否要支持续传，主要给边下边播使用
@property(nonatomic) BOOL   NBNetDownload;                  //新数据通道的下载，将fileid拼接成蚂蚁cdn下载的url后进行的下载
@end


@interface MASSMarkDownMethod : MASSDownBaseMethod
@property(nonatomic, strong) NSString *fileId;              //主图的文件ID
@property(nonatomic, strong) NSString *zoom;                //主图的zoom
@property(nonatomic, strong) NSDictionary<NSString*,NSString*>* extralMMDPParams;
@end
