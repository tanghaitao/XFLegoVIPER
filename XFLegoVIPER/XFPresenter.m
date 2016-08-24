//
//  XFPersenter.m
//  XFLegoVIPER
//
//  Created by yizzuide on 15/12/21.
//  Copyright © 2015年 yizzuide. All rights reserved.
//

#import "XFPresenter.h"

@implementation XFPresenter

- (void)bindView:(id)view
{
    self.userInterface = view;
}

- (void)viewDidLoad{}
- (void)viewDidUnLoad{}

- (void)viewWillBecomeFocusWithIntentData:(id)intentData{}
- (void)viewWillResignFocus{}


- (void)render
{
    __weak typeof(self) weakSelf = self;
    [self.interactor fetchRenderDataWithBlock:^(id obj) {
        weakSelf.expressData = [weakSelf filterWithData:obj];
        // 如果有接受者采用直接推送
        if ([weakSelf.userInterface respondsToSelector:@selector(fillData:)]) {
            [weakSelf.userInterface fillData:weakSelf.expressData];
        }
    }];
    
}

- (id)filterWithData:(id)data
{
    return data;
}
@end
