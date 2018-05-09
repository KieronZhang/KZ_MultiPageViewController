//
//  KZ_ConstraintUtils.h
//  KZ_Constraints
//
//  Created by Kieron Zhang on 2017/5/11.
//  Copyright © 2017年 Kieron Zhang. All rights reserved.
//

#import <Foundation/Foundation.h>
#if TARGET_OS_IPHONE
#import <UIKit/UIKit.h>
#define KZ_View UIView
#define KZ_EdgeInsets UIEdgeInsets
#elif TARGET_OS_MAC
#import <Cocoa/Cocoa.h>
#define KZ_View NSView
#define KZ_EdgeInsets NSEdgeInsets
#endif

typedef NS_OPTIONS(NSInteger, KZ_LayoutAttribute) {
    KZ_LayoutAttribute_NoAttribute = 0,
    KZ_LayoutAttribute_Left = 1 << 0,
    KZ_LayoutAttribute_Right = 1 << 1,
    KZ_LayoutAttribute_Top = 1 << 2,
    KZ_LayoutAttribute_Bottom = 1 << 3,
    KZ_LayoutAttribute_Leading = 1 << 4,
    KZ_LayoutAttribute_Trailing = 1 << 5,
    KZ_LayoutAttribute_Width = 1 << 6,
    KZ_LayoutAttribute_Height = 1 << 7,
    KZ_LayoutAttribute_CenterX = 1 << 8,
    KZ_LayoutAttribute_CenterY = 1 << 9,
    KZ_LayoutAttribute_Baseline = 1 << 10,
    
#if (__IPHONE_OS_VERSION_MIN_REQUIRED >= 80000) || (__MAC_OS_X_VERSION_MIN_REQUIRED >= 101100)
    KZ_LayoutAttribute_LastBaseline = 1 << 11,
    KZ_LayoutAttribute_FirstBaseline = 1 << 12,
#endif

#if (__IPHONE_OS_VERSION_MIN_REQUIRED >= 80000)
    KZ_LayoutAttribute_LeftMargin = 1 << 13,
    KZ_LayoutAttribute_RightMargin = 1 << 14,
    KZ_LayoutAttribute_TopMargin = 1 << 15,
    KZ_LayoutAttribute_BottomMargin = 1 << 16,
    KZ_LayoutAttribute_LeadingMargin = 1 << 17,
    KZ_LayoutAttribute_TrailingMargin = 1 << 18,
    KZ_LayoutAttribute_CenterXWithinMargins = 1 << 19,
    KZ_LayoutAttribute_CenterYWithinMargins = 1 << 20,
#endif
    
    KZ_LayoutAttribute_Center = (KZ_LayoutAttribute_CenterX | KZ_LayoutAttribute_CenterY),
    KZ_LayoutAttribute_Size = (KZ_LayoutAttribute_Width | KZ_LayoutAttribute_Height),
    KZ_LayoutAttribute_EdgeInsets = (KZ_LayoutAttribute_Left | KZ_LayoutAttribute_Right | KZ_LayoutAttribute_Top | KZ_LayoutAttribute_Bottom),
};

@interface KZ_ConstraintUtils : NSObject

+ (NSArray *)transLayoutAttributes:(KZ_LayoutAttribute)layoutAttribute;
+ (NSLayoutAttribute)transToLayoutAttribute:(KZ_LayoutAttribute)layoutAttribute;
+ (KZ_LayoutAttribute)transLayoutAttribute:(NSLayoutAttribute)layoutAttribute;
+ (KZ_View *)commonSuperview:(KZ_View *)view1 view2:(KZ_View *)view2;

+ (CGFloat)constantWithValue:(NSValue *)value attribute:(NSLayoutAttribute)layoutAttribute;
+ (id)transValue:(const char *)type, ...;

@end
