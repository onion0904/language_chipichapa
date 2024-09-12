#include <stdio.h>
#include <stdlib.h>

#define MEM_SIZE 30000

int main(int argc, char *argv[]) {
    char memory[MEM_SIZE] = {0}; // メモリ配列の初期化
    char *ptr = memory; // ポインタの初期位置
    int c; // 入力された文字を一時的に保存

    // ファイルからBrainfuckコードを読み込む
    FILE *file = fopen(argv[1], "r");
    if (!file) {
        fprintf(stderr, "ファイルが開けません: %s\n", argv[1]);
        return 1;
    }

    // ファイルから1文字ずつ読み込み、対応する操作を実行
    while ((c = fgetc(file)) != EOF) {
        switch (c) {
            case '>':
                ptr++; // ポインタをインクリメント
                break;
            case '<':
                ptr--; // ポインタをデクリメント
                break;
            case '+':
                (*ptr)++; // ポインタが指す値をインクリメント
                break;
            case '-':
                (*ptr)--; // ポインタが指す値をデクリメント
                break;
            case '.':
                putchar(*ptr); // ポインタが指す値を出力
                break;
            case ',':
                *ptr = getchar(); // 1バイトを入力
                break;
            case '[':
                if (*ptr == 0) {
                    // 対応する ']' を見つける
                    int loop = 1;
                    while (loop > 0) {
                        c = fgetc(file);
                        if (c == '[') loop++;
                        if (c == ']') loop--;
                    }
                }
                break;
            case ']':
                if (*ptr != 0) {
                    // 対応する '[' を見つける
                    int loop = 1;
                    fseek(file, -2, SEEK_CUR);
                    while (loop > 0) {
                        c = fgetc(file);
                        fseek(file, -2, SEEK_CUR); // 1文字前に戻る
                        if (c == ']') loop++;
                        if (c == '[') loop--;
                    }
                    fseek(file, 1, SEEK_CUR); // 正しい位置に調整
                }
                break;
        }
    }

    fclose(file); // ファイルを閉じる
    return 0;
}
