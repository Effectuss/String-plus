CC = gcc
CFLAGS =-Wall -Wextra -Werror -std=c11
CFLAGS_GCOV = --coverage

OS=$(shell uname)
ifeq ($(OS), Linux)
CFLAGS_TEST= -lcheck -lm -lpthread -lrt -lsubunit -D_GNU_SOURCE
LEAKS = valgrind --leak-check=full --track-origins=yes -s
endif
ifeq ($(OS), Darwin)
CFLAGS_TEST= -lcheck
LEAKS = leaks -atExit -- 
endif

SOURCES = my_string.c my_sprintf.c
SOURCES_TEST = my_string_test.c

BUILD_DIR = .
OUTFILE_TEST = my_string_test

all: my_string.a test gcov_report

test:
	$(CC) $(CFLAGS) $(SOURCES) $(SOURCES_TEST) $(CFLAGS_TEST) -o $(BUILD_DIR)/$(OUTFILE_TEST)
	$(BUILD_DIR)/$(OUTFILE_TEST)

my_string.a:
	$(CC) $(CFLAGS) -c my_string.c -o my_string.o
	$(CC) $(CFLAGS) -c my_sprintf.c -o my_sprintf.o
	ar rc my_string.a my_string.o my_sprintf.o

gcov_my_string.a:
	$(CC) $(CFLAGS) -c my_string.c -o my_string.o $(CFLAGS_GCOV)
	$(CC) $(CFLAGS) -c my_sprintf.c -o my_sprintf.o $(CFLAGS_GCOV)
	ar rc gcov_my_string.a my_string.o my_sprintf.o

gcov_report: gcov_test
	$(BUILD_DIR)/$(OUTFILE_TEST)
	lcov --capture --directory . --output-file main_coverage.info
	genhtml  main_coverage.info --output-directory lcov_report

gcov_test: gcov_my_string.a
	$(CC) -Wall -Werror -Wextra $(SOURCES) $(SOURCES_TEST) $(CFLAGS_TEST) $(CFLAGS_GCOV) -o $(BUILD_DIR)/$(OUTFILE_TEST)
	$(BUILD_DIR)/$(OUTFILE_TEST)

check: test
	cppcheck --enable=all --suppress=missingIncludeSystem *.c *.h
	$(LEAKS) $(BUILD_DIR)/$(OUTFILE_TEST)

clean:
	rm -rf ./lcov_report
	rm -rf *.o *.a *.gcno *.out *.dSYM *.gcda *.gcov *.info $(BUILD_DIR)/$(OUTFILE_TEST)