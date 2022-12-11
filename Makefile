# **************************************************************************** #
#   COLORS                                                                     #
#   COM_COLOR=blue, OBJ_COLOR=green, ERROR_COLOR=red, WARN_COLOR=yellow        #
# **************************************************************************** #
COM_COLOR   := \033[0;34m
OBJ_COLOR   := \033[0;32m
ERROR_COLOR := \033[0;31m
WARN_COLOR  := \033[0;33m


# **************************************************************************** #
#   VARIABLES                                                                  #
# **************************************************************************** #
NAME			:=		push_swap

CC				:=		gcc
CFLAGS			:=		-Wall -Werror -Wextra -Iheader
DEPFLAGS		 =		-MMD -MF $(DDIR)$*.d

SDIR			:= 		srcs/
ODIR			:=		obj/
DDIR			:=		$(ODIR)deps/

LIBFT_DIR		:=		42cursus-Libft/
LDLIBS			:=		$(LIBFT_DIR)libft.a


SRCS 			:= 		push_swap.c 				\
						init_stack.c				\
						input_handling.c			\
						free_mem.c					\
						sort_small.c				\
						sort_big.c					\
						sorting_utils.c				\
						swap_operations.c			\
						push_operations.c			\
						rotate_operations.c			\
						reverse_rotate_operations.c	\
						list_functions.c

OBJS			:=		$(SRCS:%.c=$(ODIR)%.o)
DEPS			:=		$(SRCS:%.c=$(DDIR)%.d)


# **************************************************************************** #
#   RULES                                                                      #
# **************************************************************************** #

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): LIBFT $(ODIR) $(DDIR) $(DEPS) $(OBJS)
	@ $(CC) $(CFLAGS) $(DEPFLAGS) $(OBJS) -o $@ $(LDLIBS)
	@echo "$(COM_COLOR)...creating: $(NAME)"

$(ODIR):
	@mkdir $@
	@echo "$(OBJ_COLOR)...compiling $(NAME)-object-files..."

$(DDIR):
	@mkdir -p $@
	@echo "$(OBJ_COLOR)...creating dependencies..."

$(ODIR)%.o: $(SDIR)%.c $(DDIR)%.d
	@$(CC) $(CFLAGS) $(CPPFLAGS) $(DEPFLAGS) -c $< -o $@

LIBFT:
	@make -C $(LIBFT_DIR)

clean:
	@rm -rf $(OBJS) $(ODIR) $(DDIR)
	@make clean -C $(LIBFT_DIR)
	@echo "$(ERROR_COLOR)...$(NAME)-object files deleted"

fclean: clean
	@rm -rf $(NAME) $(LDLIBS)

re: fclean all

$(DEPS):
-include $(DEPS)