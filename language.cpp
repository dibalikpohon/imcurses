#include "language.hpp"
#include <cstring>
#include <istream>
#include <fstream>
#include <algorithm>
#include <type_traits>

language::language(const char* language_code)
{
    static_assert(std::is_pointer<decltype(language_code)>::value, "language_code should not be null!");
    std::strncpy(this->language_code.data(), language_code, 3);
    kv_langpair& langpair = this->lang;
    
    char *file_path = new char[8];
    std::sprintf(file_path, "lang/%2s", language_code);
    std::ifstream language_file { file_path, std::ios_base::in };
    delete[] file_path;

    char *lines = new char[256];
    while (!language_file.eof()) {
        memset(lines, 0, 256);
        language_file.getline(lines, 256);

        if (lines[0] == '#') continue; // skip comment
        if (language_file.gcount() <= 1) continue; // skip line or skip nothing
        
        /* start to tokenize */
        // find the equal('=') sign
        char* equal_sign = std::find(lines, lines + 256, '=');
        
        // find the first quote
        char* quote1 = std::find(lines, lines + 256, '\"');
        
        // find the second quote
        char* quote2 = std::find(quote1 + 1, lines + 256, '\"');
        
        // get the keys
        std::string key(lines, equal_sign);

        // get the value
        std::string value(quote1 + 1, quote2);

        langpair[key] = value;
    }
    delete[] lines;
}

language& language::get_instance(const char* language_code)
{
    static language instance_ { language_code };
    return instance_;
}

const language::key_result& language::operator[] (const char* key)
{
    return this->lang[key];
}
