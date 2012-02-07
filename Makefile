%: %.c++
	g++-4.5 -std=c++0x -W -Wall -Wextra -Werror $< -o $@
