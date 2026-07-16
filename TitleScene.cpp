#include "TitleScene.h"

TitleScene::~TitleScene()
{ delete sprite_; }

void TitleScene::Initialize()
{
	textureHandle_ = TextureManager::Load("titlebg.png");
	sprite_ = Sprite::Create(textureHandle_, {0.0f, 0.0f});
}

void TitleScene::Update()
{

}

void TitleScene::Draw() { sprite_->Draw(); }
