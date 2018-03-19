//
//  KZ_ConstraintAttribute.h
//  KZ_Constraints
//
//  Created by Kieron Zhang on 2017/5/8.
//  Copyright © 2017年 Kieron Zhang. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "KZ_ConstraintUtils.h"

@interface KZ_ConstraintAttribute : NSObject

@property (nonatomic, weak, readonly) UIView *view;
@property (nonatomic, assign, readonly) KZ_LayoutAttribute layoutAttribute;
@property (nonatomic, strong, readonly) NSArray *viewArray;
@property (nonatomic, assign, readonly) NSLayoutAttribute toLayoutAttribute;

@property (nonatomic, strong, readonly) KZ_ConstraintAttribute *kz_left;
@property (nonatomic, strong, readonly) KZ_ConstraintAttribute *kz_right;
@property (nonatomic, strong, readonly) KZ_ConstraintAttribute *kz_top;
@property (nonatomic, strong, readonly) KZ_ConstraintAttribute *kz_bottom;
@property (nonatomic, strong, readonly) KZ_ConstraintAttribute *kz_leading;
@property (nonatomic, strong, readonly) KZ_ConstraintAttribute *kz_trailing;
@property (nonatomic, strong, readonly) KZ_ConstraintAttribute *kz_width;
@property (nonatomic, strong, readonly) KZ_ConstraintAttribute *kz_height;
@property (nonatomic, strong, readonly) KZ_ConstraintAttribute *kz_centerx;
@property (nonatomic, strong, readonly) KZ_ConstraintAttribute *kz_centery;
@property (nonatomic, strong, readonly) KZ_ConstraintAttribute *kz_baseline;

#if (__IPHONE_OS_VERSION_MIN_REQUIRED >= 80000)
@property (nonatomic, strong, readonly) KZ_ConstraintAttribute *kz_firstBaseline;
@property (nonatomic, strong, readonly) KZ_ConstraintAttribute *kz_lastBaseline;
@property (nonatomic, strong, readonly) KZ_ConstraintAttribute *kz_leftMargin;
@property (nonatomic, strong, readonly) KZ_ConstraintAttribute *kz_rightMargin;
@property (nonatomic, strong, readonly) KZ_ConstraintAttribute *kz_topMargin;
@property (nonatomic, strong, readonly) KZ_ConstraintAttribute *kz_bottomMargin;
@property (nonatomic, strong, readonly) KZ_ConstraintAttribute *kz_leadingMargin;
@property (nonatomic, strong, readonly) KZ_ConstraintAttribute *kz_trailingMargin;
@property (nonatomic, strong, readonly) KZ_ConstraintAttribute *kz_centerxWithinMargins;
@property (nonatomic, strong, readonly) KZ_ConstraintAttribute *kz_centeryWithinMargins;
#endif

@property (nonatomic, strong, readonly) KZ_ConstraintAttribute *kz_center;
@property (nonatomic, strong, readonly) KZ_ConstraintAttribute *kz_size;
@property (nonatomic, strong, readonly) KZ_ConstraintAttribute *kz_edgeInsets;

- (instancetype)initWithView:(UIView *)view layoutAttribute:(KZ_LayoutAttribute)layoutAttribute;
- (instancetype)initWithViewArray:(NSArray<UIView *> *)viewArray layoutAttribute:(KZ_LayoutAttribute)layoutAttribute;

- (void)addConstraintEqualTo:(id)value;
- (void)addConstraintEqualTo:(id)value offset:(id)offset;
- (void)addConstraintEqualTo:(id)value multipier:(CGFloat)multipier;
- (void)addConstraintEqualTo:(id)value offset:(id)offset multipier:(CGFloat)multipier;

- (void)addConstraintGreaterThanOrEqualTo:(id)value;
- (void)addConstraintGreaterThanOrEqualTo:(id)value offset:(id)offset;
- (void)addConstraintGreaterThanOrEqualTo:(id)value multipier:(CGFloat)multipier;
- (void)addConstraintGreaterThanOrEqualTo:(id)value offset:(id)offset multipier:(CGFloat)multipier;

- (void)addConstraintLessThanOrEqualTo:(id)value;
- (void)addConstraintLessThanOrEqualTo:(id)value offset:(id)offset;
- (void)addConstraintLessThanOrEqualTo:(id)value multipier:(CGFloat)multipier;
- (void)addConstraintLessThanOrEqualTo:(id)value offset:(id)offset multipier:(CGFloat)multipier;

@end
