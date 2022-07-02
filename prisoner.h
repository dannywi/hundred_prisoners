#pragma once

#include <array>

// Numbered prisoners

namespace hundred {
class Prisoner {
  size_t number_;

public:
  size_t number() const { return number_; }

  template<size_t COUNT>
  static std::array<Prisoner, COUNT> generate_prisoners() {
    std::array<Prisoner, COUNT> res;
    for (size_t i = 0; i < COUNT; ++i) {
      res[i].number_ = i + 1;
    }
    return res;
  }
};

}