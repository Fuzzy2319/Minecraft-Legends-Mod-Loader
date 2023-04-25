INSTALL_DIR = "C:\\XboxGames\\Minecraft Legends - Windows\\Content\\"

all: clean build

build:
	mkdir -p ./build/
	x86_64-w64-mingw32-gcc -shared -o ./build/XINPUT1_4.dll ./src/dllmain.cpp ./XInput1_4.def -s

clean:
	rm -rf ./build/ || true

install: all
    rm -f $(INSTALL_DIR)XINPUT1_4.dll.bak
    mv $(INSTALL_DIR)XINPUT1_4.dll $(INSTALL_DIR)XINPUT1_4.dll.bak
    cp ./build/XINPUT1_4.dll $(INSTALL_DIR)
