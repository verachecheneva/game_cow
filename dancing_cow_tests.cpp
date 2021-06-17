#include "cow.h"
#include "gtest/gtest.h"
#include <SFML/Graphics.hpp>

#include "my_config.h"

TEST(Cow, SetGetPosition) {
  Cow cow;
  cow.set_position(200, 10);
  EXPECT_EQ(cow.get_position().x, 200);
  EXPECT_EQ(cow.get_position().y, 10);
}

TEST(Cow, FallingTest) {
  Cow cow;

  cow.set_position(200, 0);
  sf::Clock clock;
  while (clock.getElapsedTime().asMilliseconds() < 10);
  cow.update();

  ASSERT_GT(cow.get_position().y, 0);
}

TEST(Cow, Moving) {
  Cow cow;

  float prev_x_pos = 200;
  cow.set_position(prev_x_pos, 0);

  sf::Clock clock;
  sf::Event custom_event;
  custom_event.key.code = COW_MOVE_LEFT_BUTTON;

  while (clock.getElapsedTime().asMilliseconds() < 10) {
    cow.key_pressed_handler(custom_event);
  };

  cow.update();
  ASSERT_LT(cow.get_position().x, prev_x_pos);

  cow.key_released_handler(custom_event);

  prev_x_pos = cow.get_position().x;
  custom_event.key.code = COW_MOVE_RIGHT_BUTTON;

  clock.restart();
  while (clock.getElapsedTime().asMilliseconds() < 10) {
    cow.key_pressed_handler(custom_event);
  };
  cow.update();
  ASSERT_GT(cow.get_position().x, prev_x_pos);
}

TEST(Cow, Jumping) {
  Cow cow;

  float prev_y_pos = COW_FLOOR;
  cow.set_position(0, COW_FLOOR);

  sf::Clock clock;
  sf::Event custom_event;
  custom_event.key.code = COW_JUMP_BUTTON;

  while (clock.getElapsedTime().asMilliseconds() < 10) {
    cow.key_pressed_handler(custom_event);
  };

  cow.update();
  ASSERT_LT(cow.get_position().y, prev_y_pos);
}
