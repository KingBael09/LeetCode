// ? 2623. Memoize
// ? https://leetcode.com/problems/memoize/description/

type Fn = (...params: number[]) => number;

type Cache = Record<string, number>;

function memoize(fn: Fn): Fn {
  const cache: Cache = {};

  return function (...args): number {
    const key = JSON.stringify(args);

    if (key in cache) {
      return cache[key] as number;
    }

    const result = fn(...args);
    cache[key] = result;

    return result;
  };
}

function memoizeBetter(fn: Fn): Fn {
  const cache = new Map();

  return function (...args): number {
    const key = JSON.stringify(args);

    if (cache.has(key)) {
      return cache.get(key);
    }

    const result = fn(...args);
    cache.set(key, result);

    return result;
  };
}
