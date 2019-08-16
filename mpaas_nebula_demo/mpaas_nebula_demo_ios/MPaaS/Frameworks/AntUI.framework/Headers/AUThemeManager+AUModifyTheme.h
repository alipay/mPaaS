//
//  AUThemeManager+AUModifyTheme.h
//  AntUI
//
//  Created by 莜阳 on 2017/6/22.
//  Copyright © 2017年 Alipay. All rights reserved.
//

@interface AUThemeManager (AUModifyTheme)

+ (BOOL)au_curTheme_add_extraInfo:(NSDictionary *)extraInfo;

+ (BOOL)au_curTheme_remove_extraInfo:(NSDictionary *)extraInfo;

@end


@interface AUThemeManager (AURemoteTheme)

// 远程下发的主题更新AntUI默认主题
+ (void)au_remoteTheme_update:(NSDictionary *)themeInfo;

// 本地优先检测并更新缓存中的主题
+ (NSDictionary *)au_update_themes_inCache;

@end
