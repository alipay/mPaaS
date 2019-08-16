//
//  MASSCommonDefine.h
//  MASSChannel
//
//  Created by yangxiao on 15/11/24.
//  Copyright © 2015年 ppp. All rights reserved.
//

#import <Foundation/Foundation.h>

#define MASS_DOWNLOAD_LOACAL_PARTLY_FILE_WHOLE_LEN_ATTRIBUTES_KEY @"MASS_Download_Local_partly_file_whole_len_attributes_key"
#define MASS_UPLOAD_STORAGE_SERVER_MISSING_HOLES_KEY @"MASS_upload_file_missing_holes_storage_key"
#define MASS_MASS_UUID_STORAGE_KEY @"MASS_uuid_storage_key"
#define MASS_DOWNLOAD_STORAGE_DOWNLOADED_TMP_FILE_KEY @"MASS_download_file_tmp_paths"
//服务端文档上说续传在24小时完成都可以，为保险起见，我们这边设置20小时过期
#define MASS_UPLOAD_PART_SERVER_CACHE_EXPIRE_TIME_SECONDS (22*60*60)
//下载续传的临时文件保存时间15天
#define MASS_DOWNLOAD_TMP_PART_FILE_EXPIRE_TIME_SECONDS (15*24*60*60)
#define MASS_UPLOAD_HOLES_THIS_TASK_CREATE_TIME_KEY @"createTime"
#define MASS_UPLOAD_HOLES_THIS_TASK_PERCENT_KEY @"percent"
#define MASS_UPLOAD_HOLES_THIS_TASK_HOLES_KEY @"holes"

typedef NS_ENUM(NSInteger,MATErrorCode) {
    succ,
    error_no_main_thread = 1,
    error_stream_svr_host_illegal = 2,
    error_stream_schedule_fail = 3,
    error_stream_open_fail = 4,
    error_create_stream_pair_fail = 5,
    error_connect_timer_alloc_fail = 6,
    error_start_connect_fail = 7,
    error_token_interval_timer_alloc_fail = 8,
    error_send_token_request = 9,
    error_token_socket_close_no_send_whole = 10,
    error_token_uri_alloc_fail = 11,
    error_token_request_alloc_fail = 12,
    error_token_http_data_alloc_fail = 13,
    error_token_http_rsp_parser_partly = 14,
    error_token_http_rsp_json_illegal = 15,
    error_token_http_rsp_body_code_missing = 16,
    error_token_rsp_body_code_not_0 = 17,
    error_token_rsp_body_data_part_missing = 18,
    error_token_rsp_body_params_missing = 19,
    error_token_rsp_json_parser_exception = 20,
    error_token_rsp_http_code_error = 21,
    error_quick_up_uri_alloc_fail = 22,
    error_quick_up_request_alloc_fail = 23,
    error_quick_up_http_data_alloc_fail = 24,
    error_quick_up_write_fail = 25,
    error_quick_up_socket_close_no_send_whole = 26,
    error_quick_up_rcv_request = 27,
    error_quick_up_rsp_json_index_illegal = 28,
    error_quick_up_rsp_body_code_missing = 29,
    error_quick_up_rsp_body_data_part_missing = 30,
    error_quick_up_rsp_code_wrong = 31,
    error_quick_up_json_parser_exception = 32,
    error_quick_up_http_head_code_wrong = 33,
    error_quick_up_http_rcved_part = 34,
    error_upload_rsp_timer_alloc_fail = 35,
    error_upload_send_fail = 36,
    error_upload_close_upload_partly = 37,
    error_upload_read_error = 38,
    error_upload_uri_alloc_fail = 39,
    error_upload_cf_request_alloc_fail = 40,
    error_upload_cf_request_data_alloc_fail = 41,
    error_upload_rsp_rcved_partly = 42,
    error_upload_rsp_http_head_code_error = 43,
    error_upload_rsp_data_json_parse_fail = 44,
    error_upload_rsp_body_code_missing = 45,
    error_upload_rsp_json_data_part_missing = 46,
    error_upload_rsp_code206_missing_parts_null = 47,
    error_upload_rsp_json_code_error = 48,
    error_upload_rsp_missing_pieces_format_error = 49,
    error_task_upload_task_alloc_fail = 50,
    error_quick_up_callback_not_found = 51,
    error_upload_callback_not_found = 52,
    error_upload_progress_callback_not_found = 53,
    error_download_callback_not_found = 54,
    error_download_progress_callback_not_found = 55,
    error_download_connect_timer_alloc_fail = 56,
    error_download_uri_alloc_fail = 57,
    error_download_cf_req_alloc_fail = 58,
    error_download_cf_http_data_alloc_fail = 59,
    error_download_stream_write_fail = 60,
    error_download_sock_close_not_complated = 61,
    error_download_stream_read_fail = 62,
    error_download_need_copy_len_error = 63,
    error_download_rsp_content_start_index_error = 64,
    error_download_rsp_http_code_error = 65,
    error_download_rsp_part_head_rcved = 66,
    error_token_svr_close_when_connecting = 67,
    error_quick_up_svr_close_when_connecting = 68,
    error_up_svr_close_when_connecting = 69,
    error_download_svr_close_when_connecting = 70,
    error_token_rsp_read_fail = 71,
    error_download_local_file_attr_read_fail = 72,
    error_upload_old_hole_start_bigger_than_end = 73,
    error_upload_old_hole_format_illegal = 74,
    error_config_format_illegal = 75,
    error_recording_request_alloc_fail = 76,
    error_recording_stream_write_fail = 77,
    error_recording_svr_close_when_connecting = 78,
    error_recording_close_happens_task_uncomplated = 79,
    error_recording_read_error = 80,
    error_recording_json_data_part_miss = 81,
    error_recording_json_rsp_code_wrong = 82,
    error_recording_json_rsp_code_miss = 83,
    error_recording_json_parser_exception = 84,
    error_recording_http_rsp_content_json_illegal = 85,
    error_recording_http_rsp_head_code_wrong = 86,
    error_recording_http_rsp_parser_partly = 87,
    error_recording_data_append_task_miss = 88,
    error_recording_callback_task_miss = 89,
    error_tfs_connect_timer_alloc_fail = 90,
    error_tfs_write_stream_write_fail = 91,
    error_tfs_svr_close_client_when_connectiong = 92,
    error_tfs_svr_close_when_download_part = 93,
    error_tfs_fill_http_data_alloc_fail = 94,
    error_tfs_fill_http_request_alloc_fail = 95,
    error_tfs_fill_http_url_alloc_fail = 96,
    error_tfs_read_stream_read_wrong = 97,
    error_tfs_rsp_copylen_error = 98,
    error_tfs_rsp_content_start_index_wrong = 99,
    error_tfs_rsp_http_head_code_wrong = 100,
    error_tfs_succ_callback_task_miss_in_queue = 101,
    error_tfs_progress_callback_task_miss = 102,
    error_tfs_start_connect_fail = 103,
    error_recording_start_connect_fail = 104,
    error_save_file_stream_fail = 105,
    error_mass_thread_dead = 106,
    error_mass_token_expire = 107,
    error_download_msg_in_queue_expired = 108,
    error_tfs_msg_in_queue_expired = 109,
    error_mark_alloc_timer_fail = 110,
    error_mark_start_connect_error = 111,
    error_mark_write_error = 112,
    error_mark_tcp_close_when_connecting = 113,
    error_mark_tcp_close_when_request_not_complated = 114,
    error_mark_read_fail = 115,
    error_mark_rsp_len_wrong = 116,
    error_mark_rsp_content_start_index_wrong = 117,
    error_mark_rsp_http_code_not_200 = 118,
    error_mark_build_req_data_alloc_fail = 119,
    error_mark_build_req_msg_alloc_fail = 120,
    error_mark_build_req_url_alloc_fail = 121,
    error_event_callback_exception = 122,
    error_exchange_url_token_expired = 123,
    error_total_count

};

