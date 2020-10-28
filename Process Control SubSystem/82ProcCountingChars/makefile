build:
	gcc 02ProcCountingChars.c -o 02ProcCountingChars.o
	gcc 02CapsCharCounter.c -o CounterProc

clean:
	rm -rf 02ProcCountingChars.o
	rm -rf CounterProc
	rm -rf count.txt

help:
	@echo '[USAGE] make build && make run ARGS="FileName1 FileName2"'

run:
	./02ProcCountingChars.o ${ARGS}