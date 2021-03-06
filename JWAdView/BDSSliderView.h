//
//  BDSSliderView.h
//  JWAdView
//
//  Created by jiajunwei on 2019/1/17.
//  Copyright © 2019年 中再融. All rights reserved.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@class BDSSliderView;
@protocol BDSSliderViewDelagete <NSObject>

- (void)BDSSliderView:(BDSSliderView *)sliderView didSelectItemAtIndex:(NSInteger)index;

@end

@interface BDSSliderView : UIView

/** 本地图片数组 */
@property (nonatomic, strong) NSArray<NSString *> *localizationImageNamesGroup;
/** 网络图片 url string 数组 */
@property (nonatomic, strong) NSArray<NSString *> *imageURLStringsGroup;
/** 占位图，用于网络未加载到图片时 */
@property (nonatomic, strong) UIImage *placeholderImage;
/** 是否无限循环,默认Yes */
@property (nonatomic,assign) BOOL infiniteLoop;
/** 是否自动滚动,默认Yes */
@property (nonatomic,assign) BOOL autoScroll;
/** 自动滚动间隔时间,默认2s */
@property (nonatomic, assign) CGFloat autoScrollTimeInterval;
/** item大小,默认宽高为本视图宽高0.9倍 */
@property (assign, nonatomic) CGSize itemSize;
/** item之间水平方向间距,默认10 */
@property (assign, nonatomic) CGFloat pageSpace;
/** 是否在只有一张图时隐藏pagecontrol，默认为YES */
@property(nonatomic) BOOL hidesForSinglePage;
/** 是否显示分页控件 */
@property (nonatomic, assign) BOOL showPageControl;
/** 当前分页控件小圆标颜色 */
@property (nonatomic, strong) UIColor *currentPageDotColor;
/** 其他分页控件小圆标颜色 */
@property (nonatomic, strong) UIColor *pageDotColor;
/** 当前分页控件小圆标图片 */
@property (nonatomic, strong) UIImage *currentPageDotImage;
/** 其他分页控件小圆标图片 */
@property (nonatomic, strong) UIImage *pageDotImage;
/** 分页控件距离轮播图的底部间距（在默认间距基础上）的偏移量 */
@property (nonatomic, assign) CGFloat pageControlBottomOffset;

@property (weak, nonatomic) id<BDSSliderViewDelagete> delegate;

/**
 本地图片卡片式轮播初始化

 @param frame frame
 @param localizationImageNamesGroup 本地图片数组
 @return 轮播view
 */
+ (BDSSliderView *)sliderViewWithFrame:(CGRect)frame localizationImageNamesGroup:(NSArray *)localizationImageNamesGroup;

/**
 网络图片轮播初始化

 @param frame frame
 @param imageURLStringsGroup 网络图片URL
 @return 轮播view
 */
+ (BDSSliderView *)sliderViewWithFrame:(CGRect)frame imageURLStringsGroup:(NSArray *)imageURLStringsGroup;

@end

NS_ASSUME_NONNULL_END

@interface BDSSliderViewCell : UICollectionViewCell

@property (strong, nonatomic) UIImageView *imageView;

@end

@interface BDSSliderViewPageControl : UIPageControl

/** 当前分页控件小圆标图片 */
@property (nonatomic, strong) UIImage *currentPageDotImage;
/** 其他分页控件小圆标图片 */
@property (nonatomic, strong) UIImage *pageDotImage;

@end
