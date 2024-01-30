use std::cmp::Ordering;

pub fn can_complete_circuit(gas: Vec<i32>, cost: Vec<i32>) -> i32 {
    let n = gas.len();

    let (mut total_gas, mut total_cost) = (0, 0);
    let (mut curr_gas, mut x_pos) = (0, 0);

    for i in 0..n {
        total_gas += gas[i];
        total_cost += cost[i];

        curr_gas += gas[i] - cost[i];

        if curr_gas < 0 {
            x_pos = (i + 1) as i32;
            curr_gas = 0;
        }
    }

    match total_gas.cmp(&total_cost) {
        Ordering::Less => -1,
        _ => x_pos,
    }
}

pub fn can_complete_circuit_other(gas: Vec<i32>, cost: Vec<i32>) -> i32 {
    let x = gas
        .into_iter()
        .zip(cost)
        .map(|(g, c)| c - g)
        .enumerate()
        .fold(
            (0, 0, 0),
            |(total_gas, current_gas, x_pos), (i, resource)| match current_gas.cmp(&resource) {
                Ordering::Less => (total_gas - resource, 0, i + 1),
                _ => (total_gas - resource, current_gas - resource, x_pos),
            },
        );

    match x {
        (total, _, x_pos) if total >= 0 => x_pos as i32,
        _ => -1,
    }
}

fn main() {}
