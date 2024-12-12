#include <iostream>
#include <limits>
#include <random>

#define USERS 3

typedef struct Person {
  std::string name;
  std::int16_t age;
  std::uint32_t oid;
} person_t;

int main(void) {

  std::random_device dev;
  std::mt19937 rng(dev());
  std::uniform_int_distribution<std::mt19937::result_type> dist6(
      0, std::numeric_limits<std::uint32_t>::max());

  person_t persons[USERS];
  person_t *pptr{persons};

  for (size_t i = 0; i < USERS; i++) {
    std::cout << "Enter a name for person " << i + 1 << "." << std::endl
              << "Input: ";
    std::cin >> persons[i].name;
    std::cin.clear();
    std::cin.ignore();

    std::cout << "Enter an age for person " << i + 1 << "." << std::endl;
    std::cin >> persons[i].age;
    while (std::cin.fail()) {
      std::cout << "Input ";
      std::cin.clear();
      std::cin.ignore(256, '\n');
      std::cin >> persons[i].age;
    };

    persons[i].oid = dist6(rng);
  }

  std::cout << "Pre-sort" << std::endl;
  for (size_t i = 0; i < USERS; i++) {
    std::cout << "Order " << i + 1 << " | Name: " << pptr[i].name
              << "\t\tAge: " << pptr[i].age << "\t\tID: " << pptr[i].oid
              << std::endl;
  }

  std::cout << "Post-sort" << std::endl;
  while (true) {
    bool _end = true;
    for (size_t i = 0; i < USERS - 1; i++) {
      if (pptr[i].oid > pptr[i + 1].oid) {
        person_t _temp{pptr[i]};
        pptr[i] = pptr[i + 1];
        pptr[i + 1] = _temp;
        _end = false;
      }
    }
    if (_end)
      break;
  }

  for (size_t i = 0; i < USERS; i++) {
    std::cout << "Order " << i + 1 << " | Name: " << pptr[i].name
              << "\t\tAge: " << pptr[i].age << "\t\tID: " << pptr[i].oid
              << std::endl;
  }

  return 0;
}
