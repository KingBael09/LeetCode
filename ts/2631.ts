// ? 2631. Group By
// ? https://leetcode.com/problems/group-by/description

declare global {
  interface Array<T> {
    groupBy(fn: (item: T) => string): Record<string, Array<T>>;
    betterGroupBy(fn: (item: T) => string): Record<string, Array<T>>;
  }
}

Array.prototype.groupBy = function <T>(fn: (item: T) => string) {
  const group: Record<string, Array<T>> = {};

  this.forEach((item) => {
    const key = fn(item);

    if (group[key]) {
      group[key]?.push(item);
    } else {
      group[key] = [item];
    }
  });

  return group;
};

Array.prototype.betterGroupBy = function <T>(fn: (item: T) => string) {
  return this.reduce<Record<string, Array<T>>>((group, item) => {
    const key = fn(item);

    if (!(key in group)) {
      group[key] = [];
    }

    group[key]?.push(item);

    return group;
  }, {});
};

console.log([1, 2, 3].betterGroupBy(String));
