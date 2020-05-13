CC						=				gcc

NAME					=				corewar
SRC						=				src/main.c								\
										src/register.c							\
										src/vm.c								\
										src/loop.c								\
										src/utils/read_file.c					\
										src/utils/str_begin.c

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