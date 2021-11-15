#include <GL/glut.h>
#include <iostream>
#include "common.h"

using namespace std;

void run(void)
{
    // 以下がバッファの初期化
    glClearColor(1.0, 0.75, 0.75, 1.0); // バッファを初期化するカラー情報
    glClear(GL_COLOR_BUFFER_BIT);   // バッファを初期化
    // 以上がバッファの初期化
    cout << "バッファの初期化の完了\n" << endl;
}

int main(int argc, char *argv[])
{
    // 以下初期化処理
    glutInit(&argc, argv);  // GLUT を初期化
    glutInitWindowPosition(WINDOWPOSITION.x, WINDOWPOSITION.y);   // ウィンドウの位置を決定
    glutInitWindowSize(WINDOWSIZE.x, WINDOWSIZE.y);   // ウィンドウサイズを決定
    glutInitDisplayMode(GLUT_RGBA); // GLUT のディスプレイモードを設定する。
    // 以上が初期化処理
    cout << "GLUT の初期化の完了\n" << endl;

    // 以下がウィンドウの生成と表示
    glutCreateWindow("This is top level window.");  // トップレベルウィンドウを生成する
    glutDisplayFunc(run);  // コールバック関数の登録
    glutMainLoop(); // 最後に呼び出されるべき関数
    // 以上がウィンドウの生成と表示
    cout << "ウィンドウの生成と表示の完了\n" << endl;

    return 0;
}




