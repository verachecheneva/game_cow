#ifndef MY_CONFIG_H
#define MY_CONFIG_H

const std::string BACKGROUND_MUSIC_PATH = "res/Cypis-Polish_cow_dancing.wav"; ///< относительный путь до музыки
const std::string BACKGROUND_IMG_PATH_0 = "res/background_0.jpg"; ///< относительный путь до картинки фона 0
const std::string BACKGROUND_IMG_PATH_1 = "res/background_1.jpg"; ///< относительный путь до картинки фона 1
const std::string BACKGROUND_IMG_PATH_2 = "res/background_2.jpg"; ///< относительный путь до картинки фона 2
const int WINDOW_HEIGHT = 600; ///< высота окна
const int WINDOW_WIDTH = 900;  ///< ширина окна


const std::string COW_SPRITE_PATH = "res/cow_sprite_sheet.png";  ///< относительный путь до картинки спрайта коровы
const int COW_SPRITE_HEIGHT = 179; ///< высота кадра спрайта
const int COW_SPRITE_HEIGHT_INDENT = COW_SPRITE_HEIGHT / 2; ///< вертикальное смещение цента спрайта
const int COW_SPRITE_WIDTH = 215; ///< ширина кадра спрайта
const int COW_SPRITE_WIDTH_INDENT = COW_SPRITE_WIDTH / 2; ///< горизонтальное смещение цента спрайта
const int COW_SPRITE_SIZE = 20; ///< количество кадров у спрайта
const int COW_SPRITE_START_NUM = 1; ///< начальный кадр   (0 <= COW_SPRITE_START_NUM < COW_SPRITE_SIZE)

const bool COW_RESET_SPRITE_ON_STOP = false; ///< устанавливать ли начальный кадр спрайта при остановке коровы
const int COW_SPRITE_SPEED_MS = 100; ///< скорость смены кадров спрайта коровы (кол-во мс показа одного кадра)

const float COW_LEFT_WINDOW_BORDER = static_cast<float>(COW_SPRITE_WIDTH_INDENT); ///< координата левой стенки для коровы
const float COW_RIGHT_WINDOW_BORDER = static_cast<float>(WINDOW_WIDTH) - COW_SPRITE_WIDTH_INDENT; ///< координата правой стенки для коровы

const float COW_JUMP_VELOCITY = 1.5f; ///< пикс/мс начальная скорость прыжка
const float COW_HORIZONTAL_VELOCITY = 0.4f; ///< пикс/мс скорость ходьбы 

const auto COW_MOVE_LEFT_BUTTON = sf::Keyboard::Left; ///< кнопка влево
const auto COW_MOVE_RIGHT_BUTTON = sf::Keyboard::Right; ///< кнопка вправо 
const auto COW_JUMP_BUTTON = sf::Keyboard::Space; ///< кнопка прыжка
const auto BACKGROUND_CHANGE_BUTTON = sf::Keyboard::Enter; ///< кнопка смены фона

const float COW_FLOOR = 400.0f; ///< координата пола для коровы

const float GLOBAL_GRAVITY = 0.005f; ///< пикс/мс^2 гравитационная постоянная

#endif // MY_CONFIG_H