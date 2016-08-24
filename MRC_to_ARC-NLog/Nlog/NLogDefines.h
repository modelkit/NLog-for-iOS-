//
//  NLogDefines.h
//  Zhidao
//
//  Created by Yong on 13-9-17.
//  Copyright (c) 2013年 Baidu. All rights reserved.
//
#pragma mark - log defines

#define kEventTypeClick @"clk"
#define kEventTypeState @"state"
#define kEventTypeTime  @"timing"
#define kDataKeyUdef    @"udef"

//内部log
#define ZDLogEnable 1
#if ZDLogEnable && DEBUG
#define ZDLogDebug(...)  NSLog(@"%@", [NSString stringWithFormat:__VA_ARGS__])
#define ZDLogInfo(...)  NSLog(@"%@", [NSString stringWithFormat:__VA_ARGS__])
#define ZDLogError(...)  NSLog(@"%@", [NSString stringWithFormat:__VA_ARGS__])
#else // release
#define ZDLogDebug(...)
#define ZDLogInfo(...)
#define ZDLogError(...)
#define NSLog(...)
#endif

#ifdef DEBUG
#endif

//统计
#define NLogEnable 1
#if NLogEnable
#define KIDLogClickEvent(name)        [NLog send:@"event" params:@{@"act":@"clk",@"name":name}]
#define KIDLogClickEventWithUdef(logName,udef) [NLog send:@"event" params:@{@"act":@"clk",@"name":logName,@"udef":udef}]
#define KIDLogShare(url)        [NLog send:@"event" params:@{@"act":@"clk",@"name":@"SHARE_ANALYSE",@"share":url}]
#define KIDLogPlayerTime(time,issue,status)        [NLog send:@"event" params:@{@"act":@"clk",@"name":@"LIVE_LOOK_LENGTH",@"LIVE_LOOK_LENGTH":time,@"LIVE_PERIOD":issue,@"LIVE_STATUS":status}]

#define ZDLogEvent(click,label)        [NLog send:@"event" params:@{@"act":click,@"name":label}]
#define ZDLogEventWithData(click, label, dataKey, dataValue) [NLog send:    @"event" params:@{@"act":click,@"name":label,dataKey:dataValue}]
#define ZDLogViewStart(viewName)       [NLog logDurationStart: viewName]
#define ZDLogViewEnd(viewName)         [NLog logDurationEnd:  viewName]
#define ZDLogTiming(label, value)      [NLog send:@"event" params:@{@"act":kEventTypeTime,@"name":label,@"tvalue":value}]
#define ZDLogException(crashMd5,crashTime)       [NLog send:@"exception" params:@{@"act":@"ept",@"emd5":crashMd5, @"etime":crashTime}]
#else
#define KIDLogClickEvent(name)        ZDLogDebug(@"============ %@", name)
#define KIDLogClickEventWithUdef(logName,udef)  ZDLogDebug(@"============ %@: %@", logName, udef)
#define ZDLogEvent(click,label)        ZDLogDebug(@"============ %@: %@", click, label)
#define ZDLogEventWithData(click, label, dataKey, dataValue) ZDLogDebug(@"============= %@: %@, %@: %@", click, label, dataKey, dataValue)
#define ZDLogViewStart(viewName)       ZDLogDebug(@"============ start: %@", viewName)
#define ZDLogViewEnd(viewName)         ZDLogDebug(@"============ end  : %@", viewName)
#define ZDLogTiming(label, value)      ZDLogDebug(@"============ timing: %@ - %f", label, value)
#define ZDLogException(crashMd5,crashTime)       ZDLogDebug(@"============ exception: %@ time: %@", crashMd5, crashTime)
#endif

#pragma mark - log key

#pragma mark - 日报

#define DAILY_ARTICLE_CLICK             @"DAILY_ARTICLE_CLICK_%d"       // 日报文章点击
#define DAILY_ARTICLE_SHARE             @"DAILY_ARTICLE_SHARE_%d"       // 日报文章分享
#define DAILY_ARTICLE_COLLECT           @"DAILY_ARTICLE_COLLECT_%d"     // 日报文章收藏
#define DAILY_COLUMN_CLICK              @"DAILY_COLUMN_CLICK_%d"        // 日报专栏点击

#pragma mark - 每日知识

#define INDEX_CLOSE_REMIND              @"INDEX_CLOSE_REMIND"           // 首页叉掉提醒 ✓
#define INDEX_CATEGORY_CLICK            @"INDEX_CATEGORY_CLICK"         // 首页用户关注帖子点击量 ✓
#define INDEX_CLICK                     @"INDEX_CLICK_%d"               // 知识点击 lcid ✓
#define INDEX_SLIDE_VIEW                @"INDEX_SLIDE_VIEW"             // 首页滑动切换量 ✓
#define DAILY_EXPERIENCE_COLLECT        @"DAILY_EXPERIENCE_COLLECT"     // 每日经验收藏量    -----ok
#define DAILY_EXPERIENCE_SHARE          @"DAILY_EXPERIENCE_SHARE"       // 每日经验分享量    -----ok
#define COLUMN_FROM_INDEX               @"COLUMN_FROM_INDEX_%d"         // 从文章页底部进入专栏 lcid
#define DAILY_KNOWLEDGE_COLLECT         @"DAILY_KNOWLEDGE_COLLECT_%d"   // 每日知识收藏量   ---ok
#define DAILY_KNOWLEDGE_SHARE           @"DAILY_KNOWLEDGE_SHARE_%d"     // 每日知识分享量   ---ok

#pragma mark - 分享

#define SHARE_TO_WECHAT_FRIEND          @"SHARE_TO_WECHAT_FRIEND_%d"    // 分享到微信朋友 ✓
#define SHARE_TO_WECHAT_CIRCLE          @"SHARE_TO_WECHAT_CIRCLE_%d"    // 分享到微朋友圈 ✓
#define SHARE_TO_WEIBO                  @"SHARE_TO_WEIBO_%d"            // 分享到新浪微博 ✓
#define SHARE_TO_QQ_FRIEND              @"SHARE_TO_QQ_FRIEND_%d"        // qq 好友 ✓
#define SHARE_TO_QQ_ZONE                @"SHARE_TO_QQ_ZONE_%d"          // qq 空间 ✓
#define SHARE_TO_MSG                    @"SHARE_TO_MSG_%d"              // 分享到短信 ✓

#pragma mark - 问专家

#define DAILY_ASK_EXPERT_PV             @"DAILY_ASK_EXPERT_PV"          // 问专家模块pv    ----ok
#define DAILY_ASK_NUM                   @"DAILY_ASK_NUM"                // 日提问量       -----ok
#define DAILY_CONTINUE_ASK_NUM          @"DAILY_CONTINUE_ASK_NUM"       // 日追问量       ----ok
#define DAILY_PRAISE_NUM                @"DAILY_PRAISE_NUM"             // 问题日好评量   ----ok
#define DAILY_QUESTION_COLLECT          @"DAILY_QUESTION_COLLECT"       // 提问收藏量     ----ok
#define DAILY_QUESTION_SHARE            @"DAILY_QUESTION_SHARE"         // 提问分享量     ----ok
#define QUESTION_BANNER_CLICK           @"QUESTION_BANNER_CLICK"        // 问答顶部banner点击量
#define QUESTION_RANK_CLICK             @"QUESTION_RANK_CLICK_%d"       // 问答顶部banner点击量


#pragma mark - 搜索

#define SEARCH_RELATE_CLICK             @"SEARCH_RELATE_CLICK"         // 相关问题点击

#pragma mark - 消息

#define DAILY_MSG_PV                    @"DAILY_MSG_PV"                // 消息页面的pv     ----ok
#define MSG_OPEN_FROM_IKNOW             @"MSG_OPEN_FROM_IKNOW"         // 系统消息打开量     --ok
#define DAILY_MSG_OPEN_FROM_EXPERIENCE  @"DAILY_MSG_OPEN_FROM_EXPERIENCE" // 每日经验消息打开量     ----ok
#define WEEK_MSG_OPEN_FROM_APP          @"WEEK_MSG_OPEN_FROM_APP"      // 每周第一天提醒推送打开量  ----ok
#define Q_HAS_ANSWER_MSG_OPEN           @"Q_HAS_ANSWER_MSG_OPEN"       // 提问有新回答消息点击量   --ok
#define MESSAGE_TALK_LINK_CLICK         @"MESSAGE_TALK_LINK_CLICK"     // 系统消息点击量

#pragma mark - 个人中心

#define USER_CENTER_INDEX_PV            @"USER_CENTER_INDEX_PV"        // 个人中心PV        ----ok
#define USER_NEW_PORTRAIT               @"USER_NEW_PORTRAIT"           // 个人中心设置头像（新
#define USER_MODIFY_PORTRAIT            @"USER_MODIFY_PORTRAIT"        // 个人中心头像修改      ----ok
#define USER_MODIFY_NICKNAME            @"USER_MODIFY_NICKNAME"        // 个人中心昵称修改次数   ----ok
#define USER_MODIFY_UPDATE_BIRTHDAY     @"USER_MODIFY_UPDATE_BIRTHDAY" // 个人中心修改预产期次数 ----ok
#define USER_MODIFY_SET_BIRTHDAY        @"USER_MODIFY_SET_BIRTHDAY"    // 个人中心设置预产期次数
#define USER_CENTER_CLICK_COLLECT       @"USER_CENTER_CLICK_COLLECT"   // 个人中心查看我的收藏   ----ok
#define USER_CENTER_CLICK_MY_QUESTION   @"USER_CENTER_CLICK_MY_QUESTION" // 个人中心产看我的提问   ----ok
#define USER_CENTER_CLICK_MY_ANSWER     @"USER_CENTER_CLICK_MY_ANSWER" // 个人中心产看我的回答   ----ok
#define USER_CENTER_CLICK_MY_CATEGORY   @"USER_CENTER_CLICK_MY_CATEGORY" // 个人中心我的发帖      ----ok
#define UESR_CENTER_CLICK_MY_REPLY_CATEGORY @"UESR_CENTER_CLICK_MY_REPLY_CATEGORY" // 个人中心我的回帖      ----ok
#define USER_MODIFY_BACKGROUND          @"USER_MODIFY_BACKGROUND"      // 个人中心头像修改

#pragma mark - 圈子

#define DAILY_CIRCLE_PV                 @"DAILY_CIRCLE_PV"             // 圈子板块PV          -----ok
#define CIRCLE_ONLY_HOST                @"CIRCLE_ONLY_HOST"            // 只看楼主            -----ok
#define CIRCLE_PAGE_TURN                @"CIRCLE_PAGE_TURN"            // 翻页            -----ok
#define CORCLE_SEND_HAPPLINESS          @"CORCLE_SEND_HAPPLINESS"      // 送祝福              -----ok
#define CIRCLE_LBS_REQUEST              @"CIRCLE_LBS_REQUEST"          // 请求获取地理位置
#define CIRCLE_LBS_REQUEST_SUCCESS      @"CIRCLE_LBS_REQUEST_SUCCESS"  // 请求获取地理位置，成功
#define CIRCLE_LBS_REQUEST_FAIL         @"CIRCLE_LBS_REQUEST_FAIL"     // 请求获取地理位置，失败
#define CIRCLE_LBS_SWITCH               @"CIRCLE_LBS_SWITCH"           // 切换城市

#pragma mark - 登录注册

#define LOGIN_SUCCESS                   @"LOGIN_SUCCESS"               // 登录成功           -----ok
#define LOGIN_CLICK_BAIDU               @"LOGIN_CLICK_BAIDU"           // 百度登录按钮点击    -----ok 登录页面弹出量

#pragma mark - 商城

#define MALL_HOME_FROM_MYCENTER         @"MALL_HOME_FROM_MYCENTER"
#define MALL_HOME_FROM_EARNCOIN         @"MALL_HOME_FROM_EARNCOIN"
#define MALL_DETAIL                     @"MALL_DETAIL_%zd"


