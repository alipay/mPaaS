//
//  DTRpcConfigScope.h
//  APMobileNetwork
//
//  Created by WenBi on 13-4-19.
//  Copyright (c) 2013年 Alipay. All rights reserved.
//

#import <Foundation/Foundation.h>

/**
 * PRC 配置的作用域。
 */
typedef enum DTRpcConfigScope
{
	
	/** 全局生效。 */
	kDTRpcConfigScopeGlobal,
    
    /** 全局范围内，只生效一次。*/
    kDTRpcConfigScopeGlobalOnce,
	
	/** 本地线程生效。 */
	kDTRpcConfigScopeLocalThread,
	
	/** 最近一次 RPC 调用生效。 */
	kDTRpcConfigScoperaryTemporary,
	
} DTRpcConfigScope;
