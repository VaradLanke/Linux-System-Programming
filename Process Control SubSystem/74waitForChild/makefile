build:
	gcc 04waitForChild.c -o 04waitForChild.o
	gcc add.c -o add.o
	gcc subtract.c -o subtract.o

clean:
	rm -rf 04waitForChild.o
	rm -rf add.o
	rm -rf subtract.o

help:
	echo '[INFO] make build && make run'

run:
	./04waitForChild.o ${ARGS}