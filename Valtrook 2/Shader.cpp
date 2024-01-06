#include "Shader.h"

#include "FileReader.h"
#include "GLShaderImplementation.h"

#include "Engine.h"
#include "Logger.h"

Shader::Shader(FileReader* file, GraphicsAPI api)
{
	this->api = api;
	switch (api) {
	case OpenGL:
		GL_shader = new GLShaderImplementation(file);
		break;
	case Vulkan:
		Vulkan_shader = new GLShaderImplementation(file);
		Engine::engine->getLogger()->logMessage(ERROR, "Vulkan Shader is not supported yet (Shader.cpp)");
		break;
	}
}

Shader::~Shader()
{
	switch (api) {
	case OpenGL:
		if(GL_shader != nullptr)
			delete GL_shader;
		break;
	case Vulkan:
		if(Vulkan_shader != nullptr)
			delete Vulkan_shader;
		break;
	}
}

bool Shader::IsValid()
{
	switch (api) {
	case OpenGL:
		return GL_shader->IsValid();
	case Vulkan:
		return Vulkan_shader->IsValid();
	}
}

int Shader::ShaderPriority()
{
	switch (api) {
	case OpenGL:
		return GL_shader->ShaderPriority();
	case Vulkan:
		return Vulkan_shader->ShaderPriority();
	}
}

void Shader::SetShaderPriority(int priority)
{
	switch (api) {
	case OpenGL:
		GL_shader->SetShaderPriority(priority);
		break;
	case Vulkan:
		Vulkan_shader->SetShaderPriority(priority);
		break;
	}
}

void Shader::Attach()
{
	switch (api) {
	case OpenGL:
		GL_shader->Attach();
		break;
	case Vulkan:
		Vulkan_shader->Attach();
		break;
	}
}

void Shader::Update()
{
	switch (api) {
	case OpenGL:
		GL_shader->Update();
		break;
	case Vulkan:
		Vulkan_shader->Update();
		break;
	}
}

void Shader::SetMainTexture(int texture_id)
{
	switch (api) {
		case OpenGL:
			GL_shader->SetMainTexture(texture_id);
			break;
		case Vulkan:
			Vulkan_shader->SetMainTexture(texture_id);
			break;
	}
}

void Shader::SetFloat(std::string name, float value)
{
	switch (api) {
	case OpenGL:
		GL_shader->SetFloat(name, value);
		break;
	case Vulkan:
		Vulkan_shader->SetFloat(name, value);
		break;
	}
}

void Shader::SetFloat2(std::string name, float value, float value2)
{
	switch (api) {
	case OpenGL:
		GL_shader->SetFloat2(name, value, value2);
		break;
	case Vulkan:
		Vulkan_shader->SetFloat2(name, value, value2);
		break;
	}
}

void Shader::SetFloat3(std::string name, float value, float value2, float value3)
{
	switch (api) {
	case OpenGL:
		GL_shader->SetFloat3(name, value, value2, value3);
		break;
	case Vulkan:
		Vulkan_shader->SetFloat3(name, value, value2, value3);
		break;
	}
}

void Shader::SetFloat4(std::string name, float value, float value2, float value3, float value4)
{
	switch (api) {
	case OpenGL:
		GL_shader->SetFloat4(name, value, value2, value3, value4);
		break;
	case Vulkan:
		Vulkan_shader->SetFloat4(name, value, value2, value3, value4);
		break;
	}
}

void Shader::SetInteger(std::string name, int value)
{
	switch (api) {
	case OpenGL:
		GL_shader->SetInteger(name, value);
		break;
	case Vulkan:
		Vulkan_shader->SetInteger(name, value);
		break;
	}
}

void Shader::SetInteger2(std::string name, int value, int value2)
{
	switch (api) {
	case OpenGL:
		GL_shader->SetInteger2(name, value, value2);
		break;
	case Vulkan:
		Vulkan_shader->SetInteger2(name, value, value2);
		break;
	}
}

void Shader::SetInteger3(std::string name, int value, int value2, int value3)
{
	switch (api) {
	case OpenGL:
		GL_shader->SetInteger3(name, value, value2, value3);
		break;
	case Vulkan:
		Vulkan_shader->SetInteger3(name, value, value2, value3);
		break;
	}
}

