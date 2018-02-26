#ifndef __MAGICSTACK_MODEL_CARD_H__
#define __MAGICSTACK_MODEL_CARD_H__

#include <string>

namespace MagicStack
{
    class CCard
    {
        public:
            CCard(const std::string& name, const int attackScore, const int defenseScore);
            ~CCard() = default;

            std::string GetName() const;
            int GetAttackScore() const;
            int GetDefenseScore() const;
            bool IsAlive() const;
            int GetEnergy() const;
            void ReduceEnergy(const int value);
            void IncreaseEnergy(const int value);

        private:
            int Energy;
            int AttackScore;
            int DefenseScore;
            std::string Name;
    };
}

#endif