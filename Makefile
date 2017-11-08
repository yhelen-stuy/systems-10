all:
	gcc -o signals signals.c

run: all
	./signals

clean:
	rm signals
	rm errors.log
