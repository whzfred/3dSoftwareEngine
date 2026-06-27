#include "render.h"
#include "camera.h"
#include "projection.h"
#include "rasterizer.h"

Uint32 pixels[WIDTH * HEIGHT];


void render_object(Object* obj)
{
    for(int i = 0; i < obj->face_count; i++)
    {
        Face face = obj->faces[i];

        Vertex v1 = obj->vertices[face.a];
        Vertex v2 = obj->vertices[face.b];
        Vertex v3 = obj->vertices[face.c];

        // model transform
        //v1 = transform_rotate_y(v1, 0.01f);
        //v2 = transform_rotate_y(v2, 0.01f);
        //v3 = transform_rotate_y(v3, 0.01f);

        // view transform
        v1 = camera_transform(v1,&camera);
        v2 = camera_transform(v2,&camera);
        v3 = camera_transform(v3,&camera);

        // behind camera
        if(v1.z <= 0 ||
           v2.z <= 0 ||
           v3.z <= 0)
        {
            continue;
        }

        int x1, y1, x2, y2, x3, y3;

        // projection
        projection_project_vertex(v1,&x1,&y1);
        projection_project_vertex(v2,&x2,&y2);
        projection_project_vertex(v3,&x3,&y3);
		
		 // rasterization
		rasterizer_draw_triangle(x1, y1, x2, y2, x3, y3);
    }
}