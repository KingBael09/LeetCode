// ? 2721. Execute Asynchronous Functions in Parallel
// ? https://leetcode.com/problems/execute-asynchronous-functions-in-parallel/description/

type Fn<T> = () => Promise<T>;

function promiseAll<T>(functions: Fn<T>[]): Promise<T[]> {
  return new Promise((resolve, reject) => {
    const resolved = Array<T>(functions.length);
    let count = 0; // this counts resolved count
    functions.forEach(async (func, i) => {
      try {
        const curr = await func();
        count++;
        resolved[i] = curr; //otherwise order can change
        if (count == functions.length) {
          resolve(resolved);
        }
      } catch (error) {
        reject(error);
      }
    });
  });
}

// const promise = promiseAll([
//   () => new Promise((resolve) => setTimeout(() => resolve(1), 200)),
//   () =>
//     new Promise((resolve, reject) => setTimeout(() => reject("Error"), 100)),
// ]);
// const promise = promiseAll([() => new Promise((res) => res(42))]);
const promise = promiseAll([
  () => new Promise((resolve) => setTimeout(() => resolve(4), 50)),
  () => new Promise((resolve) => setTimeout(() => resolve(10), 150)),
  () => new Promise((resolve) => setTimeout(() => resolve(16), 100)),
]);
promise.then(console.log); // [42]
