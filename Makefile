CC						=				gcc

all:
						$(MAKE) -C asm/
clean:
						$(MAKE) -C asm/ clean
fclean:                 clean
						$(MAKE) -C asm/ fclean
re:                     fclean all