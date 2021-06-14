#ifndef MY_CONFIG_H
#define MY_CONFIG_H

#define BACKGROUND_MUSIC_PATH "res/Cypis-Polish_cow_dancing.wav"
#define BACKGROUND_IMG_PATH_0 "res/background_0.jpg"
#define BACKGROUND_IMG_PATH_1 "res/background_1.jpg"
#define BACKGROUND_IMG_PATH_2 "res/background_2.jpg"
#define WINDOW_HEIGHT 600
#define WINDOW_WIDTH 900

#define COW_SPRITE_PATH "res/cow_sprite_sheet.png"
#define COW_SPRITE_HEIGHT 179 //высота кадра спрайта 
#define COW_SPRITE_HEIGHT_INDENT COW_SPRITE_HEIGHT / 2 //вертикальное смещение центра спрайта
#define COW_SPRITE_WIDTH 215 //ширирна кадра спрайта 
#define COW_SPRITE_WIDTH_INDENT COW_SPRITE_WIDTH / 2 //горизонтальное смещение центра спрайта 
#define COW_SPRITE_SIZE 20 //количество кадров спрайта 
#define COW_SPRITE_START_NUM 1 //начальный кадр

#define COW_RESET_SPRITE_ON_STOP false // устанавливать ли начальный кадр спрайта при остановке коровы
#define COW_SPRITE_SPEED_MS                                                    \
  100 // скорость смены кадров спрайта коровы (кол-во мс показа одного кадра)
#define COW_LEFT_WINDOW_BORDER                                                 \
  static_cast<float>(                                                          \
      COW_SPRITE_WIDTH_INDENT) // координата левой стенки для коровы
#define COW_RIGHT_WINDOW_BORDER                                                \
  static_cast<float>(WINDOW_WIDTH) - COW_SPRITE_WIDTH_INDENT // координата правой стенки для коровы

#define COW_JUMP_VELOCITY 1.5f // пикс/мс начальная скорость прыжка
#define COW_HORIZONTAL_VELOCITY 0.4f // пикс/мс скорость ходьбы

#define COW_MOVE_LEFT_BUTTON sf::Keyboard::A  // кнопка влево
#define COW_MOVE_RIGHT_BUTTON sf::Keyboard::D // кнопка вправо
#define COW_JUMP_BUTTON sf::Keyboard::Space   // кнопка прыжка
#define BACKGROUND_CHANGE_BUTTON sf::Keyboard::Enter //кнопка смены фона

#define COW_FLOOR 400.0f // координата пола для коровы

#define GLOBAL_GRAVITY 0.005f // пикс/мс^2 гравитационная постоянная

#endif // MY_CONFIG_H