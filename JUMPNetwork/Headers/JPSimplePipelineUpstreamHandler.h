/*
 * Copyright (c) 2011 - SEQOY.org and Paulo Oliveira ( http://www.seqoy.org )
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#import <Foundation/Foundation.h>
#import "JPPipelineUpstreamHandler.h"
#import "JPDefaultHandlerContext.h"
#import "JPPipelineEvent.h"
#import "JPPipelineMessageEvent.h"
#import "JPPipelineExceptionEvent.h"

#import "JPLogger.h"
/**
 * @ingroup handlers_group
 
 A JPPipelineUpstreamHandler implementation which provides an individual handler method for each event type. 
 This handler down-casts the received upstream event into more meaningful sub-type event and calls an appropriate
 handler method with the down-cast event. The names of the methods are identical to the upstream event names, 
 as introduced in the JPPipelineEvent documentation.
 
 Please use JPSimplePipelineHandler if you need to implement both JPPipelineUpstreamHandler and JPPipelineDownstreamHandler.
 
 <h2>Overriding the handleContextUpstream method</h2>
 
 You can override the <b>handleContextUpstream:withEvent:</b> method just like overriding an ordinary Objective-C method.
 Please make sure to call <b>super</b> so that other handler methods are invoked properly:
 
 \code
 
 // Override...
 -(void)handleContextUpstream:(JPDefaultHandlerContext*)ctx withEvent:(id<JPPipelineEvent>)e {
	 ...
	 [super handleContextUpstream:ctx withEvent:e];
	 ...
 }
 
 \endcode
 

 */
@interface JPSimplePipelineUpstreamHandler : NSObject <JPPipelineUpstreamHandler> {
    NSInteger progressPriority;
}

//// //// //// //// //// //// //// //// //// //// //// //// //// //// //// //// //// //// //// //// //// //// //// //// //// //// //// //// //// //// //// //// //// //// //// 
#pragma mark -
#pragma mark Properties.
//// //// //// //// //// //// //// //// //// //// //// //// //// //// //// //// //// //// //// //// //// //// //// //// //// //// //// //// //// //// //// //// //// //// //// 

/**
 * Progress priority that this has on the overall progress
 * calculation. Return a number from 0 to 10. You can set a custom priority
 * when you add the Handler to the Pipeline. Otherwise will use this value.
 * <b>Default value is 10.</b> 
 */
@property (assign) NSInteger progressPriority;

//// //// //// //// //// //// //// //// //// //// //// //// //// //// //// //// //// //// //// //// //// //// //// //// //// //// //// //// //// //// //// //// //// //// //// 
#pragma mark -
#pragma mark Init Methods. 
//// //// //// //// //// //// //// //// //// //// //// //// //// //// //// //// //// //// //// //// //// //// //// //// //// //// //// //// //// //// //// //// //// //// //// 
/**
 * Init this handler.
 */
+(id)init;

//// //// //// //// //// //// //// //// //// //// //// //// //// //// //// //// //// //// //// //// //// //// //// //// //// //// //// //// //// //// //// //// //// //// //// 
#pragma mark -
#pragma mark Methods. 
//// //// //// //// //// //// //// //// //// //// //// //// //// //// //// //// //// //// //// //// //// //// //// //// //// //// //// //// //// //// //// //// //// //// //// 

/**
 * Invoked when a message object was received.
 * @param ctx An context. 
 * @param e The event.
 */
-(void)messageReceived:(id<JPPipelineHandlerContext>)ctx withMessageEvent:(id<JPPipelineMessageEvent>)e;

/**
 * Invoked when an exception was raised.
 * @param ctx An context. 
 * @param e The event.
 */
-(void)exceptionCaughtWithContext:(id<JPPipelineHandlerContext>)ctx withException:(id<JPPipelineExceptionEvent>)e;

@end
