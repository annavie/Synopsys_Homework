#include <iostream>
#include <string>

class Window {
public:
    Window() {
        std::cout << "Window constructor called" << std::endl;
    }
    Window(const Window& other) {
        std::cout << "Window copy constructor called" << std::endl;
    }


    virtual ~Window() {
        std::cout << "Window destructor called" << std::endl;
    }

    virtual std::string name() const {
        return "Window";
    }

    virtual void display() const {
        std::cout << "Displaying Window" << std::endl;
    }
};

class WindowWithScrollBars : public Window {
public:
    WindowWithScrollBars() {
        std::cout << "WindowWithScrollBars constructor called" << std::endl;
    }

    virtual ~WindowWithScrollBars() {
        std::cout << "WindowWithScrollBars destructor called" << std::endl;
    }

    virtual std::string name() const override {
        return "WindowWithScrollBars";
    }

    virtual void display() const override {
        std::cout << "Displaying Window with Scroll Bars" << std::endl;
    }
};

// Correct function definition to avoid slicing
void printNameAndDisplay( Window w) { //slicing but when i will be write with  cosnt Window& w its will be all okey because we have virtual function
    std::cout << w.name() << std::endl;
    w.display();
}

int main() {

    WindowWithScrollBars wwsb;
    std::cout << "as" <<std::endl;
    printNameAndDisplay(wwsb);
    return 0;
}
