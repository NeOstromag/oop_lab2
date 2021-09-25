//
// Created by lena on 18.09.2021.
//

#include "hypocycloid.h"


namespace Prog2{

    //конструктор
    hypo::hypo(Point start_point, double Rad, double rad,  double dl)
    {
        start = start_point;
        if (rad < 0 || Rad < 0  || dl < 0)
            throw std::runtime_error("invalid radius");
        r = rad;
        R = Rad;
        D = dl ;
    }


    // сеттеры
    hypo& hypo::set_r(double r0)
    {
        if (r0 < 0)
            throw std::runtime_error("invalid radius");
        r = r0;
        return *this;
    }
    hypo& hypo::set_R(double R0)
    {
        if (R0 < 0)
            throw std::runtime_error("invalid radius");
        R = R0;
        return *this;
    }
    hypo& hypo::set_D(double d0)
    {
        if (d0 < 0)
            throw std::runtime_error("invalid radius");
        D = d0;
        return *this;
    }


    //другие методы

    Point hypo::coord(double fi) const {
        double k = (R/r);
        double x,y;
        x = start.x + r * (k-1) * (cos(fi) + (cos(k-1) * fi) / (k-1));
        y = start.y + r * (k-1) * (sin(fi) + (sin(k-1) * fi) / (k-1));
        return Point(x,y);

    }                // 3 пункт

    double hypo::radius_of_curvature(double fi) const {
        double k = (R/r);
        double  Rk;

        Rk = (4*R*(k-1))/(k*k*(k-2)) * sin(fi/2);
        return Rk;
    } // 5 пункт

    int hypo::type() const {
        if( D == r){
            //обыкновенная
            return 1;
        }

        else if(D < r){
            //укороченная
            return 2;
        }

        else {
            //удлиненная";
            return 3;
        }

    }                            // 6 пункт

    double hypo::sec_square(double fi) const {
        double S;

        S = std::abs(((R+r)*(R+2*r)/2) * (fi - r/R * sin(R/r * fi)));

        return S;
    }          // 7 пункт
}


//вспомгательные функции

int menu()
{
    using namespace std;
    int a = 0;
    cout << "Выберите действие:"<<endl;
    cout << "1.Вернуть координаты точки"<<endl;
    cout << "2.Вернуть радиусы окружностей"<<endl;
    cout << "3.Вернуть радиус кривизны от угла поворота луча"<<endl;
    cout << "4.Вернуть тип гипоциклоиды"<<endl;
    cout << "5.Вернуть секториальную площадь гипоциклоиды "<<endl;
    cout << "6.Выход"<<endl;
    cin >> a;

    while (a < 1 || a > 6) {
        cout << "Введите 1-5!"<<endl;
        cin >> a;
    };
    return a;
}
double get_double() {
    using namespace std;
    double a;
    do {
        cin >> a;
        if (!(cin.good())) {
            cout << " [ERROR] Некорректное значение, повторите попытку:" << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << " > ";
        }
        else if(cin.eof()){
            cout << "Конец файла" ;
            std::exit(EXIT_SUCCESS);
        }
        else {
            break;
        }
    } while (true);
    return a;
}

double chat_R(){
    double R;
    using namespace std;
    cout << " > Введите радиус большой окружности:"<<endl;

    cout << " > ";
    R = get_double();

    return R;
}
double chat_r(){
    double r;
    using namespace std;
    cout << " > Введите радиус маленькой окружности:"<<endl;

    cout << " > ";
    r = get_double();

    return r;
}
double chat_d(){
    double d;
    using namespace std;
    cout << " > Введите длину от маленькой окр до гипоциклоиды:"<<endl;

        cout << " > ";
        d = get_double();

    return d;
}
double chat_x(){
    double x;
    using namespace std;
    cout << " > Введите координату по X:"<<endl;
    cout << " > ";
    x = get_double();
    return x;
}
double chat_y(){
    double y;
    using namespace std;
    cout << " > Введите координату по Y:"<<endl;
    cout << " > ";
    y = get_double();
    return y;
}
double chat_fi(){
    double fi;
    using namespace std;
    cout << " > Введите угол:"<<endl;

        cout << " > ";
        fi = get_double();

    return fi;
}
