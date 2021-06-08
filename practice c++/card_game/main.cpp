#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

class unit
{
  protected:
  double hp;
  double base_damage;
  unit(double _hp, double _base_damage)
    : hp(_hp), base_damage(_base_damage) {}
  public:
  virtual bool print_stat(const char *) = 0;
  virtual double get_damage() = 0;
  virtual void take_damage(double) = 0;
};

class hunter : public unit
{
  protected:
  double agile;
  hunter(double _hp, double _bd, double _ag)
    : unit(_hp, _bd), agile(_ag) {}
};

class rogue : public hunter
{
  private:
  int evasion_chance;
  bool evasion()
  {
    return rand() % 100 < evasion_chance;
  }
  public:
  bool print_stat(const char *name)
  {
    cout << "Rogue HP: "<<  name << " " << hp;
    return hp > 0;
  }
  rogue(double _hp, double _bd, double _ag, int _ec)
    : hunter(_hp, _bd, _ag), evasion_chance(_ec) {}
  double get_damage()
  {
    return base_damage * agile;
  }
  void take_damage(double damage)
  {
    if (evasion())
    {
      puts("Evasion!");
    }
    else
      hp -= damage;
  }
};

const int crit_mult = 10;

class reaper : public hunter
{
  private:
  int crit_chance;
  bool crit()
  {
    return rand() % 100 < crit_chance;
  }
  public:
  reaper(double _hp, double _bd, double _ag, int _cc)
    : hunter(_hp, _bd, _ag), crit_chance(_cc) {}
  bool print_stat(const char *name)
  {
    cout << "Reaper HP: " <<  name << " "<<  hp;
    return hp > 0;
  }
  double get_damage()
  {
    if (crit())
    {
      puts("CRIT!");
      return base_damage * agile * crit_mult;
    }
    return base_damage * agile;
  }
  void take_damage(double damage)
  {
    hp -= damage;
  }
};

class warrior : public unit
{
  protected:
  double armor;
  warrior(double _hp, double _bd, double _ar)
    : unit(_hp, _bd), armor(_ar) {}
  void take_damage(double damage)
  {
    hp -= damage * armor;
  }
};

const int hp_heal = 20;

class paladin : public warrior
{
  private:
  void healing()
  {
    hp += hp_heal;
  }
  public:
  paladin(double _hp, double _bd, double _ar)
    : warrior(_hp, _bd, _ar) {}
  bool print_stat(const char *name)
  {
    cout << "Paladin HP: " <<  name <<  hp;
    return hp > 0;
  }
  double get_damage()
  {
    puts("[1]\tHeal\n[other]\tAttack");
    int c;
    scanf("%d", &c);
    switch (c)
    {
      case 1:
        healing();
        return 0;
      default:
        return base_damage;
    }
  }
};

class berserk : public warrior
{
  private:
  int rage;
  public:
  berserk(double _hp, double _bd, double _ar, int _r)
    : warrior(_hp, _bd, _ar), rage(_r) {}
  bool print_stat(const char *name)
  {
    cout << "Berserk HP: " <<  name << hp;
    return hp > 0;
  }
  double get_damage()
  {
    rage += 2;
    return base_damage + rage;
  }
};


const int manaregen = 5;

class mage : public unit
{
  protected:
  int mana;
  void regen_mana()
  {
    mana += manaregen;
  }
  public:
  mage(double _hp, double _bd, int _m)
    : unit(_hp, _bd), mana(_m) {}
  void take_damage(double damage)
  {
    hp -= damage;
    regen_mana();
  }
};

const int  fireball_price = 20;
const int fireball_damage = 100;

class firemage : public mage
{
  private:
  double fireball()
  {
    if (mana >= fireball_price)
    {
      mana -= fireball_price;
      return fireball_damage;
    }
    else
    {
      puts("Not enought mana!");
      return 0;
    }
  }
  public:
  firemage(double _hp, double _bd, int _m)
    : mage(_hp, _bd, _m) {}
  bool print_stat(const char *name)
  {
    cout << "Firemage hp and mana: " <<  name << " " << hp << " " << mana;
    return hp > 0;
  }

  double get_damage()
  {
    puts("[1]\tSpell fireball\n[other]\tnothing");
    int c;
    cin >> c;
    switch(c)
    {
      case 1:
        return base_damage + fireball();
      default:
        return base_damage;
    }
  }
};

const int lifesteal_price = 10;
const int lifesteal_percent = 1.05;

class arcanemage : public mage
{
  private:
  double lifesteal()
  {
    if (mana >= lifesteal_price)
    {
      mana -= lifesteal_price;
      return lifesteal_percent;
    }
    else
      return 1;
  }
  public:
  arcanemage(double _hp, double _bd, int _m)
    : mage(_hp, _bd, _m) {}
  bool print_stat(const char *name)
  {
    cout << "Arcan mage hp and mana: " <<  name << " " << hp << " " << mana;
    return hp > 0;
  }
  double get_damage()
  {
    hp += lifesteal();
    return base_damage;
  }
};

int main()
{
  srand(time(NULL));
  puts("Enter number of players");
  int n;
  cin >> n;
  unit *player[n];
  char *name[n];
  bool alive[n];
  int c;
  puts("Available classes:\n1\tRogue\n2\tReaper\n3\tPaladin\n4\tBerserk\n5\tFire mage\n6\tArcane mage");
  for (int i(0); i < n; ++i)
  {
    cout << "Player : [CLASS_ID] [NAME]\n" <<  i + 1;
    name[i] = new char[100];
    cin >>  c >> name[i];
    alive[i] = true;
    switch(c)
    {
      case 1:
        player[i] = new rogue(250, 15, 2.5, 30);
        break;
      case 2:
        player[i] = new reaper(250, 15, 3, 15);
        break;
      case 3:
        player[i] = new paladin(500, 20, 0.5);
        break;
      case 4:
        player[i] = new berserk(500, 20, 0.5, 0);
        break;
      case 5:
        player[i] = new firemage(200, 15, 60);
        break;
      case 6:
        player[i] = new arcanemage(200, 20, 40);
    }
    player[i]->print_stat(name[i]);
  }
  int target;
  for (int k(0);; k = (k + 1) % n)
  {
    if (!alive[k])
      continue;
    cout << "Move player \nWhom are attacking?\n" <<  k + 1;
    cin >> target;

    player[target - 1]->take_damage(player[k]->get_damage());

    if (!player[target - 1]->print_stat(name[target - 1]))
    {
      cout << "Playe is death\n" << target;
      alive[target - 1] = false;
    }

    player[k]->print_stat(name[k]);
    puts("------------------------------");
  }
  return 0;
}
