/**
 * Card Creature Gameplay Prototype.
 *
 * @example
 *      - turn begins
 *      - First Player picks his element card
 *      - Second player picks his element card
 *      - system compares the element cards with each other and calculates the attack store for each other
 *      - turn ends
 */

#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>

bool IsInList(const int value, const std::vector<int> list) 
{
    for (auto it = list.begin(); it != list.end(); ++it) {
        if (*it == value) {
            return true;
        }
    }

    return false;
}

enum class ECardType 
{
    CreatureCard,
    ElementCard,
    MagicCard
};

struct ICard
{
    virtual ~ICard() = default;

    virtual ECardType GetType() const = 0;
    virtual std::string GetName() const = 0;
    virtual void Execute() = 0;
};

typedef std::vector<ICard*> CardList;

class CDisplay
{
    public:
        CDisplay() = default;
        ~CDisplay() = default;

        void DisplayStart() const
        {
            std::cout << "================================================================================" << std::endl;
            std::cout << "============" << std::endl;
            std::cout << "============ Card Creature Gameplay Prototype - Build " << __DATE__ << " " << __TIME__ << std::endl;
            std::cout << "============" << std::endl;
            std::cout << "================================================================================" << std::endl;
        }

        void DisplayCardList(const std::string& headline, const CardList& list) const
        {
            unsigned int counter = 0;

            std::cout << headline << std::endl;

            for (auto it = list.begin(); it != list.end(); ++it) {
                std::cout << "[" << (int)(++counter) << "] " << (*it)->GetName() << std::endl;
            }
        }

        void DisplayDebugMessage(const std::string& message) const
        {
            std::cout << "\t [DEBUG] | " << message << std::endl;
        }
};

class CInputHandler
{
    public:
        CInputHandler() = default;
        virtual ~CInputHandler() = default;

        unsigned int GetNumberFromRange(const unsigned int start, const unsigned int end) const
        {
            unsigned int enteredNumber = 0;

            do {
                std::cin >> enteredNumber;
            } while (enteredNumber < start || enteredNumber > end);
            
            return enteredNumber;
        }

        unsigned int GetNumberFromList(const std::vector<int> list) const
        {
            unsigned int enteredNumber = 0;

            do {
                std::cin >> enteredNumber;
            } while (!IsInList(enteredNumber, list));
            
            return enteredNumber;
        }
};

class CBaseCard : public ICard
{
    public:
        CBaseCard(const ECardType type, const std::string& name)
            : Type(type)
            , Name(name)
        {
        }

        ECardType GetType() const override
        {
            return this->Type;
        }

        std::string GetName() const override
        {
            return this->Name;
        }
    protected:
        ECardType Type;
        std::string Name;
};

/**
 * Creature Card.
 *
 * This is the main card of the game. The player will stack cards upon each other with
 * the creature card as a base. It'll hold the element and the magic card as some kind
 * of a gear.
 */
class CCreatureCard : public CBaseCard
{
    public:
        CCreatureCard(const std::string& name, const unsigned int strength, const unsigned int health)
            : CBaseCard(ECardType::CreatureCard, name)
            , Strength(strength)
            , Health(health)
            , MaxHealth(health)
        {
        }

        virtual ~CCreatureCard() = default;

        void Execute() override
        {
            this->Name;
        }

        unsigned int GetStrength() const
        {
            return this->Strength;
        }

        unsigned int GetHealth() const
        {
            return this->Health;
        }

        void GainHealth(const unsigned int value)
        {
            unsigned int newValue = std::abs(static_cast<int>(value));

            if (this->Health + newValue <= this->MaxHealth) {
                this->Health += newValue;
            } else {
                this->Health = this->MaxHealth;
            }
        }

        void LoseHealth(const unsigned int value)
        {
            if (this->Health > value) {
                this->Health -= std::abs(static_cast<int>(value));
            } else {
                this->Health = 0;
            }
        }

        bool IsAlive() const
        {
            return (this->Health > 0);
        }
    private:
        unsigned int Strength;
        unsigned int Health;
        unsigned int MaxHealth;
};

class CElementCard : public CBaseCard
{
    public:
        CElementCard(const std::string& name)
            : CBaseCard(ECardType::ElementCard, name)
        {
        }

        virtual ~CElementCard() = default;

        void Execute() override
        {
        }
};

class CMagicCard : public CBaseCard
{
    public:
        CMagicCard(const std::string& name)
            : CBaseCard(ECardType::MagicCard, name)
        {
        }

