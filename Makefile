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

SRC_DIR     := src
OBJ_DIR     := obj
LIBFT_DIR   := src/libft
PRINTF_DIR  := src/printf
SRCS        := \
			operations/operations_push.c \
			operations/operations_rev_rotate.c \
			operations/operations_rotate.c \
			operations/operations_swap.c \
			sort/calculate_target.c \
			sort/sort_big.c \
			sort/sort_two_five.c \
			error_control/error_control_more.c \
			error_control/error_control_str.c \
			initialization/ini.c \
			initialization/main.c \

SRCS        := $(SRCS:%=$(SRC_DIR)/%)
OBJS        := $(SRCS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)
LIBFT       := $(LIBFT_DIR)/libft.a
PRINTF       := $(PRINTF_DIR)/libftprintf.a

CC          := cc
CFLAGS      := -Wall -Wextra -Werror
CPPFLAGS    := -I $(LIBFT_DIR) -I $(PRINTF_DIR)


#------------------------------------------------#
#   UTENSILS                                     #
#------------------------------------------------#
# RM        force remove
# MAKEFLAGS make flags
# DIR_DUP   duplicate directory tree

RM          := rm -f
MAKEFLAGS   += --no-print-directory
DIR_DUP     = mkdir -p $(@D)

RED		=	\033[91;1m
GREEN	=	\033[92;1m
YELLOW	=	\033[93;1m
BLUE	=	\033[94;1m
PINK	=	\033[95;1m
CLEAR	=	\033[0m

#------------------------------------------------#
#   RECIPES                                      #
#------------------------------------------------#
# all       default goal
# $(NAME)   linking .o -> binary
# %.o       compilation .c -> .o
# clean     remove .o
# fclean    remove .o + binary
# re        remake default goal

all: $(NAME)

$(NAME): $(LIBFT) $(PRINTF) $(OBJS)
	@echo "$(BLUE)Make all$(CLEAR)\n$(PINK)Compiling push_swap.$(CLEAR)"
	$(CC) $(CFLAGS) $(OBJS) -L$(LIBFT_DIR) -L$(PRINTF_DIR) -lft -o $(NAME)
	$(info CREATED $(NAME))

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	$(DIR_DUP)
	$(CC) $(CFLAGS) $(CPPFLAGS) -c -o $@ $<
	$(info CREATED $@)

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR) -C $(PRINTF_DIR)

clean:
	@echo "$(BLUE)Make clean/fclean$(CLEAR)\n$(RED)Removing all compiled files.$(CLEAR)"
	@$(MAKE) clean -C $(LIBFT_DIR) -C $(PRINTF_DIR)
	$(RM) $(OBJS)

fclean: clean
	@$(MAKE) fclean -C $(LIBFT_DIR) -C $(PRINTF_DIR)
	$(RM) $(NAME)

re: fclean all

#------------------------------------------------#
#   SPEC                                         #
#------------------------------------------------#

.PHONY: clean fclean re all
.SILENT:
