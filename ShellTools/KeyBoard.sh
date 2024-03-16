#!/usr/bin/bash

arg="$1"

if [ -z $arg ] 
then
    echo "请使用参数 '--disable' 或 '--enable' "
else

    if [ $arg == '--disable' ]
    then
        xinput disable "AT Translated Set 2 keyboard"
        echo "关闭完成"
    fi

    if [ $arg == '--enable' ]
    then
        xinput enable "AT Translated Set 2 keyboard"
        echo "打开完成"
    fi
fi

