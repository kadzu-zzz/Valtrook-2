#pragma once

#include "ShaderImplementation.h"
#include <hash_map>
#include <string>
#include "FileReader.h"
#include "GL/glew.h"

class GLShaderImplementation : public ShaderImplementation
{
protected:
	unsigned int shader_id;
	unsigned int number_of_attributes;

	bool is_compiled;
	int shader_priority;
	std::hash_map<std::string, int> uniform_map;

	int GetUniformName(std::string name);

public:
	GLShaderImplementation(FileReader* shader_file);
	~GLShaderImplementation();

	virtual bool IsValid() override;
	virtual int ShaderPriority() override;
	virtual void SetShaderPriority(int priority) override;

	virtual void Attach() override;
	virtual void Update() override;

	virtual void SetMainTexture(int texture_id) override;
	virtual void SetFloat(std::string name, float value) override;
	virtual void SetFloat2(std::string name, float value, float value2) override;
	virtual void SetFloat3(std::string name, float value, float value2, float value3) override;
	virtual void SetFloat4(std::string name, float value, float value2, float value3, float value4) override;
	virtual void SetInteger(std::string name, int value) override;
	virtual void SetInteger2(std::string name, int value, int value2) override;
	virtual void SetInteger3(std::string name, int value, int value2, int value3) override;
	virtual void SetInteger4(std::string name, int value, int value2, int value3, int value4) override;
	virtual void SetUnsignedInteger(std::string name, unsigned int value) override;
	virtual void SetUnsignedInteger2(std::string name, unsigned int value, unsigned int value2) override;
	virtual void SetUnsignedInteger3(std::string name, unsigned int value, unsigned int value2, unsigned int value3) override;
	virtual void SetUnsignedInteger4(std::string name, unsigned int value, unsigned int value2, unsigned int value3, unsigned int value4) override;
	virtual void SetFloatVector(std::string name, int count, float* value) override;
	virtual void SetFloatVector2(std::string name, int count, float* value) override;
	virtual void SetFloatVector3(std::string name, int count, float* value) override;
	virtual void SetFloatVector4(std::string name, int count, float* value) override;
	virtual void SetIntegerVector(std::string name, int count, int* value) override;
	virtual void SetIntegerVector2(std::string name, int count, int* value) override;
	virtual void SetIntegerVector3(std::string name, int count, int* value) override;
	virtual void SetIntegerVector4(std::string name, int count, int* value) override;
	virtual void SetUnsignedIntegerVector(std::string name, int count, unsigned int* value) override;
	virtual void SetUnsignedIntegerVector2(std::string name, int count, unsigned int* value) override;
	virtual void SetUnsignedIntegerVector3(std::string name, int count, unsigned int* value) override;
	virtual void SetUnsignedIntegerVector4(std::string name, int count, unsigned int* value) override;
	virtual void SetMatrix2Vector(std::string name, int count, bool transpose, float* value) override;
	virtual void SetMatrix3Vector(std::string name, int count, bool transpose, float* value) override;
	virtual void SetMatrix4Vector(std::string name, int count, bool transpose, float* value) override;
	virtual void SetMatrix2x3Vector(std::string name, int count, bool transpose, float* value) override;
	virtual void SetMatrix3x2Vector(std::string name, int count, bool transpose, float* value) override;
	virtual void SetMatrix2x4Vector(std::string name, int count, bool transpose, float* value) override;
	virtual void SetMatrix4x2Vector(std::string name, int count, bool transpose, float* value) override;
	virtual void SetMatrix3x4Vector(std::string name, int count, bool transpose, float* value) override;
	virtual void SetMatrix4x3Vector(std::string name, int count, bool transpose, float* value) override;
};

