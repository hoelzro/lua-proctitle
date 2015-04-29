proctitle.so: proctitle.o
	gcc -o $@ -shared $< -lm -ldl -llua5.1

proctitle.o: proctitle.c
	gcc -c -fPIC $< -I/usr/include/lua5.1
