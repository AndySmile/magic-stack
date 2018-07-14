#include <cstdlib>
#include <iostream>
#include <string>
#include <thread>
#include <chrono>
#include <ctime>

#define DELETE_OBJECT(object) if (object != nullptr) { delete object; object = nullptr; }

class CCard
{
    public:
        CCard(const std::string& name, const int attackScore, const int defenseScore)
            : Energy(100)
            , AttackScore(attackScore)
            , DefenseScore(defenseScore)
            , Name(name)
        {
        }

        ~CCard() = default;

        std::string GetName() const
        {
            return this->Name;
        }

        int GetAttackScore() const
        {
            return this->AttackScore;
        }

        int GetDefenseScore() const
        {
            return this->DefenseScore;
        }

        bool IsAlive() const
        {
            return (this->Energy > 0);
        }

        int GetEnergy() const
        {
            return this->Energy;
        }

        void ReduceEnergy(const int value)
        {
            std::cout << "[DEBUG: reduce energy " << value << "]" << std::endl;

            this->Energy -= abs(value);
        }

        void IncreaseEnergy(const int value)
        {
            std::cout << "[DEBUG: increase energy " << value << "]" << std::endl;

            this->Energy += abs(value);
        }

    private:
        int Energy;
        int AttackScore;
        int DefenseScore;
        std::string Name;
};

struct ICardAction
{
    virtual ~ICardAction() = default;

    virtual void Apply(CCard* attack, CCard* defense) = 0;
    virtual std::string GetDescription() const = 0;
};

class CFireAttackAction : public ICardAction
{
    public:
        CFireAttackAction() = default;
        virtual ~CFireAttackAction() = default;

        virtual void Apply(CCard* attack, CCard* defense) override
        {
            int attackScore = std::rand() % (attack->GetAttackScore() * FireMultiplier) + 1;
            int defenseScore = std::rand() % defense->GetDefenseScore() + 1;

            defense->ReduceEnergy(attackScore - defenseScore);
        }

        virtual std::string GetDescription() const override
        {
            return "Fire Attack";
        }

    private:
        static const int FireMultiplier = 2;
};

class CHealAction : public ICardAction
{
    public:
        CHealAction() = default;
        virtual ~CHealAction() = default;

        virtual void Apply(CCard* attack, CCard* defense) override
        {
            attack->IncreaseEnergy(HealScore + (std::rand() % HealScore));
        }

        virtual std::string GetDescription() const override
        {
            return "Heal Portion";
        }

    private:
        static const int HealScore = 8;
};

struct ICardController
{
    virtual ~ICardController() = default;

    virtual ICardAction* Execute() = 0;
};

class CBaseController
{
    public:
        CBaseController()
            : FireAction(nullptr)
            , HealAction(nullptr)
        {
        }

        virtual ~CBaseController()
        {
            DELETE_OBJECT(this->FireAction);
            DELETE_OBJECT(this->HealAction);
        }

    protected:

        ICardAction* GetFireAction()
        {
            if (this->FireAction == nullptr) {
                this->FireAction = new CFireAttackAction();
            }

            return this->FireAction;
        }

        ICardAction* GetHealAction()
        {
            if (this->HealAction == nullptr) {
                this->HealAction = new CHealAction();
            }

            return this->HealAction;
        }

    private:
        CFireAttackAction* FireAction;
        CHealAction* HealAction;
};

class CAIController 
    : protected CBaseController
    , public ICardController
{
    public:
        CAIController() = default;
        virtual ~CAIController() = default;

        virtual ICardAction* Execute() override
        {
            int mindIndex = std::rand() % 100;

            if (mindIndex > 80) {
                return this->GetHealAction();
            }

            return this->GetFireAction();
        }
};

class CPlayerInputController 
    : protected CBaseController
    , public ICardController
{
    public:
        CPlayerInputController() = default;
        virtual ~CPlayerInputController() = default;

        virtual ICardAction* Execute() override
        {
            ICardAction* action = nullptr;

            do {
                std::string inputLine;

                std::getline(std::cin, inputLine);

                if (inputLine == "fire") {
                    action = this->GetFireAction();
                } 
                else if (inputLine == "heal") {
                    action = this->GetHealAction();
                }
            } while (action == nullptr);

            return action;
        }
};

