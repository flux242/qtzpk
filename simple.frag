#version 130

//layout(location = 0, index = 0) out vec4 fragColor;

void main( void )
{
    //gl_FragColor = vec4( 0.0, 1.0, 0.0, 1.0 );
    gl_FragColor = gl_Color;
}
