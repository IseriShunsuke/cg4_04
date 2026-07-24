#include "GameScene.h"
#include "Math.h"

using namespace KamataEngine;


// デストラクタ
GameScene::~GameScene()
{
	delete sprite_;
	delete spriteNext_;
}

// 初期化
void GameScene::Initialize()
{
	// カメラの初期化
	camera_.Initialize();

	textureHandle_ = TextureManager::Load("stage.png");
	textureHandleNext_ = TextureManager::Load("stageB.png");

	model_ = Model::CreateFromOBJ("player");

	player_.Initialize(model_);

	position = {0.0f, 0.0f};
	sprite_ = Sprite::Create(textureHandle_, position);

	nextPosition = {1280.0f, 0.0f};
	spriteNext_ = Sprite::Create(textureHandle_, nextPosition);
}

// 更新
void GameScene::Update()
{
	player_.Update();

	position.x -= 2.0f;
	nextPosition.x -= 2.0f;

	if (position.x <= -1280.0f) {
		position.x = 1280.0f;
	}

	if (nextPosition.x <= -1280.0f) {
		nextPosition.x = 1280.0f;
	}

	sprite_->SetPosition(position);
	spriteNext_->SetPosition(nextPosition);
}

// 描画
void GameScene::Draw() 
{
	DirectXCommon* dxcommon = DirectXCommon::GetInstance();

	Sprite::PreDraw(dxcommon->GetCommandList());

	sprite_->Draw();
	spriteNext_->Draw();

	Sprite::PostDraw();

	Model::PreDraw();

	player_.Draw(camera_);

	Model::PostDraw();
}