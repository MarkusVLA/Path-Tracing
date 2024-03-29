#ifndef PATHTRACER_MATERIALBUILDER_HPP
#define PATHTRACER_MATERIALBUILDER_HPP

#include <SFML/Graphics.hpp>
#include "vector.hpp"
#include "material.hpp"

/**
 * Builder design pattern used for keeping Material class encapsulated and immutable
 */

// A tiny bit unnecessary (simple setters would've been enough)
class MaterialBuilder {
public:

    /**
     * Constructor with default values
     */
    MaterialBuilder() :
            color_(sf::Color(255,0,255)),
            roughness_(0.5),
            specularIntensity_(0.5),
            specularColor_(sf::Color(255,255,255)),
            emission_(Vector()),
            n_(1),
            name_("default") {}

    ~MaterialBuilder() = default;

    [[nodiscard]] inline Material BuildMaterial() const {
        return Material(color_, roughness_, specularIntensity_,
                        specularColor_, emission_, n_, name_);
    }

    inline void SetColor(sf::Color color) { color_ = color; }
    inline void SetRoughness(double roughness) { roughness_ = roughness; }
    inline void SetSpecularIntensity(double specularIntensity) { specularIntensity_ = specularIntensity; }
    inline void SetSpecularColor(sf::Color specularColor) { specularColor_ = specularColor; }
    inline void SetEmission(const Vector &emission) { emission_ = emission; }
    inline void SetN(double n) { n_ = n; }
    inline void SetName(const std::string& name) { name_ = name; }

private:
    sf::Color color_;
    double roughness_;
    double specularIntensity_;
    sf::Color specularColor_;
    Vector emission_;
    double n_;
    std::string name_;
};


#endif //PATHTRACER_MATERIALBUILDER_HPP
