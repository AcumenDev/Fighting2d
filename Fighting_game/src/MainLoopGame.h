#ifndef MAINLOOPGAME_H
#define MAINLOOPGAME_H
#include "Engine.h"

class MainLoopGame : public MainLoop
{
    public:
        MainLoopGame();
        virtual ~MainLoopGame();
        void EventHandler(SDL_Event event) override;
        void Draw() override;
        void Update(float delta) override;
    protected:
    private:
};

#endif // MAINLOOPGAME_H
