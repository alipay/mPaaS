//
//  APDAOTransaction.h
//  MobileFoundation
//
//  Created by shenmo on 11/11/14.
//  Copyright (c) 2014 Alipay. All rights reserved.
//

#import <Foundation/Foundation.h>

typedef NS_ENUM (unsigned int, APDAOTransaction)
{
    APDAOTransactionBegin = 0,
    APDAOTransactionCommit,
    APDAOTransactionRollback,
};