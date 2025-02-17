package com.mpaas.antui.viewdemo;

import android.app.Activity;
import android.content.Context;
import android.graphics.Color;
import android.os.Bundle;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.ArrayAdapter;
import android.widget.TextView;

import com.alipay.mobile.antui.utils.PublicResources;
import com.mpaas.antui.R;
import com.alipay.mobile.antui.basic.AUPinnedSectionListView;
import com.alipay.mobile.antui.basic.AUPullLoadingView;
import com.alipay.mobile.antui.basic.AUPullRefreshView;

import java.text.SimpleDateFormat;
import java.util.Date;
import java.util.Locale;

/**
 * Created by minghui on 2017/9/21.
 */

public class PinnedSectionActivity extends Activity{

    private AUPullRefreshView pullRefreshView;
    AUPullLoadingView mAUPullLoadingView;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.pinned_layout);
        pullRefreshView = (AUPullRefreshView) findViewById(R.id.pull_refresh);
        final AUPinnedSectionListView pinnedSectionListView = (AUPinnedSectionListView) findViewById(R.id.list_view);

        TextView tv = new TextView(this);
        tv.setText("nihao");
        pinnedSectionListView.addHeaderView(tv);
        pullRefreshView.setRefreshListener(new AUPullRefreshView.RefreshListener() {

            @Override
            public void onRefresh() {

                pullRefreshView.autoRefresh();

                pullRefreshView.postDelayed(new Runnable() {

                    @Override
                    public void run() {
                        pullRefreshView.refreshFinished();

                    }
                }, 1000);

            }

            @Override
            public AUPullLoadingView getOverView() {

                mAUPullLoadingView = (AUPullLoadingView) LayoutInflater.from(getBaseContext())
                        .inflate(PublicResources.Layout_PullRefresh_Overview, null);
                Date date = new Date(1466577757265L);
                SimpleDateFormat formatter = new SimpleDateFormat("yyyy-MM-dd HH:mm:ss");
                String dateString = formatter.format(date);
                mAUPullLoadingView.setIndicatorText(dateString);
                mAUPullLoadingView.setLoadingText(dateString);
                return mAUPullLoadingView;
            }

            @Override
            public boolean canRefresh() {
                return true;
            }
        });


        final SimpleAdapter adapter  = new SimpleAdapter(this, android.R.layout.simple_list_item_1, android.R.id.text1);

        pinnedSectionListView.setAdapter(adapter);

        pinnedSectionListView.onFinishLoading(true);
        pinnedSectionListView.setOnLoadMoreListener(new AUPinnedSectionListView.OnLoadMoreListener() {
            @Override
            public void onLoadMoreItems() {

                pinnedSectionListView.postDelayed(new Runnable() {
                    @Override
                    public void run() {
                        pinnedSectionListView.onFinishLoading(false);
                    }
                }, 3000);

            }
        });
    }


    static class SimpleAdapter extends ArrayAdapter<Item> implements AUPinnedSectionListView.PinnedSectionListAdapter {


        public SimpleAdapter(Context context, int resource, int textViewResourceId) {
            super(context, resource, textViewResourceId);
            generateDataset('A', 'Z', false);
        }

        public void generateDataset(char from, char to, boolean clear) {

            if (clear) clear();

            final int sectionsNumber = to - from + 1;
            prepareSections(sectionsNumber);

            int sectionPosition = 0, listPosition = 0;
            for (char i=0; i<sectionsNumber; i++) {
                Item section = new Item(Item.SECTION, String.valueOf((char)('A' + i)));
                section.sectionPosition = sectionPosition;
                section.listPosition = listPosition++;
                onSectionAdded(section, sectionPosition);
                add(section);

                final int itemsNumber = (int) Math.abs((Math.cos(2f*Math.PI/3f * sectionsNumber / (i+1f)) * 25f));
                for (int j=0;j<itemsNumber;j++) {
                    Item item = new Item(Item.ITEM, section.text.toUpperCase(Locale.ENGLISH) + " - " + j);
                    item.sectionPosition = sectionPosition;
                    item.listPosition = listPosition++;
                    add(item);
                }

                sectionPosition++;
            }
        }

        protected void prepareSections(int sectionsNumber) { }
        protected void onSectionAdded(Item section, int sectionPosition) { }

        @Override public View getView(int position, View convertView, ViewGroup parent) {
            TextView view = (TextView) super.getView(position, convertView, parent);
            view.setTextColor(Color.DKGRAY);
            view.setTag("" + position);
            Item item = getItem(position);
            if (item.type == Item.SECTION) {
                //view.setOnClickListener(PinnedSectionListActivity.this);
                view.setBackgroundColor(Color.parseColor("#ff0000"));
            }
            return view;
        }

        @Override public int getViewTypeCount() {
            return 2;
        }

        @Override public int getItemViewType(int position) {
            return getItem(position).type;
        }

        @Override
        public boolean isItemViewTypePinned(int viewType) {
            return viewType == Item.SECTION;
        }

        @Override
        public View getPinnedView(int position, View convertView, ViewGroup parent) {
            return getView(position, convertView, parent);
        }
    }

    static class Item {

        public static final int ITEM = 0;
        public static final int SECTION = 1;

        public final int type;
        public final String text;

        public int sectionPosition;
        public int listPosition;

        public Item(int type, String text) {
            this.type = type;
            this.text = text;
        }

        @Override public String toString() {
            return text;
        }

    }
}