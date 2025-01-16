.PHONY = format

format:
		find . -type f -name "*.cpp" -o -name "*.h" -o -name "*.cxx" -o -name "*.hpp" -exec clang-format -i {} +
