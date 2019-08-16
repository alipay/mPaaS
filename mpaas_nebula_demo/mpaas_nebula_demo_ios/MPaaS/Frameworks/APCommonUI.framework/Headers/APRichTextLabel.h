//
//  APRichTextLabel.h
//
//

#import <UIKit/UIKit.h>
#import <AntUI/AURichTextLabel.h>

__deprecated_msg("请直接替换 APRichTextLabelDelegate 为 AURichTextLabelDelegate")
@protocol APRichTextLabelDelegate <AURichTextLabelDelegate>

@end

__deprecated_msg("请直接替换 APRichTextLabelComponent 为 AURichTextLabelComponent")
@interface APRichTextLabelComponent : AURichTextLabelComponent //NSObject

@end

@interface APRichTextLabelExtractedComponent : AURichTextLabelExtractedComponent 

@end

__deprecated_msg("APRichTextLabel 已经废弃，请直接使用 AURichTextLabel")
@interface APRichTextLabel : AURichTextLabel


@end
