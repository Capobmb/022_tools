まず Command + Shift + B でコンパイルする

# 1つのテストケース実行
```
cargo run --release --bin tester ./main < ./in/0000.txt > ./out/0000.txt 2> ./err/0000.txt
```

- その後visualizer見たい場合（使い方ようワカランからウェブ版使うだろうと思う）：
```
cargo run --release --bin vis ./in/0000.txt ./out/0000.txt
```

# 全テストケース実行
```
source runner.sh
```

# テストケースの生成
<p><code>in</code> ディレクトリに、あらかじめ生成された seed=0~99 に対する入力ファイルが置かれています。</p>
<p>より多くの入力が欲しい場合は、 <code>seeds.txt</code> に欲しい入力ファイルの数だけ乱数seed値(符号なし64bit整数値)を記入し、以下のコマンドを実行します。</p>
<pre>
cargo run --release --bin gen seeds.txt
</pre>
<p>生成された入力ファイルは <code>in</code> ディレクトリに出力されます。</p>

<p><code>seeds.txt</code> の各行の末尾に3つの整数 <code>l</code>, <code>n</code>, <code>s</code> をスペース区切りで続けることで、生成する入力の <code>L</code>, <code>N</code>, <code>S</code> の値をそれぞれ <code>l</code>, <code>n</code>, <code>s</code> に固定できます。  
一部のみを固定したい場合は、それら以外の値を <code>0</code> とします。</p>
<p>たとえば <code>seeds.txt</code> を以下のようにすると、 <code>seed=1, L=35, S=121</code> の入力が生成されます。</p>
<pre>
1 35 0 121
</pre>