.PHONY: build run

clean:
	@cmake -E remove_directory bin
	@cmake -E remove_directory build

build-debug:
	@cmake -B build -S . --preset Windows-x64-Debug
	@cmake --build build

build-release:
	@cmake -B build -S . --preset Windows-x64-Release
	@cmake --build build

run:
	@./bin/Sparky