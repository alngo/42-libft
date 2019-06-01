#include <stdio.h>
#include "libft.h"

int tests_run = 0;

int foo = 7;
int bar = 4;

static char *test_foo() {
	return (ft_assert("error, foo != 7", foo == 7));
}

static char *test_bar() {
	return (ft_assert("error, bar != 5", bar == 5));
}

static char *all_tests() {
	char *str;
	str = ft_test(&test_foo, &tests_run);
	if (str) {
		printf("\033[1;31m");
		printf("%s\n", str);
		printf("\033[0m");
	}
	str = ft_test(&test_bar, &tests_run);
	if (str)
		printf("%s\n", str);
	return 0;
}

int main(void) {
	char *result = all_tests();
	if (result != 0) {
		printf("%s\n", result);
	}
	else {
		printf("ALL TESTS PASSED\n");
	}
	printf("Tests run: %d\n", tests_run);
	return result != 0;
}

