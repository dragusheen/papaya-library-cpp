/*
** EPITECH PROJECT, 2024
** papaya-library
** File description:
** PapayaPrivate
*/

#include "Papaya.hpp"

std::string Papaya::_buildPath() const
{
    if (_path.back() != '/' && _name.front() != '/')
        return _path + "/" + _name + ".papaya";
    if (_path.back() == '/' && _name.front() == '/')
        return _path + _name.substr(1) + ".papaya";
    return _path + _name + ".papaya";
}

void Papaya::_loadPapaya(const std::vector<std::string> &lines)
{
    if (lines.size() < 1)
        throw PapayaError("The papaya you are trying to open is empty", "Papaya constructor");

    _loadPapayaKeys(lines[0]);
    _loadPapayaDatas(std::vector<std::string>(lines.begin() + 1, lines.end()));
}

void Papaya::_loadPapayaKeys(const std::string &line)
{
    std::string key;
    for (const auto &c : line) {
        if (c == ';' && key.back() != '\\') {
            _keys.push_back(key);
            key.clear();
        } else
            key += c;
    }
    if (key.size() > 0)
        _keys.push_back(key);

    if (_keys.size() < 1)
        throw PapayaError("The papaya you are trying to open has no keys", "Papaya constructor");
}

void Papaya::_loadPapayaDatas(const std::vector<std::string> &lines)
{
    _datas.clear();
    for (const auto &line : lines) {
        std::string data;
        std::unordered_map<std::string, std::string> map;
        size_t keyIndex = 0;
        for (const auto &c : line) {
            if (c == ';' && data.back() != '\\') {
                map[_keys[keyIndex]] = data;
                data.clear();
                keyIndex++;
            } else
                data += c;
        }
        map[_keys[keyIndex]] = data;
        _datas.push_back(map);
    }
}

void Papaya::_checkKeys(const std::vector<std::string> &keys, const std::string &where) const
{
    for (const auto &key : keys)
        if (!hasKey(key))
            throw PapayaError("The key \"" + key + "\" does not exist", where);
}
