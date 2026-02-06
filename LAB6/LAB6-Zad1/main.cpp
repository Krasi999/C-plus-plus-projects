#include <iostream>     // За вход/изход
using std::cout;
using std::endl;

class CBox
{
public:
    // Конструктор с параметри и стойности по подразбиране
    // Гарантира, че дължината винаги е >= ширината
    CBox(double lv = 1.0, double wv = 1.0, double hv = 1.0)
        : m_Height(hv)
    {
        m_Length = lv > wv ? lv : wv;   // Дължина = по-голямата стойност
        m_Width  = wv < lv ? wv : lv;   // Ширина  = по-малката стойност
    }

    // Метод за изчисляване на обема на кутията
    double Volume() const
    {
        return m_Length * m_Width * m_Height;
    }

    // Оператор > между две кутии – сравнява обемите
    int operator>(const CBox& aBox) const
    {
        return Volume() > aBox.Volume();
    }

    // Оператор > между кутия и число
    int operator>(const double& value) const
    {
        return Volume() > value;
    }

    // Оператор < сравнява обеми
    int operator<(const CBox& aBox) const
    {
        return Volume() < aBox.Volume();
    }

    // Оператор == сравнява обеми
    int operator==(const CBox& aBox) const
    {
        return Volume() == aBox.Volume();
    }

    // Оператор + създава нова кутия:
    // дължина = по-голямата от двете
    // ширина  = по-голямата от двете
    // височина = сбор от височините
    CBox operator+(const CBox& aBox) const
    {
        return CBox(
            m_Length > aBox.m_Length ? m_Length : aBox.m_Length,
            m_Width  > aBox.m_Width  ? m_Width  : aBox.m_Width,
            m_Height + aBox.m_Height
        );
    }

    // Оператор - изважда височините
    // Ако новата височина стане отрицателна -> 0
    CBox operator-(const CBox& aBox) const
    {
        double newHeight = m_Height - aBox.m_Height;
        if (newHeight < 0.0) newHeight = 0.0;

        return CBox(
            m_Length > aBox.m_Length ? m_Length : aBox.m_Length,
            m_Width  > aBox.m_Width  ? m_Width  : aBox.m_Width,
            newHeight
        );
    }

    // Показване на размерите на кутията
    void ShowBox() const
    {
        cout << m_Length << " "
             << m_Width  << " "
             << m_Height << endl;
    }

private:
    double m_Length;   // дължина
    double m_Width;    // ширина
    double m_Height;   // височина
};

// Оператор > между число и CBox
int operator>(const double& value, const CBox& aBox)
{
    return value > aBox.Volume();
}

int main()
{
    CBox smallBox(4.0, 2.0, 1.0);
    CBox mediumBox(10.0, 4.0, 2.0);

    CBox aBox, bBox, cBox;

    // Тест на оператор +
    aBox = smallBox + mediumBox;
    cout << "aBox = smallBox + mediumBox: ";
    aBox.ShowBox();

    // Тест на оператор -
    cBox = mediumBox - smallBox;
    cout << "cBox = mediumBox - smallBox: ";
    cBox.ShowBox();

    // Тест на оператор <
    if (smallBox < mediumBox)
        cout << "smallBox < mediumBox: TRUE" << endl;
    else
        cout << "smallBox < mediumBox: FALSE" << endl;

    // Тест на оператор ==
    CBox box1(4.0, 2.0, 1.0);
    CBox box2(2.0, 2.0, 4.0);

    if (box1 == box2)
        cout << "box1 == box2 (same volume): TRUE" << endl;
    else
        cout << "box1 == box2: FALSE" << endl;

    return 0;
}
