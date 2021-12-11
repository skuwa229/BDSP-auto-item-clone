#include <NintendoSwitchControlLibrary.h>
//MIT License
//
//Copyright (c) 2021 lefmarna
//
//Copyright (c) 2019 celclow
//
//Permission is hereby granted, free of charge, to any person obtaining a copy
//of this software and associated documentation files (the "Software"), to deal
//in the Software without restriction, including without limitation the rights
//to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
//copies of the Software, and to permit persons to whom the Software is
//furnished to do so, subject to the following conditions:
//
//The above copyright notice and this permission notice shall be included in all
//copies or substantial portions of the Software.
//
//THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
//IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
//FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
//AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
//LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
//OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
//SOFTWARE.

void setup(){
  // 前回のカーソルがポケモンに残っている前提
  // スクショボタンを連打して認識待ちをする
  pushButton(Button::CAPTURE, 200, 4);

  delay(2000);
}

// ここに記述した内容がループされ続ける
void loop(){
  // boxの二重起動バグを作る
  prepareBox();

  // 二枚目のboxでアイテムを回収
  for (int height = 0; height < 5; height++) { // boxの高さ
    for (int width = 0; width < 6; width++) { // boxの横幅
      // カーソルのあっているポケモンからアイテムを奪う
      getItem();

      // カーソルを右にずらす
      pushHat(Hat::RIGHT, 100);
      
      // boxの右端のポケモンにカーソルが合っていた場合は次の列にカーソルをずらす
      if (width == 5 && height != 4) {
        pushHat(Hat::RIGHT, 100);
        pushHat(Hat::DOWN, 100);
      }
    }
  }
  delay(500);

  // 全部回収したら1枚目のboxに戻る
  pushButton(Button::B, 1500, 3);

  // アイテムデータの複製を行う
  duplication();

  // メニューバグ状態に戻す
  pushButton(Button::B, 2000, 3);
  delay(500);
}

// メニューバグ状態からボックスの二重起動を行う
void prepareBox() {
  // 手持ち一覧へ
  pushButton(Button::A, 1500);

  // Rでボックスを開く
  pushButton(Button::R, 1500);

  // せいり + メニュー表示状態へ
  pushButton(Button::X, 1000, 5);

  // 手持ち一覧へ
  pushButton(Button::A, 1000);

  // Rでボックスを開く
  pushButton(Button::R, 1500);
}

// カーソルがあっているポケモンからアイテムを奪う
void getItem() {
  // ポケモンを選択
  pushButton(Button::A, 100);

  // 持ち物にカーソルをあわせる
  pushHat(Hat::DOWN, 100, 2);

  // アイテムを奪う
  pushButton(Button::A, 500, 3);
}

// アイテムデータの複製を行う
void duplication() {
  // ポケモン選択
  pushButton(Button::A, 200);

  // つよさをみるにカーソルをあわせる
  pushHat(Hat::DOWN, 200);

  // つよさをみる
  pushButton(Button::A, 1000);
}

