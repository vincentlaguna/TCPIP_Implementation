TARGET:liblist.a exe
liblist.a:LL_API.o
	ar rs liblist.a LL_API.o
exe:LL_main.o liblist.a
	gcc -g LL_main.o -o exe -L . -llist
LL_API.o:LL_API.c
	gcc -g -c -I . LL_main.c -o LL_main.o
clean:
	rm *.o
	rm exe
	rm liblist.a