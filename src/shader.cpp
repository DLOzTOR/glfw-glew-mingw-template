#include "shader.h"
#include "SimpleLogger.h"
void SuccessCheck(GLuint descriptor, int status) {
	SimpleLogger logger("logs/errors.txt");
	int success;
	char infoLog[512];
	if (status == GL_COMPILE_STATUS) {
		glGetShaderiv(descriptor, status, &success);
		if (!success) {
			glGetShaderInfoLog(descriptor, 512, nullptr, infoLog);
			logger.Log("ERROR::SHADER::COMPILATION_FAILED");
			logger.Log(infoLog);
		}
	}
	else if (status == GL_LINK_STATUS) {
		glGetProgramiv(descriptor, status, &success);
		if (!success) {
			glGetProgramInfoLog(descriptor, 512, nullptr, infoLog);
			logger.Log("ERROR::SHADER::PROGRAM::LINKING_FAILED");
			logger.Log(infoLog);
		}
	}
	else {
		return;
	}
}

Render::Shader::Shader(const char* vertexShaderSource, const char* fragmentShaderSource) {
	GLuint vertexShader, fragmentShader;
	SimpleLogger logger("logs/main_log.txt");
	logger.Log("Create shader");
	logger.Log("vertex data");
	logger.Log(vertexShaderSource);
	logger.Log("fragment data");
	logger.Log(fragmentShaderSource);
	vertexShader = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(vertexShader, 1, &vertexShaderSource, nullptr);
	glCompileShader(vertexShader);
	SuccessCheck(vertexShader, GL_COMPILE_STATUS);

	fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(fragmentShader, 1, &fragmentShaderSource, nullptr);
	glCompileShader(fragmentShader);
	SuccessCheck(fragmentShader, GL_COMPILE_STATUS);

	shaderProgram = glCreateProgram();
	glAttachShader(shaderProgram, vertexShader);
	glAttachShader(shaderProgram, fragmentShader);
	glLinkProgram(shaderProgram);
	SuccessCheck(shaderProgram, GL_COMPILE_STATUS);

	glDeleteShader(vertexShader);
	glDeleteShader(fragmentShader);
}

void Render::Shader::UseProgram() {
	glUseProgram(shaderProgram);
}

void Render::Shader::SetUniform3fv(const float (&data)[3], const char* name) {
	GLuint colorLocation = glGetUniformLocation(shaderProgram, name);
	glUniform3fv(colorLocation, 1, data);
}

Render::Shader::~Shader() {
	glDeleteProgram(shaderProgram);
}