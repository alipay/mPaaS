//
//  sqlite_repair.h
//  SqliteSourceCode
//
//  Created by pucheng on 16/7/22.
//  Copyright © 2016年 Alipay. All rights reserved.
//

#ifndef sqlite_repair_h
#define sqlite_repair_h


#ifdef __cplusplus
extern "C" {
#endif // __cplusplus
    
/**
 *  本工具需要包含sqlite3的C接口库
 *
 */


/** 
 *  SQLITE_REPAIR_ERROR_CODE
 *  成功和错误的返回编码
 */
#define SQLITE_REPAIR_SUCCESS       0       //成功
#define SQLITE_REPAIR_SQLFILE       1       //.sql文件打开失败
#define SQLITE_REPAIR_OPEN          2       //数据库打开失败
#define SQLITE_REPAIR_NOT_EXTIST    3       //数据库文件不存在
#define SQLITE_REPAIR_BACKUP_FAIL   4       //数据库备份失败
#define SQLITE_REPAIR_VERSION_TOO_OLD   5   //版本太旧 接口不支持

/**
 * 数据库完整性检测 
 * 
 * @return 损坏的数据库返回-1，完整的返回0
 */
int sqlite_db_integrity_check(const char *db_path);

/**
 * 修复sqlite数据库，对于损坏的数据库尽可能的导出了可用的数据，修复后的数据库配置都是默认的，需要重新配置
 *
 * @return 返回0表示成功 或者 返回上面定义的错误编码
 */
int sqlite_db_repair(
                    const char *db_path,           //数据库路径
                    const char *backup_dir_name    //旧数据库备份到同目录下的新建目录，NULL表示不留备份
);

/**
 * 对输入路径的db进行备份，备份出的数据库是完全一样的，对损坏的数据库备份出的数据库很有可能还是损坏的
 *
 * @return 返回0表示成功 或者 返回上面定义的错误编码
 */
//int sqlite_db_backup(
//           const char *db_path,         //数据库路径
//           const char *backup_path      //备份数据库的路径
//);
    
#ifdef __cplusplus
}
#endif // __cplusplus

#endif /* sqlite_repair_h */
