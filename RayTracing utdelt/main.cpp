#include "color.h"
#include "vec3.h"
#include "ray.h"
#include "utilities.h"
#include "hittable_list.h"
#include "sphere.h"
#include "camera.h"

#include <iostream>

/*
color ray_color(const ray& r, const hittable& scene, int depth) {
    //hit_record rec;

  
    if (depth <= 0)
        return color(0,0,0);
    
    if (scene.hit(r, 0, infinity, rec)) {
        point3 target = rec.p + rec.normal + random_in_unit_sphere();
        return 0.5 * ray_color(ray(rec.p, target - rec.p), scene, depth-1);
    }
    vec3 unit_direction = unit_vector(r.direction());
    auto t = 0.5*(unit_direction.y() + 1.0);
    return (1.0-t)*color(1.0, 1.0, 1.0) + t*color(0.5, 0.7, 1.0);
}*/

/*
color ray_color(const ray& r) {
    vec3 unit_direction = unit_vector(r.direction());
    auto t = 0.5*(unit_direction.y() + 1.0);
    return (1.0-t)*color(1.0, 1.0, 1.0) + t*color(0.5, 0.7, 1.0);
}*/

int main(){

    std::ofstream ofs{"image.ppm"};

    // Image
    
    const auto aspect_ratio = 16.0/9.0;
    const int image_width = 400;
    const int image_height = static_cast<int>(image_width/aspect_ratio);
    const int samples_per_pixel = 50;
    const int max_depth = 50;

    // Scene

    //hittable_list scene;
    

    //Camera
    camera cam;

    // Render
    ofs << "P3\n" << image_width << ' ' << image_height << "\n255\n";
     for (int j = image_height-1; j >= 0; --j) {
        std::cerr << "\rScanlines remaining: " << j << ' ' << std::flush;
        for (int i = 0; i < image_width; ++i) {

            auto r = double(i) / (image_width-1);
            auto g = double(j) / (image_height-1);
            auto b = 0.25;

            int ir = static_cast<int>(255.999 * r);
            int ig = static_cast<int>(255.999 * g);
            int ib = static_cast<int>(255.999 * b);

            ofs << ir << ' ' << ig << ' ' << ib << '\n';

        }
    }
    std::cerr << "\nDone.\n";
}
