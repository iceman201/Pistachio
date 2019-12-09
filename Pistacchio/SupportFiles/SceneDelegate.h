//
//  SceneDelegate.h
//  Pistacchio
//
//  Created by Liguo Jiao on 29/11/19.
//  Copyright © 2019 Liguo Jiao. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "NetworkServices.h"

@interface SceneDelegate : UIResponder <UIWindowSceneDelegate, NetworkServicesDelegate>

@property (strong, nonatomic) UIWindow * window;

@end

