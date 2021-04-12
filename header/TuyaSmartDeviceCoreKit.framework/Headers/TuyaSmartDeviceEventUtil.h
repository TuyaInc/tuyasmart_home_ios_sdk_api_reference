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
    TYEventPipelineTypeBLE      = 4, // Single Point Bluetooth
    TYEventPipelineTypeSIGMesh  = 5, // Sig Mesh
    TYEventPipelineTypeBLEMesh  = 6, // Tuya Private Mesh
    
    TYEventPipelineTypeOther    = 9, // others
};


@interface TuyaSmartDeviceEventUtil : NSObject

/// Message sent request  successful.
///
/// @param pipelineType Message sending pipeline
+ (void)successEventWithPipelineType:(TYEventPipelineType)pipelineType;

/// Message sent request  failed.
///
/// @param pipelineType Message sending pipeline.
/// @param pv The pv of the device when the message is sent.
/// @param error The error generated by the message
/// @param extendInfo Detailed error information, you can easily check the status of the error and the app situation.
+ (void)failedEventWithPipelineType:(TYEventPipelineType)pipelineType
                                 pv:(double)pv
                              error:(NSError *)error
                         extendInfo:(NSDictionary *)extendInfo;

@end

NS_ASSUME_NONNULL_END