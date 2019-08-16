//
//  H5LogConfigs.h
//  NebulaBiz
//
//  Created by Glance on 2017/5/7.
//  Copyright © 2017年 Alipay. All rights reserved.
//

#import <Foundation/Foundation.h>
#ifndef H5_AUTOLOG_CONFIGS
#define H5_AUTOLOG_CONFIGS

#define h5_al_intercept_scheme                     2100
#define h5_al_network_performance                  2045
#define h5_al_network_permisson_error              2088
#define h5_al_session_start                        4010
#define h5_al_session_verifyTar_success            4030
#define h5_al_session_verifyTar_fail               4031
#define h5_al_session_entry_error                  4001
#define h5_al_session_launch                       4040
#define h5_al_session_resume                       4050
#define h5_al_session_to_native                    4009
#define h5_al_session_end                          4060
#define h5_al_launch_param_warn                    2200
#define h5_al_pay_start                            1070
#define h5_al_pay_result                           1080
#define h5_al_jsapi_notfound                       4102
#define h5_rpc_notfound                            4103
#define h5_al_session_inject_js                    4150
#define h5_al_session_inject_jscode                4151
#define h5_al_jsapi_sendevent                      4200
#define h5_al_session_aliautologin                 4400
#define h5_al_autologin_start                      4300
#define h5_al_autologin_result                     4301
#define h5_al_autologin_end                        4302
#define h5_al_session_zhimalogin                   4401
#define h5_al_debugmode_enable                     4600
#define h5_al_h5app_maperror                       4700
#define h5_al_page_context_lost_error              4800
#define h5_wk_process_hang                         6001
#define h5_al_tabbar_warn                          99000
#define h5_al_tabbar_error                         99001
#define h5_al_jsapi_permission_cors                5000
#define h5_page_repair                             5020
#define h5_trans_pushWindow                        5101
#define h5_tinyapp_handleLaunchMode                5102

#endif

@interface H5AutoLogConfigs : NSObject

NSDictionary * H5AutoLogDefaultConfigs();

+ (NSDictionary*)readPreConfigByLid:(NSInteger)lid;

@end
