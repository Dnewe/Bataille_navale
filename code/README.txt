

to use:

	make documentation  : generates doxygen 
	make clean			: removes compiled files (obj , main.o, program, doc, ...)
	make execute		: executes program with generated lib



change variable: (in cst_type_functions.h)

	size of board -> change constant SIZE	(default:10)
	
	number of boats ->  change MAX_LENGTH to desired max length of boats		(default:5)
						change P1_BOATS_COMPOSITION to change human player's boats composition		(default: {0,1,2,2,1}) <=> 0 boat size 1, 1 boat size 2, 2 boats size 3, 2 boats size 4, 1 boat size 5
						change P2_BOATS_COMPOSITION to change computer's boats composition			(default: {0,1,2,2,1})
						
						/!\: MAX_LENGTH must be equal to length of P1_BOATS_COMPOSITION and P2_BOATS_COMPOSITION
	
	

