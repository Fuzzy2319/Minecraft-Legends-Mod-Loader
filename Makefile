INSTALL_DIR = "C:\\XboxGames\\Minecraft Legends - Windows\\Content\\"

all: clean build

build:
	mkdir -p ./build/
	g++ -municode -std=c++23 -static -Wall -O3 -shared -iquote ./include/ ./src/* ./XInput1_4.def -o ./build/XINPUT1_4.dll

clean:
	rm -rf ./build/ || true

install: all
    rm -f $(INSTALL_DIR)XINPUT1_4.dll.bak
    mv $(INSTALL_DIR)XINPUT1_4.dll $(INSTALL_DIR)XINPUT1_4.dll.bak
    cp ./build/XINPUT1_4.dll $(INSTALL_DIR)
