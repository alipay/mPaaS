package com.mpaas.demo.uicontrol.storage;

import android.os.Bundle;
import android.util.TypedValue;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.AdapterView;
import android.widget.BaseAdapter;
import android.widget.TextView;

import com.alipay.android.phone.mobilesdk.storage.file.BaseFile;
import com.alipay.android.phone.mobilesdk.storage.file.ZExternalFile;
import com.alipay.android.phone.mobilesdk.storage.file.ZFile;
import com.alipay.android.phone.mobilesdk.storage.file.ZSecurityFileInputStream;
import com.alipay.android.phone.mobilesdk.storage.file.ZSecurityFileOutputStream;
import com.mpaas.demo.R;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.io.StringReader;
import java.io.StringWriter;
import java.util.Date;
import java.util.LinkedList;
import java.util.List;
import java.util.Random;

public class FileStorageActivity extends BaseStorageActivity {

    private BaseFile mRandomFile;
    private String mFilePath;
    private String mExternalFilePath;
    private final List<BaseFile> mData = new LinkedList<>();
    private static final int DEFAULT_BUFFER_SIZE = 1024;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_storage);
        mFilePath = getFilesDir() + File.separator + GROUP_ID;
        mExternalFilePath = getExternalFilesDir(GROUP_ID).getAbsolutePath();
        initData();
        findView();
        initView();
    }

    private void initView() {
        setTitle(getString(R.string.file_storage));
        mAdapter = new FileAdapter();
        mMainLv.setAdapter(mAdapter);
        mMainBtn.setText(R.string.insert_file);
        mMainBtn.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                if (mRandomFile == null) {
                    // 随机生成文件信息
                    randomFile();
                    mMainTv.setText(getString(R.string.name_is) + mRandomFile.getName() +
                            "\n" + getString(R.string.file_type_is) + mRandomFile.getClass().getSimpleName());
                    mMainBtn.setText(getString(R.string.insert_file));
                } else {
                    // 将随机生成的文件信息插入DB并刷新listView
                    insertFile(mRandomFile);
                    initData();
                    mAdapter.notifyDataSetChanged();
                    mRandomFile = null;
                    mMainTv.setText("");
                    mMainBtn.setText(getString(R.string.random_file));
                }
            }
        });
        mMainLv.setOnItemClickListener(new AdapterView.OnItemClickListener() {
            @Override
            public void onItemClick(AdapterView<?> adapterView, View view, int i, long l) {
                BaseFile file = mData.get(i);
                if (null != file) {
                    // 删除文件信息并刷新ListView
                    deleteFile(file);
                    mAdapter.notifyDataSetChanged();
                }
            }
        });
    }

    /**
     * 初始化File数据
     */
    private void initData() {
        mData.clear();
        File dir = new File(mFilePath);
        File[] files = dir.listFiles();
        if (null != files) {
            for (File file : files) {
                mData.add(new ZFile(this, GROUP_ID, file.getName()));
            }
        }

        File extDir = new File(mExternalFilePath);
        if (null != files) {
            files = extDir.listFiles();
            for (File file : files) {
                mData.add(new ZExternalFile(this, GROUP_ID, file.getName()));
            }
        }
    }

    /**
     * 随机生成文件
     */
    private void randomFile() {
        BaseFile file;
        boolean isExternal = new Random().nextBoolean();

        // 随机生成名字
        StringBuilder sb = new StringBuilder();
        sb.append((char) (Math.random() * 26 + 'A'));
        for (int i = 0; i < 7; i++) {
            sb.append((char) (Math.random() * 26 + 'a'));
        }
        String name = sb.toString();
        if (isExternal) {
            file = new ZExternalFile(this, GROUP_ID, name);
        } else {
            file = new ZFile(this, GROUP_ID, name);
        }
        mRandomFile = file;
    }

    /**
     * 插入文件
     *
     * @param file 文件
     */
    private void insertFile(BaseFile file) {
        if (null == file) {
            return;
        }
        StringBuilder sb = new StringBuilder();
        String content = sb.append(file.getName())
                .append(' ')
                .append(SIMPLE_DATE_FORMAT.format(new Date(System.currentTimeMillis()))).toString();
        string2File(content, file);
        try {
            if (!file.exists()) {
                file.createNewFile();
            }
            mData.add(file);
        } catch (Exception e) {
            e.printStackTrace();
        }
    }

    /**
     * 删除文件
     *
     * @param file 文件
     */
    private void deleteFile(BaseFile file) {
        try {
            file.delete();
            mData.remove(file);
        } catch (Exception e) {
            e.printStackTrace();
        }
    }

    /**
     * 文件转文本
     *
     * @param file 文件
     * @return 文本
     */
    public String file2String(File file) {
        InputStreamReader reader = null;
        StringWriter writer = new StringWriter();
        try {
            reader = new InputStreamReader(new ZSecurityFileInputStream(file, this));
            //将输入流写入输出流
            char[] buffer = new char[DEFAULT_BUFFER_SIZE];
            int n = 0;
            while (-1 != (n = reader.read(buffer))) {
                writer.write(buffer, 0, n);
            }
        } catch (Exception e) {
            e.printStackTrace();
            return null;
        } finally {
            if (reader != null)
                try {
                    reader.close();
                } catch (IOException e) {
                    e.printStackTrace();
                }
        }
        //返回转换结果
        if (writer != null) {
            return writer.toString();
        } else {
            return null;
        }
    }

    /**
     * 文本转文件
     *
     * @param res  文本
     * @param file 文件
     * @return true表示成功，反之失败
     */
    public boolean string2File(String res, File file) {
        boolean flag = true;
        BufferedReader bufferedReader = null;
        BufferedWriter bufferedWriter;
        try {
            bufferedReader = new BufferedReader(new StringReader(res));
            bufferedWriter = new BufferedWriter(new OutputStreamWriter(new ZSecurityFileOutputStream(file, this)));
            //字符缓冲区
            char buf[] = new char[DEFAULT_BUFFER_SIZE];
            int len;
            while ((len = bufferedReader.read(buf)) != -1) {
                bufferedWriter.write(buf, 0, len);
            }
            bufferedWriter.flush();
            bufferedReader.close();
            bufferedWriter.close();
        } catch (Exception e) {
            e.printStackTrace();
            flag = false;
            return flag;
        } finally {
            if (bufferedReader != null) {
                try {
                    bufferedReader.close();
                } catch (IOException e) {
                    e.printStackTrace();
                }
            }
        }
        return flag;
    }

    private class FileAdapter extends BaseAdapter {

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
                view = LayoutInflater.from(FileStorageActivity.this).inflate(R.layout.item_storage, null, true);
                viewHolder = new ViewHolder();
                viewHolder.firstTv = (TextView) view.findViewById(R.id.item_storage_first_tv);
                viewHolder.secondTv = (TextView) view.findViewById(R.id.item_storage_second_tv);
                viewHolder.firstTv.setTextSize(TypedValue.COMPLEX_UNIT_SP, 14);
                viewHolder.secondTv.setTextSize(TypedValue.COMPLEX_UNIT_SP, 14);
                view.setTag(viewHolder);
            } else {
                viewHolder = (ViewHolder) view.getTag();
            }
            BaseFile file = mData.get(i);
            String path = file.getAbsolutePath();
            String content = file2String(file);
            viewHolder.firstTv.setText(getString(R.string.path_is) + path);
            viewHolder.secondTv.setText(getString(R.string.content_is) + content);
            return view;
        }
    }
}