//4.0版本新添加的
#pragma mark - 提醒工具

#define KNOWLG_LEFT_DRAWER_SHOW        @"KNOWLG_LEFT_DRAWER_SHOW"
#define REMIND_PRODUCT_CHECK_LIST      @"REMIND_PRODUCT_CHECK_LIST"      //产检列表页面的PV
#define REMIND_PHYSICAL_CHECK_LIST     @"REMIND_PHYSICAL_CHECK_LIST"     //体检列表页面的PV
#define REMIND_VACCINE_CHECK_LIST      @"REMIND_VACCINE_CHECK_LIST"      //疫苗列表页面的PV
#define REMIND_PRODUCT_CHECK_DETAIL    @"REMIND_PRODUCT_CHECK_DETAIL"    //产检详情页面的PV
#define REMIND_PHYSICAL_CHECK_DETAIL   @"REMIND_PHYSICAL_CHECK_DETAIL"   //体检详情页面的PV
#define REMIND_VACCINE_CHECK_DETAIL    @"REMIND_VACCINE_CHECK_DETAIL"    //疫苗详情页面的PV
#define REMIND_CHECK_STATUS            @"TOOLS_R_CHECK_%d-%@-%d"         //产检,体检,疫苗的选中;类型，编号，选中的状态

#pragma mark - 记录工具

#define TOOLS_RECORD_BABY_PAGE_PV      @"TOOLS_RECORD_BABY_PAGE_PV"
#define TOOLS_RECORD_MOTHER_PAGE_PV    @"TOOLS_RECORD_MOTHER_PAGE_PV"
#define TOOLS_RECORD_D_BABY_PAGE_PV    @"TOOLS_RECORD_D_BABY_PAGE_PV"
#define TOOLS_RECORD_D_MOTHER_PAGE_PV  @"TOOLS_RECORD_D_MOTHER_PAGE_PV"

// 4.2版本新增统计

#pragma mark - 视频

#define VIDEO_SHORT_PLAY               @"VIDEO_SHORT_PLAY"
#define VIDEO_FULL_PLAY                @"VIDEO_FULL_PLAY"

#pragma mark - 首页

#define HOMEPAGE_READING_CLK           @"HOMEPAGE_READING_CLK"
#define HOMEPAGE_RECORD_CLK            @"HOMEPAGE_RECORD_CLK"           // udef type
#define HOMEPAGE_TODO_CLK              @"HOMEPAGE_TODO_CLK"             // udef type
#define HOMEPAGE_ARTICLE_CLK           @"HOMEPAGE_ARTICLE_CLK"
#define HOMEPAGE_ARTICLE_TEST          @"HOMEPAGE_ARTICLE_TEST"
#define HOMEPAGE_ACTIVITY_CLK          @"HOMEPAGE_ACTIVITY_CLK"         // udef evtType
#define HOMEPAGE_PV                    @"HOMEPAGE_PV"                   // udef: READING|RECORD|TODO|ACT1|ACT2|ACT3

#pragma mark - 侧边栏

#define SIDEBAR_QUICKEN_CLK            @"SIDEBAR_QUICKEN_CLK"
#define SIDEBAR_UTERINE_CLK            @"SIDEBAR_UTERINE_CLK"
#define SIDEBAR_MOTHER_JOURNAL_CLK     @"SIDEBAR_MOTHER_JOURNAL_CLK"
#define SIDEBAR_JOURNAL_CLK            @"SIDEBAR_JOURNAL_CLK"
#define SIDEBAR_REMIND_CLK             @"SIDEBAR_REMIND_CLK"

#pragma mark - 日刊专栏

#define PV_NB_COLUMNLIST               @"PV_NB_COLUMNLIST"              // udef cid
#define COLUMN_ARTICLE_PV              @"COLUMN_ARTICLE_PV"             // udef cid
#define COLUMN_ARTICLE_GO_TOP          @"COLUMN_ARTICLE_GO_TOP"         // udef cid
#define COLUMN_ARTICLE_GO_BOTTOM       @"COLUMN_ARTICLE_GO_BOTTOM"      // udef cid

#pragma mark - 专业化工具

#define TOOLS_RECORD_QUICKEN_PV        @"TOOLS_RECORD_QUICKEN_PV"
#define TOOLS_RECORD_QUICKEN_SAVE      @"TOOLS_RECORD_QUICKEN_SAVE"
#define TOOLS_RECORD_UTERINE_PV        @"TOOLS_RECORD_UTERINE_PV"
#define TOOLS_RECORD_UTERINE_SAVE      @"TOOLS_RECORD_UTERINE_SAVE"
#define TOOLS_SCALE_CLICK              @"TOOLS_SCALE_CLICK"
#define TOOLS_SCALE_SYNC_VIEW          @"TOOLS_SCALE_SYNC_VIEW"
#define TOOLS_SCALE_SYNC               @"TOOLS_SCALE_SYNC"

#pragma mark - 4.2.1新增
#define TOOLS_REMIND_DETAIL_TO_LIST_0  @"TOOLS_REMIND_DETAIL_TO_LIST_0"    // 详情页“全部产检”点击UV。
#define TOOLS_REMIND_DETAIL_TO_LIST_1  @"TOOLS_REMIND_DETAIL_TO_LIST_1"    // 详情页“全部疫苗”点击UV
#define TOOLS_REMIND_DETAIL_TO_LIST_2  @"TOOLS_REMIND_DETAIL_TO_LIST_2"    // 详情页“全部体检”点击UV。
#define TOOLS_REMIND_SUBSCRIBE         @"TOOLS_REMIND_SUBSCRIBE"           // 今⽇有订阅⾏为的⽤户数；
#define TOOLS_REMIND_HAS_SUBSCRIBE     @"TOOLS_REMIND_HAS_SUBSCRIBE"       // 疫苗列表页UV中有订阅疫苗的⽤户数；
#define LOCALREMIND_PUSHNOTIFICATION   @"TOOLS_F_PUSH_C"                   // 提醒tools push


#pragma mark 4.3版本新增
#define TOOLS_LANDMARK_TAB_1 @"TOOLS_LANDMARK_TAB_1"
#define TOOLS_LANDMARK_TAB_2 @"TOOLS_LANDMARK_TAB_2"
#define TOOLS_LANDMARK_TAB_3 @"TOOLS_LANDMARK_TAB_3"
#define TOOLS_LANDMARK_TAB_4 @"TOOLS_LANDMARK_TAB_4"
#define TOOLS_LANDMARK_TAB_5 @"TOOLS_LANDMARK_TAB_5"
#define TOOLS_LANDMARK_TAB_5 @"TOOLS_LANDMARK_TAB_5"
#define TOOLS_LANDMARK_TAB_6 @"TOOLS_LANDMARK_TAB_6"
#define LEFT_BAR_MILESTONE @"LEFT_BAR_MILESTONE"
//B超
#define LEFT_BAR_ULTRASOUND @"LEFT_BAR_ULTRASOUND" //侧边栏点击B超解读
#define TOOLS_BSCAN @"TOOLS_BSCAN" //B超单解读⾸页
#define TOOLS_BSCAN_SWITCH @"TOOLS_BSCAN_SWITCH" //B超单解读⾸页切换孕周
#define TOOLS_BSCAN_DETAIL @"TOOLS_BSCAN_DETAIL" //B超单解读详情页
// 设置预产期
#define GESTATION_STATUS @"GESTATION_STATUS"
#define GESTATION_PREGNANT @"GESTATION_PREGNANT"
#define GESTATION_CALCULATE @"GESTATION_CALCULATE"
#define GESTATION_BORN @"GESTATION_BORN"
#define GESTATION_PREGNANT_DONE @"GESTATION_PREGNANT_DONE"
#define GESTATION_CALCULATE_DONE @"GESTATION_CALCULATE_DONE"
#define GESTATION_BORN_DONE @"GESTATION_BORN_DONE"
#define GESTATION_SKIP @"GESTATION_SKIP"
#define GESTATION_LOGIN @"GESTATION_LOGIN"
// 引导
#define APP_GUIDE @"APP_GUIDE"
#define APP_GUIDE_CLICK_ENTER @"APP_GUIDE_CLICK_ENTER"
#define APP_GUIDE_SWIPE_ENTER @"APP_GUIDE_SWIPE_ENTER"
#define MESSAGE_DAILY_HAS_DETAIL @"MESSAGE_DAILY_HAS_DETAIL"
#define MESSAGE_DAILY_NO_DETAIL @"MESSAGE_DAILY_NO_DETAIL"
#define MESSAGE_DAILY_URL @"MESSAGE_DAILY_URL"
#define MESSAGE_DAILY_MILESTONE @"MESSAGE_DAILY_MILESTONE"
#define MESSAGE_DAILY_OTHER @"MESSAGE_DAILY_OTHER"

//4.3.1新增打点
#define VIDEO_LIST_PV                   @"VIDEO_LIST_PV"    //"note": "视频专栏PV"
#define VIDEO_LIST_PLAY_TIMES  @"VIDEO_LIST_PLAY_TIMES" //专栏1视频播放

//4.5版本添加
//侧边栏营养食谱的打点
#define LEFT_BAR_NUTRITIOUS_DIET @"LEFT_BAR_NUTRITIOUS_DIET"
//侧边栏1-2岁宝宝发育的打点
#define LEFT_BAR_GROWTH_1_2 @"LEFT_BAR_GROWTH_1_2"
//侧边栏保健视频的打点
#define LEFT_BAR_GROWTH_HEALTH_VEDIO @"LEFT_BAR_GROWTH_HEALTH_VEDIO"
//侧边栏切换"孕期"与"育儿"打点名称
#define KNOWLG_LEFT_DRAWER_SHOW @"KNOWLG_LEFT_DRAWER_SHOW"
#define SIDEBAR_DAILY_CLK @"SIDEBAR_DAILY_CLK"
#define COLUMN_PLAY_VIDEO_DONE @"COLUMN_PLAY_VIDEO_DONE"


// 4.6 版本添加
#define CHECK_IN_OK_FROM_HOME_PAGE    @"CHECK_IN_OK_FROM_HOME_PAGE"// 首页签到成功
#define CHECK_IN_OK_FROM_USER_CENTER    @"CHECK_IN_OK_FROM_USER_CENTER"// 个人中心签到成功
#define CLICK_CHECK_IN_ON_HOME_PAGE    @"CLICK_CHECK_IN_ON_HOME_PAGE"// 首页签到点击
#define CLICK_CHECK_IN_ON_USER_CENTER    @"CLICK_CHECK_IN_ON_USER_CENTER"// 个人中心签到点击
#define CHECK_IN_TOTAL_DAYS    @"CHECK_IN_TOTAL_DAYS"// 本月累计签到天数
#define PROGESTATION_VIEW    @"PROGESTATION_VIEW"// 完整日历页
#define PROGESTATION_MENSES_START    @"PROGESTATION_MENSES_START"// 记录月经来了
#define PROGESTATION_MENSES_END    @"PROGESTATION_MENSES_END"// 记录月经走了
#define PROGESTATION_OVULATE    @"PROGESTATION_OVULATE"// 记录排卵
#define PROGESTATION_SEX    @"PROGESTATION_SEX"// 记录同房
#define SHOW_APPRAISE_VIEW    @"SHOW_APPRAISE_VIEW"// 显示评价框
#define MAMAQUAN_TAB_DISPLAY    @"MAMAQUAN_TAB_DISPLAY"// 妈妈圈不同圈子展示
#define MAMAQUAN_TAB_SELECTED    @"MAMAQUAN_TAB_SELECTED"// 妈妈圈分Tab点击选中
#define MAMAQUAN_HAS_SUBSCRIBE    @"MAMAQUAN_HAS_SUBSCRIBE"// 妈妈圈中有订阅记录的用户
#define MAMAQUAN_TAB_SELECTED_PAGE    @"MAMAQUAN_TAB_SELECTED_PAGE"// 访问妈妈圈有订阅记录的圈子
#define MAMAQUAN_SUBSCRIBE_CLK    @"MAMAQUAN_SUBSCRIBE_CLK"// 订阅圈子操作
#define MAMAQUAN_RECOMMODDISPLAY    @"MAMAQUAN_RECOMMODDISPLAY"// 推荐圈子展示次数
#define MAMAQUAN_RECOMMODDISPLAY_OVER    @"MAMAQUAN_RECOMMODDISPLAY_OVER"// 关闭推荐圈⼦（订阅完）
#define MAMAQUAN_RECOMMODDISPLAY_CLOSE    @"MAMAQUAN_RECOMMODDISPLAY_CLOSE"// 关闭推荐圈⼦（手动关闭）


