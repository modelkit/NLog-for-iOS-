//
//  NLogConfig.h
//  NLog
//
//  Created by Miller on 13-7-10.
//
//

#ifndef NLogConfig_h
#define NLogConfig_h

#define LOGS_MAX_DEPTH 250

// 服务器日志接收路径
#define RECEIVER_URL @"http://hunter.duapp.com/command/?command=nlog-post&channel=miller"
//#define RECEIVER_URL @"http://kstj.baidu.com/ctj/88/"

// 版本
#define SDK_VERSION @"1.0"

// 云端策略文件路径
//#define REMOTE_RULE_URL @"http://miller.duapp.com/policy.php"
#define REMOTE_RULE_URL @"http://kstj.baidu.com/zhidao_iphone_2.7.2.rule"

// 云端策略过期时间（单位：天）
#define REMOTE_RULE_EXPIRES 1

// 是否开启仅wifi下发送数据
#define ONLY_SEND_WITH_WIFI NO

// 数据定期发送周期（单位：秒）
#define TIMER_INTERVAL 120

// WIFI下数据定期发送周期（单位：秒）
#define TIMER_INTERVAL_WITH_WIFI 60

// Session过期时间（单位：秒）
#define SESSION_TIMEOUT 30

// 本地缓存日志数据过期时间（单位：天）
#define STORAGE_EXPIRES 10

// 数据最大发送大小（单位：KB）
#define MAX_SEND_SIZE 200

// 默认采样率
#define SAMPLE_RATE 1

// 加密Token
#define ENCRYPT_TOKEN @"5D97EEF8-3127-4859-2222-82E6C8FABD8A"

#define NLOG_CACHE_KEY  @"nlog_cache"
#define CurrentTimeMillis  (long long)round ([[NSDate date] timeIntervalSince1970] * (double)1000)
#define LOG_FORMAT_VERSION 1

#define NLOG_DEBUG_MODE

#ifdef NLOG_DEBUG_MODE
#define NPrintLog( s, ... ) ZDLogDebug( @"<%@:(%d)> %@", [[NSString stringWithUTF8String:__FILE__] lastPathComponent], __LINE__, [NSString stringWithFormat:(s), ##__VA_ARGS__] )
#else
#define NPrintLog( s, ... )
#endif

#endif

//#import "NLog.h"
@class NLogConfig;
@interface NLogConfig : NSObject{
    NSMutableDictionary* defaultConfig;
}

- (id)get:(NSString *) key;

- (id)get:(NSString *) key subkey:(NSString *)subkey;

+ (NLogConfig *)sharedInstance;
+ (NLogConfig *)sharedInstanceWith:(NSDictionary*)configs;

+ (id)get:(NSString *) key;

+ (id)get:(NSString *) key subkey:(NSString *)subkey;
@end
