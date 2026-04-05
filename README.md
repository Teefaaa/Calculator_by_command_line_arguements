# Calculator_by_command_line_arguements
This is the first project implemented indvidually as part of CSE231s-Computer Programming course at Faculty of Engineering - Ain Shams University Fall 25



# Command-Line Calculator in C++
> **Phases:**  
> Phase 1 – Real Numbers  
> Phase 2 – Complex Numbers

---

## 🚩 Project Overview

This multi-phase command-line calculator, written in C++, can perform basic arithmetic operations on real numbers (Phase 1) and extends to complex numbers using a custom `Complex` class (Phase 2). All input is taken via command line arguments—no interactive input is used.

---

## Phase 1 – Real Number Calculator

### 📖 Description

- Perform arithmetic operations:
  - Addition (`add`)
  - Subtraction (`sub`)
  - Multiplication (`mul`)
  - Division (`div`)
  - Power (`pow`)
- All inputs are provided as command-line arguments.
- Validates input arguments and operation types.
- Handles errors with clear, precise output.

### 🔧 Compilation

```bash
g++ -std=c++17 main.cpp -o calc
```

### ▶️ Usage

```bash
./calc <operation> <operand1> <operand2>
# Example:
./calc add 2 3
# Output:
5.000000
```

### 🎯 Supported Operations

| Operation | Description                    | Example Command           | Output         |
|-----------|--------------------------------|--------------------------|--------------- |
| add       | Addition                       | ./calc add 2 3           | 5.000000       |
| sub       | Subtraction                    | ./calc sub 5.5 2.25      | 3.250000       |
| mul       | Multiplication                 | ./calc mul -3 7          | -21.000000     |
| div       | Division                       | ./calc div 10 4          | 2.500000       |
| pow       | Exponentiation (base ^ exp)    | ./calc pow 2.5 2         | 6.250000       |

### 📝 Input Rules

- Operands can be integers (`5`, `-3`), floating-point (`2.5`, `-1.75`), or scientific notation (`1e3`, `-2e-4`).
- Strict output formatting: One line, **six decimal places**, no extra spaces.
- Precise error messages:
    - `ERROR: Invalid arguments`
    - `ERROR: Unknown operation`
    - `ERROR: Division by zero`
    - `ERROR: Invalid result`

### ✅ Phase 1 Test Cases

| # | Command | Expected Output |
|---|---------|-----------------|
| 1 | `./calc add 2 3` | `5.000000` |
| 2 | `./calc sub 5.5 2.25` | `3.250000` |
| 3 | `./calc mul -3 7` | `-21.000000` |
| 4 | `./calc div 10 4` | `2.500000` |
| 5 | `./calc div 5 0` | `ERROR: Division by zero` |
| 6 | `./calc pow 2 10` | `1024.000000` |
| 7 | `./calc pow 2.5 2` | `6.250000` |
| 8 | `./calc pow -2 3` | `-8.000000` |
| 9 | `./calc pow -2 0.5` | `ERROR: Invalid result` |
| 10 | `./calc mul 1000000000 3` | `3000000000.000000` |
| 11 | `./calc sub 0 0` | `0.000000` |
| 12 | `./calc mod 3 2` | `ERROR: Unknown operation` |
| 13 | `./calc add 5` | `ERROR: Invalid arguments` |
| 14 | `./calc add two 3` | `ERROR: Invalid arguments` |

---

## Phase 2 – Complex Number Calculator

### 📖 Description

Extends the calculator to support complex numbers and implements all operations with a `Complex` class.

- **Complex Format:**  
  Must be `a+bi` or `a-bi`, with no spaces and both parts always present (e.g., `-2.5+3i`, `4-1i`)
- **Supported Operations:**
    - `add` (addition)
    - `sub` (subtraction)
    - `mul` (multiplication)
    - `div` (division; handles division by zero)
    - `magnitude` (absolute value; prints real number)

### 🔧 Compilation

```bash
g++ -std=c++17 main.cpp Complex.cpp -o calc
```

### ▶️ Usage

**Two-argument operations (return a complex number):**

```bash
./calc <operation> <complex1> <complex2>
```

- Example:  
  `./calc add 3+4i 1+2i`  
  Output: `4.000000+6.000000i`

**Magnitude (single complex number, returns real):**

```bash
./calc magnitude <complex>
```

- Example:  
  `./calc magnitude 3+4i`  
  Output: `5.000000`

