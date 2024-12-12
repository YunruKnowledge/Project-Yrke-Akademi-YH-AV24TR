#include "Colors.h"

namespace Color {

    // Constructor initializes the color code
    Modifier::Modifier(Code pCode) : code(pCode) {}

    // Overload the << operator to apply the ANSI escape code for coloring
    std::ostream& operator<<(std::ostream& os, const Modifier& mod) {
        return os << "\033[" << mod.code << "m";
    }
}
