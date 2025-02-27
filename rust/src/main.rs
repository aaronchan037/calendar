// 导入所需的标准库模块
use std::env;
use std::process;

mod date;
mod info;

fn main() {
    let version = "v0.2";
    let build_date = "2022.3.14";

    // 获取命令行参数
    let args: Vec<String> = env::args().collect();
    let prog_name = &args[0];

    // 特定参数处理
    for arg in args.iter().skip(1) {
        if arg == "--help" || arg == "-h" {
            info::print_help(prog_name, version, build_date);
            process::exit(0);
        } else if arg == "--version" || arg == "-V" {
            info::print_version(prog_name, version, build_date);
            process::exit(0);
        }
    }

    // 没有参数时打印欢迎信息
    if args.len() != 2 {
        info::print_welcome(prog_name);
        process::exit(0);
    }

    // 生成日历
    let year_str = &args[1];
    let year: i32 = match year_str.parse() {
        Ok(num) => num,
        Err(_) => {
            eprintln!("Year must be a valid integer.");
            process::exit(1);
        }
    };

    // 年份范围限制
    if year < 1970 || year > 65535 {
        eprintln!("Year must be between 1970 and 65535.");
        process::exit(1);
    }

    for i in 0..4 {
        let mut a = [[' '; 21]; 8];
        let mut b = [[' '; 21]; 8];
        let mut c = [[' '; 21]; 8];

        date::generate_month_layout(year, 3 * i + 1, &mut a);
        date::generate_month_layout(year, 3 * i + 2, &mut b);
        date::generate_month_layout(year, 3 * i + 3, &mut c);

        for j in 0..8 {
            let row_a: String = a[j].iter().collect();
            let row_b: String = b[j].iter().collect();
            let row_c: String = c[j].iter().collect();
            println!("{a}{b}{c}", row_a, " ", row_b, " ", row_c);
        }
    }
}