#!/bin/bash

echo -n "FILENAME:"
read STR

echo -n "1.C, 2.C++ > "
read MODE
while true
do
    case "$MODE" in
        1)
            echo "gcc $STR.c -o $STR.out -lglut -lGL"
            gcc $STR.c -o $STR.out -lglut -lGL
            exit
            ;;
        2)
            echo "g++ $STR.cpp -o $STR.out -lglut -lGL"
            g++ $STR.cpp -o $STR.out -lglut -lGL
            exit
            ;;
        *)
            echo "undefined..."
            exit
            ;;
    esac
done

# Bibliography
# https://atmarkit.itmedia.co.jp/ait/articles/1705/26/news013.html  // echo オプション
# https://atmarkit.itmedia.co.jp/ait/articles/1811/21/news009.html  // case による条件分岐
# https://qiita.com/tamurashingo@github/items/54b25acc93e37580989d  // while によるループ
