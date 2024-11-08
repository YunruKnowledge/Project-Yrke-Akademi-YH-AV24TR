#include <inttypes.h>
#include <stdint.h>
#include <stdio.h>

uint64_t countSteps(const unsigned int _disk_amount);
void countTime(const uint64_t _seconds, int _seconds_per_step);

int main(void) {
  countTime(countSteps(3), 5);
  return 0;
}

uint64_t countSteps(const unsigned int _disk_amount) {
  if (_disk_amount > sizeof(uint64_t) * 8) {
    (void)printf("\n%i: ERROR, NOT ENOUGH BYTES.\n", __LINE__);
    (void)printf("%i: AMOUNT OF BYTES REQUESTED: [%u] - INPUTTED: [%u]\n",
                 __LINE__, _disk_amount / 8, _disk_amount);
  } else {
    uint64_t _bitTotal = 0;
    for (uint64_t i = 0; i < (uint64_t)_disk_amount; i++) {
      _bitTotal = (_bitTotal << 1) | 1;
    }
    (void)printf("Steps needed: %" PRIu64 "\n", _bitTotal);
    return _bitTotal;
  }
  return 0;
}

void countTime(const uint64_t _steps, int _seconds_per_step) {
  const uint64_t seconds = _steps * _seconds_per_step;
  const uint64_t minutes = _steps / (60 * _seconds_per_step);
  const uint64_t hours = _steps / (3600 * _seconds_per_step);
  const uint64_t days = hours / 24;
  const uint64_t months = days / 31;
  const uint64_t years = days / 364;

  // shift by 2 to bypass missmatch between steps - abit janky
  if ((seconds == _steps || (seconds >> 2) == (_steps >> 2)) &&
      _seconds_per_step > 1) {
    printf("\n%i: MAX AMOUNT REACHED, %" PRIu64 " NOT VALID\n", __LINE__,
           seconds);
  } else {
    (void)printf("\n");
    (void)printf(
        "If it took %i second for each step, it would take a estimate of:\n",
        _seconds_per_step);
    (void)printf("\n");
    (void)printf("\t%20" PRIu64 " seconds\n", seconds);
    (void)printf("\t%20" PRIu64 " minutes\n", minutes);
    (void)printf("\t%20" PRIu64 " hours\n", hours);
    (void)printf("\t%20" PRIu64 " days\n", days);
    (void)printf("\t%20" PRIu64 " months\n", months);
    (void)printf("\t%20" PRIu64 " years\n", years);
    (void)printf("\n");
  }
}
