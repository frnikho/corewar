CC						=				gcc

all:
						$(MAKE) -C asm/
						$(MAKE) -C corewar/
clean:
						$(MAKE) -C asm/ clean
						$(MAKE) -C corewar/ clean
fclean:                 clean
						$(MAKE) -C asm/ fclean
						$(MAKE) -C corewar/ fclean
re:                     fclean all

debug:
						$(MAKE) -C asm/ debug
						$(MAKE) -C corewar/ debug
test_run:
						$(MAKE) -C tests
						./tests/unit_tests