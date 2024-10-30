import { H5EmbedPageLifeCycleProvider } from '@mpaas/hriver';
import router from '@ohos.router';

export class H5EmbedPageLifeCycleProviderImpl extends H5EmbedPageLifeCycleProvider {

  pageInfos: NavPathStack

  constructor(pageInfos: NavPathStack) {
    super();
    this.pageInfos = pageInfos;
  }


  onPageShow(): void {
    super.onPageShow();
  }

  //修复解决首页 tab 第二次打开离线包白屏问题
  // onPageHide(): void {
  //   super.onPageHide();
  //   if (this.pageInfos.size() == 0) {
  //     router.back()
  //   }
  // }
}