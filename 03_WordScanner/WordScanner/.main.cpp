#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include "../String/KMP.h"
#include "../Tools/ColorIO.h"
#include "../Tools/ConsoleSetting.h"

std::ifstream targetFile;
std::ifstream patternFile;

int main() {
    std::string targetName;
    std::string patternName;
    scui::cout(6) << "Enter target file name: ";
    scui::cin(4) >> targetName;
    scui::cin().ignore();
    targetFile.open(targetName);
    while (targetFile.fail()) {
        scui::cout(6) << "Unable to open file \"" << targetName << "\", please enter again! : ";
        scui::cin(4) >> targetName;
        scui::cin().ignore();
    }
    scui::cout(6) << "Enter pattern file name: ";
    scui::cin(4) >> patternName;
    scui::cin().ignore();
    patternFile.open(patternName);

    // Store all pattern words to a vector.
    std::vector<std::string> pattern;
    std::string temp;
    while (patternFile >> temp) {
        pattern.push_back(temp);
    }

    // Store the file to a string vector in splited lines.
    std::vector<std::string> file;
    std::string splitedLines;
    while (std::getline(targetFile, splitedLines)) {
        file.push_back(splitedLines);
    }

    // For every pattern in {pattern}:
    for (auto& pat : pattern) {
        scui::cout(6) << "------------------------------\n";
        scui::cout(6) << "WORD \"" << pat << "\":\n";

        int sum = 0; // The number of all found words.

        // For every line in {file}:
        for (int i = 0; i < file.size(); ++i) {
            std::vector<int> result = KMP(file[i], pat);
            // If {result} is not empty:
            if (result.size()) {
                scui::cout(6) << "\t| Line " << i + 1 << ": ";
            }

            // Print all the found position:
            for (auto position : result) {
                scui::cout() << position << " ";
            }

            // Update the number of found words:
            sum += result.size();
        }

        scui::cout(6) << "TOTAL: " << sum;
        scui::cout(6) << "\n------------------------------\n";
    }
    std::cin.get();
}