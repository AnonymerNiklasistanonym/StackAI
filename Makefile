BUILD_DIR=build
CMAKE_GENERATOR=Unix Makefiles
CMAKE_BUILD_TYPE=Release
CMAKE_BUILD_OPTIONS=-G "$(CMAKE_GENERATOR)" \
                    -DCMAKE_BUILD_TYPE="$(CMAKE_BUILD_TYPE)"
CMAKE_BUILD_OPTIONS_EXTRA=-DCHECK_CODE=OFF \
                          -DFORMAT_CODE=OFF
CMAKE_BUILD_OPTIONS_EXTRA_CHECK=-DCHECK_CODE=ON \
                                -DFORMAT_CODE=OFF
CMAKE_PROJECT_NAME=StackAI

.PHONY: build check clean

all: build

build:
	cmake -E make_directory "$(BUILD_DIR)"
	cmake -E chdir "$(BUILD_DIR)" cmake $(CMAKE_BUILD_OPTIONS) $(CMAKE_BUILD_OPTIONS_EXTRA) ..
	cmake -E chdir "$(BUILD_DIR)" cmake --build . -- -j 4 2>&1 | tee build.log

check:
	cmake -E make_directory "$(BUILD_DIR)"
	cmake -E chdir "$(BUILD_DIR)" cmake $(CMAKE_BUILD_OPTIONS) $(CMAKE_BUILD_OPTIONS_EXTRA_CHECK) ..
	cmake -E chdir "$(BUILD_DIR)" cmake --build . -- -j 4 2>&1 | tee cppcheck.log

clean:
	rm -rf "$(BUILD_DIR)"

run: build
	./"$(BUILD_DIR)"/"$(CMAKE_PROJECT_NAME)"
