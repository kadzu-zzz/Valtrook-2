#include "GLShaderImplementation.h"

#include "Engine.h"
#include "Logger.h"

auto getAttributes() {
	auto attributes = std::vector<std::string>();

	attributes.push_back("vertexPosition");
	attributes.push_back("vertexUV");
	attributes.push_back("vertexColor");

	return attributes;
}

int GLShaderImplementation::GetUniformName(std::string name)
{
	if (uniform_map.contains(name)) {
		return uniform_map.at(name);
	}

	int location = glGetUniformLocation(shader_id, name.c_str());

	if (location != GL_INVALID_INDEX) {
		uniform_map.emplace(std::make_pair(name, location));
		return location;
	}

	Engine::engine->getLogger()->logMessage(ERROR, "Invalid Uniform Name requested : " + name);

	return GL_INVALID_INDEX;
}


GLShaderImplementation::GLShaderImplementation(FileReader* shader_file) : is_compiled(false), uniform_map(32), shader_priority(0)
{
	auto attributes = getAttributes();
	number_of_attributes = attributes.size();

	shader_id = glCreateProgram();

	std::string vertex_shader = "";
	std::string fragment_shader = "";

	bool vertex_mode = false;
	bool fragment_mode = false;

	if (shader_file->File.good()) {
		std::string line = "";
		while (std::getline(shader_file->File, line)) {
			if (line == "VERT") {
				vertex_mode = true;
				fragment_mode = false;
				continue;
			}
			if (line == "FRAG") {
				vertex_mode = false;
				fragment_mode = true;
				continue;
			}

			if (vertex_mode)
				vertex_shader += line;
			if (fragment_mode)
				fragment_shader += line;
		}
	}
	else
	{
		Engine::engine->getLogger()->logMessage(ERROR, "Invalid Shader File Location");
		return;
	}

	unsigned int vertex_shader_id = 0;
	unsigned int fragment_shader_id = 0;

	if (!(vertex_shader_id = glCreateShader(GL_VERTEX_SHADER))) {
		const char* vertex_content = vertex_shader.c_str();
		glShaderSource(vertex_shader_id, 1, &vertex_content, nullptr);
		glCompileShader(vertex_shader_id);

		int success = 0;
		glGetShaderiv(vertex_shader_id, GL_INFO_LOG_LENGTH, &success);
		if (success == GL_FALSE) {
			int maxLength = 0;
			glGetShaderiv(vertex_shader_id, GL_INFO_LOG_LENGTH, &maxLength);

			std::vector<char> errorLog(maxLength);
			glGetShaderInfoLog(vertex_shader_id, maxLength, &maxLength, &errorLog[0]);
			Engine::engine->getLogger()->logMessage(ERROR, &errorLog[0]);


			glDeleteShader(vertex_shader_id);
			glDeleteProgram(shader_id);
			return;
		}
	}

	if (!(fragment_shader_id = glCreateShader(GL_FRAGMENT_SHADER))) {
		const char* fragment_content = fragment_shader.c_str();
		glShaderSource(fragment_shader_id, 1, &fragment_content, nullptr);
		glCompileShader(fragment_shader_id);

		int success = 0;
		glGetShaderiv(fragment_shader_id, GL_INFO_LOG_LENGTH, &success);
		if (success == GL_FALSE) {
			int maxLength = 0;
			glGetShaderiv(fragment_shader_id, GL_INFO_LOG_LENGTH, &maxLength);

			std::vector<char> errorLog(maxLength);
			glGetShaderInfoLog(fragment_shader_id, maxLength, &maxLength, &errorLog[0]);
			Engine::engine->getLogger()->logMessage(ERROR, &errorLog[0]);

			glDeleteShader(vertex_shader_id);
			glDeleteShader(fragment_shader_id);
			glDeleteProgram(shader_id);
			return;
		}
	}

	int c = 0;
	for (std::string attrib : attributes) {
		glBindAttribLocation(shader_id, c++, attrib.c_str());
	}

	glAttachShader(shader_id, vertex_shader_id);
	glAttachShader(shader_id, fragment_shader_id);

	glLinkProgram(shader_id);

	int isLinked = 0;
	glGetProgramiv(shader_id, GL_LINK_STATUS, (int*)&isLinked);

	glDetachShader(shader_id, vertex_shader_id);
	glDetachShader(shader_id, fragment_shader_id);

	if (isLinked == GL_FALSE) {
		int maxLength = 0;
		glGetProgramiv(shader_id, GL_INFO_LOG_LENGTH, &maxLength);

		std::vector<char> errorLog(maxLength);
		glGetProgramInfoLog(shader_id, maxLength, &maxLength, &errorLog[0]);
		Engine::engine->getLogger()->logMessage(ERROR, &errorLog[0]);

		glDeleteProgram(shader_id);
	}

	glDeleteShader(vertex_shader_id);
	glDeleteShader(fragment_shader_id);

	if(isLinked == GL_TRUE)
		is_compiled = true;
}

GLShaderImplementation::~GLShaderImplementation()
{
	if (is_compiled) {
		glDeleteProgram(shader_id);
	}
}

bool GLShaderImplementation::IsValid()
{
	return is_compiled;
}

int GLShaderImplementation::ShaderPriority()
{
	return shader_priority;
}

void GLShaderImplementation::SetShaderPriority(int priority)
{
	shader_priority = priority;
}

void GLShaderImplementation::Attach()
{
	glUseProgram(shader_id);
	for (unsigned int i = 0; i < number_of_attributes; ++i) {
		glEnableVertexAttribArray(i);
	}
}

void GLShaderImplementation::Update()
{
	SetMatrix4Vector("CameraMatrix", 1, false, nullptr);
}