### 📤 Output Format

- **Complex results:** `a+bi` or `a-bi` with exactly six decimal places, and no spaces.
- **Always show the sign** (`+` or `-`) of the imaginary part.
- **Always include the trailing `i`**
- **Real results** (from `magnitude`): single line, six decimal places.

Examples:
- `3.000000+4.500000i`
- `2.000000-1.750000i`
- `5.000000` (magnitude)

### ⚠️ Error Handling

- `ERROR: Invalid arguments`
- `ERROR: Invalid complex number`
- `ERROR: Unknown operation`
- `ERROR: Division by zero`


### 👩‍💻 The `Complex` Class (Phase 2)

**Private members:**
```cpp
double real;
double imag;
```

**Public methods:**
```cpp
Complex();                                    // Default constructor
Complex(double r, double i);                  // Parameterized constructor
Complex add(const Complex& other);            // Addition
Complex sub(const Complex& other);            // Subtraction
Complex mul(const Complex& other);            // Multiplication
Complex div(const Complex& other);            // Division
double magnitude() const;                     // Magnitude: sqrt(real² + imag²)
double get_real() const;                      // Get real part
double get_imag() const;                      // Get imaginary part
```

### ✅ Phase 2 Test Cases

| # | Command | Expected Output |
|---|---------|-----------------|
| 1 | `./calc add 3+4i 1+2i` | `4.000000+6.000000i` |
| 2 | `./calc sub 5+3i 2+7i` | `3.000000-4.000000i` |
| 3 | `./calc mul 3+2i 1+4i` | `-5.000000+14.000000i` |
| 4 | `./calc div 4+2i 3-1i` | `1.000000+1.000000i` |
| 5 | `./calc magnitude 3+4i` | `5.000000` |
| 6 | `./calc add -2-3i 4-1i` | `2.000000-4.000000i` |
| 7 | `./calc div 3+2i 0+0i` | `ERROR: Division by zero` |
| 8 | `./calc add 3+4 1+i` | `ERROR: Invalid complex number` |
| 9 | `./calc mod 1+1i 2+2i` | `ERROR: Unknown operation` |
| 10 | `./calc add 3+4i` | `ERROR: Invalid arguments` |

---


## 🧑‍💻 Example Commands & Outputs

### Phase 1 Examples

```bash
./calc add 2 3
5.000000

./calc sub 5.5 2.25
3.250000

./calc mul -3 7
-21.000000

./calc div 10 4
2.500000

./calc div 10 0
ERROR: Division by zero

./calc pow 2 10
1024.000000

./calc pow -2 0.5
ERROR: Invalid result

./calc add two 3
ERROR: Invalid arguments
```

### Phase 2 Examples

```bash
./calc add 3+4i 1+2i
4.000000+6.000000i

./calc sub 5+3i 2+7i
3.000000-4.000000i

./calc mul 3+2i 1+4i
-5.000000+14.000000i

./calc div 4+2i 3-1i
1.000000+1.000000i

./calc magnitude 3+4i
5.000000

./calc add -2-3i 4-1i
2.000000-4.000000i

./calc div 3+2i 0+0i
ERROR: Division by zero

./calc add 3+4 1+i
ERROR: Invalid complex number

./calc add 3+4i
ERROR: Invalid arguments
```

---

## 📋 Development Notes

- ✅ All input is via command-line; no interactive prompts
- ✅ Output must match autograder expectations **exactly**
- ✅ Handle all edge cases gracefully
- ✅ Use `std::stod()` for parsing operands
- ✅ Use `isinf()` and `isnan()` to validate results
- ✅ Format output with `fixed` and `setprecision(6)`
- ✅ No extra spaces in complex number output

---

## 🛠️ Building & Running

### Build Phase 1
```bash
g++ -std=c++17 main.cpp -o calc
```

### Build Phase 2
```bash
g++ -std=c++17 main.cpp Complex.cpp -o calc
```

### Run
```bash
./calc add 2 3
./calc magnitude 3+4i
```

### Windows
```bash
g++ -std=c++17 main.cpp Complex.cpp -o calc.exe
calc.exe add 2 3
```

---

## 📝 License

This project is for educational purposes.

---

**Created:** 2026-04-05  
**Author:** Teefaaa  
**Repository:** [Teefaaa/Calculator_by_command_line_arguements](https://github.com/Teefaaa/Calculator_by_command_line_arguements)



