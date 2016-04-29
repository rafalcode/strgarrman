CC=gcc
CFLAGS=-g -Wall
EXES=bi ac2 ac3 rp0 fstr


# Ancillary programs ... usually just for testing some ideas.
bi: bi.c
	${CC} ${CFLAGS} -o $@ $^

fstr: fstr.c
	${CC} ${CFLAGS} -o $@ $^

ac2: ac2.c
	${CC} ${CFLAGS} -o $@ $^

ac3: ac3.c
	${CC} ${CFLAGS} -o $@ $^

.PHONY: clean

clean:
	rm -f ${EXES}
