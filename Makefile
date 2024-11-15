NAME        := push_swap

#------------------------------------------------#
#   INGREDIENTS                                  #
#------------------------------------------------#
# SRC_DIR   source directory
# OBJ_DIR   object directory
# SRCS      source files
# OBJS      object files
#
# CC        compiler
# CFLAGS    compiler flags
# CPPFLAGS  preprocessor flags

INCLUDE		:= push_swap.h
LIBFT		:= src/libft_/libft.a
PRINTF		:= src/printf_/libftprintf.a
SRCS        := \
			src/operations/operations_push.c \
			src/operations/operations_rev_rotate.c \
			src/operations/operations_rotate.c \
			src/operations/operations_swap.c \
			src/sort/calculate_target.c \
			src/sort/calculate_cheap.c \
			src/sort/generate_moves.c \
			src/sort/get_min_to_top.c \
			src/sort/move_target.c \
			src/sort/move_target_aux.c \
			src/sort/sort_big.c \
			src/sort/sort_two_five.c \
			src/error_control/error_checks.c \
			src/error_control/error_control_argv.c \
			src/error_control/error_control_str.c \
			src/initialization/ini.c \
			src/initialization/main.c \
			src/utils/ps_free.c \
			src/utils/ps_utils.c \

OBJS        := $(SRCS:.c=.o)
CC          := cc
CFLAGS      := -Wall -Wextra -Werror

GREEN = \033[1;32m
RED = \033[1;31m
YELLOW = \033[1;33m
RESET = \033[0m

all: $(NAME)

$(NAME): $(OBJS) $(INCLUDE)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) $(PRINTF) -o $(NAME)
	@echo "${GREEN}Push_swap compilation OK${RESET}"
	
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	-rm -f $(OBJS)
	@echo "${YELLOW}All objects removed${RESET}"

fclean: clean
	-rm -f $(NAME)
	@echo "${RED}Push_swap removed${RESET}"

re: fclean all

.PHONY: clean fclean re all
