##
## EPITECH PROJECT, 2024
## Typedef
## File description:
## Makefile
##

NAME		:=	typedef

CC			:=	gcc
CPPFLAGS	:=	-Iinclude/
CFLAGS 		:=	-Wall -Wextra -Werror -pedantic -ansi -fPIE -Wformat \
				-fno-delete-null-pointer-checks -fno-strict-overflow \
				-fno-strict-aliasing -ftrivial-auto-var-init=zero    \
				-Wimplicit-fallthrough -fstack-protector-strong		 \
				-U_FORTIFY_SOURCE -D_GLIBCXX_ASSERTIONS

ifeq ($(PLATFORM),x86_64)
CFLAGS		+=	-fcf-protection=full -Wl,-z,nodlopen -Wl,-z,noexecstack	\
				-Wl,-z,relro -Wl,-z,now -fstack-clash-protection 		\
				-fstrict-flex-arrays=3 -Wtrampolines
endif

ifeq ($(PLATFORM),aarch64)
CFLAGS		+=	-mbranch-protection=standard
endif

SRCS			:=	$(shell find src -name '*.c')
OBJS			:=	$(SRCS:.c=.o)

TESTS_SRCS		:=	$(shell find tests -type f -name 'tests_*.c')
TESTS_OBJS		:=	$(TESTS_SRCS:.c=.o)

VALGRIND_FLAGS	:=	-s							\
					--leak-check=full			\
					--track-origins=yes			\
					--read-var-info=yes			\
					--trace-children=yes		\
					--show-leak-kinds=all		\
					--read-inline-info=yes		\
					--errors-for-leak-kinds=all

RM				:=	rm -f

all:	$(NAME)

$(NAME):	CFLAGS += -UUNIT_TESTS
$(NAME):	$(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $@

tests/%.o:	CFLAGS += -Wall -Wextra -Werror
tests/%.o:	tests/%.c
	$(CC) $(CFLAGS) $(CPPFLAGS) -o $@ -c $<

tests_run:	CFLAGS = -g --coverage -DUNIT_TESTS
tests_run:	fclean	$(OBJS)	$(TESTS_OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(TESTS_OBJS) -o unit_tests -lcriterion
	./unit_tests
	gcovr -e tests .

valgrind:	tests_run
	valgrind $(VALGRIND_FLAGS) ./$(NAME)

clean:
	@$(RM) $(OBJS)
	@$(RM) $(TESTS_OBJS)
	@$(RM) $(shell find . -type f -name '*.gcno')
	@$(RM) $(shell find . -type f -name '*.gcda')

fclean:	clean
	@$(RM) $(NAME)
	@$(RM) unit_tests

re:	fclean	all
