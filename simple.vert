#version 130

in vec3 vertex;
uniform mat4 proj_matrix;
uniform mat4 model_matrix;
uniform float fog_end;
uniform vec4 model_color;

void main( void )
{
    float fog; // amount of fog to apply
    float fog_coord; // distance for fog calculation...

    gl_Position = proj_matrix * model_matrix * vec4(vertex,1.0);
    fog_coord = abs(gl_Position.z);
    fog_coord = clamp( fog_coord, 0.0, fog_end);
    fog = (fog_end - fog_coord)/fog_end;
    fog = clamp( fog, 0.0, 1.0);
    //gl_FrontColor = mix(fog_color, gl_Color, fog);
    gl_FrontColor = mix(vec4( 0.0, 0.0, 0.0, 1.0 ), model_color, fog);
}
