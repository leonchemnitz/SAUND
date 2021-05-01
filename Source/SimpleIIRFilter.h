#pragma once

class SimpleIIRFilter {
public:
  SimpleIIRFilter();
  ~SimpleIIRFilter();

  void initialize(double a, double state);
  double update(double value);
  double getState();

private:
  double a;
  double state;
};