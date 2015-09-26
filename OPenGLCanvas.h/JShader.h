#pragma once
#include "string"
#include <Windows.h>
#include <gl\GL.h>
#include <gl\GLU.h>

namespace obaro {

	namespace gui {
		namespace graphics {

			class JShader
			{
			public:
				JShader(const std::string &filename);
				void bind();
				static std::string LoadShader(const std::string & filename);
				static void checkShaderError(const GLuint shader, GLuint flag, bool isProgram, const std::string& errormessage);
				virtual ~JShader();

			private:
				static const unsigned int NUM_SHADERS = 2;
				JShader(const JShader& other) {}
				void operator =(const JShader& other) {};
				GLuint m_program;
				GLuint  m_shader[NUM_SHADERS];
			};
		}
	}

}

