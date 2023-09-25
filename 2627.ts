// ? 2627. Debounce
// ? https://leetcode.com/problems/debounce/description/

type F = (...args: any[]) => void;

type TimerId = ReturnType<typeof setTimeout>;

function debounce(fn: F, t: number): F {
  let id: TimerId;
  return function (...args) {
    clearInterval(id);
    id = setTimeout(() => fn(...args), t);
  };
}

const log = debounce(console.log, 1000);
log("Hello"); // cancelled
log("Hello"); // cancelled
log("Hello"); // Logged at t=1000ms
