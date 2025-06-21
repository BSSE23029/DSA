#Compilation of files
.PHONY: run test eval clean

# Linking of files
r.out: main.o functions.o
	g++ -std=c++11 -o r.out main.o functions.o

e.out: evaluation.o functions.o
	g++ -std=c++11 -o e.out evaluation.o functions.o

a.out: test.o functions.o
	g++ -std=c++11 -o a.out test.o functions.o


#Compilation of files
%.o: %.cpp functions.h
	g++ -std=c++11 -c $< -o $@

#Forced targets to run
run: r.out
	./r.out

test: a.out
	./a.out

eval: e.out
	./e.out

clean:
	rm -f r.out e.out a.out *.o                           
