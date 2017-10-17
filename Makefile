all: clean
	meson debug
	ninja -C debug
	./debug/base_converter

clean:
	rm -rf debug
