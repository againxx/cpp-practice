#include <algorithm>
#include <cmath>
#include <iostream>
#include <map>
#include <set>
#include <unordered_map>
#include <vector>

bool check_prime(unsigned input, const std::set<unsigned> &primes) {
  if (primes.count(input) > 0) {
    return true;
  }
  return false;
}

std::set<unsigned> construct_primes(unsigned threshold) {
  std::set<unsigned> results;
  for (unsigned i = 3; i <= threshold; i += 2) {
    bool is_prime = true;
    for (auto prime : results) {
      if (prime * prime > i) {
        break;
      }
      if (i % prime == 0) {
        is_prime = false;
        break;
      }
    }
    if (is_prime) {
      results.insert(i);
    }
  }
  return results;
}

bool find_matching(unsigned query, const std::vector<unsigned> &opposites,
                   const std::set<unsigned> &primes,
                   std::map<unsigned, unsigned> &existing_matchings,
                   std::set<unsigned> &considered_queries) {
  if (considered_queries.count(query) > 0) {
      return false;
  }
  considered_queries.insert(query);
  for (std::size_t i = 0; i < opposites.size(); ++i) {
    if (check_prime(query + opposites[i], primes)) {
      auto it = existing_matchings.find(opposites[i]);
      if (it == existing_matchings.end() ||
          find_matching(it->second, opposites, primes, existing_matchings,
                        considered_queries)) {
        existing_matchings[opposites[i]] = query;
        return true;
      }
    }
  }
  return false;
}

int main() {
  auto primes = construct_primes(60000);
  unsigned candidate_num;
  while (std::cin >> candidate_num) {
    std::vector<unsigned> odd_inputs;
    std::vector<unsigned> even_inputs;
    unsigned input_num;
    for (std::size_t i = 0; i < candidate_num; ++i) {
      std::cin >> input_num;
      if (input_num % 2 == 0) {
        even_inputs.push_back(input_num);
      } else {
        odd_inputs.push_back(input_num);
      }
    }

    std::sort(odd_inputs.begin(), odd_inputs.end());
    std::sort(even_inputs.begin(), even_inputs.end());
    std::set<unsigned> considered_queries;
    std::map<unsigned, unsigned> existing_matchings;
    unsigned count = 0;
    for (auto even : even_inputs) {
      considered_queries.clear();
      if (find_matching(even, odd_inputs, primes, existing_matchings,
                    considered_queries)) {
                    ++count;
            }
    }
    for (auto matching : existing_matchings) {
        std::cout << matching.second << ' ' << matching.first << '\n';
    }
    std::cout << existing_matchings.size() << '\n';
    std::cout << count << '\n';
  }
}
