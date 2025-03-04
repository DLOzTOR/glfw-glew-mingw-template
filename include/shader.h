#include <GL/glew.h>
#include <iostream>
namespace Render {
	class Shader {
	GLuint shaderProgram;
	public:	
		Shader(const char* vertexShaderSource, const char* fragmentShaderSource);
		void UseProgram();
		void SetUniform3fv(const float(&data)[3], const char *name);
		~Shader();
	};
}