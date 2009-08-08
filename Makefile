all: mousewheel-cli

%: %.c
	$(CC) -lX11 -lXtst -o $@ $^

clean:
	$(RM) mousewheel-cli

.PHONY: clean
