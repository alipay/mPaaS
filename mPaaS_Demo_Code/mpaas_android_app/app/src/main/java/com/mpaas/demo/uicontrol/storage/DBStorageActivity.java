package com.mpaas.demo.uicontrol.storage;

import android.os.Bundle;
import android.util.TypedValue;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.AdapterView;
import android.widget.BaseAdapter;
import android.widget.TextView;
import android.widget.Toast;

import com.mpaas.demo.R;
import com.mpaas.demo.uicontrol.storage.api.DemoOrmLiteSqliteOpenHelper;
import com.mpaas.demo.uicontrol.storage.api.User;


import java.util.ArrayList;
import java.util.Date;
import java.util.List;

public class DBStorageActivity extends BaseStorageActivity {

    private User mRandomUser;
    private DemoOrmLiteSqliteOpenHelper mDbHelper;
    private final List<User> mData = new ArrayList<>();

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_storage);
        // 生成DBHelper
        mDbHelper = new DemoOrmLiteSqliteOpenHelper(this);
        initData();
        findView();
        initView();
    }

    private void initView() {
        setTitle(getString(R.string.db_storage));
        mAdapter = new UserAdapter();
        mMainLv.setAdapter(mAdapter);
        mMainBtn.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                if (mRandomUser == null) {
                    // 随机生成用户信息
                    randomUser();
                    mMainTv.setText(getString(R.string.user_name_is) + mRandomUser.name +
                            "\n" + getString(R.string.user_color_is) + Integer.toHexString(mRandomUser.color));
                    mMainBtn.setText(getString(R.string.insert_user));
                } else {
                    // 将随机生成的用户信息插入DB并刷新listView
                    insertUser(mRandomUser);
                    initData();
                    mAdapter.notifyDataSetChanged();
                    mRandomUser = null;
                    mMainTv.setText("");
                    mMainBtn.setText(getString(R.string.random_user));
                }
            }
        });
        mMainLv.setOnItemClickListener(new AdapterView.OnItemClickListener() {
            @Override
            public void onItemClick(AdapterView<?> adapterView, View view, int i, long l) {
                User user = mData.get(i);
                if (null != user) {
                    // 删除用户信息并刷新ListView
                    deleteUser(user);
                    initData();
                    mAdapter.notifyDataSetChanged();
                }
            }
        });
    }

    /**
     * 初始化DB数据
     */
    private void initData() {
        mData.clear();
        try {
            mData.addAll(mDbHelper.getDao(User.class).queryBuilder().orderBy("timestamp", true).query());
        } catch (Exception e) {
            e.printStackTrace();
        }
    }

    /**
     * 随机生成用户信息
     */
    private void randomUser() {
        User temp = new User();
        // 随机生成名字
        StringBuilder nameSb = new StringBuilder();
        nameSb.append((char) (Math.random() * 26 + 'A'));
        for (int i = 0; i < 7; i++) {
            nameSb.append((char) (Math.random() * 26 + 'a'));
        }
        temp.name = nameSb.toString();
        // 随机生成颜色
        temp.color = (int) (Math.random() * 0XFFFFFF);
        temp.timestamp = System.currentTimeMillis();
        mRandomUser = temp;
    }

    /**
     * 插入用户信息
     *
     * @param user 用户信息
     */
    private void insertUser(User user) {
        if (null == user) {
            return;
        }
        try {
            // 先查询，如果用户名冲突则不插入
            List<User> temp = mDbHelper.getDao(User.class).queryBuilder().where().eq("name", user.name).query();
            if (temp != null && temp.size() > 0) {
                Toast.makeText(this, getString(R.string.user_repeated), Toast.LENGTH_SHORT).show();
                return;
            }
            // 插入
            mDbHelper.getDao(User.class).create(user);
        } catch (Exception e) {
            e.printStackTrace();
        }
    }

    /**
     * 删除用户信息
     *
     * @param user 用户信息
     */
    private void deleteUser(User user) {
        try {
            mDbHelper.getDao(User.class).delete(user);
        } catch (Exception e) {
            e.printStackTrace();
        }
    }

    private class UserAdapter extends BaseAdapter {

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
                view = LayoutInflater.from(DBStorageActivity.this).inflate(R.layout.item_storage, null, true);
                viewHolder = new ViewHolder();
                viewHolder.firstTv = (TextView) view.findViewById(R.id.item_storage_first_tv);
                viewHolder.secondTv = (TextView) view.findViewById(R.id.item_storage_second_tv);
                viewHolder.firstTv.setTextSize(TypedValue.COMPLEX_UNIT_SP, 18);
                viewHolder.secondTv.setTextSize(TypedValue.COMPLEX_UNIT_SP, 12);
                view.setTag(viewHolder);
            } else {
                viewHolder = (ViewHolder) view.getTag();
            }
            User user = mData.get(i);
            viewHolder.firstTv.setText(getString(R.string.user_name_is) + user.name);
            viewHolder.secondTv.setText(getString(R.string.user_time_is) + SIMPLE_DATE_FORMAT.format(new Date(user.timestamp)));
            view.setBackgroundColor(0x3f000000 + user.color);
            return view;
        }
    }

}
