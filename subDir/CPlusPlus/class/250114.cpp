
// #include <ctime>
#include <chrono>
#include <iostream>
#include <string>

class Game {
protected:
  std::string version;
  Game(const std::string &_version) : version{_version} {};
};

class Skin {
protected:
  int type{0};
  Skin(const int _type = 1) : type{_type} {}
};

class Doll final : private Game, private Skin {
  std::string name;
  size_t index;

  std::uint64_t getLiveTime(void) {
    using namespace std::chrono;
    return duration_cast<milliseconds>(system_clock::now().time_since_epoch())
        .count();
  }

public:
  Doll(const std::string &_name, const std::string &_version,
       const int _skin = 1)
      : name{_name}, Game{_version}, Skin{_skin},
        index{static_cast<size_t>(getLiveTime())} {
    if (_version == "1.0F") {
      name = "Mila";
      type = 1;
    } else if ( _version == "1.1") {
      name = "Sleepy Mita";
      type = 1;
      index = 1;

    }
  };

  friend std::ostream &operator<<(std::ostream &_os, const Doll &_mita) {
    _os << "Name: " << _mita.name << " | Skin: " << _mita.type;
    _os << " | Index: " << _mita.index;
    return _os;
  };
};

class Player : protected Game {
  std::string name;
  std::string version;
  Doll mita;

public:
  Player(const std::string &_name, const std::string &_version,
         const int _mitaSkin = 1)
      : name{_name}, version{_version}, mita{"Mita", _version, _mitaSkin},
        Game{_version} {};

  void config(void) {
    std::cout << "Player info:" << std::endl
              << "Name: " << name << " | Version: " << version << std::endl
              << "Mita info: " << std::endl
              << mita << std::endl;
  };
};

int main(void) {
  Player *session = new Player{"Pwayer2", "1.9", 3};
  session->config();
  delete session;

  session = new Player{"Wocky", "1.0F", 3};
  session->config();
  delete session;

  session = new Player{"Bocky", "1.1", 3};
  session->config();
  delete session;
  
  return 0;
}