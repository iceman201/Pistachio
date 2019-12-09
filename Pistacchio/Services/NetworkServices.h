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
@required
- (void)serviceStart:(BOOL)success;
@optional
- (void)didReceiveNewsData:(std::shared_ptr<std::vector<news_by_topic::Doc>>)news;
@end

@interface NetworkServices:NSObject
@property (nonatomic, weak) id<NetworkServicesDelegate> delegate;

- (std::shared_ptr<std::vector<news_by_topic::Doc>>)getNewsData;
@end

NS_ASSUME_NONNULL_END
