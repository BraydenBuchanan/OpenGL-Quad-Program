#pragma once

#include <iostream>
#include <unordered_map>
#include <fstream>
#include <string>
#include <sstream>
#include <tuple>

#include "ErrorHandle.h"

class Shader {
public:
	Shader(const std::string& filePath);
	~Shader();

	void Bind() const;
	void Unbind() const;

	void SetUniform1i(const std::string& name, int value);
	void SetUniform1f(const std::string& name, float value);
	void SetUniform4f(const std::string& name, float v0, float v1, float v2, float v3);
private:
	std::tuple<std::string, std::string> ParseShader(const std::string& filepath);
	unsigned int CompileShader(unsigned int type, const std::string& source);
	unsigned int CreateShader(const std::string& vertexShader, const std::string& fragmentShader);
	int GetUniformLocation(const std::string& name);
private:
	std::string filePath;
	unsigned int rendererID;

	std::unordered_map<std::string, int> uniformLocationCache;
};