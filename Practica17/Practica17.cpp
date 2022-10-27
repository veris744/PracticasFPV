#include <iostream>

#define EXPAND(x) x
#define GET_MACRO(_1, _2, _3, _4, _5, _6, _7, NAME) NAME
// Foreach macros FE
#define FE_1(_WHAT, X) _WHAT(X)
#define FE_2(_WHAT, X, ...) EXPAND(_WHAT(X)FE_1(_WHAT, __VA_ARGS__))
#define FE_3(_WHAT, X, ...) EXPAND(_WHAT(X)FE_2(_WHAT, __VA_ARGS__))
#define FE_4(_WHAT, X, ...) EXPAND(_WHAT(X)FE_3(_WHAT, __VA_ARGS__))
#define FE_5(_WHAT, X, ...) EXPAND(_WHAT(X)FE_4(_WHAT, __VA_ARGS__))
#define FE_6(_WHAT, X, ...) EXPAND(_WHAT(X)FE_5(_WHAT, __VA_ARGS__))
#define FE_7(_WHAT, X, ...) EXPAND(_WHAT(X)FE_6(_WHAT, __VA_ARGS__))
// La macro que itera cada uno los argumentos
#define MACRO_FOR_EACH_ARGUMENT(_ACTION, ...) \
EXPAND(GET_MACRO(__VA_ARGS__, FE_7, FE_6, FE_5, FE_4, FE_3, FE_2, FE_1)(_ACTION, __VA_ARGS__))

#define DECLARE_ENUM(_ENUM) _ENUM,
#define DECLARE_ENUM_TO_STR(_ENUM) case _ENUM: return #_ENUM;
#define DECLARE_STR_TO_ENUM(_ENUM) if (std::strcmp(_sEnum, #_ENUM) == 0) return _ENUM;
#define DECLARE_ENUM_CLASS(_NAME, ...) \
struct _NAME \
{ \
  enum Enum \
  { \
    MACRO_FOR_EACH_ARGUMENT(DECLARE_ENUM, __VA_ARGS__) \
    Invalid \
  }; \
  static const char* AsStr(Enum _eEnum) \
  { \
    switch (_eEnum) \
    { \
      MACRO_FOR_EACH_ARGUMENT(DECLARE_ENUM_TO_STR, __VA_ARGS__) \
    default: \
      break; \
    } \
    return "Invalid"; \
  } \
  static Enum AsEnum(const char* _sEnum) \
  { \
    MACRO_FOR_EACH_ARGUMENT(DECLARE_STR_TO_ENUM, __VA_ARGS__) \
    return Invalid; \
  } \
};

DECLARE_ENUM_CLASS(EColor, Rojo, Verde, Azul, Amarillo, Naranja, Morado)

int main()
{
#define PRINT(_A) printf("%s\n", #_A);
  MACRO_FOR_EACH_ARGUMENT(PRINT, A, B, C, D);

  printf("Test AsStr %s\n", EColor::AsStr(EColor::Rojo));
  printf("Test AsStr %s\n", EColor::AsStr(EColor::Azul));
  printf("Test AsStr %s\n", EColor::AsStr(EColor::Naranja));

  char sRojo[] = "Rojo";

  printf("Test AsEnum %d (%s)\n", EColor::AsEnum(sRojo), EColor::AsStr(EColor::AsEnum(sRojo)));
  printf("Test AsEnum %d (%s)\n", EColor::AsEnum("Azul"), EColor::AsStr(EColor::AsEnum("Azul")));
  printf("Test AsEnum %d (%s)\n", EColor::AsEnum("Naranja"), EColor::AsStr(EColor::AsEnum("Naranja")));


}