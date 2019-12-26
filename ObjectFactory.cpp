#include "ObjectFactory.hpp"

ObjectFactory::ObjectFactory()
{
}
void ObjectFactory::run(list<Unit *> &objectlist, Score &GameScore)
{
    bool collided = false;
    for (std::list<Unit *>::iterator it = objectlist.begin(); it != objectlist.end(); ++it)
    {
        if ((*it) != NULL)
        {
            if ((*it)->GetType() == "metalball")
            {
                for (std::list<Unit *>::iterator it1 = objectlist.begin(); it1 != objectlist.end(); ++it1)
                {
                    if ((*it1) != NULL)
                    {
                        if ((*it1)->GetType() == "metal")
                        {
                            collided = (*it)->check_collision(*it1);
                            if (collided)
                            {
                                GameScore = GameScore + 10;
                                (*it1)->SetAlive(false);
                                (*it)->SetAlive(false);
                                break;
                            }
                        }
                        if ((*it1)->GetType() == "plastic")
                        {
                            collided = (*it)->check_collision(*it1);
                            if (collided)
                            {

                                GameScore = GameScore - 10;
                                (*it1)->SetAlive(false);
                                (*it)->SetAlive(false);
                                break;
                            }
                        }
                        if ((*it1)->GetType() == "paper")
                        {
                            collided = (*it)->check_collision(*it1);
                            if (collided)
                            {
                                GameScore = GameScore - 10;
                                (*it1)->SetAlive(false);
                                (*it)->SetAlive(false);
                                break;
                            }
                        }
                    }
                }
            }
            if ((*it)->GetType() == "plasticball")
            {
                for (std::list<Unit *>::iterator it1 = objectlist.begin(); it1 != objectlist.end(); ++it1)
                {
                    if ((*it1) != NULL)
                    {
                        if ((*it1)->GetType() == "metal")
                        {
                            collided = (*it)->check_collision(*it1);
                            if (collided)
                            {

                                GameScore = GameScore - 10;
                                (*it1)->SetAlive(false);
                                (*it)->SetAlive(false);
                                break;
                            }
                        }
                        if ((*it1)->GetType() == "plastic")
                        {
                            collided = (*it)->check_collision(*it1);
                            if (collided)
                            {

                                GameScore = GameScore + 10;
                                (*it1)->SetAlive(false);
                                (*it)->SetAlive(false);
                                break;
                            }
                        }
                        if ((*it1)->GetType() == "paper")
                        {
                            collided = (*it)->check_collision(*it1);
                            if (collided)
                            {
                                GameScore = GameScore - 10;
                                (*it1)->SetAlive(false);
                                (*it)->SetAlive(false);
                                break;
                            }
                        }
                    }
                }
            }
            if ((*it)->GetType() == "paperball")
            {
                for (std::list<Unit *>::iterator it1 = objectlist.begin(); it1 != objectlist.end(); ++it1)
                {
                    if ((*it1) != NULL)
                    {
                        if ((*it1)->GetType() == "metal")
                        {
                            collided = (*it)->check_collision(*it1);
                            if (collided)
                            {
                                GameScore = GameScore - 10;
                                (*it1)->SetAlive(false);
                                (*it)->SetAlive(false);
                                break;
                            }
                        }
                        if ((*it1)->GetType() == "plastic")
                        {
                            collided = (*it)->check_collision(*it1);
                            if (collided)
                            {
                                GameScore = GameScore - 10;
                                (*it1)->SetAlive(false);
                                (*it)->SetAlive(false);
                                break;
                            }
                        }
                        if ((*it1)->GetType() == "paper")
                        {
                            collided = (*it)->check_collision(*it1);
                            if (collided)
                            {
                                GameScore = GameScore + 10;
                                (*it1)->SetAlive(false);
                                (*it)->SetAlive(false);
                                break;
                            }
                        }
                    }
                }
            }
        }
    } //end of for loop
} // end of run
void ObjectFactory::Clean(std::list<Unit *> &objectlist)
{
    for (std::list<Unit *>::iterator it = objectlist.begin(); it != objectlist.end(); ++it)
    {
        if ((*it)->GetAlive() == false)
        {
            objectlist.remove(*(it));
            delete (*it);
        }
    }
}