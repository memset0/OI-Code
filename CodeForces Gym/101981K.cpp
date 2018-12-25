#include <bits/stdc++.h>
using namespace std;

int main() {
    for (int i = 0; i < 50000; i++)
        switch (rand() % 4) {
            case 0: putchar('U'); break;
            case 1: putchar('L'); break;
            case 2: putchar('R'); break;
            case 3: putchar('D'); break;
        }
}
