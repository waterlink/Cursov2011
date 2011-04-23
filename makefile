
linux_CC= g++
linux_CFLAGS= -c -Wall
linux_LDFLAGS= -Wl,--allow-multiple-definition
linux_LIBRARIES= 
linux_DEFFS= -DLINUX_target

linux_spec_SOURCES= 
linux_spec_HEADERS= 
linux_spec_OBJECTS= 

win_CC=i586-mingw32msvc-gcc
win_RC=i586-mingw32msvc-windres
win_CFLAGS= -c -Wall -mwindows
win_LDFLAGS= -mwindows -Wl,--allow-multiple-definition
win_DEFFS= -DWIN_target
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

#tab
$(linux_EXECUTABLE): $(linux_spec_OBJECTS)
	$(linux_CC) $(linux_LDFLAGS) $(linux_spec_OBJECTS) -o $@ $(LIBRARIES) $(linux_LIBRARIES) $(DEBUG)

#tab
$(win_EXECUTABLE): $(linux_spec_OBJECTS)
	$(win_CC) $(win_LDFLAGS) $(win_spec_OBJECTS) -o $@ $(LIBRARIES) $(win_LIBRARIES) $(DEBUG)

#tab
./objects/%.win.coff: ./sources/%.win.rc
	$(win_RC) -i $< -o $@

#tab
./objects/%.linux.o: ./sources/%.linux.cpp ./sources/%.linux.hpp
	$(linux_CC) $(linux_CFLAGS) $< -o $@ $(DEBUG)

#tab
./objects/%.win.o: ./sources/%.win.cpp ./sources/%.win.hpp
	$(win_CC) $(win_CFLAGS) $< -o $@ $(DEBUG)

#tab
./objects/%.linux.all.o: ./sources/%.all.cpp ./sources/%.all.hpp
	$(linux_CC) $(linux_CFLAGS) $< -o $@ $(DEBUG)

#tab
./objects/%.win.all.o: ./sources/%.all.cpp ./sources/%.all.hpp
	$(win_CC) $(linux_CFLAGS) $< -o $@ $(DEBUG)

#end

