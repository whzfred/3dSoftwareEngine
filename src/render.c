#include "render.h"
#include "camera.h"
#include "projection.h"
#include "rasterizer.h"
#include "transform.h"

Uint32 pixels[WIDTH * HEIGHT];


void render_object(Object* obj, int angle_x, int angle_y, int angle_z)
{
    for(int i = 0; i < obj->face_count; i++)
    {
        Face face = obj->faces[i];

        Vertex v0 = obj->vertices[face.a];
        Vertex v1 = obj->vertices[face.b];
        Vertex v2 = obj->vertices[face.c];

        // model transform
        v0 = transform_rotate(v0, angle_x, angle_y, angle_z);
        v1 = transform_rotate(v1, angle_x, angle_y, angle_z);
        v2 = transform_rotate(v2, angle_x, angle_y, angle_z);

        // view transform
        v0 = camera_transform(v0, &camera);
        v1 = camera_transform(v1, &camera);
        v2 = camera_transform(v2, &camera);

        // behind camera
        if(v0.z <= 0 ||
           v1.z <= 0 ||
           v2.z <= 0)
        {
            continue;
        }

        // projection
        ScreenVertex sv0 = projection_project_vertex(v0);
        ScreenVertex sv1 = projection_project_vertex(v1);
        ScreenVertex sv2 = projection_project_vertex(v2);
		
		 // rasterization
		rasterizer_draw_triangle_vertices(sv0, sv1, sv2);
    }
}

void render_triangle()
{
    ScreenVertex v0;
    v0.x = 150;
    v0.y = 150;

    ScreenVertex v1;
    v1.x = 100;
    v1.y = 200;

    ScreenVertex v2;
    v2.x = 200;
    v2.y = 250;

    rasterizer_draw_triangle_vertices(v0, v1, v2);
}