extern const NSString* mass_error_messages[];

typedef NS_ENUM(NSInteger,MASSBizErrorCode) {
    MASSBizErrorCode_Tcp_Timeout = -1000101,
    MASSBizErrorCode_SSL_Timeout = -1000102,
    MASSBizErrorCode_Response_Timeout = -1000103,
    MASSBizErrorCode_Queue_Timeout = -1000104,
};

@interface UtilsForm : NSObject

+(NSString*)getMd5OXC:(NSData*)data;

+(void)noticeError:(MATErrorCode) code;

+(void) setObjToFileWithKey:(NSString*) key value:(NSObject*)value;

+(id) getObjFromFileWithKey:(NSString*)key;

+(void)logDiagnose:(NSArray*) content;

+(void)MdapUploadLog:(NSArray*) content;

+(NSString*)getHostFromUrl:(NSString*)url port:(NSInteger*)port;

+(BOOL)getUrlNeedCrypto:(NSString*)url;

+(NSString*)getOxcNum:(int32_t)num;

+(NSInteger)getNumFromOxcString:(NSString*)oxc;

+(NSData*)decompressGzip:(NSData*)source;

+(NSInteger)getRandomNum;

@end

/**
 *  错误上报调用
 *
 *  @param code 错误码
 */
void noticeError(MATErrorCode code);

/**
 *  本地诊断日志
 *
 *  @param log 本地日志的内容
 */
void DIAGNOSELOCAL(NSString* log);

/**
 *  content 最大容量4，前3个位NSString，最后一个为NSDictionary
 *
 *  @param content
 */
void mdapLog(NSArray* content);


@interface HttpDataParser : NSObject

@property (nonatomic) NSUInteger contentlen;

@property (nonatomic) NSInteger  httpCode;

@property (nonatomic) NSInteger  contentStartIndex;

@property (nonatomic) NSInteger  totalHttpLen;

@property (nonatomic) NSString*     Location302;

@property (nonatomic) BOOL          chunked;

@property (nonatomic) NSString*     cdnVia;

@property (nonatomic) NSString*     cdnTrace;

@property (nonatomic) BOOL          isHttp1;

@property (nonatomic) NSData*       httpHead;

@property (nonatomic) BOOL          useGzip;

@property (nonatomic) NSString*     contentMd5;

+(instancetype)shareInstance;

//成功返回整个http包长度，包不全返回-1，其他错误返回其他负数
-(NSInteger)ParserHttpRsp:(UInt8*)start length:(NSUInteger)len;

+(NSMutableData*)getChunkedBodyFromHttpBody:(UInt8*)start length:(NSUInteger)len;

@end

@interface RecordingData : NSObject
@property (nonatomic) NSData*       data;
@property (nonatomic) NSString*     taskid;
@property (nonatomic) BOOL          hasNext;
+(instancetype)RecordingData:(NSData*)data TaskKey:(NSString*)tk HasNext:(BOOL)hn;
@end

