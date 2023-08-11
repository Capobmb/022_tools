# Usage
Command + Shift + B でコンパイルする

## 1つのテストケース実行
```
cargo run --release --bin tester ./main < ./in/0000.txt > ./out/0000.txt 2> ./err/0000.txt
```

その後visualizer見たい場合（使い方ようワカランからウェブ版使うだろうと思う）：
```
cargo run --release --bin vis ./in/0000.txt ./out/0000.txt
```

## 全テストケース実行
```
source runner.sh
```