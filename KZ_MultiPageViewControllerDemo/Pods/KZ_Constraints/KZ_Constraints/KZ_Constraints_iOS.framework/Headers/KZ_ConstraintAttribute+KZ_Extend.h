//
//  KZ_ConstraintAttribute+KZ_Extend.h
//  KZ_Constraints
//
//  Created by Kieron Zhang on 2017/10/13.
//  Copyright © 2017年 Kieron Zhang. All rights reserved.
//

#import "KZ_ConstraintAttribute.h"

@interface KZ_ConstraintAttribute (KZ_Extend)

- (KZ_ConstraintAttribute *(^)(id value))equalTo;
- (KZ_ConstraintAttribute *(^)(id value))greaterThanOrEqualTo;
- (KZ_ConstraintAttribute *(^)(id value))lessThanOrEqualTo;

- (KZ_ConstraintAttribute *(^)(id offset))offset;
- (KZ_ConstraintAttribute *(^)(CGFloat multipier))multipier;

- (void)binding;

- (KZ_ConstraintAttribute *(^)(id value))kz_equalTo;
- (KZ_ConstraintAttribute *(^)(id value))kz_greaterThanOrEqualTo;
- (KZ_ConstraintAttribute *(^)(id value))kz_lessThanOrEqualTo;

- (KZ_ConstraintAttribute *(^)(id offset))kz_offset;
- (KZ_ConstraintAttribute *(^)(CGFloat multipier))kz_multipier;

@end
