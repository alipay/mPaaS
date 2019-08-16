package com.mpaas.demo.nebula;

import com.alipay.mobile.nebula.provider.H5UaProvider;

/**
 * Created by omg on 2018/7/23.
 */

public class H5UaProviderImpl implements H5UaProvider {
    @Override
    public String getUa(String defaultUaStr) {
        return defaultUaStr + " AlipayClient/mPaaS"; //请不要修改defaultUaStr，或者返回一个不包含defaultUaStr的结果
    }
}
