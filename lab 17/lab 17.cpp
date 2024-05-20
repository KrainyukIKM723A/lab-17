#include <iostream> 

using namespace std;

class HexCounter {

protected:

    int value;
    int minValue;
    int maxValue;



public:

    HexCounter() {

        value = 0;

        minValue = 0;

        maxValue = 255;

    }



    HexCounter(int initialValue, int minVal, int maxVal) {

        minValue = minVal;

        maxValue = maxVal;



        if (initialValue < minValue || initialValue > maxValue) {

            value = minValue;

        }

        else {

            value = initialValue;

        }

    }

    void increment() {

        if (value < maxValue) {

            ++value;

        }

    }

    void decrement() {

        if (value > minValue) {

            --value;

        }

    }

    int getValue() {

        return value;

    }



    void printValue() {

        cout << "Current value: " << hex << value << endl;

    }

};



class AdjustableHexCounter : public HexCounter {

public:

    using HexCounter::HexCounter;



    void incrementBy(int num) {

        if (value + num <= maxValue) {

            value += num;

        }

        else {

            value = maxValue;

        }

    }



    void decrementBy(int num) {

        if (value - num >= minValue) {

            value -= num;

        }

        else {

            value = minValue;

        }

    }

};



int main() {

    HexCounter counter1;
    HexCounter counter2(50, 0, 100);


    cout << "Counter 1 initial value: ";
    counter1.printValue();
    counter1.increment();
    cout << "Counter 1 after increment: ";
    counter1.printValue();
    counter1.decrement();
    cout << "Counter 1 after decrement: ";
    counter1.printValue();
    cout << endl;


    cout << "Counter 2 initial value: ";
    counter2.printValue();
    counter2.increment();
    cout << "Counter 2 after increment: ";
    counter2.printValue();
    counter2.decrement();
    cout << "Counter 2 after decrement: ";
    counter2.printValue();
    cout << endl;

    AdjustableHexCounter adjustableCounter(10, 0, 50);

    cout << "Adjustable Counter initial value: ";
    adjustableCounter.printValue();
    adjustableCounter.incrementBy(5);
    cout << "Adjustable Counter after increment by 5: ";
    adjustableCounter.printValue();
    adjustableCounter.decrementBy(3);
    cout << "Adjustable Counter after decrement by 3: ";
    adjustableCounter.printValue();
  
    return 0;

}