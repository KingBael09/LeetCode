// ? 2625. Flatten Deeply Nested Array
// ? https://leetcode.com/problems/flatten-deeply-nested-array/description/

type MultiDimensionalArray = (number | MultiDimensionalArray)[];

function flattenArray(arr: MultiDimensionalArray, n: number): Array<number> {
  const finalArray: Array<number> = [];

  function flatten(arr: MultiDimensionalArray, depth: number) {
    arr.forEach((item) => {
      if (Array.isArray(item) && depth < n) {
        flatten(item, depth + 1);
      } else {
        finalArray.push(item as number);
      }
    });
  }

  flatten(arr, 0);

  return finalArray;
}

console.log(
  flattenArray([1, 2, 3, [4, 5, 6], [7, 8, [9, 10, 11], 12], [13, 14, 15]], 1)
);
