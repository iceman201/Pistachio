//
//  macros.h
//  Pistacchio
//
//  Created by Liguo Jiao on 30/11/19.
//  Copyright © 2019 Liguo Jiao. All rights reserved.
//

/**
 *  Safely use self inside blocks without introducing reference cycles.
 *  Inpired by @weakify and @strongify from libextobjc / extobjc / EXTScope.h
 *
 *
 *  WEAK_SELF defines __weak weakSelf
 *
 *  STRONG_SELF should only be used inside blocks. It shadows self by a strong
 *  variable initialized to weakSelf. Which means
 *  1. The block does not hold strong reference to self before or after execution.
 *  2. If self is alive when the block enters, it remains alive during the block execution.
 *  2. If self is released before the block executes, self inside the block is nil.
 *
 *  e.g.
   @property (strong, nonatomic) NSString* name;
   @property (copy, nonatomic) void (^selfReport)();

   - (void)setup
   {
     WEAK_SELF;
     self.name = @"FOO";

     self.selfReport = ^{
         STRONG_SELF_OR_RETURN;
         NSLog(@"%@", self ? self->_name : @"self is gone");
     };
   }
 */
#define WEAK_SELF \
    __weak __typeof(self) weakSelf = self;

// Use STRONG_SELF_UNSAFE    if the code is expected to run when self == nil. Be safe.
// Use STRONG_SELF_OR_RETURN if the code may run but should not continue when self == nil. Early return included.
// Use STRONG_SELF_REQUIRED  if the code must run and self must not be nil. Assertion included.

#define STRONG_SELF_UNSAFE \
    _Pragma("clang diagnostic push") \
    _Pragma("clang diagnostic ignored \"-Wshadow\"") \
    __typeof(self) self = weakSelf; \
    _Pragma("clang diagnostic pop")

#define STRONG_SELF_OR_RETURN STRONG_SELF_UNSAFE; if (!self) return /* left blank so that we can return a custom value */
#define STRONG_SELF_REQUIRED STRONG_SELF_UNSAFE; mr_assert(self);