//4.7版本打点


//description:统计打点
#define CLICK_HOME_PAGE_HEADER    @"CLICK_HOME_PAGE_HEADER"// 首页头图点击(播放视频)
#define CLICK_HOME_PAGE_SEARCH    @"CLICK_HOME_PAGE_SEARCH"// 搜索按钮点击
#define CLICK_HOME_PAGE_TOOLLIB_TOOL    @"CLICK_HOME_PAGE_TOOLLIB_TOOL"// 工具库工具点击
#define CLICK_HOME_PAGE_TOOLLIB_COLUMN    @"CLICK_HOME_PAGE_TOOLLIB_COLUMN"// 工具库专栏点击
#define CLICK_HOME_PAGE_REMIND_ITEM    @"CLICK_HOME_PAGE_REMIND_ITEM"// 提醒列表⼊点击UV
#define CLICK_HOME_PAGE_REMIND_SINGLE_ITEM    @"CLICK_HOME_PAGE_REMIND_SINGLE_ITEM"// 单条提醒点击
#define PAGE_REMIND_LIST_VIEW    @"PAGE_REMIND_LIST_VIEW"// 提醒列表显示
#define PAGE_REMIND_LIST_DETAIL_VIEW    @"PAGE_REMIND_LIST_DETAIL_VIEW"// 提醒详情页
#define CLICK_REMIND_DONE    @"CLICK_REMIND_DONE"// 今⽇日完成了提醒的UV(勾选和『我知道了』都算)
#define CLICK_HOME_PAGE_TOOLIB_MORE    @"CLICK_HOME_PAGE_TOOLIB_MORE"// 首页工具库点击更多
#define CLICK_HOME_PAGE_HOT_MORE    @"CLICK_HOME_PAGE_HOT_MORE"// 查看更多热帖
#define SCROLL_HOME_PAGE_DATE    @"SCROLL_HOME_PAGE_DATE"// 首页切换⽇日期
#define HOMEPAGE_SWITCH_PREGNANT    @"HOMEPAGE_SWITCH_PREGNANT"// 从备孕切到孕期
#define HOMEPAGE_SWITCH_PREGNANT_DONE    @"HOMEPAGE_SWITCH_PREGNANT_DONE"// 从备孕切到孕期，成功
#define HOMEPAGE_SWITCH_BORN    @"HOMEPAGE_SWITCH_BORN"// 从孕期切到育儿
#define HOMEPAGE_SWITCH_BORN_DONE    @"HOMEPAGE_SWITCH_BORN_DONE"// 从孕期切到育儿，成功
#define CLICK_TOOLLIB_TOOL    @"CLICK_TOOLLIB_TOOL"// 工具库页面（工具点击）
#define CLICK_TOOLLIB_COLUMN    @"CLICK_TOOLLIB_COLUMN"// 工具库页面点击（专栏）
#define PAGE_ENABLE_EAT    @"PAGE_ENABLE_EAT"// 能不能吃
#define CLICK_ENABLE_EAT_SEARCH    @"CLICK_ENABLE_EAT_SEARCH"// 能不能吃搜索次数
#define CLICK_ENABLE_EAT_SEARCH_FAILED    @"CLICK_ENABLE_EAT_SEARCH_FAILED"// 能不能吃搜索失败次数
#define PAGE_FROM_XIACHUFANG    @"PAGE_FROM_XIACHUFANG"// 下厨房⾷食谱
#define CLICK_COLLECTION_XIACHUFANG    @"CLICK_COLLECTION_XIACHUFANG"// 下厨房⾷食谱收藏
#define CLICK_PAGE_ENABLE_EAT_ITEM    @"CLICK_PAGE_ENABLE_EAT_ITEM"// 能不能吃分类点击
#define PAGE_DUMA_LIST    @"PAGE_DUMA_LIST"// 度妈学堂列表
#define PAGE_DUMA_DETAIL    @"PAGE_DUMA_DETAIL"// 度妈学堂活动详情页
#define PAGE_DUMA_DETAIL_ITEM    @"PAGE_DUMA_DETAIL_ITEM"// 度妈学堂活动详情页不同期
#define CLICK_DUMA_ASK    @"CLICK_DUMA_ASK"// 度妈学堂提问数量
#define CLICK_DUMA_QUESTION    @"CLICK_DUMA_QUESTION"// 度妈学堂回答数量
#define CLICK_DUMA_ASK_SUCCESS    @"CLICK_DUMA_ASK_SUCCESS"// 度妈学堂提问按钮点击
#define CLICK_DUMA_NEW_MESSAGE    @"CLICK_DUMA_NEW_MESSAGE"// 度妈学堂新内容提⽰示条展现量
#define CLICK_DUMA_NEW_MESSAGE_CLICK    @"CLICK_DUMA_NEW_MESSAGE_CLICK"// 度妈学堂新内容提⽰点击量
#define  PAGE_ENABLE_EAT_DETAIL @"PAGE_ENABLE_EAT_DETAIL" //食材详情页

//4.7.1补充打点

//description:统计打点
#define APPRAISE_ALERT_OK    @"APPRAISE_ALERT_OK"// 马上五星好评
#define APPRAISE_ALERT_LATER    @"APPRAISE_ALERT_LATER"// 改天再说
#define APPRAISE_ALERT_REJECT    @"APPRAISE_ALERT_REJECT"// 残忍拒绝
#define COLUMN_ARTICLE_SHARE    @"COLUMN_ARTICLE_SHARE" // 日刊分享，udef用cid
#define TOOLLIB_VIEW    @"TOOLLIB_VIEW" // 工具库展现

// 4.8统计



//description:统计打点
#define QUAN_PEOPLE_VIEW    @"QUAN_PEOPLE_VIEW"// 别人的个人中心访问
#define QUAN_PEOPLE_CHAT    @"QUAN_PEOPLE_CHAT"// 点击发私信按钮
#define QUAN_PEOPLE_ARTICLE    @"QUAN_PEOPLE_ARTICLE"// 点击别人发的帖子
#define CHATROOM_VIEW    @"CHATROOM_VIEW"// 私信窗口
#define CHATROOM_SEND    @"CHATROOM_SEND"// 发送私信
#define CHATROOM_BLOCK    @"CHATROOM_BLOCK"// 拉黑
#define CHATROOM_UNBLOCK    @"CHATROOM_UNBLOCK"// 取消拉黑
#define CHATROOM_REPORT    @"CHATROOM_REPORT"// 举报
#define QUAN_MESSAGE_VIEW    @"QUAN_MESSAGE_VIEW"// 妈妈圈消息
#define QUAN_MESSAGE_CLICK    @"QUAN_MESSAGE_CLICK"// 妈妈圈消息点击
#define QUAN_MESSAGE_CLEAR    @"QUAN_MESSAGE_CLEAR"// 妈妈圈消息清空
#define MSGSETTING_VIEW    @"MSGSETTING_VIEW"// 消息设置页
#define MSGSETTING_DISABLE_NOTIFICATION    @"MSGSETTING_DISABLE_NOTIFICATION"// 关闭私信提醒
#define MSGSETTING_DISABLE_NODISTURB    @"MSGSETTING_DISABLE_NODISTURB"// 关闭免打扰模式
#define PAGE_FETATION_DEV    @"PAGE_FETATION_DEV"// 胎儿发育专题
#define PAGE_MOTHER_CHANGE    @"PAGE_MOTHER_CHANGE"// 妈妈变化专题
#define CLICK_FETATION_DEV_PLAY_3D_VIDEO    @"CLICK_FETATION_DEV_PLAY_3D_VIDEO"// 播放3D视频的次数
#define CLICK_FETATION_DEV_MONTH    @"CLICK_FETATION_DEV_MONTH"// 胎儿发育中切换月份
#define CLICK_MOTHER_CHANGE_MONTH    @"CLICK_MOTHER_CHANGE_MONTH"// 妈妈变化中切换月份
#define CLICK_SEARCH_TAB    @"CLICK_SEARCH_TAB"// 搜索次数
#define PAGE_SEARCH_VIEW    @"PAGE_SEARCH_VIEW"// 搜索结果页(有结果)展示
#define CLICK_PAGE_SEARCH_DETAIL    @"CLICK_PAGE_SEARCH_DETAIL"// 搜索结果详情页点击
#define PAGE_SEARCH_DETAIL_VIEW    @"PAGE_SEARCH_DETAIL_VIEW"// 问题搜索结果详情页展示
#define PAGE_SEARCH_OTHER_QUESTION_VIEW    @"PAGE_SEARCH_OTHER_QUESTION_VIEW"// 问题搜索结果其他相关问题展示
#define CLICK_OPEN_APP_BY_PUSH_FEEDBACK    @"CLICK_OPEN_APP_BY_PUSH_FEEDBACK"// 意见反馈导致的点击量
#define CLICK_HOME_PAGE_EXPERT_ONLINE    @"CLICK_HOME_PAGE_EXPERT_ONLINE"// 专家在线点击量
#define CLICK_HOME_PAGE_EXPERT_ONLINE_MORE    @"CLICK_HOME_PAGE_EXPERT_ONLINE_MORE"// 专家在线点击更多
#define PAGE_SEACH_HOME_VIEW    @"PAGE_SEACH_HOME_VIEW"// 搜索首页view
#define CLICK_SEACH_HOME_FIELD    @"CLICK_SEACH_HOME_FIELD"// 点击搜索框
#define CLICK_SEACH_HOME_HOT    @"CLICK_SEACH_HOME_HOT"// 点击热门搜索
#define CLICK_SEACH_HOME_CHANGE    @"CLICK_SEACH_HOME_CHANGE"// 点击搜索首页换一批
#define CLICK_SEACH_HOME_MESSAGE    @"CLICK_SEACH_HOME_MESSAGE"// 点击搜索首页消息
#define CLICK_SEACH_RESULT_ASK    @"CLICK_SEACH_RESULT_ASK"// 点击搜索结果页问题Tab下提问按钮
#define CLICK_SEACH_NORESULT_ASK    @"CLICK_SEACH_NORESULT_ASK"// 搜索无结果页区分tab：问题、帖子、知识

