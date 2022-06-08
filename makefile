build:
	gcc main.c -o main -I./elk-2.2.0
run:
	./main
create:
	wget https://github.com/cesanta/elk/archive/refs/tags/2.2.0.zip
	unzip 2.2.0.zip
	rm -r 2.2.0.zip
clean:
	rm -fr elk-2.2.0
	rm -rf 2.2.0.zip