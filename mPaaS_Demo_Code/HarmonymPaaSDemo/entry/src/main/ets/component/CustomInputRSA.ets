import { Input, MPKeyboardType, MPEncryptType, KeyboardModel, buildSafeKeyboard, Cursor } from '@mpaas/safekeyboard';
import { Constants } from '../constants/Constants';

@Component
export struct CustomInputRSA {
  @Provide input: Input = new Input(MPKeyboardType.allNumber, MPEncryptType.rsa, Constants.RSA_PUBLIC_KEY_TEST_2048)
  control = new TextInputController()
  @Provide cursor: Cursor = new Cursor()
  private model: KeyboardModel = new KeyboardModel()


  build() {
    TextInput({ text: this.input.text, controller: this.control, placeholder: '特殊键盘(RSA)' })
      .width('40%')
      // .customKeyboard(buildSafeKeyboard(new KeyboardModel(), this.control, this.cursor))
      .customKeyboard(buildSafeKeyboard(this.model, this.control, this.cursor))
      .onChange((string) => {
        console.log('键盘输入为:' + string)
      })
      .onAppear(()=>{
        this.model.showPreView = false
        this.model.showLight = false
      })
  }
}
