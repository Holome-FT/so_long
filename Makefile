# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: raamayri <raamayri@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/05/29 18:33:52 by raamayri          #+#    #+#              #
#    Updated: 2025/08/04 13:48:36 by raamayri         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC_FLAGS = -Wall -Wextra -Werror -g3 -MMD -MP
MK_FLAGS = --silent
MAKEFLAGS += $(MK_FLAGS)

NAME = so_long
LBFT = Libft/libft.a
MLBX = minilibx-linux/libmlx.a

SRCS = srcs/main.c \
	srcs/flags.c \
	srcs/maps_1.c \
	srcs/maps_2.c \
	srcs/checker_1.c \
	srcs/checker_2.c \
	srcs/game.c \
	srcs/free.c \
	srcs/error.c \
	srcs/draw_ghosts.c \
	srcs/draw_other.c \
	srcs/draw_pacman.c \
	srcs/draw_walls.c \
	srcs/draw.c \
	srcs/game_calc.c \
	srcs/game_utils_1.c \
	srcs/game_utils_2.c \
	srcs/mlx.c \
	srcs/game_calc_player.c \
	srcs/game_calc_ghosts.c \
	srcs/game_calc_ghosts_moves.c \
	srcs/game_calc_blinky.c \
	srcs/game_calc_pinky.c \
	srcs/game_calc_inky.c \
	srcs/game_calc_clyde.c \
	srcs/game_bfs_1.c \
	srcs/game_bfs_2.c \
	srcs/game_calc_other.c \
	srcs/game_over.c \
	srcs/debug.c
INCS = incs/ \
	Libft/incs/ \
	minilibx-linux/
OBJS = $(patsubst srcs/%.c, objs/%.o, $(SRCS))
DEPS = $(patsubst objs/%.o, deps/%.d, $(OBJS))

.PHONY: all clean fclean re

ifneq ($(shell uname -s), Linux)
    $(error Error: This project can only be built on Linux)
endif

ifneq ($(shell test -d minilibx-linux && echo found), found)
    $(error Error: This project depends on 'minilibx-linux/')
endif

all: $(NAME)

$(NAME): $(OBJS) $(LBFT) $(MLBX)
	cc $(CC_FLAGS) -o $@ $^ -lX11 -lXext
	$(info [MAKE] $@ built successfully.)

objs/%.o: srcs/%.c
	mkdir -p $(sort $(dir $@) $(dir $(patsubst objs/%.o, deps/%.d, $@)))
	cc $(CC_FLAGS) -MF $(patsubst objs/%.o, deps/%.d, $@) $(addprefix -I, $(INCS)) -o $@ -c $<
	$(info [MAKE] $(addprefix $*, .c) compiled successfully.)

$(LBFT):
	$(MAKE) $(MK_FLAGS) -C $(dir $@) 1> /dev/null
	$(info [MAKE] $(dir $@) compiled successfully.)

$(MLBX):
	$(MAKE) $(MK_FLAGS) -C $(dir $@) 1> /dev/null 2> /dev/null
	$(info [MAKE] $(dir $@) compiled successfully.)

clean:
	rm -rf $(sort $(dir $(OBJS)) $(dir $(DEPS)))
	$(MAKE) $(MK_FLAGS) -C $(dir $(LBFT)) $@ 1> /dev/null
	-$(MAKE) $(MK_FLAGS) -C $(dir $(MLBX)) $@ 1> /dev/null 2> /dev/null
	$(info [MAKE] $(NAME) cleaned successfully.)

fclean: clean
	rm -rf $(NAME) $(LBFT) $(MLBX)

re: fclean all

-include $(DEPS)
