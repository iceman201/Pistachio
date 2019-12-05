//
//  BaseViewController.m
//  Pistacchio
//
//  Created by Liguo Jiao on 30/11/19.
//  Copyright © 2019 Liguo Jiao. All rights reserved.
//

#import "BaseViewController.h"


@interface BaseViewController ()

@end

@implementation BaseViewController

- (instancetype)initWithNetworkServices:(NetworkServices *)services
{
    self = [super init];
    if (self)
    {
        self.services = services;
        [self shouldShowTopBar:NO];
    }
    return self;
}

- (void)loadView
{
    [super loadView];
    UIView *topBar = [[UIView alloc] initForAutoLayout];
    {
        [topBar setBackgroundColor:[UIColor greenColor]];
        [self.view addSubview:topBar];
        [topBar autoMatchDimension:ALDimensionWidth toDimension:ALDimensionWidth ofView:self.view];
        [topBar autoPinEdgeToSuperviewEdge:ALEdgeTop];
        [topBar autoSetDimension:ALDimensionHeight toSize:150];
        self.topBar = topBar;
    }
}

- (void)viewDidLoad
{
    [super viewDidLoad];
}

- (void)shouldShowTopBar:(BOOL)show
{
    self.topBar.hidden = !show;
}

@end
