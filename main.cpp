
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
  sf::Texture background_texture;
  if (!background_texture.loadFromFile(BACKGROUND_IMG_PATH))
    throw std::runtime_error("err: cant load background texture");
  background_sprite.setTexture(background_texture);

  // основный цикл 
  sf::Event event;

  while (window.isOpen()) {
    while (window.pollEvent(event)) {
      switch (event.type) {
      // если окно закрывается
      case sf::Event::Closed:
        window.close();
        break;
      }
    }

    window.clear();

    window.draw(background_sprite);

    window.display();
  }

  return 0;
}