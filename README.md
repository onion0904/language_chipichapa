# language_chipichapa

## 説明
これは簡単に言語を作りたいという思いから生まれた言語chipichapaです。
オリジナルの記法をbrainfuckに対応づけることで簡単に実装しました。
chipichapaの元ネタは猫ミームから来ています。

## 使用方法

```
make run INPUT=hoge.cat
```

## catとbrainfuckの対応

| Brainfuck | Cat         |
|-----------|-------------|
| `>`       | chipi chipi |
| `<`       | chapa chapa |
| `+`       | dubi dubi   |
| `-`       | daba daba   |
| `,`       | boom boom   |
| `.`       | chipi chapa |
| `[`       | dubi daba   |
| `]`       | happy happy |


## chipichapaが書けない人へ

[このサイト](https://mikecat.usamimi.info/jstool/bfgen/)を用いてhoge.bfファイルを作り
```
gcc -o bf_to_cat bf_to_cat.c
./bf_to_cat < hoge.bf > hoge.cat
```
この手順で.catファイルが作れます

## 実行例
フォルダ内のhello.catを使用すると"Hello World!"が出力できます。
```
make run INPUT=hello.cat
```