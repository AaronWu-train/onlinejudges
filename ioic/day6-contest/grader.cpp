#if __has_include ("reporter.h")
#   include "reporter.h"
#else
#   include "lib0058.h"
#endif 
#include <cassert>
#include <cstdio>
#include <cstdlib>

namespace {
  static const int maxN = 500;
  static const int maxQ = 200'000;
  static int Q = 0;

  void wrong_answer(const char *c) {
    fprintf(stdout, "Wrong Answer: %s\n", c);
    exit(0);
  }

  int N, rank[maxN], occ[maxN];
}

int get_downvote(std::vector<int> g) {
  ++Q;
  if (Q > maxQ)
    wrong_answer("too many queries");

  if (g.size() != N)
    wrong_answer("invalid guess");
  for (int i = 0; i < N; i++)
    occ[i] = 0;

  for (int i = 0; i < N; i++) {
    if (g[i] < 0 || g[i] >= N)
      wrong_answer("invalid guess");
    if (occ[g[i]] == 1)
      wrong_answer("invalid guess");
    occ[g[i]] = 1;
  }

  int result = 0;
  for (int i = 0; i < N; i++)
    if (rank[g[i]] < i)
      ++result;

  return result;
}

int main()
{
  assert(fscanf(stdin, "%d", &N) == 1);
  assert(!(N <= 0 || N > maxN));
  for (int i = 0; i < N; i++)
    occ[i] = 0;

  std::vector<int> r(N);
  for (int i = 0; i < N; i++) {
    int j;
    assert(fscanf(stdin, "%d", &j) == 1);
    assert(!(j < 0 || j >= N));
    assert(occ[j] == 0);
    rank[j] = i;
    r[i] = j;
  }

  std::vector<int> g = get_ranking(N);

  if (g.size() != N)
    wrong_answer("invalid answer");
  for (int i = 0; i < N; i++)
    occ[i] = 0;

  for (int i = 0; i < N; i++) {
    if (g[i] < 0 || g[i] >= N)
      wrong_answer("invalid answer");
    if (occ[g[i]] == 1)
      wrong_answer("invalid answer");
    occ[g[i]] = 1;
  }

  if (r != g)
    wrong_answer("not correct");

  fprintf(stdout, "Accepted: %d\n", Q);
}