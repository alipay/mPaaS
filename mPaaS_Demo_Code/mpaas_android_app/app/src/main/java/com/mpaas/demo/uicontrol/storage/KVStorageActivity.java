package com.mpaas.demo.uicontrol.storage;

import android.os.Bundle;
import android.text.TextUtils;
import android.util.TypedValue;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.AdapterView;
import android.widget.BaseAdapter;
import android.widget.TextView;

import com.alipay.android.phone.mobilesdk.storage.sp.APSharedPreferences;
import com.alipay.android.phone.mobilesdk.storage.sp.SharedPreferencesManager;
import com.mpaas.demo.R;

import java.util.Iterator;
import java.util.LinkedHashMap;
import java.util.LinkedList;
import java.util.Map;

public class KVStorageActivity extends BaseStorageActivity {

    private String mRandomKey;
    private String mRandomValue;
    private APSharedPreferences mAPSharedPreferences;
    private final LinkedHashMap<String, String> mData = new LinkedHashMap<>();
    private final LinkedList<String> mDataKeyIndex = new LinkedList<>();

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_storage);
        mAPSharedPreferences = SharedPreferencesManager.getInstance(this, GROUP_ID);
        initData();
        findView();
        initView();
    }

    private void initView() {
        setTitle(getString(R.string.kv_storage));
        mAdapter = new KVAdapter();
        mMainLv.setAdapter(mAdapter);
        mMainBtn.setText(R.string.insert_kv);
        mMainBtn.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                if (mRandomKey == null) {
                    // 随机生成键值对信息
                    randomKeyValue();
                    mMainTv.setText(getString(R.string.key_is) + mRandomKey +
                            "\n" + getString(R.string.value_is) + mRandomValue);
                    mMainBtn.setText(getString(R.string.insert_kv));
                } else {
                    // 将随机生成的键值对信息插入SP并刷新listView
                    insertKeyValue(mRandomKey, mRandomValue);
                    mAdapter.notifyDataSetChanged();
                    mRandomKey = null;
                    mRandomValue = null;
                    mMainTv.setText("");
                    mMainBtn.setText(getString(R.string.random_kv));
                }
            }
        });
        mMainLv.setOnItemClickListener(new AdapterView.OnItemClickListener() {
            @Override
            public void onItemClick(AdapterView<?> adapterView, View view, int i, long l) {
                String key = mDataKeyIndex.get(i);
                if (null != key) {
                    deleteKeyValue(key);
                    // 删除键值对信息并刷新ListView
                    mAdapter.notifyDataSetChanged();
                }
            }
        });
    }

    /**
     * 初始化键值对数据
     */
    private void initData() {
        mData.clear();
        try {
            mData.putAll((Map<String, String>) mAPSharedPreferences.getAll());
            Iterator it = mData.entrySet().iterator();
            while (it.hasNext()) {
                Map.Entry<String, String> entity = (Map.Entry) it.next();
                mDataKeyIndex.add(entity.getKey());
            }
        } catch (Exception e) {
            e.printStackTrace();
        }
    }

    /**
     * 随机生成键值对
     */
    private void randomKeyValue() {
        // 随机生成名字
        StringBuilder sb = new StringBuilder();
        for (int i = 0; i < 4; i++) {
            sb.append((char) (Math.random() * 26 + 'A'));
        }
        mRandomKey = sb.toString();
        sb = new StringBuilder();
        for (int i = 0; i < 8; i++) {
            sb.append((char) (Math.random() * 26 + 'a'));
        }
        mRandomValue = sb.toString();
    }


    /**
     * 插入键值对
     *
     * @param key   key
     * @param value value
     */
    private void insertKeyValue(String key, String value) {
        if (TextUtils.isEmpty(key)) {
            return;
        }
        mAPSharedPreferences.putString(key, value);
        mAPSharedPreferences.commit();
        mData.put(key, value);
        mDataKeyIndex.add(key);
    }

    /**
     * 删除键值对
     *
     * @param key key
     */
    private void deleteKeyValue(String key) {
        if (TextUtils.isEmpty(key)) {
            return;
        }
        mAPSharedPreferences.remove(key);
        mAPSharedPreferences.commit();
        mData.remove(key);
        mDataKeyIndex.remove(key);
    }


    private class KVAdapter extends BaseAdapter {

        @Override
        public int getCount() {
            return mData.size();
        }

        @Override
        public Object getItem(int i) {
            return mData.get(i);
        }

        @Override
        public long getItemId(int i) {
            return i;
        }

        @Override
        public View getView(int i, View view, ViewGroup viewGroup) {
            ViewHolder viewHolder;
            if (view == null) {
                view = LayoutInflater.from(KVStorageActivity.this).inflate(R.layout.item_storage, null, true);
                viewHolder = new ViewHolder();
                viewHolder.firstTv = (TextView) view.findViewById(R.id.item_storage_first_tv);
                viewHolder.secondTv = (TextView) view.findViewById(R.id.item_storage_second_tv);
                viewHolder.firstTv.setTextSize(TypedValue.COMPLEX_UNIT_SP, 14);
                viewHolder.secondTv.setTextSize(TypedValue.COMPLEX_UNIT_SP, 14);
                view.setTag(viewHolder);
            } else {
                viewHolder = (ViewHolder) view.getTag();
            }
            String key = mDataKeyIndex.get(i);
            String value = mData.get(key);
            viewHolder.firstTv.setText(getString(R.string.key_is) + " " + key);
            viewHolder.secondTv.setText(getString(R.string.value_is) + " " + value);
            return view;
        }
    }
}
