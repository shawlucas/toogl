CC = gcc
CXX = g++
CFLAGS = -std=c99 
CXXFLAGS = -std=c++98 -fpermissive -Dprivate=public
OPTFLAGS = -g

TARGETS = toogl
LDIRT = ptrepository
C_FILES := regex.c
CXX_FILES := search.c++ toogl.c++ perlclass.c++
$(shell mkdir -p build)

O_FILES := $(foreach f, $(C_FILES:.c=.o),build/$f) \
           $(foreach f, $(CXX_FILES:.c++=.o),build/$f) 
 

default: $(TARGETS)

toogl: $(O_FILES)
	$(CXX) -o toogl -lGL $(O_FILES)

build/%.o: %.c
	$(CC) $(OPTFLAGS) $(CFLAGS) -c -o $@ $<

build/%.o: %.c++
	$(CXX) $(OPTFLAGS) $(CXXFLAGS) -c -o $@ $<

.PHONY: clean
clean:
	$(RM) -rf build
	$(RM) -rf libirisgl.a
	$(RM) -rf toogl