class CMatchRound
{
    public:
        CMatchRound(CCard& player, CCard& opponent)
            : CurrentRound(0)
            , Player(&player)
            , Opponent(&opponent)
            , AIController(new CAIController())
            , PlayerController(new CPlayerInputController())
        {
        }

        ~CMatchRound()
        {
            DELETE_OBJECT(this->AIController);
            DELETE_OBJECT(this->PlayerController);
        }

        CCard* GetAttackCard() const
        {
            return (this->CurrentRound == 0) ? this->Player : this->Opponent;
        }

        CCard* GetDefenseCard() const
        {
            return (this->CurrentRound == 0) ? this->Opponent : this->Player;
        }

        ICardController* GetCurrentController()
        {
            if (this->CurrentRound == 0) {
                return this->PlayerController;
            }
            else {
                return this->AIController;
            }
        }

        void NextRound()
        {
            this->CurrentRound = (this->CurrentRound == 0) ? 1 : 0;
        }

    private:
        unsigned int CurrentRound;
        CCard* Player;
        CCard* Opponent;
        CAIController* AIController;
        CPlayerInputController* PlayerController;
};

class CMatchTalker
{
public:
    CMatchTalker() = default;
    ~CMatchTalker() = default;

    void IntroduceMatch(const CCard& player, const CCard& opponent) const
    {
        this->Talk("Starting card match: " + player.GetName() + " vs " + opponent.GetName());
    }

    void IntroduceWinner(const CCard& player, const CCard& opponent) const
    {
        const CCard* winner = (player.IsAlive()) ? &player : &opponent;

        this->Talk(winner->GetName() + " has won the game!");
    }

    void IntroduceCurrentRound(const CCard& attackCard) const
    {
        this->Talk("It's the turn of \"" + attackCard.GetName() + "\" to make its next move!");
    }

    void DescribeAction(const CCard& attackCard, const ICardAction& action)
    {
        this->Talk(attackCard.GetName() + " performs a " + action.GetDescription(), 2);
    }

    void DescribeStatus(const CCard& card)
    {
        this->Talk(card.GetName() + " has " + std::to_string(card.GetEnergy()) + "% of energy left!", 2);
    }

    void MarkEndOfRound()
    {
        std::cout << "........................................................................" << std::endl;
    }

private:
    void Talk(const std::string& message, const unsigned int numTabs = 1) const
    {
        for (unsigned int i = 0; i < numTabs; ++i) {
            std::cout << ">>>";
        }

        std::cout << " " << message << std::endl;
    }
};

int main()
{
    std::cout << "***********************************************************" << std::endl;
    std::cout << "**** Card Game Prototype - Build " __DATE__ " " __TIME__ << std::endl;
    std::cout << "***********************************************************" << std::endl;

    std::srand(static_cast<unsigned int>(std::time(0)));

    CCard playerCard("FireJack", 30, 20);
    CCard opponentCard("SmokingBrad", 20, 40);
    CMatchRound round(playerCard, opponentCard);
    CMatchTalker talker;

    talker.IntroduceMatch(playerCard, opponentCard);

    while (playerCard.IsAlive() && opponentCard.IsAlive()) {
        CCard* attackCard = round.GetAttackCard();
        CCard* defenseCard = round.GetDefenseCard();
        ICardController* controller = round.GetCurrentController();

        talker.IntroduceCurrentRound(*attackCard);

        ICardAction* action = controller->Execute();

        action->Apply(attackCard, defenseCard);

        talker.DescribeAction(*attackCard, *action);
        talker.DescribeStatus(*attackCard);
        talker.DescribeStatus(*defenseCard);

        round.NextRound();

        talker.MarkEndOfRound();

        std::this_thread::sleep_for(std::chrono::seconds(1));
    }

    talker.IntroduceWinner(playerCard, opponentCard);

    system("pause");

    return EXIT_SUCCESS;
}