TARGET:liblist.a exe

liblist.a:LL_API.o
	ar rs liblist.a LL_API.o

exe:LL_main.o liblist.a
	gcc -g LL_main.o -o exe -L . -llist
	
