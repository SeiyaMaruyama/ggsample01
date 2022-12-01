﻿#pragma once

///
/// メニューの描画クラスの定義
///
/// @file
/// @author Kohe Tokoi
/// @date November 15, 2022
///

// 構成データ
#include "Config.h"

///
/// メニューの描画
///
class Menu
{
  // 図形の描画クラスから参照する
  friend class Draw;

  // オリジナルの構成データ
  const Config& defaults;

  // 構成データのコピー
  Config settings;

  // CAD データ
  std::unique_ptr<GgSimpleObj> model;

  // 光源データ
  std::unique_ptr<GgSimpleShader::LightBuffer> light;

  // シェーダ
  std::unique_ptr<GgSimpleShader> shader;

public:

  ///
  /// コンストラクタ
  ///
  Menu(const Config& config);

  // コピーコンストラクタは封じる
  Menu(const Menu& menu) = delete;

  ///
  /// デストラクタ
  ///
  virtual ~Menu();

  // 代入演算子は封じる
  Menu& operator=(const Menu& menu) = delete;

  ///
  /// 描画する
  ///
  void draw();
};
