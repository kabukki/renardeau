BIN	=	renardeau

SRC	=	src/main.cpp		\
		src/Color.cpp		\
		src/Word.cpp		\
		src/Solver.cpp
OBJ	=	$(SRC:.cpp=.o)

INC	=	-I include
LIB	=

CXXFLAGS	=	-g -W -Wall -Wextra
CC			=	g++ $(CXXFLAGS)
RM			=	rm -rf

# Linking
$(BIN):	$(OBJ)
	$(CC) $^ $(INC) $(LIB) -o $@

# Compilation
%.o:	%.cpp
	$(CC) -c $< $(INC) -o $@

# Extra rules
all:	$(BIN)

clean:
	$(RM) $(OBJ)
fclean:	clean
	$(RM) $(BIN)
re: fclean all

.PHONY:	$(BIN)
