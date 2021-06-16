#include "cow.h"
#include <iostream>
Cow::Cow()
  : m_rect(0, 0, COW_SPRITE_WIDTH,  COW_SPRITE_HEIGHT) ,
    m_y_velocity(0.0f),
    m_x_velocity(0.0f) {

  if (!m_texture.loadFromFile(COW_SPRITE_PATH))
    throw std::runtime_error("err: cant load cow texture");

  m_sprite.setTexture(m_texture);
  _set_static_frame();
  // set center point as relative point
  m_sprite.setOrigin(COW_SPRITE_WIDTH_INDENT, COW_SPRITE_HEIGHT / 2);

  m_sprite_clock.restart();
  m_movement_clock.restart();

  _set_sprite_state(standing);
  _set_direction(right);
}

void Cow::key_pressed_handler(sf::Event& event) {
  switch (event.key.code) {
  case COW_MOVE_LEFT_BUTTON:
    m_x_velocity = -COW_HORIZONTAL_VELOCITY;
    _set_sprite_state(moving);
    _set_direction(left);
    break;
  case COW_MOVE_RIGHT_BUTTON:
    m_x_velocity = COW_HORIZONTAL_VELOCITY;
    _set_sprite_state(moving);
    _set_direction(right);
    break;
  case COW_JUMP_BUTTON:
    _jump_action_handler();
    break;
  }
}

void Cow::key_released_handler(sf::Event& event) {
  switch (event.key.code) {
  case COW_MOVE_LEFT_BUTTON:
    m_x_velocity = 0.0f;
    _set_sprite_state(standing);
    if (COW_RESET_SPRITE_ON_STOP)
      _set_static_frame();
    break;
  case COW_MOVE_RIGHT_BUTTON:
    m_x_velocity = 0.0f;
    _set_sprite_state(standing);
    if (COW_RESET_SPRITE_ON_STOP)
      _set_static_frame();
    break;
  }
}

void Cow::update(sf::RenderWindow& window) {
  _update_position(window);
  _update_sprite();
}

void Cow::draw(sf::RenderWindow &window) const {
  window.draw(m_sprite);
}

void Cow::set_position(const float& x, const float& y) {
  m_sprite.setPosition(x, y);
}

sf::Vector2f Cow::get_position(){
  return m_sprite.getPosition();
}

void Cow::_set_next_frame() {
  m_rect.left = m_rect.left + COW_SPRITE_WIDTH;
  m_rect.left %= COW_SPRITE_WIDTH * COW_SPRITE_SIZE;
  m_sprite.setTextureRect(m_rect);
}

void Cow::_set_static_frame() {
  m_rect.left = COW_SPRITE_START_NUM * COW_SPRITE_WIDTH;
  m_sprite.setTextureRect(m_rect);
}

void Cow::_set_direction(direction dir) {
  if (dir != m_direction) {
    m_direction = dir;
    if (dir == left)
      m_sprite.setScale(-1.0f, 1.0f);
    else
      m_sprite.setScale(1.0f, 1.0f);
  }
}

void Cow::_set_sprite_state(state stt) {
  if (stt != m_sprite_state) {
    m_sprite_state = stt;
  }
}


void Cow::_update_position(sf::RenderWindow& window) {
  auto elapsed_time = m_movement_clock.getElapsedTime().asMilliseconds();
  if (elapsed_time >= 1) {
    m_movement_clock.restart();
    float cur_x = get_position().x;
    float cur_y = get_position().y;
    
    // update horisontal position
    // x = x0 + v*t
    cur_x += m_x_velocity * elapsed_time;

    // left border collision check
    if (cur_x < COW_LEFT_WINDOW_BORDER) {
      cur_x = COW_LEFT_WINDOW_BORDER;
    }
    // right border collision check
    if (cur_x > COW_RIGHT_WINDOW_BORDER) {
      cur_x = COW_RIGHT_WINDOW_BORDER;
    }

    // update vertical position
    // y = y0 + v0*t - (g*t^2) / 2
    cur_y -= m_y_velocity * elapsed_time - GLOBAL_GRAVITY * elapsed_time * elapsed_time / 2;
    // v = v0 - g*t
    m_y_velocity -= GLOBAL_GRAVITY * elapsed_time;

    // reached the floor
    if (cur_y > COW_FLOOR) {
      m_y_velocity = 0.0f;
      cur_y = COW_FLOOR;
    }

    set_position(cur_x, cur_y);
  }
}

void Cow::_update_sprite() {
  if (m_sprite_state == moving)
    if (m_sprite_clock.getElapsedTime().asMilliseconds() > COW_SPRITE_SPEED_MS) {
      _set_next_frame();
      m_sprite_clock.restart();
    }
}

void Cow::_jump_action_handler() {
  // check if cow is standing on the floor
  if (m_sprite.getPosition().y > COW_FLOOR - 0.001f)
    m_y_velocity = COW_JUMP_VELOCITY;
}
