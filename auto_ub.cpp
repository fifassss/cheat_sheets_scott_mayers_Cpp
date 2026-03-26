// AUTO и неопределенное поведение начало(вспомогательное)

class sensor
{
public:
    bool HighTemperatureDetected = true;
    bool smokeDetected = true;
};

std::vector<bool> features(const sensor& s)
{
    return std::vector<bool> {s.HighTemperatureDetected,s.smokeDetected};
}

// AUTO и неопределенное поведение конец(вспомогательное)

    // AUTO и неопределенное поведение начало
    
    //sensor sen;

    auto Issmokedetector = features(sen)[1]; // обращение к bit_refence.Прокси классу.А не к bool.Auto очень плохо с ними работает.Ну с прокси классами.
    auto Issmokedetector_two = static_cast<bool>(features(sen)[1]); // тут кастуем явно к bool. И получаем нормальный результат. auto name = static_cast<type>(выражение)
    //std::cout << Issmokedetector << '\n';
    //AUTO и неопределенное поведение конец
