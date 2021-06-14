#include "cow.h"
#include "my_config.h"
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <stdexcept>

int main() {
  sf::RenderWindow window;
  window.create(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "dancing polish cow", sf::Style::Close);
  window.setPosition(sf::Vector2i(200, 200));
  window.setKeyRepeatEnabled(true); //когда кнопку зажимаем много раз воспринимается нажатие


  // музыка
  sf::Music music;
  if (!music.openFromFile(BACKGROUND_MUSIC_PATH))
    throw std::runtime_error("err: cant load music");
  music.setLoop(true);
  music.setVolume(50);
  music.play();

  // ставим фон 
  sf::Sprite background_sprite;
  sf::Texture background_texture_0;
  if (!background_texture_0.loadFromFile(BACKGROUND_IMG_PATH_0))
    throw std::runtime_error("err: cant load background texture");

  sf::Texture background_texture_1;
  if (!background_texture_1.loadFromFile(BACKGROUND_IMG_PATH_1))
    throw std::runtime_error("err: cant load background texture");

  sf::Texture background_texture_2;
  if (!background_texture_2.loadFromFile(BACKGROUND_IMG_PATH_2))
    throw std::runtime_error("err: cant load background texture");

  int current_background_number = 0;
  background_sprite.setTexture(background_texture_0);


Cow cow;
cow.set_position(WINDOW_WIDTH / 2, WINDOW_HEIGHT / 3 * 2);
  // основный цикл 
  sf::Event event;

  while (window.isOpen()) {
    while (window.pollEvent(event)) {
      switch (event.type) {
      // если окно закрывается
      case sf::Event::Closed:
        window.close();
        break;
      case sf::Event::KeyPressed:
        cow.key_pressed_handler(event);
        if (event.key.code == BACKGROUND_CHANGE_BUTTON) {

          if (current_background_number == 0) {
            current_background_number = 1;
            background_sprite.setTexture(background_texture_1);
          } else if (current_background_number == 1) {
            current_background_number = 2;
            background_sprite.setTexture(background_texture_2);
          } else if (current_background_number == 2) {
            current_background_number = 0;
            background_sprite.setTexture(background_texture_0);
          }
        }
        break;

      // key released
      case sf::Event::KeyReleased:
        cow.key_released_handler(event);
        break;
      }
    }

    window.clear();

    cow.update(window);

    window.draw(background_sprite);

    cow.draw(window);

    window.display();
  }

  return 0;
}