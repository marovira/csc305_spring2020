#include <atlas/math/Math.hpp>

#include <fmt/printf.h>
#include <stb_image.h>
#include <stb_image_write.h>

#include <vector>

struct Ray
{
    atlas::math::Point o;
    atlas::math::Vector d;

    atlas::math::Point eval(float t)
    {
        return o + t * d;
    }
};

struct Sphere
{
    atlas::math::Point centre;
    float radius;
};

using Colour = atlas::math::Vector;

Colour intersectRayWithSphere(Sphere s, Ray r);
void saveToFile(std::string const& filename,
                std::size_t width,
                std::size_t height,
                std::vector<Colour> const& image);

int main()
{
    const std::size_t imageWidth{600};
    const std::size_t imageHeight{600};

    Ray ray;
    ray.d = {0, 0, -1};
    Sphere s;
    s.centre = {0, 0, 0};
    s.radius = 120.0f;

    std::vector<Colour> image(imageWidth * imageHeight);

    for (std::size_t y{0}; y < imageHeight; ++y)
    {
        for (std::size_t x{0}; x < imageWidth; ++x)
        {
            // Compute origin of ray.
            float originX = (x - 0.5f * (imageWidth - 1.0f));
            float originY = (y - 0.5f * (imageHeight - 1.0f));

            ray.o = {originX, originY, 100.0f};

            Colour pixel = intersectRayWithSphere(s, ray);

            image[x + y * imageHeight] = pixel;
        }
    }

    saveToFile("sphere.bmp", imageWidth, imageHeight, image);
    return 0;
}

Colour intersectRayWithSphere(Sphere s, Ray r)
{
    using atlas::math::Point;
    using atlas::math::Vector;

    Vector temp = r.o - s.centre;
    float a     = glm::dot(r.d, r.d);
    float b     = 2.0f * glm::dot(temp, r.d);
    float c     = glm::dot(temp, temp) - (s.radius * s.radius);
    float disc  = b * b - 4.0f * a * c;

    if (disc < 0.0f)
    {
        return {0, 0, 0};
    }

    return {1, 0, 0};
}

void saveToFile(std::string const& filename,
                std::size_t width,
                std::size_t height,
                std::vector<Colour> const& image)
{
    std::vector<unsigned char> data(image.size() * 3);

    for (std::size_t i{0}, k{0}; i < image.size(); ++i, k += 3)
    {
        Colour pixel = image[i];
        data[k + 0]  = static_cast<unsigned char>(pixel.r * 255);
        data[k + 1]  = static_cast<unsigned char>(pixel.g * 255);
        data[k + 2]  = static_cast<unsigned char>(pixel.b * 255);
    }

    stbi_write_bmp(filename.c_str(),
                   static_cast<int>(width),
                   static_cast<int>(height),
                   3,
                   data.data());
}
