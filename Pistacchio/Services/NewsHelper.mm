//
//  NewsHelper.m
//  Pistacchio
//
//  Created by Liguo Jiao on 30/11/19.
//  Copyright © 2019 Liguo Jiao. All rights reserved.
//

#import "NewsHelper.h"
#import "macros.h"

@interface NewsHelper()

@end

@implementation NewsHelper
{
    std::shared_ptr<std::vector<news_by_topic::Doc>> docs;
}

- (instancetype)init:(NSString *)apiUrl
{
    self = [super init];
    if (self)
    {
        self.apiUrl = apiUrl;
        [self fetchAllNewsData];
    }
    return self;
}

- (void)fetchAllNewsData
{
    NSURLRequest *request = [[NSURLRequest alloc] initWithURL:[NSURL URLWithString:self.apiUrl]];
    NSURLSession *session = [NSURLSession sharedSession];
    WEAK_SELF;
    NSURLSessionDataTask *task = [session dataTaskWithRequest:request completionHandler:^(NSData * _Nullable data, NSURLResponse * _Nullable response, NSError * _Nullable error) {
        STRONG_SELF_OR_RETURN;
        if (data != nil)
        {
            NSString *jsonString = [[NSString alloc] initWithData:data encoding:NSUTF8StringEncoding];
            const char * _Nullable text = [jsonString UTF8String];

            news_by_topic::json data = news_by_topic::json::parse(text);

            auto news = data.get<news_by_topic::Welcome>();
            self->docs = news.get_response()->get_docs();
        }
    }];
    [task resume];
}

- (void)gaga
{
    
}

@end
