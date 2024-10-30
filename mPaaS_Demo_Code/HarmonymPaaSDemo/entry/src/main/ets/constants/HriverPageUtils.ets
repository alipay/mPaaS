import { Constants } from './Constants'

export class HriverPageUtils {
  static instance: HriverPageUtils | null = null
  pageLength: number = 0

  static getInstance() {
    if (!HriverPageUtils.instance) {
      HriverPageUtils.instance = new HriverPageUtils()
    }
    return HriverPageUtils.instance
  }

  addPageNum() {
    this.pageLength++
    console.info(Constants.TAG, `当前离线包pageLength：${this.pageLength}`)
  }

  removePageNum() {
    this.pageLength--
    console.info(Constants.TAG, `当前离线包pageLength：${this.pageLength}`)
  }
}

