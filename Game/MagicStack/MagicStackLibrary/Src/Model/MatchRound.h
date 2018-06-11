#ifndef __MAGICSTACK_MODEL_MATCHROUND_H__
#define __MAGICSTACK_MODEL_MATCHROUND_H__

namespace MagicStack
{
    struct IPlayerController;
    class CCard;
    class CAIController;
    class CPlayerInputController;

    class CMatchRound
    {
        public:
            CMatchRound();
            ~CMatchRound();

        public:
            enum class PlayerIndex
            {
                FirstPlayer,
                SecondPlayer
            };

        public:
            void SetPlayerController(IPlayerController* controller, const PlayerIndex index);
            CCard* GetAttackCard() const;
            CCard* GetDefenseCard() const;
            IPlayerController* GetCurrentController() const;
            void Init();
            void NextRound();
            bool IsRunning() const;
            bool HasAllPlayer() const;

        private:
            unsigned int CurrentRound;
            IPlayerController* FirstPlayerController;
            IPlayerController* SecondPlayerController;
            CCard* AttackCard;
            CCard* DefenseCard;
    };
}

#endif
