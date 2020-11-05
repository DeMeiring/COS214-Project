ofiles = main.o Engineering_Stage.o Engineering.o Department.o Component.o Engineering_Iterator.o
gpp_o = g++ -c -std=c++11 -static -g

main: $(ofiles)
	g++ -std=c++11 -static $(ofiles) -o main -g

main.o: main.cpp Engineering_Stage.h Engineering.h Department.h Component.h Engineering_Iterator.h

Engineering_Stage.o: Engineering_Stage.cpp Engineering_Stage.h
	$(gpp_o) Engineering_Stage.cpp

Engineering.o: Engineering.cpp Engineering.h
	$(gpp_o) Engineering.cpp

Department.o: Department.cpp Department.h
	$(gpp_o) Department.cpp

Component.o: Component.cpp Component.h
	$(gpp_o) Component.cpp

Engineering_Iterator.o: Engineering_Iterator.cpp Engineering_Iterator.h
	$(gpp_o) Engineering_Iterator.cpp

run: main
	./main

clean:
	rm *.o main