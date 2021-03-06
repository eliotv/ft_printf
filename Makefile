NAME = libftprintf.a

CFLAGS = -Wall -Wextra -Werror -g -I

PFDR = src/

LFTDR = libft/

PFFL = build.c \
	   conversion.c \
	   conversion2.c \
	   flagmod.c \
	   ft_printf.c \
	   functionfinder.c \
	   lengthmod.c \
	   percisionmod.c \
	   widthmod.c \
	   print.c \
	   print2.c

LFTFL = ft_strlen.c \
		ft_atoi.c \
		ft_putchar.c \
		ft_putstr.c \
		ft_itoa.c \
		ft_itoa_base.c \
		ft_toupper.c \
		ft_strjoin.c \
		ft_count_int_len.c \
		ft_memalloc.c \
		ft_isspace.c \
		ft_bzero.c \
		ft_u_itoa_bs.c \
		ft_strcmp.c \
		ft_strndup.c \
		ft_count_unint_len.c \
		ft_strnew.c \
		ft_strcat.c \
		ft_strncpy.c \
		ft_strdel.c \
		ft_strdup.c

PFSR = $(addprefix $(PFDR), $(PFFL))

LFSR = $(addprefix $(LFTDR), $(LFTFL))

POBJ = $(PFSR:.c=.o)
LOBJ = $(LFSR:.c=.o)

all: $(NAME)

$(POBJ): %.o: %.c
	@gcc -c $(CFLAGS) $(PFDR) $< -o $@

$(LOBJ): %.o: %.c
	gcc -c $(CFLAGS) $(LFTDR) $< -o $@

$(NAME): $(POBJ) $(LOBJ)
	@ar rcs $(NAME) $(POBJ) $(LOBJ)
	@echo "\033[32mft_printf Created\033[0m"

clean:
	@rm -rf $(LOBJ)
	@rm -rf $(POBJ)
	@echo "\033[31mft_printf Removed\033[0m"

fclean: clean
	@rm -rf $(NAME)
	@echo "\033[31mft_printf Removed\033[0m"

re: fclean all
