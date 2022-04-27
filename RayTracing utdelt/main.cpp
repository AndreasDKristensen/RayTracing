#include "std_lib_facilities.h"
#include "color.h"
#include "vec3.h"
#include "ray.h"
#include "utilities.h"
#include "hittable_list.h"
#include "sphere.h"
#include "camera.h"

/*
double hit_sphere(const point3& center, double radius, const ray& r){
    vec3 oc = r.origin() - center;
    auto a = r.direction().length_squared();
    auto half_b = dot(oc, r.direction());
    auto c = oc.length_squared() - radius*radius;
    auto discriminant = half_b*half_b - a*c;

    if (discriminant < 0){
        return -1.0;
    } else{
        return (-half_b - std::sqrt(discriminant) / (a));
    }
}
*/

/*
color ray_color(const ray& r, const hittable& seen, int depth) {
    //hit_record rec;

  
    if (depth <= 0)
        return color(0,0,0);
    
    if (seen.hit(r, 0, infinity, rec)) {
        point3 target = rec.p + rec.normal + random_in_unit_sphere();
        return 0.5 * ray_color(ray(rec.p, target - rec.p), seen, depth-1);
    }
    vec3 unit_direction = unit_vector(r.direction());
    auto t = 0.5*(unit_direction.y() + 1.0);
    return (1.0-t)*color(1.0, 1.0, 1.0) + t*color(0.5, 0.7, 1.0);
}*/


color ray_color(const ray& r) {
    vec3 unit_direction = unit_vector(r.direction());
    auto t = 0.5*(unit_direction.y());// + 1.0);
    return (1.0-t)*color(1.0, 1.0, 1.0) + t*color(0.5, 0.7, 1.0);
}

int main(){
    // Image
   
    
    const auto aspect_ratio = 16.0/9.0;
    const int image_width = 400;
    const int image_height = static_cast<int>(image_width/aspect_ratio);
    const int samples_per_pixel = 50;
    const int max_depth = 50;

    //seen

    //hittable_list seen;
    

    //Camera
    camera cam;

    // Render
    std::cout << "P3\n" << image_width << ' ' << image_height << "\n255\n";
     for (int j = image_height-1; j >= 0; --j) {
        std::cerr << "\rScanlines remaining: " << j << ' ' << std::flush;
        for (int i = 0; i < image_width; ++i) {
            color pixel_color;//(i, j, 0.25);

            auto u = double(i) / (image_width-1);
            auto v = double(j) / (image_height-1);
            ray r = cam.get_ray(u, v);
            pixel_color = ray_color(r); 

            //cout << pixel_color << endl;
            write_color(std::cout, pixel_color, samples_per_pixel);
        }
    }
    std::cerr << "\nDone.\n";
}
