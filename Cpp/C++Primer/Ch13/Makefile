#file: Makefile
test_makefile: test_makefile.o Message.o Folder.o String.o
	g++ test_makefile.o Message.o Folder.o String.o -o test_makefile

test_makefile.o: test_makefile.cpp Message.cpp Folder.cpp String.cpp
	g++ -c test_makefile.cpp

Message.o: Message.cpp Folder.cpp
	g++ -c Message.cpp

Folder.o: Folder.cpp Message.cpp
	g++ -c Folder.cpp

String.o: String.cpp
	g++ -c String.cpp

.PHONY: clean

clean: 
	del *.o -rf
