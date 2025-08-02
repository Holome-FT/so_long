# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: raamayri <raamayri@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/06/23 17:57:19 by raamayri          #+#    #+#              #
#    Updated: 2025/08/01 19:15:20 by raamayri         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC_FLAGS = -Wall -Wextra -Werror -g3 -MMD -MP

NAME = libft.a

SRCS = srcs/ft_isalpha.c \
	   srcs/ft_isdigit.c \
	   srcs/ft_isalnum.c \
	   srcs/ft_isascii.c \
	   srcs/ft_isprint.c \
	   srcs/ft_islower.c \
	   srcs/ft_isupper.c \
	   srcs/ft_isspace.c \
	   srcs/ft_strlen.c \
	   srcs/ft_memset.c \
	   srcs/ft_bzero.c \
	   srcs/ft_memcpy.c \
	   srcs/ft_memmove.c \
	   srcs/ft_strlcpy.c \
	   srcs/ft_strlcat.c \
	   srcs/ft_toupper.c \
	   srcs/ft_tolower.c \
	   srcs/ft_strchr.c \
	   srcs/ft_strrchr.c \
	   srcs/ft_strcmp.c \
	   srcs/ft_strncmp.c \
	   srcs/ft_memchr.c \
	   srcs/ft_memcmp.c \
	   srcs/ft_strnstr.c \
	   srcs/ft_atoi.c \
	   srcs/ft_calloc.c \
	   srcs/ft_strdup.c \
	   srcs/ft_substr.c \
	   srcs/ft_strjoin.c \
	   srcs/ft_strtrim.c \
	   srcs/ft_split.c \
	   srcs/ft_itoa.c \
	   srcs/ft_strmapi.c \
	   srcs/ft_striteri.c \
	   srcs/ft_putchar_fd.c \
	   srcs/ft_putstr_fd.c \
	   srcs/ft_putendl_fd.c \
	   srcs/ft_putnbr_fd.c \
	   srcs/get_next_line/get_next_line.c \
	   srcs/get_next_line/get_next_line_utils.c \
	   srcs/ft_printf/ft_printf.c \
	   srcs/ft_printf/ft_putchar_len.c \
	   srcs/ft_printf/ft_putstr_len.c \
	   srcs/ft_printf/ft_putnbr_len.c \
	   srcs/ft_printf/ft_putunbr_len.c \
	   srcs/ft_printf/ft_puthex_len.c \
	   srcs/ft_printf/ft_putptr_len.c \
	   srcs/ft_dprintf/ft_dprintf.c \
	   srcs/ft_dprintf/ft_dputchar_len.c \
	   srcs/ft_dprintf/ft_dputstr_len.c \
	   srcs/ft_dprintf/ft_dputnbr_len.c \
	   srcs/ft_dprintf/ft_dputunbr_len.c \
	   srcs/ft_dprintf/ft_dputhex_len.c \
	   srcs/ft_dprintf/ft_dputptr_len.c \
	   srcs/ft_sprintf/ft_sprintf.c \
	   srcs/ft_sprintf/ft_sputchar_len.c \
	   srcs/ft_sprintf/ft_sputstr_len.c \
	   srcs/ft_sprintf/ft_sputnbr_len.c \
	   srcs/ft_sprintf/ft_sputunbr_len.c \
	   srcs/ft_sprintf/ft_sputhex_len.c \
	   srcs/ft_sprintf/ft_sputptr_len.c
INCS = incs/
OBJS = $(patsubst srcs/%.c,objs/%.o,$(SRCS))
DEPS = $(patsubst objs/%.o,deps/%.d,$(OBJS))

-include $(DEPS)

all: $(NAME)

$(NAME): $(OBJS)
	ar -rcs $@ $^
	$(info [MAKE] $@ built successfully.)

objs/%.o: srcs/%.c
	mkdir -p $(sort $(dir $@) $(dir $(patsubst objs/%.o,deps/%.d,$@)))
	cc $(CC_FLAGS) -MF $(patsubst objs/%.o,deps/%.d,$@) $(addprefix -I,$(INCS)) -o $@ -c $<
	$(info [MAKE] $(addprefix $*, .c) compiled successfully.)

clean:
	rm -rf $(sort $(dir $(OBJS)) $(dir $(DEPS)))
	$(info [MAKE] $(NAME) cleaned successfully.)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
