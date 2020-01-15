
int main() {
  auto data = build_array(1, 0u, 'a', 3.2f, false);

  for (auto i : data)
    std::cout << i << " ";
  std::cout << std::endl;

  auto data2 = build_array(1, "Packt", 2.0);
}
