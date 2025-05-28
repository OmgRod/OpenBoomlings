// MenuLayer.cpp

#include "MenuLayer.hpp"

using namespace ax;

bool MenuLayer::init() {
    if (!Layer::init()) {
        return false;
    }

    // Enable keypad (if needed)
    // this->setKeypadEnabled(true);

    // Shared game manager call, replicated from decompiled logic
    // (commented as GameManager not defined here)
    // GameManager::sharedState()->someMethod(1);

    auto director = Director::getInstance();
    Size visibleSize = director->getVisibleSize();
    Vec2 origin = director->getVisibleOrigin();

    // Background sprite
    auto mainMenuBG = Sprite::create("images/menuSheet/MainMenuBG_001.png");
    mainMenuBG->setPosition(origin.x + visibleSize.width / 2, origin.y + visibleSize.height / 2);

    // Scale background uniformly to cover the whole visible size
    float scaleX = visibleSize.width / mainMenuBG->getContentSize().width;
    float scaleY = visibleSize.height / mainMenuBG->getContentSize().height;
    float scale = std::max(scaleX, scaleY);
    mainMenuBG->setScale(scale);
    this->addChild(mainMenuBG, 0);

    // Logo sprite, centered at top (approx 85% height)
    auto logoSprite = Sprite::create("images/menuSheet/boomlingslogo.png");
    logoSprite->setPosition(origin.x + visibleSize.width / 2, origin.y + visibleSize.height * 0.85f);
    // this->addChild(logoSprite, 2);

    // Add a particle effect on logo (from decompiled: "glitterEffect.plist")
    auto glitterEffect = ParticleSystemQuad::create();
    this->addChild(glitterEffect, 1);
    glitterEffect->setPosition(logoSprite->getPosition());

    // Setup menu buttons & related UI elements
    // setupMenuButtons();

    // --- RobTop Menu Item (small logo) ---
    auto robtopLogoSprite = Sprite::create("images/menuSheet/robtoplogo_small.png");
    robtopLogoSprite->setAnchorPoint(Vec2(0.f, 0.f));

    auto robtopMenuItem = MenuItemSprite::create(robtopLogoSprite, robtopLogoSprite,
        AX_CALLBACK_0(MenuLayer::menuRobtopCallback, this));

    auto robtopMenu = Menu::create(robtopMenuItem, nullptr);
    robtopMenu->setPosition(
        origin.x + visibleSize.width * 0.025f + robtopLogoSprite->getContentSize().width / 2,
        origin.y + visibleSize.height * 0.025f + robtopLogoSprite->getContentSize().height / 2
    );
    this->addChild(robtopMenu, 2);

    // --- Feedback Menu Item ---
    auto feedbackSprite = Sprite::create("images/menuSheet/feedbackBtn_001.png");
    auto feedbackItem = MenuItemSprite::create(feedbackSprite, feedbackSprite,
        AX_CALLBACK_0(MenuLayer::menuFeedbackCallback, this));

    auto feedbackMenu = Menu::create(feedbackItem, nullptr);
    feedbackMenu->setPosition(origin.x + visibleSize.width / 2 + 130, origin.y + visibleSize.height * 0.7f);
    this->addChild(feedbackMenu, 2);

    // --- Hello Sprite (left of RobTop button) ---
    auto helloSprite = Sprite::create("images/menuSheet/hello_001.png");
    helloSprite->setPosition(origin.x + visibleSize.width / 2 - 130, origin.y + visibleSize.height * 0.62f);
    this->addChild(helloSprite, 1);

    // --- Feedback Text below RobTop button ---
    auto feedbackTextSprite = Sprite::create("images/menuSheet/feedback_001.png");
    feedbackTextSprite->setPosition(origin.x + visibleSize.width / 2, origin.y + visibleSize.height * 0.53f);
    this->addChild(feedbackTextSprite, 1);

    // --- Rate Button to the right of Daily button ---
    auto rateBtnSprite = Sprite::create("images/menuSheet/rateBtn_001.png");
    auto rateMenuItem = MenuItemSprite::create(rateBtnSprite, rateBtnSprite,
        AX_CALLBACK_0(MenuLayer::menuRateCallback, this));

    auto rateMenu = Menu::create(rateMenuItem, nullptr);
    rateMenu->setPosition(origin.x + visibleSize.width / 2 + 180, origin.y + visibleSize.height * 0.37f);
    this->addChild(rateMenu, 4);

    // Rate sprite with moving animation above Rate button
    auto rateSprite = Sprite::create("images/menuSheet/rate_001.png");
    rateSprite->setPosition(rateMenu->getPosition() + Vec2(0, 40));
    this->addChild(rateSprite, 4);

    float duration = 1.0f;
    auto moveRight = MoveBy::create(duration, Vec2(10, 0));
    auto easeMove = EaseInOut::create(moveRight, 2);
    auto sequence = Sequence::create(easeMove, easeMove->reverse(), nullptr);
    rateSprite->runAction(RepeatForever::create(sequence));

    // --- More Games Button to the left and below Daily button ---
    auto moreGamesBtn = Sprite::create("images/moreGamesBtn_001.png");
    auto moreGamesItem = MenuItemSprite::create(moreGamesBtn, moreGamesBtn,
        AX_CALLBACK_0(MenuLayer::menuMoreGamesCallback, this));

    auto moreGamesMenu = Menu::create(moreGamesItem, nullptr);
    moreGamesMenu->setPosition(origin.x + visibleSize.width / 2 - 180, origin.y + visibleSize.height * 0.32f);
    this->addChild(moreGamesMenu, 4);

    return true;
}

// Callback implementations
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

// Static create method
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

// Create scene with MenuLayer
Scene* MenuLayer::scene() {
    auto scene = Scene::create();
    auto layer = MenuLayer::create();
    scene->addChild(layer);
    return scene;
}