//description:统计打点
//version:4.9版本打点统计---------------begin--------------
#define QUAN_SENDARTICLE_PHOTO_CAMERA    @"QUAN_SENDARTICLE_PHOTO_CAMERA"// 通过拍照插入图片（插入输入框才算）
#define QUAN_SENDARTICLE_PHOTO_PHOTOSALBUM    @"QUAN_SENDARTICLE_PHOTO_PHOTOSALBUM"// 通过相册插入图片（插入输入框才算）
#define EMOTION_BOTTOM_TAB_CHANGED    @"EMOTION_BOTTOM_TAB_CHANGED"// 切换底部表情tab
#define EMOTION_BOTTOM_ADD_CLICK    @"EMOTION_BOTTOM_ADD_CLICK"// 点击添加表情按钮
#define EMOTION_DETAIL_DISPLAY    @"EMOTION_DETAIL_DISPLAY"// 表情列表页点击单个表情进入到详情
#define EMOTION_LIST_DISPLAY    @"EMOTION_LIST_DISPLAY"// 表情列表页访问
#define EMOTION_DOWNLOAD_CLICK    @"EMOTION_DOWNLOAD_CLICK"// 点击表情下载按钮
#define EMOTION_MINE_CLICK    @"EMOTION_MINE_CLICK"// 点击我的表情按钮
#define EMOTION_MINE_VISIT    @"EMOTION_MINE_VISIT"// 我的表情页访问
#define EMOTION_MINE_DELETE    @"EMOTION_MINE_DELETE"// 我的表情点击移除
#define QUAN_SEND_STATIC_EMOTIONS_COUNT    @"QUAN_SEND_STATIC_EMOTIONS_COUNT"// 发帖、回帖、私信页面点击小表情数量的统计
#define QUAN_SEND_DYNAMIC_EMOTIONS_COUNT    @"QUAN_SEND_DYNAMIC_EMOTIONS_COUNT"// 发帖、回帖、私信页面点击动态表情数量的统计
#define MALL_BANNER_CLICK    @"MALL_BANNER_CLICK"// 商城首页-->点击banner
#define NEWER_AREA_CLICK    @"NEWER_AREA_CLICK"// 点击『新手专区』
#define LEVEL_DETAILS_CLICK    @"LEVEL_DETAILS_CLICK"// 点击『查看等级详情
#define HOW_TO_BE_VIP_CLICK    @"HOW_TO_BE_VIP_CLICK"// 点击『如何成为VIP』
#define GET_MORE_COIN_CLICK    @"GET_MORE_COIN_CLICK"// 点击『赚取更多金币』
#define NEWER_FIRST_CHECK_IN_SHOW    @"NEWER_FIRST_CHECK_IN_SHOW"// 签到页-->首签弹框-->展现
#define GET_IN_NEWER_AREA_CLICK    @"GET_IN_NEWER_AREA_CLICK"// 签到页-->首签弹框-->马上领取
#define NEWER_CHECK_IN_CANCEL_ICON_CLICK    @"NEWER_CHECK_IN_CANCEL_ICON_CLICK"// 签到页-->首签弹框-->点击叉叉
#define CLICK_HOME_PAGE_HEIGHT    @"CLICK_HOME_PAGE_HEIGHT"// 育儿期身高
#define CLICK_HOME_PAGE_WEIGHT    @"CLICK_HOME_PAGE_WEIGHT"// 育儿期体重
#define TOOLLIB_VIEW    @"TOOLLIB_VIEW"// 知识库不同时期Tab下展示
#define CLICK_TOOLLIB_TOOL    @"CLICK_TOOLLIB_TOOL"// 知识库不同时期Tab下 不同工具的点击
#define CLICK_TOOLLIB_COLUMN    @"CLICK_TOOLLIB_COLUMN"// 知识库不同时期Tab下 不同工具的点击
#define CLICK_COLLECTION_FOOD    @"CLICK_COLLECTION_FOOD"// 食材详情收藏
#define CLICK_SHARE_FOOD    @"CLICK_SHARE_FOOD"// 食材详情分享
#define PAGE_BABY_GROWTH    @"PAGE_BABY_GROWTH"// 宝宝发育页面展示
#define BABY_GROWTH_CHANGE_MONTH    @"BABY_GROWTH_CHANGE_MONTH"// 宝宝切换月份
#define QUAN_COPY_MAIN_ARTICLE    @"QUAN_COPY_MAIN_ARTICLE"// 复制主帖
#define QUAN_COPY_FLOOR_ARTICLE    @"QUAN_COPY_FLOOR_ARTICLE"// 复制楼层
#define QUAN_LOOK_BIG_PIC    @"QUAN_LOOK_BIG_PIC"// 查看大图
#define USER_DARK_CLICK    @"USER_DARK_CLICK" // 夜间模式
//version:4.9版本打点统计---------------end----------------


//description:统计打点
//version:4.9.2版本打点统计---------------begin--------------
#define SEARCH_CAN_ITEM_CLICK    @"SEARCH_CAN_ITEM_CLICK"// 能不能做（吃）结果卡片点击
#define SEARCH_MORE_CLICK    @"SEARCH_MORE_CLICK"// 更多搜索结果点击
#define SEARCH_SAME_CONCERN_ITEM_CLICK    @"SEARCH_SAME_CONCERN_ITEM_CLICK"// 同分类排行榜点击
#define SEARCH_SAME_CONCERN_MORE_CLICK    @"SEARCH_SAME_CONCERN_MORE_CLICK"// 同分类排行榜更多点击
#define SEARCH_DIFF_CONCERN_ITEM_CLICK    @"SEARCH_DIFF_CONCERN_ITEM_CLICK"// 不同分类排行榜点击
#define SEARCH_DIFF_CONCERN_MORE_CLICK    @"SEARCH_DIFF_CONCERN_MORE_CLICK"// 不同分类排行榜更多点击
#define SEARCH_RECIPE_ITEM_CLICK    @"SEARCH_RECIPE_ITEM_CLICK"// 食谱点击量
#define SEARCH_RECIPE_MORE_CLICK    @"SEARCH_RECIPE_MORE_CLICK"// 食谱更多点击量
#define SEARCH_CAN_ITEM_CLICK    @"SEARCH_CAN_ITEM_CLICK"// 能不能做（吃）结果卡片点击
#define SEARCH_MORE_CLICK    @"SEARCH_MORE_CLICK"// 更多搜索结果点击
#define SEARCH_SAME_CONCERN_ITEM_CLICK    @"SEARCH_SAME_CONCERN_ITEM_CLICK"// 同分类排行榜点击
#define SEARCH_SAME_CONCERN_MORE_CLICK    @"SEARCH_SAME_CONCERN_MORE_CLICK"// 同分类排行榜更多点击
#define SEARCH_DIFF_CONCERN_ITEM_CLICK    @"SEARCH_DIFF_CONCERN_ITEM_CLICK"// 不同分类排行榜点击
#define SEARCH_DIFF_CONCERN_MORE_CLICK    @"SEARCH_DIFF_CONCERN_MORE_CLICK"// 不同分类排行榜更多点击
#define GEEK_INTRO_PAGE    @"GEEK_INTRO_PAGE"// 达人介绍页
#define GEEK_APPLY_PAGE    @"GEEK_APPLY_PAGE"// 达人申请页
#define GEEK_ANSWER_PAGE    @"GEEK_ANSWER_PAGE"// 达人-自己答
#define GEEK_AGREE_OTHER_PAGE    @"GEEK_AGREE_OTHER_PAGE"// 达人-赞别人
#define GEEK_SELECT_TAG_PAGE    @"GEEK_SELECT_TAG_PAGE"// 标签选择页
#define GEEK_POST_APPLY_CLICK    @"GEEK_POST_APPLY_CLICK"// 达人申请提交点击
#define GEEK_ANSWER_QUESTION_CLICK    @"GEEK_ANSWER_QUESTION_CLICK"// 达人-自己答问题点击
#define GEEK_AGREE_OTHER_QUESTION_CLICK    @"GEEK_AGREE_OTHER_QUESTION_CLICK"// 达人-赞别人问题点击
#define GEEK_QUESTION_ITEM_TAG_CLICK    @"GEEK_QUESTION_ITEM_TAG_CLICK"// 问题下标签Item点击
#define GEEK_TAG_LIST_CLICK    @"GEEK_TAG_LIST_CLICK"// 下拉菜单标签点击
#define SEARCH_UNIQUE_QB_CLICK    @"SEARCH_UNIQUE_QB_CLICK"// 唯一答案点击
#define SEARCH_UNIQUE_RECOMMEND_QB_CLICK    @"SEARCH_UNIQUE_RECOMMEND_QB_CLICK"// 推荐问题点击
#define SEARCH_UNIQUE_SUBJECT_CLICK    @"SEARCH_UNIQUE_SUBJECT_CLICK"// 查看专题点击
#define SEARCH_UNIQUE_MORE_CLICK    @"SEARCH_UNIQUE_MORE_CLICK"// 更多搜索结果点击
#define SEARCH_TAG_PV    @"SEARCH_TAG_PV"// tag详情页访问量
#define SEARCH_TAG_QB_CLICK    @"SEARCH_TAG_QB_CLICK"// tag详情页问题点击
#define SEARCH_TAG_MORE_CLICK    @"SEARCH_TAG_MORE_CLICK"// tag详情页更多点击
#define VOICE_SEARCH_CLICK    @"VOICE_SEARCH_CLICK"// 点击语音搜索icon
#define VOICE_SEARCH_BEGIN    @"VOICE_SEARCH_BEGIN"// 语音搜索页面长按点击
#define VOICE_SEARCH_CANCEL    @"VOICE_SEARCH_CANCEL"// 语音搜索页面上滑取消点击
#define VOICE_SEARCH_ERROR    @"VOICE_SEARCH_ERROR"// 语音搜索返回错误访问
#define VOICE_SEARCH_SUCCESS    @"VOICE_SEARCH_SUCCESS"// 语音搜索执行搜索请求
#define VOICE_SEARCH_NORESULT    @"VOICE_SEARCH_NORESULT"// 语音搜索无结果
#define VOICE_SEARCH_RESULT_ASK    @"VOICE_SEARCH_RESULT_ASK"// 搜索结果点击语音提问按钮
#define USER_CENTER_HELP_MUM_CLICK    @"USER_CENTER_HELP_MUM_CLICK"// 帮其他妈妈回答问题
#define QB_PAGE_APPLY_GEEK_CLICK    @"QB_PAGE_APPLY_GEEK_CLICK"// 问答页申请达人点击
#define GIF_SINGLESHOW_DETAIL_CLICK    @"GIF_SINGLESHOW_DETAIL_CLICK"// 点击表情大图详情
#define GIF_SINGLESHOW_DETAIL_CLICK    @"GIF_SINGLESHOW_DETAIL_CLICK"// 点击表情大图详情
#define GIF_CLICK    @"GIF_CLICK"// 点击表情大图
#define GIF_CLICK    @"GIF_CLICK"// 点击表情大图
#define EAT_TAG_CLICK    @"EAT_TAG_CLICK"// 能不能吃菜单的点击量
#define PAGE_ENABLE_BEHAVIOR    @"PAGE_ENABLE_BEHAVIOR"// 能不能做的页面访问
#define PAGE_ENABLE_EAT    @"PAGE_ENABLE_EAT"// 能不能吃的页面访问
#define EAT_TITLE_TAGS_CONTAINER_SHOW    @"EAT_TITLE_TAGS_CONTAINER_SHOW"// 能不能吃导航条的点击量
#define BEHAVIOR_TITLE_TAGS_CONTAINER_SHOW    @"BEHAVIOR_TITLE_TAGS_CONTAINER_SHOW"// 能不能做导航条的点击量
#define BEHAVIOR_TAG_CLICK    @"BEHAVIOR_TAG_CLICK"// 能不能做菜单的点击量
#define BEHAVIOR_DETAILS_SHARE_DO    @"BEHAVIOR_DETAILS_SHARE_DO"// 能不能做分享
#define BEHAVIOR_DETAILS_COLLECT_DO    @"BEHAVIOR_DETAILS_COLLECT_DO"// 能不能做收藏
#define VIEW_LIGHT_THEME @"VIEW_LIGHT_THEME"
#define VIEW_DARK_THEME @"VIEW_DARK_THEME"
#define CLICK_OPEN_DARK_THEME @"CLICK_OPEN_DARK_THEME"
#define CLICK_CLOSE_DARK_THEME @"CLICK_CLOSE_DARK_THEME"
//version:4.9.2版本打点统计---------------end----------------


