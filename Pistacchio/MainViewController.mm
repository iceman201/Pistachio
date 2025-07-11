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
    [self shouldShowTopBar:YES];

    UIView *newsContentContainer = [[UIView alloc] initForAutoLayout];
    newsContentContainer.backgroundColor = [UIColor greenColor];
    [self.view addSubview:newsContentContainer];
    [newsContentContainer autoPinEdge:ALEdgeTop toEdge:ALEdgeBottom ofView:self.topBar withOffset:DEFAULT_PADDING*2];
    [newsContentContainer autoMatchDimension:ALDimensionWidth toDimension:ALDimensionWidth ofView:self.view];
    [newsContentContainer autoPinEdgeToSuperviewSafeArea:ALEdgeBottom];
    [self.view setNeedsDisplay];
    {
        UICollectionViewFlowLayout *layout = [[UICollectionViewFlowLayout alloc] init];
        [layout setScrollDirection:UICollectionViewScrollDirectionVertical];

        UICollectionView *view = [[UICollectionView alloc] initWithFrame:CGRectZero collectionViewLayout:layout];
        NewsCollectionViewDelegate *nDelegate = [[NewsCollectionViewDelegate alloc] initWithTargetView:view];
        self.newsCollectionDelegate = nDelegate;
        {
            [view registerClass:[NewsCViewCell class] forCellWithReuseIdentifier:NEWS_COLLECTION_CELL_ID];
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
