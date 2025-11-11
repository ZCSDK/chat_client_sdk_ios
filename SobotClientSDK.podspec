
Pod::Spec.new do |s|

  s.name         = "SobotClientSDK"
  s.version      = "4.3.0"
  s.summary      = "iOS SobotClientSDK v7"
  s.description      = <<-DESC
 Sobot SDKv7 Visitor Side provides enterprises with a complete set of intelligent customer service solutions. Sobot Customer Service SDK includes both customer service business logic and interactive interfaces. Enterprises can integrate Sobot Customer Service into their App with just two simple steps, enabling the App to have 7*24 hour customer service capabilities. 
DESC

  s.homepage     = "https://github.com/ZCSDK/chat_client_sdk_ios.git"

  s.license      = "MIT"

  s.author       = { 'sobot' => 'app_dev@sobot.com' }

  s.platform     = :ios, "13.0"
  
  #依赖库不支持i386
  #s.pod_target_xcconfig = { 'VALID_ARCHS' => 'arm64 x86_64' }
# 架构和 Swift 配置
  s.pod_target_xcconfig = {
    'VALID_ARCHS' => 'arm64 x86_64',
    'SWIFT_VERSION' => '5.0',
    'SWIFT_OPTIMIZATION_LEVEL' => '-Onone',
    'ENABLE_BITCODE' => 'NO'
  }


  #s.user_target_xcconfig = {'OTHER_LDFLAGS' => ['-lObjC','-all_load']}

  s.source       = { :git => "https://github.com/ZCSDK/chat_client_sdk_ios.git", :tag => s.version }

  s.resources = 'SobotKit.bundle'
  s.ios.vendored_frameworks = 'SobotKit.framework','SobotChatClient.framework','SobotCommon.framework'


# 封装的framework名称
#  s.ios.vendored_frameworks = 'SobotKit.xcframework'

# 工程配置
s.user_target_xcconfig = { 'BUILD_LIBRARY_FOR_DISTRIBUTION' => 'YES' }
s.pod_target_xcconfig = { 'BUILD_LIBRARY_FOR_DISTRIBUTION' => 'YES' }

end
