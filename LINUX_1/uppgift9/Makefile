all: electrotest-standalone

electrotest-standalone: electrotest-standalone.c
	$(CC) -o electrotest-standalone electrotest-standalone.c -lm

install: electrotest-standalone
	install -m 755 electrotest-standalone $(DESTDIR)/usr/bin/
