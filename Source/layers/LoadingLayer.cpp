#include "LoadingLayer.hpp"

using namespace ax;

bool LoadingLayer::init() {
    if (!Layer::init()) {
        return false;
    }

    auto dir = Director::getInstance();

    time_t currentTime = time(nullptr);
    srand(currentTime);

    Sprite* background = Sprite::create("images/startMenuSheet/BlankBG_001.png");
    background->setPosition(dir->getWinSize() / 2);
    this->addChild(background);

    Sprite* logo = Sprite::create("images/startMenuSheet/RobTopLogoBig_001.png");
    logo->setPosition(dir->getWinSize() / 2);
    this->addChild(logo);

    this->m_showingLoadingString = true;
    this->m_loadingLabel = Label::createWithBMFont("fonts/goldFont.fnt", std::string(getLoadingString()), ax::TextHAlignment::CENTER, 400.0f);

    this->m_loadingLabel->setPosition(dir->getWinSize() / 2);
    this->m_loadingLabel->setScale(0.7f);
    this->addChild(this->m_loadingLabel);

    auto labelSize = this->m_loadingLabel->getContentSize();
    if (labelSize.width > 300.0f) {
        float newScale = 300.0f / labelSize.width;
        this->m_loadingLabel->setScale(newScale);
    }

    Sprite* sliderGroove = Sprite::create("images/slidergroove.png");
    this->addChild(sliderGroove, 3);

    Sprite* sliderBar = Sprite::create("images/sliderBar.png");
    this->m_sliderBar = sliderBar;
    this->m_sliderBarScale = 8.0f;
    this->m_sliderBarMaxWidth = sliderGroove->getContentSize().width - 4.0f;

    Texture2D::TexParams params;
    params.minFilter = backend::SamplerFilter::LINEAR;
    params.magFilter = backend::SamplerFilter::LINEAR;
    params.sAddressMode = backend::SamplerAddressMode::REPEAT;
    params.tAddressMode = backend::SamplerAddressMode::REPEAT;

    this->m_sliderBar->getTexture()->setTexParameters(params);
    sliderGroove->addChild(this->m_sliderBar);
    this->m_sliderBar->setAnchorPoint(Point(0, 0.5f));
    this->m_sliderBar->setPosition(Point(0, sliderGroove->getContentSize().height / 2));

    auto labelPos = this->m_loadingLabel->getPosition();
    sliderGroove->setPosition(Point(labelPos.x, labelPos.y - 35.0f));

    this->updateProgress();

    auto delay = DelayTime::create(0.0f);
    auto callback = CallFunc::create([this]() { this->loadAssets(); });
    auto sequence = Sequence::create(delay, callback, nullptr);
    dir->getActionManager()->addAction(sequence, this, false);

    return true;
}

void LoadingLayer::updateProgress(int progress) {
    float x = 0.0f;
    float y = 0.0f;
    float fullWidth = 200.0f;
    float height = 20.0f;
    
    float width = fullWidth * (progress / 100.0f);
    
    Rect rect(x, y, width, height);
    
    if (m_sliderBar) {
        m_sliderBar->setTextureRect(rect);
    }
}

