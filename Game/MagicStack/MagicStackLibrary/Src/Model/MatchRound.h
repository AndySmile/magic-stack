#ifndef __MAGICSTACK_MODEL_MATCHROUND_H__
#define __MAGICSTACK_MODEL_MATCHROUND_H__

namespace MagicStack
{
    struct ICardController;
    class CCard;
    class CAIController;
    class CPlayerInputController;

    class CMatchRound
    {
        public:
            CMatchRound(CCard& player, CCard& opponent);
            ~CMatchRound();

            CCard& GetAttackCard() const;
            CCard& GetDefenseCard() const;
            ICardController* GetCurrentController();
            void NextRound();

        private:
            unsigned int CurrentRound;
            CCard& Player;
            CCard& Opponent;
            CAIController* AIController;
            CPlayerInputController* PlayerController;
    };
}

#endif
