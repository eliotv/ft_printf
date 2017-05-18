NAME = ft_printf.a

CFLAG = -Wall -Wextra -Werror -I

PFDR = src/

LFTDR = libft/

PFFL = build.c \
	   conversion.c \
	   flagmod.c \
	   ft_printf.c \
	   functionfinder.c \
	   lengthmod.c \
	   percisionmod.c \
	   widthmod.c

LFTFL = ft_strlen.c \
		ft_atoi.c \
		ft_putchar.c \
		ft_putstr.c \
		ft_itoa.c \
		ft_itoa_base.c \
		ft_toupper.c \
		ft_strjoin.c

PFSR = $(addprefix $(PFDR), $(PFFL))

LFSR = $(addprefix $(PFDR)$(LFTDR), $(LFTFL))

POBJ = $(PRSR:.c=.o)
LOBJ = $(LFSR:.c=.o)

all: $(NAME)

$(POBJ): %.o: %.c
	@gcc -c $(CFLAG) src/ $< -o $@

$(LOBJ): %.o: %.c
	gcc -c $(CFLAG) libft/ $< -o $@

$(NAME): $(POBJ) $(LOBJ)
	@ar rc $(NAME) $(POBJ) $(LOBJ)
	@echo "\033[32mft_printf Created\033[0m"

clean:
	@rm -rf $(PFDR)*.o
	@rm -rf $(LFTDR)*.o $(LFTDR)libft.a
	@echo "\033[31mft_printf Removed\033[0m"

fclean: clean
	@rm -rf $(NAME)
	@echo "\033[31mft_printf Removed\033[0m"

re: fclean all
