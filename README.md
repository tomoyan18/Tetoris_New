# Tetoris_New

<仕様><br/>
@* 仕様言語 *@ <br/>
● C++ <br/>
<br/>

@* 使用ツール *<br/>
● SDL2</br>
● SDL2/SDL_ttf <br/>
<br/>

@* 開発環境 *@<br/>
● Mac<br/>
●　Visual Studio Code<br/>
<br/>

@* フォルダ・ファイル構成 *@ <br/>

Tetris/<br/>
├── main.cpp                  // SDL初期化とメインループ<br/>
├── Game/<br/>
│   ├── Game.h<br/>
│   └── Game.cpp              // ゲーム全体の管理 <br/>
├── Tetromino/ <br/>
│   ├── Tetromino.h <br/>
│   └── Tetromino.cpp        // テトロミノの定義・動き<br/>
├── Board/ <br/>
│   ├── Board.h<br/>
│   └── Board.cpp            // ゲーム盤（フィールド）管理<br/>
├── Assets/Fonts             // フォントや画像など<br/>
├── Makefile                 // ビルド設定<br/>

<br/>

@* 盤面 *@<br/>
● Height：20 <br />
● Width ：10 <br />
<br/>

@* 操作 *@<br/>
● テトロミノの形を変更するには、上矢印キーで変更<br/>
● テトロミノの移動は左右矢印キーで移動<br/>
<br/>

@* スコア *@<br/>
● 一列消すごとに10P加算<br/>
● 複数列消してもそれぞれ10P加算<br/>
<br/>

@* 画面 *@<br/>
● タイトル画面　　　：Enterキーでゲーム画面へ<br/>
● ゲーム画面<br/>
● ゲームオーバー画面：Tキーでタイトルに、Rキーでリトライ（ゲーム画面に戻る）</br>
</br>

@* テトロミノ *@<br/>
● I<br/>
● O<br/>
● T<br/>
● S<br/>
● Z<br/>
● J<br/>
● L<br/>