//description:统计打点
//version:5.0版本打点统计---------------begin--------------
#define SEARCH_SUG_HOT    @"SEARCH_SUG_HOT"// 热词点击
#define SEARCH_REPEAT_SEARCH    @"SEARCH_REPEAT_SEARCH"// 120秒内再次搜索
#define SEARCH_CONFINEMENT_SAVE    @"SEARCH_CONFINEMENT_SAVE"// 计算预产期特型点击保存
#define SEARCH_CONFINEMENT_MORE    @"SEARCH_CONFINEMENT_MORE"// 计算预产期特型更多搜索结果
#define SEARCH_NAME_MORE_CLICK     @"SEARCH_NAME_MORE_CLICK"   //起名工具更多搜索结果
#define GESTATION_CALCULATION_VIEW    @"GESTATION_CALCULATION_VIEW"// 计算预产期工具首页
#define PAGE_BABY_NAMING_HOME    @"PAGE_BABY_NAMING_HOME"// 起名工具首页
#define PAGE_BABY_NAMING_LIST    @"PAGE_BABY_NAMING_LIST"// 起名列表页
#define PAGE_BABY_NAMING_DETAIL    @"PAGE_BABY_NAMING_DETAIL"// 名字详情页
#define PAGE_BABY_NAME_TEST_HOME    @"PAGE_BABY_NAME_TEST_HOME"// 测名工具首页
#define PAGE_BABY_NAME_TEST_DETAIL    @"PAGE_BABY_NAME_TEST_DETAIL"// 测名工具名字详情页
#define CLICK_BABY_NAMING_LIST_TO_DETAIL    @"CLICK_BABY_NAMING_LIST_TO_DETAIL"// 起名列表页查看名字详情
#define CLICK_TO_BABY_NAMING_LIST_FROM_SEARCH    @"CLICK_TO_BABY_NAMING_LIST_FROM_SEARCH"// 从特型点击查看更多进入列表
#define CLICK_TO_BABY_NAMING_LIST_FROM_NAMING_TOOL    @"CLICK_TO_BABY_NAMING_LIST_FROM_NAMING_TOOL"// 从特型的起名工具进入列表
#define CLICK_BABY_NAMING_SEARCH_TO_DETAIL    @"CLICK_BABY_NAMING_SEARCH_TO_DETAIL"// 从特型的起名工具进入详情页
#define BABY_NAMING_SUBMIT    @"BABY_NAMING_SUBMIT"// 起名按钮点击
#define BABY_NAMING_DETAIL_COLLECT    @"BABY_NAMING_DETAIL_COLLECT"// 名字详情页-收藏
#define BABY_NAMING_DETAIL_SHARE    @"BABY_NAMING_DETAIL_SHARE"// 名字详情页-分享
#define BABY_NAME_TEST_SUBMIT    @"BABY_NAME_TEST_SUBMIT"// 测名按钮点击
#define BABY_NAME_TEST_DETAIL_COLLECT    @"BABY_NAME_TEST_DETAIL_COLLECT"// 测名详情页-收藏
#define BABY_NAME_TEST_DETAIL_SHARE    @"BABY_NAME_TEST_DETAIL_SHARE"// 测名详情页-分享
#define CLICK_BABY_NAMING_SEARCH_TO_DETAIL    @"CLICK_BABY_NAMING_SEARCH_TO_DETAIL"// 从特型的起名工具进入详情页
#define GESTATION_CALCULATION_SAVE    @"GESTATION_CALCULATION_SAVE"// 计算预产期工具保存
#define FAMOUS_VIEW    @"FAMOUS_VIEW"// 名人堂页面展现
#define FAMOUS_CLICK    @"FAMOUS_CLICK"// 名人堂入口点击
#define SEARCH_SUG_HISTORY    @"SEARCH_SUG_HISTORY"// 历史记录点击
#define SEARCH_HOT_VIEW    @"SEARCH_HOT_VIEW"// 热词展现
#define SEARCH_SUG_VIEW    @"SEARCH_SUG_VIEW"// SUG展现
#define SEARCH_SUG_CLICK    @"SEARCH_SUG_CLICK"// SUG点击
#define SEARCH_CAN_ITEM_CLICK    @"SEARCH_CAN_ITEM_CLICK"// 能不能做（吃）结果卡片点击
#define SEARCH_MORE_CLICK    @"SEARCH_MORE_CLICK"// 普通搜索更多
#define SEARCH_SAME_CONCERN_ITEM_CLICK    @"SEARCH_SAME_CONCERN_ITEM_CLICK"// 能不能做（吃）同分类排行榜点击
#define SEARCH_SAME_CONCERN_MORE_CLICK    @"SEARCH_SAME_CONCERN_MORE_CLICK"// 能不能做（吃）同分类排行榜点击更多
#define SEARCH_DIFF_CONCERN_ITEM_CLICK    @"SEARCH_DIFF_CONCERN_ITEM_CLICK"// 能不能做（吃）不同分类排行榜点击
#define SEARCH_DIFF_CONCERN_MORE_CLICK    @"SEARCH_DIFF_CONCERN_MORE_CLICK"// 能不能做（吃）不同分类更多点击
#define SEARH_BOYORGIRL_ARTICLE_CLICK    @"SEARH_BOYORGIRL_ARTICLE_CLICK"// 生男生女文章点击
#define SEARH_BOYORGIRL_MORE_CLICK    @"SEARH_BOYORGIRL_MORE_CLICK"// 生男生女查看更多点击
#define SEARH_BOYORGIRL_NORMAL_SEARCH_CLICK    @"SEARH_BOYORGIRL_NORMAL_SEARCH_CLICK"// 生男生女更多搜索结果点击
#define HOME_CLICK_BOYORGIRL    @"HOME_CLICK_BOYORGIRL"// 工具-生男女
#define HOME_CLICK_NAMING    @"HOME_CLICK_NAMING"// 工具-起名测名
#define HOME_CLICK_CALCULATEDUEDATE    @"HOME_CLICK_CALCULATEDUEDATE"// 工具-计算预产期
#define HOME_CLICK_FEED    @"HOME_CLICK_FEED"// 工具-喂养记录
#define BOYORGIRL_CATEGORY_CLICK    @"BOYORGIRL_CATEGORY_CLICK"// 点击大分类
#define BOYORGIRL_ARTICLE_CLICK    @"BOYORGIRL_ARTICLE_CLICK"// 点击文章详情
#define BOYORGIRL_ARTICLE_DETAIL_COLLECT    @"BOYORGIRL_ARTICLE_DETAIL_COLLECT"// 文章详情页-收藏
#define BOYORGIRL_ARTICLE_DETAIL_SHARE    @"BOYORGIRL_ARTICLE_DETAIL_SHARE"// 文章详情页-分享
#define BABYLIFERECORD_VIEW_SHOW    @"BABYLIFERECORD_VIEW_SHOW"// 喂养工具首页访问
#define BABYLIFERECORD_EXPEND    @"BABYLIFERECORD_EXPEND"// 喂养工具点击添加
#define BABYLIFERECORD_CLICK_MENU    @"BABYLIFERECORD_CLICK_MENU"// 喂养工具类别切换
#define BABYLIFERECORD_CLICK_RECORDBUTTON    @"BABYLIFERECORD_CLICK_RECORDBUTTON"// 喂养工具点击tab签
#define BABYLIFERECORD_EDIT    @"BABYLIFERECORD_EDIT"// 喂养工具编辑记录
#define BABYLIFERECORD_SAVERECORD    @"BABYLIFERECORD_SAVERECORD"// 喂养工具保存记录
#define BABYLIFERECORD_DETAILPAGESHOW @"BABYLIFERECORD_DETAILPAGESHOW" //喂养工具编辑页面展示
//version:5.0版本打点统计---------------end----------------



