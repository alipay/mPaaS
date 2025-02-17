import { H5WebClientProvider, Page } from '@mpaas/hriver';
import { Constants } from '../constants/Constants';

export class H5WebProivder extends H5WebClientProvider {
  onScroll(x: number, y: number, page: Page | undefined): void {
    console.info(Constants.TAG,`透传滚动   ${x}  ${y}  ${page?.pageId}`)
  }
}