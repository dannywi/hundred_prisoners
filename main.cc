#include <iostream>
#include <vector>

//#define LOG_DEBUG

#include "prisoner.h"
#include "boxes.h"
#include "picker.h"

using namespace std;

int main() {
  cout << "Help the prisoners survive!" << endl;

  constexpr size_t PRISONERS = 14;
  constexpr size_t TRIALS = 100'000;

  struct Combo {
    const char* title;
    bool(*picker)(const hundred::Boxes<PRISONERS>&, const hundred::Prisoner&);
    size_t survived_count;
  };

  vector<Combo> combos {
    { "picker_random", hundred::picker_random, 0 },
    { "picker_follow", hundred::picker_follow, 0 },
  };

  for (size_t i = 0; i < TRIALS; ++i) {
    hundred::Boxes<PRISONERS> boxes;
    auto prisoners = hundred::Prisoner::generate_prisoners<PRISONERS>();

    for (auto& combo : combos) {
      #ifdef LOG_DEBUG
      cout << " .. " << i << ": Running - " << combo.title << endl;
      #endif

      bool res = hundred::run(boxes, prisoners, combo.picker);

      #ifdef LOG_DEBUG
      bs.print();
      cout << " .. ALL SURVIVED: " << (res ? "YES" : "NO") << endl;
      #endif
      if (res) {
        ++combo.survived_count;
      }
    }
  }

  cout << "===========" << endl;
  cout << "TRIALS: " << TRIALS << endl;
  cout << "PRISONERS: " << PRISONERS << endl;
  for (auto const& combo : combos) {
    cout << "  " << combo.title << endl;
    cout << "    SURVIVED: " << combo.survived_count
      << " (" << 100 * combo.survived_count / static_cast<double>(TRIALS) << "%)" <<  endl;
  }
}