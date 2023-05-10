/**
 * @file StringUtils.h
 * @brief Contains declaration of StringUtils functions
 */

#ifndef __STRINGUTILS_H__
#define __STRINGUTILS_H__

#include <string>

namespace excpp {

  /**
   * @brief The StringUtils namespace
   */
namespace StringUtils {

  /**
   * @brief Formats the input string using the given format
   *
   * @param[in] format a C-style string format
   * @param[in] the arguments to format
   *
   * @return the formatted string
   *
   * @note All arguments are implicitly converted to std::string before being appended
   */
std::string format(const char *format, ...);

};
} // namespace excpp

#endif // __STRINGUTILS_H__

