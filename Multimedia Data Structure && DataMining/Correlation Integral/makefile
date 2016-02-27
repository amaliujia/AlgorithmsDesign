#####################################
# Author: christos faloutsos
# Date: Feb. 2016
# USAGE:  
#	'make' should create the output for HW3-Q1
#	'make sanity-check' should be empty
#####################################

FNAME= mystery.inp
FNAME_1= mystery_t1.inp
FNAME_50= mystery_t50.inp

# top: secret

hw3: plot_t1 plot_t50


demo:
	python q1.py

plot_t1:
	python get-timetick.py $(FNAME) 1 >> $(FNAME_1)
	python q1.py $(FNAME_1)

plot_t50:
	python get-timetick.py $(FNAME) 50 >> $(FNAME_50)
	python q1.py $(FNAME_50)

clean:
	\rm -rf $(FNAME_1) $(FNAME_50)

spotless: clean

#####################################################################
##### to 15-826 students: below this line, is for instructor/TA use
#####################################################################

secret: secret-t1 secret-t50

secret-t1:
	python get-timetick.py $(FNAME) 1 >> $(FNAME_1)
	python q1-solution.py $(FNAME_1)

secret-t50:
	python get-timetick.py $(FNAME) 50 >> $(FNAME_50)
	python q1-solution.py $(FNAME_50)
