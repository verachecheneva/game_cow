#ifndef COW_H
#define COW_H

#include <SFML/Graphics.hpp>
#include <stdexcept>

#include "my_config.h"

class Cow {
public:
  Cow();
  ~Cow() = default;

  void update(); ///< обновить состояние программы
  
  /**
  * отрисовка коровы
  * @param sf::RenderWindow окно для отрисоввки
  */
  void draw(sf::RenderWindow &) const; 
  
  /**
  * установка позиции спрайта
  * @param координаты X и Y спрайта  
  */
  void set_position(const float &, const float &);

  /**
  * получить положение спрайта коровы 
  * @return вектор из 2 координат спрайта (X,Y)
  */
  sf::Vector2f get_position();

  /**
  * обработчик события "нажатие"
  * @param sf::Event системное событие
  */
  void key_pressed_handler(sf::Event &); 

  /**
  * обработчик события "отжатие"
  * @param sf::Event системное событие
  */
  void key_released_handler(sf::Event &); // обработчик события "отжатие"

private:
  enum state { standing, moving }; ///< состояние коровы (стоит или двигается)
  enum direction { left, right }; ///< направление коровы (смотрит влево или вправо)

  state m_sprite_state;  ///< состояние анимации спрайта
  direction m_direction; ///< направление коровы
  sf::Texture m_texture; ///< текстура
  sf::IntRect m_rect;    ///< прямоугольник спрайта
  sf::Clock m_sprite_clock; ///< счетчик времени для анимации спрайта
  sf::Clock m_movement_clock; ///< счетчик времени движения коровы
  sf::Sprite m_sprite; ///< спрайт

  float m_x_velocity; ///< скорость коровы по X-координате
  float m_y_velocity; ///< скорость коровы по Y-координате

  void set_next_frame(); ///< Анимация. Установка следующего кадра
  void set_static_frame(); ///< установка статического кадра

  /**
  * устанавливает направление коровы
  * @param direction направлние коровы 
  */
  void set_direction(direction); 

  /**
  * устанавливает состояние анимации спрайта
  * @param state состояние коровы (стоит или двигается)
  */
  void set_sprite_state(state); 
  void update_position(); ///< обновление позиции коровы
  void update_sprite(); ///< проверка на обновления анимации
  void jump_action_handler(); ///< Обработка запроса прыжка
};

#endif // COW_H