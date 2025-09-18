use std::error::Error;
use std::fs;

fn main() -> Result<(), Box<dyn Error>> {
    let message: String = fs::read_to_string("../inputs/day7_input.txt")?;
    println!("{}", message);

    Ok(())
}
