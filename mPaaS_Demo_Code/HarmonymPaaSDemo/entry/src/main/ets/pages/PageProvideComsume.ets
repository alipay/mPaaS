import { CompB } from '../component/ProvideConsumeTest';

@Entry
@Component
struct PageProvideComsume {
  // @Provide装饰的变量reviewVotes由入口组件PageProvideComsume提供其后代组件
  @Provide reviewVotes: number = 0;

  build() {
    Column() {
      Button(`reviewVotes(${this.reviewVotes}), give +1`)
        .onClick(() => this.reviewVotes += 1)
      CompB()
    }
  }
}