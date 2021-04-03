CC=gcc
CFLAGS=-g
TARGET:test.exe

OBJS=gluethread_lib/glthread.o	\
			graph.o										\
			topologies.o
			
test.exe:testapp.o ${OBJS}
	${CC} ${CFLAGS} testapp.o ${OBJS} -o test.exe
	