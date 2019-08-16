//
//  H5LogConfigs.h
//  NebulaBiz
//
//  Created by Glance on 2017/5/7.
//  Copyright © 2017年 Alipay. All rights reserved.
//

#import <Foundation/Foundation.h>
#ifndef NB_AUTOLOG_CONFIGS
#define NB_AUTOLOG_CONFIGS

//CONFIGS_START

#define h5_al_page_start                           1100
#define h5_al_page_finish                          1060
#define h5_al_page_load_fail                       1110
#define h5_al_page_appear                          3333
#define h5_al_page_resume                          1120
#define h5_al_network_start                        2044
#define h5_al_network_performance_warn             2041
#define h5_al_network_performance_error            2042
#define h5_page_performance	                       2020
#define h5_page_abnormal	                       2021
#define h5_al_jsapi_result_error                   4101
#define h5_al_page_jsError                         2050
#define h5_al_jsError                              2051
#define h5_al_page_syncajax                        2030
#define h5_al_session_from_native                  4008

#define h5_psd_loadplugins_fail                    5500
#define h5_al_session_httpProxy                    4130
#define h5_al_session_map_success                  4160
#define h5_al_session_fallback                     4161
#define h5_wk_process_terminate                    6000
#define h5_wk_process_reload_fail                  6002
#define h5_al_resource_first_offline               7000

#define h5_app_prepare                             5000
#define h5_app_download                            5001
#define h5_app_unzip                               5002
#define h5_app_request                             5003
#define h5_app_pool                                5004
#define h5_app_verify                              5005
#define h5_app_excep                               5006
#define h5_app_biz_sync                            5007
#define h5_app_biz_appcenter                       5008
#define h5_app_biz_excp                            5009
#define h5_app_rpc_exception                       5010
#define h5_app_load_datasource                     5011
#define h5_al_page_res_redirect                    5012
#define h5_app_smart                               5013
#define psd_wk_message_received                    8000
#define psd_wk_message_xmlhttprequest_sendback     8001

#define h5_al_network_unfinish                     100001

#endif

@interface NBAutoLogConfigs : NSObject

NSDictionary * NBAutoLogMappingDict();
NSDictionary * NBAutoLogDefaultConfigs();

+ (NSDictionary*)readPreConfigByLid:(NSInteger)lid;

@end
