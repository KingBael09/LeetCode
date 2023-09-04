# LeetCode Solutions

This is my leetcode solutions

---

## Findings

- Deque is faster than Queue in CPP.

- This speeds up execution by disabling sync between C & C++ stream.

```cpp
ios_base::sync_with_stdio(false);
```

- This unties `cin` from `cout` and speeds up execution.

```cpp
cin.tie(NULL);
```

- In vectors `ans.emplace_back(val)` is faster than `ans.push_back(val)` but it takes more memory, `emplace_back` constructs the object to insert this is useful when the object is expensive to copy, `push_back` should be used when the object which has to be inserted is cheap to copy or you already have the copy of the object.
