//package com.mpaas.demo.service;
//
//import com.alipay.mobile.base.config.ConfigService;
//
//public class MPConfigService {
//    /**
//     * 获取开关
//     *
//     * @param key
//     * @return
//     */
//    public static String getConfig(String key);
//    /**
//     *  加载开关，默认达到半小时间隔才会去服务端拉取最新开关。
//     */
//    public static void loadConfig();
//    /**
//     * 马上加载开关
//     *
//     * @param delay 加载开关的延迟时间，单位毫秒，0 为立刻加载
//     */
//    public static void loadConfigImmediately(long delay);
//    /**
//     * 注册开关改变监听器
//     * @param configChangeListener 监听器
//     * @return
//     */
//    public static boolean addConfigChangeListener(ConfigService.ConfigChangeListener configChangeListener);
//    /**
//     * 移除开关改变监听器
//     * @param configChangeListener 监听器
//     */
//    public static void removeConfigChangeListener(ConfigService.ConfigChangeListener configChangeListener);
//}
