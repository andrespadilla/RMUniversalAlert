//
//  RMUniversalAlert.h
//  RMUniversalAlert
//
//  Created by Ryan Maxwell on 19/11/14.
//  Copyright (c) 2014 Ryan Maxwell. All rights reserved.
//

#import <UIKit/UIKit.h>

#import "RMPopoverPresentationController.h"

@class RMUniversalAlert;

typedef void(^RMUniversalAlertCompletionBlock)(RMUniversalAlert * __nonnull alert, NSInteger buttonIndex);
typedef void(^RMUniversalAlertTextFieldCompletionBlock)(RMUniversalAlert * __nonnull alert, NSInteger buttonIndex, NSString *__nonnull text);

@interface RMUniversalAlert : NSObject

+ (nonnull instancetype)showAlertInViewController:(nonnull UIViewController *)viewController
                                        withTitle:(nullable NSString *)title
                                          message:(nullable NSString *)message
                                cancelButtonTitle:(nullable NSString *)cancelButtonTitle
                           destructiveButtonTitle:(nullable NSString *)destructiveButtonTitle
                                otherButtonTitles:(nullable NSArray *)otherButtonTitles
                                         tapBlock:(nullable RMUniversalAlertCompletionBlock)tapBlock;

// Custom code to support showing an alert with a UITextField

+ (nonnull instancetype)showAlertInViewController:(nonnull UIViewController *)viewController
                                        withTitle:(nullable NSString *)title
                                          message:(nullable NSString *)message
                                       textToEdit:(nullable NSString *)text
                                      placeholder:(nullable NSString *)placeholder
                                  isPasswordField:(BOOL)isPasswordField
                                cancelButtonTitle:(nullable NSString *)cancelButtonTitle
                           destructiveButtonTitle:(nullable NSString *)destructiveButtonTitle
                                otherButtonTitles:(nullable NSArray *)otherButtonTitles
                                         tapBlock:(nullable RMUniversalAlertTextFieldCompletionBlock)tapBlock;

// End custom code

+ (nonnull instancetype)showActionSheetInViewController:(nonnull UIViewController *)viewController
                                              withTitle:(nullable NSString *)title
                                                message:(nullable NSString *)message
                                      cancelButtonTitle:(nullable NSString *)cancelButtonTitle
                                 destructiveButtonTitle:(nullable NSString *)destructiveButtonTitle
                                      otherButtonTitles:(nullable NSArray *)otherButtonTitles
                     popoverPresentationControllerBlock:(void(^ __nullable)(RMPopoverPresentationController * __nonnull popover))popoverPresentationControllerBlock
                                               tapBlock:(nullable RMUniversalAlertCompletionBlock)tapBlock;

-(void)dismissAlertAnimated:(BOOL)animated;

@property (readonly, nonatomic) BOOL visible;
@property (readonly, nonatomic) NSInteger cancelButtonIndex;
@property (readonly, nonatomic) NSInteger firstOtherButtonIndex;
@property (readonly, nonatomic) NSInteger destructiveButtonIndex;

@end
