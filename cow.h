#ifndef COW_H
#define COW_H

#include <SFML/Graphics.hpp>
#include <stdexcept>

#include "my_config.h"

class Cow  {
 public:
  Cow();
  ~Cow() = default;

  void update(sf::RenderWindow&);
  void draw(sf::RenderWindow&) const ;
  void set_position(const float&, const float&);
  void key_pressed_handler(sf::Event&);
  void key_released_handler(sf::Event&);

 private:
  enum state {
    standing,
    moving
  };
  enum direction {
    left,
    right
  };

  state       m_sprite_state;
  direction   m_direction;
  sf::Texture m_texture;
  sf::IntRect m_rect;
  sf::Clock   m_sprite_clock;
  sf::Clock   m_movement_clock;
  sf::Sprite  m_sprite;

  float m_x_velocity;
  float m_y_velocity;

  void _set_next_frame();
  void _set_static_frame();
  void _set_direction(direction);
  void _set_sprite_state(state);
  void _update_position(sf::RenderWindow&);
  void _update_sprite();
  void _jump_action_handler();
};

#endif // COW_H