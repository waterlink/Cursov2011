
linux_CC= gcc
linux_CFLAGS= -c -Wall
linux_LDFLAGS= -Wl,--allow-multiple-definition
linux_LIBRARIES= 

linux_spec_SOURCES= 
linux_spec_HEADERS= 
linux_spec_OBJECTS= 

win_CC=i586-mingw32msvc-gcc
win_RC=i586-mingw32msvc-windres
win_CFLAGS= -c -Wall -mwindows
win_LDFLAGS= -mwindows -Wl,--allow-multiple-definition
win_LIBRARIES= -lwinspool -lcomctl32

win_spec_SOURCES=
win_spec_HEADERS= 
win_spec_RESOURCES=  
win_spec_OBJECTS= 

LIBRARIES= 

linux_EXECUTABLE=./binary/linux/x.elf
win_EXECUTABLE=./binary/win/x.exe

DEBUG= -g -O0

# author: Fedorov Alexey

linux: $(linux_spec_SOURCES) $(linux_spec_HEADERS) $(linux_EXECUTABLE)

win: $(win_spec_SOURCES) $(win_spec_HEADERS) $(win_EXECUTABLE)

$(linux_EXECUTABLE): $(linux_spec_OBJECTS)
	$(linux_CC) $(linux_LDFLAGS) $(linux_spec_OBJECTS) -o $@ $(LIBRARIES) $(linux_LIBRARIES) $(DEBUG)

$(win_EXECUTABLE): $(linux_spec_OBJECTS)
	$(win_CC) $(win_LDFLAGS) $(win_spec_OBJECTS) -o $@ $(LIBRARIES) $(win_LIBRARIES) $(DEBUG)

%.win.coff: %.win.rc
	$(win_RC) -i $< -o $@

%.linux.o: %.linux.cpp %.linux.hpp
	$(linux_CC) $(linux_CFLAGS) $< -o $@ $(DEBUG)

%.win.o: %.win.cpp %.win.hpp
	$(win_CC) $(win_CFLAGS) $< -o $@ $(DEBUG)

%.linux.all.o: %.all.cpp %.all.hpp
	$(linux_CC) $(linux_CFLAGS) $< -o $@ $(DEBUG)

%.win.all.o: %.all.cpp %.all.hpp
	$(win_CC) $(linux_CFLAGS) $< -o $@ $(DEBUG)

#end

