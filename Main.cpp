#include "stack.h"
#include <iostream>
using namespace std;

int main() {
    Stack st;
    st.push(60);
    st.push(50);
    st.multiPop(1);
    st.show();
    return 0;
}
