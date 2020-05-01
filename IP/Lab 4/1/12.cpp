#include <iostream>
#include <stack>

struct interval { int x, y; };

bool areOverlaping(interval left, interval right)
{
    return right.x <= left.y && left.x <= right.y;
}

interval unite(interval left, interval right)
{
    return {std::min(left.x, right.x), std::max(left.y, right.y)};
}

int main()
{
    int intervalCount;
    std::cin >> intervalCount;

    std::stack<interval> intervals;
    for (int index = 0; index < intervalCount; ++index) {
        interval inter;
        std::cin >> inter.x >> inter.y;

        intervals.push(inter);

        while (intervals.size() > 1) {
            interval last = intervals.top();
            intervals.pop();
            interval penultimate = intervals.top();

            if (areOverlaping(penultimate, last)) {
                intervals.pop();
                intervals.push(unite(penultimate, last));
            }
            else {
                intervals.push(last);
                break;
            }
        }
    }

    std::cout << intervals.size() << '\n';
    return 0;
}
