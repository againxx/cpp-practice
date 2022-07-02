#include <algorithm>
#include <cmath>
#include <iostream>
#include <map>
#include <set>
#include <unordered_map>
#include <vector>

std::vector<unsigned> odd_inputs;
std::vector<unsigned> even_inputs;

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

bool find_matching(unsigned even_id, const std::set<unsigned> &primes,
                   std::vector<int> &existing_matchings,
                   std::vector<bool> &considered_odds) {
  for (std::size_t i = 0; i < odd_inputs.size(); ++i) {
    if (check_prime(even_inputs[even_id] + odd_inputs[i], primes) && !considered_odds[i]) {
      considered_odds[i] = true;
      if (existing_matchings[i] == -1 ||
          find_matching(existing_matchings[i], primes, existing_matchings,
                        considered_odds)) {
        existing_matchings[i] = even_id;
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
    unsigned input_num;
    for (std::size_t i = 0; i < candidate_num; ++i) {
      std::cin >> input_num;
      if (input_num % 2 == 0) {
        even_inputs.push_back(input_num);
      } else {
        odd_inputs.push_back(input_num);
      }
    }

    std::vector<bool> considered_odds(odd_inputs.size());
    std::vector<int> existing_matchings(odd_inputs.size(), -1);
    unsigned count = 0;
    for (std::size_t i = 0; i < even_inputs.size(); ++i) {
      std::fill(considered_odds.begin(), considered_odds.end(), false);
      if (find_matching(i, primes, existing_matchings, considered_odds)) {
        ++count;
      }
    }
    std::cout << count << '\n';

    odd_inputs.clear();
    even_inputs.clear();
  }
}
