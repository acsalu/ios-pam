//
//  OMHClient.h
//  PAM
//
//  Created by Charles Forkish on 12/2/14.
//  Copyright (c) 2014 Charlie Forkish. All rights reserved.
//

#import <Foundation/Foundation.h>

@protocol OMHSignInDelegate;

@interface OMHClient : NSObject

+ (instancetype)sharedClient;

+ (UIButton *)googleSignInButton;

@property (nonatomic, weak) id<OMHSignInDelegate> signInDelegate;

@property (nonatomic, strong) NSString *appGoogleClientID;
@property (nonatomic, strong) NSString *serverGoogleClientID;
@property (nonatomic, strong) NSString *appDSUClientID;
@property (nonatomic, strong) NSString *appDSUClientSecret;

@property (nonatomic, readonly) BOOL isSignedIn;


- (BOOL)handleURL:(NSURL *)url
sourceApplication:(NSString *)sourceApplication
       annotation:(id)annotation;

- (void)signOut;

- (void)updateDataPoint:(NSDictionary *)dataPoint;

@end


@protocol OMHSignInDelegate
@optional

- (void)OMHClientSignInFinishedWithError:(NSError *)error;

@end