#pragma once

#include <array>
#include <iostream>

#include "utils.h"

// Numbered boxes, containing numbered cards

namespace hundred {

template<size_t COUNT>
class Boxes {
  std::array<size_t, COUNT> boxes_;

public:
  Boxes() {
    std::iota(boxes_.begin(), boxes_.end(), 1);
    hundred::shuffle(boxes_.begin(), boxes_.end());
  }

  size_t size() const { return COUNT; }

  // boxes number starts from 1
  size_t number(size_t index) const { return boxes_[index - 1]; }

  void print() const {
    #ifdef LOG_DEBUG
    std::cout << "boxes contents:" << std::endl;
    for (size_t i = 0; i < boxes_.size(); ++i) {
      std::cout << i + 1 << ":" << boxes_[i] << std::endl;
    }
    #endif
  }
};
}