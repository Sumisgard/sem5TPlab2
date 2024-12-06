#include "Task.hpp"

namespace smd
{
    void Task::readAndPrint(std::string path)
    {
        std::ifstream file(path);
        if (!file) 
        {
            std::cout << "Unable to open file";
            exit(1);
        }

        // First pass - count sentences
        int questionCount = 0;
        int exclamationCount = 0;
        std::string temp;
        char ch;
        
        while (file.get(ch)) {
            if (ch == '?') questionCount++;
            if (ch == '!') exclamationCount++;
        }

        // Create dynamic arrays
        std::string* questionSentences = new std::string[questionCount];
        std::string* exclamationSentences = new std::string[exclamationCount];
        
        // Reset file pointer
        file.clear();
        file.seekg(0);
        
        // Second pass - store sentences
        std::string sentence;
        int qIndex = 0, eIndex = 0;
        
        while (file.get(ch)) {
            sentence += ch;
            if (ch == '?' || ch == '!' || ch == '.') {
                if (ch == '?') {
                    questionSentences[qIndex++] = sentence;
                }
                else if (ch == '!') {
                    exclamationSentences[eIndex++] = sentence;
                }
                sentence.clear();
            }
        }

        // Print results
        std::cout << "Interrogative sentences:\n";
        for (int i = 0; i < questionCount; i++) {
            std::cout << questionSentences[i] << "\n";
        }

        std::cout << "\nExclamatory sentences:\n";
        for (int i = 0; i < exclamationCount; i++) {
            std::cout << exclamationSentences[i] << "\n";
        }

        // Cleanup
        delete[] questionSentences;
        delete[] exclamationSentences;
        file.close();
    }
}