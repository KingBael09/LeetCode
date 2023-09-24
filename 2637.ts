// ? 2637. Promise Time Limit
// ? https://leetcode.com/problems/promise-time-limit/description/

type Fn = (...params: any[]) => Promise<any>;

function timeLimit(fn: Fn, t: number): Fn {
  return async function (...args) {
    const orignalFn = fn(...args);

    const timerFn = new Promise((_, reject) => {
      setTimeout(() => {
        reject("Time Limit Exceeded");
      }, t);
    });

    return Promise.race([orignalFn, timerFn]);
  };
}

function timeLimitBasic(fn: Fn, t: number): Fn {
  return async function (...args) {
    return new Promise((resolve, reject) => {
      const id = setTimeout(reject, t, "Time Limit Exceeded");
      fn(...args)
        .then(resolve)
        .catch(reject)
        .finally(() => clearInterval(id));
    });
  };
}

const limited = timeLimit((t) => new Promise((res) => setTimeout(res, t)), 100);
limited(150).catch(console.log); // "Time Limit Exceeded" at t=100ms
