package com.mpaas.demo.nebula;

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
        return "MIIBIjANBgkqhkiG9w0BAQEFAAOCAQ8AMIIBCgKCAQEAwn7LQcdQYrw44Sr8hAvM" +
                "3og1mxB3YkfGrBXuWHRWGEbuL2yIOxVaJZpcJsC48leUHxlqrHk1FnaLuWbeCSiS" +
                "EuXLqzOT/w8Vtfl9GPyzP/h0VWRITlV5tMX67U9urxVK6dq1GJzGwHnprFFjebey" +
                "IukQUAOQMPTWLFbdPPIvaCtU1LCYqHbj23ANu8h+xWV9ts83FWhJ1WKNFYrjEmGU" +
                "x9M1YDsbJUzcpC7RByWVOg/ZHAYPHBrVC07B+VG4219q8AI/ijJ9AhK5T8yxdz4k" +
                "pcL9BFzk8BSs4eSCZ10e6Y3gVybO7iNac/1a2EGfFNz9EUJ8/kxccZfpO01DPwXu" +
                "NQIDAQAB";
    }
}
