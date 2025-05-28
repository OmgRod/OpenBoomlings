#include "MenuLayer.hpp"

using namespace ax;

bool MenuLayer::init() {
    if (!Layer::init()) {
        return false;
    }

    // this->setKeypadEnabled(true);

    // GameManager::sharedState()->someMethod(1);

    auto director = Director::getInstance();
    Size visibleSize = director->getVisibleSize();
    Vec2 origin = director->getVisibleOrigin();

    auto mainMenuBG = Sprite::create("images/menuSheet/MainMenuBG_001.png");
    mainMenuBG->setPosition(origin.x + visibleSize.width / 2, origin.y + visibleSize.height / 2);

    float scaleX = visibleSize.width / mainMenuBG->getContentSize().width;
    float scaleY = visibleSize.height / mainMenuBG->getContentSize().height;
    float scale = std::max(scaleX, scaleY);
    mainMenuBG->setScale(scale);
    this->addChild(mainMenuBG, 0);

    auto logoSprite = Sprite::create("images/menuSheet/boomlingslogo.png");
    logoSprite->setPosition(origin.x + visibleSize.width / 2, origin.y + visibleSize.height * 0.85f);
    this->addChild(logoSprite, 2);

    auto glitterEffect = ParticleSystemQuad::create("plist/glitterEffect.plist");
    glitterEffect->setTexture(Director::getInstance()->getTextureCache()->addImage("images/particleImgSheet/starParticle.png"));
    glitterEffect->setScale(2.f);
    this->addChild(glitterEffect, 1);
    glitterEffect->setPosition(logoSprite->getPosition());

    setupMenuButtons();

    auto robtopLogoSprite = Sprite::create("images/menuSheet/robtoplogo_small.png");
    robtopLogoSprite->setAnchorPoint(Vec2(0.f, 0.f));

    auto robtopMenuItem = MenuItemSpriteExtra::create(robtopLogoSprite, robtopLogoSprite,
        AX_CALLBACK_0(MenuLayer::menuRobtopCallback, this));

    auto robtopMenu = Menu::create(robtopMenuItem, nullptr);
    robtopMenu->setPosition(
        origin.x + visibleSize.width * 0.025f + robtopLogoSprite->getContentSize().width / 2,
        origin.y + visibleSize.height * 0.025f + robtopLogoSprite->getContentSize().height / 2
    );
    this->addChild(robtopMenu, 2);

    auto feedbackSprite = Sprite::create("images/menuSheet/feedbackBtn_001.png");
    auto feedbackItem = MenuItemSpriteExtra::create(feedbackSprite, feedbackSprite,
        AX_CALLBACK_0(MenuLayer::menuFeedbackCallback, this));

    auto feedbackMenu = Menu::create(feedbackItem, nullptr);
    feedbackMenu->setPosition(origin.x + visibleSize.width / 2 + 130, origin.y + visibleSize.height * 0.7f);
    this->addChild(feedbackMenu, 2);

    auto helloSprite = Sprite::create("images/menuSheet/hello_001.png");
    helloSprite->setPosition(origin.x + visibleSize.width / 2 - 130, origin.y + visibleSize.height * 0.62f);
    this->addChild(helloSprite, 1);

    auto feedbackTextSprite = Sprite::create("images/menuSheet/feedback_001.png");
    feedbackTextSprite->setPosition(origin.x + visibleSize.width / 2, origin.y + visibleSize.height * 0.53f);
    this->addChild(feedbackTextSprite, 1);

    auto rateBtnSprite = Sprite::create("images/menuSheet/rateBtn_001.png");
    auto rateMenuItem = MenuItemSpriteExtra::create(rateBtnSprite, rateBtnSprite,
        AX_CALLBACK_0(MenuLayer::menuRateCallback, this));

    auto rateMenu = Menu::create(rateMenuItem, nullptr);
    rateMenu->setPosition(origin.x + visibleSize.width / 2 + 180, origin.y + visibleSize.height * 0.37f);
    this->addChild(rateMenu, 4);

    auto rateSprite = Sprite::create("images/menuSheet/rate_001.png");
    rateSprite->setPosition(rateMenu->getPosition() + Vec2(0, 40));
    this->addChild(rateSprite, 4);

    float duration = 1.0f;
    auto moveRight = MoveBy::create(duration, Vec2(10, 0));
    auto easeMove = EaseInOut::create(moveRight, 2);
    auto sequence = Sequence::create(easeMove, easeMove->reverse(), nullptr);
    rateSprite->runAction(RepeatForever::create(sequence));

    auto moreGamesBtn = Sprite::create("images/moreGamesBtn_001.png");
    auto moreGamesItem = MenuItemSpriteExtra::create(moreGamesBtn, moreGamesBtn,
        AX_CALLBACK_0(MenuLayer::menuMoreGamesCallback, this));

    auto moreGamesMenu = Menu::create(moreGamesItem, nullptr);
    moreGamesMenu->setPosition(origin.x + visibleSize.width / 2 - 180, origin.y + visibleSize.height * 0.32f);
    this->addChild(moreGamesMenu, 4);

    return true;
}

