build:
	gcc 05ThreadFileRead.c -o 05ThreadFileRead.o -lpthread
	touch demo.txt
	@echo 'ABC zczczc___@#{}]' > demo.txt

clean:
	rm -rf 05ThreadFileRead.o
	rm -rf demo.txt

help:
	@echo '[USAGE] make build && make run'

run:
	./05ThreadFileRead.o ${ARGS}