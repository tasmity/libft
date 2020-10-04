SRC_PATH = src

SRC_NAME =	libft/ft_bzero.c      		\
			libft/ft_memccpy.c    		\
			libft/ft_memchr.c     		\
			libft/ft_memcmp.c     		\
			libft/ft_memcpy.c     		\
			libft/ft_memmove.c    		\
			libft/ft_memset.c     		\
			libft/ft_strlen.c     		\
			libft/ft_strdup.c     		\
			libft/ft_strcpy.c     		\
			libft/ft_strncpy.c    		\
			libft/ft_strcat.c     		\
			libft/ft_strncat.c    		\
			libft/ft_strlcat.c    		\
			libft/ft_strchr.c     		\
			libft/ft_strrchr.c    		\
			libft/ft_strstr.c     		\
			libft/ft_strnstr.c    		\
			libft/ft_strcmp.c     		\
			libft/ft_strncmp.c    		\
			libft/ft_atoi.c       		\
			libft/ft_isalpha.c    		\
			libft/ft_isdigit.c    		\
			libft/ft_isalnum.c    		\
			libft/ft_isascii.c    		\
			libft/ft_isprint.c    		\
			libft/ft_toupper.c    		\
			libft/ft_tolower.c    		\
			libft/ft_memalloc.c   		\
			libft/ft_memdel.c     		\
			libft/ft_strnew.c     		\
			libft/ft_strdel.c     		\
			libft/ft_strclr.c     		\
			libft/ft_striter.c    		\
			libft/ft_striteri.c   		\
			libft/ft_strmap.c     		\
			libft/ft_strmapi.c    		\
			libft/ft_strequ.c     		\
			libft/ft_strnequ.c    		\
			libft/ft_putchar_fd.c 		\
			libft/ft_putchar.c    		\
			libft/ft_putstr.c     		\
			libft/ft_putnbr.c     		\
			libft/ft_putstr_fd.c  		\
			libft/ft_putnbr_fd.c  		\
			libft/ft_putendl.c    		\
			libft/ft_putendl_fd.c 		\
			libft/ft_itoa.c       		\
			libft/ft_strsub.c     		\
			libft/ft_strjoin.c    		\
			libft/ft_strtrim.c    		\
			libft/ft_strsplit.c   		\
			libft/ft_lstnew.c     		\
			libft/ft_lstdelone.c  		\
			libft/ft_lstdel.c     		\
			libft/ft_lstadd.c     		\
			libft/ft_lstiter.c    		\
			libft/ft_lstmap.c     		\
			libft/ft_intlen.c     		\
			libft/ft_lstfree.c			\
			gnl/get_next_line.c 		\
			ft_printf/ft_printf.c 		\
			ft_printf/ft_initialize.c 	\
			ft_printf/ft_attribut.c 	\
			ft_printf/ft_print_s.c 		\
			ft_printf/ft_print_all.c 	\
			ft_printf/ft_print_c.c 		\
			ft_printf/ft_digit_nbr.c 	\
			ft_printf/ft_print_d.c 		\
			ft_printf/ft_put_num.c 		\
			ft_printf/ft_print_u.c 		\
			ft_printf/ft_find_f.c 		\
			ft_printf/ft_long_arifm_f.c	\
			ft_printf/ft_nan_f.c 		\
			ft_printf/ft_other_f.c 		\
			ft_printf/ft_presicion_f.c 	\
			ft_printf/ft_print_f.c		\
			ft_printf/ft_helpdrop_f.c	\

INCFLAGS = -I includes

FLAGS = -Wall -Wextra -Werror

OBJ_NAME = $(SRC_NAME:.c=.o)

MDF_NAME += $(SRC_NAME:.c=.d)

OBJ_PATH = obj

DEPS =		includes/libft.h			\
			includes/get_next_line.h	\
			includes/ft_printf.h		\

NAME = libft.a

SRC = $(addprefix $(SRC_PATH)/,$(SRC_NAME))

OBJ = $(addprefix $(OBJ_PATH)/,$(OBJ_NAME))

all: $(NAME)

$(NAME): $(OBJ)
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)
	@echo "\nCreating $@"

$(OBJ_PATH)/%.o: $(SRC_PATH)/%.c $(DEPS)
	@mkdir -p $(OBJ_PATH)
	@mkdir -p $(dir $(OBJ))
	@gcc $(FLAGS) -o $@ -c  -MD $< $(INCFLAGS)
	@echo "#" | tr -d '\n'

clean:
	@rm -rf $(OBJ_PATH)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
