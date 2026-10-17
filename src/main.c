/**
 * Home of the main function
 * Crazy no
 */

#include "ansicolors.h"
#include "array.h"

// I am not dealing with Windows quirks for ANSI color codes
#ifdef _WIN32
#	define isatty(x) 0
#else
#	include <unistd.h>
#endif

#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

/**
 * 1 = Bad input
 * 2 = Allocation error
 */
int main(int argc, const char* argv[]) {
	// Variables
	int STDERR_TTY = isatty(STDERR_FILENO);
	if (argc == 1) {
		fprintf(stderr, "%s: %serror:%s %sno functions given%s\n",
			argv[0],
			STDERR_TTY ? ANSI_BOLD ANSI_RED : "",
			STDERR_TTY ? ANSI_RESET : "",
			STDERR_TTY ? ANSI_BOLD : "",
			STDERR_TTY ? ANSI_RESET : ""
		);
		fprintf(stderr, "%s: %snote:%s %ssee '%s --help' for details%s\n",
			argv[0],
			STDERR_TTY ? ANSI_BOLD ANSI_GRAY : "",
			STDERR_TTY ? ANSI_RESET : "",
			STDERR_TTY ? ANSI_BOLD : "",
			argv[0],
			STDERR_TTY ? ANSI_RESET : ""
		);
		return 1;
	}
	const char* argumentLookupTable[] = {
		/// Functions
		"-a",
		"/a",
		"-s",
		"/s",
		"-m",
		"/m",
		"-d",
		"/d",
		/// Misc
		"-h",
		"/h",
		"--help",
		"-V",
		"/V",
		"--version"
	};

	// Read function
	int lookup = findIndexOfString(
		argumentLookupTable,
		sizeof(argumentLookupTable) / sizeof(argumentLookupTable[0]),
		argv[1]
	);
	switch (lookup) {
		// Add
		case 0: case 1: {
			if (argc == 2) {
				goto only_func;
			}
			if (argc == 3) {
				goto only_one;
			}
			size_t len = (size_t)argc - 3;
			double* nums = getDoubleArray(argv + 3, len);
			double total = atof(argv[2]);
			if (!nums) {
				goto alloc_fail;
			}
			doArithmeticOnArray(+, nums, len, total);
			free(nums);
			printf("%g\n", total);
			return 0;
		}
		// Subtract
		case 2: case 3: {
			if (argc == 2) {
				goto only_func;
			}
			if (argc == 3) {
				goto only_one;
			}
			size_t len = (size_t)argc - 3;
			double* nums = getDoubleArray(argv + 3, len);
			if (!nums) {
				goto alloc_fail;
			}
			double total = atof(argv[2]);
			doArithmeticOnArray(-, nums, len, total);
			free(nums);
			printf("%g\n", total);
			return 0;
		}
		// Multiply
		case 4: case 5: {
			if (argc == 2) {
				goto only_func;
			}
			if (argc == 3) {
				goto only_one;
			}
			size_t len = (size_t)argc - 3;
			double* nums = getDoubleArray(argv + 3, len);
			if (!nums) {
				goto alloc_fail;
			}
			double total = atof(argv[2]);
			doArithmeticOnArray(*, nums, len, total);
			free(nums);
			printf("%g\n", total);
			return 0;
		}
		// Divide
		case 6: case 7: {
			if (argc == 2) {
				goto only_func;
			}
			if (argc == 3) {
				goto only_one;
			}
			size_t len = (size_t)argc - 3;
			double* nums = getDoubleArray(argv + 3, len);
			if (!nums) {
				goto alloc_fail;
			}
			double total = atof(argv[2]);
			doArithmeticOnArray(/, nums, len, total);
			free(nums);
			printf("%g\n", total);
			return 0;
		}
		only_func: {
			fprintf(stderr, "%s: %serror:%s %sno numbers given to function '%s'%s\n",
				argv[0],
				STDERR_TTY ? ANSI_BOLD ANSI_RED : "",
				STDERR_TTY ? ANSI_RESET : "",
				STDERR_TTY ? ANSI_BOLD : "",
				argv[1],
				STDERR_TTY ? ANSI_RESET : ""
			);
			return 1;
		}
		only_one: {
			fprintf(stderr, "%s: %serror:%s %sonly 1 number given to function '%s'%s\n",
				argv[0],
				STDERR_TTY ? ANSI_BOLD ANSI_RED : "",
				STDERR_TTY ? ANSI_RESET : "",
				STDERR_TTY ? ANSI_BOLD : "",
				argv[1],
				STDERR_TTY ? ANSI_RESET : ""
			);
			return 1;
		}
		alloc_fail: {
			fprintf(stderr,
				"%s: %serror:%s %sfailed to allocate memory%s\n",
				argv[0],
				STDERR_TTY ? ANSI_BOLD ANSI_RED : "",
				STDERR_TTY ? ANSI_RESET : "",
				STDERR_TTY ? ANSI_BOLD : "",
				STDERR_TTY ? ANSI_RESET : ""
			);
			return 2;
		}

		// Help
		case 8: case 9: case 10: {
			printf("%s%s%s",
				"Usage: ", argv[0], " <function> [arguments]\n"
				"A stupid and detereministic shell calculator\n"
				"Behavior of division by zero depends on OS implementation\n"
				"Any numbers that are not in the format '123456.789' will be interpeted as 0\n\n"
				"Examples:\n"
				"compute -a 1 2       Add 1 and 2 (1 + 2 + 3)\n"
				"compute -a 1 2 3     Add 1, 2, and 3 (1 + 2 + 3)\n"
				"compute -m 1 2 3     Multiply 1, 2, and 3 (1 * 2 * 3)\n\n"
				"List of functions:\n"
				"Math related\n"
				"-a, /a               Adds numbers\n"
				"-s, /s               Subtracts numbers\n"
				"-m, /m               Multiplies numbers\n"
				"-d, /d               Divides numbers\n"
				"Miscellaneous\n"
				"  -h, /h, --help     Prints this screen.\n"
				"  -V, /V, --version  Prints version.\n"
			);
			return 0;
		}
		// Version
		case 11: case 12: case 13: {
			puts(
				"Compute (as in calculate) " PROJECT_VER "\n\n"
				"Copyright (c) 2026 MrSaturnIdk.\n"
				"Licensed under the AGPL-3.0-or-later.\n\n"
				"Source code hosted at <" HOMEPAGE ">."
			);
			return 0;
		}
		default: {
			fprintf(stderr, "%s: %serror:%s %sunrecognized argument '%s'%s\n",
				argv[0],
				STDERR_TTY ? ANSI_BOLD ANSI_RED : "",
				STDERR_TTY ? ANSI_RESET : "",
				STDERR_TTY ? ANSI_BOLD : "",
				argv[1],
				STDERR_TTY ? ANSI_RESET : ""
			);
			fprintf(stderr, "%s: %snote:%s %ssee '%s --help' for details%s\n",
				argv[0],
				STDERR_TTY ? ANSI_BOLD ANSI_GRAY : "",
				STDERR_TTY ? ANSI_RESET : "",
				STDERR_TTY ? ANSI_BOLD : "",
				argv[0],
				STDERR_TTY ? ANSI_RESET : ""
			);
			return 1;
		}
	}
}
