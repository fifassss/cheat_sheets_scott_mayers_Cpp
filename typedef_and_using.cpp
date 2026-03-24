    // пример для typedef и using

    using func = int(*)(int, int); // указатель на функцию которая возращает int и принимает 2 int 

    typedef int(*func)(int, int); // 

    int plus(int a, int b)
    {
        return a + b;
    }
    int mult(int a, int b)
    {
        return a * b;
    }
    
    
    void process(int a, int b, func f)
    {
        auto result = f(a, b);
    }


    // typedef и using

    // using умеет работать хорошо с шаблонами.А typedef - нет. При использовании using нам не требуется думать о проблеме зависимых типов ставить typename или структуру делать..

    process(5,6, mult);

   
    // using = typedef они взаимнозаменямы
    typedef int newintname;
    using newintname = int;
