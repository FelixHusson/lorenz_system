CC =  gcc -g
CFLAGS = -W -Wall -Wextra
IFLAGS = -I $(H_DIR)
LFLAGS = -L/libs -lm

O_DIR = obj/
EXEC_DIR = exec/
SRC_DIR = src/
H_DIR = include/
L_DIR = libs/



SRC = $(filter-out $(SRC_DIR)/main.c, $(wildcard $(SRC_DIR)*.c))
OBJ = $(patsubst $(SRC_DIR)%.c, $(O_DIR)%.o,$(SRC))

EXEC = test

default : linealg


$(shell mkdir -p obj)
$(shell mkdir -p libs)



linealg : $(OBJ)
	@ar -crs $(L_DIR)linealg.a $(O_DIR)matrix_tools.o $(O_DIR)matrix_sparse_tools.o $(O_DIR)matrix_stockage.o
	@ar -crs $(L_DIR)linear_solve.a $(O_DIR)Gauss.o $(O_DIR)Gauss_Seidel.o $(O_DIR)SOR.o $(O_DIR)Jacobi.o $(O_DIR)solvers_tools.o 


$(OBJ) : $(O_DIR)%.o : $(SRC_DIR)%.c
	@$(CC) $(CFLAGS) -c $^ -o $@ $(IFLAGS)

$(EXEC) : $(OBJ) $(O_DIR)main.o
	@ar -crs $(L_DIR)linealg.a $(O_DIR)matrix_tools.o $(O_DIR)matrix_sparse_tools.o $(O_DIR)matrix_stockage.o
	@ar -crs $(L_DIR)linear_solve.a $(O_DIR)Gauss.o $(O_DIR)Gauss_Seidel.o $(O_DIR)SOR.o $(O_DIR)Jacobi.o $(O_DIR)solvers_tools.o 
	@$(shell mkdir -p exec)
	@$(CC) $(CFLAGS) -o $(EXEC_DIR)$@ $^ $(LFLAGS)


$(O_DIR)main.o : test/main.c
	$(CC) $(CFLAGS) -c  $^ -o $(O_DIR)main.o $(IFLAGS)

.PHONY : clean clear_all

clean : 
	rm -rf obj
	rm -rf libs
	rm -rf exec
	@rm -rf *.o
	@rm -rf *.a 

clear_all : clean
	rm -rf $(EXEC)