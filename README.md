# Dancing cow
## История появления Polish Cow

В 2015 году рэпер Cypis выпустил клип на свою композицию "Gdzie jest biały węgorz?". В 2020 году пользователи интернета начали активно создавать мемы, в которых под эту мелодию танцуют разные персонади. Самым героем стала Польская корова. На ютубе есть множество роликов с этим мемом. Вот видео, которое меня вдохновило.

[польская корова танцует в известных местах](https://www.youtube.com/watch?v=RDIFwM9ba4I)

## Как открыть проект

Требуется: [conan](https://conan.io/downloads.html), [cmake](https://cmake.org/download/), [MSVC 15+](https://visualstudio.microsoft.com/ru/downloads/)

## Установка для Windows 
[об установке conan + sfml](https://leinnan.github.io/blog/conan-adventuressfml-and-entt-in-c.html)

сконфигурировать conan: \
`conan remote add bincrafters https://api.bintray.com/conan/bincrafters/public-conan` \
`conan profile new default --detect` \
`conan profile update settings.cppstd=17 default` 

В папке проекта 

запустить установщик пакетов conan \
`conan install . -if build` 

запустить cmake \
`cmake -G "Visual Studio 16 2019" -B build -S .` \
`cmake --build build --config Release` \
`start ./build/bin/polska_cow.exe`

## Использованные ресурсы

[SFML документация](https://www.sfml-dev.org/documentation/2.5.1/classsf_1_1Sprite.php)
[ссылки в cpp](https://ravesli.com/urok-88-ssylki/)
[туториал по созданию игр](https://www.youtube.com/playlist?list=PLMgDVIa0Pg8WrI9WmZR09xAbfXyfkqKWy)
[GoogleTest + CMake](https://google.github.io/googletest/quickstart-cmake.html)






