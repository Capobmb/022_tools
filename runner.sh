#!/bin/zsh

# ここにコンパイルコマンド（いる？）

for file in $(ls -1 ./in/*.txt); do
    filename=${file:5}
    cargo run --release --bin tester ./main < ./in/$filename > ./out/$filename 2> ./err/$filename
done

echo All the testcase processed.
