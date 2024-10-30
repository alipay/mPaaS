import { Input, MPKeyboardType, MPEncryptType,KeyboardModel,buildSafeKeyboard, Cursor} from '@mpaas/safekeyboard';
import { Constants } from '../constants/Constants';

@Component
export struct CustomInputSM2 {
  @Provide input: Input = new Input(MPKeyboardType.allNumber,MPEncryptType.sm2,Constants.SM2_PUBLIC_KEY_TEST)
  control = new TextInputController()
  @Provide cursor: Cursor = new Cursor()
  build() {
    TextInput({text: this.input.text,controller: this.control,placeholder:'特殊键盘(SM2)'})
      .width('40%')
      .customKeyboard(buildSafeKeyboard(new KeyboardModel(), this.control,this.cursor))
      .onChange((string) => {
        console.log('键盘输入为:' + string)
      })
  }
}
