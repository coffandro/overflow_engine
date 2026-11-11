DEF_FLAGS=-Wall -std=c++11 -D_DEFAULT_SOURCE -Wno-missing-braces -Wunused-result -Os
INCLUDES=-Iinclude -Iinclude/raylib/src
LINKING=-Linclude -lraylib
RAYLIB_ARGS=-sUSE_GLFW=3 -sASYNCIFY -sALLOW_MEMORY_GROWTH=1 -sSTACK_SIZE=2097152
SYS=include/libraylib.a -DPLATFORM_WEB -s 'EXPORTED_FUNCTIONS=["_free","_malloc","_set_dimensions", "_main"]' -s EXPORTED_RUNTIME_METHODS=["ccall","cwrap","FS","addRunDependency","removeRunDependency"]

DEFAULT_ARGS=$(INCLUDES) $(LINKING) $(RAYLIB_ARGS)

BIN_PATH="build/"

build-libs:
	./raylib.sh

build-game:
	mkdir -p $(BIN_PATH)

	emcc -o $(BIN_PATH)index.html src/*.cpp src/*/*.cpp \
		$(DEFAULT_ARGS) \
		--shell-file src/shell.html \
		$(SYS)

	sed -i '/event\.target\.setCapture()/d' $(BIN_PATH)index.js

watch-game:
	while true; do \
        $(MAKE) build-game; \
        inotifywait -qre close_write .; \
    done