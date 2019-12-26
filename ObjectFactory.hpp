#include <list>
#include "Unit.hpp"
#include "Score.hpp"

class ObjectFactory
{

public:
    ObjectFactory();
    void run(list<Unit *> &objectlist, Score &GameScore); // checks collisions
    void Clean(std::list<Unit *> &objectlist);            // cleans the ones whose alive is false
};