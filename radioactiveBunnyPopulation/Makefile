## VARIABLES
#
EXECUTABLE=bunnies.exe
LANGUAGES := de en es pt
# Note the order of source files
SOURCES=bunny.cpp main.cpp  
HEADERS=bunny.h

CC=g++
CFLAGS=-c -Wall
LDFLAGS=


## SUBSTITUTIONS of file endings
# All strings in SOURCES with ending of .cpp is substituted by .o
OBJECTS=$(SOURCES:.cpp=.o)


## TARGETS
#
all: $(SOURCES) $(EXECUTABLE)

clean:
	rm -vf $(OBJECTS) $(EXECUTABLE)

distclean: clean
	rm -Rvf po/ *.orig
	
pretty:
	astyle --style=bsd $(SOURCES) $(HEADERS)

# Note the position of LDFLAGS    
$(EXECUTABLE): $(OBJECTS) 
	$(CC) $(OBJECTS) $(LDFLAGS) -o $@

PO: $(SOURCES)
	for LANG in $(LANGUAGES); do \
		echo "=> $$LANG"; \
		mkdir -p po/$$LANG; \
		xgettext -o po/$$LANG/$(EXECUTABLE).po -s $(SOURCES); \
		done

MO:
	for LANG in $(LANGUAGES); do \
		echo "=> $$LANG"; \
		msgfmt po/$$LANG/$(EXECUTABLE).po -o po/$$LANG/$(EXECUTABLE).mo; \
		done

## RULES
# Double-suffix .cpp.o is equivalent to %.o: %.cpp
# .cpp is the first prerequisite and .o is the target
# Automatic variable $< refers to the first prerequisite, i.e. .cpp file
# Automatic variable $@ refers to the target, i.e. .o file    
.cpp.o:
	$(CC) $(CFLAGS) $< -o $@

