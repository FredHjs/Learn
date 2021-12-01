class X;
class Y;

//we can declare ptr to a class as long as it's declared
class X{
    public:
        Y* p_y;
};

//we need to define the class X before we declare it as member of another class Y
class Y{
    public:
        X x;
};

