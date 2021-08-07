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
CMAKE_PROJECT_NAME_TEST=tests

.PHONY: build check clean test

all: build

build:
	set -o pipefail; \
	cmake -B "$(BUILD_DIR)" -DCMAKE_BUILD_TYPE=$(CMAKE_BUILD_TYPE)
	set -o pipefail; \
	cmake --build "$(BUILD_DIR)" --config $(CMAKE_BUILD_TYPE) --target $(CMAKE_PROJECT_NAME) \
	-- -j 4 2>&1 | tee build.log
	set +o pipefail

build_test:
	set -o pipefail; \
	cmake -B "$(BUILD_DIR)" -DCMAKE_BUILD_TYPE=$(CMAKE_BUILD_TYPE) 2>&1 | tee test.log
	set -o pipefail; \
	cmake --build "$(BUILD_DIR)" --config $(CMAKE_BUILD_TYPE) --target $(CMAKE_PROJECT_NAME_TEST) \
	-- -j 4 2>&1 | tee -a test.log
	set +o pipefail

check:
	cmake -E make_directory "$(BUILD_DIR)"
	cmake -E chdir "$(BUILD_DIR)" cmake $(CMAKE_BUILD_OPTIONS) $(CMAKE_BUILD_OPTIONS_EXTRA_CHECK) ..
	cmake -E chdir "$(BUILD_DIR)" cmake --build . -- -j 4 2>&1 | tee cppcheck.log

clean:
	rm -rf "$(BUILD_DIR)"

test: build_test
	set -o pipefail; \
	ctest --test-dir "$(BUILD_DIR)" --verbose 2>&1 | tee -a test.log
	set +o pipefail

run: build
	./"$(BUILD_DIR)"/"$(CMAKE_PROJECT_NAME)"
