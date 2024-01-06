#pragma once

#include <string>

class ShaderImplementation {
public:
	virtual bool IsValid() = 0;
	virtual int ShaderPriority() = 0;
	virtual void SetShaderPriority(int priority) = 0;

	virtual void Attach() = 0;
	virtual void Update() = 0;
	 
	virtual void SetMainTexture(int texture_id) = 0;

	virtual void SetFloat(std::string name, float value) = 0;
	virtual void SetFloat2(std::string name, float value, float value2) = 0;
	virtual void SetFloat3(std::string name, float value, float value2, float value3) = 0;
	virtual void SetFloat4(std::string name, float value, float value2, float value3, float value4) = 0;

	virtual void SetInteger(std::string name, int value) = 0;
	virtual void SetInteger2(std::string name, int value, int value2) = 0;
	virtual void SetInteger3(std::string name, int value, int value2, int value3) = 0;
	virtual void SetInteger4(std::string name, int value, int value2, int value3, int value4) = 0;

	virtual void SetUnsignedInteger(std::string name, unsigned int value) = 0;
	virtual void SetUnsignedInteger2(std::string name, unsigned int value, unsigned int value2) = 0;
	virtual void SetUnsignedInteger3(std::string name, unsigned int value, unsigned int value2, unsigned int value3) = 0;
	virtual void SetUnsignedInteger4(std::string name, unsigned int value, unsigned int value2, unsigned int value3, unsigned int value4) = 0;

	virtual void SetFloatVector(std::string name, int count, float* value) = 0;
	virtual void SetFloatVector2(std::string name, int count, float* value) = 0;
	virtual void SetFloatVector3(std::string name, int count, float* value) = 0;
	virtual void SetFloatVector4(std::string name, int count, float* value) = 0;

	virtual void SetIntegerVector(std::string name, int count, int* value) = 0;
	virtual void SetIntegerVector2(std::string name, int count, int* value) = 0;
	virtual void SetIntegerVector3(std::string name, int count, int* value) = 0;
	virtual void SetIntegerVector4(std::string name, int count, int* value) = 0;

	virtual void SetUnsignedIntegerVector(std::string name, int count, unsigned int* value) = 0;
	virtual void SetUnsignedIntegerVector2(std::string name, int count, unsigned int* value) = 0;
	virtual void SetUnsignedIntegerVector3(std::string name, int count, unsigned int* value) = 0;
	virtual void SetUnsignedIntegerVector4(std::string name, int count, unsigned int* value) = 0;

	virtual void SetMatrix2Vector(std::string name, int count, bool transpose, float* value) = 0;
	virtual void SetMatrix3Vector(std::string name, int count, bool transpose, float* value) = 0;
	virtual void SetMatrix4Vector(std::string name, int count, bool transpose, float* value) = 0;
	virtual void SetMatrix2x3Vector(std::string name, int count, bool transpose, float* value) = 0;
	virtual void SetMatrix3x2Vector(std::string name, int count, bool transpose, float* value) = 0;
	virtual void SetMatrix2x4Vector(std::string name, int count, bool transpose, float* value) = 0;
	virtual void SetMatrix4x2Vector(std::string name, int count, bool transpose, float* value) = 0;
	virtual void SetMatrix3x4Vector(std::string name, int count, bool transpose, float* value) = 0;
	virtual void SetMatrix4x3Vector(std::string name, int count, bool transpose, float* value) = 0;
};
