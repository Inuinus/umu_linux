CC = gcc
CFLAGS = -Wall -Wextra -g
#dependencieflags, if .h file is changed, this will make that .c is regenerated
DEPFLAGS = -MMD -MP

CFILES = main.c a_functions.c b_functions.c c_functions.c d_functions.c
#*.o
OBJECTS = $(CFILES:.c=.o)
#*.d
DEPFILES = $(OBJECTS:.o=.d) #*.d

BINARY = program1 #the output
DIRECTION = /usr/local/bin

all: $(BINARY)

$(BINARY): $(OBJECTS)
	$(CC) -o $@ $^

#wildcard is %: each .o will create a .c
%.o: %.c
	$(CC) $(CFLAGS) $(DEPFLAGS) -c -o $@ $<

#include
-include $(DEPFILES)

install: $(BINARY)
	mkdir -p $(DIRECTION)
	cp $(BINARY) $(DIRECTION)/
	chmod +x $(DIRECTION)/$(BINARY)

uninstall:
	rm -f $(DIRECTION)/$(BINARY)

clean:
	rm -rf $(BINARY) $(OBJECTS) $(DEPFILES)
