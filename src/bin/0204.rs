pub fn count_primes(n: i32) -> i32 {
    let n = n as usize;

    let mut not_prime = vec![false; n];

    (2..n).for_each(|i| {
        if !not_prime[i] {
            (2..)
                .take_while(|j| i * j < n)
                .for_each(|j| not_prime[i * j] = true);
        }
    });

    not_prime.into_iter().skip(2).filter(|&np| !np).count() as i32
}

fn main() {}
