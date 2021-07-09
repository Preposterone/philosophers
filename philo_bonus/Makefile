NAME := philo_bonus

include variables.mk

#default make target
all: $(NAME)

#compilation
$(OBJS):  $(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(HEADERS)
	$(CC) $(CFLAGS) $(IFLAGS) -c $< -o ${<$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c} $@
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(HEADERS)
	$(CC) $(CFLAGS) $(IFLAGS) -c $< -o ${<$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c} $@

#main recipe
$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(IFLAGS) -o $(NAME) $(OBJS) $(LFLAGS)
	@echo ${NAME} compiled

re:	fclean all

#cleaning up
clean:
	/bin/rm -f $(OBJS)

fclean:	clean
	/bin/rm -f $(NAME)

cleanall: fclean dclean

#extra
norm:
	@norminette ${SRC_FILES} | grep --color -E '^|Error'

norminc:
	@norminette ${HEADERS} | grep --color -E '^|Error'

#shortcuts
ca: cleanall
n: norm norminc

.PHONY:	all clean fclean re
