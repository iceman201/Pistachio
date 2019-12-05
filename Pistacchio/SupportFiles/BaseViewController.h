//
//  BaseViewController.h
//  Pistacchio
//
//  Created by Liguo Jiao on 30/11/19.
//  Copyright © 2019 Liguo Jiao. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <PureLayout/PureLayout.h>
#import "macros.h"
#include "NetworkServices.h"
#import "SharedConstants.h"
#import "Pistacchio-Swift.h"

NS_ASSUME_NONNULL_BEGIN

@interface BaseViewController : UIViewController
@property (nonatomic, strong) NetworkServices *services;
@property (nonatomic, strong) UIView *topBar;

- (instancetype)initWithNetworkServices:(NetworkServices *)services;
- (void)shouldShowTopBar:(BOOL)show;
@end

NS_ASSUME_NONNULL_END
