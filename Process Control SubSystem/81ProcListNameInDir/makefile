build:
	gcc 01ProcListNameInDir.c -o 01ProcListNameInDir.o
	gcc 01Proc.c -o myProc
	touch ~/Desktop/a.txt ~/Desktop/b.txt

clean:
	rm -rf 01ProcListNameInDir.o
	rm -rf 01Proc.o
	rm -rf data.txt
	rm -rf ~/Desktop/a.txt ~/Desktop/b.txt

help:
	@echo '[USAGE] make build && make run'

run:
	./01ProcListNameInDir.o ${ARGS}