build:
	gcc 05IpcSignalTwoProc.c -o 05IpcSignalTwoProc.o
	gcc sender.c -o sender
	gcc receiver.c -o receiver

clean:
	rm -rf sender
	rm -rf receiver
	rm -rf 05IpcSignalTwoProc.o

help:
	@echo '[USAGE] make build && make run'

run:
	./05IpcSignalTwoProc.o ${ARGS}