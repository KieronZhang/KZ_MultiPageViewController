//
//  KZ_MultiPageViewController.h
//  KZ_MultiPageViewController
//
//  Created by Kieron Zhang on 2016/12/24.
//  Copyright © 2016年 Kieron Zhang. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "KZ_MultiPageSegmentControl.h"

@class KZ_MultiPageViewController;

@protocol KZ_MultiPageViewControllerDelegate <NSObject>

@optional
- (void)multiPageViewControllerWillBeginDragging:(KZ_MultiPageViewController *)controller;
- (void)multiPageViewController:(KZ_MultiPageViewController *)controller scrollToIndex:(int)index radio:(float)radio;
- (void)multiPageViewController:(KZ_MultiPageViewController *)controller didSelectAtIndex:(int)index;

//下面可以针对不同的index设置不同的高亮和普通的颜色值和字体，（可选，如果不实现代理则可以统一设置颜色和字体大小）
- (UIFont *)multiPageViewController:(KZ_MultiPageViewController *)controller highlightFontForIndex:(int)index;
- (UIFont *)multiPageViewController:(KZ_MultiPageViewController *)controller normalFontForIndex:(int)index;

- (UIColor *)multiPageViewController:(KZ_MultiPageViewController *)controller highlightTextColorForIndex:(int)index;
- (UIColor *)multiPageViewController:(KZ_MultiPageViewController *)controller normalTextColorForIndex:(int)index;
- (UIColor *)multiPageViewController:(KZ_MultiPageViewController *)controller movingViewColorForIndex:(int)index;

@end

@interface KZ_MultiPageViewController : UIViewController {
    NSMutableArray *multiPageViewControllers;
}
@property (nonatomic, weak) id<KZ_MultiPageViewControllerDelegate> delegate;
@property (nonatomic, strong) KZ_MultiPageSegmentControl *multiPageSegmentControl;
@property (nonatomic, assign) float segmentViewHeight; //选择条的高度
@property (nonatomic, assign) CGRect viewFrame; //整体view的frame
@property (nonatomic, assign) int itemDistance; //controller之间的空隙
@property (nonatomic, assign) int selectIndex; //当前选择的位置
@property (nonatomic, assign) BOOL disappearSegmentView; //是否隐藏选择条
@property (nonatomic, assign) BOOL scrollEnabled; //是否可以滑动
@property (nonatomic, assign) BOOL bounces; //是否有回弹效果

//选择条的标题和viewControllers是一一对应的关系，数组大小需一致
- (void)resetSegmentTitles:(NSArray *)titles type:(KZ_MultiPageTitleType)type;
- (void)resetViewControllers:(NSArray *)viewControllers;
- (void)resetViewControllers:(NSArray *)viewControllers segmentTitles:(NSArray *)array type:(KZ_MultiPageTitleType)type;
- (void)setSelectIndex:(int)selectIndex animated:(BOOL)animated;
- (void)reloadData;

@end
