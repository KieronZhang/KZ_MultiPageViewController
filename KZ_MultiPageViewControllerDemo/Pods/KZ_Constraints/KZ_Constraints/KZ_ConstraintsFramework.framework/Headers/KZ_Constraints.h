//
//  KZ_Constraints.h
//  KZ_Constraints
//
//  Created by Kieron Zhang on 2017/5/15.
//  Copyright © 2017年 Kieron Zhang. All rights reserved.
//

#import "UIView+KZ_Constraints.h"
#import "UIView+KZ_FrameBinding.h"
#import "NSArray+KZ_Constraints.h"
#import "KZ_ConstraintAttribute.h"
#import "KZ_ConstraintAttribute+KZ_Extend.h"
#import "KZ_ConstraintUtils.h"

#define kz_TransValue(value) [KZ_ConstraintUtils transValue:@encode(__typeof__((value))), (value)]

#define kz_equalTo(value) equalTo(kz_TransValue(value))
#define kz_greaterThanOrEqualTo greaterThanOrEqualTo(kz_TransValue(value))
#define kz_lessThanOrEqualTo lessThanOrEqualTo(kz_TransValue(value))

#define kz_offset offset(kz_TransValue(value))
#define kz_multipier multipier(kz_TransValue(value))
