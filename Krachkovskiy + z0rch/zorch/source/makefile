all: main.exe
main.exe: main.o RobotControl.o MainWindow.o ../../../objects/all/utilcore/logger.win.all.o
	i586-mingw32msvc-g++ main.o RobotControl.o MainWindow.o ../../../objects/all/utilcore/logger.win.all.o -o main.exe -mwindows -lcomctl32 WS2_32.Lib
main.o: main.cpp
	i586-mingw32msvc-g++ main.cpp -c -o main.o
RobotControl.o: RobotControl.cpp
	i586-mingw32msvc-g++ RobotControl.cpp -c -o RobotControl.o
MainWindow.o: MainWindow.cpp
	i586-mingw32msvc-g++ MainWindow.cpp -c -o MainWindow.o

