#!usr/bin/bash


filename=$1".cpp"

cat << EOF > "$filename"
#include <stdio.h>

using namespace std;

int main() {


    return 0;
}
EOF
