
# AUTHOR: Di Jin and Christos Faloutsos
# DATE: Jan. 2016

FNAME=hcurve

all: plot

hw2: all

$(FNAME): $(FNAME).c
	gcc -o $(FNAME) $(FNAME).c -lm

plot: $(FNAME)
	@echo ""
	@echo "... running $(FNAME) "
	./$(FNAME) -n 6
	gnuplot < cmd.plt
	@echo "... output is in hcurve.png"

clean:
	\rm -f *.png
	\rm -f $(FNAME)

spotless: clean
