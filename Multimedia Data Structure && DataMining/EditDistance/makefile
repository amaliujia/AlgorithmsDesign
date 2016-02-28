#####################################
# Author: Christos Faloutsos
# Date: Feb. 2016
# USAGE:  
#	'make' should create the output for HW3-Q3
#	'make sanity-check' should be empty
#####################################

HAND_IN= q3-hand-in.txt

hw3: $(HAND_IN)
	@echo ""
	@echo "**********************************************"
	@echo "*** Q3: REMEMBER to 'make sanity-check' ***** "
	@echo "**********************************************"
	@echo ""

demo:
	python edit_distance.py bla blu

sanity-check:
	@echo "output format is IMPORTANT"
	@echo -e "\033[0;31m" starting $@  "\033[0m"
	python edit_distance.py `cat sample-input.txt` > my-output.txt
	@diff sample-output.txt my-output.txt
	@echo -e "\033[0;31m" passed $@  "\033[0m"

$(HAND_IN):
	\rm -f $(HAND_IN)
	@echo ""
	@echo " *** Writing results in $(HAND_IN) ..."
	python edit_distance.py abababab ddddddddd >> $(HAND_IN)
	python edit_distance.py receive recieve >> $(HAND_IN)
	python edit_distance.py blank bland >> $(HAND_IN)
	python edit_distance.py blank brandy >> $(HAND_IN)
	@echo " *** DONE          with $(HAND_IN) ..."
	@echo ""

clean:
	\rm -f my-output.txt

spotless: clean
	\rm -f $(HAND_IN)

####################################################################
##### to 15-816 students: below this line, is for instructor/TA use
####################################################################

Q3SOL= q3-solution.py
CORRECT= correct_output.txt

sample-output.txt: sample-input.txt
	python $(Q3SOL) `cat sample-input.txt` > sample-output.txt

secret:
	python $(Q3SOL)  bla blu

autograde:
	\rm -f $(CORRECT)
	python $(Q3SOL)  abababab ddddddddd >> $(CORRECT)
	python $(Q3SOL)  receive recieve >> $(CORRECT)
	python $(Q3SOL)  blank bland >> $(CORRECT)
	python $(Q3SOL)  blank brandy >> $(CORRECT)
	@echo -e "\033[0;31m" starting $@  "\033[0m"
	diff $(CORRECT) $(HAND_IN)
	@echo -e "\033[0;31m" $@  passed "\033[0m"


my-sanity-check:
	python $(Q3SOL)  `cat sample-input.txt` > my-output.txt
	@diff sample-output.txt my-output.txt

myclean:
	\rm -f $(CORRECT)

myspotless: myclean
