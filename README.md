# iOS SDK V7


Sobot SDK Visitor Side provides enterprises with a complete set of intelligent customer service solutions. Sobot Customer Service SDK includes both customer service business logic and interactive interfaces. Enterprises can integrate Sobot Customer Service into their App with just two simple steps, enabling the App to have 7*24 hour customer service capabilities.


The administrator can add an APP in the background under "Homepage - Online Customer Service - Settings - Channel Integration Settings - Add Channel", and then complete the SDK integration according to the instructions in this access document.

Sobot Customer Service SDK has the following features:

* Online Consultation: Consult with robot, consult with human customer service (send and receive images, send voice messages), send emojis;
* Assign to a specific skill group for reception;
* Guide users to leave messages when they are queuing or when customer service is offline;
* In robot priority mode, the button to transfer to human is hidden, and the robot shows unknown issues N times;
* Customer Service Satisfaction Evaluation: User-initiated satisfaction evaluation + Asking for evaluation when the user exits;
* Pass in user profile: User connection ID + basic information + custom fields;
* Pass in the product source page: Source page title + Source page URL;
* Highly customizable UI;

![Image](/en/images/online/sdk/a-0.png)

Relevant Limitations and Precautions
1. The new version of the iOS SDK supports iOS 10 and above, and works on both iPhone and iPad. It supports both portrait and landscape modes.

2. The current release version of XCode is XCode 14.2. It is recommended to use the latest version for development.

3. IOS currently only supports hyperlink tags. It does not recognize other HTML tags and attributes.

4. IOS requires permission for the microphone, camera, photo library, and push notifications. Otherwise, some features will not work.

#### Document Introduction

##### ● Integration Process Diagram
![Image](/en/images/online/sdk/sobotusersdk_i_1_1.png)

##### ● File Description
**The SDK includes (SobotKit.framework, SobotCommon.framework, SobotChatClient.framework, and SobotKit.bundle), SobotDemo, and Doc-related documentation.**

| File Name   | Description   | Notes |
|:----|:----|:----|
| SobotKit.framework   | Sobot SDK UI Code Library   |    |
| SobotCommon.framework   | Sobot SDK Base Code Library   |    |
| SobotChatClient.framework   | Sobot SDK Interface Library   |    |
| SobotKit.bundle   | SDK resource library, including image files, multilingual files, and colors   |    |
| ZCSobotApi.h   | This file provides access functions   |    |
| ZCLibInitInfo.h   | Basic function parameter class (user information, reception mode, skill group, etc.)   |    |
| ZCKitInfo.h   | Basic UI parameter class (color, control visibility, etc.)   |    |
| ZCUIBaseController   | Parent class for UI interface, all other pages inherit from this controller   |    |
| ZCChatController   | Chat Interface   |    |
| SobotLocalizable.strings   | International language file, automatically matches the system language by default   |    |
| ZCLibClient.h   | Global configuration class, mainly includes non-UI related operation settings   |    |



#### Integration Method
**Note: Before using the V7 version SDK, please confirm that "Management Console - Online Customer Service - Visitor Client Settings" has been updated to the latest version. Only the latest version supports integration with the V7 version SDK.**

##### ● Manual Integration


