build:
	gcc 03ProcRenameFilesInDir.c -o 03ProcRenameFilesInDir.o
	gcc 03RenameProc.c -o 03RenameProc.o
	mkdir test
	touch test/a.txt test/b.txt test/c.txt test/d.txt

clean:
	rm -rf 03ProcRenameFilesInDir.o
	rm -rf 03RenameProc.os
	rm -rf test

help:
	@echo '[USAGE] make build && make run ARGS="DirectoryName"'

run:
	./03ProcRenameFilesInDir.o ${ARGS}
	#./03RenameProc.o ${ARGS}