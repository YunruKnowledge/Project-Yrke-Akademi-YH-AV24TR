
#!/bin/bash
clear
echo "run GCC."
gcc binaryConverter.c -o run
./run <<EOF
3
11001000
EOF

var='hello'
printf '|%10s|\n' "$var"