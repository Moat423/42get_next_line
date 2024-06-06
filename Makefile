# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lmeubrin <lmeubrin@student.42berlin.       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/22 15:55:27 by lmeubrin          #+#    #+#              #
#    Updated: 2024/05/22 17:14:21 by lmeubrin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SHELL = /bin/bash
MAKEFLAGS += --warn-undefined-variables
.ONESHELL:
LIB = ar
LIBFLAGS = -rcs
CC = cc
CFLAGS = -Werror -Wall -Wextra -g -I.
NAME = a.out
BONUS = bonus.out

MAIN = main.c

BUILD_DIR = ./objs

SRC_DIR = .

DEPS = get_next_line.h

SRCS = get_next_line.c \
		get_next_line_utils.c

OBJS := $(SRCS:%.c=$(BUILD_DIR)/%.o)

BONUS_DEPS = get_next_line_bonus.h

BONUS_SRCS = 	get_next_line_bonus.c \
				get_next_line_utils_bonus.c

BONUS_OBJS = $(BONUS_SRCS:%.c=$(BUILD_DIR)/%.o) $(MAIN:main.c=$(BUILD_DIR)/main.o)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

$(BUILD_DIR)/%.o: %.c $(DEPS)
	mkdir -p objs
	$(CC) -c $< $(MAIN) $(CFLAGS) -o $@

bonus: $(BONUS_OBJS)
	$(CC) $(CFLAGS) $(BONUS_OBJS) -o $(BONUS)

$(BUILD_DIR)/%_bonus.o: %_bonus.c $(BONUS_DEPS)
	mkdir -p objs
	$(CC) $(CFLAGS) -c $< -o $@ $(MAIN)

$(OBJS): $(SRCS)

$(BONUS_OBJS): $(BONUS_SRCS)

all: $(NAME)

clean:
	rm -dRf $(BUILD_DIR)

fclean: clean
	rm -f $(NAME)
	rm -f $(BONUS)

re: fclean all


.PHONY: all, clean, fclean, re, bonus
