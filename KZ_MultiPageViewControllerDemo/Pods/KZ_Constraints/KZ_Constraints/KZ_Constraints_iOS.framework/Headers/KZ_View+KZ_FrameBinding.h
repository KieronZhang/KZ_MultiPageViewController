//
//  KZ_View+KZ_FrameBinding.h
//  KZ_Constraints
//
//  Created by Kieron Zhang on 2017/10/13.
//  Copyright © 2017年 Kieron Zhang. All rights reserved.
//

#import "KZ_View+KZ_Constraints.h"

@interface KZ_View (KZ_FrameBinding)

//只支持 KZ_LayoutAttribute_Left KZ_LayoutAttribute_Right KZ_LayoutAttribute_Top KZ_LayoutAttribute_Bottom KZ_LayoutAttribute_Width KZ_LayoutAttribute_Height KZ_LayoutAttribute_CenterX KZ_LayoutAttribute_CenterY
- (void)kz_addConstraintsUseFrameWithAttribute:(KZ_LayoutAttribute)layoutAttribute;

@end
