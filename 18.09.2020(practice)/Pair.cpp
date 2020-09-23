#include "Pair.h"

Pair::Pair():m_first(0), m_second(0){}
Pair::Pair(int first, int second) : m_first(first), m_second(second){}
Pair::~Pair() { std::cout << "Destructor is called.\n"; };
