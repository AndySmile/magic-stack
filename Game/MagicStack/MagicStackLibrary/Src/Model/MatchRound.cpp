#include "MatchRound.h"
#include "../Helper/Macros.h"

namespace MagicStack
{
    CMatchRound::CMatchRound(CCard& player, CCard& opponent)
        : CurrentRound(0)
        , Player(player)
        , Opponent(opponent)
        , AIController(/*new CAIController()*/)
        , PlayerController(/*new CPlayerInputController()*/)
    {
    }

    CMatchRound::~CMatchRound()
    {
        /*DELETE_OBJECT(this->AIController);
        DELETE_OBJECT(this->PlayerController);*/
    }

    CCard& CMatchRound::GetAttackCard() const
    {
        return (this->CurrentRound == 0) ? this->Player : this->Opponent;
    }

    CCard& CMatchRound::GetDefenseCard() const
    {
        return (this->CurrentRound == 0) ? this->Opponent : this->Player;
    }

    ICardController* CMatchRound::GetCurrentController()
    {
        /*if (this->CurrentRound == 0) {
            return this->PlayerController;
        }
        else {
            return this->AIController;
        }*/

        return nullptr;
    }

    void CMatchRound::NextRound()
    {
        this->CurrentRound = (this->CurrentRound == 0) ? 1 : 0;
    }
}