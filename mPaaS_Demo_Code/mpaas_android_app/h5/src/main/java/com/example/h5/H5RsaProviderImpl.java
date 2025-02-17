package com.example.h5;

import com.alipay.mobile.nebula.provider.H5PublicRsaProvider;

/**
 * Created by omg on 2018/7/23.
 * 配置离线包验签公钥
 * 生成私钥:
 * openssl genrsa -out private_key.pem 2048
 * 生成公钥：
 * openssl rsa -in private_key.pem -outform PEM -pubout -out public.pem
 * 此处拷贝public.pem内不含头尾的内容，且需要去掉\n
 */

public class H5RsaProviderImpl implements H5PublicRsaProvider {
    @Override
    public String getPublicRsa() {
        return "MIIBIjANBgkqhkiG9w0BAQEFAAOCAQ8AMIIBCgKCAQEArrbiSmhH+oru/dzwyftJ" +
                "OXvXkSSYQ/f2K7kOMP6HN9cxvKQu/50LzjrpfusDQFZr2zMWayUPqSMftrpwfKGg" +
                "mxD6G8ldDzufjfAR7jI+AVlG3O6L9/pWjGYSjF7/IrPNzfSjG8zRRxoCeOOj0Y3n" +
                "tCEZ0h/+ndYN/BY3Ej4VySnTOHRJJyVgGMblN7Q4mBztN1RnoDldkx7nETrBX23S" +
                "I0Kp2GpggvmYcPx1Un2nF9UNvZDHIG/TnOg1GL4KP006kShqYD+2NPOJXPPhaDbf" +
                "F9grlxl8xRBGQ5/SQcs1r5gtpJp8NpiWxPcMjd8uA+SOsa0DmLMzuo4oMH3MOktI" +
                "tQIDAQAB";
    }
}
