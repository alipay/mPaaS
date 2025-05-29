let full = '100%'

interface BaseListener{
  changeString(inputString: string): string
  showString?(show: string): void
}

class ChildCallBack implements  BaseListener{


  onChildChange: Function = (change: string) => null

  // changeString(inputString: string): string {
  //   return inputString.concat(' to changeStr()')
  // }
  changeString(inputString: string): string {
    throw new Error('Method not implemented.')
  }
}

@Preview
@Entry
@Component
struct TestInterface{

  readonly childCallBack = new ChildCallBack()

  @State showMsg : string = ''

  aboutToAppear(): void {
    this.childCallBack.onChildChange = (change: string)=>{
      this.showMsg = change
    }
  }

  build() {
    Column({ space: 18 }) {
      Text('Simple Interface click: '.concat(this.showMsg))
      customList({
        childCallBack: this.childCallBack
      })
    }.width(full)
    .height(full)
    .padding(18)
    .justifyContent(FlexAlign.Center)

  }


}

@Component
struct customList{

  childCallBack? : ChildCallBack

  build() {

    List({space: 3}){
      ForEach(['1','2','3','4', '5'], (item: string, index: number) =>{
        ListItem(){
          Text('customList'.concat(` ${item}`))
            .onClick(()=>{
              if(this.childCallBack) this.childCallBack.onChildChange('customList'.concat(` ${item}`))
            })
        }
      })
    }.width(full)
    .padding(18)
  }
}
