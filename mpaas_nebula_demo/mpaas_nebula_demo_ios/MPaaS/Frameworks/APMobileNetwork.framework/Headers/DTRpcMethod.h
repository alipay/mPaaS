//
//  DTRpcMethod.h
//  APMobileNetwork
//
//  Created by WenBi on 13-4-18.
//  Copyright (c) 2013年 Alipay. All rights reserved.
//

#import <Foundation/Foundation.h>

typedef NS_ENUM(NSInteger, RpcCacheDataType)
{
    RpcCacheDataTypeDefault = 0,//不存储RPC数据,不读取RPC的cache数据,普通的RPC流程
    RpcCacheDataTypeCommonSave, //RPC完成后保存数据为普通数据,与userId无关
    RpcCacheDataTypeUserSave,   //RPC完成后保存数据为用户数据,当前userId是存数据的Key的一部分
    RpcCacheDataTypeCommonRead, //不做网络请求,根据RPC参数为从cache中读取数据,无数据返回nil,与登录无关
    RpcCacheDataTypeUserRead,   //不做网络请求,根据RPC参数和userId为从cache中读取数据,不是登录态时或无数据返回nil
};

@protocol DTRpcPrivateEncryptProtocol <NSObject>

@optional
/**
 *  加密方法
 *  @param data 需要加密的数据
 *  @return 加密后的数据
 */
-(NSData*)encryptData:(NSData*)data;

/**
 *  解密方法
 *  @param data 需要解密的数据
 *  @return 解密后的数据
 */
-(NSData*)decryptData:(NSData*)data;

@end

@interface DTRpcMethod : NSObject

/** Operation type */
@property(nonatomic, copy) NSString *operationType;

/** 期望返回的对象类型。*/
@property(nonatomic, unsafe_unretained) Class resultClass;

/** 返回对象的类型。 */
@property(nonatomic, copy) NSString *returnType;

/** 如果一个 PRC 方法的返回值是一个集合类型，\code elementClass 指定集合中元素的类型。否则该属性为 nil。*/
@property(nonatomic, unsafe_unretained) Class elementClass;

/** 检查登录 */
@property(nonatomic, assign) BOOL checkLogin;

/** 签名 */
@property(nonatomic, assign) BOOL signCheck;

/** 是否是统一账户网关的请求，默认NO*/
@property(nonatomic, assign) BOOL isAliUserGWMethod;

/** 统一账户网关需要在httpHeader里加此字段*/
@property(nonatomic, strong) NSString *apdid;

/** 缓存策略 */
@property(nonatomic, assign) RpcCacheDataType cacheStrategy;

/** 是否支持网络层的重传,需要业务做好幂等性才设置为YES */
@property(nonatomic, assign) BOOL retryable;

/** rpc超时时长可设置 */
@property(nonatomic,assign) NSTimeInterval timeoutInterval;

/** 设置是否忽略网络状态 */
@property(nonatomic,assign) BOOL isIgnoreNetStatus;

/** 设置是否是特殊通道rpc 默认no */
@property(nonatomic,assign) BOOL isSpecialChannelRPC;

/** 设置是否是NSData rpc 默认no */
@property(nonatomic,assign) BOOL isNSData;

/** 设置是否是登录rpc(专为登录session串号提供仅在账号切换时使用,其他业务不可使用) 默认no */
@property(nonatomic,assign) BOOL isLoginRPC;
/**request 请求走post还是get 默认是post 当走get请求时 走RPCV1**/
@property(nonatomic,assign) BOOL httpGET;
/**rpc是否需要自加密 默认YES mpaas用**/
@property(nonatomic,assign) BOOL isCrypt;

/** 设置对发送数据的body加解密协议 inside专用*/
@property(nonatomic,strong) id<DTRpcPrivateEncryptProtocol> privateEncrypt;
@end
