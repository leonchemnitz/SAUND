#include "SimpleIIRFilter.h"

SimpleIIRFilter::SimpleIIRFilter() {
  state = 0.0;
  a = 0.0;
}

SimpleIIRFilter::~SimpleIIRFilter() {}

void SimpleIIRFilter::initialize(double _a, double _state) {
  a = _a;
  state = _state;
}

double SimpleIIRFilter::getState() { return state; }

double SimpleIIRFilter::update(double value) {
  state = state + a * (value - state);
  return state;
}