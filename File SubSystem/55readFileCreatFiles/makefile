build:
	gcc 05readFileCreatFiles.c -o 05readFileCreatFiles.o

clean:
	rm -rf 05readFileCreatFiles.o
	rm -rf ./test/a.txt_recovered
	rm -rf ./test/b.txt_recovered
	rm -rf ./test/c.txt_recovered

help:
	@echo '[USAGE] make build && make run ARGS="filname"'

run:
	./05readFileCreatFiles.o ${ARGS}