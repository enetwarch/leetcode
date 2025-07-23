# The variables defining the compiler, formatter, and linter are important.
# They need to be installed in your local machine in order to work.

FORMATTER = clang-format
FORMATTER_CONFIG = {BasedOnStyle: Google, IndentWidth: 4}
FORMATTER_FLAGS = -i -style='$(FORMATTER_CONFIG)'

LINTER = clang-tidy
LINTER_FLAGS = -checks=bugprone-* -quiet -extra-arg=-fno-caret-diagnostics
LINTER_COMPILER_FLAGS = -Iinclude -Wall

C_FILES = $(shell find . -name "*.cpp" | sort)
H_FILES = $(shell find . -name "*.hpp" | sort)
FILES = $(C_FILES) $(H_FILES)

.PHONY: check format lint

check: format lint
	@echo All files checked!

format:
	@$(FORMATTER) $(FORMATTER_FLAGS) $(FILES)

lint:
	@for file in $(FILES); do \
		$(LINTER) $(LINTER_FLAGS) $$file -- $(LINTER_COMPILER_FLAGS); \
	done
