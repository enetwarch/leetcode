# The variables defining the compiler, formatter, and linter are important.
# They need to be installed in your local machine in order to work.

FORMATTER = clang-format
FORMATTER_FLAGS = -i

LINTER = clang-tidy
LINTER_FLAGS = -quiet

CPP_FILES = $(shell find . -name "*.cpp" | sort)
HPP_FILES = $(shell find . -name "*.hpp" | sort)

.PHONY: check format lint

check: format
	@echo All files checked!

format:
	@$(FORMATTER) $(FORMATTER_FLAGS) $(CPP_FILES) $(HPP_FILES)
	@echo All files formatted!

lint:
	@for file in $(CPP_FILES) $(HPP_FILES); do \
		$(LINTER) $(LINTER_FLAGS) $$file --; \
	done
	@echo All files linted!
