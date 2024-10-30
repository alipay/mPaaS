import { H5UrlInterceptProvider, Page } from '@mpaas/hriver';
import { Constants } from '../constants/Constants';

export class MyH5UrlInterceptProvider extends H5UrlInterceptProvider {
  intercept(request: WebResourceRequest, page: Page | undefined): boolean {
    console.error(Constants.TAG, `page:${page?.startParams}   request:${request.getRequestUrl()}`)
    console.error(Constants.TAG, `page:${page?.webcontroller?.getUrl()}`)
    if (page != undefined) {
      // page.webcontroller?.loadUrl("https://www.baidu.com")

      // page.webcontroller?.runJavaScript("")
    }
    return false
  }
}