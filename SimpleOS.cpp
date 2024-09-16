#include <iostream>
#include <string>


void displayHelp();
void runCommand(const std::string& command);

void runCommand(const std::string& command) {
    if (command == "help") {
        displayHelp();
    } else if (command == "version") {
        std::cout << "SimpleOS v1.0" << std::endl;
    } else if (command == "exit") {
        std::cout << "Exiting SimpleOS..." << std::endl;
        exit(0); 
    } else {
        std::cout << "Unknown command: " << command << std::endl;
    }
}


void displayHelp() {
    std::cout << "SimpleOS Help:" << std::endl;
    std::cout << "help    - Show this help message" << std::endl;
    std::cout << "version - Show OS version" << std::endl;
    std::cout << "exit    - Exit the OS" << std::endl;
}

int main() {
    std::string command;

    std::cout << "Welcome to SimpleOS v1.0" << std::endl;
    std::cout << "Type 'help' for a list of commands." << std::endl;

    while (true) {
        std::cout << "> ";
        std::getline(std::cin, command); 
        runCommand(command); 
    }

    return 0;
}
