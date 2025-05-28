#include "axmol.h"
#include "MenuItemSpriteExtra.hpp"

using namespace ax;

void MenuItemSpriteExtra::selected() {
    MenuItemSprite::selected();
    this->stopActionByTag(0);
    auto scaleUp = ScaleTo::create(0.3f, 1.1f);
    auto easeAction = EaseBounceOut::create(scaleUp);
    easeAction->setTag(0);
    this->runAction(easeAction);
}
