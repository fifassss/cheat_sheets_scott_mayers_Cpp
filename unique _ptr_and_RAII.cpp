// std::unique_ptr и идиома RAII начало(вспомогательное)
enum class FigureType
{
    Circle, Square
};

class Figure
{
public:
    virtual ~Figure() = default;
    virtual double calcArea() const = 0;
};

class Circle : public Figure
{
private:
    double R;
public:
    Circle(double r) : R(r) {}
    double calcArea() const override
    {
        return 3.14 * R * R;
    }
};

class Square : public Figure
{
private:
    double A;
public:
    Square(double a) : A(a) {}
    double calcArea() const override
    {
        return A * A;
    }
};

// фабричная функция.(та функция которая создает объекты) без delete-ра

std::unique_ptr<Figure> makeFigure(FigureType type, double x)
{
    std::unique_ptr<Figure> pFigure(nullptr);
    if (type == FigureType::Circle)
    {
       pFigure.reset(new Circle(x));
    }
    else if (type == FigureType::Square)
    {
        pFigure.reset(new Square(x));
    }
    return pFigure;
}

// фабричная функция.(та функция которая создает объекты) с delete-ром
auto makeFigure(FigureType type, double x)
{
    auto deleter = [](Figure* f)
        {
            std::cout << "Figure delete!!!\n";
            delete f;
        };
    std::unique_ptr<Figure,decltype(deleter)> pFigure(nullptr,deleter);
    if (type == FigureType::Circle)
    {
        pFigure.reset(new Circle(x));
    }
    else if (type == FigureType::Square)
    {
        pFigure.reset(new Square(x));
    }
    return pFigure;
}

// тут заменяем сишный указатель(int* p = nullptr;) на умный указатель
class A
{
private:
    std::unique_ptr<int> p;
public:
    A(std::unique_ptr<int>& P) : p(std::move(P)) {}
    void show() { std::cout << *p << '\n'; }
};

// std::unique_ptr и идиома RAII конец(вспомогательное)

    std::unique_ptr<int> p1(new int(5));
    auto p2 = std::make_unique<int>(5); // c++ 14 вариант без new.new вызывается в make_unique.Иногда она(функция make_unique) даже безопаснее чем простое создание указателя.Например при передавании аргументов в функцию ведь не было до 17 стандарта четко определенных порядков операции.
    // но make_unique проблематично используется когда мы имеем дело с фигурной инициализацией,второе когда мы имеем дело с пользовательским delete-ром.

    auto circle = makeFigure(FigureType::Circle, 5);
    std::cout << "Circle area: " << circle->calcArea() << '\n';

    auto square = makeFigure(FigureType::Square, 4);
    std::cout << "Square area: " << square->calcArea() << '\n';
