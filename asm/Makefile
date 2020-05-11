CC						=				gcc

NAME					=				asm
SRC						=				src/main.c								\
										src/endian_handling.c					\
										src/get_params_values.c					\
										src/instruction.c						\
										src/instruction/basic.c					\
										src/instruction/jump.c					\
										src/parser/parser.c						\
										utils/read_file.c						\
										utils/str_begin.c

OBJ                     =       		$(SRC:%.c=%.o)

INCLUDE         		= 		      	-I ../include/
CFLAGS         			=       		$(INCLUDE) $(LIB) -g -L ../lib -lmy

all:                    $(NAME)
$(NAME):                $(OBJ)
						$(MAKE) -C ../lib/
						$(CC) -o $(NAME) $(OBJ) $(CFLAGS)
clean:
						$(MAKE) -C ../lib/ clean
						rm -rf $(OBJ) $(OBJTESTS)
fclean:                 clean
						$(MAKE) -C ../lib/ fclean
						rm -rf $(NAME) $(TNAME)
re:                     fclean all
test_run:
						$(MAKE) -C tests