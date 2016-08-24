//
//  XFPersenter.h
//  XFLegoVIPER
//
//  Created by yizzuide on 15/12/21.
//  Copyright © 2015年 yizzuide. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "XFEventHandlerProt.h"
#import "XFUserInterfaceProt.h"
#import "XFWireFrameProt.h"
#import "XFInteractorProt.h"
#import "XFUIOperatorProt.h"
#import "XFLegoMarco.h"

#define XFConvertInteractorToType(type) LEGORealProt(type, self.interactor)
#define XFConvertRoutingToType(type) LEGORealProt(type, self.routing)
#define XFConvertUserInterfaceToType(type) LEGORealProt(type, self.userInterface)

@interface XFPresenter : NSObject <XFEventHandlerProt,XFUIOperatorProt>
/**
 *  显示界面
 */
@property (nonatomic, weak) id<XFUserInterfaceProt> userInterface;
/**
 *  界面跳转和模块切换管理
 */
@property (nonatomic, strong) id<XFWireFrameProt> routing;
/**
 *  业务管理者
 */
@property (nonatomic, strong) id<XFInteractorProt> interactor;

/**
 *  模块之间传递的意图数据
 */
@property (nonatomic, strong) id intentData;

/**
 * 视图填充数据（用于视图层使用MVVM响应获取数据）
 *
 */
@property (nonatomic, strong) id expressData;

/**
 *  错误消息
 */
@property (nonatomic, copy) NSString *errorMessage;

/**
 *  绑定一个视图(架构关联View方法，不要直接调用！）
 *
 *  @param view 视图
 */
- (void)bindView:(id)view NS_DEPRECATED_IOS(1_0, 1_0,"架构加载View方法，不要直接调用！");
/**
 *  视图加载完成(架构加载View方法，不要直接调用！）
 */
- (void)viewDidLoad NS_DEPRECATED_IOS(1_0, 1_0, "架构加载View方法，不要直接调用！");
/**
 *  视图回收(架构回收View方法，不要直接调用！）
 */
- (void)viewDidUnLoad NS_DEPRECATED_IOS(1_0, 1_0, "架构加载View方法，不要直接调用！");

/**
 *  发起从后台抓起数据后渲染视图
 *
 */
- (void)render;
/**
 *  格式化数据的数据
 *
 *  @param data 原数据
 */
- (id)filterWithData:(id)data;
@end
