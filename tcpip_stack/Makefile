CC=gcc
CFLAGS=-g
TARGET:test.exe

OBJS=gluethread_lib/glthread.o	\
		 graph.o										\
		 topologies.o								\
		 net.o
			
test.exe:testapp.o ${OBJS}
	${CC} ${CFLAGS} testapp.o ${OBJS} -o test.exe
	
testapp.o:testapp.c
	${CC} ${CFLAGS} -c testapp.c -o testapp.o
	
gluethread_lib/glthread.o:gluethread_lib/glthread.c
	${CC} ${CFLAGS} -c -I gluethread_lib gluethread_lib/glthread.c -o gluethread_lib/glthread.o

graph.o:graph.c
	${CC} ${CFLAGS} -c -I . graph.c -o graph.o

topologies.o:topologies.c
	${CC} ${CFLAGS} -c -I . topologies.c -o topologies.o
	
net.o:net.c
	${CC} ${FLAGS} -c -I . net.c -o net.o
	
utils.o:utils.c
	${CC} ${FLAGS} -c -I . utils.c -o utils.o
	
clean:
	rm *.o
	rm gluethread_lib/glthread.o
	rm *exe