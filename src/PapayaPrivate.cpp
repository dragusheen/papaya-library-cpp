/*
** EPITECH PROJECT, 2024
** papaya-library
** File description:
** PapayaPrivate
*/

#include "Papaya.hpp"

std::filesystem::path Papaya::_buildPath() const
{
    return _path / (_name + ".papaya");
}

void Papaya::_loadPapaya(const std::vector<std::string> &lines)
{
    if (lines.empty())
        throw PapayaError("The papaya file is empty", "Papaya::_loadPapaya");

    _loadPapayaKeys(lines[0]);
    _loadPapayaDatas({lines.begin() + 1, lines.end()});
}

void Papaya::_loadPapayaKeys(const std::string &line)
{
    std::istringstream stream(line);
    std::string key;

    while (std::getline(stream, key, ','))
        _keys.push_back(key);
}

void Papaya::_loadPapayaDatas(const std::vector<std::string> &lines)
{
    for (const auto &line : lines)
    {
        std::unordered_map<std::string, std::string> data;
        std::istringstream stream(line);
        std::string value;

        for (const auto &key : _keys) {
            if (!std::getline(stream, value, ','))
                throw PapayaError("Data line mismatch with keys", "Papaya::_loadPapayaDatas");
            data[key] = value;
        }
        _datas.push_back(data);
    }
}

void Papaya::_checkKeys(const std::vector<std::string> &keys, const std::string &where) const
{
    for (const auto &key : keys)
        if (!hasKey(key))
            throw PapayaError("Key '" + key + "' does not exist", where);
}
