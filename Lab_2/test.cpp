//
// Created by lena on 23.09.2021.
//
#include "../hypocycloid.h"
#include "gtest/gtest.h"




TEST(Hypo_Constructor, InitConstructors)
{
    Prog2::Point p(2, 3);
    Prog2::hypo a(p, 6, 3 , 8);
    ASSERT_EQ(6, a.get_R());
    ASSERT_EQ(3, a.get_r());
    ASSERT_EQ(8, a.get_D());
}

TEST(Hypo_Methods, coord)
{
    double error = 0.001;
    Prog2::Point p(2, 3);
    Prog2::hypo b(p, 6, 3 , 8);
    const double PI = 3.14159, err = 0.00001;

    ASSERT_NEAR(b.coord(34).x, 54.5651, error);
    ASSERT_NEAR(b.coord(34).y, 90.4173, error);

}

TEST(Hypo_Methods, radius_of_curvature)
{
    double error = 0.001;
    Prog2::Point p(4, 5);
    Prog2::hypo b(p, 2, 3 , 4);
    const double PI = 3.14159, err = 0.00001;

    ASSERT_NEAR(b.radius_of_curvature(4), 4.09184, error);

}

TEST(Hypo_Methods, sec_square)
{
    double error = 0.001;
    Prog2::Point p(4, 5);
    Prog2::hypo b(p, 6, 7 , 7);
    const double PI = 3.14159, err = 0.00001;

    ASSERT_NEAR(b.sec_square(89), 11452.3840, error);
}


































































