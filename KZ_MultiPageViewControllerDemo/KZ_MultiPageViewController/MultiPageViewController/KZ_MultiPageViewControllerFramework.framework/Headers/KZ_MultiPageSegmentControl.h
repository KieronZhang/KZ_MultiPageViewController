//
//  KZ_MultiPageSegmentControl.h
//  KZ_MultiPageViewController
//
//  Created by Kieron Zhang on 2016/12/24.
//  Copyright © 2016年 Kieron Zhang. All rights reserved.
//

#import <UIKit/UIKit.h>

typedef NS_ENUM(NSInteger, KZ_MultiPageTitleType) {
    KZ_MultiPageTitleType_AutoSize, //自动匹配文字宽度
    KZ_MultiPageTitleType_Average, //固定宽度
};

typedef NS_ENUM(NSInteger, KZ_MultiPageMovingType) {
    KZ_MultiPageMovingType_Translation, //滑块移动
    KZ_MultiPageMovingType_Stretch, //滑块拉伸
};

typedef NS_ENUM(NSInteger, KZ_MultiPageMovingTransType) {
    KZ_MultiPageMovingTransType_Whole, //颜色整体渐变
    KZ_MultiPageMovingTransType_Part, //颜色部分渐变
};

@class KZ_MultiPageSegmentControl;

@protocol KZ_MultiPageSegmentControlDelegate <NSObject>

- (void)multiPageSegmentControl:(KZ_MultiPageSegmentControl *)segmentControl didSelectAtIndex:(int)index animated:(BOOL)animated;

@optional
//下面可以针对不同的index设置不同的高亮和普通的颜色值和字体，（可选，如果不实现代理则可以统一设置颜色和字体大小）
- (UIFont *)multiPageSegmentControl:(KZ_MultiPageSegmentControl *)segmentControl highlightFontForIndex:(int)index;
- (UIFont *)multiPageSegmentControl:(KZ_MultiPageSegmentControl *)segmentControl normalFontForIndex:(int)index;

- (UIColor *)multiPageSegmentControl:(KZ_MultiPageSegmentControl *)segmentControl highlightTextColorForIndex:(int)index;
- (UIColor *)multiPageSegmentControl:(KZ_MultiPageSegmentControl *)segmentControl normalTextColorForIndex:(int)index;
- (UIColor *)multiPageSegmentControl:(KZ_MultiPageSegmentControl *)segmentControl movingViewColorForIndex:(int)index;

@end

@interface KZ_MultiPageSegmentControl : UIView <UICollectionViewDelegate, UICollectionViewDataSource, UICollectionViewDelegateFlowLayout> {
    UICollectionView *segmentCollectionView;
    UIView *movingView;
    NSMutableArray *itemsArray;
    NSMutableArray *itemWidthArray;
    UIView *sepView;
}
@property (nonatomic, weak) id<KZ_MultiPageSegmentControlDelegate> delegate;
@property (nonatomic, assign) int selectIndex;
@property (nonatomic, assign) KZ_MultiPageTitleType type;
@property (nonatomic, assign) KZ_MultiPageMovingType movingType;
@property (nonatomic, assign) KZ_MultiPageMovingTransType movingTransType;
@property (nonatomic, assign) BOOL changeSelectAnimated; //点击时是否有动画，默认yes

@property (nonatomic, assign) float titleDistance; //标题之间的间距，只有在type是KZ_MultiPageTitleType_AutoSize时有效
@property (nonatomic, assign) float sideLeftWidth; //左侧的contentInsert
@property (nonatomic, assign) float sideRightWidth; //右侧的contentInsert
@property (nonatomic, strong) UIColor *highlightTextColor; //高亮的textColor，默认redColor
@property (nonatomic, strong) UIColor *normalTextColor; //正常的textColor，默认blackColor
@property (nonatomic, strong) UIFont *highlightFont; //高亮的字体，默认16
@property (nonatomic, strong) UIFont *normalFont; //正常的字体，默认16
@property (nonatomic, strong) UIColor *movingViewColor; //下面移动条的颜色，默认redColor
@property (nonatomic, assign) float movingViewHeight; //移动条的高度，默认4
@property (nonatomic, assign) float movingViewWidth; //移动条的宽度，如果设置为0，则自动匹配文字宽度
@property (nonatomic, assign) float movingViewSideWidth; //移动条距离文字左右的宽度，只有当movingViewWidth是0时有效
@property (nonatomic, assign) BOOL movingViewRoundCorner; //移动条是否显示圆角
@property (nonatomic, strong) UIColor *sepViewColor; //分割线颜色
@property (nonatomic, assign) BOOL sepViewHidden; //分割线是否隐藏

- (id)initWithFrame:(CGRect)frame delegate:(id<KZ_MultiPageSegmentControlDelegate>)delegate;
- (void)resetItems:(NSArray *)items type:(KZ_MultiPageTitleType)type;
- (void)setSelectIndex:(int)selectIndex animated:(BOOL)animated;
- (void)setCurrentIndex:(int)index radio:(float)radio;
- (void)reloadData;

@end