const char * LoadingLayer::getLoadingString() {
    static std::random_device rd;
    static std::mt19937 gen(rd());
    static std::uniform_int_distribution < > distrib(0, 54);

    int value = distrib(gen);

    switch (value) {
    case 1:
        return "Blink twice to continue";
    case 2:
        return "To the Boommobile!";
    case 3:
        return "I R Game Master";
    case 4:
        return "So worth the wait";
    case 5:
        return "Bah, humbug!";
    case 6:
        return "Detonating bombs";
    case 7:
        return "Building a castle";
    case 8:
        return "Beware of Trolls";
    case 9:
        return "Wait for my signal!";
    case 10:
        return "Random Nonsence";
    case 11:
        return "Get to the Chopper!";
    case 12:
        return "What is the Boom?";
    case 13:
        return "It\'s a trap!";
    case 14:
        return "Skulls are just misunderstood";
    case 15:
        return "I am the Boom!";
    case 16:
        return "Waiting is optional";
    case 17:
        return "Watch out for the Bandits";
    case 18:
        return "Look closely...";
    case 19:
        return "Fire the cannon!";
    case 20:
        return "Chain bomb frenzy";
    case 21:
        return "Look behind you";
    case 22:
        return "You should play more often...";
    case 23:
        return "AFK";
    case 24:
        return "Mu mu mu Multikill!";
    case 25:
        return "zzzZZZ...";
    case 26:
        return "Insert funny quote";
    case 27:
        return "Think of a joke, then laugh";
    case 28:
        return "Arr, here be dragons!";
    case 29:
        return "Best loading screen EVER!";
    case 30:
        return "Uh oh...";
    case 31:
        return "Do a barrel roll";
    case 32:
        return "Grow 10 feet to continue";
    case 33:
        return "Sorry about the ads...";
    case 34:
        return "Boomlings need to eat too";
    case 35:
        return "This.. IS.. BOOMLINGS!";
    case 36:
        return "Catching Mega Blobs";
    case 37:
        return "Mega Bombs are awesome";
    case 38:
        return "Running low on Blobs...";
    case 39:
        return "Quickly, hide!";
    case 40:
        return "Up, Up, Down, Down, Left, Right, Left, Right, B, A";
    case 41:
        return "Why not?";
    case 42:
        return "Prepare for battle!";
    case 43:
        return "Speillng is overraetd";
    case 44:
        return "Just kidding";
    case 45:
        return "Awesome entertainment imminent";
    case 46:
        return "You can\'t handle The BOOM!";
    case 47:
        return "Level up!";
    case 48:
        return "Rage quit incoming...";
    case 49:
        return "What if game plays you?";
    case 50:
        return "Running out of ideas";
    case 51:
        return "Rate the game, you will...";
    case 52:
        return "Nice day to rate the game!";
    case 53:
        return "Developers don\'t need to sleep!";
    case 54:
        return "Boomlings like Stars...";
    default:
        return "The Boom approaches..";
    }
}

Scene* LoadingLayer::scene() {
    Scene* scene = Scene::create();
    LoadingLayer* layer = LoadingLayer::create();
    scene->addChild(layer);
    return scene;
}

LoadingLayer* LoadingLayer::create() {
    LoadingLayer* ret = new (std::nothrow) LoadingLayer();
    if (ret && ret->init()) {
        ret->autorelease();
        return ret;
    } else {
        delete ret;
        return nullptr;
    }
}

