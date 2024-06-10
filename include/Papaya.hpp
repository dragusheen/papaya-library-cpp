/*
** EPITECH PROJECT, 2024
** papaya-library
** File description:
** library
*/

#ifndef PAPAYA_H_
    #define PAPAYA_H_

#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <fstream>
#include <unordered_map>
#include <exception>
#include <algorithm>

/**
 * @brief Papaya class
 *
 * This class is used to handle a papaya
*/
class Papaya
{
    public:
        /**
         * @brief PapayaError class
         *
         * This class is used to handle errors in the Papaya class
        */
        class PapayaError: public std::exception
        {
            public:
                /**
                 * @brief Construct a new PapayaError object
                 *
                 * @param what The error message
                 * @param where The error location (default: "Unknown")
                */
                PapayaError(std::string const &what, std::string const &where = "Unknown");

                /**
                 * @brief Get the error message
                 *
                 * @return `const char *` The error message
                */
                const char *what() const noexcept override;

                /**
                 * @brief Get the error location
                 *
                 * @return `const char *` The error location
                */
                const char *where() const noexcept;

                /**
                 * @brief Read the error message
                */
                void read() const noexcept;

            private:
                /**
                 * @brief The error message
                */
                std::string _what;

                /**
                 * @brief The error location
                */
                std::string _where;
        };

        /**
         * @brief Construct a Papaya object
         *
         * @param path The path to the papaya file
         * @param name The name of the papaya file
         * @param keys The keys of the papaya
         *
         * @warning This constructor is used to create a new papaya
        */
        Papaya(std::string path, std::string name, std::vector<std::string> keys);

        /**
         * @brief Construct a Papaya object
         *
         * @param path The path to the papaya file
         * @param name The name of the papaya file
         *
         * @warning This constructor is used to open an existing papaya
        */
        Papaya(std::string path, std::string name);
        ~Papaya() = default;

        /**
         * @brief Check if the papaya has a specific data
         *
         * @param refKey The reference key
         * @param refValue The reference value
         * @param key The key to check
         *
         * @return `bool` True if the data exists isn't empty, false otherwise
        */
        bool hasData(const std::string &refKey, const std::string &refValue, const std::string &key) const;

        /**
         * @brief Check if the papaya has a specific line
         *
         * @param refKey The reference key
         * @param refValue The reference value
         *
         * @return `bool` True if the line exists, false otherwise
        */
        bool hasLine(const std::string &refKey, const std::string &refValue) const;

        /**
         * @brief Check if the papaya has a specific key
         *
         * @param key The key to check
         *
         * @return `bool` True if the key exists, false otherwise
        */
        bool hasKey(const std::string &key) const;

        /**
         * @brief Get the keys of the papaya
         *
         * @return `std::vector<std::string>` The keys of the papaya
        */
        std::vector<std::string> getKeys() const;

        /**
         * @brief Get the datas of the papaya
         *
         * @return `std::vector<std::unordered_map<std::string, std::string>>` The datas of the papaya
        */
        std::vector<std::unordered_map<std::string, std::string>> getDatas() const;

        /**
         * @brief Get a specific line of the papaya
         *
         * @param key The key to check
         * @param value The value to check
         *
         * @return `std::vector<std::string>` The line of the papaya
        */
        std::vector<std::string> getLine(const std::string &key, const std::string &value) const;

        /**
         * @brief Get a specific data of the papaya
         *
         * @param refKey The reference key
         * @param refValue The reference value
         * @param key The key to check
         *
         * @return `std::string` The data of the papaya
        */
        std::string getData(const std::string &refKey, const std::string &refValue, const std::string &key) const;

        /**
         * @brief Get a specific key of the papaya
         *
         * @param key The key to check
         *
         * @return `std::vector<std::string>` The key of the papaya
        */
        std::vector<std::string> getKey(const std::string &key) const;

        /**
         * @brief Add a new data to the papaya
         *
         * @param key The key of the data
         * @param value The value of the data
        */
        void addData(const std::string &key, const std::string &value);

        /**
         * @brief Add a new key to the papaya
         *
         * @param key The key to add
        */
        void addKey(const std::string &key);

        /**
         * @brief Add a new line to the papaya
        */
        void addNewLine();

        /**
         * @brief Add a new line to the papaya
         *
         * @param data The data of the line
        */
        void addLine(const std::vector<std::string> &data);

        /**
         * @brief Clear the content of the papaya
        */
        void clear();

        /**
         * @brief Destroy the papaya
         *
         * @warning This function will remove the papaya
        */
        void destroy();

        /**
         * @brief Remove a specific data from the papaya
         *
         * @param refKey The reference key
         * @param refValue The reference value
         * @param key The key to remove
        */
        void removeData(const std::string &refKey, const std::string &refValue, const std::string &key);

        /**
         * @brief Remove a specific key from the papaya
         *
         * @param key The key to remove
        */
        void removeKey(const std::string &key);

        /**
         * @brief Remove a specific line from the papaya
         *
         * @param refKey The reference key
         * @param refValue The reference value
        */
        void removeLine(const std::string &refKey, const std::string &refValue);

        /**
         * @brief Update a specific data from the papaya
         *
         * @param refKey The reference key
         * @param refValue The reference value
         * @param key The key to update
         * @param value The value to update
        */
        void updateData(const std::string &refKey, const std::string &refValue, const std::string &key, const std::string &value);

        /**
         * @brief Update a specific key from the papaya
         *
         * @param refKey The reference key
         * @param newKey The new key
        */
        void updateKey(const std::string &refKey, const std::string &newKey);

        /**
         * @brief Update a specific line from the papaya
         *
         * @param refKey The reference key
         * @param refValue The reference value
         * @param data The data to update
        */
        void updateLine(const std::string &refKey, const std::string &refValue, const std::vector<std::string> &data);

        /**
         * @brief Save the papaya to a .papaya file
        */
        void save() const;

        /**
         * @brief View the content of the papaya
        */
        void view() const;

    private:
        /**
         * @brief The path to the papaya file
        */
        std::string _path;

        /**
         * @brief The name of the papaya file
        */
        std::string _name;

        /**
         * @brief The keys of the papaya
        */
        std::vector<std::string> _keys;

        /**
         * @brief The datas of the papaya
        */
        std::vector<std::unordered_map<std::string, std::string>> _datas;

        /**
         * @brief Build the path to the papaya file
         *
         * @return `std::string` The complete path to the papaya file
        */
        std::string _buildPath() const;

        /**
         * @brief Load the papaya file
         *
         * @param lines The content of the papaya file
        */
        void _loadPapaya(const std::vector<std::string> &lines);

        /**
         * @brief Load the keys of the papaya file
         *
         * @param line The line containing the keys
        */
        void _loadPapayaKeys(const std::string &line);

        /**
         * @brief Load the datas of the papaya file
         *
         * @param lines The content of the papaya file
        */
        void _loadPapayaDatas(const std::vector<std::string> &lines);

        /**
         * @brief Check if the keys exist
         *
         * @param keys The keys to check
         * @param where The location of the check
        */
        void _checkKeys(const std::vector<std::string> &keys, const std::string &where) const;
};

#endif /* PAPAYA_H_ */
