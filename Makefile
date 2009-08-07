default: mousewheel-cli.c
	$(CC} -o mousewheel-cli -lX11 -lXtst mousewheel-cli.c
