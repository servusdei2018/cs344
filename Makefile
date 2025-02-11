.PHONY = format

default: format

format:
	find . -type f \( -name "*.cpp" -o -name "*.cxx" -o -name "*.h" -o -name "*.hpp" \) | xargs clang-format -i
