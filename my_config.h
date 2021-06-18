#ifndef MY_CONFIG_H
#define MY_CONFIG_H

inline const std::string BACKGROUND_MUSIC_PATH = "res/Cypis-Polish_cow_dancing.wav"; ///< относительный путь до музыки
inline const std::string BACKGROUND_IMG_PATH_0 = "res/background_0.jpg"; ///< относительный путь до картинки фона 0
inline const std::string BACKGROUND_IMG_PATH_1 = "res/background_1.jpg"; ///< относительный путь до картинки фона 1
inline const std::string BACKGROUND_IMG_PATH_2 = "res/background_2.jpg"; ///< относительный путь до картинки фона 2
inline const int WINDOW_HEIGHT = 600; ///< высота окна
inline const int WINDOW_WIDTH = 900;  ///< ширина окна


inline const std::string COW_SPRITE_PATH = "res/cow_sprite_sheet.png";  ///< относительный путь до картинки спрайта коровы
inline const int COW_SPRITE_HEIGHT = 179; ///< высота кадра спрайта
inline const int COW_SPRITE_HEIGHT_INDENT = COW_SPRITE_HEIGHT / 2; ///< вертикальное смещение цента спрайта
inline const int COW_SPRITE_WIDTH = 215; ///< ширина кадра спрайта
inline const int COW_SPRITE_WIDTH_INDENT = COW_SPRITE_WIDTH / 2; ///< горизонтальное смещение цента спрайта
inline const int COW_SPRITE_SIZE = 20; ///< количество кадров у спрайта
inline const int COW_SPRITE_START_NUM = 1; ///< начальный кадр   (0 <= COW_SPRITE_START_NUM < COW_SPRITE_SIZE)

inline const bool COW_RESET_SPRITE_ON_STOP = false; ///< устанавливать ли начальный кадр спрайта при остановке коровы
inline const int COW_SPRITE_SPEED_MS = 100; ///< скорость смены кадров спрайта коровы (кол-во мс показа одного кадра)

inline const float COW_LEFT_WINDOW_BORDER = static_cast<float>(COW_SPRITE_WIDTH_INDENT); ///< координата левой стенки для коровы
inline const float COW_RIGHT_WINDOW_BORDER = static_cast<float>(WINDOW_WIDTH) - COW_SPRITE_WIDTH_INDENT; ///< координата правой стенки для коровы

inline const float COW_JUMP_VELOCITY = 1.5f; ///< пикс/мс начальная скорость прыжка
inline const float COW_HORIZONTAL_VELOCITY = 0.4f; ///< пикс/мс скорость ходьбы 

inline const auto COW_MOVE_LEFT_BUTTON = sf::Keyboard::Left; ///< кнопка влево
inline const auto COW_MOVE_RIGHT_BUTTON = sf::Keyboard::Right; ///< кнопка вправо 
inline const auto COW_JUMP_BUTTON = sf::Keyboard::Space; ///< кнопка прыжка
inline const auto BACKGROUND_CHANGE_BUTTON = sf::Keyboard::Enter; ///< кнопка смены фона

inline const float COW_FLOOR = 400.0f; ///< координата пола для коровы

inline const float GLOBAL_GRAVITY = 0.005f; ///< пикс/мс^2 гравитационная постоянная

#endif // MY_CONFIG_H