// #include "SimpleGamePiece.hpp"
// #include "base/CCDirector.h"
// #include "platform/CCFileUtils.h"
// #include "2d/CCSprite.h"
// #include "base/CCValue.h"

// using namespace ax;

// bool SimpleGamePiece::initWithType(const char* typeName) {
//     if (!typeName) {
//         AXLOG("initWithType called with null typeName");
//         return false;
//     }

//     ObjectManager* objectManager = ObjectManager::instance();
//     if (!objectManager) {
//         AXLOG("ObjectManager instance is null");
//         return false;
//     }

//     const ValueMap* definition = objectManager->getDefinition(typeName);
//     if (!definition) {
//         AXLOG("No definition found for type: %s", typeName);
//         return false;
//     }

//     const std::string spriteSheetKey = "spriteSheet";
//     auto iter = definition->find(spriteSheetKey);
//     if (iter == definition->end()) {
//         AXLOG("No spriteSheet key found for type: %s", typeName);
//         return false;
//     }

//     std::string spriteSheetFile = iter->second.asString();

//     std::string fullPath = FileUtils::getInstance()->fullPathForFilename(spriteSheetFile);

//     Texture2D* texture = Director::getInstance()->getTextureCache()->addImage(fullPath);
//     if (!texture) {
//         AXLOG("Failed to load texture: %s", fullPath.c_str());
//         return false;
//     }

//     if (!Sprite::initWithTexture(texture)) {
//         AXLOG("Sprite::initWithTexture failed");
//         return false;
//     }

//     static const char* kTypeInfo = "SimpleGamePieceTypeInfo";
//     this->typeInfo = kTypeInfo;

//     AnimatedSprite::loadType(this, typeName);

//     return true;
// }

// SimpleGamePiece* SimpleGamePiece::createWithType(const char* typeName) {
//     SimpleGamePiece* sprite = new (std::nothrow) SimpleGamePiece();
//     if (!sprite) {
//         AXLOG("Failed to allocate SimpleGamePiece");
//         return nullptr;
//     }

//     if (!sprite->initWithType(typeName)) {
//         delete sprite;
//         return nullptr;
//     }

//     sprite->autorelease();
//     return sprite;
// }

// void SimpleGamePiece::animationFinished() {
//     if (_animManager) {
//         _animManager->resetAnimState();
//         _animManager->runAnimation();
//     }
// }
