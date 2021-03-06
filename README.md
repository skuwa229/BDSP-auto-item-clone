# BDSP-auto-item-clone

Arduinoを利用してダイパリメイク(v1.1.1)のメニューバグ状態でアイテム増殖を自動で行うコードです。  
バグを利用しているものですが、ゲームバランスを崩壊させるようなものなのでオフラインで利用することをおすすめします。  
今後のアップデートでBANやアイテムの削除も無いとは言い切れないので自己責任での利用をお願いします。  

# 利用方法
auto-item-clone.inoファイルの中身をArduinoのIDEにコピペし、書き込めば利用できます。  
[NintendoSwitchControlLibrary](https://github.com/lefmarna/NintendoSwitchControlLibrary)を利用しているので、事前に導入をしてください。

Arduinoを接続する際、以下の条件を満たしている状態で接続してください
1. ボックスを開いた際、一番最初に表示されるボックスにポケモンが30匹預けられていること
2. 1のボックスにいる30匹のポケモンが全てアイテムを所持していること（所持しているアイテムが増殖します）
3. メニューバグ状態かつメニューのカーソルがポケモンに合っていること
4. プレイヤーがハクタイシティのわざマシン46があった場所にいること（必須では無いですが、安定しないと思われます）

# ライセンス
[GNU General Public License v3.0](https://github.com/skuwa229/BDSP-auto-item-clone/blob/main/LICENSE)
