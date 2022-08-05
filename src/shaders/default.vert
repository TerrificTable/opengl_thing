#version 330 core
layout (location = 0) in vec3 aPos;
layout (location = 1) in vec3 aColor;


out vec3 color;

uniform float u_time;
uniform float u_scale;

void main() {
   // gl_Position = vec4(aPos + vec3(aPos * u_scale), 1.0);
   gl_Position = vec4(
         (aPos.x * u_scale) + (cos(u_time) * 0.5), 
         (aPos.y * u_scale) + (sin(u_time) * 0.5), 
         aPos.z * u_scale, 
         1.0
   );
   color = aColor;
}
