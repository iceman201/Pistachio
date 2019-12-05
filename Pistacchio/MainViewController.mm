//
//  ViewController.m
//  Pistacchio
//
//  Created by Liguo Jiao on 29/11/19.
//  Copyright © 2019 Liguo Jiao. All rights reserved.
//

#import "MainViewController.h"
#import "NewsCollectionViewDelegate.h"

@interface MainViewController()
@property (nonatomic, strong) NewsCollectionViewDelegate *newsCollectionDelegate;
@end

@implementation MainViewController

- (void)loadView
{
    [super loadView];
    [self.view setBackgroundColor:[UIColor systemBackgroundColor]];

    UIView *newsContentContainer = [[UIView alloc] initForAutoLayout];
    newsContentContainer.backgroundColor = [UIColor greenColor];
    [self.view addSubview:newsContentContainer];
    [newsContentContainer autoPinEdgesToSuperviewSafeArea];
    {
        UICollectionViewFlowLayout *layout = [[UICollectionViewFlowLayout alloc] init];
        [layout setScrollDirection:UICollectionViewScrollDirectionVertical];

        UICollectionView *view = [[UICollectionView alloc] initWithFrame:CGRectZero collectionViewLayout:layout];
        NewsCollectionViewDelegate *nDelegate = [[NewsCollectionViewDelegate alloc] initWithTargetView:view];
        self.newsCollectionDelegate = nDelegate;
        {
            [view registerClass:[UICollectionViewCell class] forCellWithReuseIdentifier:NEWS_COLLECTION_CELL_ID];
            view.backgroundColor = [UIColor cyanColor];
            [self.view addSubview:view];
            [view autoPinEdgesToSuperviewSafeArea];
        }
    }
}

- (void)viewDidLoad
{
    [super viewDidLoad];

}

- (void)tapTest
{
//    [self.services serviceStart];
}


@end
