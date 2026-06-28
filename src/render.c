#include "render.h"
#include "camera.h"
#include "projection.h"
#include "rasterizer.h"
#include "transform.h"
#include <stdio.h>
#include <math.h>

Uint32 pixels[WIDTH * HEIGHT];
void render_object(Object* obj, int angle_x, int angle_y, int angle_z)
{
    Vec3 light_dir = {0.5f, 0.5f, 1.0f}; 
    light_dir = vector_normalize(light_dir);

    for(int i = 0; i < obj->face_count; i++)
    {
        Face face = obj->faces[i];

        Vertex v0 = obj->vertices[face.a];
        Vertex v1 = obj->vertices[face.b];
        Vertex v2 = obj->vertices[face.c];

        // model Transform (World Space)
        v0 = transform_rotate(v0, angle_x, angle_y, angle_z);
        v1 = transform_rotate(v1, angle_x, angle_y, angle_z);
        v2 = transform_rotate(v2, angle_x, angle_y, angle_z);

        // flat lightning (world space)
        Vec3 world_edge1 = vector_sub(v1.pos, v0.pos);
        Vec3 world_edge2 = vector_sub(v2.pos, v0.pos);
        Vec3 world_normal = vector_cross(world_edge1, world_edge2);
        world_normal = vector_normalize(world_normal);

        float brightness = vector_dot(world_normal, light_dir);
        if(brightness < 0.0f) brightness = 0.0f;

        brightness = brightness * 0.8f + 0.2f; // Ambient
        if(brightness > 1.0f) brightness = 1.0f;

        int face_light = (int)(brightness * 255.0f);

        // camera Transform (Camera Space)
        v0 = camera_transform(v0, &camera);
        v1 = camera_transform(v1, &camera);
        v2 = camera_transform(v2, &camera);

        // behind Camera Clip
        if(v0.pos.z <= 0.1f || v1.pos.z <= 0.1f || v2.pos.z <= 0.1f)
        {
            continue;
        }

        // backface Culling (Camera Space)
        Vec3 cam_edge1 = vector_sub(v1.pos, v0.pos);
        Vec3 cam_edge2 = vector_sub(v2.pos, v0.pos);
        Vec3 cam_normal = vector_cross(cam_edge1, cam_edge2);
        Vec3 view_ray = v0.pos; 

        // drop the face if it points away from the camera 
        if(vector_dot(cam_normal, view_ray) <= 0.0f)
        {
            continue;
        }

        // projection
        ScreenVertex sv0 = projection_project_vertex(v0);
        ScreenVertex sv1 = projection_project_vertex(v1);
        ScreenVertex sv2 = projection_project_vertex(v2);

        sv0.light = face_light;
        sv1.light = face_light;
        sv2.light = face_light;

        // rasterize 
        rasterizer_draw_triangle(sv0, sv1, sv2);
    }
}

void render_triangle()
{
    ScreenVertex v0;
    v0.x = 150;
    v0.y = 150;
    v0.light = 255;

    ScreenVertex v1;
    v1.x = 100;
    v1.y = 200;
    v1.light = 255;

    ScreenVertex v2;
    v2.x = 200;
    v2.y = 250;
    v2.light = 255;

    rasterizer_draw_triangle(v0, v1, v2);
}