//description:统计打点
//version:5.1版本打点统计---------------begin--------------
#define SHOP_HOME_PV    @"SHOP_HOME_PV"// 商城首页
#define SHOP_COLUMN_PV    @"SHOP_COLUMN_PV"// 专题页
#define SHOP_DETAIL_PV    @"SHOP_DETAIL_PV"// 商品详情页
#define SHOP_CART_PV    @"SHOP_CART_PV"// 购物车
#define SHOP_ADDRESS_PV    @"SHOP_ADDRESS_PV"// 地址表单页
#define SHOP_ORDER_UNPAY_PV    @"SHOP_ORDER_UNPAY_PV"// 待支付订单页
#define SHOP_CHECKOUT_PV    @"SHOP_CHECKOUT_PV"// 支付页
#define SHOP_PAY_SUCCESS_PV    @"SHOP_PAY_SUCCESS_PV"// 支付成功
#define SHOP_GO_LOGIN_PV    @"SHOP_GO_LOGIN_PV"// 调起登录框
#define SHOP_LOGIN_SUCCESS    @"SHOP_LOGIN_SUCCESS"// 调起后登录成功
#define SHOP_DETAIL_CLICK_ADDCART    @"SHOP_DETAIL_CLICK_ADDCART"// 点击加入购物车
#define SHOP_DETAIL_CLICK_ICON    @"SHOP_DETAIL_CLICK_ICON"// 点击购物车icon
#define SHOP_DETAIL_GOTO_SETTLEMAENT    @"SHOP_DETAIL_GOTO_SETTLEMAENT"// 点击“去结算”
#define SHOP_DETAIL_COLLECT    @"SHOP_DETAIL_COLLECT"// 详情页面点击收藏
#define BIND_BEGIN    @"BIND_BEGIN"//
#define BIND_ALL_SUCCESS    @"BIND_ALL_SUCCESS"//
#define BIND_SUCCESS_CHANGE    @"BIND_SUCCESS_CHANGE"//
#define LOGIN_HOME_SHOW    @"LOGIN_HOME_SHOW"//
#define LOGIN_SEND_CODE    @"LOGIN_SEND_CODE"//
#define LOGIN_MESSAGE_CLICK    @"LOGIN_MESSAGE_CLICK"//
#define LOGIN_QQ_CLICK    @"LOGIN_QQ_CLICK"//
#define LOGIN_WEIXIN_CLICK    @"LOGIN_WEIXIN_CLICK"//
#define LOGIN_WEIBO_CLICK    @"LOGIN_WEIBO_CLICK"//
#define LOGIN_BAIDU_CLICK    @"LOGIN_BAIDU_CLICK"//
#define LOGIN_MESSAGE_SUCCESS    @"LOGIN_MESSAGE_SUCCESS"//
#define LOGIN_QQ_SUCCESS    @"LOGIN_QQ_SUCCESS"//
#define LOGIN_WEIXIN_SUCCESS    @"LOGIN_WEIXIN_SUCCESS"//
#define LOGIN_WEIBO_SUCCESS    @"LOGIN_WEIBO_SUCCESS"//
#define LOGIN_BAIDU_SUCCESS    @"LOGIN_BAIDU_SUCCESS"//
#define ENTER_TURNTABLE_FROM_CHECKIN    @"ENTER_TURNTABLE_FROM_CHECKIN"//
#define ENTER_TURNTABLE_FROM_MALL    @"ENTER_TURNTABLE_FROM_MALL"//
#define CLICK_TO_DIET_BABY_DETAIL_FROM_SEARCH    @"CLICK_TO_DIET_BABY_DETAIL_FROM_SEARCH"// 宝宝辅食特型食谱点击量
#define CLICK_TO_DIET_BABY_LIST_FROM_SEARCH    @"CLICK_TO_DIET_BABY_LIST_FROM_SEARCH"// 宝宝辅食特型点击更多结果量
#define SEARCH_DIET_BABY_MORE_CLICK    @"SEARCH_DIET_BABY_MORE_CLICK"// 宝宝辅食特型点击“更多搜索结果”量
#define PAGE_DIET_BABY    @"PAGE_DIET_BABY"// 宝宝辅食工具All工具使用量
#define CLICK_TO_DIET_BABY_DETAIL    @"CLICK_TO_DIET_BABY_DETAIL"// 宝宝辅食工具食谱点击量
#define CLICK_SHOW_MORE_DIET_BABY    @"CLICK_SHOW_MORE_DIET_BABY"// 宝宝辅食工具展开食谱点击量
#define CLICK_HOT_TOPIC_ON_DIET_BABY    @"CLICK_HOT_TOPIC_ON_DIET_BABY"// 宝宝辅食工具热帖点击量
#define CLICK_MORE_TOPIC_ON_DIET_BABY    @"CLICK_MORE_TOPIC_ON_DIET_BABY"// 宝宝辅食工具查看更多帖子点击量
#define CLICK_TO_DIET_MOTHER_DETAIL_FROM_SEARCH    @"CLICK_TO_DIET_MOTHER_DETAIL_FROM_SEARCH"// 妈妈食谱特型食谱点击量
#define CLICK_TO_DIET_MOTHER_LIST_FROM_SEARCH    @"CLICK_TO_DIET_MOTHER_LIST_FROM_SEARCH"// 妈妈食谱特型点击更多结果量
#define SEARCH_DIET_MOTHER_MORE_CLICK    @"SEARCH_DIET_MOTHER_MORE_CLICK"// 妈妈食谱特型点击“更多搜索结果”量
#define PAGE_DIET_MOTHER    @"PAGE_DIET_MOTHER"// 妈妈食谱工具All工具使用量
#define CLICK_TO_DIET_MOTHER_DETAIL    @"CLICK_TO_DIET_MOTHER_DETAIL"// 妈妈食谱工具食谱点击量
#define CLICK_SHOW_MORE_DIET_MOTHER    @"CLICK_SHOW_MORE_DIET_MOTHER"// 妈妈食谱工具展开食谱点击量
#define CLICK_HOT_TOPIC_ON_DIET_MOTHER    @"CLICK_HOT_TOPIC_ON_DIET_MOTHER"// 妈妈食谱工具热帖点击量
#define CLICK_MORE_TOPIC_ON_DIET_MOTHER    @"CLICK_MORE_TOPIC_ON_DIET_MOTHER"// 妈妈食谱工具查看更多帖子点击量
#define CLICK_TOPIC_COMMODITY_ITEM    @"CLICK_TOPIC_COMMODITY_ITEM"// 点击商品卡片的
#define CLICK_ADD_CART_BUTTON    @"CLICK_ADD_CART_BUTTON"// 点击“加入购物车”
#define CLICK_ADD_FAVOURITE_ICON    @"CLICK_ADD_FAVOURITE_ICON"// 点击收藏
#define CLICK_TOPIC_CART_ICON    @"CLICK_TOPIC_CART_ICON"// 点击购物车icon
#define CLICK_SHOPPING_BANNER    @"CLICK_SHOPPING_BANNER"// 点击轮播图的UV
#define CLICK_SHOPPING_HOT_TOPIC    @"CLICK_SHOPPING_HOT_TOPIC"// 点击热门专题的UV
#define CLICK_TOPIC_LIST_TOPIC_ITEM    @"CLICK_TOPIC_LIST_TOPIC_ITEM"// 点击专题list_专题图的UV
#define CLICK_TOPIC_LIST_COMMODITY_ITEM    @"CLICK_TOPIC_LIST_COMMODITY_ITEM"// 点击专题list_商品图的UV
#define CLICK_COMMODITY_LIST_ITEM    @"CLICK_COMMODITY_LIST_ITEM"// 点击商品list的UV
#define CLICK_SHOPPING_MSG_ICON    @"CLICK_SHOPPING_MSG_ICON"// 点击购物消息icon的UV
#define CLICK_SHOPPING_CART_ICON    @"CLICK_SHOPPING_CART_ICON"// 点击购物车UV
#define CLICK_HeartRate_Controller    @"CLICK_HeartRate_Controller"// 心率总UV
#define CLICK_HeartRate_DETECTSUCESS    @"CLICK_HeartRate_DETECTSUCESS"// 心率测量成功量
#define CLICK_HeartRate_BABYTOADULT    @"CLICK_HeartRate_BABYTOADULT"// 心率测量从宝宝切换到成人
#define CLICK_HeartRate_AULTTOBABY    @"CLICK_HeartRate_AULTTOBABY"// 心率测量从成人切换到宝宝
#define CLICK_HeartRate_DELETE    @"CLICK_HeartRate_DELETE"// 心率测量删除历史纪录
#define CLICK_HeartRate_HELPER    @"CLICK_HeartRate_HELPER"// 心率测量点击帮助量
#define SIGN_SWICH_STATE    @"SIGN_SWICH_STATE"// 签到开关打开的数量
#define CLICK_SIGN_LOCALPUSH    @"CLICK_SIGN_LOCALPUSH"// 签到push点击数量
#define LOCAL_PUSH_DAILY_CLICK    @"LOCAL_PUSH_DAILY_CLICK"// 本地日刊点击
#define LOCAL_PUSH_COLUMN_CLICK    @"LOCAL_PUSH_COLUMN_CLICK"// 本地专栏点击
#define LOCAL_PUSH_URL_CLICK    @"LOCAL_PUSH_URL_CLICK"// 本地url点击
#define LOCAL_PUSH_ARTICLE_CLICK    @"LOCAL_PUSH_ARTICLE_CLICK"// 本地文章点击
//在5.2版本追加
#define SIGN_ALERT_DISPLAY    @"SIGN_ALERT_DISPLAY"// 签到第一次弹框展现
#define SIGN_ALERT_CANCEL    @"SIGN_ALERT_CANCEL"// 签到第一次弹框点击取消
#define SIGN_ALERT_OK    @"SIGN_ALERT_OK"// 签到第一次弹框点击确定

//version:5.1版本打点统计---------------end----------------


