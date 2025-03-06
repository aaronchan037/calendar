// 打印欢迎信息
pub fn print_welcome(program_name: &str) {
    println!("Calendar Generator");
    println!("====================================");
    println!("Welcome to {}, we are glad to have you here!", program_name);
    println!();
    println!("This program generates a calendar for the specified year.");
    println!();
    println!("Type '{} --help' for more information.", program_name);
}

// 打印帮助信息
pub fn print_help(program_name: &str, version: &str, build_date: &str) {
    println!("Calendar Generator {} ({} build)", version, build_date);
    println!("====================================");
    println!("Usage:");
    println!("  {} [OPTIONS] <COMMAND>", program_name);
    println!("Options:");
    println!("  --output, -o   \t\t Output a calendar for the specified");
    println!("      <default>  \t\t default output a calendar for this year");
    println!("        year     \t\t for a year");
    println!("        month    \t\t for a month");
    println!("  --help, -h     \t\t Print this help documentation");
    println!("  --version, -V  \t\t Print the version");
    println!("Commands:");
    println!("  <year>         \t\t Generate a calendar for the specified year");
    println!("  <year>-<month> \t\t Generate a calendar for the specified month");
    println!("Example: {} 2022", program_name);
    println!("Help:");
    println!("  - The year should be an integer between 1970 and 65535.");
}

// 打印版本信息
pub fn print_version(program_name: &str, version: &str, build_date: &str) {
    println!("{} version: {} ({} build)", program_name, version, build_date);
}