void Shader::SetInteger4(std::string name, int value, int value2, int value3, int value4)
{
	switch (api) {
	case OpenGL:
		GL_shader->SetInteger4(name, value, value2, value3, value4);
		break;
	case Vulkan:
		Vulkan_shader->SetInteger4(name, value, value2, value3, value4);
		break;
	}
}

void Shader::SetUnsignedInteger(std::string name, unsigned int value)
{
	switch (api) {
	case OpenGL:
		GL_shader->SetUnsignedInteger(name, value);
		break;
	case Vulkan:
		Vulkan_shader->SetUnsignedInteger(name, value);
		break;
	}
}

void Shader::SetUnsignedInteger2(std::string name, unsigned int value, unsigned int value2)
{
	switch (api) {
	case OpenGL:
		GL_shader->SetUnsignedInteger2(name, value, value2);
		break;
	case Vulkan:
		Vulkan_shader->SetUnsignedInteger2(name, value, value2);
		break;
	}
}

void Shader::SetUnsignedInteger3(std::string name, unsigned int value, unsigned int value2, unsigned int value3)
{
	switch (api) {
	case OpenGL:
		GL_shader->SetUnsignedInteger3(name, value, value2, value3);
		break;
	case Vulkan:
		Vulkan_shader->SetUnsignedInteger3(name, value, value2, value3);
		break;
	}
}

void Shader::SetUnsignedInteger4(std::string name, unsigned int value, unsigned int value2, unsigned int value3, unsigned int value4)
{
	switch (api) {
	case OpenGL:
		GL_shader->SetUnsignedInteger4(name, value, value2, value3, value4);
		break;
	case Vulkan:
		Vulkan_shader->SetUnsignedInteger4(name, value, value2, value3, value4);
		break;
	}
}

void Shader::SetFloatVector(std::string name, int count, float* value)
{
	switch (api) {
	case OpenGL:
		GL_shader->SetFloatVector(name, count, value);
		break;
	case Vulkan:
		Vulkan_shader->SetFloatVector(name, count, value);
		break;
	}
}

void Shader::SetFloatVector2(std::string name, int count, float* value)
{
	switch (api) {
	case OpenGL:
		GL_shader->SetFloatVector2(name, count, value);
		break;
	case Vulkan:
		Vulkan_shader->SetFloatVector2(name, count, value);
		break;
	}
}

void Shader::SetFloatVector3(std::string name, int count, float* value)
{
	switch (api) {
	case OpenGL:
		GL_shader->SetFloatVector3(name, count, value);
		break;
	case Vulkan:
		Vulkan_shader->SetFloatVector3(name, count, value);
		break;
	}
}

void Shader::SetFloatVector4(std::string name, int count, float* value)
{
	switch (api) {
	case OpenGL:
		GL_shader->SetFloatVector4(name, count, value);
		break;
	case Vulkan:
		Vulkan_shader->SetFloatVector4(name, count, value);
		break;
	}
}

void Shader::SetIntegerVector(std::string name, int count, int* value)
{
	switch (api) {
	case OpenGL:
		GL_shader->SetIntegerVector(name, count, value);
		break;
	case Vulkan:
		Vulkan_shader->SetIntegerVector(name, count, value);
		break;
	}
}

void Shader::SetIntegerVector2(std::string name, int count, int* value)
{
	switch (api) {
	case OpenGL:
		GL_shader->SetIntegerVector2(name, count, value);
		break;
	case Vulkan:
		Vulkan_shader->SetIntegerVector2(name, count, value);
		break;
	}
}

void Shader::SetIntegerVector3(std::string name, int count, int* value)
{
	switch (api) {
	case OpenGL:
		GL_shader->SetIntegerVector3(name, count, value);
		break;
	case Vulkan:
		Vulkan_shader->SetIntegerVector3(name, count, value);
		break;
	}
}

void Shader::SetIntegerVector4(std::string name, int count, int* value)
{
	switch (api) {
	case OpenGL:
		GL_shader->SetIntegerVector4(name, count, value);
		break;
	case Vulkan:
		Vulkan_shader->SetIntegerVector4(name, count, value);
		break;
	}
}

void Shader::SetUnsignedIntegerVector(std::string name, int count, unsigned int* value)
{
	switch (api) {
	case OpenGL:
		GL_shader->SetUnsignedIntegerVector(name, count, value);
		break;
	case Vulkan:
		Vulkan_shader->SetUnsignedIntegerVector(name, count, value);
		break;
	}
}

