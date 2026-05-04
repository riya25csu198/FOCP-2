#include <iostream>
#include <vector>
#include <string>
#include <random>   // Modern random library

// Function to get valid user name
std::string getUserName() {
    std::string name;

    while (true) {
        std::cout << "Enter student name: ";
        std::getline(std::cin, name);

        // Check for empty or spaces-only input
        if (!name.empty() && name.find_first_not_of(' ') != std::string::npos) {
            return name;
        }

        std::cout << "Invalid input. Please enter a valid name.\n";
    }
}

// Function to replace {name} placeholder
std::string replaceName(const std::string& text, const std::string& name) {
    std::string result = text;
    size_t pos = 0;

    while ((pos = result.find("{name}", pos)) != std::string::npos) {
        result.replace(pos, 6, name);
        pos += name.length();
    }

    return result;
}

// Function to get random excuse
std::string getRandomExcuse(const std::vector<std::string>& excuses) {
    // Random device + Mersenne Twister engine
    static std::random_device rd;
    static std::mt19937 gen(rd());

    std::uniform_int_distribution<> dist(0, excuses.size() - 1);
    return excuses[dist(gen)];
}

int main() {
    // Step 1: Get user input
    std::string name = getUserName();

    // Step 2: Store excuses
    std::vector<std::string> excuses = {
        "{name} couldn't complete the assignment because the laptop battery died unexpectedly.",
        "{name} was about to submit the homework when the Wi-Fi suddenly stopped working.",
        "{name} tried finishing the assignment, but the keyboard stopped responding.",
        "{name}'s file got corrupted just before submission.",
        "{name} accidentally deleted the assignment while organizing files.",
        "{name}'s system froze during the final save.",
        "{name} lost internet connection during upload.",
        "{name}'s USB drive got damaged with the assignment inside.",
        "{name} faced a sudden power cut while completing the work.",
        "{name}'s software crashed repeatedly during the assignment."
    };

    // Safety check
    if (excuses.empty()) {
        std::cout << "No excuses available.\n";
        return 1;
    }

    // Step 3: Generate and process excuse
    std::string excuse = getRandomExcuse(excuses);
    excuse = replaceName(excuse, name);

    // Step 4: Display result
    std::cout << "\nGenerated Excuse:\n" << excuse << std::endl;

    return 0;
}
