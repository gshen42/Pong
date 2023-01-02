#pragma once

constexpr int SCREEN_WIDTH = 1280;
constexpr int SCREEN_HEIGHT = 720;
constexpr int BOARDER_WIDTH = 20;

constexpr int PLAYER_H = 100;
constexpr int PLAYER_W = 20;
constexpr int PLAYER_COLOR_R = 234;
constexpr int PLAYER_COLOR_G = 30;
constexpr int PLAYER_COLOR_B = 30;
constexpr int PLAYER_COLOR_A = 255;

constexpr int PLAYERA_INIT_X = SCREEN_WIDTH - 100;
constexpr int PLAYERA_INIT_Y = SCREEN_HEIGHT / 2;
constexpr int PLAYERB_INIT_X = 100;
constexpr int PLAYERB_INIT_Y = SCREEN_HEIGHT / 2;

constexpr int BALL_RADIUS = 10;
constexpr int BALL_INIT_X = SCREEN_WIDTH / 2 - BALL_RADIUS;
constexpr int BALL_INIT_Y = SCREEN_HEIGHT / 2 - BALL_RADIUS;
constexpr int BALL_INIT_VX = 5;
constexpr int BALL_INIT_VY = 0;
constexpr int BALL_COLOR_R = 255;
constexpr int BALL_COLOR_G = 255;
constexpr int BALL_COLOR_B = 255;
constexpr int BALL_COLOR_A = 255;

constexpr double PI = 3.141593;
constexpr double RADIAN_MAX = 65 * PI / 180;
