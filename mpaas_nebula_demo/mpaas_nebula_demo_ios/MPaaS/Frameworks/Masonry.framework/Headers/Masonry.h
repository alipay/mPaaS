//
//  Masonry.h
//  Masonry
//
//  Created by Jonas Budelmann on 20/07/13.
//  Copyright (c) 2013 cloudling. All rights reserved.
//

#import <Foundation/Foundation.h>

//define this constant if you want to use Masonry without the 'mas_' prefix
//#define MAS_SHORTHAND

//define this constant if you want to enable auto-boxing for default syntax
#define MAS_SHORTHAND_GLOBALS

//! Project version number for Masonry.
FOUNDATION_EXPORT double MasonryVersionNumber;

//! Project version string for Masonry.
FOUNDATION_EXPORT const unsigned char MasonryVersionString[];

#import <Masonry/MASUtilities.h>
#import <Masonry/View+MASAdditions.h>
#import <Masonry/View+MASShorthandAdditions.h>
#import <Masonry/ViewController+MASAdditions.h>
#import <Masonry/NSArray+MASAdditions.h>
#import <Masonry/NSArray+MASShorthandAdditions.h>
#import <Masonry/MASConstraint.h>
#import <Masonry/MASCompositeConstraint.h>
#import <Masonry/MASViewAttribute.h>
#import <Masonry/MASViewConstraint.h>
#import <Masonry/MASConstraintMaker.h>
#import <Masonry/MASLayoutConstraint.h>
#import <Masonry/NSLayoutConstraint+MASDebugAdditions.h>
