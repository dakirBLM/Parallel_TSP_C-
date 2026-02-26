#include <algorithm>
#include <iostream>
#include <vector>
#include <thread>
#include <mutex>

using namespace std;


const unsigned int N = 4;
const unsigned int D[N][N] = {
    {0, 5, 40, 11}, {5, 0, 9, 6}, {40, 9, 0, 8}, {11, 6, 8, 0}};
// for the best bath 
vector<int> best_path;
//for the best cost 
unsigned int best = UINT_MAX;

mutex best_mutex;
void print_matrix() {
    cout << "Distance Matrix:" << endl;
    cout << "   ";
    for (unsigned int i = 0; i < N; i++)
        cout << "  " << i;  
    cout << endl;

    for (unsigned int i = 0; i < N; i++) {
        cout << i << " |";  
        for (unsigned int j = 0; j < N; j++) {
            cout << " " << D[i][j] << " ";  
        }
        cout << endl;
    }
    cout << endl;
}

// Print all cities in a permutation on one line
void print_permutation(vector<int> &perm) {
  for (int i : perm) cout << i << " ";
  cout << endl;
}

// Print permutation using iterators (used for partial printing)
void print_permutation(vector<int>::iterator it, vector<int>::iterator end) {
  while (it != end) { cout << *it << " "; it++; }
  cout << endl;
}

// Fill permutation with [0, 1, 2, ..., n-1]
void create_permutation(vector<int> &perm, unsigned int n) {
  perm.clear();
  perm.resize(n);
  for (unsigned int i = 0; i < n; i++) perm[i] = i;
}

// Generate and print ALL permutations of n cities
void test_permutations(unsigned int n) {
  vector<int> permutation;
  create_permutation(permutation, n);
  do {
    print_permutation(permutation);
  } while (next_permutation(permutation.begin(), permutation.end()));
}


unsigned int calc_perm(vector<int> &p) {
  unsigned int total = 0;
  for (unsigned int i = 0; i < p.size() - 1; i++)
    total += D[p[i]][p[i+1]];  
  total += D[p.back()][p[0]]; 
  return total;
}


unsigned int calc_perm_pref(vector<int> &p, unsigned int pref) {
  unsigned int total = 0;
  for (unsigned int i = 0; i < pref - 1; i++)
    total += D[p[i]][p[i+1]];  // only sum the prefix portion
  return total;
}

void test_permutations_pref(unsigned int pref, unsigned int n) {
  vector<int> permutation;
  create_permutation(permutation, n);
  do {
    print_permutation(permutation);
    cout << "cost: " << calc_perm(permutation) << endl;
  } while (next_permutation(permutation.begin() + pref, permutation.end()));
}


void thread_work(unsigned int start_city, unsigned int n) {
  vector<int> perm;
  create_permutation(perm, n);

  // Move start_city to front so this thread owns that starting point
  swap(perm[0], perm[start_city]);

  for(int i = 0; i <= n; i++) {
    unsigned int cost = calc_perm(perm);


     cout << "Tour: "; 
     print_permutation(perm);
     cout << "Cost: " << cost << endl;  

    // Lock mutex before accessing shared `best` to avoid race conditions
    lock_guard<mutex> lock(best_mutex);
    if (cost < best) {
    best = cost;
    best_path = perm; 
       
}  
  }
  
}

int main() {
  vector<thread> threads;


  print_matrix();

  for (unsigned int i = 0; i < N; i++)
    threads.push_back(thread(thread_work, i, N));


  for (auto &t : threads)
    t.join();

  cout << "Best tour cost: " << best << endl;

  cout << "Best path: ";
for (int city : best_path)
    cout << city << " → ";
cout << best_path[0] << endl; 

  return 0;
}