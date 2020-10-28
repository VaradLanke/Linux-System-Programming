build:
	gcc 05IpcMgsqClient.c -o client
	gcc 05IpcMgsqServer.c -o server

clean:
	rm -rf client
	rm -rf server

help:
	@echo '[USAGE] make build && make run'

runserver:
	./server ${ARGS}

runclient:
	./client ${ARGS}