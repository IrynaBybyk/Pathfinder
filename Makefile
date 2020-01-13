NAME = pathfinder
INC = ./inc/header.h
INCLIB = ./libmx/inc/libmx.h
HEADTMP = ./header.h ./libmx.h

SRC = ./main.c ./mx_isalpha.c ./mx_isdigit.c ./mx_printerr.c \
    ./mx_free_all.c ./mx_print_err.c ./mx_print.c ./mx_my_atoi.c \
    ./mx_is_valid_name.c ./mx_read_file.c ./mx_initialize.c \
    ./mx_init_AM.c ./mx_make_DM.c ./mx_restore_all_paths.c ./mx_line.c \
    ./mx_init_stack.c ./mx_is_next.c ./mx_allpaths_and_print.c \
    ./mx_get_from_stack.c ./mx_init_city.c ./mx_parse_line.c \
    ./mx_print_line.c ./mx_check_file.c ./mx_push.c ./mx_index.c \
    ./mx_index_in_city.c ./mx_push_in_city.c ./mx_push_am.c \

SRCS = ./src/main.c ./src/mx_isalpha.c ./src/mx_isdigit.c \
    ./src/mx_printerr.c ./src/mx_free_all.c ./src/mx_print_err.c \
    ./src/mx_print.c ./src/mx_my_atoi.c ./src/mx_push_in_city.c \
    ./src/mx_is_valid_name.c ./src/mx_read_file.c ./src/mx_init_AM.c \
    ./src/mx_make_DM.c ./src/mx_restore_all_paths.c ./src/mx_check_file.c \
    ./src/mx_init_stack.c ./src/mx_is_next.c ./src/mx_index_in_city.c \
    ./src/mx_allpaths_and_print.c ./src/mx_get_from_stack.c ./src/mx_index.c\
    ./src/mx_init_city.c ./src/mx_print_line.c ./src/mx_push.c ./src/mx_line.c \
    ./src/mx_parse_line.c ./src/mx_initialize.c ./src/mx_push_am.c\

OBJ = ./main.o ./mx_isalpha.o ./mx_isdigit.o ./mx_printerr.o \
    ./mx_free_all.o ./mx_print_err.o ./mx_print.o ./mx_index.o\
    ./mx_check_file.o ./mx_parse_line.o ./mx_push.o \
    ./mx_my_atoi.o ./mx_is_valid_name.o ./mx_index_in_city.o \
    ./mx_read_file.o ./mx_init_AM.o ./mx_make_DM.o ./mx_restore_all_paths.o \
    ./mx_init_stack.o ./mx_is_next.o ./mx_push_am.o \
    ./mx_allpaths_and_print.o ./mx_push_in_city.o \
    ./mx_get_from_stack.o ./mx_init_city.o \
    ./mx_print_line.o ./mx_initialize.o ./mx_line.o \

OBJO = ./obj/main.o ./obj/mx_isalpha.o ./obj/mx_push.o \
    ./obj/mx_isdigit.o ./obj/mx_initialize.o ./obj/mx_index.o \
    ./obj/mx_printerr.o ./obj/mx_free_all.o ./obj/mx_push_am.o \
    ./obj/mx_print_err.o ./obj/mx_push_in_city.o \
    ./obj/mx_print.o ./obj/mx_my_atoi.o ./obj/mx_parse_line.o \
    ./obj/mx_is_valid_name.o ./obj/mx_read_file.o ./obj/mx_init_AM.o \
    ./obj/mx_make_DM.o ./obj/mx_restore_all_paths.o ./obj/mx_check_file.o \
    ./obj/mx_init_stack.o ./obj/mx_is_next.o ./obj/mx_index_in_city.o \
    ./obj/mx_allpaths_and_print.o ./obj/mx_get_from_stack.o \
    ./obj/mx_init_city.o ./obj/mx_print_line.o  ./obj/mx_line.o \

CFLGS = -std=c11 -Wall -Wextra -Wpedantic -Werror

all: install uninstall
install:
	@cd libmx && make -f Makefile install
	@cp $(INC) $(SRCS) .
	@cp $(INCLIB) . 
	@clang $(CFLGS) -c  $(SRC)
	@mkdir  obj
	@mv $(OBJ) ./obj
	@clang $(CFLGS) $(OBJO) libmx/libmx.a -o $(NAME)
uninstall:
	@cd libmx && make -f Makefile uninstall
	@rm -rf $(OBJO) $(SRC) $(HEADTMP)
	@rm -rf ./obj
	@rm -rf ./libmx/obj
clean: uninstall
	@cd libmx && make -f Makefile clean
	@rm -rf $(NAME)
reinstall: clean all

