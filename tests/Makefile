CC						=				gcc

NAME					=				unit_tests
SRC						=				../asm/src/endian_handling.c					\
										../asm/src/bytes_tab_tools.c					\
										../asm/src/offset_calculation.c					\
										../asm/src/headers.c							\
										../asm/src/get_params_values.c					\
										../asm/src/instruction.c						\
										../asm/src/instruction/basic.c					\
										../asm/src/instruction/jump.c					\
										../asm/src/instruction/operator.c				\
										../asm/src/parser/parser.c						\
										../asm/utils/read_file.c						\
										../asm/utils/str_begin.c						\
										src/test_get_coding_byte.c						\
										src/test_get_register.c							\
										src/test_get_params.c							\

OBJ                     =       		$(SRC:%.c=%.o)

INCLUDE         		= 		      	-I ../include/
CFLAGS         			=       		$(INCLUDE) $(LIB) -L ../lib -lmy -lcriterion

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

debug:			$(CFLAGS)+=-g
debug:			re