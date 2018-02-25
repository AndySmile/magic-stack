#ifndef __MENU_CONTROLLER_ICONTROLLER_H__
#define __MENU_CONTROLLER_ICONTROLLER_H__

#include <string>

struct IMenuAction;
class CControllerTransition;

struct IController
{
    virtual ~IController() = default;

    virtual void Init(CControllerTransition& transition) = 0;
    virtual void Render() const = 0;
    virtual IMenuAction* ProcessUserInput() const = 0;
    virtual void Enter() = 0;
    virtual void Leave() = 0;
    virtual std::string GetAlias() const = 0;
};

#endif
