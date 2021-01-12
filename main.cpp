#include <iostream>

#include "language.hpp"

int main()
{
    std::cout << "Pilih bahasa/Select language:";
    std::cout << "\n1. Bahasa Indonesia/Indonesian";
    std::cout << "\n2. Bahasa enggres/English";
    std::cout << "\nPilihan Anda/Your choice: ";
    int choice;
    std::cin >> choice;
    std::cout << language::get_instance("en")["hinf_waiting_client"];
}