void LoadingLayer::loadAssets() {
    static int loadStep = 0;
    int currentStep = loadStep;

    if (currentStep < 1) {
        // FileSaveManager::sharedState()->load();
        // GameStoreManager::sharedState()->load();

        // GameSoundManager::sharedManager()->setup();
        // GameStatsManager::sharedState()->load();

        // GameKitManager::sharedState()->setup();
        // GameManager::sharedState()->load();

        // int someFlag = 0;
        // GameManager::sharedState()->getSomeData(&someFlag);
        // if (someFlag == 0) {
        //     AppDelegate::getUserID();
        // }

        // MoreGamesManager::sharedState()->checkMoreGames();

        // AppDelegate::setSomeFlag(1);

        // auto fontCache = BitmapFontCache::sharedFontCache();
        // fontCache->fontWithConfigFile("chatFont.fnt");

        auto textureCache = Director::getInstance()->getTextureCache();
        textureCache->addImage("fonts/goldFont.png");
        textureCache->addImage("fonts/bigFont.png");
        textureCache->addImage("fonts/levelFont.png");
        textureCache->addImage("fonts/numbersFont.png");
        textureCache->addImage("fonts/scoreFont2.png");

        Vec2 dummyPos = Vec2(0, 0);
        Label::createWithBMFont("", "fonts/goldFont.fnt", ax::TextHAlignment::CENTER, 0, dummyPos);
        Label::createWithBMFont("", "fonts/bigFont.fnt", ax::TextHAlignment::CENTER, 0, dummyPos);
        Label::createWithBMFont("", "fonts/levelFont.fnt", ax::TextHAlignment::CENTER, 0, dummyPos);
        Label::createWithBMFont("", "fonts/numbersFont.fnt", ax::TextHAlignment::CENTER, 0, dummyPos);
        Label::createWithBMFont("", "fonts/scoreFont2.fnt", ax::TextHAlignment::CENTER, 0, dummyPos);

        Texture2D::setDefaultAlphaPixelFormat(backend::PixelFormat::RGBA8);
        // textureCache->addImage("square03_001.png");

        Texture2D::setDefaultAlphaPixelFormat(backend::PixelFormat::RGBA4);
    } else {
        auto textureCache = Director::getInstance()->getTextureCache();
        auto spriteFrameCache = SpriteFrameCache::getInstance();

        switch (currentStep) {
            // case 1:
            //     textureCache->addImage("BoomUISheet.png");
            //     spriteFrameCache->addSpriteFramesWithFile("BoomUISheet.plist");
            //     break;

            // case 2:
            //     textureCache->addImage("ObjectSheet.png");
            //     spriteFrameCache->addSpriteFramesWithFile("ObjectSheet.plist");
            //     break;

            // case 3:
            //     textureCache->addImage("boomIconSheet.png");
            //     spriteFrameCache->addSpriteFramesWithFile("boomIconSheet.plist");
            //     break;

            // case 4:
            //     // textureCache->addImage("menuSheet.png");
            //     // spriteFrameCache->addSpriteFramesWithFile("menuSheet.plist");

            //     // textureCache->addImage("particleImgSheet.png");
            //     // spriteFrameCache->addSpriteFramesWithFile("particleImgSheet.plist");

            //     // textureCache->addImage("BoomSheet02.png");
            //     // spriteFrameCache->addSpriteFramesWithFile("BoomSheet02.plist");

            //     // ObjectManager::instance()->setup();
            //     break;
            // case 10:
            //     SpriteFrameCache::getInstance()->addSpriteFramesWithFile("plist/Color_xyz_AnimDesc.plist");
            //     break;
            // case 12:
            //     SpriteFrameCache::getInstance()->addSpriteFramesWithFile("plist/MegaColor_xyz_AnimDesc.plist");

            //     break;

            case 13:
            {
                // GameSaveManager::sharedState()->load();

                // GameManager::sharedState()->fadeInMusic("audio/BoomlingsTitle.mp3");

                // GameAdManager::sharedState()->setup();

                // GameKitManager::sharedState()->setupAchievementRewards();

                auto director = Director::getInstance();

                // int offset = AppDelegate::get();
                // int delay = offset == 0 ? 0 : offset + 4;
                // director->getScheduler()->schedule([this](float) { this->loadingFinished(); }, this, 0, false);

                // if (AppDelegate::isNetworkAvailable())
                // {
                //     if (!GameStoreManager::sharedState()->isFeatureUnlocked("boomlings.iap.premium"))
                //     {
                //         GameAdManager::sharedState()->cacheInterstitial();
                //         GameAdManager::sharedState()->updateAdPrio();
                //     }

                //     int local1 = 0;
                //     GameManager::sharedState()->getSomeData(&local1);

                //     bool someFlag = false;
                //     if (local1 != 0)
                //     {
                //         int local2 = 0;
                //         GameManager::sharedState()->getSomeData(&local2);
                //         someFlag = (local2 != 0);
                //     }

                //     if (someFlag)
                //     {
                //         GameSocialManager::sharedState()->getRefBonus(false);
                //     }

                //     GameKitManager::sharedState()->submitCachedScores();
                //     GameKitManager::sharedState()->trySubmitFBScore();
                // }

                // AppDelegate::get()->loadingIsFinished();
                // GameSocialManager::performQueuedFBAction();
                // GameAdManager::sharedState()->getTapPoints();

                // if (!GameManager::sharedState()->isInitialized())
                // {
                //     AppDelegate::get()->onGameLaunch();
                // }

                loadingFinished();
                return;
            }

            default:
                break;
        }
    }

    // Timing code removed due to incomplete type and undefined function

    // _loadFinished = true;

    loadStep += 1;

    updateProgress();

    auto director = Director::getInstance();
    auto scheduler = director->getScheduler();

    auto delay = DelayTime::create(0.1f);

    auto callFunc = CallFunc::create([this]() {
        this->loadAssets();
    });

    auto seq = Sequence::create(delay, callFunc, nullptr);

    this->runAction(seq);
}

void LoadingLayer::loadingFinished() {
    auto director = Director::getInstance();
    auto scene = MenuLayer::scene();
    director->replaceScene(scene);
}