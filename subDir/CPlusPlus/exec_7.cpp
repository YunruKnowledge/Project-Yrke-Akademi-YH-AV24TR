#include <iostream>
#include <random>

#define MAX_ATTEMPTS 10

int main(void) {
  unsigned int _input{0}, _attempts{1}, _winningNumber{0};
  unsigned int _round{1}, _totalAttempts{1};
  bool _exit{false};

  std::random_device dev;
  std::mt19937 rng(dev());
  std::uniform_int_distribution<std::mt19937::result_type> dist6(0, 99);

  do {
    _attempts = 0;
    _winningNumber = dist6(rng);
    std::cout << "*Random number generated.*" << std::endl;

    do {
      std::cout << "Guess a number! (Between 0 - 99)" << std::endl;
      std::cout << "[" << _attempts << "/" << MAX_ATTEMPTS << "] Input: ";
      std::cin >> _input;
      std::cin.clear();
      std::cin.ignore();
      std::cout << std::endl;

      if (_attempts >= MAX_ATTEMPTS) {
        std::cout << "You lost! You've ran out of attempts." << std::endl;
      } else {
        if (_input == _winningNumber) {
          std::cout << "You found the winning number!" << std::endl;
          break;
        } else if (_input > _winningNumber) {
          std::cout << "The input is *larger* than the winning number!"
                    << " Try again :3" << std::endl;
        } else {
          std::cout << "Input is *smaller* than the winning number!"
                    << " Try again :P" << std::endl;
        }
      }

      _attempts++;
      _totalAttempts++;
    } while (_attempts <= MAX_ATTEMPTS);

    std::cout << "Would you like to replay? (Press '1')" << std::endl
              << "Input: ";
    std::cin >> _input;
    std::cin.clear();
    std::cin.ignore();
    if (_input != 1) {
      _exit = true;
    } else {
      _round++;
    }
  } while (!_exit);

  std::cout << std::endl << "End game stats:" << std::endl;
  std::cout << "You've played " << _round << " round(s)." << std::endl;
  std::cout << "You've used   " << _totalAttempts << " attempt(s)."
            << std::endl;
  std::cout << "You've saved  " << _round * MAX_ATTEMPTS - _totalAttempts
            << " attempt(s)." << std::endl;
  std::cout << "Exiting..." << std::endl;
  return 0;
}
