//
//  ViewController.m
//  Pistacchio
//
//  Created by Liguo Jiao on 29/11/19.
//  Copyright © 2019 Liguo Jiao. All rights reserved.
//

#import "MainViewController.h"

@interface MainViewController ()

@end

@implementation MainViewController

- (void)viewDidLoad
{
    [super viewDidLoad];

    [self.view setBackgroundColor:[UIColor redColor]];

    UIButton *ha = [[UIButton alloc] initForAutoLayout];
    [ha addTarget:self action:@selector(tapTest) forControlEvents:UIControlEventTouchUpInside];
    [ha setBackgroundColor:[UIColor yellowColor]];
    [self.view addSubview:ha];
    [ha autoPinEdgeToSuperviewEdge:ALEdgeLeading];
    [ha autoPinEdgeToSuperviewEdge:ALEdgeTrailing];
    [ha autoPinEdgeToSuperviewSafeArea:ALEdgeTop];
    [ha autoPinEdgeToSuperviewSafeArea:ALEdgeBottom];
//    self.services 
}

- (void)tapTest
{
//    [self.services serviceStart];
}


@end
