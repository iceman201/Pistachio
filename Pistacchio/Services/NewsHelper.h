//
//  NewsHelper.h
//  Pistacchio
//
//  Created by Liguo Jiao on 30/11/19.
//  Copyright © 2019 Liguo Jiao. All rights reserved.
//

#import <UIKit/UIkit.h>

#include "NewsTopic.hpp"
#include <iostream>
#include <iomanip>
#include <string>
#include <ostream>

NS_ASSUME_NONNULL_BEGIN

@interface NewsHelper : NSObject
@property (nonatomic) NSString *apiUrl;

- (instancetype)init:(NSString *)apiUrl;
- (std::shared_ptr<std::vector<news_by_topic::Doc>>)getArticles;
@end
NS_ASSUME_NONNULL_END
