//
//  MultiViewController.m
//  KZ_MultiPageViewController_iOS
//
//  Created by Kieron Zhang on 2018/5/9.
//  Copyright © 2018年 Kieron Zhang. All rights reserved.
//

#import "MultiViewController.h"
#import <KZ_Constraints_iOS/KZ_Constraints.h>

@interface MultiViewController ()

@end

@implementation MultiViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    NSLog(@"viewDidLoad");
    
    multiTableView = [[UITableView alloc] initWithFrame:self.view.bounds];
    multiTableView.delegate = self;
    multiTableView.dataSource = self;
    [self.view addSubview:multiTableView];
    [multiTableView kz_addConstraintsUseFrameWithAttribute:KZ_LayoutAttribute_EdgeInsets];
}

- (void)viewWillAppear:(BOOL)animated {
    [super viewWillAppear:animated];
    NSLog(@"viewWillAppear, %d", self.index);
}

- (void)viewDidAppear:(BOOL)animated {
    [super viewDidAppear:animated];
    NSLog(@"viewDidAppear, %d", self.index);
}

- (void)viewWillDisappear:(BOOL)animated {
    [super viewWillDisappear:animated];
    NSLog(@"viewWillDisappear, %d", self.index);
}

- (void)viewDidDisappear:(BOOL)animated {
    [super viewDidDisappear:animated];
    NSLog(@"viewDidDisappear, %d", self.index);
}

#pragma mark UITableViewDelegate
- (NSInteger)tableView:(UITableView *)tableView numberOfRowsInSection:(NSInteger)section {
    return 100;
}

- (UITableViewCell *)tableView:(UITableView *)tableView cellForRowAtIndexPath:(NSIndexPath *)indexPath {
    static NSString *NameCell = @"NameCell";
    UITableViewCell *cell = [tableView dequeueReusableCellWithIdentifier:NameCell];
    if (!cell) {
        cell = [[UITableViewCell alloc] initWithStyle:UITableViewCellStyleDefault reuseIdentifier:NameCell];
    }
    cell.textLabel.text = [NSString stringWithFormat:@"%d - %d", self.index, (int)indexPath.row];
    return cell;
}

- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
}

@end
