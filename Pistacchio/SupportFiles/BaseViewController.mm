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
    if (self) {
        self.services = services;
    }
    return self;
}

- (void)viewDidLoad {
    [super viewDidLoad];
    
}

@end
