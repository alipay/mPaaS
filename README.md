# mPaaS H5 Container 10.1.60
[![en](https://img.shields.io/badge/Language-English-red)](https://github.com/alipay/mPaaS/blob//master/README.md)
[![zh-Hans](https://img.shields.io/badge/Language-%E4%B8%AD%E6%96%87-blue)](https://github.com/alipay/mPaaS/blob/master/README.zh-Hans.md)

### What is the mPaaS offline package?
The hybrid development model is not a new topic. It can not only quickly release new services, but also provide great flexibility for business updates and iterations without considering the release time of the App. Compared with Web development, the hybrid development model provides a rich set of device APIs, making business forms more diverse and rich.  

The mPaaS offline package is derived from the native solution of Alipay and has undergone rigorous business tests. It allows you to use the same set of framework layer codes as Alipay directly, with a unified container and kernel, and a lower Crash rate and ANR rate compared to the system kernel. It has strong adaptability and good and flexible expansion capabilities, and can customize JSAPI based on specific business needs.

### What problem does it solve?


* **Reduce the white screen**
* **Solve the cross-platform compatibility and adaptation of Hybrid App**
* **Improve Hybrid App Performance**
* **Optimize package size for native development**

### The principles

* **Reduce the white screen**

In order to optimize the HTML5 container user experience and reduce the white screen time, we introduced the offline package technology in the H5 container. The offline package can be simply understood as a zip compressed package, which contains the HTML, CSS, JS, pictures and other resources required by the front-end page. After being built into the client side, the H5 container will directly obtain resources from the offline package when opening the offline package page. The access time of this process is at the millisecond level, which can eliminate the white screen phenomenon when opening the page.

* **Solve the cross-platform compatibility and adaptation of Hybrid App**

The unified UC kernel provided by mPaaS can quickly solve the compatibility and adaptation problem on Android devices: "a set of code has different presentation forms due to different system kernels."

* **Improve Hybrid App Performance**

To improve the stability of the HTML5 container, we used UC WebView on the Android system. Its crash rate and ANR rate are much lower than those of the system browser, and it completely avoids the Android system Webview fragmentation problem.

* **Optimize package size for native development**

For offline packages, we have classified them into "business resource packages" and "public resource packages". The public resource package contains framework JS, CSS, common images, etc., and only one copy of such resources is saved in the entire App; the business resource package only saves the page static resources required by the business, and each business is independently decoupled from each other. This ensures that the page resources of a business can come from both the business resource package and the public resource package, fully optimizing the App size.
Based on the above solution, Native services can be converted into HTML5, thereby further optimizing the App size and enabling dynamic service delivery and on-demand downloading.

### What you need to prepare

- A native Android project, add signature and compile APK installation package
- Create an application in the mPaaS console and upload the signed installation package to obtain the *.config configuration file
- Configure the development environment (this tutorial uses the Android development environment under macOS as an example). For more information, see [Prepare for Configuration]([Document Center - Ant Financial Technology](https://tech.antfin.com/docs/2/99044))
- Internet connection and web browser (Chrome is recommended)
- An Android phone and its data cable (the phone system version must be Android 4.3 or later, you can also choose to use an emulator for debugging)

### How can you access it?

#### [Step 0: Apply for a trial]

  [Apply for a trial of mPaaS offline package](https://www.alibabacloud.com/en?_p_lc=1)

#### [Android]

* Step 1: Connect to mPaaS Inside

  [Connect to mPaaS Inside](https://gw.alipayobjects.com/mdn/site_comm/afts/file/A*xziLQJ_oNFsAAAAAAAAAAABkARQnAQ)

* Step 2: Connect to the mPaaS Nebula container

  [Connect to the mPaaS Nebula container](https://gw.alipayobjects.com/mdn/site_comm/afts/file/A*kRtRRam3PxAAAAAAAAAAAABkARQnAQ)

* Step 3: Packaging, pre-installing to the client side, compiling and running

  [Preset offline package, compile and run](https://gw.alipayobjects.com/mdn/site_comm/afts/file/A*e5pMRpUNrjcAAAAAAAAAAABkARQnAQ)

#### [iOS]

* Step 1: Create a project and connect to the mPaaS Nebula container component

  [Connect to mPaaS Nebula container](https://gw.alipayobjects.com/mdn/site_comm/afts/file/A*IwoXSqm6sBgAAAAAAAAAAABkARQnAQ)

* Step 2: Use mPaaS Nebula container

  [Use mPaaS Nebula container](https://gw.alipayobjects.com/mdn/site_comm/afts/file/A*y02KQ6c9gFkAAAAAAAAAAABkARQnAQ)

* Step 3: Use the mPaaS offline package

  [Preset offline package, compile and run](https://gw.alipayobjects.com/mdn/site_comm/afts/file/A*U_wHQ51Gb6IAAAAAAAAAAABkARQnAQ)


#### [Step 4: Apply for UC kernel]

  [Apply for UC kernel key, which is expected to take effect within half a working day](https://survey.alipay.com/apps/zhiliao/Oi2hbo_-v)

For access documents, please refer to:[mPaaS Container Documentation](https://tech.antfin.com/docs/2/130789)

### Who have we served?

![Container Capabilities - Case Wall](https://img.alicdn.com/tfs/TB1aJf4vUz1gK0jSZLeXXb9kVXa-2560-641.png)

### Welcome to exchange + feedback + criticism

* Issue feedback (if you encounter any bugs or feature requests, please let us know as soon as possible)  
  [Issue address](https://github.com/alipay/mpaas-demo/issues)
* Join the technical exchange group and communicate at any time if you have any questions

![mPaaS Function Trial - Draw Attention](https://img.alicdn.com/tfs/TB1Rbf9vHY1gK0jSZTEXXXDQVXa-2560-1000.jpg)

### Open Source License

This project is under the Apache 2.0 License. See the [LICENSE](https://github.com/alipay/mpaas-demo/blob/master/LICENSE) file for the full license text.

```
Copyright (C) 2015-present, Ant Financial Services Group

Licensed under the Apache License, Version 2.0 (the "License");
you may not use this file except in compliance with the License.
You may obtain a copy of the License at

 	http://www.apache.org/licenses/LICENSE-2.0

Unless required by applicable law or agreed to in writing, software
distributed under the License is distributed on an "AS IS" BASIS,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
See the License for the specific language governing permissions and
limitations under the License.
```

### Disclaimer

[Disclaimer](https://github.com/alipay/mpaas-demo/blob/master/Disclaimer.md)
```

### Disclaimer

[Disclaimer](https://github.com/alipay/mpaas-demo/blob/master/Disclaimer.md)
