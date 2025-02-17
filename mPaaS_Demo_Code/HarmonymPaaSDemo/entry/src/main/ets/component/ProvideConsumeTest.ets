@Component
struct CompD {
  // @Consume装饰的变量通过相同的属性名绑定其祖先组件PageProvideComsume内的@Provide装饰的变量
  @Consume('reviewVotes') a: number;

  build() {
    Column() {
      Text(`reviewVotes(${this.a})`)
      Button(`reviewVotes(${this.a}), give +1`)
        .onClick(() => this.a += 1)
    }
    .width('50%')
  }
}

@Component
struct CompC {
  build() {
    Row({ space: 5 }) {
      CompD()
      CompD()
    }
  }
}

@Component
struct CompB {
  build() {
    CompC()
  }
}

export { CompB, CompC, CompD }