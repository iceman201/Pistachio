//
//  NewsHelper.h
//  Pistacchio
//
//  Created by Liguo Jiao on 30/11/19.
//  Copyright © 2019 Liguo Jiao. All rights reserved.
//

#import <UIKit/UIkit.h>
#include "News.hpp"

NS_ASSUME_NONNULL_BEGIN

@class NetworkServicesDelegate;
@protocol NetworkServicesDelegate <NSObject>
- (void)serviceStart;
@end

@interface NetworkServices:NSObject <NetworkServicesDelegate>
- (void)setDelegate:(id)delegate;
- (std::shared_ptr<std::vector<news_by_topic::Doc>>)getNewsTopic;
@end

NS_ASSUME_NONNULL_END
