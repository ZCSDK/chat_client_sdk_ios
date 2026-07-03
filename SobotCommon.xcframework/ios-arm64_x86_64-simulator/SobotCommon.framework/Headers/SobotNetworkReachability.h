//
//  SobotNetworkReachability.h
//  SobotNetwork
//
//  Created by zhangxy on 2021/7/13.
//

#import <Foundation/Foundation.h>

#if !TARGET_OS_WATCH
#import <SystemConfiguration/SystemConfiguration.h>

typedef NS_ENUM(NSInteger, SobotNetworkReachabilityStatus) {
    SobotNetworkReachabilityStatusUnknown          = -1,
    SobotNetworkReachabilityStatusNotReachable     = 0,
    SobotNetworkReachabilityStatusReachableViaWWAN = 1,
    SobotNetworkReachabilityStatusReachableViaWiFi = 2,
};

/// 精细化网络接口类型(用于检测 WiFi↔4G、VPN 切换、IP 漂移等 reachable 二值无法覆盖的场景)
typedef NS_ENUM(NSInteger, SobotNetworkInterfaceType) {
    SobotNetworkInterfaceTypeUnknown   = 0,
    SobotNetworkInterfaceTypeWiFi      = 1,   // en0
    SobotNetworkInterfaceTypeCellular  = 2,   // pdp_ip0..pdp_ip7
    SobotNetworkInterfaceTypeVPN       = 3,   // utun0..utunN / ppp0
    SobotNetworkInterfaceTypeWired     = 4,   // en1(极少见,iPad 直连有线)
    SobotNetworkInterfaceTypeLoopback  = 5,   // lo0(不作为出网)
};

NS_ASSUME_NONNULL_BEGIN

/// 当前默认出网接口快照(getifaddrs 结果)
@interface SobotNetworkInterfaceSnapshot : NSObject
@property (nonatomic, copy,   nullable) NSString *ifname;
@property (nonatomic, copy,   nullable) NSString *ipv4;
@property (nonatomic, copy,   nullable) NSString *ipv6;
@property (nonatomic, assign) SobotNetworkInterfaceType type;
@property (nonatomic, assign) NSTimeInterval capturedAt;
/// 判定是否同一出网路径:接口名相同 & IPv4 相同(IPv6 仅在无 IPv4 时参与比较)
- (BOOL)isSamePathAs:(nullable SobotNetworkInterfaceSnapshot *)other;
@end

/**
 `SobotNetworkReachabilityManager` monitors the reachability of domains, and addresses for both WWAN and WiFi network interfaces.

 Reachability can be used to determine background information about why a network operation failed, or to trigger a network operation retrying when a connection is established. It should not be used to prevent a user from initiating a network request, as it's possible that an initial request may be required to establish reachability.

 See Apple's Reachability Sample Code ( https://developer.apple.com/library/ios/samplecode/reachability/ )

 @warning Instances of `SobotNetworkReachabilityManager` must be started with `-startMonitoring` before reachability status can be determined.
 */
@interface SobotNetworkReachability : NSObject

/**
 The current network reachability status.
 */
@property (readonly, nonatomic, assign) SobotNetworkReachabilityStatus networkReachabilityStatus;

/**
 Whether or not the network is currently reachable.
 */
@property (readonly, nonatomic, assign, getter = isReachable) BOOL reachable;

/**
 Whether or not the network is currently reachable via WWAN.
 */
@property (readonly, nonatomic, assign, getter = isReachableViaWWAN) BOOL reachableViaWWAN;

/**
 Whether or not the network is currently reachable via WiFi.
 */
@property (readonly, nonatomic, assign, getter = isReachableViaWiFi) BOOL reachableViaWiFi;

///---------------------
/// @name Initialization
///---------------------

/**
 Returns the shared network reachability manager.
 */
+ (instancetype)sharedManager;

/**
 Creates and returns a network reachability manager with the default socket address.
 
 @return An initialized network reachability manager, actively monitoring the default socket address.
 */
+ (instancetype)manager;

/**
 Creates and returns a network reachability manager for the specified domain.

 @param domain The domain used to evaluate network reachability.

 @return An initialized network reachability manager, actively monitoring the specified domain.
 */
+ (instancetype)managerForDomain:(NSString *)domain;

/**
 Creates and returns a network reachability manager for the socket address.

 @param address The socket address (`sockaddr_in6`) used to evaluate network reachability.

 @return An initialized network reachability manager, actively monitoring the specified socket address.
 */
+ (instancetype)managerForAddress:(const void *)address;

/**
 Initializes an instance of a network reachability manager from the specified reachability object.

 @param reachability The reachability object to monitor.

 @return An initialized network reachability manager, actively monitoring the specified reachability.
 */
- (instancetype)initWithReachability:(SCNetworkReachabilityRef)reachability NS_DESIGNATED_INITIALIZER;

/**
 *  Unavailable initializer
 */
+ (instancetype)new NS_UNAVAILABLE;

