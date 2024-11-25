compile fork: fork.o
	@gcc -o fork fork.o
fork.o: fork.c 
	@gcc -c fork.c
run: fork
	@./fork
clean:
	rm *.o
	rm fork
