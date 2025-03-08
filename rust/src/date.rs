// 获取月份的起始日期偏移
pub fn get_month_beginning(year: u16, month: u16) -> i64 {
    let a = (14 - month) / 12;
    let y = year + 4800 - a;
    let m = month + 12 * a - 3;
    ((153 * m + 2) / 5) as i64 + 365 * y as i64 + (y / 4) as i64 - (y / 100) as i64
        + (y / 400) as i64
        - 32044
}

// 生成月份布局
pub fn generate_month_layout(year: i32, month: i32, output: &mut [[char; 21]; 8]) {
    // 对输入的年份和月份进行有效性分析
    assert!(month >= 1 && month <= 12);
    assert!(year >= 1970 && year <= 65535);

    // 月份头部
    let head: [&str; 12] = [
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
    // 日期主体
    let body = "  1  2  3  4  5  6  7  8  9 10 11 12 13 14 15 16 17 18 19 20 21 22 23 24 25 26 27 28 29 30 31";

    // 复制头部信息
    let head_str = head[(month - 1) as usize];
    for (i, c) in head_str.chars().enumerate() {
        // output[0][i] = c;
        println!("{}, {}", i, c);
    }

    let this_month_beg = get_month_beginning(year as u16, month as u16);
    let next_month_beg = get_month_beginning(
        year as u16 + if month == 12 { 1 } else { 0 },
        (month % 12 + 1) as u16,
    );
    let month_length = next_month_beg - this_month_beg;
    let head_length = (this_month_beg + 1) % 7;
    let _tail_length = 126 - 3 * (head_length + month_length);

    // 填充前面的空格
    for i in 0..(3 * head_length) as usize {
        output[2][i] = ' ';
    }
    // 复制日期内容信息
    for (i, c) in body.chars().take((3 * month_length) as usize).enumerate() {
        output[2][(3 * head_length) as usize + i] = c;
    }
    // 填充后面的空格
    for i in (3 * (head_length + month_length)) as usize..126 {
        output[2][i] = ' ';
    }
}
