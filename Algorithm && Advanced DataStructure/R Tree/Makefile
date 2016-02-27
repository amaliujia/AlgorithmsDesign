# top-level Makefile for Deferred-split R-tree (DR)
#.IGNORE:

demo: spotless all
	bin/DRmain -d 2 < input.tiny

alltests: demo mytest hw2

hw2: spotless all
	bin/DRmain -d 2 < input.hw2

mytest: spotless all
	bin/DRmain -d 2 < input.tiny2

# Make all or clean...
all clean:
		cd libsrc/src; make $@
		cd binsrc; make $@

spotless: clean
	\rm -f default.idx
	\rm -f bin/DRmain
	\rm -f lib/libdr.a

# Make binary only...
binary:
		cd binsrc; make clean; make all

# Make library only...
library:
		cd libsrc/src; make clean; make all

# Make tar...
tar:
		tar cvFFf ../DRtree.tar .

