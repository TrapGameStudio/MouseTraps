#include "Button.h"
/// <summary>
/// Button is a clickable shape which responses to hover and click events
/// </summary>
template <typename T>
Button<T>::Button() {}

template <typename T>
Button<T>::Button(T* buttonShape,
                  std::function<void(void)> onEnterFunction,
                  std::function<void(void)> onLeaveFunction,
                  std::function<void(void)> onClickMouseDownFunction,
                  std::function<void(void)> onClickMouseUpFunction) {

}

template <typename T>
void Button<T>::draw() {
    if (buttonShape) {
        buttonShape->draw();
    }
}

template <typename T>
void Button<T>::scale(float x, float y) {
    buttonShape->scale(x, y);
}

template <typename T>
void Button<T>::entered() {
    if (onEnterFunction) {
        onEnterFunction();
    }
}

template <typename T>
void Button<T>::onEnter(std::function<void(void)> onEnterFunction) {
    this->onEnterFunction = onEnterFunction;
}

template <typename T>
void Button<T>::left() {
    if (onLeaveFunction) {
        onLeaveFunction();
    }
}

template <typename T>
void Button<T>::onLeave(std::function<void(void)> onLeaveFunction) {
    this->onLeaveFunction = onLeaveFunction;
}

template <typename T>
void Button<T>::clickMouseDown() {
    if (onClickMouseDownFunction) {
        onClickMouseDownFunction();
    }
}

template <typename T>
void Button<T>::onClickMouseDown(std::function<void(void)> onClickMouseDownFunction) {
    this->onClickMouseDownFunction = onClickMouseDownFunction;
}

template <typename T>
void Button<T>::clickMouseUp() {
    if (onClickMouseDownFunction) {
        onClickMouseDownFunction();
    }
}

template <typename T>
void Button<T>::onClickMouseUp(std::function<void(void)> onClickMouseUpFunction) {
    this->onClickMouseUpFunction = onClickMouseUpFunction;
}

template <typename T>
T * Button<T>::getShape() {
    return buttonShape;
}

template <typename T>
bool Button<T>::contains(float x, float y) const {
    return buttonShape->contains(x, y);
}

template <typename T>
Button<T>::~Button() {}

template <typename T>
typename Button<T>::Builder Button<T>::builder() {
    return Button<T>::Builder();
}

template <typename T>
typename Button<T>::Builder & Button<T>::Builder::ofShape(T * buttonShape) {
    delete building->buttonShape;
    building->buttonShape = buttonShape;
    return *this;
}

template <typename T>
typename Button<T>::Builder & Button<T>::Builder::onEnter(std::function<void(void)> onEnterFunction) {
    building->onEnterFunction = onEnterFunction;
    return *this;
}

template <typename T>
typename Button<T>::Builder & Button<T>::Builder::onLeave(std::function<void(void)> onLeaveFunction) {
    building->onLeaveFunction = onLeaveFunction;
    return *this;
}

template <typename T>
typename Button<T>::Builder & Button<T>::Builder::onMouseDown(std::function<void(void)> onClickMouseDownFunction) {
    building->onClickMouseDownFunction = onClickMouseDownFunction;
    return *this;
}

template <typename T>
typename Button<T>::Builder & Button<T>::Builder::onMouseUp(std::function<void(void)> onClickMouseUpFunction) {
    building->onClickMouseUpFunction = onClickMouseUpFunction;
    return *this;
}

template <typename T>
typename Button<T> * Button<T>::Builder::build() {
    return building;
}

template <typename T>
Button<T>::Builder::~Builder() {}

template class Button<TextureRect>;
