import { hilog } from '@kit.PerformanceAnalysisKit'
import { Constants } from '../constants/Constants';

export class DLogger {
  static error(desc: string, log: string) {
    hilog.info(0x0000, Constants.TAG, '%{public}s->%{public}s', desc, log);
  }

  static info(desc: string, log: string) {
    console.error(Constants.TAG, `${desc}`, `${log}`);
  }
}