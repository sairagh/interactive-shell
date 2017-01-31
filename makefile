all:
	gcc main.c exit_child.c cd.c user_print.c spawn.c splitline.c fg.c splitio.c splitio1.c built.c -o hello

clean:
	rm ./hello
