APP         = hash

CC          = g++
SRCS        = $(wildcard *.cpp)
HEADERS     = $(wildcard *.h)
OUT         = main.out

CFLAGS      = -Wall -Wextra -Werror -I.
LFLAGS      = -whitespace/braces,-legal/copyright
LINELENGTH  = 120

.PHONY: all run clean lint
all: lint $(APP) run clean

debug: $(SRCS)
	$(CC) -o debug_$(OUT) -g main.cpp $(CFLAGS)

$(APP): $(SRCS)
	$(CC) -o $(OUT) $(SRCS) $(CFLAGS)

run:
	./$(OUT)

lint:
	cpplint --linelength=$(LINELENGTH) --filter=$(LFLAGS) $(SRC) $(HEADERS)
	cppcheck --language=c++ $(SRC) $(HEADERS)

clean:
	rm $(OUT)
