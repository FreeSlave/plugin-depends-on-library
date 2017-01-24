#!/bin/sh

gcc -shared -fPIC libtest.c -o libtest.so
gcc main.c -o main -ldl -L. -ltest -Wl,-rpath=.
cd plugins && gcc -shared -fPIC plugin.c -o libplugin.so -L.. -ltest
