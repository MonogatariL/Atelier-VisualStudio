#include <iostream>
#include <random>
#include <vector>
#include <map>
#include <unordered_map>
#include <set>
#include <deque>
using namespace std;
// ���� 1 �� 6 �������
int rollDice() {
    static std::random_device rd;
    static std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(1, 6);
    return dis(gen);
}

// ģ�ⶪһ������ 6 �����Ӳ������� 2
int rollThreeDiceAndAddOne() {
    int sum = 0;
    for (int i = 0; i < 3; ++i) {
        sum += rollDice();
    }
    return sum + 2;
}

// ģ�ⶪ�������� 6 �����Ӳ�ȡ�ϴ�ֵ
int rollThreeDiceTwiceAndTakeMax() {
    int sum1 = 0, sum2 = 0;
    for (int i = 0; i < 3; ++i) {
        sum1 += rollDice();
    }
    for (int i = 0; i < 3; ++i) {
        sum2 += rollDice();
    }
    return max(sum1, sum2);
}

int main() {

}