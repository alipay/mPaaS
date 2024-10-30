package com.mpaas.upgrade;

import android.content.Context;
import android.content.SharedPreferences;


import java.lang.reflect.InvocationTargetException;
import java.lang.reflect.Method;
import java.util.Map;

public class SPUtils {

    private static final String LASTSHOWTIME ="lastShowTime";

    //记录单次升级的 间隔时间
    private static final String INTERVALTIME ="IntervalTime";
    /**
     * 保存在手机里面的文件名
     */
    public static final String FILE_NAME = "mp_content_share_data";

    //单词升级时间默认是 3天
    private static long ONE_DAY_TIME = 86400000L;


    /**
     * 设置版本升级弹框时间（最近一次弹框时间）
     *
     * @param context
     */
    public static void setlastShowTime(Context context ,Long lastShowTime ) {

        SharedPreferences sp = context.getSharedPreferences(FILE_NAME,
                Context.MODE_PRIVATE);
        SharedPreferences.Editor editor = sp.edit();

        editor.putLong(LASTSHOWTIME, lastShowTime);

        SharedPreferencesCompat.apply(editor);
    }

    /**
     * 获取最近一次弹框的时间，默认值为0
     *
     * @param context
     */
    public static Long getlastShowTime(Context context) {
        SharedPreferences sp = context.getSharedPreferences(FILE_NAME,
                Context.MODE_PRIVATE);

        return sp.getLong(LASTSHOWTIME, 0L);
    }


    /**
     * 单词升级的弹框时间，本地记录下
     *
     * @param context
     */
    public static void putIntervalTime(Context context ,Long dialogShowTime) {

        SharedPreferences sp = context.getSharedPreferences(FILE_NAME,
                Context.MODE_PRIVATE);
        SharedPreferences.Editor editor = sp.edit();

        editor.putLong(INTERVALTIME, dialogShowTime);

        SharedPreferencesCompat.apply(editor);
    }


    public static Long getIntervalTime(Context context) {
        SharedPreferences sp = context.getSharedPreferences(FILE_NAME,
                Context.MODE_PRIVATE);

        // 单次升级默认间隔是3天
        return sp.getLong(INTERVALTIME, 3* ONE_DAY_TIME);
    }




    /**
     * 移除某个key值已经对应的值
     *
     * @param context
     * @param key
     */
    public static void remove(Context context, String key) {
        SharedPreferences sp = context.getSharedPreferences(FILE_NAME,
                Context.MODE_PRIVATE);
        SharedPreferences.Editor editor = sp.edit();
        editor.remove(key);
        SharedPreferencesCompat.apply(editor);
    }

    /**
     * 清除所有数据
     *
     * @param context
     */
    public static void clear(Context context) {
        SharedPreferences sp = context.getSharedPreferences(FILE_NAME,
                Context.MODE_PRIVATE);
        SharedPreferences.Editor editor = sp.edit();
        editor.clear();
        SharedPreferencesCompat.apply(editor);
    }

    /**
     * 查询某个key是否已经存在
     *
     * @param context
     * @param key
     * @return
     */
    public static boolean contains(Context context, String key) {
        SharedPreferences sp = context.getSharedPreferences(FILE_NAME,
                Context.MODE_PRIVATE);
        return sp.contains(key);
    }

    /**
     * 返回所有的键值对
     *
     * @param context
     * @return
     */
    public static Map<String, ?> getAll(Context context) {
        SharedPreferences sp = context.getSharedPreferences(FILE_NAME,
                Context.MODE_PRIVATE);
        return sp.getAll();
    }

    /**
     * 创建一个解决SharedPreferencesCompat.apply方法的一个兼容类
     *
     * @author zhy
     */
    private static class SharedPreferencesCompat {
        private static final Method sApplyMethod = findApplyMethod();

        /**
         * 反射查找apply的方法
         *
         * @return
         */
        @SuppressWarnings({"unchecked", "rawtypes"})
        private static Method findApplyMethod() {
            try {
                Class clz = SharedPreferences.Editor.class;
                return clz.getMethod("apply");
            } catch (NoSuchMethodException e) {
            }

            return null;
        }

        /**
         * 如果找到则使用apply执行，否则使用commit
         *
         * @param editor
         */
        public static void apply(SharedPreferences.Editor editor) {
            try {
                if (sApplyMethod != null) {
                    sApplyMethod.invoke(editor);
                    return;
                }
            } catch (IllegalArgumentException e) {
            } catch (IllegalAccessException e) {
            } catch (InvocationTargetException e) {
            }
            editor.commit();
        }
    }


}
