#!usr/bin/bash


filename=$1".c"

cat << EOF > "$filename"
#include <stdio.h>

int main() {


    return 0;
}
EOF
