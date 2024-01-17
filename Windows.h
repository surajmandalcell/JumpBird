#include <iostream>

#ifdef _WIN32
#include <windows.h>
#else
#include <unistd.h>
#endif

using namespace std;

class Window {
public:
	static void clear_screen() {
		#ifdef _WIN32
				// Windows-specific code
				HANDLE                     hStdOut;
				CONSOLE_SCREEN_BUFFER_INFO csbi;
				DWORD                      count;
				DWORD                      cellCount;
				COORD                      homeCoords = { 0, 0 };

				hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
				if (hStdOut == INVALID_HANDLE_VALUE) return;

				// Get the number of cells in the current buffer 
				if (!GetConsoleScreenBufferInfo(hStdOut, &csbi)) return;
				cellCount = csbi.dwSize.X * csbi.dwSize.Y;

				// Fill the entire buffer with spaces
				if (!FillConsoleOutputCharacter(
					hStdOut,
					(TCHAR)' ',
					cellCount,
					homeCoords,
					&count
				)) return;

				// Move the cursor home
				SetConsoleCursorPosition(hStdOut, homeCoords);
		#else
				// Unix/Linux-specific code
				cout << "\033[2J\033[1;1H";
		#endif
	}
};