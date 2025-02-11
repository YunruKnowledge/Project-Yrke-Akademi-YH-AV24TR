
#include <cstdint>
#include <cstdlib>
#include <ctime>
#include <iostream>

class TicTac {
private:
  static constexpr uint8_t AI_TRY_LIMIT{254};
  static constexpr uint8_t GAME_SIZE{9};

  enum player_types { player1 = 1, player2, ai, end };
  uint8_t state_game[GAME_SIZE]{0};
  uint8_t state_player{player1};

  bool enable_ai;

public:
  TicTac(bool _AI = true) : enable_ai{_AI} {};

  friend std::ostream &operator<<(std::ostream &_os, TicTac _game) {

    _os << "=====";
        _os << std::endl;
    _os << "|";
    for (size_t i = 0; i < GAME_SIZE; i++) {
      if ((i != 0) && ((i) % 3 == 0)) {
        _os << "|";
        _os << std::endl;
        _os << "|";
      }

      if (_game.state_game[i] == 0) {
        _os << "E";
      } else if (_game.state_game[i] == player1) {
        _os << "X";
      } else {
        _os << "O";
      }
    }
    _os << "|";
        _os << std::endl;
    _os << "=====";
    return _os;
  }

private:
  void next_player(void) {
    if (enable_ai) {
      if (state_player == player1) {
        state_player = ai;
      } else {
        state_player = player1;
      }
    } else {
      if (state_player == player1) {
        state_player = player2;
      } else {
        state_player = player1;
      }
    }
  }

  void next_player(const uint8_t _force) {
    if (_force >= player1 && _force <= ai) {
      state_player = _force;
    }
  }

  int check_game(void) {
    uint8_t winner{0};
    for (uint8_t player = player1; player < ai; player++) {
      if (state_game[0] == player && state_game[1] == player &&
          state_game[2] == player) {
        winner = player; // top row
      } else if (state_game[0] == player && state_game[3] == player &&
                 state_game[6] == player) {
        winner = player; // left col
      } else if (state_game[6] == player && state_game[7] == player &&
                 state_game[8] == player) {
        winner = player; // bottom row
      } else if (state_game[2] == player && state_game[5] == player &&
                 state_game[8] == player) {
        winner = player; // right col
      } else if (state_game[0] == player && state_game[4] == player &&
                 state_game[8] == player) {
        winner = player; // diagonal T-left to B-right
      } else if (state_game[2] == player && state_game[4] == player &&
                 state_game[6] == player) {
        winner = player; // diag T-right to B-left
      } else {
        ; // no winners
      };
    }
    return winner;
  }

public:
  bool play(const uint8_t _slot) {
    bool status{false};

    if (state_game[_slot - 1] == 0) {
      state_game[_slot - 1] = state_player;
      if (check_game()) {
        next_player(end);
      } else {
        next_player();
      }
      status = true;
    } else {
      ;
    }

    return status;
  }

  bool play(void) {
    bool status{false};
    srand(time(NULL));

    if (enable_ai && state_player == ai) {
      uint8_t temp{static_cast<uint8_t>(rand() % GAME_SIZE)};
      uint8_t limit;
      while (!play(temp + 1)) {
        if (limit >= AI_TRY_LIMIT) {
          break;
        } else {
          temp = static_cast<uint8_t>(rand() % GAME_SIZE);
          limit++;
        }
      }

      if (limit >= AI_TRY_LIMIT) {
        ;
      } else {
        status = true;
      }
    } else {
      ;
    }

    return status;
  }
};

int main(void) {
  TicTac session;
  std::cout << session << std::endl;
  session.play(2);
  std::cout << session << std::endl;
  return 0;
}