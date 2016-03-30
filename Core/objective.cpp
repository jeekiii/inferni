#include "objective.hpp"

Objective::Objective(int type, int target_id)
{
    type_ = type;
    target_id_ = target_id;
}

//to complete
static int getDistance(int x1, int y1, int x2, int y2)
{
    return 0;
}

bool Objective::isCompleted(Player *player, std::vector<Object *> *objects)
{
    switch(type_)
    {
        case KILL:
            for (unsigned int i = 0; i < objects->size(); i++)
                if (objects->at(i)->getId() == target_id_)
                    return false;
            return true;
            break;
        case REACH:
            for (unsigned int i = 0; i < objects->size(); i++)
                if (objects->at(i)->getId() == target_id_)
                    return getDistance(0,0,0,0) < 100; //to complete
            return false;
            break;
        case POSSESS:
            return player->getPossessedId() == target_id_;
            break;
        default:
            return true;
            break;
    }
}

bool Objective::isLost(Player *player, std::vector<Object *> *objects)
{
    switch(type_)
    {
        case KILL:
            return false;
        case REACH:
            for (unsigned int i = 0; i < objects->size(); i++)
                if (objects->at(i)->getId() == target_id_)
                    return false;
            return true;
        case POSSESS:
            for (unsigned int i = 0; i < objects->size(); i++)
                if (objects->at(i)->getId() == target_id_)
                    return false;
            return player->getPossessedId() != target_id_;
        default:
            return false;
    }
}

int Objective::getStatus(Player *player, std::vector<Object *> *objects)
{
    if (isCompleted(player, objects))
        return OBJECTIVE_COMPLETED;
    else if (isLost(player, objects))
        return OBJECTIVE_LOST;
    else
        return OBJECTIVE_IN_PROGRESS;
}
