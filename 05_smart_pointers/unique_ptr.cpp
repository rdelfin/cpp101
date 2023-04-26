#include <iostream>
#include <memory>
#include <string>

class Node {
   public:
    Node(int value, std::unique_ptr<Node> next = nullptr)
        : value_(value), next_(std::move(next)) {}
    int get() { return value_; }
    void print_all() {
        std::cout << value_;
        if (next_ != nullptr) {
            std::cout << ", ";
            next_->print_all();
        }
    }

   private:
    int value_;
    std::unique_ptr<Node> next_;
};

int main() {
    Node n(10, std::make_unique<Node>(
                   5, std::make_unique<Node>(55, std::make_unique<Node>(3))));
    n.print_all();
    std::cout << std::endl;
}
