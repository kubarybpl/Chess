
#ifndef TEMPLATEMOVES_H
#define TEMPLATEMOVES_H

template <typename T1, typename T2>
struct myTemplate {
    T1 x;
    T1 y;
    T2 setPassant;

    myTemplate(T1 X, T1 Y, T2 enumVal) : x(X), y(Y), setPassant(enumVal) {}
};

#endif // TEMPLATEMOVES_H
