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

/// <summary>
/// Draw the shape this button uses.
/// </summary>
template <typename T>
void Button<T>::draw() {
    if (buttonShape) {
        buttonShape->draw();
    }
}

/// <summary>
/// Function to called when mouse pointer enters the button. 
/// </summary>
template <typename T>
void Button<T>::entered() {
    if (onEnterFunction) {
        onEnterFunction();
    }
}

/// <summary>
/// Defining what should happen when mouse pointer enters the button.
/// </summary>
template <typename T>
void Button<T>::onEnter(std::function<void(void)> onEnterFunction) {
    this->onEnterFunction = onEnterFunction;
}

/// <summary>
/// Function to called when mouse pointer leaves the button. 
/// </summary>
template <typename T>
void Button<T>::left() {
    if (onLeaveFunction) {
        onLeaveFunction();
    }
}

/// <summary>
/// Defining what should happen when mouse pointer leaves the button.
/// </summary>
template <typename T>
void Button<T>::onLeave(std::function<void(void)> onLeaveFunction) {
    this->onLeaveFunction = onLeaveFunction;
}

/// <summary>
/// Function to called when there is a left click the button. 
/// </summary>
template <typename T>
void Button<T>::clickMouseDown() {
    if (onClickMouseDownFunction) {
        onClickMouseDownFunction();
    }
}

/// <summary>
/// Defining what should happen when the button is left clicked.
/// </summary>
template <typename T>
void Button<T>::onClickMouseDown(std::function<void(void)> onClickMouseDownFunction) {
    this->onClickMouseDownFunction = onClickMouseDownFunction;
}

/// <summary>
/// Function to called when the left mouse button is released on this button. 
/// </summary>
template <typename T>
void Button<T>::clickMouseUp() {
    if (onClickMouseDownFunction) {
        onClickMouseDownFunction();
    }
}

/// <summary>
/// Defining what should happen when the left mouse button is released on this button.
/// </summary>
template <typename T>
void Button<T>::onClickMouseUp(std::function<void(void)> onClickMouseUpFunction) {
    this->onClickMouseUpFunction = onClickMouseUpFunction;
}

/// <summary>
/// Get the under laying shape of this button.
/// </summary>
template <typename T>
T * Button<T>::getShape() {
    return buttonShape;
}

/// <summary>
/// Check if a xy-coordinate is in this button.
/// </summary>
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
