build/lellointerpreter.exe: build/main.o build/comandi.o build/vm.o
	gcc build/main.o build/comandi.o vm.o -o build/lellointerpreter

build/main.o: code/main.c
	gcc -c code/main.c -o build/main.o

build/comandi.o: code/lelloVm/comandi.c code/lelloVm/comandi.h
	gcc -c code/lelloVm/comandi.c -o build/comandi.o

build/vm.o: code/lelloVm/vm.c code/lelloVm/vm.h
	gcc -c code/lelloVm/vm.c -o build/vm.o

clean:
	del build\*.o build\lellointerpreter.exe

test:
	.\build\lellointerpreter.exe