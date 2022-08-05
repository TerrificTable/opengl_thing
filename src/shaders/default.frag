#version 330 core

in vec3 color;

uniform float u_time;


void main() {

    // vec3 vertColor = vec3(1.0, 0.0, 1.0);

    // vec4 col = vec4(vertColor, sin(u_time));

    gl_FragColor = vec4(color, 1.0);

}
