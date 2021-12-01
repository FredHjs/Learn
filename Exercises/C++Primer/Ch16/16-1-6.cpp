#include "SharedPtr.h"
#include <iostream>

struct Foo {
    Foo() { std::cout << "Foo()\n"; }
    ~Foo() { std::cout << "~Foo()\n"; }
    Foo(const Foo&) { std::cout << "Foo copy ctor\n"; }
    Foo(Foo&&) { std::cout << "Foo move ctor\n"; }
};

struct Fooo {
    Fooo(int n = 0) noexcept : bar(n) { std::cout << "Fooo: constructor, bar = " << bar << '\n'; }
    ~Fooo() { std::cout << "Fooo: destructor, bar = " << bar << '\n'; }
    int GetBar() const noexcept { return bar; }

private:
    int bar;
};

struct D {
    void bar() { std::cout << "Call deleter D::bar()...\n"; }
    void operator()(Foo* p) const
    {
        std::cout << "Call delete from function object...\n";
        delete p;
    }
};

int main(){
    std::cout << "SharedPtr constructor with no managed object\n";
    {
        SharedPtr<Foo> sh1;
    }

    std::cout << "SharedPtr constructor with object\n";
    {
        SharedPtr<Foo> sh2(new Foo);
        std::cout << sh2.used_count() << '\n';
        SharedPtr<Foo> sh3(sh2);
        std::cout << sh3.used_count() << '\n';
    }

    std::cout << "SharedPtr constructor with deleter\n";
    {
        auto lambda = [](Foo* p) {
            std::cout << "Call delete from lambda...\n";
            delete p;
        };
        SharedPtr<Foo> sh5(new Foo, lambda);
    }

    {
        SharedPtr<Fooo> sptr(new Fooo(1));
        std::cout << "The first Fooo's bar is " << sptr->GetBar() << "\n";
        sptr.reset(new Fooo);
        std::cout << "The second Fooo's bar is " << sptr->GetBar() << "\n";
    }
}