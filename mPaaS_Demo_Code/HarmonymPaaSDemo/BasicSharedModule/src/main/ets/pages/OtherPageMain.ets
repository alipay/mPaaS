@Builder
export function getOtherPageMain(): void {
  OtherPageMain()
}

@Component
export struct OtherPageMain {
  @State message: string = '跨module打开page';

  build() {
    NavDestination() {
      Row() {
        Column() {
          Text(this.message)
            .fontSize(20)
            .fontWeight(FontWeight.Bold)
        }
        .width('100%')
      }
      .height('100%')
    }
  }
}