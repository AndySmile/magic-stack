#ifndef __MENU_MODEL_IMENUACTION_H__
#define __MENU_MODEL_IMENUACTION_H__

struct IMenuAction
{
    virtual ~IMenuAction() = default;

    virtual void Execute() = 0;
};

#endif