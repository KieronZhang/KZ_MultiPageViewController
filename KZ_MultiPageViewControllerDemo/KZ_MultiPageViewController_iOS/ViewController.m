//
//  ViewController.m
//  KZ_MultiPageViewController_iOS
//
//  Created by Kieron Zhang on 2018/5/9.
//  Copyright © 2018年 Kieron Zhang. All rights reserved.
//

#import "ViewController.h"
#import "MultiViewController.h"
#import <KZ_Categories_iOS/UIView+KZ_Frame.h>
#import <KZ_MacroDefinition_iOS/KZ_MacroDefinition.h>
#import <KZ_MultiPageViewController_iOS/KZ_MultiPageViewController.h>

@interface ViewController () <KZ_MultiPageViewControllerDelegate> {
    NSArray *highlightTextColorArray;
    NSArray *normalTextColorArray;
    
    KZ_MultiPageViewController *multiPageViewController;
}

@end

@implementation ViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    self.view.backgroundColor = [UIColor whiteColor];
    self.automaticallyAdjustsScrollViewInsets = NO;
    
    highlightTextColorArray = @[[UIColor redColor], [UIColor blueColor], [UIColor blackColor], [UIColor brownColor], [UIColor purpleColor], [UIColor magentaColor], [UIColor redColor], [UIColor blueColor], [UIColor blackColor], [UIColor brownColor], [UIColor purpleColor], [UIColor magentaColor]];
    normalTextColorArray = @[[UIColor yellowColor], [UIColor cyanColor], [UIColor orangeColor], [UIColor greenColor], [UIColor lightGrayColor], [UIColor darkGrayColor], [UIColor yellowColor], [UIColor cyanColor], [UIColor orangeColor], [UIColor greenColor], [UIColor lightGrayColor], [UIColor darkGrayColor]];
    
    NSMutableArray *array = [NSMutableArray arrayWithCapacity:0];
    NSArray *titleArray = @[@"早餐前", @"早餐后", @"午餐前", @"午餐后", @"晚餐前", @"晚餐后", @"早餐前", @"早餐后", @"午餐前", @"午餐后", @"晚餐前", @"晚餐后"];
    for (int i = 0; i < titleArray.count; i++) {
        MultiViewController *viewController = [[MultiViewController alloc] init];
        viewController.index = i;
        [array addObject:viewController];
    }
    multiPageViewController = [[KZ_MultiPageViewController alloc] init];
    multiPageViewController.delegate = self;
    multiPageViewController.itemDistance = 20.0f;
//    multiPageViewController.segmentViewHeight = 44;
    multiPageViewController.multiPageSegmentControl.movingType = KZ_MultiPageMovingType_Stretch;
    multiPageViewController.multiPageSegmentControl.movingTransType = KZ_MultiPageMovingTransType_Part;
//    multiPageViewController.multiPageSegmentControl.highlightTextColor = [UIColor blueColor];
//    multiPageViewController.multiPageSegmentControl.normalTextColor = [UIColor blackColor];
    multiPageViewController.multiPageSegmentControl.highlightFont = [UIFont systemFontOfSize:18.0f];
    multiPageViewController.multiPageSegmentControl.normalFont = [UIFont systemFontOfSize:10.0f];
    multiPageViewController.multiPageSegmentControl.titleDistance = 10;
//    multiPageViewController.multiPageSegmentControl.movingViewWidth = 20;
//    multiPageViewController.multiPageSegmentControl.movingViewSideWidth = 10;
//    multiPageViewController.multiPageSegmentControl.sideLeftWidth = 50;
//    multiPageViewController.multiPageSegmentControl.sideRightWidth = 50;
    multiPageViewController.viewFrame = CGRectMake(0, KZ_Status_Height, self.view.width, self.view.height - KZ_Status_Height);
    [multiPageViewController resetSegmentTitles:titleArray type:KZ_MultiPageTitleType_AutoSize];
    [multiPageViewController resetViewControllers:array];
    [self addChildViewController:multiPageViewController];
    [self.view addSubview:multiPageViewController.view];
    
    UIButton *button = [UIButton buttonWithType:UIButtonTypeCustom];
    button.backgroundColor = [UIColor yellowColor];
    button.frame = CGRectMake(self.view.width - 120, 20, 100, 100);
    [button addTarget:self action:@selector(buttonTapped) forControlEvents:UIControlEventTouchUpInside];
//    [self.view addSubview:button];
}

- (void)buttonTapped {
//    if (multiPageViewController.multiPageSegmentControl.movingViewHeight == 4) {
//        multiPageViewController.multiPageSegmentControl.movingViewHeight = 10;
//        return;
//    }
//    multiPageViewController.multiPageSegmentControl.movingViewHeight = 4;

//    if (multiPageViewController.view.height < self.view.height) {
//        [multiPageViewController.view mas_updateConstraints:^(MASConstraintMaker *make) {
//            make.height.mas_equalTo(@(self.view.height));
//        }];
////        multiPageViewController.view.height = self.view.height;
//        return;
//    }
//    [multiPageViewController.view mas_updateConstraints:^(MASConstraintMaker *make) {
//        make.height.mas_equalTo(@(self.view.height / 2));
//    }];
//    multiPageViewController.view.height = self.view.height / 2;
}

#pragma mark KZ_MultiPageViewControllerDelegate
- (UIFont *)multiPageViewController:(KZ_MultiPageViewController *)controller highlightFontForIndex:(int)index {
    return [UIFont systemFontOfSize:index * 2 + 10];
}

- (UIFont *)multiPageViewController:(KZ_MultiPageViewController *)controller normalFontForIndex:(int)index {
    return [UIFont systemFontOfSize:(6 - index) + 5];
}

- (UIColor *)multiPageViewController:(KZ_MultiPageViewController *)controller highlightTextColorForIndex:(int)index {
    return highlightTextColorArray[index];
}

- (UIColor *)multiPageViewController:(KZ_MultiPageViewController *)controller normalTextColorForIndex:(int)index {
    return normalTextColorArray[index];
}

- (UIColor *)multiPageViewController:(KZ_MultiPageViewController *)controller movingViewColorForIndex:(int)index {
    return highlightTextColorArray[index];
}

- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
}

@end
