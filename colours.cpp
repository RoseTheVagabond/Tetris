#include "colours.h"
#include <vector>

const Color darkBlue = {0, 29, 62, 255};
const Color blue = {0, 53, 102, 255};
const Color orange = {255, 195, 0, 255};
const Color yellow = {255, 214, 10, 255};
const Color almostBlack = {0, 8, 20, 255};

std::vector<Color> getCellColours() {
    return {darkBlue, blue, orange, yellow, almostBlack};
}