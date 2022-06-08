build:
	gcc main.c -o main.o -I./elk-2.2.0 -c
	gcc elk-2.2.0/elk.c -o elk.o -c
	gcc -o app main.o elk.o -lm
	rm *.o
run:
	./app
create:
	wget https://github.com/cesanta/elk/archive/refs/tags/2.2.0.zip
	unzip 2.2.0.zip
	rm -r 2.2.0.zip
clean:
	rm -fr elk-2.2.0
	rm -rf 2.2.0.zip
	rm *.o