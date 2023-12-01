#include "doctest.h"
#include "../src/world/Objects/objects.hpp"


// no radius getter
TEST_CASE("Testing getters") {
    object::Sphere sphere = object::Sphere(Vector(), 3);

    CHECK((sphere.getOrigin() == Vector(0, 0, 0)));
    CHECK((sphere.GetMaterial().getName() == "default"));
    CHECK((sphere.GetColor() == sf::Color::Magenta));
}

TEST_CASE("Testing normal") {
    object::Sphere sphere = object::Sphere(Vector(3, 1, 5), 3);

    CHECK((sphere.Normal(Vector(0, 1, 0)) == Vector(-0.51449575542752646,0,-0.8574929257125441)));
}

//todo ask how the functions work
TEST_CASE("Testing intersection") {
    object::Sphere sphere = object::Sphere(Vector(0, 0, 0), 3);

    Ray rayA = Ray(Vector(-5, 1, 4), Vector(-5, 1, 1).Norm());
    double dA = sphere.GetIntersectionDistance(rayA);
    Vector vA = sphere.GetIntersectionPoint(rayA);
//    CHECK((sphere.GetIntersectionDistance(rayA) == 0));
//    CHECK((sphere.GetIntersectionPoint(rayA) == rayA.GetOrigin()));

    Ray rayB = Ray(Vector(-5, 1, 4), Vector(3, 2, -2).Norm());
    double dB = sphere.GetIntersectionDistance(rayB);
    Vector vB = sphere.GetIntersectionPoint(rayB);
//    CHECK((sphere.GetIntersectionDistance(rayB) == -1));
//    CHECK((sphere.GetIntersectionPoint(rayB) == Vector(0,0,0)));
}