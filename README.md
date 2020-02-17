# mPaaS H5 容器 10.1.60
![30 分钟接入](https://img.alicdn.com/tfs/TB1v2Y8vKL2gK0jSZFmXXc7iXXa-2560-1000.png)

### mPaaS 离线包是什么？
Hybrid 开发模式已不是什么新鲜的话题，不仅可以快速发布新业务，同时无需考虑 App 发版时间，为业务更新迭代提供了极强的灵活性。相比于 Web 开发，Hybrid 开发模式提供了丰富的设备 API，让业务形态可以更加多元和丰富。  

mPaaS 离线包源自于支付宝原生方案，经历了严苛的业务考验，让你直接和支付宝使用同一套框架层代码，拥有统一容器及内核，相对系统内核获取更低 Crash 率和 ANR 率，适配性强，并具备良好的、弹性的扩展能力，结合具体业务需求定制 JSAPI。

### 它解决什么问题？

* **减少白屏**
* **解决 Hybrid App 跨平台兼容与适配**
* **提升 Hybrid App 性能**
* **原生开发下的包大小优化**

### 实现原理

* **减少白屏**

为了优化 HTML5 容器用户体验，减少白屏时间，我们在 H5 容器中引入了离线包技术。离线包可以简单理解为一个 zip 压缩包，其中包含前端页面所需的 HTML、CSS、JS、图片等资源。内置到客户端后，H5 容器打开离线包页面时会直接从离线包中获取资源，这个是毫秒的访问时间，消除了打开页面白屏现象。

* **解决 Hybrid App 跨平台兼容与适配**

通过 mPaaS 提供的统一 UC 内核，从而快速解决在 Android 设备上“一套代码因系统内核不同，导致展现形式不同”的兼容适配问题。

* **提升 Hybrid App 性能**

为了提升 HTML5 容器稳定性，我们在安卓系统上使用了 UC WebView，其崩溃率和 ANR 率远低于系统浏览器，而且彻底规避了安卓系统 Webview 碎片化问题。

* **原生开发下的包大小优化**

针对离线包，我们做了“业务资源包”和“公共资源包”分类。公共资源包中包含框架 JS、CSS、常见图片等，同时此类资源在整个 App 内仅保存一份；业务资源包仅保存业务所需的页面静态资源，同时各业务间相互独立解耦。从而保证一个业务的页面资源能够同时来自业务资源包和公共资源包，充分优化 App 大小。
基于以上方案，Native 业务可将转化成 HTML5，从而进一步优化 App 大小，实现业务动态下发，按需下载。

### 你需要准备的

- 一个原生安卓工程，添加签名切编译出 APK 安装包
- 在 mPaaS 控制台创建了应用并上传加签后的安装包获得了 *.config 配置文件
- 配置开发环境（在本教程中以 macOS 下的安卓开发环境为例进行说明）。更多信息，请参考[准备配置]([文档中心 - 蚂蚁金服金融科技](https://tech.antfin.com/docs/2/99044))
- 网络连接和网络浏览器（推荐使用 Chrome 浏览器）
- 一部安卓手机及配套的数据线（手机系统版本为安卓 4.3 或更新，您也可以选择使用模拟器进行调试）

### 你可以如何接入它？

#### [步骤零：申请试用]

  [申请试用 mPaaS 离线包](https://www.aliyun.com/product/mpaas?spm=5176.224200.h2v3icoap.455.5d716ed6zl3rpw&aly_as=J7wB1L5q)

#### [Android 端]

* 步骤一：接入 mPaaS Inside

  [接入 mPaaS Inside](https://gw.alipayobjects.com/mdn/site_comm/afts/file/A*xziLQJ_oNFsAAAAAAAAAAABkARQnAQ)

* 步骤二：接入 mPaaS Nebula 容器

  [接入 mPaaS Nebula 容器](https://gw.alipayobjects.com/mdn/site_comm/afts/file/A*kRtRRam3PxAAAAAAAAAAAABkARQnAQ)

* 步骤三：打包，预置到客户端，编译运行

  [预置离线包，编译运行](https://gw.alipayobjects.com/mdn/site_comm/afts/file/A*e5pMRpUNrjcAAAAAAAAAAABkARQnAQ)

#### [iOS 端]

* 步骤一：创建工程并接入 mPaaS Nebula 容器组件

  [接入 mPaaS Nebula 容器](https://gw.alipayobjects.com/mdn/site_comm/afts/file/A*IwoXSqm6sBgAAAAAAAAAAABkARQnAQ)

* 步骤二：使用 mPaaS Nebula 容器

  [使用 mPaaS Nebula 容器](https://gw.alipayobjects.com/mdn/site_comm/afts/file/A*y02KQ6c9gFkAAAAAAAAAAABkARQnAQ)

* 步骤三：使用 mPaaS 离线包

  [预置离线包，编译运行](https://gw.alipayobjects.com/mdn/site_comm/afts/file/A*U_wHQ51Gb6IAAAAAAAAAAABkARQnAQ)


#### [步骤四：申请 UC 内核]

  [申请 UC 内核 Key，预计半个工作日内生效](https://tech.antfin.com/docs/2/112551)

具体接入文档可参考：[mPaaS 容器文档](https://tech.antfin.com/docs/2/130789)

### 我们已经服务了谁

![容器能力 - 案例墙](https://img.alicdn.com/tfs/TB1aJf4vUz1gK0jSZLeXXb9kVXa-2560-641.png)

### 欢迎交流 + 反馈 + 拍砖

* Issue 反馈（如果你遇到任何 bug 或者功能需求，欢迎第一时间让我们知道）  
  [Issue 地址](https://github.com/alipay/mpaas-demo/issues)
* 加入技术交流群，有问题随时交流

![mPaaS 功能试用 - 引流关注](https://img.alicdn.com/tfs/TB1Rbf9vHY1gK0jSZTEXXXDQVXa-2560-1000.jpg)

### 开源许可

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

### Disclaimer（免责声明）

[免责声明](https://github.com/alipay/mpaas-demo/blob/master/Disclaimer.md)