//description:统计打点
//version:5.2版本打点统计---------------begin--------------
#define APP_SHARE    @"APP_SHARE"// APP分享
#define MENSES_START_CANCEL_TODAY    @"MENSES_START_CANCEL_TODAY" // 在今天点击取消标记
#define MAMIZHINAN_SEARCH_CALLBACK    @"MAMIZHINAN_SEARCH_CALLBACK" // 妈咪指南搜索召回
#define MAMIZHINAN_SEARCH_ANSWER_CLICK    @"MAMIZHINAN_SEARCH_ANSWER_CLICK" // 普通搜索答案点击
#define MAMAQUAN_ALLCIRCLES_PV    @"MAMAQUAN_ALLCIRCLES_PV" // 全部圈子tab访问
#define MAMAQUAN_ALLCIRCLES_DINGYUE_CLICK    @"MAMAQUAN_ALLCIRCLES_DINGYUE_CLICK" // 点击订阅圈子
#define USERCENTER_SHARE_MBABY    @"USERCENTER_SHARE_MBABY" // 分享宝宝知道
#define CIRCLE_ESSARTICLE_CIRCLESLIST    @"CIRCLE_ESSARTICLE_CIRCLESLIST" // 每个圈子的精华帖详情页PV
#define CIRCLE_ESSARTICLE_PV    @"CIRCLE_ESSARTICLE_PV" // 精华帖详情页PV_Android
#define CIRCLE_ESSARTICLE_PV    @"CIRCLE_ESSARTICLE_PV" // 精华帖详情页PV_IOS
#define CIRCLE_ARTICLE_REPLY_ZERO_RATE    @"CIRCLE_ARTICLE_REPLY_ZERO_RATE" // 零回复帖子率
#define TOOLS_DIALOG_PUSH_CLICK    @"TOOLS_DIALOG_PUSH_CLICK" // 点击工具push的数量
#define TOOLS_DIALOG_RECORD_CLICK    @"TOOLS_DIALOG_RECORD_CLICK" // 点击工具弹窗去记录
#define TOOLS_DIALOG_LATER_CLICK    @"TOOLS_DIALOG_LATER_CLICK" // 点击工具弹窗以后再说
#define MAMAQUAN_BANNER_CLICK    @"MAMAQUAN_BANNER_CLICK" // 点击banner
#define MAMAQUAN_MYSUBSCRIPTION_CIRCLE_CLICK    @"MAMAQUAN_MYSUBSCRIPTION_CIRCLE_CLICK" // 点击『我的订阅』中的圈子
#define MAMAQUAN_MYSUBSCRIPTION_ADD_CLICK    @"MAMAQUAN_MYSUBSCRIPTION_ADD_CLICK" // 点击『我的订阅』中的加号
#define MAMAQUAN_HOTARTICLE_CLICK    @"MAMAQUAN_HOTARTICLE_CLICK" // 点击热门帖子
#define MAMAQUAN_ENTRY_ARTICLE    @"MAMAQUAN_ENTRY_ARTICLE" // 妈妈圈进入帖子详情页
#define WELFARE_MYWELFARE_SECKILLTAB    @"WELFARE_MYWELFARE_SECKILLTAB" // 点击秒杀tab
#define WELFARE_MYWELFARE_FREETRAILTAB    @"WELFARE_MYWELFARE_FREETRAILTAB" // 点击试用tab
#define WELFARE_MYWELFARE_GOLDMALL_ROTARYTABLETAB    @"WELFARE_MYWELFARE_GOLDMALL_ROTARYTABLETAB" // 点击金币商城&转盘tab
#define PERSONALCENTER_MYWELFARE_CLICK    @"PERSONALCENTER_MYWELFARE_CLICK" // 个人中心-点击我的福利
#define WELFARE_ACTIVITY    @"WELFARE_ACTIVITY" // 点击活动总量
#define MESSAGE_CLICK    @"MESSAGE_CLICK" // 点击消息总量
#define MESSAGE_DELETEALL_CLICK    @"MESSAGE_DELETEALL_CLICK" // 点击清空按钮总量
#define WELFARE_BANNER_CLICK    @"WELFARE_BANNER_CLICK" // 点击轮播图
#define WELFARE_HOME_SECKILL_CLICK    @"WELFARE_HOME_SECKILL_CLICK" // 点击秒杀入口
#define WELFARE_HOME_ROTARYTABLE_CLICK    @"WELFARE_HOME_ROTARYTABLE_CLICK" // 点击天天转盘入口
#define WELFARE_HOME_GOLDMALL_CLICK    @"WELFARE_HOME_GOLDMALL_CLICK" // 点击金币商城入口
#define WELFARE_HOME_FREETRIAL_CLICK    @"WELFARE_HOME_FREETRIAL_CLICK" // 点击免费试用入口
#define WELFARE_HOME_ACTIVITY_CLICK    @"WELFARE_HOME_ACTIVITY_CLICK" // 点击社区活动入口
#define WELFARE_HOME_MYWELFARE_CLICK    @"WELFARE_HOME_MYWELFARE_CLICK" // 点击我的福利入口
#define WELFARE_HOME_MESSAGE_CLICK    @"WELFARE_HOME_MESSAGE_CLICK" // 点击福利社消息icon
#define WELFARE_HOME_EXT_CLICK    @"WELFARE_HOME_EXT_CLICK" // 点击扩展活动入口
#define WELFARE_HOME_EXT_CLICK    @"WELFARE_HOME_EXT_CLICK" // 点击扩展活动入口
#define WELFARE_HOME_EXT_CLICK    @"WELFARE_HOME_EXT_CLICK" // 点击扩展活动入口
#define WELFARE_HOME_EXT_CLICK    @"WELFARE_HOME_EXT_CLICK" // 点击扩展活动入口
#define WELFARE_HOME_EXT_CLICK    @"WELFARE_HOME_EXT_CLICK" // 点击扩展活动入口
#define WELFARE_HOME_EXT_CLICK    @"WELFARE_HOME_EXT_CLICK" // 点击扩展活动入口
#define WELFARE_SECKILL_ACTIVITY_CLICK    @"WELFARE_SECKILL_ACTIVITY_CLICK" // 活动访问总量
#define WELFARE_SECKILL_DETAIL_CUSTOMERSEVICE_CLICK    @"WELFARE_SECKILL_DETAIL_CUSTOMERSEVICE_CLICK" // 点击联系客服按钮
#define WELFARE_SECKILL_DETAIL_BUYNOW_CLICK    @"WELFARE_SECKILL_DETAIL_BUYNOW_CLICK" // 点击立即抢购按钮
#define WELFARE_SECKILL_DETAIL_DELETEORDER_CLICK    @"WELFARE_SECKILL_DETAIL_DELETEORDER_CLICK" // 点击删除订单按钮
#define WELFARE_SECKILL_CUSTOMERSERVICE_CLICK    @"WELFARE_SECKILL_CUSTOMERSERVICE_CLICK" // 点击联系客服按钮
#define WELFARE_SECKILL_DELETEORDER_CLICK    @"WELFARE_SECKILL_DELETEORDER_CLICK" // 点击删除订单按钮
#define WELFARE_SECKILL_ADRESS_CLICK    @"WELFARE_SECKILL_ADRESS_CLICK" // 点击订单地址栏
#define WELFARE_SECKILL_ADDADRESS_CLICK    @"WELFARE_SECKILL_ADDADRESS_CLICK" // 点击添加收货地址按钮
#define WELFARE_SECKILL_DETAIL_BRAND_CLICK    @"WELFARE_SECKILL_DETAIL_BRAND_CLICK" // 点击品牌外链
#define WELFARE_FREERTIAL_ACTIVITY_CLICK    @"WELFARE_FREERTIAL_ACTIVITY_CLICK" // 活动访问总量
#define WELFARE_FREERTIAL_DETAIL_CUSTOMERSERVICE_CLICK    @"WELFARE_FREERTIAL_DETAIL_CUSTOMERSERVICE_CLICK" // 点击联系客服按钮
#define WELFARE_FREERTIAL_DETAIL_APPLY_CLICK    @"WELFARE_FREERTIAL_DETAIL_APPLY_CLICK" // 点击我要申请按钮
#define WELFARE_FREERTIAL_DETAIL_CONFIRMAPPLY_CLICK    @"WELFARE_FREERTIAL_DETAIL_CONFIRMAPPLY_CLICK" // 点击确认申请按钮
#define WELFARE_FREERTIAL_DETAIL_SHARE_CLICK    @"WELFARE_FREERTIAL_DETAIL_SHARE_CLICK" // 点击分享按钮
#define WELFARE_FREERTIAL_DETAIL_COMMENTSTAB_CLICK    @"WELFARE_FREERTIAL_DETAIL_COMMENTSTAB_CLICK" // 评论TAB点击
#define WELFARE_FREERTIAL_DETAIL_BRAND_CLICK    @"WELFARE_FREERTIAL_DETAIL_BRAND_CLICK" // 点击品牌外链
#define WELFARE_FREERTIAL_DETAIL_SENDMYPAPER_CLICK    @"WELFARE_FREERTIAL_DETAIL_SENDMYPAPER_CLICK" // 点击发布我的试用报告按钮
#define WELFARE_FREERTIAL_SENDPAPER_CLICK    @"WELFARE_FREERTIAL_SENDPAPER_CLICK" // 点击提交试用报告按钮
#define WELFARE_FREERTIAL_PAPER_SEEMORE_CLICK    @"WELFARE_FREERTIAL_PAPER_SEEMORE_CLICK" // 试用报告-点击查看更多
#define WELFARE_FREERTIAL_WINNINGUSER_SEEMORE_CLICK    @"WELFARE_FREERTIAL_WINNINGUSER_SEEMORE_CLICK" // 中奖用户-点击查看更多
#define WELFARE_FREERTIAL_APPLYREASONDIALOG_CLOSE_CLICK    @"WELFARE_FREERTIAL_APPLYREASONDIALOG_CLOSE_CLICK" // 点击关闭申请理由弹窗按钮
#define WELFARE_FREERTIAL_APPLYREASONDIALOG_SEND_CLICK    @"WELFARE_FREERTIAL_APPLYREASONDIALOG_SEND_CLICK" // 点击提交申请理由按钮
#define WELFARE_FREERTIAL_ALLPAPER    @"WELFARE_FREERTIAL_ALLPAPER" // 访问试用报告列表页
#define WELFARE_FREERTIAL_ALLAPPLICANT    @"WELFARE_FREERTIAL_ALLAPPLICANT" // 访问中奖用户列表页
#define CHECKIN_PUSH_OR_DIALOG_SHOW    @"CHECKIN_PUSH_OR_DIALOG_SHOW" // 当日签到push展现量
#define CHECKIN_PUSH_OR_DIALOG_CLICK    @"CHECKIN_PUSH_OR_DIALOG_CLICK" // 当日签到push点击量
#define CHECKIN_NOTIFY_OPENDIALOG_SHOW    @"CHECKIN_NOTIFY_OPENDIALOG_SHOW" // 当日签到提醒开启弹窗展现量
#define CHECKIN_NOTIFY_OPENDIALOG_OPEN_CLICK    @"CHECKIN_NOTIFY_OPENDIALOG_OPEN_CLICK" // 当日签到提醒开启弹窗点击开启量
#define CHECKIN_NOTIFY_OPENDIALOG_LATER_CLICK    @"CHECKIN_NOTIFY_OPENDIALOG_LATER_CLICK" // 当日签到提醒开启弹窗点击以后再说量
#define CHECKIN_SWITCH_OPEN_CLICK    @"CHECKIN_SWITCH_OPEN_CLICK" // 当日签到开关打开
#define CHECKIN_SWITCH_CLOSE_CLICK    @"CHECKIN_SWITCH_CLOSE_CLICK" // 当日签到开关关闭
#define DUMASCHOOL_SHARE_ALL    @"DUMASCHOOL_SHARE_ALL" // 度妈学堂总分享
#define DUMASCHOOL_SHARE_WECHAT_AND_WECHATCIRCLE_CLICK    @"DUMASCHOOL_SHARE_WECHAT_AND_WECHATCIRCLE_CLICK" // 度妈学堂微信总分享
#define QUESTION_SEARCHQB_PAGE_PV    @"QUESTION_SEARCHQB_PAGE_PV" // 相关问题展现
#define QUESTION_SEARCHQB_XIANGGUAN_PV    @"QUESTION_SEARCHQB_XIANGGUAN_PV" // 相关问题展现
#define QUESTION_SEARCHQB_XIANGGUAN_CLICK    @"QUESTION_SEARCHQB_XIANGGUAN_CLICK" // 相关问题点击
#define HOMEPAGE_WELFARE    @"HOMEPAGE_WELFARE" // 福利社首页
#define SPLASH_AD_CLICK    @"SPLASH_AD_CLICK" // 广告点击量
//version:5.2版本打点统计---------------end----------------




//description:统计打点
//version:5.3版本打点统计---------------begin--------------
#define ARTICLE_POST_SPRING_SEND    @"ARTICLE_POST_SPRING_SEND" // 点击发帖页面提交按钮
#define VOICE_SEARCH_BEGIN    @"VOICE_SEARCH_BEGIN" // 搜索说话的量
#define CIRCLE_HOTARTICLE_CLICK    @"CIRCLE_HOTARTICLE_CLICK" // 点击妈妈圈热帖中某个帖子量
#define MAMAQUAN_BANNER_CLICK    @"MAMAQUAN_BANNER_CLICK" // 每个圈的订阅数
#define SPRING_ACT_GOTOPOST    @"SPRING_ACT_GOTOPOST" // 点击发帖赢红包按钮
#define SPRING_ACT_SEE_DETAIL    @"SPRING_ACT_SEE_DETAIL" // 点击查看详情
#define SPRING_GIFT_SHOW    @"SPRING_GIFT_SHOW" // 红包展现量
#define SPRING_GIFT_OPEN    @"SPRING_GIFT_OPEN" // 点击拆红包按钮
#define SPRING_GIFT_GOTO_SEE    @"SPRING_GIFT_GOTO_SEE" // 点击去看看
#define SPRING_GIFT_GOTO_TAKE    @"SPRING_GIFT_GOTO_TAKE" // 点击领取奖品
#define HOTQUERY_SEARCH_CLICK    @"HOTQUERY_SEARCH_CLICK" // 搜索热词点击
#define FULL_AGE_LIST_PAGE_VIEW    @"FULL_AGE_LIST_PAGE_VIEW" // 访问全时期专栏列表页
#define FULL_AGE_CARD_SHOW    @"FULL_AGE_CARD_SHOW" // 展现全时期专栏
#define FULL_AGE_CARD_CLICK    @"FULL_AGE_CARD_CLICK" // 点击全时期专栏
#define FULL_AGE_DETAIL_PAGE_VIEW    @"FULL_AGE_DETAIL_PAGE_VIEW" // 访问全时期专栏详情页
#define FULL_AGE_FORMER_AGE_CLICK    @"FULL_AGE_FORMER_AGE_CLICK" // 点击“查看往期内容”
#define TOOL_REORDER_VIEW    @"TOOL_REORDER_VIEW" // 手动调整顺序
#define TOOL_REORDER_ACTION    @"TOOL_REORDER_ACTION" // 手动调整顺序
#define HOME_REORDER_VIEW    @"HOME_REORDER_VIEW" // 手动设置卡片顺序
#define HOME_REORDER_ACTION    @"HOME_REORDER_ACTION" // 手动设置卡片顺序
#define HOT_TOPIC_CARD_CLICK    @"HOT_TOPIC_CARD_CLICK" // 点击热门专题卡片
#define HOT_TOPIC_CARD_SHOW    @"HOT_TOPIC_CARD_SHOW" // 展现热门专题
#define HOT_TOPIC_LIST_PAGE_VIEW    @"HOT_TOPIC_LIST_PAGE_VIEW" // 访问热门专题列表页
#define HOT_TOPIC_FORMER_TOPIC_CLICK    @"HOT_TOPIC_FORMER_TOPIC_CLICK" // 点击“查看往期内容”
#define HOMEPAGE_BANNER_CLICK    @"HOMEPAGE_BANNER_CLICK" // 点击banner图
#define HOMEPAGE_ARTICLE_TEST    @"HOMEPAGE_ARTICLE_TEST" // 首页热贴点击（包含qid和pos）
//version:5.3版本打点统计---------------end----------------

#define PUSH_REGISTER_SUCCESS   @"PUSH_REGISTER_SUCCESS"
#define PUSH_REGISTER_FAIL      @"PUSH_REGISTER_FAIL"

