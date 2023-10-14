# LeetCode Solutions

This is my leetcode solutions

---

## Findings

- Deque is faster than Queue in CPP.

- For speed-up use:

```cpp
static auto _ = []() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);
  return 0;
}();

```

- This speeds up execution by disabling sync between C & C++ stream. [^1]

```cpp
ios_base::sync_with_stdio(false);
```

- This unties `cin` from `cout` and speeds up execution.

```cpp
cin.tie(NULL);
```

- In vectors `ans.emplace_back(val)` is faster than `ans.push_back(val)` but it takes more memory, `emplace_back` constructs the object to insert this is useful when the object is expensive to copy, `push_back` should be used when the object which has to be inserted is cheap to copy or you already have the copy of the object.

- SQL is hard

- Function `next_permutaton` is a damn good, similarly `prev_premutation`

```cpp
vector<int> nums{1, 2, 3};

next_permutation(nums.begin(), nums.end());

// nums=> 1, 3, 2
```

- Function `iota` assigns sucessive values to elements

```cpp
vector<int> nums(5);

iota(nums.begin(), nums.end(), 1);

// nums => 1, 2, 3, 4, 5
```

[^1]: source: [GFG](https://www.geeksforgeeks.org/fast-io-for-competitive-programming/)
