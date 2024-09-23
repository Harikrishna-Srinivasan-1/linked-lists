#include "exception.h"


/**
 * @brief Constructs an Exception with a detailed error message.
 *
 * This constructor initializes the Exception base class with a standard error message,
 * and also formats a detailed message including the file name, line number, and function
 * where the exception was thrown.
 *
 * @param msg The error message.
 * @param file The name of the file where the exception occurred.
 * @param line The line number where the exception occurred.
 * @param func The name of the function where the exception occurred.
 */
Exception::Exception(const std::string &msg, const char *file, int line, const char *func):
    std::runtime_error(msg), 
    err_msg("\n" + msg + " in file `" + file + "` at line: " + std::to_string(line) + " in function " + func) {}

/**
 * @brief Returns the detailed error message.
 *
 * @return A C-style string containing the detailed error message with additional context.
 */
const char* Exception::what() const noexcept 
{
    return (this->err_msg).c_str();
}

/**
 * @brief Constructs an IndexError with a detailed error message.
 *
 * This constructor initializes the base Exception class with a message specifically for
 * index errors, and includes file, line, and function information.
 *
 * @param msg The error message.
 * @param file The name of the file where the exception occurred.
 * @param line The line number where the exception occurred.
 * @param func The name of the function where the exception occurred.
 */
IndexError::IndexError(const std::string &msg, const char *file, int line, const char *func):
    Exception("\nIndexError: " + msg, file, line, func) {}

/**
 * @brief Constructs a ValueError with a detailed error message.
 *
 * This constructor initializes the base Exception class with a message specifically for
 * value errors, and includes file, line, and function information.
 *
 * @param msg The error message.
 * @param file The name of the file where the exception occurred.
 * @param line The line number where the exception occurred.
 * @param func The name of the function where the exception occurred.
 */
ValueError::ValueError(const std::string &msg, const char *file, int line, const char *func):
    Exception("\nValueError: " + msg, file, line, func) {}

/**
 * @brief Constructs a TypeError with a detailed error message.
 *
 * This constructor initializes the base Exception class with a message specifically for
 * type errors, and includes file, line, and function information.
 *
 * @param msg The error message.
 * @param file The name of the file where the exception occurred.
 * @param line The line number where the exception occurred.
 * @param func The name of the function where the exception occurred.
 */
TypeError::TypeError(const std::string &msg, const char *file, int line, const char *func):
    Exception("\nTypeError: " + msg, file, line, func) {}
