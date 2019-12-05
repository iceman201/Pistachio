//
//  NewsCollectionViewDelegate.h
//  Pistacchio
//
//  Created by Liguo Jiao on 4/12/19.
//  Copyright © 2019 Liguo Jiao. All rights reserved.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@interface NewsCollectionViewDelegate : NSObject <UICollectionViewDelegate, UICollectionViewDataSource, UICollectionViewDelegateFlowLayout>
- (instancetype)initWithTargetView:(UICollectionView *)view;
@end

NS_ASSUME_NONNULL_END