        virtual ~CMagicCard() = default;

        void Execute() override
        {
        }
};

struct IPlayerController
{
    virtual ~IPlayerController() = default;

    virtual void PickCreatureCard(CardList* creatureCardList) = 0;
    virtual void PickElementCards(const CardList& elementCardList) = 0;
    virtual void PickMagicCard(CardList* magicCardList) = 0;
    virtual ICard* ActivateCard() const = 0;
    virtual ICard* GetCreatureCard() const = 0;
};

typedef std::vector<IPlayerController*> PlayerControllerList;

class CBaseController
{
    public:
        CBaseController(const CDisplay& display)
            : Display(&display)
        {
        }

        virtual ~CBaseController() = default;

    protected:
        const CDisplay* Display;
};

class CBasePlayerController 
    : protected CBaseController
    , public IPlayerController
{
    public:
        CBasePlayerController(const CDisplay& display)
            : CBaseController(display)
        {
        }

        virtual ~CBasePlayerController() = default;

        ICard* GetCreatureCard() const override
        {
            return this->CreatureCard;
        }
    protected:
        ICard* CreatureCard;
        ICard* MagicCard;
        CardList ElementCardList;
};

class CPlayerController : public CBasePlayerController
{
    public:
        CPlayerController(const CDisplay& display, const CInputHandler& input)
            : CBasePlayerController(display)
            , Input(&input)
        {
        }

        virtual ~CPlayerController() = default;

        virtual void PickCreatureCard(CardList* creatureCardList) override
        {
            this->Display->DisplayDebugMessage("Player is picking a creature card!");
            
            this->CreatureCard = creatureCardList->at(this->GetIndexFromMenu("Pick your creature card: ", *creatureCardList));
        }

        virtual void PickElementCards(const CardList& elementCardList) override
        {
            this->Display->DisplayDebugMessage("Player is picking some element cards!");

            this->ElementCardList.push_back(elementCardList.at(this->GetIndexFromMenu("Pick your element card: ", elementCardList)));
        }

        virtual void PickMagicCard(CardList* magicCardList) override
        {
            this->Display->DisplayDebugMessage("Player is picking a magic card!");
        }

        virtual ICard* ActivateCard() const override
        {
            return this->ElementCardList[0];
        }

    private:
        unsigned int GetIndexFromMenu(const std::string& headline, const CardList& list) const
        {
            this->Display->DisplayCardList("Pick your creature card: ", list);

            return this->Input->GetNumberFromRange(1, list.size()) - 1;
        }

    private:
        const CInputHandler* Input;
        
};

class CAIController : public CBasePlayerController
{
    public:
        CAIController(const CDisplay& display)
            : CBasePlayerController(display)
        {
        }

        virtual ~CAIController() = default;

        virtual void PickCreatureCard(CardList* creatureCardList) override
        {
            this->Display->DisplayDebugMessage("AI is picking a creature card!");

            this->CreatureCard = creatureCardList->at(1);
        }

        virtual void PickElementCards(const CardList& elementCardList) override
        {
            this->Display->DisplayDebugMessage("AI is picking some element cards!");
        }

        virtual void PickMagicCard(CardList* magicCardList) override
        {
            this->Display->DisplayDebugMessage("AI is picking a magic card!");
        }

        virtual ICard* ActivateCard() const override
        {
            return this->ElementCardList[0];
        }
};

class CMatchSystem
{
    public:
        CMatchSystem() = default;
        ~CMatchSystem() = default;

        /**
         * TODO
         *  - get element card from first creature
         *  - get element card from second creature
         *  - calculates the attack score by boost or reduce the attack strength depending on the element type (each element card has a boost and reduce score as percentage value)
         *  - apply the attack value to each creature card
         */
        void RunTurn(CCreatureCard* firstCard, CCreatureCard* secondCard, const ICard& firstActiveCard, const ICard& secondActiveCard) const
        {
            unsigned int attackStrength = firstCard->GetStrength();

            float impactScore = 1.0f;

            if (firstActiveCard.GetType() == ECardType::ElementCard && secondActiveCard.GetType() == ECardType::ElementCard) {
                impactScore = this->CalculateImpactScoreByElementCards(firstActiveCard, secondActiveCard);
            }

            secondCard->LoseHealth(attackStrength * impactScore);
        }

