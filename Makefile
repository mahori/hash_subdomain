CXX      = clang++

CXXFLAGS = -std=c++17
LDFLAGS  = -lboost_program_options

EXEC     = hash_subdomain
SRCS     = Subdomain.cpp MailAddress.cpp main.cpp
OBJS     = Subdomain.o MailAddress.o main.o

.PHONY: all
all: $(EXEC)

$(EXEC): $(OBJS)
	$(CXX) $(LDFLAGS) -o $@ $(OBJS) $(LIBS)

.PHONY: clean
clean:
	rm -f *~ *.o a.out $(EXEC)