#define BABY_MUSIC_CHANGE_CLICK    @"BABY_MUSIC_CHANGE_CLICK" // 点击上一首PREV、下一首NEXT
#define MUSIC_ALBUM_LIST_CLICK    @"MUSIC_ALBUM_LIST_CLICK" // 点击专辑下拉菜单
#define MUSIC_ALBUM_ITEM_CLICK    @"MUSIC_ALBUM_ITEM_CLICK" // 点击切换其他专辑
#define MUSIC_SINGLE_CLICK    @"MUSIC_SINGLE_CLICK" // 点击切换其他单曲
#define MUSIC_GLOBAL_BABY_STOP_CLICK    @"MUSIC_GLOBAL_BABY_STOP_CLICK" // 点击全局关闭按钮
#define INDEX_BABY_MUSIC_PAUSE_CLICK    @"INDEX_BABY_MUSIC_PAUSE_CLICK" // 点击首页暂停按钮
#define MUSIC_COLLECT_CLICK    @"MUSIC_COLLECT_CLICK" // 点击收藏
#define MUSIC_SHARE_CLICK    @"MUSIC_SHARE_CLICK" // 点击分享
#define MUSIC_BABY_PLAYTIME    @"MUSIC_BABY_PLAYTIME" // 人均收听时长
#define INDEX_BABY_MUSIC_CLICK    @"INDEX_BABY_MUSIC_CLICK" // 点击首页卡片
#define INDEX_BABY_MUSIC_START_CLICK    @"INDEX_BABY_MUSIC_START_CLICK" // 点击首页卡片播放按钮
#define INDEX_MOM_MUSIC_CLICK    @"INDEX_MOM_MUSIC_CLICK" // 点击首页音频
#define MUSIC_GLOBAL_MOM_STOP_CLICK    @"MUSIC_GLOBAL_MOM_STOP_CLICK" // 点击全局关闭按钮
#define MUSIC_MOM_PLAYTIME    @"MUSIC_MOM_PLAYTIME" // 人均收听时长
#define CIRCLE_VOTE_SHARE    @"CIRCLE_VOTE_SHARE" // 分享投票贴数
#define CIRCLE_EXPERIENCE_SHARE    @"CIRCLE_EXPERIENCE_SHARE" // 分享经验贴
#define INDEX_REMIND_DIALOG_VIEW    @"INDEX_REMIND_DIALOG_VIEW" // 提醒弹框展现UV
#define INDEX_REMIND_DIALOG_ITEM_CLICK    @"INDEX_REMIND_DIALOG_ITEM_CLICK" // 点击提醒UV
#define INDEX_REMIND_DIALOG_KNOW_CLICK    @"INDEX_REMIND_DIALOG_KNOW_CLICK" // 点击“我知道了”UV
#define PAGE_REMIND_LIST_VIEW    @"PAGE_REMIND_LIST_VIEW" // 提醒列表页UV
#define PAGE_REMIND_LIST_DETAIL_VIEW    @"PAGE_REMIND_LIST_DETAIL_VIEW" // 提醒详情页UV
#define INDEX_REMIND_BUTTON_CLICK    @"INDEX_REMIND_BUTTON_CLICK" // 提醒按钮点击UV
#define INDEX_ARTICLE_CLICK    @"INDEX_ARTICLE_CLICK" // 高手在民间点击UV
#define INDEX_MUSIC_CLICK    @"INDEX_MUSIC_CLICK" // 播放音频UV
#define INDEX_HEAD_CARD    @"INDEX_HEAD_CARD" // 点击胎儿发育UV

#define FOOD_SEARCH_CAMERA_CLICK    @"FOOD_SEARCH_CAMERA_CLICK" // 今日点击拍照icon
#define FOOD_SEARCH_CAMERA_START_SUCCESS    @"FOOD_SEARCH_CAMERA_START_SUCCESS" // 今日成功调起相机
#define FOOD_SEARCH_PICTURE_UPLOAD    @"FOOD_SEARCH_PICTURE_UPLOAD" // 今日上传图片请求总量
#define FOOD_SEARCH_PICTURE_REMARK    @"FOOD_SEARCH_PICTURE_REMARK" // 今日点击“我要报错”
#define FOOD_SEARCH_PICTURE_REMARK_SUCCESS    @"FOOD_SEARCH_PICTURE_REMARK_SUCCESS" // 今日标记报错成功量
#define PUSH_URLROUTER @"PUSH_URLROUTER"
#define CIRCLE_ACTIVITIES_ENTRYWAP_CLICK    @"CIRCLE_ACTIVITIES_ENTRYWAP_CLICK" // 进入活动Wap页

#define DAILY_WEB_VIDEO_PLAY @"DAILY_WEB_VIDEO_PLAY" // 保健视频点击
#define DAILY_WEB_VIDEO_PLAY_DURATION @"DAILY_WEB_VIDEO_PLAY_DURATION" // 保健播放时长
#define VIDEO_LIST_PLAY_DURATION @"VIDEO_LIST_PLAY_DURATION" //早教视频播放时长

#define NUOMI_WELFARE_INDEX_VIEW    @"NUOMI_WELFARE_INDEX_VIEW" // 新版福利社首页pv
#define NUOMI_LIST_SHOW    @"NUOMI_LIST_SHOW" // 羊毛列表展现uv
#define NUOMI_MYWELFARE_SHOW    @"NUOMI_MYWELFARE_SHOW" // 我的福利-羊毛板块uv
#define NUOMI_MYWELFARE_CLICK    @"NUOMI_MYWELFARE_CLICK" // 我的福利-羊毛-点击订单总uv
#define NUOMI_WELFARE_INDEX_CLICK    @"NUOMI_WELFARE_INDEX_CLICK" // 列表页点击羊毛信息总uv
#define NUOMI_PAY_CONFIRM_CLICK    @"NUOMI_PAY_CONFIRM_CLICK" // 点击确认支付按钮uv
#define NUOMI_MALL_CLICK    @"NUOMI_MALL_CLICK" // 新版本点击金币商城uv
#define NUOMI_WHEEL_CLICK    @"NUOMI_WHEEL_CLICK" // 新版本点击天天转盘uv
#define NUOMI_SEEK_CLICK    @"NUOMI_SEEK_CLICK" // 新版本点击秒杀uv
#define NUOMI_PROBATION_CLICK    @"NUOMI_PROBATION_CLICK" // 新版本点击免费试用uv
#define NUOMI_OPEN_LOCATION_CLICK    @"NUOMI_OPEN_LOCATION_CLICK" // 点击“去开启”uv
#define NUOMI_REFRESH_LOCATION_CLICK    @"NUOMI_REFRESH_LOCATION_CLICK" // 点击“刷新位置”uv
#define NUOMI_NO_DATA    @"NUOMI_NO_DATA" // 当前定位下无羊毛信息uv
#define NUOMI_NO_LOCATION_DATA    @"NUOMI_NO_LOCATION_DATA" // 未开启定位uv

#define VIDEO_PLAY_TIMES @"VIDEO_PLAY_TIMES" // 视频播放次数
#define VIDEO_PLAY_LENGTH @"VIDEO_PLAY_LENGTH" // 视频播放时长
#define SMALL_VIDEO_COLLECTION_NUMBERS @"SMALL_VIDEO_COLLECTION_NUMBERS" // 小视频收藏次数
#define SMALL_VIDEO_SHARE_NUMBERS @"SMALL_VIDEO_SHARE_NUMBERS" // 小视频分享次数
#define EXP_VIDEO_COLLECTION_NUMBERS @"EXP_VIDEO_COLLECTION_NUMBERS" // 经验视频收藏次数
#define EXP_VIDEO_SHARE_NUMBERS @"EXP_VIDEO_SHARE_NUMBERS" // 经验视频分享次数
#define UPLOAD_TASK_FAIL @"UPLOAD_TASK_FAIL" // 上传失败次数
#define UPLOAD_TASK_RETRY @"UPLOAD_TASK_RETRY" // 上传重试点击次数
#define UPLOAD_TASK_CANCEL @"UPLOAD_TASK_CANCEL" // 上传取消点击次数

#define SETTING_WATERMARK_SWITCH_CLICK @"SETTING_WATERMARK_SWITCH_CLICK"
#define UCENTER_CLICK_SETTING    @"UCENTER_CLICK_SETTING" // 设置点击UV
#define UCENTER_CLICK_LIKE       @"UCENTER_CLICK_LIKE" // 赞点击UV
#define UCENTER_CLICK_FOLLOW     @"UCENTER_CLICK_FOLLOW" // 关注点击UV
#define UCENTER_CLICK_FANS       @"UCENTER_CLICK_FANS" // 粉丝点击UV
#define USER_CENTER_INDEX_TOOL    @"USER_CENTER_INDEX_TOOL" // 我的工具库TAB点击UV
#define UCENTER_CLICK_HEADER_AREA    @"UCENTER_CLICK_HEADER_AREA" // 头图区点击UV

#define SEARCH_USER_ICON_CLICK       @"SEARCH_USER_ICON_CLICK"  //点击用户头像pv
#define SEARCH_MORE_USER_CLICK       @"SEARCH_MORE_USER_CLICK"  //点击更多用户pv
#define USER_LIST_FOLLOW_CLICK       @"USER_LIST_FOLLOW_CLICK"  //点击用户列表页-关注按钮pv
#define SEND_ARTICLE_AFTER_SEARCH    @"SEND_ARTICLE_AFTER_SEARCH"  //搜索后发帖量
#define ASK_AFTER_SEARCH             @"ASK_AFTER_SEARCH"           //搜索后提问量
#define NEW_SEARCH_HOT_VIEW          @"NEW_SEARCH_HOT_VIEW"        // 热词页展现
#define NEW_SEARCH_HOT_CLICK         @"NEW_SEARCH_HOT_CLICK"       // 点击搜索热词
#define NEW_SEARCH_HISTORY_CLICK     @"NEW_SEARCH_HISTORY_CLICK"   // 点击历史记录
#define NEW_SEARCH_HISTORY_CLEAR     @"NEW_SEARCH_HISTORY_CLEAR"   // 确定清空历史记录
#define ASK_OTHER_MOTHER_SHOW        @"ASK_OTHER_MOTHER_SHOW"   // “发帖问问其他宝妈”展现
#define ASK_OTHER_MOTHER_CLICK       @"ASK_OTHER_MOTHER_CLICK"  // “发帖问问其他宝妈”点击
#define ASK_OTHER_DOCTOR_SHOW        @"ASK_OTHER_DOCTOR_SHOW"   // “向医生提问”展现
#define ASK_OTHER_DOCTOR_CLICK       @"ASK_OTHER_DOCTOR_CLICK"  // “向医生提问”点击


//version:5.6版本打点统计---------------end----------------
#define HOME_PAGE_VISIT    @"HOME_PAGE_VISIT" // 首页访问UV
#define HOME_PAGE_TAB_CLICK    @"HOME_PAGE_TAB_CLICK" // 首页总点击UV
#define HOME_DAILY_CLICK    @"HOME_DAILY_CLICK" // 进入日刊UV
#define HOME_CLICK_VIDEO        @"HOME_CLICK_VIDEO"     //点击视频
#define HOME_CLICK_USER_ICON    @"HOME_CLICK_USER_ICON" // 头像UV
#define HOME_CLICK_MESSAGE_ICON    @"HOME_CLICK_MESSAGE_ICON" // 点击消息UV
#define HOME_CLICK_SEARCH    @"HOME_CLICK_SEARCH" // 点击搜索UV
#define HOME_CLICK_ARTICLE    @"HOME_CLICK_ARTICLE" // 点击帖子UV
#define HOME_CLICK_FOLLOW    @"HOME_CLICK_FOLLOW" // 点击关注按钮
#define HOME_CHANNEL_TAB_CLICK    @"HOME_CHANNEL_TAB_CLICK" // 点击频道TAB UV
#define HOME_CHANNEL_LEBAL_CLICK    @"HOME_CHANNEL_LEBAL_CLICK" // 点击频道标签UV
#define INDEX_REMIND_DIALOG_ITEM_CLICK    @"INDEX_REMIND_DIALOG_ITEM_CLICK" // 点击提醒弹框内容UV
#define CHANNEL_DO_SUBSCRIBE    @"CHANNEL_DO_SUBSCRIBE" // 今日频道订阅总次数
#define CHANNEL_DO_SUBSCRIBE_ACTIVE    @"CHANNEL_DO_SUBSCRIBE_ACTIVE" // 今日主动订阅次数

#define CHANNEL_PAGE_VISIT    @"CHANNEL_PAGE_VISIT" // 频道页总UV
#define CHANNEL_PAGE_VISIT_TAB    @"CHANNEL_PAGE_VISIT_TAB" // 频道页总UV_精选
#define CHANNEL_PAGE_VISIT_TAB    @"CHANNEL_PAGE_VISIT_TAB" // 频道页总UV_最新

#define ARTICLE_DETAIL_LINK_CLICK  @"ARTICLE_DETAIL_LINK_CLICK"