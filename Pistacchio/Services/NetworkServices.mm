//
//  NewsHelper.m
//  Pistacchio
//
//  Created by Liguo Jiao on 30/11/19.
//  Copyright © 2019 Liguo Jiao. All rights reserved.
//

#import "NetworkServices.h"
#import "macros.h"

@interface NetworkServices()
@end

@implementation NetworkServices
{
    std::shared_ptr<std::vector<news_by_topic::Doc>> _news;
}

- (instancetype)init
{
    self = [super init];
    if (self)
    {
        dispatch_async(dispatch_get_global_queue(DISPATCH_QUEUE_PRIORITY_DEFAULT, 0), ^{
            [self fetchAllNewsData:^(BOOL success, std::shared_ptr<std::vector<news_by_topic::Doc> > news) {
                dispatch_async(dispatch_get_main_queue(), ^{
                    if (success)
                    {
                        [self.delegate serviceStart:YES];
                        if ([self.delegate respondsToSelector:@selector(didReceiveNewsData:)]) {
                            [self.delegate didReceiveNewsData:news];
                        }
                    }
                    else
                    {
                        [self.delegate serviceStart:NO];
                    }
                });
            }];
        });
    }
    return self;
}

- (NSString *)getServerAddress
{
    NSString *path = [[NSBundle mainBundle] pathForResource:@"Services" ofType:@"plist"];
    NSDictionary *service = [NSDictionary dictionaryWithContentsOfFile:path];
    NSString *address = [service valueForKey:@"ArticleSearch"];
    NSString *topic = @"finance&page";
    NSString *token = @"DzA9CAMEDhbyT6AYhW0CzdftgT623Fni";
    NSString *apiUrl = [NSString stringWithFormat:@"%@?page=50&q=%@&sort=relevance&api-key=%@", address, topic, token];
    return apiUrl;
}

- (void)fetchAllNewsData:(void(^) (BOOL success, std::shared_ptr<std::vector<news_by_topic::Doc>> news))finished
{
    NSURLRequest *request = [[NSURLRequest alloc] initWithURL:[NSURL URLWithString:[self getServerAddress]]];
    NSURLSession *session = [NSURLSession sharedSession];
    WEAK_SELF;
    NSURLSessionDataTask *task = [session dataTaskWithRequest:request completionHandler:^(NSData * _Nullable data, NSURLResponse * _Nullable response, NSError * _Nullable error) {
        STRONG_SELF_OR_RETURN;
        NSHTTPURLResponse *httpResponse = (NSHTTPURLResponse *)response;
        switch ([httpResponse statusCode])
        {
            case 200:
                if (data != nil)
                {
                    NSString *jsonString = [[NSString alloc] initWithData:data encoding:NSUTF8StringEncoding];
                    const char * _Nullable text = [jsonString UTF8String];
                    news_by_topic::json data = news_by_topic::json::parse(text);
                    auto news = data.get<news_by_topic::Welcome>();
                    auto result = news.get_response() -> get_docs();
                    self->_news = result;
                    if (result != nullptr)
                    {
                        finished(YES, result);
                        break;
                    }
                }
            default:
                finished(NO, NULL);
                break;
        };
    }];
    [task resume];
}

- (std::shared_ptr<std::vector<news_by_topic::Doc> >)getNewsData
{
    return _news;
}

@end
