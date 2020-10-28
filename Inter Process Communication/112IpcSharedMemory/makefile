build:
	gcc 02IpcSharedMemory.c -o 02IpcSharedMemory.o
	gcc child_1.c -o proc1
	gcc child_2.c -o proc2

clean:
	rm -rf 02IpcSharedMemory.o
	rm -rf proc1
	rm -rf proc2

help:
	@echo '[USAGE] make build && make run'

run:
	./02IpcSharedMemory.o ${ARGS}