#include "FireAction.h"
#include "../Card.h"

namespace MagicStack
{
    void CFireAction::Apply(CCard* attack, CCard* defense) 
    {
        int attackScore = std::rand() % (attack->GetAttackScore() * FireMultiplier) + 1;
        int defenseScore = std::rand() % defense->GetDefenseScore() + 1;

        defense->ReduceEnergy(attackScore - defenseScore);
    }

    std::string CFireAction::GetDescription() const 
    {
        return "Fire Attack";
    }
}