 
linux_CC= g++ 
linux_CFLAGS= -c -Wall 
linux_LDFLAGS= -Wl,--allow-multiple-definition 
linux_LIBRARIES= 
linux_DEFFS= -DLINUX_target 
 
linux_spec_SOURCES= ./source/linux/main/*.linux.cpp ./source/all/robocore/*.all.cpp ./source/all/guicore/*.all.cpp 
linux_spec_HEADERS= ./source/linux/main/*.linux.hpp ./source/all/robocore/*.all.hpp ./source/all/guicore/*.all.hpp 
linux_spec_OBJECTS= ./objects/linux/main/*.linux.o ./objects/all/robocore/*.linux.all.o ./objects/all/guicore/*.linux.all.o 
 
win_CC=i586-mingw32msvc-g++ 
win_RC=i586-mingw32msvc-windres 
win_CFLAGS= -c -Wall -mwindows 
win_LDFLAGS= -mwindows -Wl,--allow-multiple-definition 
win_DEFFS= -DWIN_target 
win_LIBRARIES= -lwinspool -lcomctl32 
 
win_spec_SOURCES= ./source/win/main/*.win.cpp ./source/all/robocore/*.all.cpp ./source/all/guicore/*.all.cpp ./source/win/Wguicore/*.win.cpp 
win_spec_HEADERS= ./source/win/main/*.win.hpp ./source/all/robocore/*.all.hpp ./source/all/guicore/*.all.hpp ./source/win/Wguicore/*.win.hpp 
win_spec_RESOURCES= 
win_spec_OBJECTS= ./objects/win/main/*.win.o ./objects/all/robocore/*.win.all.o ./objects/all/guicore/*.win.all.o ./objects/win/Wguicore/*.win.o 
 
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
 
#tab 
./objects/all/robocore/izprog.linux.all.o: ./source/all/robocore/izprog.all.cpp ./source/all/robocore/izprog.all.hpp 
	$(linux_CC) ./source/all/robocore/izprog.all.cpp $(linux_CFLAGS) -o ./objects/all/robocore/izprog.linux.all.o $(linux_DEFFS) 
#tab 
 
	$(win_CC) ./source/all/robocore/izprog.all.cpp $(win_CFLAGS) -o ./objects/all/robocore/izprog.win.all.o $(win_DEFFS) 
 
#tab 
./objects/all/robocore/ibtexec.linux.all.o: ./source/all/robocore/ibtexec.all.cpp ./source/all/robocore/ibtexec.all.hpp 
	$(linux_CC) ./source/all/robocore/ibtexec.all.cpp $(linux_CFLAGS) -o ./objects/all/robocore/ibtexec.linux.all.o $(linux_DEFFS) 
#tab 
 
	$(win_CC) ./source/all/robocore/ibtexec.all.cpp $(win_CFLAGS) -o ./objects/all/robocore/ibtexec.win.all.o $(win_DEFFS) 
 
#tab 
./objects/all/robocore/test_zprogemu.linux.all.o: ./source/all/robocore/test_zprogemu.all.cpp ./source/all/robocore/test_zprogemu.all.hpp 
	$(linux_CC) ./source/all/robocore/test_zprogemu.all.cpp $(linux_CFLAGS) -o ./objects/all/robocore/test_zprogemu.linux.all.o $(linux_DEFFS) 
#tab 
 
	$(win_CC) ./source/all/robocore/test_zprogemu.all.cpp $(win_CFLAGS) -o ./objects/all/robocore/test_zprogemu.win.all.o $(win_DEFFS) 
 
#tab 
./objects/all/robocore/test_roboemu_params.linux.all.o: ./source/all/robocore/test_roboemu_params.all.cpp ./source/all/robocore/test_roboemu_params.all.hpp 
	$(linux_CC) ./source/all/robocore/test_roboemu_params.all.cpp $(linux_CFLAGS) -o ./objects/all/robocore/test_roboemu_params.linux.all.o $(linux_DEFFS) 
#tab 
 
	$(win_CC) ./source/all/robocore/test_roboemu_params.all.cpp $(win_CFLAGS) -o ./objects/all/robocore/test_roboemu_params.win.all.o $(win_DEFFS) 
 
#tab 
./objects/all/robocore/test_btexecemu.linux.all.o: ./source/all/robocore/test_btexecemu.all.cpp ./source/all/robocore/test_btexecemu.all.hpp 
	$(linux_CC) ./source/all/robocore/test_btexecemu.all.cpp $(linux_CFLAGS) -o ./objects/all/robocore/test_btexecemu.linux.all.o $(linux_DEFFS) 
#tab 
 
	$(win_CC) ./source/all/robocore/test_btexecemu.all.cpp $(win_CFLAGS) -o ./objects/all/robocore/test_btexecemu.win.all.o $(win_DEFFS) 
 
#tab 
./objects/all/guicore/guicore.linux.all.o: ./source/all/guicore/guicore.all.cpp ./source/all/guicore/guicore.all.hpp 
	$(linux_CC) ./source/all/guicore/guicore.all.cpp $(linux_CFLAGS) -o ./objects/all/guicore/guicore.linux.all.o $(linux_DEFFS) 
#tab 
 
	$(win_CC) ./source/all/guicore/guicore.all.cpp $(win_CFLAGS) -o ./objects/all/guicore/guicore.win.all.o $(win_DEFFS) 
 
#tab 
./objects/all/guicore/component.linux.all.o: ./source/all/guicore/component.all.cpp ./source/all/guicore/component.all.hpp 
	$(linux_CC) ./source/all/guicore/component.all.cpp $(linux_CFLAGS) -o ./objects/all/guicore/component.linux.all.o $(linux_DEFFS) 
#tab 
 
	$(win_CC) ./source/all/guicore/component.all.cpp $(win_CFLAGS) -o ./objects/all/guicore/component.win.all.o $(win_DEFFS) 
 
#tab 
./objects/all/guicore/form.linux.all.o: ./source/all/guicore/form.all.cpp ./source/all/guicore/form.all.hpp 
	$(linux_CC) ./source/all/guicore/form.all.cpp $(linux_CFLAGS) -o ./objects/all/guicore/form.linux.all.o $(linux_DEFFS) 
#tab 
 
	$(win_CC) ./source/all/guicore/form.all.cpp $(win_CFLAGS) -o ./objects/all/guicore/form.win.all.o $(win_DEFFS) 
 
#tab 
./objects/all/guicore/client.linux.all.o: ./source/all/guicore/client.all.cpp ./source/all/guicore/client.all.hpp 
	$(linux_CC) ./source/all/guicore/client.all.cpp $(linux_CFLAGS) -o ./objects/all/guicore/client.linux.all.o $(linux_DEFFS) 
#tab 
 
	$(win_CC) ./source/all/guicore/client.all.cpp $(win_CFLAGS) -o ./objects/all/guicore/client.win.all.o $(win_DEFFS) 
 
#tab 
./objects/all/guicore/namer.linux.all.o: ./source/all/guicore/namer.all.cpp ./source/all/guicore/namer.all.hpp 
	$(linux_CC) ./source/all/guicore/namer.all.cpp $(linux_CFLAGS) -o ./objects/all/guicore/namer.linux.all.o $(linux_DEFFS) 
#tab 
 
	$(win_CC) ./source/all/guicore/namer.all.cpp $(win_CFLAGS) -o ./objects/all/guicore/namer.win.all.o $(win_DEFFS) 
 
#tab 
./objects/all/guicore/menu.linux.all.o: ./source/all/guicore/menu.all.cpp ./source/all/guicore/menu.all.hpp 
	$(linux_CC) ./source/all/guicore/menu.all.cpp $(linux_CFLAGS) -o ./objects/all/guicore/menu.linux.all.o $(linux_DEFFS) 
#tab 
 
	$(win_CC) ./source/all/guicore/menu.all.cpp $(win_CFLAGS) -o ./objects/all/guicore/menu.win.all.o $(win_DEFFS) 
 
#tab 
./objects/all/guicore/messager.linux.all.o: ./source/all/guicore/messager.all.cpp ./source/all/guicore/messager.all.hpp 
	$(linux_CC) ./source/all/guicore/messager.all.cpp $(linux_CFLAGS) -o ./objects/all/guicore/messager.linux.all.o $(linux_DEFFS) 
#tab 
 
	$(win_CC) ./source/all/guicore/messager.all.cpp $(win_CFLAGS) -o ./objects/all/guicore/messager.win.all.o $(win_DEFFS) 
 
#tab 
./objects/all/guicore/textable.linux.all.o: ./source/all/guicore/textable.all.cpp ./source/all/guicore/textable.all.hpp 
	$(linux_CC) ./source/all/guicore/textable.all.cpp $(linux_CFLAGS) -o ./objects/all/guicore/textable.linux.all.o $(linux_DEFFS) 
#tab 
 
	$(win_CC) ./source/all/guicore/textable.all.cpp $(win_CFLAGS) -o ./objects/all/guicore/textable.win.all.o $(win_DEFFS) 
 
#tab 
./objects/all/guicore/activateble.linux.all.o: ./source/all/guicore/activateble.all.cpp ./source/all/guicore/activateble.all.hpp 
	$(linux_CC) ./source/all/guicore/activateble.all.cpp $(linux_CFLAGS) -o ./objects/all/guicore/activateble.linux.all.o $(linux_DEFFS) 
#tab 
 
	$(win_CC) ./source/all/guicore/activateble.all.cpp $(win_CFLAGS) -o ./objects/all/guicore/activateble.win.all.o $(win_DEFFS) 
 
#tab 
./objects/all/guicore/selectable.linux.all.o: ./source/all/guicore/selectable.all.cpp ./source/all/guicore/selectable.all.hpp 
	$(linux_CC) ./source/all/guicore/selectable.all.cpp $(linux_CFLAGS) -o ./objects/all/guicore/selectable.linux.all.o $(linux_DEFFS) 
#tab 
 
	$(win_CC) ./source/all/guicore/selectable.all.cpp $(win_CFLAGS) -o ./objects/all/guicore/selectable.win.all.o $(win_DEFFS) 
 
#tab 
./objects/all/guicore/button.linux.all.o: ./source/all/guicore/button.all.cpp ./source/all/guicore/button.all.hpp 
	$(linux_CC) ./source/all/guicore/button.all.cpp $(linux_CFLAGS) -o ./objects/all/guicore/button.linux.all.o $(linux_DEFFS) 
#tab 
 
	$(win_CC) ./source/all/guicore/button.all.cpp $(win_CFLAGS) -o ./objects/all/guicore/button.win.all.o $(win_DEFFS) 
 
#tab 
./objects/all/guicore/enableble.linux.all.o: ./source/all/guicore/enableble.all.cpp ./source/all/guicore/enableble.all.hpp 
	$(linux_CC) ./source/all/guicore/enableble.all.cpp $(linux_CFLAGS) -o ./objects/all/guicore/enableble.linux.all.o $(linux_DEFFS) 
#tab 
 
	$(win_CC) ./source/all/guicore/enableble.all.cpp $(win_CFLAGS) -o ./objects/all/guicore/enableble.win.all.o $(win_DEFFS) 
 
#tab 
./objects/all/guicore/bitbutton.linux.all.o: ./source/all/guicore/bitbutton.all.cpp ./source/all/guicore/bitbutton.all.hpp 
	$(linux_CC) ./source/all/guicore/bitbutton.all.cpp $(linux_CFLAGS) -o ./objects/all/guicore/bitbutton.linux.all.o $(linux_DEFFS) 
#tab 
 
	$(win_CC) ./source/all/guicore/bitbutton.all.cpp $(win_CFLAGS) -o ./objects/all/guicore/bitbutton.win.all.o $(win_DEFFS) 
 
#tab 
./objects/all/guicore/bitmapable.linux.all.o: ./source/all/guicore/bitmapable.all.cpp ./source/all/guicore/bitmapable.all.hpp 
	$(linux_CC) ./source/all/guicore/bitmapable.all.cpp $(linux_CFLAGS) -o ./objects/all/guicore/bitmapable.linux.all.o $(linux_DEFFS) 
#tab 
 
	$(win_CC) ./source/all/guicore/bitmapable.all.cpp $(win_CFLAGS) -o ./objects/all/guicore/bitmapable.win.all.o $(win_DEFFS) 
 
#tab 
./objects/all/guicore/sizeble.linux.all.o: ./source/all/guicore/sizeble.all.cpp ./source/all/guicore/sizeble.all.hpp 
	$(linux_CC) ./source/all/guicore/sizeble.all.cpp $(linux_CFLAGS) -o ./objects/all/guicore/sizeble.linux.all.o $(linux_DEFFS) 
#tab 
 
	$(win_CC) ./source/all/guicore/sizeble.all.cpp $(win_CFLAGS) -o ./objects/all/guicore/sizeble.win.all.o $(win_DEFFS) 
 
#tab 
./objects/all/guicore/toolbox.linux.all.o: ./source/all/guicore/toolbox.all.cpp ./source/all/guicore/toolbox.all.hpp 
	$(linux_CC) ./source/all/guicore/toolbox.all.cpp $(linux_CFLAGS) -o ./objects/all/guicore/toolbox.linux.all.o $(linux_DEFFS) 
#tab 
 
	$(win_CC) ./source/all/guicore/toolbox.all.cpp $(win_CFLAGS) -o ./objects/all/guicore/toolbox.win.all.o $(win_DEFFS) 
 
#tab 
./objects/all/guicore/view.linux.all.o: ./source/all/guicore/view.all.cpp ./source/all/guicore/view.all.hpp 
	$(linux_CC) ./source/all/guicore/view.all.cpp $(linux_CFLAGS) -o ./objects/all/guicore/view.linux.all.o $(linux_DEFFS) 
#tab 
 
	$(win_CC) ./source/all/guicore/view.all.cpp $(win_CFLAGS) -o ./objects/all/guicore/view.win.all.o $(win_DEFFS) 
 
#tab 
./objects/all/guicore/mousecaptureble.linux.all.o: ./source/all/guicore/mousecaptureble.all.cpp ./source/all/guicore/mousecaptureble.all.hpp 
	$(linux_CC) ./source/all/guicore/mousecaptureble.all.cpp $(linux_CFLAGS) -o ./objects/all/guicore/mousecaptureble.linux.all.o $(linux_DEFFS) 
#tab 
 
	$(win_CC) ./source/all/guicore/mousecaptureble.all.cpp $(win_CFLAGS) -o ./objects/all/guicore/mousecaptureble.win.all.o $(win_DEFFS) 
 
#tab 
./objects/all/guicore/paintable.linux.all.o: ./source/all/guicore/paintable.all.cpp ./source/all/guicore/paintable.all.hpp 
	$(linux_CC) ./source/all/guicore/paintable.all.cpp $(linux_CFLAGS) -o ./objects/all/guicore/paintable.linux.all.o $(linux_DEFFS) 
#tab 
 
	$(win_CC) ./source/all/guicore/paintable.all.cpp $(win_CFLAGS) -o ./objects/all/guicore/paintable.win.all.o $(win_DEFFS) 
 
#tab 
./objects/all/guicore/status.linux.all.o: ./source/all/guicore/status.all.cpp ./source/all/guicore/status.all.hpp 
	$(linux_CC) ./source/all/guicore/status.all.cpp $(linux_CFLAGS) -o ./objects/all/guicore/status.linux.all.o $(linux_DEFFS) 
#tab 
 
	$(win_CC) ./source/all/guicore/status.all.cpp $(win_CFLAGS) -o ./objects/all/guicore/status.win.all.o $(win_DEFFS) 
 
#tab 
./objects/all/guicore/properties.linux.all.o: ./source/all/guicore/properties.all.cpp ./source/all/guicore/properties.all.hpp 
	$(linux_CC) ./source/all/guicore/properties.all.cpp $(linux_CFLAGS) -o ./objects/all/guicore/properties.linux.all.o $(linux_DEFFS) 
#tab 
 
	$(win_CC) ./source/all/guicore/properties.all.cpp $(win_CFLAGS) -o ./objects/all/guicore/properties.win.all.o $(win_DEFFS) 
 
#tab 
./objects/win/Wguicore/Wform.win.o: ./source/win/Wguicore/Wform.win.cpp ./source/win/Wguicore/Wform.win.hpp 
	$(win_CC) ./source/win/Wguicore/Wform.win.cpp $(win_CFLAGS) -o ./objects/win/Wguicore/Wform.win.o $(win_DEFFS) 
 
#tab 
./objects/win/Wguicore/Wclient.win.o: ./source/win/Wguicore/Wclient.win.cpp ./source/win/Wguicore/Wclient.win.hpp 
	$(win_CC) ./source/win/Wguicore/Wclient.win.cpp $(win_CFLAGS) -o ./objects/win/Wguicore/Wclient.win.o $(win_DEFFS) 
#end
