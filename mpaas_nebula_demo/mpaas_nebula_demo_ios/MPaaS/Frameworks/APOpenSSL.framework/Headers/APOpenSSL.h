//
//  APOpenSSL.h
//  APOpenSSL
//
//  Created by wenbi on 14-12-1.
//  Copyright (c) 2014年 Alipay. All rights reserved.
//

#ifdef __cplusplus
extern "C" {
#endif

    /**
     * 加载openssl配置，添加所有算法
     *
     * @param 无
     *
     * @return 无
     */
void APOpenSSL_add_all_algorithms();

#ifdef __cplusplus
}
#endif
