#include <iostream>
#include <string>

std::string space_message(const std::string &message);

int main(void) {
    std::string output = space_message("IF[2E]LG[5O]D");
    std::cout << output << std::endl;
    return 0;
}

std::string space_message(const std::string &message) {
    std::string decrypted_message;

    for (int i = 0; i < message.length(); i++) {
        if (message[i] == '[') {
            int repeat{0};
            std::string repeat_message;

            for (int j = i + 1; j < message.length(); j++) {
                if (message[j] == ']') {
                    break;
                } else if (std::isdigit(message[j])) {
                    repeat += (message[j] - '0');
                } else {
                    repeat_message += message[j];
                }
            }

            for (int k = 0; k < repeat; k++) {
                decrypted_message += repeat_message;
            }
        } else if (message[i] != ']' && !std::isdigit(message[i])) {
            decrypted_message += message[i];
        }
    }

    return decrypted_message;
}
