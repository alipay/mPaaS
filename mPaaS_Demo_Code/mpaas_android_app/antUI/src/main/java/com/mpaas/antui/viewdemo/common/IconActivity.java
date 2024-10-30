package com.mpaas.antui.viewdemo.common;

import android.app.Activity;
import android.os.Bundle;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.BaseAdapter;

import com.alipay.mobile.antui.utils.PublicResources;
import com.mpaas.antui.R;
import com.alipay.mobile.antui.basic.AUGridView;
import com.alipay.mobile.antui.basic.AUTextView;
import com.alipay.mobile.antui.iconfont.AUIconView;

import java.util.ArrayList;
import java.util.List;

/**
 * Created by minghui on 2017/8/22.
 */

public class IconActivity extends Activity{

    private AUGridView gridView;
    private View view;
    public List<IconModel> datas =
            new ArrayList<IconModel>();


    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        View v = View.inflate(this, R.layout.icon_activity, null);
        setContentView(v);

        view = findViewById(R.id.header);
        view.setFocusable(true);
        view.setFocusableInTouchMode(true);
        view.requestFocus();

        gridView = (AUGridView) findViewById(R.id.gridView);

        datas.add(new IconModel(getString(PublicResources.String_iconfont_more),"iconfont_more"));
        datas.add(new IconModel(getString(PublicResources.String_iconfont_cancel),"iconfont_cancel"));
        datas.add(new IconModel(getString(PublicResources.String_iconfont_cancel_surface_ios),"iconfont_cancel_surface_ios"));
        datas.add(new IconModel(getString(PublicResources.String_iconfont_voice),"iconfont_voice"));
        datas.add(new IconModel(getString(PublicResources.String_iconfont_collect_money),"iconfont_collect_money"));
        datas.add(new IconModel(getString(PublicResources.String_iconfont_back),"iconfont_back"));
        datas.add(new IconModel(getString(PublicResources.String_iconfont_user_setting),"iconfont_user_setting"));
        datas.add(new IconModel(getString(PublicResources.String_iconfont_user),"iconfont_user"));
        datas.add(new IconModel(getString(PublicResources.String_iconfont_add),"iconfont_add"));
        datas.add(new IconModel(getString(PublicResources.String_iconfont_praise),"iconfont_praise"));
        datas.add(new IconModel(getString(PublicResources.String_iconfont_map),"iconfont_map"));
        datas.add(new IconModel(getString(PublicResources.String_iconfont_checked),"iconfont_checked"));
        datas.add(new IconModel(getString(PublicResources.String_iconfont_notice),"iconfont_notice"));
        datas.add(new IconModel(getString(PublicResources.String_iconfont_cancel_line_ios),"iconfont_cancel_line_ios"));
        datas.add(new IconModel(getString(PublicResources.String_iconfont_add_user),"iconfont_add_user"));
        datas.add(new IconModel(getString(PublicResources.String_iconfont_comment),"iconfont_comment"));
        datas.add(new IconModel(getString(PublicResources.String_iconfont_selected),"iconfont_selected"));
        datas.add(new IconModel(getString(PublicResources.String_iconfont_bill),"iconfont_bill"));
        datas.add(new IconModel(getString(PublicResources.String_iconfont_pulldown),"iconfont_pulldown"));
        datas.add(new IconModel(getString(PublicResources.String_iconfont_scan),"iconfont_scan"));
        datas.add(new IconModel(getString(PublicResources.String_iconfont_list),"iconfont_list"));
        datas.add(new IconModel(getString(PublicResources.String_iconfont_delete),"iconfont_delete"));
        datas.add(new IconModel(getString(PublicResources.String_iconfont_share),"iconfont_share"));
        datas.add(new IconModel(getString(PublicResources.String_iconfont_search),"iconfont_search"));
        datas.add(new IconModel(getString(PublicResources.String_iconfont_complain),"iconfont_complain"));
        datas.add(new IconModel(getString(PublicResources.String_iconfont_qrcode),"iconfont_qrcode"));
        datas.add(new IconModel(getString(PublicResources.String_iconfont_unchecked),"iconfont_unchecked"));
        datas.add(new IconModel(getString(PublicResources.String_iconfont_right_arrow),"iconfont_right_arrow"));
        datas.add(new IconModel(getString(PublicResources.String_iconfont_help),"iconfont_help"));
        datas.add(new IconModel(getString(PublicResources.String_iconfont_group_chat),"iconfont_group_chat"));
        datas.add(new IconModel(getString(PublicResources.String_iconfont_contacts),"iconfont_contacts"));
        datas.add(new IconModel(getString(PublicResources.String_iconfont_setting),"iconfont_setting"));
        datas.add(new IconModel(getString(PublicResources.String_iconfont_phone_book),"iconfont_phone_book"));
        datas.add(new IconModel(getString(PublicResources.String_iconfont_phone_contact),"iconfont_phone_contact"));
        datas.add(new IconModel(getString(PublicResources.String_iconfont_minus_square_o),"iconfont_minus_square_o"));
        datas.add(new IconModel(getString(PublicResources.String_iconfont_heart),"iconfont_heart"));
        datas.add(new IconModel(getString(PublicResources.String_iconfont_system_defeated),"iconfont_system_defeated"));
        datas.add(new IconModel(getString(PublicResources.String_iconfont_system_serch),"iconfont_system_serch"));
        datas.add(new IconModel(getString(PublicResources.String_iconfont_system_deleteb),"iconfont_system_deleteb"));
        datas.add(new IconModel(getString(PublicResources.String_iconfont_system_addressbook),"iconfont_system_addressbook"));
        datas.add(new IconModel(getString(PublicResources.String_iconfont_system_card),"iconfont_system_card"));
        datas.add(new IconModel(getString(PublicResources.String_iconfont_system_charge),"iconfont_system_charge"));
        datas.add(new IconModel(getString(PublicResources.String_iconfont_system_complain),"iconfont_system_complain"));
        datas.add(new IconModel(getString(PublicResources.String_iconfont_system_complaint),"iconfont_system_complaint"));
        datas.add(new IconModel(getString(PublicResources.String_iconfont_system_conceal),"iconfont_system_conceal"));
        datas.add(new IconModel(getString(PublicResources.String_iconfont_system_copy),"iconfont_system_copy"));
        datas.add(new IconModel(getString(PublicResources.String_iconfont_system_dislike3),"iconfont_system_dislike3"));
        datas.add(new IconModel(getString(PublicResources.String_iconfont_system_expressfee),"iconfont_system_expressfee"));
        datas.add(new IconModel(getString(PublicResources.String_iconfont_system_dislike),"iconfont_system_dislike"));
        datas.add(new IconModel(getString(PublicResources.String_iconfont_system_friends),"iconfont_system_friends"));
        datas.add(new IconModel(getString(PublicResources.String_iconfont_system_jinzhi),"iconfont_system_jinzhi"));
        datas.add(new IconModel(getString(PublicResources.String_iconfont_system_jujue),"iconfont_system_jujue"));
        datas.add(new IconModel(getString(PublicResources.String_iconfont_system_internet),"iconfont_system_internet"));
        datas.add(new IconModel(getString(PublicResources.String_iconfont_system_loadingc),"iconfont_system_loadingc"));
        datas.add(new IconModel(getString(PublicResources.String_iconfont_system_lock),"iconfont_system_lock"));
        datas.add(new IconModel(getString(PublicResources.String_iconfont_system_loadingb),"iconfont_system_loadingb"));
        datas.add(new IconModel(getString(PublicResources.String_iconfont_system_payment),"iconfont_system_payment"));
        datas.add(new IconModel(getString(PublicResources.String_iconfont_system_phonebook),"iconfont_system_phonebook"));
        datas.add(new IconModel(getString(PublicResources.String_iconfont_system_remind),"iconfont_system_remind"));
        datas.add(new IconModel(getString(PublicResources.String_iconfont_system_select),"iconfont_system_select"));
        datas.add(new IconModel(getString(PublicResources.String_iconfont_system_peopleno),"iconfont_system_peopleno"));
        datas.add(new IconModel(getString(PublicResources.String_iconfont_system_shareb),"iconfont_system_shareb"));
        datas.add(new IconModel(getString(PublicResources.String_iconfont_system_trackparcel),"iconfont_system_trackparcel"));
        datas.add(new IconModel(getString(PublicResources.String_iconfont_systme_expressdeliv),"iconfont_systme_expressdeliv"));
        datas.add(new IconModel(getString(PublicResources.String_iconfont_system_warning3),"iconfont_system_warning3"));
        datas.add(new IconModel(getString(PublicResources.String_iconfont_sytem_collect),"iconfont_sytem_collect"));
        datas.add(new IconModel(getString(PublicResources.String_iconfont_system_wait),"iconfont_system_wait"));
        datas.add(new IconModel(getString(PublicResources.String_iconfont_follow),"iconfont_follow"));
        datas.add(new IconModel(getString(PublicResources.String_iconfont_plus_square_o),"iconfont_plus_square_o"));
        datas.add(new IconModel(getString(PublicResources.String_iconfont_system_koubeimian),"iconfont_system_koubeimian"));
        datas.add(new IconModel(getString(PublicResources.String_iconfont_system_question),"iconfont_system_question"));
        datas.add(new IconModel(getString(PublicResources.String_iconfont_closexian),"iconfont_closexian"));
        datas.add(new IconModel(getString(PublicResources.String_iconfont_exclamation_circle_o),"iconfont_exclamation_circle_o"));
        datas.add(new IconModel(getString(PublicResources.String_iconfont_cross_circle_o),"iconfont_cross_circle_o"));
        datas.add(new IconModel(getString(PublicResources.String_iconfont_like),"iconfont_like"));
        datas.add(new IconModel(getString(PublicResources.String_iconfont_system_closea),"iconfont_system_closea"));
        datas.add(new IconModel(getString(PublicResources.String_iconfont_loeft),"iconfont_loeft"));
        datas.add(new IconModel(getString(PublicResources.String_iconfont_phone),"iconfont_phone"));
        datas.add(new IconModel(getString(PublicResources.String_iconfont_system_map2),"iconfont_system_map2"));
        datas.add(new IconModel(getString(PublicResources.String_iconfont_system_tips),"iconfont_system_tips"));
        datas.add(new IconModel(getString(PublicResources.String_iconfont_system_koubeixian),"iconfont_system_koubeixian"));
        datas.add(new IconModel(getString(PublicResources.String_iconfont_system_tipsxian),"iconfont_system_tipsxian"));
        datas.add(new IconModel(getString(PublicResources.String_iconfont_sysytem_addperson),"iconfont_sysytem_addperson"));
        datas.add(new IconModel(getString(PublicResources.String_iconfont_sysytem_tixing),"iconfont_sysytem_tixing"));
        datas.add(new IconModel(getString(PublicResources.String_iconfont_system_friendsz),"iconfont_system_friendsz"));
        datas.add(new IconModel(getString(PublicResources.String_iconfont_system_friendsb),"iconfont_system_friendsb"));
        datas.add(new IconModel(getString(PublicResources.String_iconfont_system_reload),"iconfont_system_reload"));
        datas.add(new IconModel(getString(PublicResources.String_iconfont_system_noeye),"iconfont_system_noeye"));
        datas.add(new IconModel(getString(PublicResources.String_iconfont_knowledge_sharepic),"iconfont_knowledge_sharepic"));
        datas.add(new IconModel(getString(PublicResources.String_iconfont_shh_cyfw),"iconfont_shh_cyfw"));
        datas.add(new IconModel(getString(PublicResources.String_iconfont_news_write),"iconfont_news_write"));
        datas.add(new IconModel(getString(PublicResources.String_iconfont_news_comment),"iconfont_news_comment"));
        datas.add(new IconModel(getString(PublicResources.String_iconfont_news_favorites),"iconfont_news_favorites"));
        datas.add(new IconModel(getString(PublicResources.String_iconfont_system_nosound),"iconfont_system_nosound"));
        datas.add(new IconModel(getString(PublicResources.String_iconfont_system_ant),"iconfont_system_ant"));
        datas.add(new IconModel(getString(PublicResources.String_iconfont_system_anttalk),"iconfont_system_anttalk"));
        datas.add(new IconModel(getString(PublicResources.String_iconfont_fin_edit),"iconfont_fin_edit"));
        datas.add(new IconModel(getString(PublicResources.String_iconfont_systen_triangle),"iconfont_systen_triangle"));
        datas.add(new IconModel(getString(PublicResources.String_iconfont_systen_key),"iconfont_systen_key"));
        datas.add(new IconModel(getString(PublicResources.String_iconfont_system_cancel_bold),"iconfont_system_cancel_bold"));
        datas.add(new IconModel(getString(PublicResources.String_iconfont_system_information),"iconfont_system_information"));
        datas.add(new IconModel(getString(PublicResources.String_iconfont_hangye_gift),"iconfont_hangye_gift"));
        datas.add(new IconModel(getString(PublicResources.String_iconfont_hangye_note),"iconfont_hangye_note"));
        datas.add(new IconModel(getString(PublicResources.String_iconfont_hangye_bus),"iconfont_hangye_bus"));
        datas.add(new IconModel(getString(PublicResources.String_iconfont_shenghuohao_v),"iconfont_shenghuohao_v"));
        datas.add(new IconModel(getString(PublicResources.String_iconfont_system_dowload),"iconfont_system_dowload"));
        datas.add(new IconModel(getString(PublicResources.String_iconfont_hangye_chengchedou),"iconfont_hangye_chengchedou"));
        datas.add(new IconModel(getString(PublicResources.String_iconfont_alipaylogo_h),"iconfont_alipaylogo_h"));
        datas.add(new IconModel(getString(PublicResources.String_iconfont_alipaylogo_z),"iconfont_alipaylogo_z"));
        datas.add(new IconModel(getString(PublicResources.String_iconfont_system_guanzhu),"iconfont_system_guanzhu"));
        datas.add(new IconModel(getString(PublicResources.String_iconfont_slice),"iconfont_slice"));
        datas.add(new IconModel(getString(PublicResources.String_iconfont_alipaylogo_r),"iconfont_alipaylogo_r"));
        datas.add(new IconModel(getString(PublicResources.String_iconfont_system_suoxiao),"iconfont_system_suoxiao"));
        datas.add(new IconModel(getString(PublicResources.String_iconfont_system_fangda),"iconfont_system_fangda"));
        datas.add(new IconModel(getString(PublicResources.String_iconfont_hongbao),"iconfont_hongbao"));
        datas.add(new IconModel(getString(PublicResources.String_iconfont_slice1),"iconfont_slice1"));
        datas.add(new IconModel(getString(PublicResources.String_iconfont_huabei),"iconfont_huabei"));
        datas.add(new IconModel(getString(PublicResources.String_iconfont_bingtu),"iconfont_bingtu"));


