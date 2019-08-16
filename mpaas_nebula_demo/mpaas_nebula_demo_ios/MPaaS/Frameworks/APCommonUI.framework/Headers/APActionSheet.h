//
//  APActionSheet.h
//  TestView3
//
//  Created by sampan(渔真) on 13-9-29.
//  Copyright (c) 2013年 sampan. All rights reserved.
//

#import <AntUI/AUActionSheet.h>

__deprecated_msg("APActionSheetButtonType 已经废弃，请直接使用 AUActionSheetButtonType")
typedef AUActionSheetButtonType APActionSheetButtonType;

__deprecated_msg("APActionSheet 已经废弃，请直接使用 AntUI中的 AUActionSheet")
@interface APActionSheetItem : AUActionSheetItem

@end

@interface APActionSheet : AUActionSheet //UIView<UIAppearanceContainer>

@end
