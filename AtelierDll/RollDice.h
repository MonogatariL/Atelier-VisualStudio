// MathLibrary.h - Contains declarations of math functions
#pragma once

#ifdef ATELIERDLL_EXPORTS
#define MATHLIBRARY_API __declspec(dllexport)
#else
#define MATHLIBRARY_API __declspec(dllimport)
#endif

namespace AtelierDll {

    class MATHLIBRARY_API RollDice
    {
    public:
        static RollDice* GetInstance();
        int rollDice(int rollMin = 1, int rollMax = 6, int rollNums = 1);
        int rollDiceBaldur(int rollMax = 6, int rollNums = 1,BOOL Advantage = false);
    private:
        RollDice() {};
        int randomNumber(int rollMin=1, int rollMax=6);
    protected:
        static RollDice* m_pInstance;
    };

}