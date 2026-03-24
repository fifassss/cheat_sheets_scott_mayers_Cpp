// Как пользоваться DECLTYPE начало(вспомогательное)

class A{};
auto sum(int a, int b) -> int
{
    return a + b;
}

template<typename Container,typename Index>
auto getElement(Container& c, Index i) -> decltype(c[i]) // без -> decltype(c[i]) теряется константность,ссылочность.Нельзя например возращаемому значению присовоить что-то.Без этой конструкции возращается rvalue
{
    return c[i];
}
// но также можно и по другому указывать.Например вот.(доп к комменту про : 'без -> decltype(c[i])...')


template<typename Container, typename Index>
decltype(auto) getElement(Container& c, Index i) // эта перегрузка работает также как и выше.(auto - определяет тип.decltype - сохраняет модификаторы - ссылки,константность,указатели и тд.)
{
    return c[i];
}

 //как проверить выводимый тип decltype.(вспомогательно.1 способ)
decltype(auto) f()
{
    int x = 0;
    return (x);
}


template<class T>
void f() = delete; // удаляем реализацию


// Как пользоваться DECLTYPE конец блока(вспомогательное)

// Как пользоваться DECLTYPE начало

    const int x = 20;

    decltype(x) y = x; // const int будет тип у 'y'.Или же равносильно тому,если бы человек написал const int y.

    A a;
    decltype(a) b; // тип у объекта b будет A

    std::vector<int> v = { 1,2,3,4 };
    decltype(v); // vector<int>

    v[0];
    decltype(v[0]); // int&

    std::vector<int> v = { 1,2,3 };
    getElement(v, 0) = 10;
    for (int i = 0; i < v.size(); i++)
    {
        std::cout << v.at(i) << '\n';
    }

    int x = 10;
    const int& rx = x;
    decltype(auto) rrx = rx; // тип const int&


    //Имена функций и перегруженных операторов (без вызова) также не дают ссылку, даже если функция возвращает lvalue-ссылку.

    //Имена членов данных, являющихся ссылками, сохраняют свой ссылочный тип(так как это объявленный тип).

    //Вывод: decltype для lvalue - выражений даёт ссылку на lvalue только тогда, когда выражение не является простым идентификатором без скобок.В остальных случаях — да.
     decltype(x) y = 10; // int a не int&
     decltype((x)) ys; // int&
    
    
    // как проверить выводимый тип decltype.

    int x = 10;
    decltype(f()) y = x; // int& 
    f<decltype(f())>();
    
    // Как пользоваться DECLTYPE конец блока
