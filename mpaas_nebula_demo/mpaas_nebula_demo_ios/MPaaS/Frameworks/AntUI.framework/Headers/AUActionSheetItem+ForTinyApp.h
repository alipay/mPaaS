//
//  AUActionSheetItem+ForTinyApp.h
//  AntUI
//
//  Created by zhaolei.lzl on 2018/7/10.
//  Copyright © 2018年 Alipay. All rights reserved.
//

#import <Foundation/Foundation.h>



@interface AUActionSheetItem(ForTinyApp)

- (void)au_for_tiny_app_setBageStyle:(NSString *) style
                             content:(NSString *) content
                               error:(NSError **) error;

@end
