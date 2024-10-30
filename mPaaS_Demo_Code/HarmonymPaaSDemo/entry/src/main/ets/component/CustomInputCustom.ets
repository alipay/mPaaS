import { Input, MPKeyboardType, MPEncryptType, KeyboardModel, buildSafeKeyboard, Cursor } from '@mpaas/safekeyboard';
import { Constants } from '../constants/Constants';

@Component
export struct CustomInputCustom {
  @Provide input: Input = new Input(MPKeyboardType.allNumber, MPEncryptType.rsa, Constants.RSA_PUBLIC_KEY_TEST_2048)
  private model: KeyboardModel = new KeyboardModel()
  control = new TextInputController()
  @Provide cursor: Cursor = new Cursor()

  build() {
    TextInput({ text: this.input.text, controller: this.control, placeholder: '自定义' })
      .width('40%')
      .customKeyboard(buildSafeKeyboard(this.model, this.control, this.cursor))
      .caretStyle({ width: 0 })
      .onAppear(()=>{
        this.model.showPreView = false
        this.model.showLight = false
      })
  }
}