Download link: [iOS_SDK](https://shimo.im/docs/XKq4252aNNc8n9AN/)


Unzip [iOS_SDK], and add the necessary files SobotKit.framework, SobotChatClient.framework, SobotCommon.framework, and SobotKit.bundle to your project. The implementation of Sobot iOS_SDK relies on some system frameworks. When developing an app, these frameworks need to be added to the project. First, the developer should click the project name on the right side of the project. Then, on the right side of the project name, select TARGETS -> Build Phases -> Link Binary With Libraries. After expanding Link Binary With Libraries, click the + below to add the following dependencies:

* AVFoundation.framework
* AssetsLibrary.framework
* AudioToolbox.framework
* SystemConfiguration.framework
* MobileCoreServices.framework
* WebKit.framework


##### ●  CocoPods Integration
Add to the Podfile:

```js  
// Standard Version:
pod 'SobotClientSDK'
```


If the latest version cannot be found, please run the following command to update the CocoPods repository.

```js  
pod repo update --verbose
If you cannot update to the latest version, you can delete the index file and try again.
rm ~/Library/Caches/CocoaPods/search_index.json

```

Clear pod cache:

```js
Delete the pod folder in the code,
pod cache clean SobotChatClient
Run pod install again
```

##### ● Domain Settings
Domain Name Description:

      * The default SaaS platform domain is: https://api.sobot.com

      * If you are a Tencent Cloud service, set it to: https://www.soboten.com

      * If you are using a localized deployment, please use your own service domain name for deployment.

Example code:



```C

// Initialization sets the domain name. If not set, the default SaaS domain will be used.
[ZCSobotApi initSobotSDK:@"your appkey" host:@"" result:^(id  _Nonnull object) {
    
}];

```
##### ● Get appkey
Log in to [Sobot Management Platform](https://sg.sobot.com/auth/sign_in) to get, as shown in the figure

![Image](/en/images/online/sdk/a-3-2.png)

##### ● Initialization
###### 1. Standard Version:
Initialization parameters and calling method: Initialization information and UI customization are divided into two models. Use ZCLibInitInfo to set function-related attributes, and ZCKitInfo to set UI-related attributes. Pass them together to the initialization method. For details, see the Demo calling code.

The main calling code is as follows:

[Note: Before starting the Sobot SDK, you must call the initialization interface initSobotSDK. Otherwise, the SDK will fail to start.]

Interface:

```js

// Initialization sets the domain name. If not set, the default SaaS domain name is used.
[ZCSobotApi initSobotSDK:@"your appkey" host:@"" result:(void (^)(id object))resultBlock;

```
Parameters:  

| Parameter Name | Type | Description |
|:----|:----|:----|
| app_key   | NSString   | app_key is required. You can view it in the background -> settings -> APP.   |
| host   | NSString   | Default is Aliyun domain. If using other domains, you need to specify it yourself. |
| resultBlock   | NSString   | Initialization status callback   |

Example code:

```js
#import <SobotKit/SobotKit.h>
- (BOOL)application:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)launchOptions {   
      // Override point for customization after application launch.
    NSLog(@"%@",[ZCSobotApi getVersion]);
// Error log collection (optional)
    // [ZCSobotApi setZCLibUncaughtExceptionHandler];
// Optional parameter settings
    if([ZCLibClient getZCLibClient].libInitInfo == nil){
        [ZCLibClient getZCLibClient].libInitInfo = [ZCLibInitInfo new];
    }
    
    // Initialization is required and must be executed before entering the SDK.
    [ZCSobotApi initSobotSDK:@"your app_key" result:^(id  _Nonnull object) {
NSLog(@"Initialization completed %@", object);
    }];
    return YES;
}
```
###### 2. E-commerce Version
Initialization parameters and calling method: Initialization information and UI customization are divided into two models. Use ZCLibInitInfo to set function-related attributes, and ZCKitInfo to set UI-related attributes. Pass them together to the initialization method. For details, see the Demo calling code.

The main calling code is as follows:

[Note: Before starting the Sobot SDK, you must call the initialization interface initSobotSDK. Otherwise, the SDK will not start. Calling it multiple times will not repeat the interface call.]

Interface:

Example code:

```js
- (BOOL)application:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)launchOptions {   
      // Override point for customization after application launch.
    NSLog(@"%@",[ZCSobot getVersion]);
// Error log collection (optional)
    // [ZCSobotApi setZCLibUncaughtExceptionHandler];
// Optional parameter settings
    if([ZCLibClient getZCLibClient].libInitInfo == nil){
        [ZCLibClient getZCLibClient].libInitInfo = [ZCLibInitInfo new];
    }    
[ZCLibClient getZCLibClient].libInitInfo.platform_key = @"Private Key"
//customer_code Merchant ID for integration (Only applicable to e-commerce version. Required if app_key is not provided)
//[ZCLibClient getZCLibClient].libInitInfo.customer_code = @"Merchant ID"
    // Add platform identifier (required for e-commerce version)
    [ZCLibClient getZCLibClient].platformUnionCode = @"Your registered platform ID";
    
    // Initialize
    //If needed, set the domain name. Make sure to set it before initialization, otherwise the initialization interface will fail.
    [ZCSobotApi initSobotSDK:@"your app_key" host:@"" result:^(id object) {
    }];
    return YES;
}
```
###### 3. Permission Settings
Permissions to be added

```js
<key>NSCameraUsageDescription</key>
<string>Sending pictures requires access to the camera</string>
  // Optional, add based on your own situation
<key>NSLocalizedDescription</key>
<string>Use push service</string>
<key>NSMicrophoneUsageDescription</key>
<string>Sending voice requires access to the microphone</string>
<key>NSPhotoLibraryUsageDescription</key>
<string>Sending images requires access to the photo album</string>
```
##### ●  Launch Sobot Page
###### 1. Launch the customer service page
The startup method for the standard version and the e-commerce version is the same.
[Note: The e-commerce version needs to reset the merchant app_key. When starting a merchant, reset the app_key for that merchant.]

Interface

```js


/// Start the chat page, simple processing
/// @param info Custom UI attributes
/// @param byController  The launched page
/// @param pageClick Current status of the page
+ (void)openZCChat:(ZCKitInfo *) info
            with:(UIViewController *) byController
       pageBlock:(void (^)(id object,ZCPageStateType type))pageClick;
    
 
/// Click the link to intercept Help Center, Messages, Chat, Message History
/// @param messagelinkBlock Get the link. If it returns YES, then intercept it.
+(void)setMessageLinkClick:(BOOL (^)(ZCLinkClickType type,NSString *linkUrl,id _Nullable object))messagelinkBlock;
    
    
```
Parameter

| Parameter Name | Type | Description |
|:----|:----|:----|
| info   | ZCKitInfo   | Custom settings for initialization parameters |
| byController   | UIViewController   | The vc that performs the jump |
| pageClick   | void (^)(id object,ZCPageBlockType type)   | Callback when returning a click   |

Example code:

```js
// Set required parameters. Parameters in ZCLibInitInfo can be reset.
ZCLibInitInfo *initInfo = [ZCLibClient getZCLibClient].libInitInfo;
// Set the user ID, which is the unique identifier for users. (Do not use fixed values like 123456, 0, or 000000. Chat records with the same ID will be identical.) If not set, a unique identifier will be generated based on the phone certificate by default. It supports up to 300 characters, and any excess will be automatically truncated.
initInfo.partnerid = @"";

// For the e-commerce version, you need to reassign the merchant app_key or merchant code customer_code
//initInfo.app_key = @"";

// Reassign
[ZCLibClient getZCLibClient].libInitInfo = initInfo;

// Configure UI
ZCKitInfo *uiInfo=[ZCKitInfo new];
// Such as setting the navigation bar color
uiInfo.topViewBgColor = [UIColor redColor];
[ZCSobotApi openZCChat:uiInfo with:vc pageBlock:^(id  _Nonnull object, ZCPageStateType type) {

}];


    [ZCSobotApi setMessageLinkClick:^BOOL(ZCLinkClickType type, NSString * _Nonnull linkUrl, id  _Nullable object) {
NSLog(@"Listen link: %@", linkUrl);
        if ([linkUrl containsString:@"sobot://sendOrderMsg"]) {
            [ZCSobotApi sendOrderGoodsInfo:[ZCUICore getUICore].kitInfo.orderGoodsInfo resultBlock:^(NSString * _Nonnull msg, int code) {
                
            }];
            return YES;
        }
        if ([linkUrl containsString:@"sobot://sendLocation"]) {
                // Send location information
            [ZCSobotApi sendLocation:@{
                @"lat":@"40.001693",
                @"lng":@"116.353276",
@"localLabel":@"No. 38 Xueqing Road, Haidian District, Beijing, Jinma Building",
@"localName":@"Cloud View Seasons Restaurant",
                @"file":@""} resultBlock:^(NSString * _Nonnull msg, int code) {
                
            }];
            return YES;
        }
        if([linkUrl containsString:@"sobot://sendFile"]){
            [ZCSobotApi sendMessageToUser:@"file:///Users/zhangxinyao/Library/Developer/CoreSimulator/Devices/BBB98C5A-0DEB-4FBD-8EB9-8B03ACAFD49A/data/Containers/Data/Application/E2528DA6-28F5-4D1D-BCD0-C4888546C7F6/tmp/com.sobot.sdk.demo-Inbox/ces.txt" type:4 resultBlock:^(NSString * _Nonnull text, int code) {
                
            }];
            return YES;
        }
        
//        if ([linkUrl hasPrefix:@"www."]) {  // Test debugging, use to jump to the root vc
//            TestViewController *test = [[TestViewController alloc]init];
//            UIViewController *vc = [self.class getCurrentViewController];
//            [vc presentViewController:test animated:YES completion:nil];
//            test.dismiss = ^{
//                NSLog(@"xx");
//            };
//            return YES;
//        }
        return NO;
    }];
    

```


###### 2. Launch Merchant List (E-commerce Version)
[Note: Launch the merchant list (supported only in the e-commerce version)]

Interface

```js

+ (void)openZCChatListView:(ZCKitInfo *)info with:(UIViewController *)byController onItemClick:(void (^)(SobotClientBaseController *object,ZCPlatformInfo *info))itemClickBlock;

```
Parameter

| Parameter Name   | Type   | Description   |
|:----|:----|:----|
| info   | ZCKitInfo   | Set UI related custom parameters |
| byController   | UIViewController   | The vc that performs the jump |
| delegate   | ZCChatControllerDelegate  | The delegate for the chat page. It can implement message redirection to a custom page. |
| itemClickBlock   | void (^)(SobotClientBaseController *object,ZCPlatformInfo *info)  | Custom jump, can be null (Note: If not null, no internal jump processing will be performed) |


Example code:

```js

// Launch the merchant list page
     [ZCSobotApi openZCChatListView:uiInfo with:self onItemClick:^(SobotClientBaseController * _Nonnull object, ZCPlatformInfo * _Nonnull info) {

    }];

```
###### 3. Start the Customer Service Center
```js

ZCKitInfo *kitInfo = [ZCKitInfo new];
//kitInfo.helpCenterTel = @"40012345678";
//kitInfo.helpCenterTelTitle = @"400-Customer Service";

// Open the help center page
+ (void)openZCServiceCenter:(ZCKitInfo *) info
                         with:(UIViewController *) byController
                  onItemClick:(void (^)(SobotClientBaseController *object))itemClickBlock;
    
```
Sketch: ![Image](/en/images/online/sdk/a-3-5.png)


##### ● End Session
```js

     
/// Close the channel, clear memory, exit Sobot client and remove push notifications
/// @param isClosePush YES to close push; NO for offline users, but can still receive push notifications
[ZCSobotApi outCurrentUserZCLibInfo:NO];

```


##### ● Robot Customer Service
###### 1. Connect to the specified robot
Get the robot number in the background:

![Image](/en/images/online/sdk/a-4-1-1.png)

In the SDK code, configure:

```js
ZCLibInitInfo *initInfo = [ZCLibClient getZCLibClient].libInitInfo;
LibInitInfo.robotid = @"Robot ID";

// It will be invalid if not set. Note that if an alias is specified, you need to set robotid to empty. Otherwise, the system will use the last default value when the alias is incorrect.
LibInitInfo.robot_alias = @"Robot Alias";

```
Note: If not set, the default value will be used.
###### 2.  Custom Access Mode
Based on the needs of your own business, you can configure the following initialization parameters to control the access mode:

```js
ZCKitInfo *uiInfo=[ZCKitInfo new];
// Whether to enable voice function. Enabled by default.
  kitInfo.isOpenRecord = @"YES";
// Whether to enable robot voice, (paid, otherwise the voice cannot be recognized)
  kitInfo.isOpenRobotVoice = @"YES";
// Whether to show the transfer-to-human button
  kitInfo.isShowTansfer = @"YES";

//Custom reception mode
Note: After setting the local reception mode, the local setting takes priority.
The reception mode setting on the PC client no longer works. It is recommended to use the setting on the PC client.
Settings on the PC client
0: Follow system settings (default)
1: Only robots,
2: Manual Only
3: Intelligent Customer Service - Robot Priority
4: Intelligent Customer Service - Human Agent
libInitInfo.service_mode = 4;
```

###### 3.  Custom Transfer to Human Event
Custom method for transferring to human agent:

```js

[Note: If this method is implemented, the SDK's transfer-to-human event will be handed over to external control. You can redirect to your custom skill group page or switch product information, etc. The SDK will no longer execute the transfer-to-human operation. You need to call the turnServiceWithGroupId: interface to implement the specific transfer-to-human operation yourself]

Custom Transfer to Human Callback Event:

Intercept SDK transfer to human event. Use it to jump to your app page for dynamic processing of transfers to human agents. Configure skill group ID, product information, and other parameters.
```

```js
@property (nonatomic,strong)  TurnServiceBlock    turnServiceBlock;
```

Example code:

```
     [ZCLibClient getZCLibClient].turnServiceBlock = ^(SobotChatMessage * _Nullable model, NSInteger turnType) {
        [ZCSobotApi connectCustomerService:model KitInfo:uiInfo ZCTurnType:turnType];
    };
       
```

###### 4. Set up manual transfer overflow

In the SDK, you can set up automatic transfer to a specific skill group when overflow occurs.

Example code:

```js
/**
 *  Transfer to human agent Specify skill group Overflow
 *
Parameter Description

ActionType Execution action type:
            to_group Specify the skill group;
To_service Assign a customer service representative.
DeciId specifies the skill group or customer service id
OptionId Overflow Flag
1: Overflow; When specifying customer service
2: No overflow; When specifying customer service
3: Overflow; When specifying a skill group
4: No overflow; When specifying a skill group
SpillId Overflow Condition
1: Customer service is offline; when assigning customer service
2: Customer service is busy; when assigning customer service
3: Intelligent judgment; When specifying customer service
4: No agents online in the skill group; when specifying a customer service group
5: All customer services in the skill group are busy; when a specific customer service group is designated
6: The skill group is not working; when specifying the customer service group
7: Intelligent judgment; When specifying a customer service group
 
 [{"actionType":"to_group","optionId":"3","deciId":"162bb6bb038d4a9ea018241a30694064","spillId":"7"},{"actionType":"to_group","optionId":"4","deciId":"a457f4dfe92842f8a11d1616c1c58dc1"}]
ActionType: Action type to execute:
To_group: Transfer to designated skill group
OptionId: Whether to overflow When specifying a skill group: 3: Overflow, 4: Not overflow.
DeciId: The specified skill group.
SpillId: Overflow condition  When specifying a customer service group: 4: No agents online in the skill group, 5: All agents in the skill group are busy, 6: Skill group is off duty, 7: Intelligent judgment
Set up to 4 groups in the array, overflowing sequentially.
 */
 
 ZCLibInitInfo *initInfo = [ZCLibClient getZCLibClient].libInitInfo;
    initInfo.transferaction = @[@{@"actionType":@"to_group",@"optionId":@"3",@"deciId":@"a890849f552b4b69b4a027db4e9a1880",@"spillId":@"4"},@{@"actionType":@"to_group",@"optionId":@"3",@"deciId":@"5600aa6786f34629a7484819b8132c3a",@"spillId":@"4"}];
```


###### 5. Specify the robot guidance message
Different scenarios can have different robot greetings set up.

```
Pass in the relevant fields in ZCKitInfo.
eg：

ZCLibInitInfo *_libInitInfo [ZCLibClient getZCLibClient].libInitInfo;
_libInitInfo.faqId = 24;

```



##### ●  Human Customer Service
###### 1. Connect to the specified skill group
Get the skill group number in the background:

![Image](/en/images/online/sdk/a-4-2-1.png)

Configure the skill group ID in the SDK code:

```js
ZCLibInitInfo *initInfo = [ZCLibClient getZCLibClient].libInitInfo;
InitInfo.groupid = @"Skill Group ID";
```
Note: This field is optional. If a skill group ID is provided, the SDK will skip the skill group selection popup and directly route to the specified skill group after transferring to manual service.
###### 2. Connect to the designated customer service representative
Get the specified customer service ID in the background:

![Image](/en/images/online/sdk/a-4-2-2.png)

![Image](/en/images/online/sdk/a-4-2-2-1.png)

Set in the SDK code:

```js
ZCLibInitInfo *initInfo = [ZCLibClient getZCLibClient].libInitInfo;
LibInitInfo.choose_adminid = @"Customer Service ID";
libInitInfo.tran_flag =  @"0";
```
Attention:
1 choose_adminid: Specify the customer service to connect with. If not set, the default will be used.

2 tran_flag: Set whether it must be transferred to the specified customer service after setting the specified customer service.

0: Can be transferred to another customer service representative,

1: Must be transferred to the designated customer service representative.

Note: If set to 1, when the specified customer service is offline, it cannot be transferred to other customer service.

###### 3. Set up user-defined profiles and custom fields
Developers can directly pass in these user information for customer service to view.

Configure the fields you need to display on the workbench by yourself. The configuration method is shown in the figure below:

![Image](/en/images/online/sdk/a-4-2-3.png)

Custom fields with fixed keys

```js
// Set user-defined fields
- (void)customUserInformation:(ZCLibInitInfo*)libInitInfo{
LibInitInfo.customer_fields = @{@"customField22":@"I am a custom branch",
@"userSex":@"Confidential",
@"weixin":@"WeChat ID",
@"weibo":@"Weibo account",
                              @"birthday":@"2017-06-08"};
}
```


User-defined data, custom key

```js
//Custom user data
LibInitInfo.params = @{@"Nickname":@"I am Sobot, the small customer service"};

```


Sketch: ![Image](/en/images/online/sdk/a-4-2-3-1.png)


###### 4. **Set up automatic message sending after a successful transfer**
```js
// Auto-send messages
ZCLibInitInfo *initInfo = [ZCLibClient getZCLibClient].libInitInfo;
// 0 Do not send 1 Send to robot 2 Send to human 3 Send to both robot and human
initInfo.good_msg_type = 1; 
// If it is non-text, pass the local path
initInfo.content = @"123";
// Content type, 0, // Text 1, // Image 12, // File // Video
initInfo.auto_send_msgtype = 0;


/// Send message to human agent
/// @param textMsg  Message content. If it is a video, image, audio, or file, please pass the local image path.
/// @param msgType  0, // Text   1, // Image  4, // File   3, // Video
/// @param ResultBlock Sending result code == 0 means sent успешно
+ (void)sendMessageToUser:(NSString *)textMsg type:(NSInteger ) msgType resultBlock:(nonnull void (^)(NSString *, int code))ResultBlock;


```
###### 5. **Set Up Priority Access for Specific Customers in Queue**
The SDK can set the current user's queue priority. When this user enters the queue, they will be served first.

```js
// Same as PC: Settings - Online Customer Service Assignment - Queue Priority Settings - Designated Customer Priority. Pass 1 to enable; default is not set.
@property(nonatomic,assign) int queue_first;
```
###### 6. **Set Custom Fields for Service Summary**

The SDK can configure custom fields for service summaries, allowing customer service to create session summaries more quickly.

1. Get Custom Field ID

![Image](/en/images/online/sdk/a-4-2-6.png)  
![Image](/en/images/online/sdk/a-4-2-6-1.png)

2. Set custom fields for service summary (Support passing service summary parameters when transferring to human agent)
```js
InitInfo.summary_params = @{@"customField15615315349481":@"Field value1",@"customField15615315349482":@"Field value2"};
```
###### 7. **Set Multi-turn Conversation Interface Parameters**
When using the multi-round conversation feature, we will pass two fixed custom parameters, `uid` and `multiParams`, to each interface. `uid` is the unique identifier for the user, and `multiParams` is a custom field in JSON string format. If the user has integrated these two fields, we will return them to the third-party interface. If not, we will pass empty fields.

```js  

InitInfo.multi_params = @{@"customField15619769556831":@"Display xxyyyzzz1032"};

```
###### 8. Product Card
Product inquiry information and support for sending message cards directly are only available in manual mode. Configure the following information in ZCKitInfo.h, and pass it in when starting the page:

```js


/**
*   Whether to automatically send product card information (When transferring to a human agent is successful, the product card information will be sent automatically)
*   Default off. After enabling, it will only send once per session by default.
 **/
@property (nonatomic,assign) BOOL isSendInfoCard;

/*
       Does it automatically send product information every time? (When transferring to a human agent is successful, the product card information will be sent automatically.)
Need to enable isSendInfoCard = YES first
(Added in version 3.0.3)
 */
@property (nonatomic,assign) BOOL isEveryTimeSendCard;

// Custom class for products: ZCProductInfo. If you choose to add product information, please include the following details. The title "title" and page URL "link" are required fields. If these are not added, the product will not be displayed on the page.
ZCProductInfo *productInfo = [ZCProductInfo new];
//thumbUrl Thumbnail URL
ProductInfo.thumbUrl = @"Thumbnail Url";
// title Title (Required)
ProductInfo.title = @"Title";
// desc Summary
ProductInfo.desc = @"Summary";
// label tag
ProductInfo.label = @"Label";
// Page address URL (required)
ProductInfo.link = @"Send product link";
kitInfo.productInfo = productInfo;



// Manually call to directly send product card
ZCProductInfo *productInfo = [ZCProductInfo new];
ProductInfo.thumbUrl = @"Thumbnail URL";
ProductInfo.title = @"Title";
ProductInfo.desc = @"Summary";
ProductInfo.label = @"Label";
ProductInfo.link = @"Page link";
[ZCSobotApi sendProductInfo:productInfo resultBlock:nil];
```

Sketch: ![Image](/en/images/online/sdk/a-4-2-8.png)


###### 9. Order Card
The SDK can send custom order information, but this is only supported in manual mode. If you have this requirement, you can use the following method to set it up:

Configuration Button:

```js
ZCKitInfo *kitInfo=[ZCKitInfo new];
NSMutableArray *arr = [[NSMutableArray alloc] init];
ZCLibCusMenu *menu1 = [[ZCLibCusMenu alloc] init];
Menu1.title = [NSString stringWithFormat:@"Order"];
menu1.url = [NSString stringWithFormat:@"sobot://sendOrderMsg"];;
menu1.imgName = @"zcicon_sendpictures";
[arr addObject:menu1];
kitInfo.cusMoreArray = arr;
```
Simulate custom "+" click send event:  
Return YES to indicate event interception, and let the user handle it manually.
Returning NO means the event is not intercepted and will be handled internally by the Sobot SDK.

```js

     [ZCSobotApi setMessageLinkClick:^BOOL(ZCLinkClickType type, NSString * _Nonnull linkUrl, id  _Nullable object) {
     if ([linkUrl hasPrefix:@"sobot://sendOrderMsg"]){
                        ZCOrderGoodsModel *model = [ZCOrderGoodsModel new];
                            model.orderStatus = 0; // Add 0 as a custom status to display statusCustom content
                            model.statusCustom = @"Custom Status";
                        model.createTime = [NSString stringWithFormat:@"%.0f",[[NSDate date] timeIntervalSince1970]*1000];
                        model.goodsCount = @"3";
                        model.orderUrl  = @"https://www.sobot.com";
                        model.orderCode = @"1000234242342345";
                            model.goods =@[@{@"name":@"Product Name",@"pictureUrl":@"http://pic25.nipic.com/20121112/9252150_150552938000_2.jpg"},@{@"name":@"Product Name",@"pictureUrl":@"http://pic31.nipic.com/20130801/11604791_100539834000_2.jpg"}];
                        
                            // The unit is cents. It will be divided by 100 when displayed, such as 48.90.
                        model.totalFee = @"4890";
                        [ZCSobotApi sendOrderGoodsInfo:model resultBlock:nil];
                        
                        return YES;
                    }
                return NO;
    }];
```
ZCOrderGoodsModel Class Description:

```js
/**
Send order message field:
Order Status: orderStatus
Order Number: orderCode
Order creation time: createTime
Product image link: goodsPicturesUrls
Order link: orderUrl  ,
Product Description: goodsDesc
Number of items: goodsCount
Total amount: totalFee, in cents. It will be automatically formatted to yuan when displayed. For example, if you pass in 4890, it will show as 48.90 yuan.
*/
/*
Customize: 0, show the content of statusCustom
Pending Payment: 1,
To be shipped: 2,
In transit: 3,
In transit: 4,
Completed: 5,
To be reviewed: 6,
Cancelled: 7,
Other: Not in the code
 */
@property (nonatomic,assign) int orderStatus;

// Custom order status display content, only effective when orderStatus=0
@property (nonatomic,strong) NSString *statusCustom;

```

Sketch: ![Image](/en/images/online/sdk/a-4-2-9.png)


###### 10. Check if the merchant's customer service is chatting with the user (only available in the e-commerce version)
```js
/**
*   Check if the merchant's customer service is currently chatting with the user
*   appkey: Merchant ID   uid: uid in ZCPlatformInfo class
**/
+(BOOL)getPlatformIsArtificialWithAppkey:(NSString *)appkey Uid:(NSString*)uid;

-(void)tableView:(UITableView *)tableView didSelectRowAtIndexPath:(NSIndexPath *)indexPath{
 ZCPlatformInfo *info = [_listArray objectAtIndex:indexPath.row];
[ZCSobotApi getPlatformIsArtificialWithAppkey:info.appkey Uid:info.uid];
}
```
###### 11. Set VIP level and user tags

```
/**
 *
* Specify whether the customer is a VIP, 0: Regular 1: VIP
*  Same as PC: Settings - Online Customer Service Allocation - Queue Priority Settings - VIP Customer Queue Priority. Set to 1 to enable, default is not set.
* After enabling, when a specified customer initiates a consultation and there is a queue, the system will prioritize their access.
 **/
@property (nonatomic,copy) NSString *isVip;


/**
 *
* Specify the VIP level for the customer and pass in the level.
* Same as PC: Settings - Custom Fields - VIP Level, get the ID or name corresponding to the level
 **/
@property (nonatomic,copy) NSString *vip_level;


/**
*User tags, multiple fields separated by commas;
User tags can be edited in the Sobot management console (System Settings > Custom Fields > Customer Fields). Obtain the ID or name corresponding to the user tag.
 **/
@property (nonatomic,copy) NSString *user_label;

Pass the relevant fields in ZCLibInitInfo.
eg：
ZCLibInitInfo *libInitInfo = [ZCLibClient getZCLibClient].libInitInfo;
// Set VIP level by name
LibInitInfo.vip_level = @"VIP";
//You can add multiple user tags. Separate multiple tag IDs or names with commas.
LibInitInfo.user_label = @"Star, Journalist";
```

###### 12. Send custom cards to the conversation history and recommend them to customers in a systematic way
[Custom Card Parameter Description Document](/en/pages/246fbc/#goods-data-structure)

```

eg:

//1. Create SobotChatCustomCard data

SobotChatCustomCard *cardModel = [[SobotChatCustomCard alloc] init];

// Configure top guidance text, images, card descriptions
CardModel.cardGuide = @"I am the guide card language, test data...............";
CardModel.cardDesc = @"I am the guide card content desc, test data...............";
cardModel.cardImg = @"https://www.sobot.com/images/books/help/logo-efa3cf68e3.png";
cardModel.cardLink = @"https://www.sobot.com";
cardModel.cardType = 1;
CardModel.isCustomerIdentity = 0;// New field added in version 4.1.4, optional parameter, 0 System identity sends 1 Customer identity sends
// Configure custom click button
NSArray *menuTitles = @[@"View Details",@"I am a very long test aaaaaaaaassss",@"Send"];
NSMutableArray *arrMenu = [[NSMutableArray alloc] init];
for(int i=0;i<3;i++){
   SobotChatCustomCardMenu *menu = [[SobotChatCustomCardMenu alloc] init];
Menu.menuTip = @"menutip Click the button for a prompt";
   menu.menuLink = @"sobot://?link";
   menu.menuType = i;
   menu.menuName = sobotConvertToString(menuTitles[i]);
   menu.menuLinkType = i;
   [arrMenu addObject:menu];
}
  cardModel.cardMenus = arrMenu;
  
// Configure the custom card middle list section
NSMutableArray *arrInfo = [[NSMutableArray alloc] init];
for(int i=0;i<3;i++){
   SobotChatCustomCardInfo *cardInfo = [[SobotChatCustomCardInfo alloc] init];
CardInfo.customCardName = [NSString stringWithFormat:@"1%d I am the card name",i];
   cardInfo.customCardThumbnail = @"https://t10.baidu.com/it/u=3829074670,206323120&fm=30&app=106&f=JPEG?w=312&h=208&s=159E7F97C67C578C3C50FCEB0300B035";
   cardInfo.customCardId = cardModel.cardId;
CardInfo.customCardDesc = @"I am card description I am card description I am card description I am card description I am card description";
   cardInfo.customCardCode = @"code000cc1";
   cardInfo.customCardLink = @"https://www.sobot.com/en";
   cardInfo.customCardTime = @"2023-06-09 17:11:10";
   cardInfo.customCardStatus = @"I am cardStatus";
   cardInfo.customCardAmountSymbol = @"￥";
   cardInfo.customCardAmount = @"6888.00";
   cardInfo.customMenus = [[NSMutableArray alloc] initWithArray:arrMenu];
   cardInfo.customCardCount = @"3";
CardInfo.customCardQuestion = @"The question label of the first question";//Added in version 4.1.4, optional parameter, used to trigger knowledge base questions when sending to the robot
   [arrInfo addObject:cardInfo];
}
            
cardModel.customCards = arrInfo;
// Configure custom fields
cardModel.customField = @{
@"Time":@"Custom 2023-6-9",
@"Location1":@"Somalia",
@"Location 2":@"Colombia",
@"location3":@"San Diego",
@"Status":@"Test Status",
@"Completed":@"Customer has signed for delivery"
};
cardModel.cardStyle = 1;
CardModel.cardId = @"Order Number";
            
2. Call the send custom card API to send a custom card
[ZCSobotApi sendCustomCardToRecord:cardModel resultBlock:^(NSString * _Nonnull msg, int code) {
                
}];

```


##### ● Message Ticket Related

###### 1. Workbench Settings Comment Interface
You can set up the message interface on the workbench.

![Image](/en/images/online/sdk/a-4-3-1.png)


###### 2. Custom Configuration of User Information on the Message Page
The validation and display logic for the three parameters of email, phone, and attachment in the message can be configured on the PC console page.

![Image](/en/images/online/sdk/a-4-3-2.png)

###### 3. Jump to the message page
You can directly jump to the comment page:

```js

ZCKitInfo *kitInfo = [[ZCKitInfo alloc] init];
KitInfo.leaveContentPlaceholder = @"Please enter content";
KitInfo.leaveMsgGuideContent = @"This is my custom guide message";
NSMutableArray *customField = [[NSMutableArray alloc] init];
[customField addObject:@{@"id" : @"510fb45d6e9d4a9c99a7c24861d584d7", @"value" : @"ca55f29ed5dd4879bdf3ab213fec3381"}];
[customField addObject:@{@"id" : @"6ee93dd945ac47fcac1a80bf03fd23fd", @"value" : @"6ee93dd945ac47fcac1a80bf03fd23fd"}];
[customField addObject:@{@"id" : @"abd0229cd5a64798b74516b3f09bbd7e", @"value" : @"abd0229cd5a64798b74516b3f09bbd7e"}];
                        
kitInfo.leaveCusFieldArray = [customField copy];
// To enter the message-to-ticket system, you need to connect to the required fields.
KitInfo.leaveParamsExtends = @[@{@"id":@"d93847a05710483893fd2d05e16a2b82",@"params":@"msgid",@"value":@"Data 1"}];
kitInfo.leaveMsgGroupId = @"540a910a760f4387918b0fa7302a0eca";
[ZCSobotApi openLeanve:0 kitinfo:kitInfo with:self onItemClick:^(NSString *msg, int code) {
                            
     }];
```
Among the parameters:

```js  
/**
Customize the preset message content. If internationalization is needed, you can translate it in the bundle file using the message as the key.
"Please enter content"="Please enter content";
 */
@property (nonatomic,strong) NSString *leaveContentPlaceholder;

/**
Customize the message prompt. If internationalization is needed, you can use the text as the key in the bundle file and translate it accordingly.
"Unable to answer your question, you can leave a message"="Please leave";
 */
@property (nonatomic,strong) NSString *leaveMsgGuideContent;

/**
*  Go directly to the custom field for messages
* Array, can pass multiple
*  id: The id of the custom field
*  value: Data you want to pass
*  @{@"id":@"",@"value":@"I am data"}
 **/
@property (nonatomic,strong) NSMutableArray * leaveCusFieldArray;


/**
*  To enter the message-to-ticket system, you need to connect to the required fields.
* Array, can pass multiple
* id: The system automatically generates an ID for the docking field.
*  value: Data you want to pass
* params: The field ID to display, such as city, address, corresponding to id
*  @{@"id":@"textfield12",@"value":@"I am data",@"params":@"city"}
 **/
@property (nonatomic,strong) NSMutableArray * leaveParamsExtends;


/**
 Message skill group id
Get: Settings —> Ticket Skill Group Settings
*/
@property (nonatomic,strong) NSString * leaveMsgGroupId;

```

###### 4. Message Page Event Interception
Messages in the SDK can redirect to a custom page. If you have this requirement, you can use the following method to set it up:

```js
/// Intercept the message event. If this method is implemented, the SDK will no longer handle the message event internally. Users can redirect to their own message page.
/// @param leavePageBlock The obtained parameter object
+(void)setCustomLeavePageBlock:(BOOL(^)(NSDictionary * dict))leavePageBlock;
  [ZCSobotApi setCustomLeavePageBlock:^BOOL(NSDictionary * _Nonnull dict) {
        NSLog(@"%@",dict);
        return YES;
    }];
```

###### 5. Work Order Reply Button
You can configure whether to display the message button through parameters:

```js
/**
* After leaving a message, does the reply button show up?
*   Default is yes, you can reply
 */
@property (nonatomic,assign) BOOL leaveCompleteCanReply;
```

###### 6. Get the latest comment replies

```
/// Get the latest reply
/// @param partnerid  User ID
/// @param ResultBlock code=1 returns success,
/// dict :data:items:[{(ticketId(Ticket ID),ticketTitle(Ticket Title),replyContent(Reply Content),replyTime(Reply Time),customerId(Customer ID),serviceNick(Service Nickname))}]
+ (void)getLastLeaveReplyMessage:(NSString *) partnerid resultBlock:(void (^)(NSDictionary *dict,NSMutableArray *arr,int code))ResultBlock;

Example code
 [ZCSobotApi getLastLeaveReplyMessage:[ZCLibClient getZCLibClient].libInitInfo.partnerid resultBlock:^(NSDictionary * _Nonnull dict, NSMutableArray * _Nonnull arr, int code) {
                            if(arr!=nil && arr.count > 0){
                                ZCRecordListModel *model = [arr firstObject];
                                
                                    // Notification parameters
                                NSString *identifier = [NSString stringWithFormat:@"leavereply.www.sobot.com%f",[[NSDate date] timeIntervalSinceNow]];
                                NSDictionary *userInfo = @{@"msgfrom":@"sobot",@"pushType":identifier,
                                             @"ticketId":model.ticketId
                                };
                                
                                
                                    NSTimeInterval time = [model.replyTime doubleValue]/1000; // If the passed timestamp str is accurate to milliseconds, remember to divide it by 1000.
                                NSDate *detailDate = [NSDate dateWithTimeIntervalSince1970:time];
                                    NSDateFormatter *dateFormatter = [[NSDateFormatter alloc] init]; // Instantiate an NSDateFormatter object
                                    // Set the time format, you can change it to the format you need here
                                [dateFormatter setDateFormat:@"MM-dd HH:mm"];
                                NSString *currentDateStr = [dateFormatter stringFromDate:detailDate];
                                
                                NSString *replyContent = model.replyContent;
                                replyContent = [replyContent stringByReplacingOccurrencesOfString:@"<p>" withString:@""];
                                replyContent = [replyContent stringByReplacingOccurrencesOfString:@"</p>" withString:@""];
                                replyContent = [replyContent stringByReplacingOccurrencesOfString:@"<br/>" withString:@""];
                                NSString *replyStr = [NSString stringWithFormat:@"%@\n %@ \n %@",model.ticketTitle,currentDateStr,replyContent];
                                
                                
                                
                                [ZCSobotApi postLocalNotification:replyStr dict:userInfo];
                            }
                        }];
```


###### 7. Add a switch for proactive reminders to leave a message or review

```
Pass in the relevant fields in ZCKitInfo
eg：
ZCKitInfo *kitInfo=[ZCKitInfo new]; 
// Completed message details page: Whether to pop up the service evaluation window when returning (It will only pop up the first time, and will not pop up again the next time)
// Default is NO, no active reminders
kitInfo.showLeaveDetailBackEvaluate = YES;

```

###### 8. Add extended parameters for leaving a message
Pass in the relevant fields in ZCKitInfo, field description;

```  
/**
*  Go directly to the custom field for leaving messages
* Array, can pass multiple
*  id: The id of the custom field
*  value: Data to be passed
*  @{@"id":@"",@"value":@"I am data"}
 **/
@property (nonatomic,strong) NSMutableArray * leaveCusFieldArray;



/**
*  Go directly to the message field
* Array, can pass multiple
* id: The system automatically generates an ID for the docking field.
*  value: Data you want to pass
* params: The field ID to display, such as city, address, corresponding to id
*  @{@"id":@"textfield12",@"value":@"I am data",@"params":@"city"}
 **/
@property (nonatomic,strong) NSMutableArray * leaveParamsExtends;


/**
Message Skill Group ID
Get: Settings —> Ticket Skill Group Settings
*/
@property (nonatomic,strong) NSString * leaveMsgGroupId;


```

##### ● Evaluation
###### 1. Set up the rating interface
You can set up the satisfaction rating interface on the workbench.

![Image](/en/images/online/sdk/a-4-4-1.png)


###### 2. Evaluation Related Configuration
```js
/**
 *
*   Whether to display the rating button in the upper right corner of the navigation bar. Default is not displayed.
 *
 **/
@property (nonatomic,assign) BOOL isShowEvaluation;

/**
*In the upper right corner of the navigation bar, whether to display the close button. By default, it is not displayed. After clicking the close button, background message listening will be disabled.*
 **/
@property (nonatomic,assign) BOOL isShowClose;

/**
 *
* For the close button, set whether to display the evaluation interface separately. Default is not to display.
 *
 **/
@property (nonatomic,assign) BOOL isShowCloseSatisfaction;
/**
* Evaluate whether to close the session after manual service (Release the session after manual satisfaction evaluation)
 *  Default is NO, not enabled
 *
 */
@property (nonatomic,assign) BOOL      isCloseAfterEvaluation;
/**
* Whether to enable satisfaction evaluation upon return
* Default is NO, not enabled
 *
 */
@property (nonatomic,assign) BOOL      isOpenEvaluation;


/**
*  When returning, enable satisfaction evaluation and display "Not to evaluate for now"
* Default is NO, not enabled
 */
@property (nonatomic,assign) BOOL      canBackWithNotEvaluation;

```

Reference effect:  

![Image](/en/images/online/sdk/a-4-4-2.png)
![Image](/en/images/online/sdk/a-4-4-2-1.png)

###### 3. Ask users for feedback when they return, and ask for feedback when they close
```js
// Whether to enable satisfaction evaluation when returning or closing. Default is NO, not enabled.
kitInfo.isOpenEvaluation = @"YES";
// Whether to close the session after manual evaluation (release session after manual satisfaction evaluation) Default is NO, not enabled
kitInfo.isCloseAfterEvaluation = @"YES";

// Whether there is a return prompt, default is NO. Set to YES, it will remind "Whether to end the session"
kitInfo.isShowReturnTips = YES;

```

###### 4. Configure the session to be released after the user submits a manual satisfaction evaluation
```js

/**
*  Evaluate whether to close the session after human service (Release the session after human satisfaction evaluation)
* Default is NO, not enabled
 *
 */
@property (nonatomic,assign) BOOL      isCloseAfterEvaluation;

```

###### 5. When returning from the top left corner and closing from the top right corner, whether to display the "Not Evaluate for Now" button in the manual satisfaction evaluation pop-up interface configuration
```js

/**
*  When returning, enable satisfaction evaluation and display "Not evaluate for now" option
* Default is NO, not enabled
 */
@property (nonatomic,assign) BOOL      canBackWithNotEvaluation;

```


##### ● Message Related
###### 1.  Message Push Notifications
Note: If you need the SDK push function, please refer to the following message notification and registration push related code. If your project does not need it, please skip.

1. When generating the appkey, upload the push certificate (.p12 format). The exported certificate must have a password.

2. Push notifications are only effective for manual conversations. The robot answers directly without push notifications. When local IM communicates normally, it will directly use the IM channel and will not send APNs push notifications.

Relevant configuration and code

Push ZCLibClient.h Key Property Description

```js
/**
Push token
The app needs to be reset every time it starts.
*/
@property (nonatomic,strong) NSData *token;
/**
Test mode,
According to this setting, the push certificate is called by default, NO.
NO, call the production environment
YES, Test Environment
*/
@property (nonatomic,assign) BOOL isDebugMode;

/**
Automatic reminder messages
Note: If automatic reminder messages are enabled, when you are not on the Sobot chat page, all messages will be actively displayed as local notifications.
This reminder is a local message push. It is unrelated to APNS and is only a notification for local IM messages not on the chat page.
*/
@property (nonatomic,assign) BOOL autoNotification;


/**
Exit the backend, automatically close long connections, default NO
Explanation: If set to YES, the channel will close immediately after exiting the background, without affecting the duration of the app running in the background.
 */
@property (nonatomic,assign) BOOL autoCloseConnect;

/**
Get the number of unread messages
@return Number of unread messages (Entering the Sobot chat page will clear them)
*/
-(int) getUnReadMessage;
```
Register for Push Notifications

Register push notifications in the AppDelegate.m file.

Import header files

```js
#import <SobotKit/SobotKit.h>
#import <UserNotifications/UserNotifications.h>
#define SYSTEM_VERSION_GRATERTHAN_OR_EQUALTO(v)  ([[[UIDevice currentDevice] systemVersion] compare:v options:NSNumericSearch] != NSOrderedAscending)
```
Agree to the terms

```js

<UIApplicationDelegate,UNUserNotificationCenterDelegate>

```
Register

```js
- (BOOL)application:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)launchOptions {
    // Override point for customization after application launch.
    
    [[UIApplication sharedApplication] setStatusBarHidden:YES withAnimation:UIStatusBarAnimationNone];
    [[UIApplication sharedApplication] setStatusBarHidden:NO withAnimation:UIStatusBarAnimationNone];
    
    if (SYSTEM_VERSION_GRATERTHAN_OR_EQUALTO(@"10")) {
        UNUserNotificationCenter *center = [UNUserNotificationCenter currentNotificationCenter];
        center.delegate = self;
        [center requestAuthorizationWithOptions:(UNAuthorizationOptionSound | UNAuthorizationOptionAlert |UNAuthorizationOptionBadge) completionHandler:^(BOOL granted, NSError * _Nullable error) {
            if (!error) {
                [[UIApplication sharedApplication] registerForRemoteNotifications];
            }
        }];
    }else{
         [self registerPush:application];
    }
    [[ZCLibClient getZCLibClient].libInitInfo setApp_key:@"your appKey"];
    // Set whether the push is in the test environment. The test environment will use the development certificate.
    [[ZCLibClient getZCLibClient] setIsDebugMode:YES];
    // Error log collection
    [ZCLibClient setZCLibUncaughtExceptionHandler];
    return YES;
}
 
-(void)registerPush:(UIApplication *)application{
    // After iOS8, you need to add this registration to get authorization.
    if ([[UIApplication sharedApplication] respondsToSelector:@selector(registerUserNotificationSettings:)]) {
        //IOS8
        // Create UIUserNotificationSettings and set the message display type
        UIUserNotificationSettings *notiSettings = [UIUserNotificationSettings settingsForTypes:(UIUserNotificationTypeBadge | UIUserNotificationTypeAlert | UIRemoteNotificationTypeSound) categories:nil];
        
        [application registerUserNotificationSettings:notiSettings];
        
    } else{ // ios7
        [application registerForRemoteNotificationTypes:(UIRemoteNotificationTypeBadge|UIRemoteNotificationTypeSound|UIRemoteNotificationTypeAlert)];
    }
}

- (void)application:(UIApplication *)application didRegisterForRemoteNotificationsWithDeviceToken:(NSData *)pToken{
    NSLog(@"---Token--%@", pToken);
    // Register token
    [[ZCLibClient getZCLibClient] setToken:pToken];

}
```


###### 2.  Set whether to enable message notifications
When the user is not on the chat interface and receives a message from customer service, the app can show a reminder in the notification bar or at the chat entry. The notification bar reminder can display the content of the most recent message.


```js  
// Whether to automatically remind. When the user is not on the chat page, send a local push notification upon receiving a local connection message.
[[ZCLibClient getZCLibClient] setAutoNotification:YES];
 
// Set up the push environment
[ZCSobotApi setShowDebug:YES]; 

```


###### 3.  Offline Messages
Offline Message Settings

```js

// Set to automatically disconnect long connections when switching to the background. This will not affect the duration of the APP being suspended in the background.
// The system will automatically reconnect when entering the foreground. During disconnection, messages will be sent via APNs push notifications.
[ZCLibClient getZCLibClient].autoCloseConnect = YES;



// @note Check if the current message channel is established. If not, re-establish it. After calling closeIMConnection, you can call this method to reconnect.
[[ZCLibClient getZCLibClient] checkIMConnected];  
/* Check if the current listener is removed. If removed, register again (reactivate).
Network listening ZCNotification_NetworkChange
 UIApplicationDidBecomeActiveNotification
 UIApplicationDidEnterBackgroundNotifica
)，often used together with checkIMConnected
*/
[[ZCLibClient getZCLibClient] checkIMObserverWithRegister];
/**
 Remove all IM listeners, which may affect the app's background running time. If you need to reactivate after calling this method, use checkIMObserverWithCreate.
Network Monitoring ZCNotification_NetworkChange
 UIApplicationDidBecomeActiveNotification
 UIApplicationDidEnterBackgroundNotification
 */
[[ZCLibClient getZCLibClient] removeIMAllObserver];

/**
@note Close the current message channel so it no longer accepts messages. If push is configured, messages will be delivered via APNs.
 */  
 [[ZCLibClient getZCLibClient] closeIMConnection];
 
 
 

     
// ReceivedMessageBlock Number of unread messages, obj Current message, unRead Number of unread messages
 [ZCLibClient getZCLibClient].receivedBlock = ^(id obj,int unRead,NSDictionary *object){
//        NSLog(@"Current number of messages: %d \n %@", unRead, obj);
    };
    
// Close the channel, clear memory, and exit Sobot client (If currently in human consultation, the client will go offline; if in robot mode, it will directly interrupt the current session, and the next entry will be a new session)
// Note: After calling this method, you will not receive offline messages unless you enter the Sobot SDK again to reactivate it.
// isClosePush:YES, means to close push; NO for offline users, but can still receive push notifications
+(void) closeAndoutZCServer:(BOOL) isClosePush; 
//Example
[ZCLibClient  closeAndoutZCServer:YES];
```


###### 4.  Send Location Message
Send location information. This method can only initiate a location call when the initialization link is received and the URL is listened to as sobot://sendlocation. Otherwise, the sending may fail.

```js
ZCKitInfo *uiInfo=[ZCKitInfo new];

// Configure the send button. Note that menu1.url = sobot://sendlocation is listened in messageLinkClick of the launch page.
NSMutableArray *arr = [[NSMutableArray alloc] init];
    for (int i = 0; i<1; i++) {
        ZCLibCusMenu *menu1 = [[ZCLibCusMenu alloc] init];
        menu1.title = [NSString stringWithFormat:@"Location"];
        menu1.url = [NSString stringWithFormat:@"sobot://sendlocation"];;
        menu1.imgName = @"zcicon_sendlocation";
        [arr addObject:menu1];
        ZCLibCusMenu *menu2 = [[ZCLibCusMenu alloc] init];
Menu2.title = [NSString stringWithFormat:@"Product"];
        menu2.url = [NSString stringWithFormat:@"sobot://sendProductInfo"];;
        menu2.imgName = @"zcicon_sendpictures";
        [arr addObject:menu2];
    }
uiInfo.cusMoreArray = arr;



// Method to send location, fullPath is the complete local path of the image
[ZCSobotApi sendLocation:@{
                        @"lat":@"40.001693",
                        @"lng":@"116.353276",
@"localLabel":@"23rd Floor, Building A, Jinma Tower, No. 38 Xueqing Road, Haidian District, Beijing, Jinma Grand Hotel",
@"localName":@"Cloud View Four Seasons Restaurant",
                        @"file":fullPath}];
```

###### 5. Link Interception
You can do this by initializing the previous code:

```js

/// Click the link to intercept Help Center, Messages, Chat, Message History
/// @param messagelinkBlock Get the link. If YES is returned, then intercept it.
     [ZCSobotApi setMessageLinkClick:^BOOL(ZCLinkClickType type, NSString * _Nonnull linkUrl, id  _Nullable object) {
        return NO;
    }];
```
Block users from clicking links in messages
###### 6.  Listen for changes in the current chat mode

You can do this by initializing the previous code:

```js
    
// Current user session status
typedef NS_ENUM(NSInteger,ZCServerConnectStatus) {
    ZCServerConnectOffline    = 0, // The current session has ended
    ZCServerConnectRobot      = 1, // Robot
    ZCServerConnectArtificial = 2, // Artificial connection successful
    ZCServerConnectWaiting    = 3  // Queue for manual service only
};
[[ZCLibClient getZCLibClient] setServerConnectBlock:^(id message, ZCServerConnectStatus status, NSDictionary *object) {
       
        
    }];
    
    
/// Click the back function event listener, replace with setFunctionClickListener
/// @param backBlock id of the current viewcontroller, type: help center, message, chat, session list
+(void)setZCViewControllerBackClick:(void (^)(id currentVC,ZCPageCloseType type))backBlock;
    
```

###### 7.  Regular expression for replacing mobile or landline numbers in messages

Change your own phone number recognition rules:

```js
    
/**
*  Phone number regular expression
* Default is @"0+\d{2}-\d{8}|0+\d{2}-\d{7}|0+\d{3}-\d{8}|0+\d{3}-\d{7}|1+[34578]+\d{9}|\+\d{2}1+[34578]+\d{9}|400\d{7}|400-\d{3}-\d{4}|\d{11}|\d{10}|\d{8}|\d{7}"
* For example: 82,563,452, 01082563234, 010-82543213, 031182563234, 0311-82563234
 、+8613691080322、4008881234、400-888-1234
 */
@property (nonatomic,strong) NSString * telRegular;

```


###### 8.  Replace the regular expression for identifying hyperlinks in chat messages

Change the recognition rules for hyperlinks in messages:

```js
    

/**
*  Link address regular expression
 *  Default is:
    @"((http[s]{0,1}|ftp)://[a-zA-Z0-9\\.\\-]+\\.([a-zA-Z0-9]{1,4})(:\\d+)?(/[a-zA-Z0-9\\.\\-~!@#$%^&*+?:_/=<>]*)?)|(([a-zA-Z0-9]{2,4}).[a-zA-Z0-9\\.\\-]+\\.([a-zA-Z]{2,4})(:\\d+)?(/[a-zA-Z0-9\\.\\-~!@#$%^&*+?:_/=<>]*)?)"
 */
@property (nonatomic,strong) NSString * urlRegular;


```


###### 9.  Hide time prompts in the message list


```js
    

/**
Whether to hide the session time. Default is NO, not hidden. If not in the China region, there may be a time difference between the client and the real time, so you can choose to hide the time in the session.
*/
@property (nonatomic,assign) BOOL hideChatTime;


```


##### ● Custom UI Settings
1.  In the navigation bar area, we support customizing the color of the navigation bar area and its font color;
2. In the chat page area, we support customizing the background color of the chat area, chat bubble color, chat font color, prompt bubble color, prompt font color, and time text color;
3. In the bottom area, we support customizing the background color of the bottom section and the line color of the input box;
4. For other parts, we support customizing the background color and text color of the album navigation bar, the text color and button color in the rating pop-up box, the text in the recording control, and the text color in the product details display (title, details, tags, send).
5. Image replacement: If you want to replace the images displayed in the SDK, you can directly replace the resources in SobotKit.bundle; alternatively, you can place a resource with the same name in your own project, and the system will prioritize obtaining the image resources from the project.

###### 1. Configure Property Values
For specific code implementation, please check the ZCKitInfo.h file in the code and refer to the ZCKitInfo class description.

```js

ZCKitInfo *uiInfo=[ZCKitInfo new];
// For example: Set the background of the chat page to red
uiInfo.backgroundColor = [UIColor redColor];
// Set the top navigation to green
uiInfo.topViewBgColor = [UIColor greenColor];

// The launch page can be passed in directly
[ZCSobotApi openZCChat:uiInfo with:self pageBlock:^(id  _Nonnull object, ZCPageStateType type) {
        }];


```

[Note: For custom UI not covered by the code, you can directly replace the images in SobotKit.bundle to achieve your desired effect, or simply place an image with the same name in your project. Currently, the SDK only supports the following HTML tags: hyperlink A, italic I, bold: strong, b, and line break br. These tags can be freely combined. Other HTML tags will be filtered out as they cannot be properly processed by the SDK.]

###### 2. Customize Top Title
```js
/**
*   Starting from V4.0.0, customize the top title of the chat page: avatar, customer service nickname, company name
*   By default, use the PC workstation settings. Method 1 displays the reception staff + company name, and method 2 displays company information + reception status.
*   If you want to set custom controls on the SDK side, you need to set the following at the same time: 1. Whether to show the avatar switch, 2. Whether to show the company name switch, 3. Whether to show the customer service nickname switch. If any of these three switches are not set, the default setting from the PC workstation will be used.
 *
 *
*    Original  title_type in use
 *   
 */

// The following properties are in the ZCKitInfo class
/// Whether to display the custom image at the top of the chat page. Default is NO, following the PC end switch setting.
@property(nonatomic,assign) BOOL isShowTitleViewImg;

/**
* Custom image for the top title of the chat page, needs to be used together with isShowTitleViewImg.
*/
@property(nonatomic,strong) NSString *custom_title_url;

/// Whether to display the custom customer service nickname at the top of the chat page. Default is NO, following the PC settings.
@property(nonatomic,assign) BOOL isShowTitleViewNick;

/**
* Customize the nickname of the receptionist at the top title of the chat page. Use it together with isShowTitleViewNick.
*/
@property(nonatomic,strong) NSString *custom_nick_title;

/// Whether to display the customized enterprise name at the top title of the chat page. Default is NO, following the PC-end switch setting.
@property(nonatomic,assign) BOOL isShowTitleViewCompanyName;

/**
* Customize the company name in the top title of the chat page. Use it together with isShowTitleViewCompanyName.
*   If isShowTitleViewCompanyName, custom_company_title takes the value set on the PC end when it is empty.
*/
@property(nonatomic,strong) NSString *custom_company_title; 

```


##### ●  Other Configurations

###### 1. Customize the display time range for chat history
If you want to set users to only see chat records within xx days, you can call the following method to make the setting:

```js
/**
History record time range, in minutes (Example: 100 - represents sessions from 100 minutes ago up to now)
 */

@property(nonatomic,assign) int scope_time;
```

2. Add custom button


In the customer service chat interface, after clicking the "+" button, a menu panel will appear. You can add menus as needed. The code is as follows:

```js
    ZCKitInfo *uiInfo=[ZCKitInfo new];
    NSMutableArray *arr = [[NSMutableArray alloc] init];
    for (int i = 0; i<1; i++) {
        ZCLibCusMenu *menu1 = [[ZCLibCusMenu alloc] init];
        menu1.title = [NSString stringWithFormat:@"Order"];
        menu1.url = [NSString stringWithFormat:@"sobot://sendOrderMsg"];
        menu1.imgName = @"zcicon_sendpictures";
        [arr addObject:menu1];
        
        ZCLibCusMenu *menu2 = [[ZCLibCusMenu alloc] init];
        menu2.title = [NSString stringWithFormat:@"Product"];
        menu2.url = [NSString stringWithFormat:@"sobot://sendProductInfo"];
        menu2.imgName = @"zcicon_sendpictures";
        
        [arr addObject:menu2];
    }
    
    
    uiInfo.cusMoreArray = arr;
    
    uiInfo.cusRobotMoreArray = arr;
```
Among them:

``` 

/**
* Content below the custom input box's more (+ icon) button (will not replace existing content, will append to the original content)
* Change the button for manual mode
* Fill in the content: ZCLibCusMenu.h
* title: Button Name
* URL: Click the link (Clicking will call the initialization of linkBock)
* imgName: Local image name, such as xxx@2x.png, icon=xxx
 */
@property (nonatomic,strong) NSMutableArray * cusMoreArray;

/**
* Content below the custom input box and more (+ icon) button (will not replace existing content, will append to the original content)
* Button to modify robot mode
 * Fill content with: ZCLibCusMenu.h
* title: Button Name
* url: Click the link (Clicking will call the initialization of linkBock)
* imgName: Local image name, such as xxx@2x.png, icon=xxx
 */
@property (nonatomic,strong) NSMutableArray * cusRobotMoreArray;
```
###### 4.  Call up the dialing interface API
```js
/**
 *  Set phone number
* When the dial button is displayed in the upper right corner of the navigation bar (effective when set together with isShowTelIcon)
 *
 **/
@property (nonatomic,copy) NSString * customTel;
/**
 *
*   Top right corner of the navigation bar: Whether to display the dial button. Default is not displayed. Note: Mutually exclusive with isShowEvaluation. Only one can be set as valid.
 *
 **/
@property (nonatomic,assign) BOOL isShowTelIcon;
```
###### 5. Sobot Log Display Switch
```js
/**
* Show log information
 *
* @param isShowDebug Not shown by default
 */
+(void) setShowDebug:(BOOL) isShowDebug;
```
###### 6. IOS Multi-language Support
Currently, the SDK supports two languages: English and Chinese. The language will automatically switch and adapt based on the current phone language. If the current phone language is not recognized, it will default to Chinese.

Language files are uniformly placed in the SobotKit.bundle file. If you need to add a new language package, place the supported language file in the corresponding language directory. For example: English path: SobotKit.bundle/en_lproj/SobotLocalizable.strings, Chinese path: SobotKit.bundle/zh-Hans_lproj/SobotLocalizable.strings;

[Note: The language folder name is the current language name followed by _lproj, such as zh-Hans_lproj, en_lproj]

[《Customer SDK Supported Language Code Table》](/en/pages/246fbc/#language-code)

```js

//Get language name
NSString * languages = [ZCSobotApi getCurLanguagePreHeader];


    ZCLibInitInfo *initInfo = [ZCLibClient getZCLibClient].libInitInfo;

// Set the default language. If the current system language cannot be identified, the default language is not set to en_lproj.
initInfo.default_language = @"zh-Hans_lproj";

// Specify the language, do not change based on the system. If the specified language is not found, follow the default language logic.
initInfo.absolute_language = @"ar_lproj";


// Download language (provided after 2.8.6). If you need to support other languages outside the bundle package, you can provide us with the language translation to include in our server for dynamic synchronization.
/// Synchronize language files from the server
/// @param lan  The language to sync. If it already exists in the local bundle, it will not be downloaded, en_lproj, zh-Hans_lproj
/// @param isReWrite  Whether to download again if it has already been downloaded
+(void)synchronizeLanguage:(NSString *) language write:(BOOL) isReWrite;



```


Special Handling:  
If multi-language is configured with human evaluation or robot evaluation tags, multi-language display is not supported. You can hide the display through the following attributes (this does not affect the use of the evaluation function, only the tag content will be missing in the evaluation).

```js

// Hide robot is evaluation tag
_kitInfo.hideRototEvaluationLabels = YES;

//  Hide manual hour rating tags
_kitInfo.hideManualEvaluationLabels = YES;





```


###### 7. Time Zone Adaptation
Starting from version 2.8.9, it is supported by default. The system uses Beijing East Eight Zone standard time. If adapting dynamically based on mobile time, configure the following code:  

```js

[ZCSobotApi setAutoMatchTimeZone:YES];

```

###### 8. Sobot partial function page click back and event monitoring (only records without interception), you can add your own logic (e.g., tracking)

```js

    [ZCSobotApi setFunctionClickListener:^(id _Nonnull obj, ZCPageCloseType type) {
        	 //1: Return from message, 2: Return from session page, 3: Return from help center, 4: Return from e-commerce message center page, 5: Telephone call button
NSLog(@"Clicked and returned %@, %zd", obj, type);
    }];

```


###### 9. Security Check
1. Function location: Online channel settings - Channel security settings - Security key settings - Check "Effective scope (APP)".

2. After enabling the APP "Security Key" function, the SDK channel must pass the partnerid parameter. When integrating, add the parameters "sign" and "create_time". Here, sign = "MD5(app_key + partnerid + secret + create_time)", createTime is a Unix millisecond timestamp; secret is a 32-character string, and create_time is a millisecond-level timestamp.

3. After passing parameters, Sobot will decrypt the sign and verify whether the passed partnerid matches the partnerid in the sign. If they match, the system will connect to Sobot normally. If not, the connection will fail. If the customer does not pass the partnerid or sign, they will be considered an illegal user, and the connection will fail. If the create_time differs from the current time by more than 5 minutes, the user will be considered illegal, and the connection will fail.

4. Turning on and off the "Security Key" feature in the APP takes effect immediately. The scope of effectiveness is also applied in real time.

```js  

ZCLibInitInfo *initInfo = [ZCLibClient getZCLibClient].libInitInfo;

// Set encryption time
_libInitInfo.create_time = [ZCSobotApi zcGetCurrentTimes];
_libInitInfo.secret = @"Encryption string";
_libInitInfo.partnerid = @"your id";
// The string after md5,
_libInitInfo.sign = [self getSign];


// Reference implementation method
-(NSString *)getSign{
    NSString *sign =  [NSString stringWithFormat:@"%@%@%@%@",_libInitInfo.app_key,_libInitInfo.partnerid,_libInitInfo.secret,_libInitInfo.create_time];
    NSLog(@"sign:%@",sign);
    return [ZCSobotApi zcMd5Sign:sign];
}

```


#### Configuration Attribute Description
##### ● ZCKitInfo Class Description (UI Related Configuration)
You can reset the Sobot page every time it starts.
###### 1. UI Logic Related:
| Attribute Name | Data Type | Description | Notes |
|:----|:----|:----|:----|
| isOpenEvaluation   | BOOL   | Whether to enable satisfaction evaluation when clicking back   | Default is NO, not enabled   |
| isCloseAfterEvaluation   | BOOL   | After enabling satisfaction evaluation when clicking back, whether to close the session after the evaluation is completed by the user   | Default is NO, not enabled     
| isShowTelIcon   | BOOL   | Whether to show the dial button at the top right corner of the navigation bar. Hidden by default. Note: Mutually exclusive with isShowEvaluation. Only one can be set as valid. |      |
| isShowEvaluation   | BOOL   | Whether to show the evaluation button at the top right corner of the navigation bar   | Hidden by default   |
| customTel | NSString | When the dial button is displayed at the top right corner of the navigation bar (effective when set together with isShowTelIcon) |    |
| isOpenRecord   | BOOL   | Whether to enable voice function (during manual reception)   | Default YES, enabled   |
| isSetPhotoLibraryBgImage   | BOOL   | Whether to set the photo library background image (if not set, it will follow the navigation color configuration)   |    |
| isOpenRobotVoice   | BOOL   | Whether to enable robot voice (requires activation; robots cannot recognize voice if not activated)   |    |
| navcBarHidden   | BOOL   | Use a custom navigation bar in the SDK page, hide the system navigation bar.   |    |
| isSendInfoCard   | BOOL   | Whether to automatically send product card information (When transferring to human agent succeeds, product card information will be sent automatically) Default: Not automatically sent   |    |
| isEveryTimeSendCard   | BOOL   | Whether to automatically send product information every time (When transferring to human agent successfully, the product card information will be sent automatically) Need to enable isSendInfoCard = YES first   |    |
| productInfo   | ZCProductInfo   | Product information, use with isSendInfoCard   |    |
| isShowCloseSatisfaction   | BOOL   | Whether to show the evaluation interface when closing the button. Default is not to show. |    |
| isShowReturnTips   | BOOL   | Whether to show a prompt when returning. The default prompt text is: Are you sure you want to end the session? If you need to modify it, please update the internationalization configuration file. |    |
| ishidesBottomBarWhenPushed   | BOOL   | Hide BottomBar after push    | Default is yes   |
| isShowPortrait   | BOOL   | Only supports portrait mode   | Default is NO   |
| isCloseInquiryForm   | BOOL   | Whether to close the pre-inquiry form (default is NO, using the system default configuration)   |    |
| isShowClose   | BOOL   | Whether to show the close button at the top right corner of the navigation bar. Hidden by default. After clicking the close button, background message listening will be disabled.   |    |
| isUseImagesxcassets   | BOOL   | Whether to use images in .xcassets   | Default is NO, not enabled   |
| autoSendOrderMessage   | BOOL   | After manual operation, whether to actively send a message   |    |
| isEveryTimeAutoSend   | BOOL   | Whether to send order information every time. You need to set the parameter autoSendOrderMessage = YES first.   |    |
| orderGoodsInfo   | ZCOrderGoodsModel   | Order information that needs to be sent, used together with autoSendOrderMessage   |    |
| leaveCompleteCanReply   | BOOL   | Whether to show the reply button after leaving a message   | Default is yes, can reply   |
| themeStyle   | BOOL   | Whether to set to dark mode, 2: normal mode, 1: dark mode, 0: follow system settings   | Default is 0   |
| useDefaultDarkTheme   | BOOL   | If custom colors are set, whether to use the default dark mode. If set to NO, the custom color attributes will not work in dark mode.   | Default is YES  |
| leaveContentPlaceholder   | NSString   | Custom leave message content placeholder   |   |
| leaveMsgGuideContent   | NSString   |  Custom leave message guidance   |   |
| leaveCusFieldArray   | NSMutableArray   | Directly enter the custom field for leaving a message   |   |
| leaveMsgGroupId   | NSString   | Leave message skill group ID, obtain from: Settings -> Ticket Skill Group Settings |   |
| hideChatTime   | BOOL   | Whether to hide chat time   |  Default NO |
| hideRototEvaluationLabels   | BOOL   | Whether to hide robot evaluation labels   |  Default NO, not hidden |
| hideManualEvaluationLabels   | BOOL   | Whether to hide manual evaluation labels   |  Default NO, not hidden |
| helpCenterTel   | NSString   | Help center redirectable phone number   |  Hidden by default |
| helpCenterTelTitle   | NSString   | Help Center Phone Number Display Content  |  Not displayed by default |
| showPhotoPreview   | BOOL   | When selecting a photo, do not send directly. Preview before sending. [Note: The preview box only has a magnifying glass effect. It does not crop the image. The original image will still be sent.]  | Default NO, Off |
| leaveTemplateId   | NSString   |  Leave template id [Note: Use with ZCChatControllerDelegate]  |    |
| hideNavBtnMore   | BOOL   |  Whether to hide the "..." more button at the top right corner of the navigation  |  Default is NO, meaning it is not hidden by default |
| hideQRCode   | BOOL   |  Whether to disable the QR code recognition feature  |  Set YES to disable, default NO to keep |


###### 2. Font Related:
| Attribute Name | Data Type | Description | Notes |
|:----|:----|:----|:----|
| titleFont   | UIFont   | Font for the top title   |    |
| subTitleFont   | UIFont   | Subtitle font   |    |
| listTitleFont   | UIFont   | List title font   |    |
| listDetailFont   | UIFont   | Font for unread message button, rating tag   |    |
| listTimeFont   | UIFont   | Message reminder (time, transfer to human agent, customer service reception, etc.) font   |    |
| chatFont   | UIFont   | Font for text in chat bubbles   |    |
| voiceButtonFont   | UIFont   | Font for the text on the recording button   |    |
| goodsTitleFont   | UIFont   | Font for the title text in the product details cell   |    |
| goodsDetFont   | UIFont   | Font for the summary text in the product details cell   |    |   |
| scTopTextFont   | UIFont   | Help Center Title Font    |    |


###### 3. Background Color Related:
| Attribute Name | Data Type | Description | Notes |
|:----|:----|:----|:----|
| goodSendBtnColor   | UIColor   | Background color of the btn in the product details cell   |    |
| leftChatColor   | UIColor   | Color of the left chat bubble   |    |
| rightChatColor   | UIColor   | Color of the right chat bubble   |    |
| leftChatSelectedColor   | UIColor   | Color of the selected left bubble for copying   |    |
| rightChatSelectedColor   | UIColor   | Color of the selected copy for the right bubble   |    |
| bottomLineColor   | UIColor   | Bottom border line color (input box, recording button, dividing line)   |    |
| commentCommitButtonColor   | UIColor   | Comment submit button background color   |    |
| commentItemButtonBgColor   | UIColor   | Default color of the rating option button (follows the theme color by default)   |    |
| LineRichColor   | UIColor   | Line color in rich text   |    |
| goodSendBtnColor   | UIColor   | Background color of the product send button   |    |
| leaveSubmitBtnImgColor   | UIColor   | Background color of the submit button on the message page   |    |
| documentLookImgProgressColor   | UIColor   | Document view, ImgProgress image background color    |    |
| documentBtnDownColor   | UIColor   |  File view, button background color    |    |
| notificationTopViewBgColor   | UIColor   | Background color of the announcement bar   |    |
| satisfactionSelectedBgColor   | UIColor   | Background color for "Resolved" and "Unresolved" on the feedback page   |    |
| leaveSuccessViewBgColor   | UIColor   | Background color of the prompt page after successfully submitting a message   |    |




###### 4. Text Color Related:
| Attribute Name | Data Type | Description | Notes |
|:----|:----|:----|:----|
| topViewTextColor   | UIColor   | Top text color   |    |
| leftChatTextColor   | UIColor   | Left bubble text color   |    |
| rightChatTextColor   | UIColor   | Right bubble text color   |    |
| chatTextViewColor   | UIColor   | Input box text color   |    |
| timeTextColor   | UIColor   | Color of the time text   |    |
| chatLeftLinkColor   | UIColor   | Link color in left bubble   |    |
| chatRightLinkColor   | UIColor   | Link color in right bubble   |    |
| satisfactionTextColor   | UIColor   | Text color for the message displayed after submitting feedback to end the session   |    |
| noSatisfactionTextColor   | UIColor   | Text color for "Not Satisfied" option   |    |
| satisfactionTextSelectedColor   | UIColor   | Color of "Resolved" and "Unresolved" text on the feedback page   |    |
| scoreExplainTextColor   | UIColor   | Text color for satisfaction star rating explanation   |    |
| submitEvaluationColor   | UIColor   | Text color of the submission evaluation button |    |
| notificationTopViewLabelColor   | UIColor   | Text color of the notification bar   |    |
| leaveSubmitBtnTextColor   | UIColor   | Text color of the submit button on the message page   |    |
| scTopTextColor   | UIColor   | Text color for Help Center and navigation titles  |    |
| robotBtnTitleColor   | UIColor   | Text color of the switch robot button  |    |
| textNolColor   | UIColor   | Default text color for buttons like "Click More", "Reviews", "Comments", "Images" |    |
| pricetTagTextColor   | UIColor   | Custom card product price text color  |    |
| referenceLeftLineColor   | UIColor   | Color of the vertical line on the left side of the quoted message  |    |
| referenceLeftNameColor   | UIColor   | Color of the sender name on the left side of the quoted message  |    |
| referenceLeftTextColor   | UIColor   | Reference message left content color  |    |
| referenceRightLineColor   | UIColor   | Reference message right vertical line color  |    |
| referenceRightNameColor   | UIColor   | Color of the sender name on the right side of the quoted message  |    |
| referenceRightTextColor   | UIColor   | Reference message right content color  |    |


###### 5. Others:
| Attribute Name | Data Type | Description | Remarks |
|:----|:----|:----|:----|
| cusMoreArray   | NSMutableArray   | Custom content below the more button (+ icon) under the input box (will not replace existing content, will append to the original content)   Filling content: ZCLibCusMenu.h   title: Button name   url: Clickable link (clicking will call the initialization linkBock)   imgName: Local image name, such as xxx@2x.png, icon=xxx |    |
| cusMenuArray   | NSMutableArray   | Custom quick access    Filling content: ZCLibCusMenu.h    url: Quick access link (Clicking will call the initialization linkBock)    title: Button title    lableId: ID for custom quick access   |    |
| cusRobotMoreArray   | NSMutableArray   | Custom content below the more button (+ icon) under the custom input box (does not replace existing content, appends to the original). Fill with: ZCLibCusMenu.h   |    |


##### ● Description of ZCLibInitInfo Class
This object will be automatically created after initialization. You can use it directly afterwards.
###### 1.  ID Related:

[Output Requirement]
Only output the translation result, no comments/explanations.
| Attribute Name | Data Type | Description | Remarks |
|:----|:----|:----|:----|
| api_host   | NSString   | API host   | If you use localized deployment, please use your deployed server domain name.   |
| app_key   | NSString   | Must be set. Initialization will fail if not set. The value will be automatically assigned during initialization.   | Required   |
| choose_adminid   | NSString   | Specify customer service ID   |    |
| tran_flag   | int   | Transfer type    |  0 Can transfer to other agents  1 Must transfer to designated agent   |
| partnerid   | NSString   | Unique user identifier   | Integrate reliable user identity, must not be hardcoded (hardcoding will result in the same identity, with serious consequences). Null is not recommended. If empty, it will differentiate by device. Maximum 300 characters supported; excess will be automatically truncated. |
| robotid   | NSString   | Docking Robot ID   |    |
| robot_alias   | NSString   | Alias for the connected robot. If this value is set, robotid needs to be set to empty each time. |    |
| platform_userid   | NSString   | Platform channel parameter, which will be automatically assigned after successful initialization   |    |
| platform_key   | NSString   | Private key   |    |
| sign   | NSString   | Signature MD5 (app_key+partnerid+secret+create_time)   | Use when you need to generate the signature yourself   |
| create_time   | NSString   | Timestamp used for the signature   |    |

E-commerce Version:

Set up the e-commerce to-human overflow strategy. The following attributes conflict with transferaction. If transferaction is set, it will override the configurations of flow_type, flow_companyid, and flow_groupid.

| Attribute Name | Data Type | Description | Remarks |
|:----:|:----:|:----|:----|
| customer_code | NSString | Merchant connection ID (Only applicable to e-commerce version. If there is no app_key, please provide this code) |    |
| flow_type   | int   | Cross-company transfer to agent (Only available for e-commerce version)   | Default 0: Not enabled, 1-All overflow, 2-Overflow when busy, 3-Overflow when offline     |
| flow_companyid   | NSString   | ID of the company being transferred to   |    |
| flow_groupid   | NSString   | Transfer to the company skill group   |    |

###### 2. Customer service workstation display:
| Attribute Name | Data Type | Description | Remarks |
|:----|:----|:----|:----|
| user_nick   | NSString   | Nickname   |    |
| user_name   | NSString   | Real name   |    |
| user_tels   | NSString   | User phone   |    |
| user_emails   | NSString   | User email   |    |
| qq   | NSString   | qq   |    |
| remark   | NSString   | Note   |    |
| face   | NSString   | User-defined avatar   |    |
| visit_title   | NSString   | Access source page title   |    |
| visit_url   | NSString   | Source URL for access   |    |
| params   | NSDictionary   | User information   |    |
| customer_fields   | NSDictionary   | Custom fields with fixed KEY. All KEYS take effect after being set in the workspace (Settings -> Custom Fields -> User Information Fields).   | ```@{@"customField22":@"I am a custom branch"};```   |
| group_name   | NSString   | Skill group name   |    |
| groupid   | NSString   | Skill group ID   |    |
| isVip   | NSString   | Specifies whether the customer is a VIP, 0: Regular 1: VIP   | Same as PC settings - Online Customer Service Assignment - Queue Priority Settings - VIP Customer Queue Priority. Pass 1 when enabled, default is not set. When enabled, if the specified customer initiates a consultation and there is a queue, the system will prioritize access.   |
| vipLevel   | NSString   | Specify the customer's VIP level, input the level   | Same as PC end Settings-Custom Fields-Customer Fields   |
| enterprise_name   | NSString   | Company/Enterprise Name   |    |


###### 3. Session Page Related:
| Attribute Name | Data Type | Description | Remarks |
|:----|:----|:----|:----|
| service_mode   | int   | Custom access mode: 1. Only robot, 2. Human only, 3. Intelligent customer service - Robot first, 4. Intelligent customer service - Human first |    |
| custom_title_url   | NSString   | Custom image path    |    |
| scope_time   | int   | History record time range, in minutes (Example: 100 - indicates sessions from 100 minutes ago) |    |
| notifition_icon_url   | NSString   | URL of the notification icon   |    |
| faqId   | int   | Specify guide words, set specific guide words for different users   |    |


###### 4. Others:
| Attribute Name | Data Type | Description | Remarks |
|:----|:----|:----|:----:|
| margs   | NSDictionary   | Extended fields for hotspot guidance questions   |    |
| transferaction   | NSArray   | Transfer to human agent, specify skill group overflow   actionType: Action type to execute: to_group: Transfer to specified skill group   optionId: Overflow setting when specifying skill group: 3: Overflow, 4: No overflow.   deciId: The specified skill group.   spillId: Overflow condition when specifying customer service group: 4: No agents online in the skill group, 5: All agents in the skill group are busy, 6: Skill group is off duty, 7: Intelligent judgment eg:[{"actionType":"to_group","optionId":"3","deciId":"162bb6bb038d4a9ea018241a30694064","spillId":"7"}, {"actionType":"to_group","optionId":"4","deciId":"a457f4dfe92842f8a11d1616c1c58dc1"}]  |    |
| summary_params   | NSDictionary   | Custom fields for transferring to human agent  key: ```@{@"customField15619769556831":@"Display xxyyyzzz1032"};```  |    |
| multi_params   | NSDictionary   | Multi-turn conversation custom fields   |    |
| good_msg_type   | int   | Custom product order info type; 0 Not sent 1 Sent to bot 2 Sent to human agent 3 Sent to both bot and human agent |    |
| content   | NSString   | Automatically send product order information content   |    |
| queue_first   | int   | Specify customer priority   |    |
| default_language   | NSString   | Default language. If not specified, the system language is not recognized and defaults to English, en_lproj   | Used only when not recognized   |
| absolute_language   | NSString   | Specifies the language, not following the system language auto-switch   |    |

#### Sobot SDK Resource Library Source Code and Function Experience Demo

Sobot iOS_SDK [UI source code](https://github.com/ZCSDK/Sobot_iOS_SDK_V6Source);  
      
Sobot SDK function experience Demo [APP download](https://apps.apple.com/us/app/id1507872824) [Use video guidance](/en/images/online/sdk/sobot_sdk_demo_android.mp4)

#### Common Questions
FAQ:

Please [click link](https://global.sobot.com/chat/h5/v2/index.html?sysnum=f8c1ea7f7ed44fd3b09604566ddc0b44&visit_start_time=1675855104890&visitTitle=Sobot%20|%20Customer%20service%20software_call%20center_livechat_chatbot&top_bar_flag=1&uid=1da53c20a0be75c31923c06d1429ef58&cid=da76dda4d2d3400b9fbfea67bedc58f6&channelid=2) to enter the intelligent bot page and enter your question


#### Update Notes

[Sobot iOS_SDK Version Update Description](https://shimo.im/docs/dPkpKPglrxtW7oqO/)


#### Sobot SDK Collects and Uses Personal Information Statement
[Description of Sobot SDK's Collection and Use of Personal Information](https://www.sobot.io/sdk-clause)
