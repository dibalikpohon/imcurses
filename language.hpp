#include <unordered_map>
#include <array>
#include <string>

#ifndef LANGUAGE_H_ // include guard

#define LANGUAGE_H_
class language
{
private:
    using kv_langpair = std::unordered_map<std::string, std::string>;
    kv_langpair lang;
    std::array<char, 3> language_code;

    language(const char*  language_code);

public:
    using key_result = std::string;
    /* deleted functions */
    language() = delete;
    language(language const& rhs) = delete;
    language& operator=(language const& rhs) = delete;

    static language& get_instance(const char* language_code = nullptr);
    const char* get_language_code();
    const key_result& operator[](const char* key);
};

#endif