void GLShaderImplementation::SetMainTexture(int texture_id)
{
	SetInteger("MainTexture", texture_id);
}

void GLShaderImplementation::SetFloat(std::string name, float value)
{
	glUniform1f(GetUniformName(name), value);
}

void GLShaderImplementation::SetFloat2(std::string name, float value, float value2)
{
	glUniform2f(GetUniformName(name), value, value2);
}

void GLShaderImplementation::SetFloat3(std::string name, float value, float value2, float value3)
{
	glUniform3f(GetUniformName(name), value, value2, value3);
}

void GLShaderImplementation::SetFloat4(std::string name, float value, float value2, float value3, float value4)
{
	glUniform4f(GetUniformName(name), value, value2, value3, value4);
}

void GLShaderImplementation::SetInteger(std::string name, int value)
{
	glUniform1i(GetUniformName(name), value);
}

void GLShaderImplementation::SetInteger2(std::string name, int value, int value2)
{
	glUniform2i(GetUniformName(name), value, value2);
}

void GLShaderImplementation::SetInteger3(std::string name, int value, int value2, int value3)
{
	glUniform3i(GetUniformName(name), value, value2, value3);
}

void GLShaderImplementation::SetInteger4(std::string name, int value, int value2, int value3, int value4)
{
	glUniform4i(GetUniformName(name), value, value2, value3, value4);
}

void GLShaderImplementation::SetUnsignedInteger(std::string name, unsigned int value)
{
	glUniform1ui(GetUniformName(name), value);
}

void GLShaderImplementation::SetUnsignedInteger2(std::string name, unsigned int value, unsigned int value2)
{
	glUniform2ui(GetUniformName(name), value, value2);
}

void GLShaderImplementation::SetUnsignedInteger3(std::string name, unsigned int value, unsigned int value2, unsigned int value3)
{
	glUniform3ui(GetUniformName(name), value, value2, value3);
}

void GLShaderImplementation::SetUnsignedInteger4(std::string name, unsigned int value, unsigned int value2, unsigned int value3, unsigned int value4)
{
	glUniform4ui(GetUniformName(name), value, value2, value3, value4);
}

void GLShaderImplementation::SetFloatVector(std::string name, int count, float* value)
{
	glUniform1fv(GetUniformName(name), count, value);
}

void GLShaderImplementation::SetFloatVector2(std::string name, int count, float* value)
{
	glUniform2fv(GetUniformName(name), count, value);
}

void GLShaderImplementation::SetFloatVector3(std::string name, int count, float* value)
{
	glUniform3fv(GetUniformName(name), count, value);
}

void GLShaderImplementation::SetFloatVector4(std::string name, int count, float* value)
{
	glUniform4fv(GetUniformName(name), count, value);
}

void GLShaderImplementation::SetIntegerVector(std::string name, int count, int* value)
{
	glUniform1iv(GetUniformName(name), count, value);
}

void GLShaderImplementation::SetIntegerVector2(std::string name, int count, int* value)
{
	glUniform2iv(GetUniformName(name), count, value);
}

void GLShaderImplementation::SetIntegerVector3(std::string name, int count, int* value)
{
	glUniform3iv(GetUniformName(name), count, value);
}

void GLShaderImplementation::SetIntegerVector4(std::string name, int count, int* value)
{
	glUniform4iv(GetUniformName(name), count, value);
}

void GLShaderImplementation::SetUnsignedIntegerVector(std::string name, int count, unsigned int* value)
{
	glUniform1uiv(GetUniformName(name), count, value);
}

void GLShaderImplementation::SetUnsignedIntegerVector2(std::string name, int count, unsigned int* value)
{
	glUniform2uiv(GetUniformName(name), count, value);
}

void GLShaderImplementation::SetUnsignedIntegerVector3(std::string name, int count, unsigned int* value)
{
	glUniform3uiv(GetUniformName(name), count, value);
}

void GLShaderImplementation::SetUnsignedIntegerVector4(std::string name, int count, unsigned int* value)
{
	glUniform4uiv(GetUniformName(name), count, value);
}

void GLShaderImplementation::SetMatrix2Vector(std::string name, int count, bool transpose, float* value)
{
	glUniformMatrix2fv(GetUniformName(name), count, transpose, value);
}

void GLShaderImplementation::SetMatrix3Vector(std::string name, int count, bool transpose, float* value)
{
	glUniformMatrix3fv(GetUniformName(name), count, transpose, value);
}

void GLShaderImplementation::SetMatrix4Vector(std::string name, int count, bool transpose, float* value)
{
	glUniformMatrix4fv(GetUniformName(name), count, transpose, value);
}

void GLShaderImplementation::SetMatrix2x3Vector(std::string name, int count, bool transpose, float* value)
{
	glUniformMatrix2x3fv(GetUniformName(name), count, transpose, value);
}

void GLShaderImplementation::SetMatrix3x2Vector(std::string name, int count, bool transpose, float* value)
{
	glUniformMatrix3x2fv(GetUniformName(name), count, transpose, value);
}

void GLShaderImplementation::SetMatrix2x4Vector(std::string name, int count, bool transpose, float* value)
{
	glUniformMatrix2x4fv(GetUniformName(name), count, transpose, value);
}

void GLShaderImplementation::SetMatrix4x2Vector(std::string name, int count, bool transpose, float* value)
{
	glUniformMatrix4x2fv(GetUniformName(name), count, transpose, value);
}

void GLShaderImplementation::SetMatrix3x4Vector(std::string name, int count, bool transpose, float* value)
{
	glUniformMatrix3x4fv(GetUniformName(name), count, transpose, value);
}

void GLShaderImplementation::SetMatrix4x3Vector(std::string name, int count, bool transpose, float* value)
{
	glUniformMatrix4x3fv(GetUniformName(name), count, transpose, value);
}
