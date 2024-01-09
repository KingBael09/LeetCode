// ? 2723. Add Two Promises
// ? https://leetcode.com/problems/add-two-promises/description/

type P = Promise<number>;

async function addTwoPromises(promise1: P, promise2: P): P {
  //   const [one, two] = await Promise.all([promise1, promise2]);

  const total = (await Promise.all([promise1, promise2])).reduce(
    (acc, val) => acc + val,
    0
  );

  return total;
}

addTwoPromises(Promise.resolve(3), Promise.resolve(2)).then(console.log);
