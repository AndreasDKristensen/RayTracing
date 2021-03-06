//#define MATERIAL_H
#ifdef  MATERIAL_H

#include "utilities.h"
#include "hittable.h"

class material {
    public:
        virtual bool scatter(
            const ray& r_in, const hit_record& rec, color& attenuation, ray& scattered
        ) const = 0; 
};

#endif