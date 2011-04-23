 
linux_CC= g++ 
linux_CFLAGS= -c -Wall 
linux_LDFLAGS= -Wl,--allow-multiple-definition 
linux_LIBRARIES= 
linux_DEFFS= -DLINUX_target 
 
linux_spec_SOURCES= ./source/linux/main/*.linux.cpp ./source/all/robocore/*.all.cpp 
linux_spec_HEADERS= ./source/linux/main/*.linux.hpp ./source/all/robocore/*.all.hpp 
linux_spec_OBJECTS= ./objects/linux/main/*.linux.o ./objects/all/robocore/*.linux.all.o 
 
win_CC=i586-mingw32msvc-g++ 
win_RC=i586-mingw32msvc-windres 
win_CFLAGS= -c -Wall -mwindows 
win_LDFLAGS= -mwindows -Wl,--allow-multiple-definition 
win_DEFFS= -DWIN_target 
win_LIBRARIES= -lwinspool -lcomctl32 
 
win_spec_SOURCES= ./source/win/main/*.win.cpp ./source/all/robocore/*.all.cpp 
win_spec_HEADERS= ./source/win/main/*.win.hpp ./source/all/robocore/*.all.hpp 
win_spec_RESOURCES= 
win_spec_OBJECTS= ./objects/win/main/*.win.o ./objects/all/robocore/*.win.all.o 
 
LIBRARIES= 
 
linux_EXECUTABLE=./binary/linux/x.elf 
win_EXECUTABLE=./binary/win/x.exe 
 
DEBUG= -g -O0 
 
# author: Fedorov Alexey 
 
linux: $(linux_spec_SOURCES) $(linux_spec_HEADERS) $(win_spec_OBJECTS) $(linux_EXECUTABLE) 
 
#tab 
$(linux_EXECUTABLE): $(linux_spec_OBJECTS) 
	$(linux_CC) $(linux_LDFLAGS) $(linux_spec_OBJECTS) -o $@ $(LIBRARIES) $(linux_LIBRARIES) $(DEBUG) 
 
win: $(win_spec_SOURCES) $(win_spec_HEADERS) $(win_spec_OBJECTS) $(win_EXECUTABLE) 
 
#tab 
$(win_EXECUTABLE): $(win_spec_OBJECTS) 
	$(win_CC) $(win_LDFLAGS) $(win_spec_OBJECTS) -o $@ $(LIBRARIES) $(win_LIBRARIES) $(DEBUG) 
 
all: linux win 
 
#tab 
./objects/win/main/main2.win.o: ./source/win/main/main2.win.cpp ./source/win/main/main2.win.hpp 
	$(win_CC) ./source/win/main/main2.win.cpp $(win_CFLAGS) -o ./objects/win/main/main2.win.o $(win_DEFFS) 
 
#tab 
./objects/linux/main/main.linux.o: ./source/linux/main/main.linux.cpp ./source/linux/main/main.linux.hpp 
	$(linux_CC) ./source/linux/main/main.linux.cpp $(linux_CFLAGS) -o ./objects/linux/main/main.linux.o $(linux_DEFFS) 
 
#tab 
./objects/linux/main/mainclass.linux.o: ./source/linux/main/mainclass.linux.cpp ./source/linux/main/mainclass.linux.hpp 
	$(linux_CC) ./source/linux/main/mainclass.linux.cpp $(linux_CFLAGS) -o ./objects/linux/main/mainclass.linux.o $(linux_DEFFS) 
 
 
#tab 
./objects/win/main/mainclass.win.o: ./source/win/main/mainclass.win.cpp ./source/win/main/mainclass.win.hpp 
	$(win_CC) ./source/win/main/mainclass.win.cpp $(win_CFLAGS) -o ./objects/win/main/mainclass.win.o $(win_DEFFS) 
 
#tab 
./objects/all/robocore/core.linux.all.o: ./source/all/robocore/core.all.cpp ./source/all/robocore/core.all.hpp 
	$(linux_CC) ./source/all/robocore/core.all.cpp $(linux_CFLAGS) -o ./objects/all/robocore/core.linux.all.o $(linux_DEFFS) 
#tab 
 
	$(win_CC) ./source/all/robocore/core.all.cpp $(win_CFLAGS) -o ./objects/all/robocore/core.win.all.o $(win_DEFFS) 
#end
