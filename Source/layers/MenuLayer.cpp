#include "MenuLayer.hpp"

using namespace ax;

bool MenuLayer::init() {
    if (!Layer::init()) {
        return false;
    }

    auto director = Director::getInstance();
    Size visibleSize = director->getVisibleSize();
    Vec2 origin = director->getVisibleOrigin();

    auto mainMenuBG = Sprite::create("images/menuSheet/MainMenuBG_001.png");
    if (!mainMenuBG) {
        AXLOG("Failed to load MainMenuBG_001.png");
        return false;
    }
    mainMenuBG->setPosition(origin.x + visibleSize.width / 2, origin.y + visibleSize.height / 2);

    float scaleX = visibleSize.width / mainMenuBG->getContentSize().width;
    float scaleY = visibleSize.height / mainMenuBG->getContentSize().height;
    float scale = std::max(scaleX, scaleY);
    mainMenuBG->setScale(scale);
    this->addChild(mainMenuBG, 0);

    auto logoSprite = Sprite::create("images/menuSheet/boomlingslogo.png");
    if (!logoSprite) {
        AXLOG("Failed to load boomlingslogo.png");
        return false;
    }
    logoSprite->setPosition(origin.x + visibleSize.width / 2, origin.y + visibleSize.height * 0.85f);
    this->addChild(logoSprite, 2);

    auto glitterEffect = ParticleSystemQuad::create("plist/glitterEffect.plist");
    if (glitterEffect) {
        glitterEffect->setTexture(Director::getInstance()->getTextureCache()->addImage("images/particleImgSheet/starParticle.png"));
        glitterEffect->setScale(2.f);
        glitterEffect->setPosition(logoSprite->getPosition());
        this->addChild(glitterEffect, 1);
    }

    setupMenuButtons();

    auto robtopLogoSprite = Sprite::create("images/menuSheet/robtoplogo_small.png");
    if (!robtopLogoSprite) {
        AXLOG("Failed to load robtoplogo_small.png");
        return false;
    }
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
    if (!feedbackSprite) {
        AXLOG("Failed to load feedbackBtn_001.png");
        return false;
    }
    auto feedbackItem = MenuItemSpriteExtra::create(feedbackSprite, feedbackSprite,
        AX_CALLBACK_0(MenuLayer::menuFeedbackCallback, this));

    auto feedbackMenu = Menu::create(feedbackItem, nullptr);
    feedbackMenu->setPosition(origin.x + visibleSize.width / 2 + 130, origin.y + visibleSize.height * 0.7f);
    this->addChild(feedbackMenu, 2);

    auto helloSprite = Sprite::create("images/menuSheet/hello_001.png");
    if (helloSprite) {
        helloSprite->setPosition(origin.x + visibleSize.width / 2 - 130, origin.y + visibleSize.height * 0.62f);
        this->addChild(helloSprite, 1);
    }

    auto feedbackTextSprite = Sprite::create("images/menuSheet/feedback_001.png");
    if (feedbackTextSprite) {
        feedbackTextSprite->setPosition(origin.x + visibleSize.width / 2, origin.y + visibleSize.height * 0.53f);
        this->addChild(feedbackTextSprite, 1);
    }

    auto rateBtnSprite = Sprite::create("images/menuSheet/rateBtn_001.png");
    if (!rateBtnSprite) {
        AXLOG("Failed to load rateBtn_001.png");
        return false;
    }
    auto rateMenuItem = MenuItemSpriteExtra::create(rateBtnSprite, rateBtnSprite,
        AX_CALLBACK_0(MenuLayer::menuRateCallback, this));

    auto rateMenu = Menu::create(rateMenuItem, nullptr);
    rateMenu->setPosition(origin.x + visibleSize.width / 2 + 180, origin.y + visibleSize.height * 0.37f);
    this->addChild(rateMenu, 4);

    auto rateSprite = Sprite::create("images/menuSheet/rate_001.png");
    if (rateSprite) {
        rateSprite->setPosition(rateMenu->getPosition() + Vec2(0, 40));
        this->addChild(rateSprite, 4);

        float duration = 1.0f;
        auto moveRight = MoveBy::create(duration, Vec2(10, 0));
        auto easeMove = EaseInOut::create(moveRight, 2);
        auto sequence = Sequence::create(easeMove, easeMove->reverse(), nullptr);
        rateSprite->runAction(RepeatForever::create(sequence));
    }

    auto moreGamesBtn = Sprite::create("images/moreGamesBtn_001.png");
    if (!moreGamesBtn) {
        AXLOG("Failed to load moreGamesBtn_001.png");
        return false;
    }
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

void MenuLayer::setupMenuButtons() {
    auto director = Director::getInstance();
    Size visibleSize = director->getVisibleSize();
    Vec2 origin = director->getVisibleOrigin();

    auto playSprite = Sprite::create("images/menuSheet/mainPlayBtn_001.png");
    if (!playSprite) {
        AXLOG("Failed to load mainPlayBtn_001.png");
        return;
    }
    auto playItem = MenuItemSpriteExtra::create(playSprite, playSprite, AX_CALLBACK_0(MenuLayer::onPlayClicked, this));

    auto storeSprite = Sprite::create("images/menuSheet/mainStoreBtn_001.png");
    if (!storeSprite) {
        AXLOG("Failed to load mainStoreBtn_001.png");
        return;
    }
    auto storeItem = MenuItemSpriteExtra::create(storeSprite, storeSprite, AX_CALLBACK_0(MenuLayer::onStoreClicked, this));

    auto extrasSprite = Sprite::create("images/menuSheet/mainExtrasBtn_001.png");
    if (!extrasSprite) {
        AXLOG("Failed to load mainExtrasBtn_001.png");
        return;
    }
    auto extrasItem = MenuItemSpriteExtra::create(extrasSprite, extrasSprite, AX_CALLBACK_0(MenuLayer::onExtrasClicked, this));

    auto freeGoldSprite = Sprite::create("images/menuSheet/freeGoldBtn_001.png");
    if (!freeGoldSprite) {
        AXLOG("Failed to load freeGoldBtn_001.png");
        return;
    }
    auto freeGoldItem = MenuItemSpriteExtra::create(freeGoldSprite, freeGoldSprite, AX_CALLBACK_0(MenuLayer::onFreeGoldClicked, this));

    auto menu = Menu::create(playItem, storeItem, extrasItem, freeGoldItem, nullptr);
    menu->setPosition(Vec2::ZERO);
    this->addChild(menu, 2);

    float padding = visibleSize.height * 0.05f;
    menu->alignItemsVerticallyWithPadding(padding);

    // Optionally, position menu somewhere else if needed
    menu->setPosition(origin.x + visibleSize.width / 2, origin.y + visibleSize.height * 0.3f);
}

void MenuLayer::onPlayClicked() {
    AXLOG("Play button clicked");
}

void MenuLayer::onStoreClicked() {
    AXLOG("Store button clicked");
}

void MenuLayer::onExtrasClicked() {
    AXLOG("Extras button clicked");
}

void MenuLayer::onFreeGoldClicked() {
    AXLOG("Free Gold button clicked");
}
