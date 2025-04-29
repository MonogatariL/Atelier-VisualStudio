// MathLibrary.cpp : Defines the exported functions for the DLL.
#include "pch.h" // use stdafx.h in Visual Studio 2017 and earlier
#include "RollDice.h"
#include <random>
#include <algorithm>

namespace AtelierDll {

    RollDice* RollDice::m_pInstance = nullptr; // 初始化静态成员变量

    RollDice* RollDice::GetInstance()
    {
        if (m_pInstance == nullptr)
        {
            m_pInstance = new RollDice();
        }
        return m_pInstance;
    }

    int RollDice::randomNumber(int rollMin, int rollMax)
    {
        static std::random_device rd;
        static std::mt19937 gen(rd());
        std::uniform_int_distribution<> dis(rollMin, rollMax);
        return dis(gen);
    }

    int RollDice::rollDice(int rollMin, int rollMax,int rollNums)
    {
        if (rollMax < rollMin)
        {
            int res = rollMax;
            rollMax = rollMin;
            rollMin = res;
        }
        int res = 0;
        for (int i = 0; i < rollNums; i++)
        {
            res += randomNumber(rollMin, rollMax);
        }
        return res;
    }
    int RollDice::rollDiceBaldur(int rollMax, int rollNums, BOOL Advantage)
    {
        int res = 0;
        if (Advantage)
        {
            return max(rollDiceBaldur(rollMax, rollNums, false), rollDiceBaldur(rollMax, rollNums, false));
        }
        else
        {
            for (int i = 0; i < rollNums; i++)
            {
                res += randomNumber(1, rollMax);
            }
            return res;
        }
    }
}