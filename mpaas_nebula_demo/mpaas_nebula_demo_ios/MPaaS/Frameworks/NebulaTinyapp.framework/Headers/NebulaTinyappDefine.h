//
//  NebulaTinyappDefine.h
//  NebulaTinyapp
//
//  Created by theone on 2017/12/18.
//  Copyright © 2017年 Alipay. All rights reserved.
//

#ifndef NebulaTinyappDefine_h
#define NebulaTinyappDefine_h


typedef void (^NBJavaScriptCompleteBlock)(NSError *_Nullable error);
typedef void (^NBJavaScriptCallback)(id _Nullable json, NSError *_Nullable error);
typedef void (^NBDownloadCallback)(NSDictionary *_Nullable result);
typedef void (^NBImportJsCallback)(NSDictionary *_Nullable dic, NSError *_Nullable error);


#define kNBFROMH5JSC @"FROMH5JSC"
#define kNBEnableDSL @"enableDSL"


//*******************************ExpandPropertyKeys***************************//
#define kExpandPropertyKey_ComponentManager     @"kExpandPropertyKey_ComponentManager"
#define kExpandPropertyKey_JSC                  @"kExpandPropertyKey_JSC"
#define kExpandPropertyKey_MultiJSC             @"kExpandPropertyKey_MultiJSC"
#define kExpandPropertyKey_ComponentManager     @"kExpandPropertyKey_ComponentManager"
#define kExpandPropertyKey_JSCViewId            @"kExpandPropertyKey_JSCViewId"
#define kExpandPropertyKey_JSCPageId            @"kExpandPropertyKey_JSCPageId"
#define kExpandPropertyKey_JSCDebugger          @"kExpandPropertyKey_JSCDebugger"

//*******************************Event***************************//
#define kNBEvent_Seesion_Worker_Load_JS         @"session.worker.load.js" //woker启动过程中加载其他js的扩展点
#define kNBEvent_Session_Worker_Jsapi_Callasync @"session.worker.jsapi.callasync" //调试模式下jsapi调用事件
#define kNBEvent_Seesion_Worker_Create_After    @"session.worker.create.after" //woker启动过程中加载其他js的扩展点
#define kNBEvent_Scene_WK_LayerTreeComplete     @"scene.wk.layertreecommitcomplete" //WKWebViewLayout布局完成


#endif /* NebulaTinyappDefine_h */
