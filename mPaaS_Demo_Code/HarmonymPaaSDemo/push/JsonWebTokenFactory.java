package com;

import java.nio.charset.Charset;
import java.security.KeyFactory;
import java.security.NoSuchAlgorithmException;
import java.security.PrivateKey;
import java.security.interfaces.RSAPrivateKey;
import java.security.spec.InvalidKeySpecException;
import java.security.spec.PKCS8EncodedKeySpec;
import org.apache.commons.codec.binary.Base64;
import com.auth0.jwt.JWT;
import com.auth0.jwt.JWTCreator.Builder;
import com.auth0.jwt.algorithms.Algorithm;


//网址：https://developer.huawei.com/consumer/cn/doc/harmonyos-guides-V5/push-jwt-token-0000001804134544-V5
public class JsonWebTokenFactory {
  private static Charset DEFAULT_CHARSET = Charset.forName("UTF-8");
  // 请使用服务帐号密钥文件中的private_key替换
  // 请在代码中加密私钥，仅获取 '-----BEGIN PRIVATE KEY-----\n' 和 '\n-----END PRIVATE KEY-----\n'之间的字符
  private static final String PRIVATE_KEY = "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";
  // 请使用服务帐号密钥文件中的sub_account替换
  private static final String ISS  = "110889197";
  // 请使用服务帐号密钥文件中的key_id替换
  private static final String KID  = "6bbc56aafdf0467e8d8aaa855950271d";

  private static final String AUD  = "https://oauth-login.cloud.huawei.com/oauth2/v3/token";

  public String createJwt() throws NoSuchAlgorithmException, InvalidKeySpecException {
    RSAPrivateKey prk = (RSAPrivateKey) getPrivateKey(PRIVATE_KEY);
    Algorithm algorithm = Algorithm.RSA256(null,prk);
    long iat = System.currentTimeMillis() / 1000;
    long exp = iat + 3600;
    Builder builder =
      JWT.create()
         .withIssuer(ISS)
         .withKeyId(KID)
         .withAudience(AUD)
         .withClaim("iat", iat)
         .withClaim("exp", exp);
    String jwt = builder.sign(algorithm);
    return jwt;
  }
  private PrivateKey getPrivateKey(String key) throws NoSuchAlgorithmException, InvalidKeySpecException {
    PKCS8EncodedKeySpec keySpec = new PKCS8EncodedKeySpec(decodeBase64(key));
    KeyFactory keyFactory = KeyFactory.getInstance("RSA");
    PrivateKey privateKey = keyFactory.generatePrivate(keySpec);
    return privateKey;
  }
  private byte[] decodeBase64(String key) {
    return Base64.decodeBase64(key.getBytes(DEFAULT_CHARSET));
  }
  public static void main(String args[]) throws InvalidKeySpecException, NoSuchAlgorithmException {
    JsonWebTokenFactory jsonWebTokenFactory = new JsonWebTokenFactory();
    System.out.println(jsonWebTokenFactory.createJwt());
  }
}

<dependency>
<groupId>com.auth0</groupId>
<artifactId>java-jwt</artifactId>
<version>3.8.1</version>
</dependency>
<dependency>
<groupId>commons-codec</groupId>
<artifactId>commons-codec</artifactId>
<version>1.16.0</version>
</dependency>
