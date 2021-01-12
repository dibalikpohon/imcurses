#include <iostream>
#include <cstdarg>

#include "language.hpp"

int choice(int min, int max);
int prompt(const char* prompt_header, const char* the_prompt,
           const char* error_message,
           int min, int max, size_t choices_count, ...);

int main()
{
/*    std::cout << "Pilih bahasa/Select language:";
    std::cout << "\n1. Bahasa Indonesia/Indonesian";
    std::cout << "\n2. Bahasa enggres/English";
    std::cout << "\nPilihan Anda/Your choice: ";
    int choice;
    std::cin >> choice;*/
    int lang = prompt("Pilih bahasa/Select language:", "Pilihan Anda/Your choice: ",
                      "Mohon pilih dengan benar!/Please choose correctly!", 1, 2, 2,
                      "Bahasa Indonesia/Indonesian", "Bahasa Inggris/English");
    language::get_instance("en");
    language::get_instance("id");
    std::cout << language::get_instance()["binf_istyping"];
}

int prompt(const char* prompt_header, const char* the_prompt,
           const char* error_message,
           int min, int max, size_t choices_count, ...)
{
    std::va_list args;
    va_start(args, choices_count);

    // prompting
    std::cout << prompt_header << std::endl;

    for (size_t i = 0; i < choices_count; i++)
        std::cout << (min + i) << ". " << va_arg(args, char*) << '\n';
    std::cout.flush();
    va_end(args);


    // choice
    int ch = min - 1;
    do {
        std::cout << the_prompt;
        std::cin.clear();
        std::cin >> ch;
        if (std::cin.fail() || (ch < min || ch > max)) {
            std::cin.ignore(std::numeric_limits<std::streamsize>::max());
            std::cout << error_message << std::endl;
        }
    } while ((ch < min || ch > max) || std::cin.fail());

    return ch;
}
