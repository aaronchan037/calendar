fn main() {
    let head = [
        "       January        Su Mo Tu We Th Fr Sa",
        "      February        Su Mo Tu We Th Fr Sa",
        "        March         Su Mo Tu We Th Fr Sa",
        "        April         Su Mo Tu We Th Fr Sa",
        "         May          Su Mo Tu We Th Fr Sa",
        "        June          Su Mo Tu We Th Fr Sa",
        "        July          Su Mo Tu We Th Fr Sa",
        "       August         Su Mo Tu We Th Fr Sa",
        "      September       Su Mo Tu We Th Fr Sa",
        "       October        Su Mo Tu We Th Fr Sa",
        "      November        Su Mo Tu We Th Fr Sa",
        "      December        Su Mo Tu We Th Fr Sa",
    ];

    // 复制头部信息
    for month in 0..=12 {
        let head_str = head[(month) as usize];
        for (i, c) in head_str.chars().enumerate() {
            // output[0][i] = c;
            println!("{}, {}", i, c);
        }
    }
}
