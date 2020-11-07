build:
	gcc 01IpcFiFO.c -o 01IpcFiFO.o
	gcc reader.c -o reader
	gcc writer.c -o writer

clean:
	rm -rf 01IpcFiFO.o
	rm -rf reader
	rm -rf writer
	rm -rf /tmp/fifo_file

help:
	@echo '[USAGE] make build && make run'

run:
	./01IpcFiFO.o ${ARGS}