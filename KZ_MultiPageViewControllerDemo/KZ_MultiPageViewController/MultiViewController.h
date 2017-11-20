//
//  MultiViewController.h
//  KZ_MultiPageViewController
//
//  Created by Kieron Zhang on 2016/12/24.
//  Copyright © 2016年 Kieron Zhang. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface MultiViewController : UIViewController <UITableViewDelegate, UITableViewDataSource> {
    UITableView *multiTableView;
}
@property (nonatomic, assign) int index;

@end
