NAME = miniRT
TEST_NAME = miniRT_test
CC = cc
CFLAGS = -Wall -Wextra -Werror -g
LIBFLAGS = -Llibs -Llibs/minilibx-linux -lm -lft -lmlx -lX11 -lXext

MATRICES = 	$(addprefix matrices/, 				add-subtract		\
												cofactor			\
												create_empty		\
												create_full			\
												equality inversion	\
												misc				\
												multiplication		\
												translation)

OBJECTS = 	$(addprefix parsing/objects/, 		ambient				\
												camera				\
												cylinder			\
												light				\
												plane				\
												sphere				\
												beam				\
												mirror)

PARSING = 	$(addprefix parsing/, 				check_utils			\
												checker				\
												count				\
												counter				\
												log					\
												parser				\
												rgb)

RENDERING = $(addprefix rendering/,				pixel				\
												rays				\
												render_sphere		\
												renderer			\
												calculate_light		\
												calculate_shade		\
												calculate_cyl_shade	\
												cylinder_intersect	\
												render_plane		\
												epsilon_check		\
												dist_between_points	\
												cylinder_cap_intersect)

ROTATION = 	$(addprefix matrices/rotation/, 	x_rotation			\
												y_rotation			\
												z_rotation			\
												world_rotation)

TESTS = 	$(addprefix tests/, 				test_invert			\
												test_parsing		\
												test_matrix1		\
												test_matrix2		\
												test_matrix3		\
												test_matrix4		\
												test_tuple1			\
												test_tuple2			\
												tests)

FILES = $(MATRICES)		\
		$(OBJECTS)		\
		$(PARSING)		\
		$(RENDERING)	\
		$(ROTATION)

SRCS = $(addprefix srcs/, $(addsuffix .c, 		minirt				\
												mlx_handling		\
												$(FILES)))
												
TEST_SRCS = $(addprefix srcs/, $(addsuffix .c, 	$(FILES)			\
												$(TESTS)))

OBJ_DIR = obj
OBJS = $(SRCS:srcs/%.c=$(OBJ_DIR)/%.o)
TEST_OBJS = $(TEST_SRCS:srcs/%.c=$(OBJ_DIR)/%.o)

OBJ_DIRS = $(sort $(dir $(OBJS)))

# Create directories if needed
$(OBJ_DIRS):
	mkdir -p $@

# Pattern rule: compile .c -> obj/.o preserving paths
$(OBJ_DIR)/%.o: srcs/%.c | $(OBJ_DIRS)
	$(CC) $(CFLAGS) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJS)
	@make -C ./libs/libft
	@make -C ./libs/minilibx-linux
	$(CC) $(CFLAGS) $(OBJS) $(LIBFLAGS) -o $@

clean:
	make clean -C ./libs/libft
	make clean -C ./libs/minilibx-linux
	rm -f $(OBJS)
	rm -f $(TEST_OBJS)

fclean: clean
	rm -f libs/libft/libft.a
	rm -f libs/libft.a
	rm -f libs/libmlx.a
	rm -f $(NAME)
	rm -f $(TEST_NAME)

re: fclean all

test: $(TEST_OBJS)
	@make -C ./libs/libft
	@make -C ./libs/minilibx-linux
	$(CC) $(CFLAGS) $(TEST_OBJS) $(LIBFLAGS) -o $(TEST_NAME)

valgrind:
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes -s ./$(NAME)

full: re
	make clean
	clear

.PHONY: all clean fclean re test valgrind full
