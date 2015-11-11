/*
 ----------------------------------------------------------------------------
 *  文件名称:CCAdsPlayView
 *  文件作用:广告横幅滚动播放，目前只支持网络下载图片，依赖SDWebImage
 *  文件作者:Cole
 *  创建时间:2015-10-09
 ----------------------------------------------------------------------------
 */

#import <UIKit/UIKit.h>

typedef NS_ENUM(NSInteger,CCPageContolAliment) {
    /* 滚动点居中 */
    CCPageContolAlimentCenter,
    /* 滚动点居右 */
    CCPageContolAlimentRight,
    /* 滚动点隐藏 */
    CCPageContolAlimentNone
};

typedef void(^tapActionBlock)(NSInteger index);

@interface CCAdsPlayView : UIView<UIScrollViewDelegate>


/* 播放周期,默认五秒钟 如设置0则不播放 */
@property(nonatomic,assign)NSTimeInterval animationDuration;

/* 滚动点对齐方式，默认居中 */
@property(nonatomic,assign)CCPageContolAliment pageContolAliment;

/* 默认图片，下载未完成时显示 */
/* 注意：赋值必须写在Start方法之前，否则仍然为nil */
@property(nonatomic,strong)UIImage *placeHoldImage;

/* 数据源 **/
@property(nonatomic,copy)NSArray *dataArray;

/**
 *  初始化广告播放滚动View
 *
 *  @param rect       尺寸位置
 *  @param imageGroup 图片数据源
 */
+ (instancetype)adsPlayViewWithFrame:(CGRect)rect imageGroup:(NSArray *)imageGroup;

/**
 *  开始播放，默认三秒钟,点击响应block回调
 *
 *  @param block 回调，返回当前图片index，不需要回调则设置为nil
 */
- (void)startWithTapActionBlock:(tapActionBlock)block;

/**
 *  停止播放
 */
- (void)stop;

@end
