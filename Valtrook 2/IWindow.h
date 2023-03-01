#pragma once

#include <string>

struct WindowData;

class IWindow
{
public:
	virtual WindowData* getData() = 0;

	virtual bool IsValid() = 0;
	virtual void Close() = 0;

	virtual int getHeight() = 0;
	virtual int getWidth() = 0;
	virtual std::string getAlias() = 0;
	virtual std::string getTitle() = 0;
	virtual bool hasFullscreenTarget() = 0;
	virtual int getFullscreenTarget() = 0;

	virtual void WindowPoll() = 0;
};