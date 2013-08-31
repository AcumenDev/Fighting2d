#ifndef IDRAW_H
#define IDRAW_H


class IDraw
{
    public:
        IDraw() {}
        virtual ~IDraw() {}
        void Update(float delta);
        void Draw();
    protected:
    private:
};

#endif // IDRAW_H
