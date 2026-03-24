// для Вывод типа auto
void func(int);
//
auto funcst() // тут как будто стоит шаблон!А не auto.То есть например для initializer_list<T> нужно явно указать его.Без явного указания - ничего работать не будет.
{
    return std::initializer_list<int>{1,2,3,4};
}

// для Вывод типа auto

// Вывод типа auto


auto x = 27 ; // auto -> int
const auto cx = x; // auto -> const int
const auto& rx = x; // auto -> const int&

auto&& uref1 = 27; // auto -> int&&
auto&& uref2 = x; // auto -> int&,потому что x - lvalue,компилятор мысленно подставляет одну ссылку к x и происходит столкновение ссылок
auto&& uref3 = rx; // auto -> const int& 

const char str[] = "abc";
auto auto_str = str; // const char*
auto& auto_str_ref = str; // const char(&)[4]
   
auto t = func; // void(*)(int)
auto& tref = func; // void(&)(int)

// различие вывода типа auto.От вывода типов шаблона.Единственное 


auto x1 = 10; // int
auto x2(10); // int
auto x3{ 10 }; // int
auto x4 = { 10 }; // std::initializer_list<int>

// auto указывания в лямба функциях и обычных функциях.Он работает как вывод типа для шаблона.А не как для auto
std::vector<int> vec;

auto resetV = [&vec](const auto& value)
{
    vec = value;
};


resetV({ 1,2,3 }); // не сработает.Работает как и для шаблонов.Так как std::initializer_list
// но если сделать так
auto value = { 1,2,3,4 };
resetV(value);
// все ок.

// Вывод типа auto
