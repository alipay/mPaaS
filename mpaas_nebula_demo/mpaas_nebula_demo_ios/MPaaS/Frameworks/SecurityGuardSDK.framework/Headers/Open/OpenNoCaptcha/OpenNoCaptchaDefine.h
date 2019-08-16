//
//  OpenNoCaptchaDefine.h
//  SecurityGuardSDK
//
//  Created by chenkong on 15/4/29.
//  Copyright (c) 2015年 Li Fengzhong. All rights reserved.
//

//touch event type
extern NSInteger const OPEN_TOUCH_TYPE_BEGAN;
extern NSInteger const OPEN_TOUCH_TYPE_MOVED;
extern NSInteger const OPEN_TOUCH_TYPE_ENDED;


//status code
extern NSInteger const OPEN_NC_INIT_SUCCEED;                  //101 返回两个渲染坐标
extern NSInteger const OPEN_NC_VERI_SUCCEED;                  //102 返回token，sig，sessionId
extern NSInteger const OPEN_NC_RETRY;                         //103 返回两个渲染坐标
extern NSInteger const OPEN_NC_SERVER_FAULT;                  //104 返回token，sig，sessionId

//error status code
extern NSInteger const OPEN_NC_INVALID_PARA;                  //1201
extern NSInteger const OPEN_NC_NO_MEMORY;                     //1202
extern NSInteger const OPEN_NC_NOT_INIT_YET;                  //1203
extern NSInteger const OPEN_NC_QUEUE_FULL;                    //1204
extern NSInteger const OPEN_NC_RETRY_TO_MAX;                  //1205
extern NSInteger const OPEN_NC_HTTP_NO_TOKEN;                 //1206
extern NSInteger const OPEN_NC_HTTP_REQUEST_FAIL;             //1207
extern NSInteger const OPEN_NC_SERVER_RETURN_ERROR;           //1208
extern NSInteger const OPEN_NC_VERI_GET_WUA_FAIL;             //1209
extern NSInteger const OPEN_NC_VERI_GET_TRACE_FAIL;           //1210
extern NSInteger const OPEN_NC_VERI_APPKEY_MISMATCH;          //1211
extern NSInteger const OPEN_NC_VERI_SESSION_EXPIRED;          //1212
extern NSInteger const OPEN_NC_VERI_WUA_INVALID_PARAM;        //1213
extern NSInteger const OPEN_NC_VERI_WUA_DATA_FILE_MISMATCHA;  //1214
extern NSInteger const OPEN_NC_VERI_WUA_NO_DATA_FILE;         //1215
extern NSInteger const OPEN_NC_VERI_WUA_INCORRECT_DATA_FILE;  //1216
extern NSInteger const OPEN_NC_VERI_WUA_KEY_NOT_EXIST;        //1217
extern NSInteger const OPEN_NC_VERI_WUA_LOW_VERSION_DATA_FILE;//1218
extern NSInteger const OPEN_NC_UNKNOWN_ERROR;                 //1299
