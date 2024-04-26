# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tanselmo <tanselmo@student.42malaga.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/01 12:49:51 by tanselmo          #+#    #+#              #
#    Updated: 2024/04/26 13:58:06 by tanselmo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

LIBFT_DIR = Libft/

LIBFT = libft.a

SRCS_DIR = src

OBJ_DIR = obj

OBJ_DIR_BONUS = obj_bonus

SRCS_DIR_BONUS = bonus

FILES = src/pipex.c \
src/main.c \
src/utils.c \
src/error.c \
src/command.c \
src/utils_command.c \

FILES_BONUS = bonus/pipex_bonus.c \
bonus/utils_bonus.c \
bonus/error_bonus.c \
bonus/files_bonus.c \
bonus/close_bonus.c \
bonus/command_bonus.c \
bonus/utils_command_bonus.c \
bonus/here_doc_bonus.c \
bonus/duplicate_bonus.c \
bonus/main_bonus.c \

CC = gcc

CFLAGS = -g -Wall -Werror -Wextra

OBJS_SRCS = $(patsubst %.c, $(OBJ_DIR)/%.o, $(FILES))

OBJS_SRCS_BONUS = $(patsubst %.c, $(OBJ_DIR_BONUS)/%.o, $(FILES_BONUS))

NAME = pipex

NAME_BONUS = pipex_bonus

INCLUDE = -I $(SRCS_DIR) -I $(LIBFT_DIR) -I $(SRCS_DIR_BONUS)

RM = rm -rf

all: $(NAME)

$(OBJ_DIR)/%.o: %.c
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

$(OBJ_DIR_BONUS)/%.o: %.c
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

#Rules

$(NAME): $(OBJS_SRCS)
	@$(MAKE) -s all bonus printf gnl -C $(LIBFT_DIR)
	@$(CC) $(INCLUDE) $(OBJS_SRCS) -L$(LIBFT_DIR) -lft -o $(NAME)

bonus: $(NAME_BONUS)
$(NAME_BONUS): $(OBJS_SRCS_BONUS)
	@$(MAKE) -s all bonus printf gnl -C $(LIBFT_DIR)
	@$(CC) $(INCLUDE) $(OBJS_SRCS_BONUS) -L$(LIBFT_DIR) -lft -o $(NAME_BONUS)

clean:
	@$(RM) $(OBJ_DIR) $(OBJ_DIR_BONUS)
	@$(MAKE) -s -C $(LIBFT_DIR) clean

fclean: clean
	@$(RM) $(NAME) $(NAME_BONUS)
	@$(MAKE) -s -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re bonus