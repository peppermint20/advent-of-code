
import re


def parse_instruction(instruction):
    if "->" in instruction:
        parts = instruction.split("->")
        output = parts[1].strip()
        rest = parts[0].strip()
        if "AND" in rest:
            a, b = rest.split(" AND ")
            return ('AND', a.strip(), b.strip(), output)
        elif "OR" in rest:
            a, b = rest.split(" OR ")
            return ('OR', a.strip(), b.strip(), output)
        elif "LSHIFT" in rest:
            a, b = rest.split(" LSHIFT ")
            return ('LSHIFT', a.strip(), int(b), output)
        elif "RSHIFT" in rest:
            a, b = rest.split(" RSHIFT ")
            return ('RSHIFT', a.strip(), int(b), output)
        elif "NOT" in rest:
            a = rest.split("NOT ")[1].strip()
            return ('NOT', a, output)
        else:
            return ('ASSIGN', rest, output)
    return None


def evaluate_wire(wires, instructions, wire):
    if wire.isdigit():
        return int(wire)
    if wire in wires:
        return wires[wire]

    # Evaluate based on the type of instruction
    inst = instructions[wire]
    if inst[0] == 'ASSIGN':
        result = evaluate_wire(wires, instructions, inst[1])
    elif inst[0] == 'AND':
        result = evaluate_wire(wires, instructions, inst[1]) & evaluate_wire(
            wires, instructions, inst[2])
    elif inst[0] == 'OR':
        result = evaluate_wire(wires, instructions, inst[1]) | evaluate_wire(
            wires, instructions, inst[2])
    elif inst[0] == 'LSHIFT':
        result = evaluate_wire(wires, instructions, inst[1]) << inst[2]
    elif inst[0] == 'RSHIFT':
        result = evaluate_wire(wires, instructions, inst[1]) >> inst[2]
    elif inst[0] == 'NOT':
        result = ~evaluate_wire(wires, instructions, inst[1]) & 0xFFFF
    else:
        raise ValueError("Unknown instruction")

    wires[wire] = result
    return result


# Read input instructions
instructions = {}
with open('input.txt') as f:
    for line in f:
        parsed = parse_instruction(line.strip())
        if parsed:
            instructions[parsed[2]] = parsed

# Find the value of wire 'a'
wires = {}
result = evaluate_wire(wires, instructions, 'a')
print(f"The signal on wire 'a' is {result}")
