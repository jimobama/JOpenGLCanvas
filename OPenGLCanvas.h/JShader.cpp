#include "JShader.h"
#include <fstream>
#include<iostream>

using namespace obaro::gui::graphics;

JShader::JShader(const std::string & title)
{


}

std::string JShader::LoadShader(const std::string &filename) {

	std::ifstream file;
	file.open(filename.c_str());
	std::string output;
	std::string line;
	if (file.is_open())
	{
		while (file.good())
		{
			std::getline(file, line);
			output.append(line + "\n");
		}
	}
	else {
		std::cerr << "Unable to load shader: " << filename << std::endl;
	}


	return output;
}

void  JShader::checkShaderError(GLuint shader, GLuint flag, bool isProgram, const std::string & errorMessage) {

	unsigned int success = 0;
	char error[1024] = { 0 };
	if (isProgram) {
	   
	}
}
JShader::~JShader()
{
}
