//
//  MultiViewController.h
//  KZ_MultiPageViewController_iOS
//
//  Created by Kieron Zhang on 2018/5/9.
//  Copyright © 2018年 Kieron Zhang. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface MultiViewController : UIViewController <UITableViewDelegate, UITableViewDataSource> {
    UITableView *multiTableView;
}
@property (nonatomic, assign) int index;

@end
