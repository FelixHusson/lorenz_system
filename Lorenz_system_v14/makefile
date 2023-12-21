CC =  gcc -g
CFLAGS =  -Wall -Wextra
IFLAGS = -I $(H_LINEALG_DIR) -I $(H_DIR) 
LFLAGS = -L/linealg/libs -L/libs -lm


O_DIR = obj/
EXEC_DIR = exec/
SRC_DIR = src/
H_DIR = include/
H_LINEALG_DIR = linealg/include/
L_DIR = libs/
LINEALG_DIR = linealg/
LINEALG_LIBS = linealg/libs/

SRC = $(wildcard $(SRC_DIR)*.c)
OBJ = $(patsubst $(SRC_DIR)%.c, $(O_DIR)%.o,$(SRC))
EXEC = exec/main



default : $(EXEC)

$(shell mkdir -p obj)
$(shell mkdir -p libs)

$(EXEC) : $(OBJ) 
	@$(MAKE) --directory=$(LINEALG_DIR)
	@ar -crs $(L_DIR)function.a $(O_DIR)*.o 
	@ar -crs $(L_DIR)library.a linealg/obj/*.o
	@$(shell mkdir -p exec)
	$(CC) $(CFLAGS)  -o $@ $^ linealg/obj/*.o $(LFLAGS) $(IFLAGS)


$(OBJ) : $(O_DIR)%.o : $(SRC_DIR)%.c
	@$(CC) $(CFLAGS) -c $^ -o $@ $(IFLAGS)

test : obj/test.o
	$(CC) $(CFLAGS) -o $@ $^ $(IFLAGS)

.PHONY : clean clear_all

data_clear :
	rm -rf implicite.txt
	rm -rf implicite_v2.txt
	rm -rf explicite.txt
	rm -rf explicite_v2.txt
	rm -rf RK4.txt
	rm -rf RK4_v2.txt
	rm -rf vitesse_convergence/vitesse_explicite.txt
	rm -rf vitesse_convergence/vitesse_implicite.txt
	rm -rf vitesse_convergence/vitesse_RK4.txt

clean : 
	rm -rf obj
	rm -rf libs
	@rm -rf *.exe
	@rm -rf exec
	@rm -rf *.o
	@rm -rf *.a
	@$(MAKE) --directory=$(LINEALG_DIR) clean
	@rm -rf main.exe.stackdump

clear_all : clean
	rm -rf $(EXEC)