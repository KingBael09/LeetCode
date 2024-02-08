pub fn find_length_of_lcis(nums: Vec<i32>) -> i32 {
    let mut max_len: i32 = 0;
    let mut cur_len: i32 = 0;
    let mut prev = i32::MIN;

    for n in nums {
        if n > prev {
            cur_len += 1;
        } else {
            max_len = max_len.max(cur_len);
            cur_len = 1;
        }
        prev = n;
    }

    max_len.max(cur_len)
}

fn main() {
    find_length_of_lcis([1, 3, 5, 7].to_vec());
}
