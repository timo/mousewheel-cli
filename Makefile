default: mousewheel-cli.c
	gcc -o mousewheel-cli -lX11 -lXtst mousewheel-cli.c
