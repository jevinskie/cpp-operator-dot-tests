extern "C" int printf(const char *format, ...);
extern "C" int puts(const char *str);

template <class X> class Ref {
public:
    Ref(X &x) : m_p{&x} {} // refer to x
    X &operator.() {
        return *m_p;
    }
    void rebind(X &x) {
        m_p = &x; // refer to x
    }

private:
    X *m_p;
};

class Foo {
public:
    Foo(int n) : m_n(n) {}
    void f() {
        puts("Foo::f()");
    }
private:
    int m_n;
};

void ref_intro_test() {
    Foo xvar{77};
    Ref<Foo> r{xvar}; // make r refer to xvar
    r.f();            // means (r.operator.()).f() means (*r.p).f()
    // ++r;              // means ++r.operator.()
    // Ref<Foo> r2 = r;  // r2 refers to the same X as r (copy constructed)
}
