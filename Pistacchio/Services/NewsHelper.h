//
//  NewsHelper.h
//  Pistacchio
//
//  Created by Liguo Jiao on 30/11/19.
//  Copyright © 2019 Liguo Jiao. All rights reserved.
//

#import <UIKit/UIkit.h>


//- (instancetype)init:(NSString *)apiUrl;
//- (std::shared_ptr<std::vector<news_by_topic::Doc>>)getArticles;
NS_ASSUME_NONNULL_BEGIN

@class NewsHelper;
@protocol NetworkServices <NSObject>
- (void)serviceStart;
@end

@interface NewsHelper: NSObject <NetworkServices>
- (void)setDelegate:(id)delegate;
@end

NS_ASSUME_NONNULL_END
