#pragma once

#include "prisoner.h"
#include "boxes.h"
#include "utils.h"

namespace hundred {

namespace _inner {
  template<typename T>
  T chance_count(T boxes) {
    // prisoners can open half of the boxes
    return boxes / 2;
  }
}

template<typename BOXES, typename PRISONERS>
bool run(const BOXES& boxes, const PRISONERS& prisoners, bool(*picker)(const BOXES&, const Prisoner&)) {
  for (auto& p : prisoners) {
    if (!picker(boxes, p)) {
      return false;
    }
  }
  return true;
}

template<typename BOXES>
bool picker_random(const BOXES& boxes, const Prisoner& prisoner) {
  #ifdef LOG_DEBUG
  std::cout << "prisoner " << prisoner.number() << std::endl;
  #endif

  // random picker
  // first create a sequential
  std::vector<size_t> picks(boxes.size());
  std::iota(picks.begin(), picks.end(), 1);
  // shuffle it
  hundred::shuffle(picks.begin(), picks.end());

  // try out his luck
  for (size_t i = 0; i < _inner::chance_count(boxes.size()); ++i) {
    #ifdef LOG_DEBUG
    std::cout << "pick " << picks[i] << std::endl;
    #endif
    if (prisoner.number() == boxes.number(picks[i])) {
      #ifdef LOG_DEBUG
      std::cout << "... SURVIVED!" << std::endl;
      #endif
      return true;
    }
  }

  #ifdef LOG_DEBUG
  std::cout << "... didn't survive ...: " << std::endl;
  #endif
  return false;
}

template<typename BOXES>
bool picker_follow(const BOXES& boxes, const Prisoner& prisoner) {
  #ifdef LOG_DEBUG
  std::cout << "prisoner " << prisoner.number() << std::endl;
  #endif

  // follow the numbers, starting with his own
  size_t current = boxes.number(prisoner.number());
  for (size_t i = 0; i < _inner::chance_count(boxes.size()); ++i) {
    #ifdef LOG_DEBUG
    std::cout << "current: " << current << std::endl;
    #endif
    if (current == prisoner.number()) {
      #ifdef LOG_DEBUG
      std::cout << "... SURVIVED!" << std::endl;
      #endif
      return true;
    }
    current = boxes.number(current);
  }

  #ifdef LOG_DEBUG
  std::cout << "... didn't survive ...: " << std::endl;
  #endif
  return false;
}

}
