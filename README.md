# Dream_Princesses

## Установка MinilibX и запуск проекта

Это руководство предоставляет инструкции по установке MinilibX и запуску проекта.

### Требования

- Операционная система: Linux (рекомендуется Ubuntu)
- Установленный компилятор GCC
- Установленная графическая библиотека X11

#### Установка MinilibX
```
git clone https://github.com/42Paris/minilibx-linux.git
cd minilibx-linux
make
```

Убедись, что библиотека libmlx.a была успешно скомпилирована.

#### Запуск проекта

```
git clone https://github.com/dertovich/Dream_Princesses.git
cd Dream_Princesses
make
./dream_princesses maps/simple2.ber
```

#### Тест проекта
```
cd tests
make
```
