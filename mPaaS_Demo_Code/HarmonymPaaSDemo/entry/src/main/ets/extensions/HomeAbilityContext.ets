import { common } from '@kit.AbilityKit';
import { window } from '@kit.ArkUI';

export class HomeAbilityContext {
  private mAbilityContext?: common.UIAbilityContext;
  private mNavPathStack?: NavPathStack;
  private mWindowStage?: window.WindowStage;

  constructor(abilityContext?: common.UIAbilityContext) {
    this.mAbilityContext = abilityContext;
  }

  setWindowStage(windowStage?: window.WindowStage) {
    this.mWindowStage = windowStage;
  }

  getWindowStage() {
    return this.mWindowStage;
  }

  setNavPathStack(navPathStack?: NavPathStack) {
    this.mNavPathStack = navPathStack;
    if (this.mAbilityContext) {
      this.mAbilityContext.eventHub.emit(navPathStack ? "FRAMEWORK_EVENT_NAV_PATH_STACK_ATTACH" :
        "FRAMEWORK_EVENT_NAV_PATH_STACK_DETACH");
    }
  }

  getNavPathStack(): NavPathStack | undefined {
    return this.mNavPathStack;
  }
}