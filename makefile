.PHONY: make run compile clean

run:
	@./a.out

compile: main.o
	@gcc -o a.out main.o -lm

main.o:
	@gcc -c main.c -lm

clean:
	@rm -f *.o a.out main.o
