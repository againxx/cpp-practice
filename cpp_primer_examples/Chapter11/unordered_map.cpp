#include <unordered_map>
#include <iostream>

int main() {
    std::unordered_map<int, int> umap;
    std::cout << umap.bucket_count() << ' ' << umap.max_bucket_count() << '\n';
    std::cout << "How many elements in each bucket" << '\n';
    for (std::size_t i = 0; i < umap.bucket_count(); ++i) {
        std::cout << umap.bucket_size(i) << '\n';
    }
    umap[2] = 0;
    umap[3] = 1;
    std::cout << umap.bucket_count() << ' ' << umap.max_bucket_count() << '\n';
    std::cout << "How many elements in each bucket" << '\n';
    for (std::size_t i = 0; i < umap.bucket_count(); ++i) {
        std::cout << umap.bucket_size(i) << '\n';
    }
    std::cout << "Load factor" << '\n';
    std::cout << umap.load_factor() << ' ' << umap.max_load_factor() << '\n';
    return 0;
}
