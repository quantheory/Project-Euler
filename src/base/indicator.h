#ifndef INDICATOR_H
#define INDICATOR_H

template <typename>
class Indicator;

template <typename>
class SimpleIndicator;

template <typename T>
class Indicator {
public:
  virtual bool operator()(const T &obj) const = 0;
};

template <typename T>
class SimpleIndicator : public Indicator<T> {
public:
  SimpleIndicator(bool f(const T &))
    : test(f) {}

  bool operator()(const T &obj) const {
    return test(obj);
  }

private:
  bool (*test)(const T &);

};

#endif //INDICATOR_H
