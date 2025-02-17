import { MPFile } from '@mpaas/datacenter'
import { Constants } from './Constants'
import { getLoaclJson } from './Global'

export class MPFileUtils {
  static instance: MPFileUtils | null = null
  mpfile: MPFile | null = null

  static getInstance() {
    if (!MPFileUtils.instance) {
      MPFileUtils.instance = new MPFileUtils()
    }
    return MPFileUtils.instance
  }

  private constructor() {
    this.mpfile = new MPFile()
  }

  getFileByName(name: string): Promise<string> {
    return new Promise((resolve: Function, reject: Function) => {
      this.mpfile?.getFileContent(name).then((result) => {
        console.info(Constants.TAG, `文件存储获取：${result}`)
        resolve(result)
      }).catch((err: Error) => {
        console.info(Constants.TAG, `文件存储获取：JSON.stringify(err)`)
        reject(err)
      })
    })
  }

  saveFileByName(name: string) {
    getLoaclJson("pageIndexConfig.txt").then((result: string) => {
      console.info(Constants.TAG, `读取本地json：${result}`)
      this.mpfile?.saveFile(name, result).then((result) => {
        console.info(Constants.TAG, `文件存储状态 ${result}`)
      })
    }).catch((error: Error) => {
    })
  }
}

// export default MPFileUtils.getInstance()

