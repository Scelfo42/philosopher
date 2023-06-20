NAME = philo

RM_DIR = rm -rf

CC = clang

DEBUG_FLAG = -g

THREAD_FLAG = -pthread

CFLAGS = -Wall -Wextra -Werror $(THREAD_FLAG) $(DEBUG_FLAG)

INCLUDE = header

DEPS = $(INCLUDE)

SRCS_DIR = srcs

OBJ_DIR = obj

SRCS_FILES =	ft_philo.c ft_errors.c ft_utils.c ft_init.c \
				ft_routine.c ft_monitoring.c ft_time.c \
				ft_destructor.c ft_routine_utils.c \

SRCS = $(addprefix $(SRCS_DIR)/, $(SRCS_FILES))

O_SRCS = $(addprefix $(OBJ_DIR)/, $(SRCS_FILES:.c=.o))

GREY            = \033[0;30m
RED             = \033[0;31m
GREEN           = \033[0;32m
YELLOW          = \033[0;33m
BLUE            = \033[0;34m
FUCHSIA         = \033[0;35m
CYAN            = \033[0;36m
NC              = \033[0m

$(OBJ_DIR)/%.o : $(SRCS_DIR)/%.c $(DEPS)
	mkdir -p $(@D)
	$(CC) $(CFLAGS) -c $< -o $@ -I $(INCLUDE)

all: $(NAME)

$(NAME): $(SRCS) $(O_SRCS)
	$(CC) $(CFLAGS) $(O_SRCS) -o $(NAME)

clean:
	$(RM_DIR) $(OBJ_DIR)/
	clear

fclean: clean
	$(RM_DIR) $(NAME)
	clear

re: fclean all

push: 
	git add .
	@echo "$(RED)Adding all changes..."
	sleep 1.5
	@clear
	@echo "$(GREEN)All changes added$(NC)"
	@read -p "Enter a custom commit message (leave blank to use the default message): " message; \
	if [ -n "$$message" ]; then \
		git commit -m "$$message"; \
	else \
		git commit -m "$(shell date +'%H:%M %d-%h') update"; \
	fi
	@echo "$(YELLOW)Committing... and..."
	git push
	@echo "$(GREEN)PUSHA KEKKO!$(NC)"

norm:
	norminette *

.PHONY: all clean fclean re push norm
.SILENT:
