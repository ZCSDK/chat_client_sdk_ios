//
//  ChunkedUploadManager.h
//  分片上传管理器
//

#import <Foundation/Foundation.h>
#import <SobotCommon/SobotCommon.h>

NS_ASSUME_NONNULL_BEGIN

// 上传进度回调
typedef void(^ChunkedUploadProgressBlock)(NSInteger uploadedChunks, NSInteger totalChunks, float progress);

// 上传完成回调
typedef void(^ChunkedUploadCompletionBlock)(BOOL success, NSString * _Nullable fileKey, NSError * _Nullable error,NSDictionary *item);

@interface SobotChunkedUploadManager : NSObject

/**
 * 单例
 */
+ (instancetype)sharedManager;

/**
 * 配置基础URL和temp-id
 * @param baseURL 服务器基础URL，例如: @"https://your-domain.com"
 * @param tempId 临时ID，用于header中的temp-id字段
 */
- (void)configureWithBaseURL:(NSString *)baseURL tempId:(NSString *)tempId;

/**
 * 上传文件（分片上传）
 * @param filePath 本地文件路径
 * @param companyId 公司ID
 * @param chunkSize 每个分片的大小（字节），默认5MB
 * @param attachmentType 附件类型，0表示正常附件，1表示其他类型
 * @param progressBlock 进度回调
 * @param completionBlock 完成回调
 */
- (void)uploadFileAtPath:(NSString *)filePath
               companyId:(NSString *)companyId
               chunkSize:(NSInteger)chunkSize
          attachmentType:(NSInteger)attachmentType
                progress:(nullable ChunkedUploadProgressBlock)progressBlock
              completion:(ChunkedUploadCompletionBlock)completionBlock;

/**
 * 取消当前上传
 */
- (void)cancelUpload;

@end

NS_ASSUME_NONNULL_END
