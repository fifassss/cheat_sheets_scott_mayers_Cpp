// всегда использовать auto? начало.(вспомогательное) 

// ситуация когда auto может заменить длинное название типа.

template<class T>
void f(T b, T e)
{
    while (b != e)
    {
       auto value = *b; // typename std::iterator_traits<T>::value_type 

        ++b;
    }
}

// всегда использовать auto? конец.(вспомогательное)

    
    // всегда использовать auto? начало.

    int x; // тут лежит мусор - UB.Хотя код по сути верный и без инициализации.
    auto b = 5; // тут ЯВНО нужно инициализировать иначе ошибка.


    // хранение замыканий
    std::function<bool(int,int)> isleess = [](int a, int b) -> bool
    {
            return a < b;
    }

    std::vector<int> v; // какие тут проблемы?
    unsigned sz = v.size(); // size возращает size_t.Проблема в том.Что unsigned и size_t в 32 битной разрядной системе имеет один и тот же размер.Но в 64 разрядной системе unsigned = 32 бит.А size_t = 64 бит.Поэтому тут нужно писать AUTO.

    std::unordered_map<std::string, int> map;
    for (const auto& m : map) // без const std::string - мы бы делали копирование.То есть ключ возращается константным!.Можно оставить так : const std::pair<const std::string, int>& m .Но лучше с auto :)s
    {

    }

    // всегда использовать auto? конец.
