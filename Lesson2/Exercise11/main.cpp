#include "./graph.h"


int main() {
    graph g(7);
    g.add_edge(city::LONDON, city::MOSCOW, 900);
    g.add_edge(city::LONDON, city::ISTANBUL, 500);
    g.add_edge(city::LONDON, city::DUBAI, 1000);
    g.add_edge(city::ISTANBUL, city::MOSCOW, 1000);
    g.add_edge(city::ISTANBUL, city::DUBAI, 500);
    g.add_edge(city::DUBAI, city::MUMBAI, 200);
    g.add_edge(city::ISTANBUL, city::SEATTLE, 1500);
    g.add_edge(city::DUBAI, city::SINGAPORE, 500);
    g.add_edge(city::MOSCOW, city::SEATTLE, 1000);
    g.add_edge(city::MUMBAI, city::SINGAPORE, 300);
    g.add_edge(city::SEATTLE, city::SINGAPORE, 700);

    g.add_edge(city::SEATTLE, city::LONDON, 1800);
    g.remove_edge(city::SEATTLE, city::LONDON);
}