void Shader::SetUnsignedIntegerVector2(std::string name, int count, unsigned int* value)
{
	switch (api) {
	case OpenGL:
		GL_shader->SetUnsignedIntegerVector2(name, count, value);
		break;
	case Vulkan:
		Vulkan_shader->SetUnsignedIntegerVector2(name, count, value);
		break;
	}
}

void Shader::SetUnsignedIntegerVector3(std::string name, int count, unsigned int* value)
{
	switch (api) {
	case OpenGL:
		GL_shader->SetUnsignedIntegerVector3(name, count, value);
		break;
	case Vulkan:
		Vulkan_shader->SetUnsignedIntegerVector3(name, count, value);
		break;
	}
}

void Shader::SetUnsignedIntegerVector4(std::string name, int count, unsigned int* value)
{
	switch (api) {
	case OpenGL:
		GL_shader->SetUnsignedIntegerVector4(name, count, value);
		break;
	case Vulkan:
		Vulkan_shader->SetUnsignedIntegerVector4(name, count, value);
		break;
	}
}

void Shader::SetMatrix2Vector(std::string name, int count, bool transpose, float* value)
{
	switch (api) {
	case OpenGL:
		GL_shader->SetMatrix2Vector(name, count, transpose, value);
		break;
	case Vulkan:
		Vulkan_shader->SetMatrix2Vector(name, count, transpose, value);
		break;
	}
}

void Shader::SetMatrix3Vector(std::string name, int count, bool transpose, float* value)
{
	switch (api) {
	case OpenGL:
		GL_shader->SetMatrix3Vector(name, count, transpose, value);
		break;
	case Vulkan:
		Vulkan_shader->SetMatrix3Vector(name, count, transpose, value);
		break;
	}
}

void Shader::SetMatrix4Vector(std::string name, int count, bool transpose, float* value)
{
	switch (api) {
	case OpenGL:
		GL_shader->SetMatrix4Vector(name, count, transpose, value);
		break;
	case Vulkan:
		Vulkan_shader->SetMatrix4Vector(name, count, transpose, value);
		break;
	}
}

void Shader::SetMatrix2x3Vector(std::string name, int count, bool transpose, float* value)
{
	switch (api) {
	case OpenGL:
		GL_shader->SetMatrix2x3Vector(name, count, transpose, value);
		break;
	case Vulkan:
		Vulkan_shader->SetMatrix2x3Vector(name, count, transpose, value);
		break;
	}
}

void Shader::SetMatrix3x2Vector(std::string name, int count, bool transpose, float* value)
{
	switch (api) {
	case OpenGL:
		GL_shader->SetMatrix3x2Vector(name, count, transpose, value);
		break;
	case Vulkan:
		Vulkan_shader->SetMatrix3x2Vector(name, count, transpose, value);
		break;
	}
}

void Shader::SetMatrix2x4Vector(std::string name, int count, bool transpose, float* value)
{
	switch (api) {
	case OpenGL:
		GL_shader->SetMatrix2x4Vector(name, count, transpose, value);
		break;
	case Vulkan:
		Vulkan_shader->SetMatrix2x4Vector(name, count, transpose, value);
		break;
	}
}

void Shader::SetMatrix4x2Vector(std::string name, int count, bool transpose, float* value)
{
	switch (api) {
	case OpenGL:
		GL_shader->SetMatrix4x2Vector(name, count, transpose, value);
		break;
	case Vulkan:
		Vulkan_shader->SetMatrix4x2Vector(name, count, transpose, value);
		break;
	}
}

void Shader::SetMatrix3x4Vector(std::string name, int count, bool transpose, float* value)
{
	switch (api) {
	case OpenGL:
		GL_shader->SetMatrix3x4Vector(name, count, transpose, value);
		break;
	case Vulkan:
		Vulkan_shader->SetMatrix3x4Vector(name, count, transpose, value);
		break;
	}
}

void Shader::SetMatrix4x3Vector(std::string name, int count, bool transpose, float* value)
{
	switch (api) {
	case OpenGL:
		GL_shader->SetMatrix4x3Vector(name, count, transpose, value);
		break;
	case Vulkan:
		Vulkan_shader->SetMatrix4x3Vector(name, count, transpose, value);
		break;
	}
}
