INSTALL_DIR := "C:\\XboxGames\\Minecraft Legends - Windows\\Content\\"

all: clean build

build:
	mkdir -p ./build/
	g++ -municode -std=c++23 -static -Wall -Wpedantic -O3 -shared -iquote ./include/ ./src/mlml/*.cpp ./src/*.cpp ./XInput1_4.def -o ./build/XINPUT1_4.dll

clean:
	rm -rf ./build/ || true

install:
	cp ./build/XINPUT1_4.dll $(INSTALL_DIR)

run: install
	$(INSTALL_DIR)MinecraftLegends.Windows.exe
