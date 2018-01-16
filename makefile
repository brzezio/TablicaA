a.out: main.o
	c++ -Wall -pedantic main.o
main.o: main.cpp map_template.o employee.o biblioteka.o
	c++ -Wall -pedantic main.cpp -c
map_template.o: map_template.h
	c++ -Wall -pedantic map_template.h -c
employee.o: employee.h
	c++ -Wall -pedantic employee.h -c
biblioteka.o: biblioteka.h
	c++ -Wall -pedantic biblioteka.h -c

clear:
	rm a.out main.o employee.h.gch map_template.h.gch biblioteka.h.gch
