#include "header.h"

int pageBack(char *input) {
	if (!strcmp(input, ":b")) {
		return 1;
	}
	else {
		return 0;
	}
}



