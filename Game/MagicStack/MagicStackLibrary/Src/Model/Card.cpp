#include "Card.h"

namespace MagicStack
{
    CCard::CCard(const std::string& name, const int attackScore, const int defenseScore)
        : Energy(100)
        , AttackScore(attackScore)
        , DefenseScore(defenseScore)
        , Name(name)
    {
    }

    std::string CCard::GetName() const
    {
        return this->Name;
    }

    int CCard::GetAttackScore() const
    {
        return this->AttackScore;
    }

    int CCard::GetDefenseScore() const
    {
        return this->DefenseScore;
    }

    bool CCard::IsAlive() const
    {
        return (this->Energy > 0);
    }

    int CCard::GetEnergy() const
    {
        return this->Energy;
    }

    void CCard::ReduceEnergy(const int value)
    {
        this->Energy -= abs(value);
    }

    void CCard::IncreaseEnergy(const int value)
    {
        this->Energy += abs(value);
    }
}