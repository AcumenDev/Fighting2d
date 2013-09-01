#ifndef IDRAW_H
#define IDRAW_H


class IDraw {
public:
    IDraw() {};
    virtual ~IDraw() {};
    virtual void  Update(float delta) = 0;
    virtual void  Draw()= 0;
};

#endif // IDRAW_H
