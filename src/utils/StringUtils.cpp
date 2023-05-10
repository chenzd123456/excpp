#include "utils/StringUtils.h"

#include <cstdarg>

namespace excpp {
namespace StringUtils {

std::string format(const char *format, ...) {
    va_list args;
    va_start(args, format);

    // Calculate required space by calling vsnprintf first
    int size = vsnprintf(nullptr, 0, format, args);
    if (size <= 0) {
        va_end(args);
        return "";
    }

    // Reset the args pointer
    va_end(args);
    va_start(args, format);

    // Allocate space and write to formatted string
    std::string result(size + 1, '\0');
    vsnprintf(const_cast<char *>(result.data()), (size_t)(size + 1), format,
              args);

    va_end(args);
    result.resize(size);  // Adjust the string length
    return result;
}

}  // namespace StringUtils
}  // namespace excpp
