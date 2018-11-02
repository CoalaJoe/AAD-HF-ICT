#include <iostream>

int crosssum(unsigned int n)
{
    if (n == 0) {
        return 0;
    }
    return (n % 10 + crosssum(n / 10));
}

int main()
{
    // Aufagbe 1.
    std::cout << crosssum(156) << std::endl;

    // Aufgabe 2.
    // Schlimmster Fall O(n^2)
    // Wenn das gewählte Pivotelement immer das grösste oder kleinste ist. z.B. Wenn die Liste bereits sortiert ist und das letzte Element gewählt wird.

    // Aufgabe 3.
    // Nein. Es fehlt das virtual keyword zur Überschreibung der Methode.
    class A {
    private :
        int m;
    public :
        A(int m) : m(m)
        { std::cout << "A::constructor,m=" << m << std::endl; }

        //virtual void method()
        void method()
        { std::cout << "A::method" << std::endl; }

        ~A()
        { std::cout << "A::desctructor" << std::endl; }
    };

    class B :
            public A {
    private :
        int m;
    public :
        B(int m) : A(m), m(m)
        { std::cout << "B::constructor,m=" << m << std::endl; }

        //virtual void method()
        //void method()
        {
            std::cout << "B::method" << std::endl;
        }

        ~B()
        { std::cout << "B::desctructor" << std::endl; }
    };

    A *obj = new B(5);
    obj->method();
    delete obj;

    // Lösung: Ja. Aber es fehlt das virtual keyword. Somit wird method nicht von B ausgeführt.

    // Aufgabe 4. Was ist Data?????????

    return 0;
}