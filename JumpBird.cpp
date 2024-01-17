// JumpBird.cpp : Defines the entry point for the application.
// Made by Suraj as a self test

#include "JumpBird.h"
#include "Windows.h"

#include <string>
#include <cstdlib>

using namespace std;


class StrHelper {
public:
	string line_gen(int len, char character) {
		string output = "";
		for (int i = 0; i <= len; i++) {
			output += character;
		}
		return output;
	}

	string col_gen(int len, int offset, char offset_char, string line) {
		string output;
		string offset_str(offset, offset_char);

		for (int i = 0; i < len; ++i) {
			output += offset_str + line + "\n";
		}

		return output;
	}
};


class Canvas {
	int screen_height = 26;
	int screen_width = 100;
	int max_fps;

	StrHelper* str_helper;
	Window* window;

private:
	string _canvas;

public:
	Canvas(int maxFps = 10) : str_helper(new StrHelper()), window(new Window()), _canvas(""), max_fps(maxFps) {}

	void render_screen() {
		_canvas = "";
		window->clear_screen();
		_canvas = add_platform();
		cout << _canvas;
	}

	string add_platform() {
		int random_height = rand() % screen_height;
		int random_width = rand() % (screen_width / 10);
		string _line = str_helper->line_gen(random_width, '.');
		string _col = str_helper->col_gen(screen_height, 0, ' ', _line);
		return _col;
	}

	~Canvas() {
		delete str_helper;
	}
};

int main() {
	Canvas game = Canvas();
	for (;;) {
		game.render_screen();
		Sleep(500);
	}
	return 0;
}
