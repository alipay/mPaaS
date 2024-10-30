// Dialog NavDestination

@Entry
@Component
struct TestPageNavigationChild {
  @Provide('NavPathStack') pageStack: NavPathStack = new NavPathStack()

  @Builder
  PagesMap(name: string) {
    if (name == 'DialogPage') {
      DialogPage()
    }
    if (name == 'ChildPage') {
      ChildPage()
    }
  }

  build() {
    Navigation(this.pageStack) {
      Button('Push DialogPage')
        .margin(20)
        .width('80%')
        .onClick(() => {
          this.pageStack.pushPathByName('DialogPage', '');
        })
      Button('Push ChildPage')
        .margin(20)
        .width('80%')
        .onClick(() => {
          this.pageStack.pushPathByName('ChildPage', '');
        })
    }
    .mode(NavigationMode.Stack)
    .title('Main')
    .navDestination(this.PagesMap)
  }
}

@Component
export struct ChildPage {
  @Consume('NavPathStack') pageStack: NavPathStack;

  build() {
    NavDestination() {
      Stack({ alignContent: Alignment.Center }) {
        Column() {
          Text("Dialog NavDestination")
            .fontSize(20)
            .margin({ bottom: 100 })
          Button("Close")
            .onClick(() => {
              this.pageStack.pop()
            })
            .width('30%')
        }
        .justifyContent(FlexAlign.Center)
        .backgroundColor(Color.White)
        .borderRadius(10)
        .height('100%')
        .width('100%')
      }.height("100%").width('100%')
    }
    .height('100%')
    .width('100%')
    .backgroundColor('rgba(0,0,0,0.5)')
    .hideTitleBar(true)
    .mode(NavDestinationMode.STANDARD)
  }
}

@Component
export struct DialogPage {
  @Consume('NavPathStack') pageStack: NavPathStack;

  build() {
    NavDestination() {
      Stack({ alignContent: Alignment.Center }) {
        Column() {
          Text("Dialog NavDestination")
            .fontSize(20)
            .margin({ bottom: 100 })
          Button("Close").onClick(() => {
            this.pageStack.pop()
          }).width('30%')
        }
        .justifyContent(FlexAlign.Center)
        .backgroundColor(Color.White)
        .borderRadius(10)
        .height('30%')
        .width('80%')
      }.height("100%").width('100%')
    }
    .backgroundColor('rgba(0,0,0,0.5)')
    .hideTitleBar(true)
    .mode(NavDestinationMode.DIALOG)
  }
}