ofiles = main.o Engineering_Stage.o Engineering.o Department.o Component.o Engineering_Iterator.o Statistics.o A_Base_Car.o A_Car_Factory.o Base_Car.o Car_Factory.o BluePrint.o Transport.o
gpp_o = g++ -c -std=c++11 -static -g

main: $(ofiles)
	g++ -std=c++11 -static $(ofiles) -o main -g

main.o: main.cpp Engineering_Stage.h Engineering.h Department.h Component.h Engineering_Iterator.h Statistics.h A_Base_Car.h A_Car_Factory.h Base_Car.h Car_Factory.h BluePrint.h Transport.h

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

Statistics.o: Statistics.cpp Statistics.h
	$(gpp_o) Statistics.cpp

A_Base_Car.o: A_Base_Car.cpp A_Base_Car.h
	$(gpp_o) A_Base_Car.cpp

A_Car_Factory.o: A_Car_Factory.cpp A_Car_Factory.h
	$(gpp_o) A_Car_Factory.cpp

Base_Car.o:	Base_Car.cpp Base_Car.h
	$(gpp_o) Base_Car.cpp

Car_Factory.o: Car_Factory.cpp Car_Factory.h
	$(gpp_o) Car_Factory.cpp

BluePrint.o: BluePrint.cpp BluePrint.h
	$(gpp_o) BluePrint.cpp

Transport.o: Transport.cpp Transport.h
	$(gpp_o) Transport.cpp

run: main
	./main

clean:
	rm *.o main