#include <iostream>
#include <string>

bool pawn(int x1, int y1, int x2, int y2) {
	return x2 == x1 - 1 && y2 == y1 + 1 || x2 == x1 + 1 && y2 == y1 - 1 || x2 == x1 + 1 && y2 == y1 + 1 || x2 == x1 - 1 && y2 == y1 - 1 ? true : false;
}