void MenuLayer::menuRobtopCallback() {
    AXLOG("RobTop button clicked");
    // GameManager::sharedState()->openRobTopPage();
}

void MenuLayer::menuFeedbackCallback() {
    AXLOG("Feedback button clicked");
    // GameManager::sharedState()->openFeedbackPage();
}

void MenuLayer::menuDailyCallback() {
    AXLOG("Daily button clicked");
    // GameManager::sharedState()->openDailyPage();
}

void MenuLayer::menuRateCallback() {
    AXLOG("Rate button clicked");
    // GameManager::sharedState()->openRatePage();
}

void MenuLayer::menuMoreGamesCallback() {
    AXLOG("More Games button clicked");
    // MoreGamesManager::sharedState()->openMoreGamesPage();
}

MenuLayer* MenuLayer::create() {
    MenuLayer* ret = new (std::nothrow) MenuLayer();
    if (ret && ret->init()) {
        ret->autorelease();
        return ret;
    }
    else {
        delete ret;
        return nullptr;
    }
}

Scene* MenuLayer::scene() {
    auto scene = Scene::create();
    auto layer = MenuLayer::create();
    scene->addChild(layer);
    return scene;
}

#include "cocos2d.h"
using namespace cocos2d;

void MenuLayer::setupMenuButtons() {
    auto playSprite = Sprite::createWithSpriteFrameName("mainPlayBtn_001.png");
    auto playItem = MenuItemSpriteExtra::create(playSprite, nullptr, this, menu_selector(MenuLayer::onPlayClicked));

    auto storeSprite = Sprite::createWithSpriteFrameName("mainStoreBtn_001.png");
    auto storeItem = MenuItemSpriteExtra::create(storeSprite, nullptr, this, menu_selector(MenuLayer::onStoreClicked));

    auto extrasSprite = Sprite::createWithSpriteFrameName("mainExtrasBtn_001.png");
    auto extrasItem = MenuItemSpriteExtra::create(extrasSprite, nullptr, this, menu_selector(MenuLayer::onExtrasClicked));

    auto freeGoldSprite = Sprite::createWithSpriteFrameName("freeGoldBtn_001.png");
    auto freeGoldItem = MenuItemSpriteExtra::create(freeGoldSprite, nullptr, this, menu_selector(MenuLayer::onFreeGoldClicked));

    auto menu = Menu::create(playItem, storeItem, extrasItem, freeGoldItem, nullptr);
    this->addChild(menu, 2);

    float padding = Director::getInstance()->getWinSize().height * 0.05f;
    menu->alignItemsVerticallyWithPadding(padding);

    auto blockR = SimpleGamePiece::createWithType("xl_Block_r");
    auto blockG = SimpleGamePiece::createWithType("xl_Block_g");
    auto blockB = SimpleGamePiece::createWithType("xl_Block_b");
    auto blockY = SimpleGamePiece::createWithType("xl_Block_y");

    float alphaValue = 0.9f;
    blockR->setAlpha(alphaValue);
    blockG->setAlpha(alphaValue);
    blockB->setAlpha(alphaValue);
    blockY->setAlpha(alphaValue);

    auto createMenuItemFromBlock = [&](SimpleGamePiece* block, SEL_MenuHandler callback) -> MenuItemSpriteExtra* {
        auto spriteWrapper = Sprite::create();
        spriteWrapper->addChild(block);
        spriteWrapper->setContentSize(block->getContentSize());
        block->setPosition(ccp(spriteWrapper->getContentSize().width/2, spriteWrapper->getContentSize().height/2));

        auto menuItem = MenuItemSpriteExtra::create(spriteWrapper, nullptr, this, callback);

        auto worldPos = block->convertToWorldSpace();
        auto nodePos = menu->convertToNodeSpace(worldPos);
        menuItem->setPosition(nodePos);

        menu->addChild(menuItem);

        return menuItem;
    };

    auto blockRItem = createMenuItemFromBlock(blockR, menu_selector(MenuLayer::onPlayClicked));
    auto blockGItem = createMenuItemFromBlock(blockG, menu_selector(MenuLayer::onStoreClicked));
    auto blockBItem = createMenuItemFromBlock(blockB, menu_selector(MenuLayer::onExtrasClicked));
    auto blockYItem = createMenuItemFromBlock(blockY, menu_selector(MenuLayer::onFreeGoldClicked));

    this->blockR = blockR;
    this->blockG = blockG;
    this->blockB = blockB;
    this->blockY = blockY;
}

void MenuLayer::onPlayClicked(cocos2d::Ref* sender) {
    AXLOG("Play button clicked");
}

void MenuLayer::onStoreClicked(cocos2d::Ref* sender) {
    AXLOG("Store button clicked");
}

void MenuLayer::onExtrasClicked(cocos2d::Ref* sender) {
    AXLOG("Extras button clicked");
}

void MenuLayer::onFreeGoldClicked(cocos2d::Ref* sender) {
    AXLOG("Free Gold button clicked");
}