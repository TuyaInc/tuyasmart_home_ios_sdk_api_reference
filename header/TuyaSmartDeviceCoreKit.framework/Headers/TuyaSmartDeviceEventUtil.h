//
//  TuyaSmartDeviceEventUtil.h
//  TuyaSmartDeviceCoreKit
//
//  Copyright (c) 2014-2021 Tuya Inc. (https://developer.tuya.com)

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSUInteger, TYEventPipelineType) {
    TYEventPipelineTypeLAN      = 1, // LAN
    TYEventPipelineTypeMQTT     = 2, // MQTT
    TYEventPipelineTypeHTTP     = 3, // HTTP
    TYEventPipelineTypeBLE      = 4, // Bluetooth LE
    TYEventPipelineTypeSIGMesh  = 5, // Bluetooth mesh
    TYEventPipelineTypeBLEMesh  = 6, // Bluetooth LE mesh
    
    TYEventPipelineTypeOther    = 9, // Other types
};


@interface TuyaSmartDeviceEventUtil : NSObject

/// The message sending request is successful.
///
/// @param pipelineType The message sending pipeline.
+ (void)successEventWithPipelineType:(TYEventPipelineType)pipelineType;

/// The message sending request failed.
///
/// @param pipelineType The message sending pipeline.
/// @param pv The device protocol version that is used when the message is sent.
/// @param error An error occurs while processing the request.
/// @param extendInfo Detailed error information, in which you can easily check the status of the error and the app condition.
+ (void)failedEventWithPipelineType:(TYEventPipelineType)pipelineType
                                 pv:(double)pv
                              error:(NSError *)error
                         extendInfo:(NSDictionary *)extendInfo;

@end

NS_ASSUME_NONNULL_END
