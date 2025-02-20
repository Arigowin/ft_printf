# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dolewski <dolewski@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/11/23 13:01:21 by dolewski          #+#    #+#              #
#    Updated: 2019/06/12 09:51:07 by dolewski         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

CC =	/usr/bin/clang
RM =	/bin/rm
MAKE =	/usr/bin/make
MKDIR =	/bin/mkdir
AR =	/usr/bin/ar
RANLIB = /usr/bin/ranlib

SRC = ft_memalloc.c \
	  ft_memccpy.c \
	  ft_memchr.c \
	  ft_memcmp.c \
	  ft_memcpy.c \
	  ft_memdel.c \
	  ft_memmove.c \
	  ft_memset.c \
	  \
	  ft_strlen.c \
	  ft_strdup.c \
	  ft_strcpy.c \
	  ft_strncpy.c \
	  ft_strcat.c \
	  ft_strncat.c \
	  ft_strlcat.c \
	  ft_strchr.c \
	  ft_strrchr.c \
	  ft_strstr.c \
	  ft_strnstr.c \
	  ft_strcmp.c \
	  ft_strncmp.c \
	  ft_strnew.c \
	  ft_strdel.c \
	  ft_strclr.c \
	  ft_striter.c \
	  ft_striteri.c \
	  ft_strmap.c \
	  ft_strmapi.c \
	  ft_strequ.c \
	  ft_strnequ.c \
	  ft_strsub.c \
	  ft_strjoin.c \
	  ft_strproperjoin.c \
	  ft_strtrim.c \
	  ft_strsplit.c \
	  ft_strproperjoin.c \
	   \
	  ft_isalpha.c \
	  ft_isdigit.c \
	  ft_isalnum.c \
	  ft_isascii.c \
	  ft_isprint.c \
	  \
	  ft_toupper.c \
	  ft_tolower.c \
	  \
	  ft_putchar.c \
	  ft_putstr.c \
	  ft_putendl.c \
	  ft_putnbr.c \
	  ft_putchar_fd.c \
	  ft_putstr_fd.c \
	  ft_putendl_fd.c \
	  ft_putnbr_fd.c \
	  ft_putnbrendl.c \
	  ft_putchar_color.c \
	  ft_putstr_color.c \
	  ft_putnbr_color.c \
	  \
	  ft_lstnew.c \
	  ft_lstdelone.c \
	  ft_lstdel.c \
	  ft_lstadd.c \
	  ft_lstiter.c \
	  ft_lstmap.c \
	  ft_lstcount.c \
	  ft_lstpushback.c \
	  \
	  ft_atoi.c \
	  ft_atoh.c \
	  ft_splittolst.c \
	  ft_free_tbl_s.c \
	  ft_bzero.c \
	  ft_itoa_base.c \
	  ft_itoa.c \
	  ft_copyt2d.c \
	  str_toupper.c \
	  ft_strncount.c \
	  ft_get_index.c \
	  get_next_line.c

OBJ = $(patsubst %.c, $(OPATH)/%.o, $(SRC))

CFLAGS = -Wall -Wextra -Werror -I $(HPATH)

ROOT =		$(shell /bin/pwd)
OPATH =		$(ROOT)/objs
CPATH =		$(ROOT)/srcs
HPATH =		$(ROOT)/includes

.PHONY: all clean fclean re

all: $(OPATH) $(NAME)

$(NAME): $(OPATH) $(OBJ)
	@echo "$(NAME) : Building $@"
	@$(AR) rc $@ $(OBJ)
	@$(RANLIB) $@
	@echo "\033[32mDone !\033[0m"

$(OPATH)/%.o: $(CPATH)/%.c
	@echo "$(NAME) : Creating file $@"
	@$(CC) $(CFLAGS) -c $< -o $@

$(OPATH):
	@echo "$(NAME) : Creating objs directory"
	@$(MKDIR) $@

clean:
	@echo "$(NAME) : Deleting objs"
	@$(RM) -Rf $(OPATH)

fclean: clean
	@echo "$(NAME) : Deleting $(NAME)"
	@$(RM) -f $(NAME)
	@echo "\033[32mDone !\033[0m"

re: fclean all

