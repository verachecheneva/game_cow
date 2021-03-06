#include "cow.h"
#include <iostream>
Cow::Cow()
    : m_rect(0, 0, COW_SPRITE_WIDTH, COW_SPRITE_HEIGHT), m_y_velocity(0.0f),
      m_x_velocity(0.0f) {

  if (!m_texture.loadFromFile(COW_SPRITE_PATH))
    throw std::runtime_error("err: cant load cow texture");

  m_sprite.setTexture(m_texture);
  set_static_frame();
  m_sprite.setOrigin(COW_SPRITE_WIDTH_INDENT, COW_SPRITE_HEIGHT / 2);

  m_sprite_clock.restart();
  m_movement_clock.restart();

  set_sprite_state(standing);
  set_direction(right);
}

void Cow::key_pressed_handler(sf::Event &event) {
  switch (event.key.code) {
  case COW_MOVE_LEFT_BUTTON:
    m_x_velocity = -COW_HORIZONTAL_VELOCITY;
    set_sprite_state(moving);
    set_direction(left);
    break;
  case COW_MOVE_RIGHT_BUTTON:
    m_x_velocity = COW_HORIZONTAL_VELOCITY;
    set_sprite_state(moving);
    set_direction(right);
    break;
  case COW_JUMP_BUTTON:
    jump_action_handler();
    break;
  }
}

void Cow::key_released_handler(sf::Event &event) {
  switch (event.key.code) {
  case COW_MOVE_LEFT_BUTTON:
    m_x_velocity = 0.0f;
    set_sprite_state(standing);
    if (COW_RESET_SPRITE_ON_STOP)
      set_static_frame();
    break;
  case COW_MOVE_RIGHT_BUTTON:
    m_x_velocity = 0.0f;
    set_sprite_state(standing);
    if (COW_RESET_SPRITE_ON_STOP)
      set_static_frame();
    break;
  }
}

void Cow::update() {
  update_position();
  update_sprite();
}

void Cow::draw(sf::RenderWindow &window) const { window.draw(m_sprite); }

void Cow::set_position(const float &x, const float &y) {
  m_sprite.setPosition(x, y);
}

sf::Vector2f Cow::get_position() { return m_sprite.getPosition(); }

void Cow::set_next_frame() {
  m_rect.left = m_rect.left + COW_SPRITE_WIDTH;
  m_rect.left %= COW_SPRITE_WIDTH * COW_SPRITE_SIZE;
  m_sprite.setTextureRect(m_rect);
}

void Cow::set_static_frame() {
  m_rect.left = COW_SPRITE_START_NUM * COW_SPRITE_WIDTH;
  m_sprite.setTextureRect(m_rect);
}

void Cow::set_direction(direction dir) {
  if (dir != m_direction) {
    m_direction = dir;
    if (dir == left)
      m_sprite.setScale(-1.0f, 1.0f);
    else
      m_sprite.setScale(1.0f, 1.0f);
  }
}

void Cow::set_sprite_state(state stt) {
  if (stt != m_sprite_state) {
    m_sprite_state = stt;
  }
}

void Cow::update_position() {
  auto elapsed_time = m_movement_clock.getElapsedTime().asMilliseconds();
  if (elapsed_time >= 1) {
    m_movement_clock.restart();
    float cur_x = get_position().x;
    float cur_y = get_position().y;

    // ???????????????????? ???????????????????????????? ??????????????
    // x = x0 + v*t
    cur_x += m_x_velocity * elapsed_time;

    // ???????????????????????? ?? ?????????? ????????????????
    if (cur_x < COW_LEFT_WINDOW_BORDER) {
      cur_x = COW_LEFT_WINDOW_BORDER;
    }
    // ???????????????????????? ?? ???????????? ????????????????
    if (cur_x > COW_RIGHT_WINDOW_BORDER) {
      cur_x = COW_RIGHT_WINDOW_BORDER;
    }

    // ???????????????????? ???????????????????????? ??????????????
    // y = y0 + v0*t - (g*t^2) / 2
    cur_y -= m_y_velocity * elapsed_time -
             GLOBAL_GRAVITY * elapsed_time * elapsed_time / 2;
    // v = v0 - g*t
    m_y_velocity -= GLOBAL_GRAVITY * elapsed_time;

    // ???????????????? ????????
    if (cur_y > COW_FLOOR) {
      m_y_velocity = 0.0f;
      cur_y = COW_FLOOR;
    }

    set_position(cur_x, cur_y);
  }
}

void Cow::update_sprite() {
  if (m_sprite_state == moving)
    if (m_sprite_clock.getElapsedTime().asMilliseconds() >
        COW_SPRITE_SPEED_MS) {
      set_next_frame();
      m_sprite_clock.restart();
    }
}

void Cow::jump_action_handler() {
  // ????????????????, ?????????? ???? ???????????? ???? ????????
  if (m_sprite.getPosition().y > COW_FLOOR - 0.001f)
    m_y_velocity = COW_JUMP_VELOCITY;
}
