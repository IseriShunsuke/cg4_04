#pragma once
#include "KamataEngine.h"

using namespace KamataEngine;

class TitleScene 
{
public:
	/// <summary>
	/// デストラクタ
	/// </summary>
	~TitleScene();

	/// <summary>
	/// 初期化
	/// </summary>
	void Initialize();

	/// <summary>
	/// 更新
	/// </summary>
	void Update();

	/// <summary>
	/// 描画
	/// </summary>
	void Draw();

private:
	uint32_t textureHandle_;

	uint32_t fontTextureHandle_;

	Sprite* sprite_ = nullptr;
	Sprite* spriteFont_ = nullptr;
};
