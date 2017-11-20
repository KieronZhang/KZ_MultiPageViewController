//
//  KZ_MultiPageSegmentControlCell.h
//  KZ_MultiPageViewController
//
//  Created by Kieron Zhang on 2016/12/24.
//  Copyright © 2016年 Kieron Zhang. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface KZ_MultiPageSegmentControlCell : UICollectionViewCell {
    UILabel *titleLabel;
}
@property (nonatomic, strong) NSString *title;
@property (nonatomic, strong) UIColor *textColor;
@property (nonatomic, assign) float scale;
@property (nonatomic, assign) int index;

- (void)setTitle:(NSString *)title font:(UIFont *)font;
+ (CGFloat)widthWithTitle:(NSString *)title font:(UIFont *)font;

@end
