# LeetCode Solutions

This is my leetcode solutions

---

## Findings

### Rust

- Rust is hard

- Double ended iterators are very useful for manual binary search

  ```rs
  let v = vec![1,2,3,4,5,6];
  let mut iter = v.iter();

  let (mut left, mut right) = (iter.next(), iter.next_back());

  while (Some(l), Some(r)) = (left, right){
    // will yield values (1,6), (2,5) ...
    left = iter.next();
    right = iter.next_back();
  }

  ```

### CPP

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

- Better way of calculating mid

  ```cpp
  int mid = (low + high) / 2; // This can cause overflow if low and high are INT_MAX

  int mid = low + (high - low) / 2;
  
  ```

- To have custom comparison in `priority_queue` with lambda functions

  ```cpp
  auto compare = [](const Node a, const Node b){
    // comparison here
    return a->val > b->val;
  };
  
  priority_queue<Node, vector<Node>, decltype(compare)> pq;

  ```

### SQL

- In MYSQL `OFFSET` can be written as

  ```sql
  SELECT * FROM table_name
  LIMIT offset_val, limit_val
  ```

- In MYSQL to set a variable to new value use `SET`

  ```sql
  CREATE FUNCTION foo(N INT) RETURNS INT
  BEGIN
  SET N = N - 1;
  RETURN (
    # Your function here
  );
  END
  ```
  
[^1]: source: [GFG](https://www.geeksforgeeks.org/fast-io-for-competitive-programming/)
