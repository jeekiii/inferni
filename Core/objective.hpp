#ifndef OBJECTIVE_HPP
#define OBJECTIVE_HPP

#include <vector>

#include "../Objects/object.hpp"
#include "../Objects/player.hpp"

#define KILL 1
#define REACH 2
#define POSSESS 3

#define OBJECTIVE_COMPLETED 1
#define OBJECTIVE_LOST 2
#define OBJECTIVE_IN_PROGRESS 3

class Objective
{
    private:
        int type_;
        int target_id_;

    public:
        Objective(int type, int target_id);
        int getStatus(Player *player, std::vector<Object *> *objects);
        bool isCompleted(Player *player, std::vector<Object *> *objects);
        bool isLost(Player *player, std::vector<Object *> *objects);
};

#endif
