#include "colors.hpp"

const Color darkGrey = {26, 31, 40, 255};
const Color lightPink = {238, 208, 232, 255};
const Color yellow = {255, 255, 74, 255};
const Color orange = {255, 136, 15, 255};
const Color skyBlue = {168, 202, 255, 255};
const Color navyBlue = {50, 58, 255, 255};
const Color brightLime = {161, 224, 141, 255};

std::vector<Color> getCellColors()
{
    return {darkGrey, lightPink, yellow, orange, skyBlue, navyBlue, brightLime};
}