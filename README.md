# LeetCode Solutions

This is my leetcode solutions

---

## Findings

- Deque is faster than Queue in CPP

```cpp
ios_base::sync_with_stdio(false);
```

- This speeds up execution by disabling sync between C & C++ stream

```cpp
cin.tie(NULL);
```

- This unties `cin` from `cout` and speeds up execution

- In vectors `ans.emplace_back(val)` is faster than `ans.push_back(val)`
