PACKAGE= kdtree1_1
MAIN= ./main
CFLAGS=-g -ansi -pedantic -DNDEBUG
# -Wno-error=unused-command-line-argument
# -DDEBUG # -DNDEBUG
SRC= kdtree.c vector.c linear_heap.c
OBJ= kdtree.o vector.o linear_heap.o
SRCALL= $(MAIN).c $(SRC)
ALLH= dfn.h kdtree.h vector.h linear_heap.h
CC= gcc
SCRIPTS= input.script inp-large.script 2d-input.txt 3d-input.txt
COPYRIGHT= COPYRIGHT
REV=
.IGNORE:
# .SILENT:
LPR= lpr

compile: $(MAIN)
	@echo "**** Compile ***"
	$(MAIN)

demo: $(MAIN) input.script
	@echo "**** DEMO ***"
	$(MAIN) -d 4 < input.script

hw2: $(MAIN) 2d-input.txt 3d-input.txt
	echo "**** HW2 - 2d case *** "
	$(MAIN) -d 2 < 2d-input.txt
	echo "**** HW2 - 3d case *** "
	$(MAIN) -d 3 < 3d-input.txt

largedemo: $(MAIN) inp-large.script
	echo " ***large demo***"
	$(MAIN) -d 2 < inp-large.script

$(MAIN): $(MAIN).o $(OBJ)
	$(CC) $(CFLAGS) -o $(MAIN) $(MAIN).o $(OBJ) -lm

p$(MAIN): $(MAIN).o $(OBJ)
	purify $(CC) $(CFLAGS) -o $(MAIN) $(MAIN).o $(OBJ) -lm

vector.o: dfn.h vector.h

linear_heap.o: dfn.h vector.h linear_heap.h

kdtree.o: dfn.h kdtree.h linear_heap.h vector.h

$(MAIN).o: dfn.h kdtree.h vector.h kdtree.c linear_heap.h

checkout:
	co -l $(REV) $(SRCALL) $(ALLH) README

checkin:
	ci -l $(REV)  -f $(SRCALL) $(ALLH) README

cleanup:
	rm -f $(OBJ) $(MAIN).o core
	rm -f *~ *.bak

clean: cleanup

spotless: clean
	rm -f $(MAIN) $(PACKAGE).bundle $(PACKAGE).tar* uu *.exe

$(PACKAGE).tar: $(SRCALL) $(ALLH) README makefile \
	$(SCRIPTS) $(COPYRIGHT)
	tar cvfh $(PACKAGE).tar $(SRCALL) $(ALLH) \
	$(SCRIPTS) README makefile $(COPYRIGHT)

printout: $(SRCALL) $(ALLH)
	$(LPR) $(SRCALL) $(ALLH)

# uu: $(PACKAGE).tar
#  	gzip $(PACKAGE).tar
# 	uuencode $(PACKAGE).tar.gz $(PACKAGE).tar.gz > uu
