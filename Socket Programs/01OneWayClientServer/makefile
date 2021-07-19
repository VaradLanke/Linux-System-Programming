build:
		gcc tcp_client.c -o client.o
		gcc tcp_server.c -o server.o

clean:
		rm -rf client.o server.o

help:
		@echo '[USAGE] make build && make run'

run_server:
		./server.o ${ARGS}

run_client:
		./client.o ${ARGS}