        gridView.setNumColumns(2);

        datas.add(new IconModel("iconfont_more"));
        datas.add(new IconModel("iconfont_more"));
        datas.add(new IconModel("iconfont_more"));
        datas.add(new IconModel("iconfont_more"));
        datas.add(new IconModel("iconfont_more"));
        datas.add(new IconModel("iconfont_more"));
        datas.add(new IconModel("iconfont_more"));

        gridView.setAdapter(new BaseAdapter() {
            @Override
            public int getCount() {
                return datas.size();
            }

            @Override
            public Object getItem(int position) {
                return datas.get(position);
            }

            @Override
            public long getItemId(int position) {
                return position;
            }

            @Override
            public View getView(int position, View convertView, ViewGroup parent) {
                IconModel model = (IconModel) getItem(position);
                if (convertView == null) {
                    convertView = LayoutInflater.from(IconActivity.this).inflate(R.layout.view_icon_item, null);
                }
                AUIconView iconView = (AUIconView) convertView.findViewById(R.id.icon);
                AUTextView descView = (AUTextView) convertView.findViewById(R.id.desc);
                iconView.setIconByName(model.desc);
                descView.setText(model.desc);
                return convertView;
            }
        });

    }

    class IconModel {
        public String icon;
        public String desc;

        public IconModel(String desc) {
            this.desc = desc;
        }

        public IconModel(String icon, String desc) {
            this.icon = icon;
            this.desc = desc;
        }
    }
}