/**
 *  Unavailable initializer
 */
- (instancetype)init NS_UNAVAILABLE;

///--------------------------------------------------
/// @name Starting & Stopping Reachability Monitoring
///--------------------------------------------------

/**
 Starts monitoring for changes in network reachability status.
 */
- (void)startMonitoring;

/**
 Stops monitoring for changes in network reachability status.
 */
- (void)stopMonitoring;

///-------------------------------------------------
/// @name Getting Localized Reachability Description
///-------------------------------------------------

/**
 Returns a localized string representation of the current network reachability status.
 */
- (NSString *)localizedNetworkReachabilityStatusString;

///---------------------------------------------------
/// @name Setting Network Reachability Change Callback
///---------------------------------------------------

/**
 Sets a callback to be executed when the network availability of the `baseURL` host changes.

 @param block A block object to be executed when the network availability of the `baseURL` host changes.. This block has no return value and takes a single argument which represents the various reachability states from the device to the `baseURL`.
 */
- (void)setReachabilityStatusChangeBlock:(nullable void (^)(SobotNetworkReachabilityStatus status))block;

///---------------------------------------------------
/// @name Default Interface Snapshot (精细化网络变化探测)
///---------------------------------------------------

/// 同步取一次当前默认出网接口快照(getifaddrs,通常 3-5ms)。无网络时返回 nil
+ (nullable SobotNetworkInterfaceSnapshot *)currentDefaultInterface;

/// 取一次新快照与缓存的 lastSnapshot 比对,如发生变化则发 SobotNetworkInterfaceChanged 通知。内含 100ms 防抖
- (void)checkAndPostInterfaceChange;

@end

///----------------
/// @name Constants
///----------------

/**
 ## Network Reachability

 The following constants are provided by `SobotNetworkReachabilityManager` as possible network reachability statuses.

 enum {
 SobotNetworkReachabilityStatusUnknown,
 SobotNetworkReachabilityStatusNotReachable,
 SobotNetworkReachabilityStatusReachableViaWWAN,
 SobotNetworkReachabilityStatusReachableViaWiFi,
 }

 `SobotNetworkReachabilityStatusUnknown`
 The `baseURL` host reachability is not known.

 `SobotNetworkReachabilityStatusNotReachable`
 The `baseURL` host cannot be reached.

 `SobotNetworkReachabilityStatusReachableViaWWAN`
 The `baseURL` host can be reached via a cellular connection, such as EDGE or GPRS.

 `SobotNetworkReachabilityStatusReachableViaWiFi`
 The `baseURL` host can be reached via a Wi-Fi connection.

 ### Keys for Notification UserInfo Dictionary

 Strings that are used as keys in a `userInfo` dictionary in a network reachability status change notification.

 `SobotNetworkingReachabilityNotificationStatusItem`
 A key in the userInfo dictionary in a `SobotNetworkingReachabilityDidChangeNotification` notification.
 The corresponding value is an `NSNumber` object representing the `SobotNetworkReachabilityStatus` value for the current reachability status.
 */

///--------------------
/// @name Notifications
///--------------------

/**
 Posted when network reachability changes.
 This notification assigns no notification object. The `userInfo` dictionary contains an `NSNumber` object under the `SobotNetworkingReachabilityNotificationStatusItem` key, representing the `SobotNetworkReachabilityStatus` value for the current network reachability.

 @warning In order for network reachability to be monitored, include the `SystemConfiguration` framework in the active target's "Link Binary With Library" build phase, and add `#import <SystemConfiguration/SystemConfiguration.h>` to the header prefix of the project (`Prefix.pch`).
 */
FOUNDATION_EXPORT NSString * const SobotNetworkingReachabilityDidChangeNotification;
FOUNDATION_EXPORT NSString * const SobotNetworkingReachabilityNotificationStatusItem;

/// 精细化网络变化通知。userInfo 字段:
///   oldIfname / newIfname : NSString | NSNull   接口名(如 en0 / pdp_ip0 / utun0)
///   oldIPv4   / newIPv4   : NSString | NSNull   IPv4 文本
///   oldType   / newType   : NSNumber(SobotNetworkInterfaceType)
///   transition            : NSString            "regained" / "lost" / "wifi-to-cellular" /
///                                              "cellular-to-wifi" / "wifi-to-vpn" / "vpn-to-wifi" /
///                                              "wifi-to-wifi"(同类 IP 漂移) / "cellular-to-cellular" /
///                                              "ifname-changed" / "none" / "unknown"
FOUNDATION_EXPORT NSString * const SobotNetworkInterfaceChanged;

///--------------------
/// @name Functions
///--------------------

/**
 Returns a localized string representation of an `SobotNetworkReachabilityStatus` value.
 */
FOUNDATION_EXPORT NSString * SobotStringFromNetworkReachabilityStatus(SobotNetworkReachabilityStatus status);

NS_ASSUME_NONNULL_END
#endif
