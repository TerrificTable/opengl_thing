#version 330 core

in vec3 color;

uniform float u_time;


void main() {

    vec4 col = vec4(1.0, 0.0, 1.0, sin(u_time));

    gl_FragColor = col; // vec4(color, 1.0);

}
