BIN = x11-idle-time

$(BIN): x11-idle-time.c
	gcc -Wall -Wextra -O2 -lX11 -lXss -o $@ $<
	strip $@

all: $(BIN)

clean:
	rm -f $(BIN)

.PHONY: all clean
