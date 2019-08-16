//
//  DTNetworkException.h
//  RPC
//
//  Created by WenBi on 13-3-5.
//  Copyright (c) 2013年 Alipay. All rights reserved.
//

#import <Foundation/Foundation.h>

extern NSString * const kNetworkException;


extern NSString * const kRPCErrorDomain;

typedef enum RPCErrorCode
{
	RPCInvalidArguments,
	RPCInvalidClass,
	RPCPropertyTypeNotMatch,
	RPCParseError,
} RPCErrorCode;

NSError * DTFCreateRPCError(RPCErrorCode code, NSString *message);

