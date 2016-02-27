
# AUTHOR: Di Jin and Christos Faloutsos
# DATE: Jan. 2016

SRC= zmirror2.c

all: q2_2 plot

hw2: all

compile: $(SRC) $(HFILES)
	gcc -o zmirror2 zmirror2.c -lm
	gcc -o draw_curve draw_curve.c -lm

q2_2: compile
	@echo ""
	@echo "  Q2.2: output for q2.input.txt"
	@./q2.sh

plot: compile
	@echo ""
	@echo "  Q2.3: creating the z-curve"
	@echo "        by running zmirror2 (actually, sub-routines of it ...) "
	@./draw_curve
	gnuplot < cmd.plt
	@echo "IMPORTANT: output is in file zcurve.png "

clean:
	\rm -f zmirror2 *.png

spotless: clean
