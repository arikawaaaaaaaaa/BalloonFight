#pragma once

//スクリーンサイズ(縦・横)
#define SCREEN_HEIGHT 480
#define SCREEN_WIDTH 640

//ゲーム画面のサイズ
#define GAME_WIDTH 512

#define SCREEN_COLOR_BIT_16 16

//マップブロック数(縦・横)
#define MAP_HEIGHT 30
#define MAP_WIDTH 32

//UI枠のサイズ
#define UI_SIZE 100

//左右の余白
#define SIDE_MARGIN (SCREEN_WIDTH - GAME_WIDTH) / 2

//ブロック1つのサイズ(正方形)
#define BLOCK_SIZE GAME_WIDTH / MAP_WIDTH