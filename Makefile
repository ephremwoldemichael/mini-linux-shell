CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -I src/headers
SRCDIR = src
OBJDIR = build
BINDIR = bin

SRCS = $(wildcard $(SRCDIR)/*.cpp)
OBJS = $(patsubst $(SRCDIR)/%.cpp,$(OBJDIR)/%.o,$(SRCS))
TARGET = shell

all: $(TARGET)

$(TARGET): $(OBJS)
	@mkdir -p $(BINDIR)
	$(CXX) $(CXXFLAGS) -o $(BINDIR)/$(TARGET) $(OBJS)

$(OBJDIR)/%.o: $(SRCDIR)/%.cpp
	@mkdir -p $(OBJDIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

run: all
	$(BINDIR)/$(TARGET)

clean:
	rm -rf $(OBJDIR) $(BINDIR)

.PHONY: all run clean
