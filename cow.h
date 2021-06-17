#ifndef COW_H
#define COW_H

#include <SFML/Graphics.hpp>
#include <stdexcept>

#include "my_config.h"

class Cow {
public:
  Cow();
  ~Cow() = default;

  void update();                       // обновить состояние
  void draw(sf::RenderWindow &) const; // отрисовка коровы
  void set_position(const float &, const float &); // позиция спрайта
  sf::Vector2f get_position(); // положение спрайта коровы
  void key_pressed_handler(sf::Event &); // обработчик события "нажатие"
  void key_released_handler(sf::Event &); // обработчик события "отжатие"

private:
  enum state { standing, moving };
  enum direction { left, right };

  state m_sprite_state;  // состояние анимации спрайта
  direction m_direction; // направление коровы
  sf::Texture m_texture; // текстура
  sf::IntRect m_rect;    // прямоугольник спрайта
  sf::Clock m_sprite_clock; // счетчик времени для анимации спрайта
  sf::Clock m_movement_clock; // счетчик времени движения коровы
  sf::Sprite m_sprite; // спрайт

  float m_x_velocity; // скорость коровы по X-координате
  float m_y_velocity; // скорость коровы по Y-координате

  void _set_next_frame(); // Анимация. Установка следующего кадра
  void _set_static_frame(); // установка статического кадра
  void _set_direction(direction); // устанавливает направление коровы
  void _set_sprite_state(state); // устанавливает состояние анимации спрайта
  void _update_position(); // обновление позиции коровы
  void _update_sprite(); // проверка на обновления анимации
  void _jump_action_handler(); // Обработка запроса прыжка
};

#endif // COW_H