run:
	make compile
	./Driver

compile:
	g++ *.cpp -c
	g++ *.o -o Driver

clean:
	rm *.o
	rm ./Driver


