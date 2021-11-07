#include <iostream>
#include <compare>
#include <regex>
#include <string>
#include <vector>
#include <stack>
#include <fstream>
#include "Massa.h"
#include "Radiation_frequency.h"
#include "Temperature.h"
#include "Wave_length.h"
#include "Energy.h"
#include "Base.h"
/* лассы физических величин: масса, энерги€, длина волны, частота излучени€,
температура, мощность излучени€.
ќпределить дл€ них операторы сложени€ (+) и вычитани€ (-) с учетом
физического смысла.
ƒл€ каждого класса определить литералы дл€ обозначени€ размерности:
масса Ц kg, энерги€ Ц J, длина волны Ц m, частота излучени€ Ц Hz,
температура Ц K, мощность излучени€ Ц W.
ƒл€ массы и энергии определить взаимнооднозначные операторы преобразовани€
по формуле E=mc2
, также определить операторы преобразовани€ энергии к
частоте, и частоты к длине волны
*/

using namespace std;
template <typename T>
std::shared_ptr<Base> create_factory(string arg)
{
    std::smatch res;
    std::regex reg("[1-9]\\d*(\\.){1}[1-9]\\d*");
    double c = 0;
    if (std::regex_search(arg, res, reg))
    {
        string s = res[0];
        c = stod(s);
        arg = std::regex_replace(arg.c_str(), std::regex("[1-9]\\d*(\\.){1}[1-9]\\d*"), "");
    }
    else
    {
        throw new exception("Ќекорректный аргумент передан в функцию");
    }
    if (arg == "kg") return make_shared<Massa>(c);
    else {
        if (arg == "m") return make_shared<Wave_length>(c);
        else {
            if (arg == "Hz") return make_shared<Radiation_frequency>(c);
            else {
                if (arg == "K") return make_shared<Temperature>(c);
                else {
                    if (arg == "J") return make_shared<Energy>(c);
                    else throw new exception("Ќет данного литерала");
                }
            }
        }
    }

}

int main()
{
    
     
    Massa n(4);

    cout << n;
}