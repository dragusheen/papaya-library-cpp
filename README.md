# Papaya Library 🍉📚

Papaya is a lightweight C++ library designed for managing and manipulating structured data in a simple and efficient manner. The library allows users to create, update, and query data stored in a custom format, providing a range of functionalities to handle key-value pairs and rows of data.

<br>
<br>

# Summary ✨

- [Features](#-features): Learn about the key features of the Papaya Library.
- [Installation](#-installation): Find instructions on how to install and build the library.
- [Usage](#-usage): Explore examples and code snippets to get started with Papaya.
- [Documentation](#-documentation): Dive into detailed documentation of the Papaya class and its methods.
- [Contributing](#-contributing): Contribute to the development of Papaya by submitting enhancements or bug fixes.
- [License](#-license): Understand the terms of use and licensing for the Papaya Library.
- [Authors](#-authors): Meet the creators behind Papaya.

Feel free to click on any section to jump directly to the relevant information!


<br>
<br>

## 🌟 Features

- Add, remove, and update data entries 📝
- Manage keys and rows of data 🗝️
- Save and load data from a file 💾
- Exception handling for error management 🚨

<br>
<br>

## 💻 Installation

To build the Papaya library, you can use the provided Makefile. Ensure you have `g++` installed on your system.

1. Clone the repository:
```bash
git clone https://github.com/yourusername/papaya-library.git
```

```bash
cd papaya-library
```

<br>

2. Build the library:
```bash
make
```

This will create a static library named `libpapaya.a`.

<br>
<br>

## 🚀 Usage

Include the Papaya header in your project and link against the `libpapaya.a` library.

### Example

```cpp
#include "Papaya.hpp"
#include <iostream>

int main() {
    try {
        // Initialize Papaya with a path, name, and keys
        Papaya papaya("path/to", "example", {"id", "name", "value"});

        // Add data
        papaya.addLine({"1", "Apple", "100"});
        papaya.addLine({"2", "Banana", "200"});

        // Update data
        papaya.updateData("id", "1", "value", "150");

        // View data
        papaya.view();

        // Save data to file
        papaya.save();

    } catch (const Papaya::PapayaError &e) {
        e.read();
    }

    return 0;
}
```

<br>

Compile and run the example:
```bash
g++ -o example example.cpp -I./include -L./ -lpapaya
```

```bash
./example
```

<br>
<br>

## 📖 Documentation

### Papaya Class

#### Constructors

- `Papaya(std::string path, std::string name, std::vector<std::string> keys)`
  - Constructs a new Papaya object with a specified path, name, and keys.
  - **Parameters:**
    - `path` - The path to the papaya file.
    - `name` - The name of the papaya file.
    - `keys` - The keys of the papaya.
  - **Example:**
    ```cpp
    Papaya papaya("path/to", "example", {"id", "name", "value"});
    ```

<br>

- `Papaya(std::string path, std::string name)`
  - Constructs a Papaya object to open an existing file.
  - **Parameters:**
    - `path` - The path to the papaya file.
    - `name` - The name of the papaya file.
  - **Example:**
    ```cpp
    Papaya papaya("path/to", "example");
    ```

<br>
<br>

#### Public Methods

- `bool hasData(const std::string &refKey, const std::string &refValue, const std::string &key) const`
  - Checks if the papaya has a specific data.
  - **Parameters:**
    - `refKey` - The reference key.
    - `refValue` - The reference value.
    - `key` - The key to check.
  - **Returns:**
    - `true` if the data exists and isn't empty, `false` otherwise.
  - **Example:**
    ```cpp
    bool exists = papaya.hasData("id", "1", "name");
    ```

<br>

- `bool hasLine(const std::string &refKey, const std::string &refValue) const`
  - Checks if the papaya has a specific line.
  - **Parameters:**
    - `refKey` - The reference key.
    - `refValue` - The reference value.
  - **Returns:**
    - `true` if the line exists, `false` otherwise.
  - **Example:**
    ```cpp
    bool lineExists = papaya.hasLine("id", "1");
    ```

<br>

- `bool hasKey(const std::string &key) const`
  - Checks if the papaya has a specific key.
  - **Parameters:**
    - `key` - The key to check.
  - **Returns:**
    - `true` if the key exists, `false` otherwise.
  - **Example:**
    ```cpp
    bool keyExists = papaya.hasKey("name");
    ```

<br>

- `std::vector<std::string> getKeys() const`
  - Gets the keys of the papaya.
  - **Returns:**
    - A vector of strings representing the keys.
  - **Example:**
    ```cpp
    std::vector<std::string> keys = papaya.getKeys();
    ```

<br>

- `std::vector<std::unordered_map<std::string, std::string>> getDatas() const`
  - Gets the data of the papaya.
  - **Returns:**
    - A vector of unordered maps, each representing a row of data.
  - **Example:**
    ```cpp
    auto datas = papaya.getDatas();
    ```

<br>

- `std::vector<std::string> getLine(const std::string &key, const std::string &value) const`
  - Gets a specific line of the papaya.
  - **Parameters:**
    - `key` - The key to check.
    - `value` - The value to check.
  - **Returns:**
    - A vector of strings representing the line.
  - **Example:**
    ```cpp
    auto line = papaya.getLine("id", "1");
    ```

<br>

- `std::string getData(const std::string &refKey, const std::string &refValue, const std::string &key) const`
  - Gets a specific data of the papaya.
  - **Parameters:**
    - `refKey` - The reference key.
    - `refValue` - The reference value.
    - `key` - The key to check.
  - **Returns:**
    - A string representing the data.
  - **Example:**
    ```cpp
    std::string data = papaya.getData("id", "1", "name");
    ```

<br>

- `std::vector<std::string> getKey(const std::string &key) const`
  - Gets a specific key of the papaya.
  - **Parameters:**
    - `key` - The key to check.
  - **Returns:**
    - A vector of strings representing the key.
  - **Example:**
    ```cpp
    auto keyValues = papaya.getKey("name");
    ```

<br>

- `void addData(const std::string &key, const std::string &value)`
  - Adds a new data to the papaya.
  - **Parameters:**
    - `key` - The key of the data.
    - `value` - The value of the data.
  - **Example:**
    ```cpp
    papaya.addData("name", "Orange");
    ```

<br>

- `void addKey(const std::string &key)`
  - Adds a new key to the papaya.
  - **Parameters:**
    - `key` - The key to add.
  - **Example:**
    ```cpp
    papaya.addKey("color");
    ```

<br>

- `void addNewLine()`
  - Adds a new line to the papaya.
  - **Example:**
    ```cpp
    papaya.addNewLine();
    ```

<br>

- `void addLine(const std::vector<std::string> &data)`
  - Adds a new line to the papaya.
  - **Parameters:**
    - `data` - The data of the line.
  - **Example:**
    ```cpp
    papaya.addLine({"3", "Grapes", "300"});
    ```

<br>

- `void clear()`
  - Clears the content of the papaya.
  - **Example:**
    ```cpp
    papaya.clear();
    ```

<br>

- `void destroy()`
  - Destroys the papaya.
  - **Warning:** This function will remove the papaya.
  - **Example:**
    ```cpp
    papaya.destroy();
    ```

<br>

- `void removeData(const std::string &refKey, const std::string &refValue, const std::string &key)`
  - Removes a specific data from the papaya.
  - **Parameters:**
    - `refKey` - The reference key.
    - `refValue` - The reference value.
    - `key` - The key to remove.
  - **Example:**
    ```cpp
    papaya.removeData("id", "1", "value");
    ```

<br>

- `void removeKey(const std::string &key)`
  - Removes a specific key from the papaya.
  - **Parameters:**
    - `key` - The key to remove.
  - **Example:**
    ```cpp
    papaya.removeKey("color");
    ```

<br>

- `void removeLine(const std::string &refKey, const std::string &refValue)`
  - Removes a specific line from the papaya.
  - **Parameters:**
    - `refKey` - The reference key.
    - `refValue` - The reference value.
  - **Example:**
    ```cpp
    papaya.removeLine("id", "2");
    ```

<br>

- `void updateData(const std::string &refKey, const std::string &refValue, const std::string &key, const std::string &value)`
  - Updates a specific data from the papaya.
  - **Parameters:**
    - `refKey` - The reference key.
    - `refValue` - The reference value.
    - `key` - The key to update.
    - `value` - The value to update.
  - **Example:**
    ```cpp
    papaya.updateData("id", "2", "value", "250");
    ```

<br>

- `void updateKey(const std::string &refKey, const std::string &newKey)`
  - Updates a specific key from the papaya.
  - **Parameters:**
    - `refKey` - The reference key.
    - `newKey` - The new key.
  - **Example:**
    ```cpp
    papaya.updateKey("color", "shade");
    ```

<br>

- `void updateLine(const std::string &refKey, const std::string &refValue, const std::vector<std::string> &data)`
  - Updates a specific line from the papaya.
  - **Parameters:**
    - `refKey` - The reference key.
    - `refValue` - The reference value.
    - `data` - The data to update.
  - **Example:**
    ```cpp
    papaya.updateLine("id", "1", {"1", "Apple", "150"});
    ```

<br>

- `void save() const`
  - Saves the papaya to a `.papaya` file.
  - **Example:**
    ```cpp
    papaya.save();
    ```

<br>

- `void view() const`
  - Views the content of the papaya.
  - **Example:**
    ```cpp
    papaya.view();
    ```

<br>
<br>

### PapayaError Class

#### Constructors

- `PapayaError(std::string const &what, std::string const &where = "Unknown")`
  - Constructs a new PapayaError object.
  - **Parameters:**
    - `what` - The error message.
    - `where` - The error location (default: "Unknown").

<br>
<br>

#### Public Methods

- `const char *what() const noexcept override`
  - Gets the error message.
  - **Returns:**
    - The error message.
  - **Example:**
    ```cpp
    try {
        // Code that might throw a PapayaError
    } catch (const Papaya::PapayaError &e) {
        std::cerr << e.what() << std::endl;
    }
    ```

<br>

- `const char *where() const noexcept`
  - Gets the error location.
  - **Returns:**
    - The error location.
  - **Example:**
    ```cpp
    try {
        // Code that might throw a PapayaError
    } catch (const Papaya::PapayaError &e) {
        std::cerr << e.where() << std::endl;
    }
    ```

<br>

- `void read() const noexcept`
  - Reads the error message.
  - **Example:**
    ```cpp
    try {
        // Code that might throw a PapayaError
    } catch (const Papaya::PapayaError &e) {
        e.read();
    }
    ```

<br>
<br>

## 💖 Contributing

Contributions are welcome! Please fork the repository and submit a pull request for any enhancements or bug fixes.

<br>
<br>

## 📜 License

This library is free to use, modify, and distribute. The only requirement is to give credit to the original author in any commercial or public use.

The author is not responsible for any issues or problems that may arise from using this library. As a small developer, errors may occur. If you find any errors or problems, please inform me so I can address them.

<br>
<br>

## 👨‍💻 Authors

- [dragusheen](https://github.com/dragusheen) - Initial work