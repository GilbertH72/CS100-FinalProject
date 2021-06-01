#ifndef __ELIXIR_H__
#define __ELIXIR_H__

#include "Heal_Items.h"

class Elixir : public Heal_Items
{
public:
   Elixir() : Heal_Items() {}
   Elixir(int level, int typeStatus, std::string n) : Heal_Items(level, typeStatus, n) {}
};

#endif
