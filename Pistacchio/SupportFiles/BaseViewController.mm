//
//  BaseViewController.m
//  Pistacchio
//
//  Created by Liguo Jiao on 30/11/19.
//  Copyright © 2019 Liguo Jiao. All rights reserved.
//

#import "BaseViewController.h"


@interface BaseViewController ()
@property (nonatomic, weak) UIButton *backButton;
@property (nonatomic, weak) UIImageView *logoView;
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
    [topBar setBackgroundColor:[UIColor whiteColor]];
    [self.view addSubview:topBar];
    [topBar autoMatchDimension:ALDimensionWidth toDimension:ALDimensionWidth ofView:self.view];
    [topBar autoPinEdgeToSuperviewEdge:ALEdgeTop];
    [topBar autoSetDimension:ALDimensionHeight toSize:88];
    self.topBar = topBar;
    {
        UIButton *back = [[UIButton alloc] initForAutoLayout];
//        [back setTitle:@"back" forState:UIControlStateNormal];
        [back setImage:[UIImage systemImageNamed:@"arrow.left"] forState:UIControlStateNormal];
        [back setTintColor:[UIColor lightGrayColor]];
        [back addTarget:self action:@selector(tapBack) forControlEvents:UIControlEventTouchUpInside];
        [topBar addSubview:back];
        [back autoPinEdgeToSuperviewEdge:ALEdgeLeading withInset:DEFAULT_PADDING];
        [back autoAlignAxisToSuperviewAxis:ALAxisHorizontal];
        [back autoSetDimensionsToSize:CGSizeMake(DEFAULT_PADDING*5, DEFAULT_PADDING*5)];
        self.backButton = back;
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

- (void)tapBack
{

}

@end
