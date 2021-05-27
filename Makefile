build/lellointerpreter.exe: build/main.o build/comandi.o build/vm.o build/lelloBLER.o
	gcc build/main.o build/comandi.o build/vm.o build/lelloBLER.o -o build/lellointerpreter.exe

build/main.o: code/main.c
	gcc -c code/main.c -o build/main.o

build/comandi.o: code/lelloVM/comandi.c code/lelloVM/comandi.h
	gcc -c code/lelloVM/comandi.c -o build/comandi.o

build/vm.o: code/lelloVM/vm.c code/lelloVM/vm.h
	gcc -c code/lelloVM/vm.c -o build/vm.o

build/lelloBLER.o: code/lelloASSEBLY/lelloBLER.c code/lelloASSEBLY/lelloBLER.h
	gcc -c code/lelloASSEBLY/lelloBLER.c -o build/lelloBLER.o

clean:
	del build\*.o build\lellointerpreter.exe

test:
	./build/lellointerpreter.exe example/conta.txt