    private:
        /**
         * TODO consider int type instead of a float
         */
        float CalculateImpactScoreByElementCards(const ICard& firstActiveCard, const ICard& secondActiveCard) const
        {
            return 1.0f;
        }
};

/**
 * TODO change to only add two player controller instead of as many as possible. the game is only made for two players
 */
class CGameplayController : protected CBaseController
{
    public:
        CGameplayController(const CDisplay& display)
            : CBaseController(display)
        {
            this->PrepareCreatureCardList();
            this->PrepareElementCardList();
            this->PrepareMagicCardList();
        }

        virtual ~CGameplayController() = default;

        void AddPlayerController(IPlayerController* controller)
        {
            this->PlayerControllerList.push_back(controller);
        }

        void PickCreatureCard()
        {
            this->Display->DisplayDebugMessage("Begin to pick creature cards...");

            for (auto it = this->PlayerControllerList.begin(); it != this->PlayerControllerList.end(); ++it) {
                (*it)->PickCreatureCard(&this->CreatureCardList);
            }
        }

        void PickElementCards() const
        {
            this->Display->DisplayDebugMessage("Begin to pick element cards...");

            for (auto it = this->PlayerControllerList.begin(); it != this->PlayerControllerList.end(); ++it) {
                for (unsigned int i = 0; i < 2; ++i) {
                    (*it)->PickElementCards(this->ElementCardList);
                }
            }
        }

        void PickMagicCard()
        {
            this->Display->DisplayDebugMessage("Begin to pick magic card...");

            for (auto it = this->PlayerControllerList.begin(); it != this->PlayerControllerList.end(); ++it) {
                (*it)->PickMagicCard(&this->MagicCardList);
            }
        }

        void Run()
        {
            this->Display->DisplayDebugMessage("Begin the game...");

            this->PickCreatureCard();
            this->PickElementCards();
            this->PickMagicCard();
            this->RunMatch();

            this->Display->DisplayDebugMessage("done!");
        }

    private:
        void PrepareCreatureCardList()
        {
            this->CreatureCardList.push_back(new CCreatureCard("FlameFox", 40, 500));
            this->CreatureCardList.push_back(new CCreatureCard("FluffyFish", 20, 500));
        }

        void PrepareElementCardList()
        {
            this->ElementCardList.push_back(new CElementCard("Fire"));
            this->ElementCardList.push_back(new CElementCard("Water"));
            this->ElementCardList.push_back(new CElementCard("Sand"));
            this->ElementCardList.push_back(new CElementCard("Air"));
        }

        void PrepareMagicCardList()
        {
            this->MagicCardList.push_back(new CMagicCard("Extra Defense Points"));
            this->MagicCardList.push_back(new CMagicCard("Extra Attack Points"));
            this->MagicCardList.push_back(new CMagicCard("Explosion Attack"));
            this->MagicCardList.push_back(new CMagicCard("Random Extra Round"));
            this->MagicCardList.push_back(new CMagicCard("Shield"));
        }

        void RunMatch()
        {
            CCreatureCard* firstCreature = static_cast<CCreatureCard*>(this->PlayerControllerList[0]->GetCreatureCard());
            CCreatureCard* secondCreature = static_cast<CCreatureCard*>(this->PlayerControllerList[1]->GetCreatureCard());

            while (firstCreature->IsAlive() && secondCreature->IsAlive()) {
                this->Display->DisplayDebugMessage("First creature health: " + std::to_string(firstCreature->GetHealth()));
                this->Display->DisplayDebugMessage("Second creature health: " + std::to_string(secondCreature->GetHealth()));

                ICard* firstPickedCard = this->PlayerControllerList[0]->ActivateCard();
                ICard* secondPickedCard = this->PlayerControllerList[1]->ActivateCard();

                this->MatchSystem.RunTurn(firstCreature, secondCreature, *firstPickedCard, *secondPickedCard);
            }
        }

    private:
        PlayerControllerList PlayerControllerList;
        CardList CreatureCardList;
        CardList ElementCardList;
        CardList MagicCardList;
        CMatchSystem MatchSystem;
};

int main()
{
    CDisplay display;
    CInputHandler input;
    CGameplayController gameplayController(display);
    CPlayerController playerController(display, input);
    CAIController aiController(display);

    gameplayController.AddPlayerController(&playerController);
    gameplayController.AddPlayerController(&aiController);

    gameplayController.Run();

    system("pause");

    return EXIT_SUCCESS;
}