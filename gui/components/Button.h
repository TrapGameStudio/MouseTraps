#pragma once
#include "gui/lang/Clickable.h"
#include "gui/lang/Drawable.h"
#include "gui/components/TextureRect.h"
#include <functional>
template <typename T>
class Button :
	public Clickable,
	public Drawable {
	static_assert(std::is_base_of<Drawable, T>(), "Type must be Drawable.");
private:
	T * buttonShape = nullptr;
	class Builder;
	std::function<void(void)> onEnterFunction = nullptr;
	std::function<void(void)> onLeaveFunction = nullptr;
	std::function<void(void)> onClickMouseDownFunction = nullptr;
	std::function<void(void)> onClickMouseUpFunction = nullptr;
	Button();
public:
	Button(T * buttonShape,
		   std::function<void(void)> onEnterFunction,
		   std::function<void(void)> onLeaveFunction,
		   std::function<void(void)> onClickMouseDownFunction,
		   std::function<void(void)> onClickMouseUpFunction);
	void draw();
	void scale(float x, float y);
	void entered();
	void onEnter(std::function<void(void)> onEnterFunction);
	void left();
	void onLeave(std::function<void(void)> onLeaveFunction);
	void clickMouseDown();
	void onClickMouseDown(std::function<void(void)> onClickMouseDownFunction);
	void clickMouseUp();
	void onClickMouseUp(std::function<void(void)> onClickMouseUpFunction);
	T * getShape();
	bool contains(float x, float y) const;
	~Button();

	static typename Button<T>::Builder Button<T>::builder();
};

template <typename T>
class Button<T>::Builder {
	typename Button<T>* building = new Button<T>();
public:
	typename Button<T>::Builder& ofShape(T * buttonShape);
	typename Button<T>::Builder& onEnter(std::function<void(void)> onEnterFunction);
	typename Button<T>::Builder& onLeave(std::function<void(void)> onLeaveFunction);
	typename Button<T>::Builder& onMouseDown(std::function<void(void)> onClickMouseDownFunction);
	typename Button<T>::Builder& onMouseUp(std::function<void(void)> onClickMouseUpFunction);
	typename Button<T> * build();
	~Builder();
};
