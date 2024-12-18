/*
** EPITECH PROJECT, 2024
** papaya-library
** File description:
** Papaya
*/

#include "Papaya.hpp"

Papaya::Papaya(const std::string &path, const std::string &name, const std::vector<std::string> &keys)
    : _path(path), _name(name), _keys(keys), _datas({})
{
}

Papaya::Papaya(const std::string &path, const std::string &name)
    : _path(path), _name(name)
{
    auto papayaPath = _buildPath();
    std::ifstream file(papayaPath);

    if (!file.is_open())
        throw PapayaError("The papaya file does not exist", "Papaya Constructor");

    std::string line;
    std::vector<std::string> lines;

    while (std::getline(file, line))
        lines.push_back(line);

    file.close();
    _loadPapaya(lines);
}

bool Papaya::hasData(const std::string &refKey, const std::string &refValue, const std::string &key) const
{
    _checkKeys({refKey, key}, "Papaya::hasData");
    for (const auto &data : _datas)
        if (data.at(refKey) == refValue)
            return data.at(key) != "";
    return false;
}

bool Papaya::hasLine(const std::string &refKey, const std::string &refValue) const
{
    _checkKeys({refKey}, "Papaya::hasLine");
    for (const auto &data : _datas)
        if (data.at(refKey) == refValue)
            return true;
    return false;
}

bool Papaya::hasKey(const std::string &key) const
{
    return std::find(_keys.begin(), _keys.end(), key) != _keys.end();
}


std::vector<std::string> Papaya::getKeys() const
{
    return _keys;
}

std::vector<std::unordered_map<std::string, std::string>> Papaya::getDatas() const
{
    return _datas;
}

std::vector<std::string> Papaya::getLine(const std::string &key, const std::string &value) const
{
    _checkKeys({key}, "Papaya::getLine");
    for (const auto &data : _datas) {
        if (data.at(key) == value) {
            std::vector<std::string> line;
            for (const auto &k : _keys)
                line.push_back(data.at(k));
            return line;
        }
    }
    return {};
}

std::string Papaya::getData(const std::string &refKey, const std::string &refValue, const std::string &key) const
{
    _checkKeys({refKey, key}, "Papaya::getData");
    for (const auto &data : _datas) {
        if (data.at(refKey) == refValue)
            return data.at(key);
    }
    return "";
}

std::vector<std::string> Papaya::getKey(const std::string &key) const
{
    _checkKeys({key}, "Papaya::getKey");
    std::vector<std::string> keys;
    for (const auto &data : _datas)
        keys.push_back(data.at(key));
    return keys;
}


void Papaya::addData(const std::string &key, const std::string &value)
{
    _checkKeys({key}, "Papaya::addData");
    addNewLine();
    _datas.back()[key] = value;
}

void Papaya::addKey(const std::string &key)
{
    _keys.push_back(key);
    for (auto &data : _datas)
        data[key] = "";
}

void Papaya::addNewLine()
{
    std::unordered_map<std::string, std::string> map;
    for (const auto &key : _keys)
        map[key] = "";
    _datas.push_back(map);
}

void Papaya::addLine(const std::vector<std::string> &data)
{
    if (data.size() != _keys.size())
        throw PapayaError("The data you are trying to add does not match the keys", "Papaya add");
    std::unordered_map<std::string, std::string> map;
    for (std::size_t i = 0; i < data.size(); i++)
        map[_keys[i]] = data[i];
    _datas.push_back(map);
}

void Papaya::clear()
{
    _datas.clear();
}

void Papaya::destroy() const
{
    auto papayaPath = _buildPath();
    if (!std::filesystem::exists(papayaPath))
        throw PapayaError("File does not exist", "Papaya::destroy");
    try {
        if (!std::filesystem::remove(papayaPath))
            throw PapayaError("Failed to delete file", "Papaya::destroy");
    } catch (const std::filesystem::filesystem_error &e) {
        throw PapayaError(e.what(), "Papaya::destroy");
    }
}

void Papaya::removeData(const std::string &refKey, const std::string &refValue, const std::string &key)
{
    _checkKeys({refKey, key}, "Papaya::removeData");
    for (std::size_t i = 0; i < _datas.size(); i++) {
        if (_datas[i].at(refKey) == refValue) {
            _datas[i][key] = "";
            return;
        }
    }
}

void Papaya::removeKey(const std::string &key)
{
    _checkKeys({key}, "Papaya::removeKey");
    _keys.erase(std::remove(_keys.begin(), _keys.end(), key), _keys.end());
    for (auto &data : _datas)
        data.erase(key);
}

void Papaya::removeLine(const std::string &refKey, const std::string &refValue)
{
    _checkKeys({refKey}, "Papaya::removeLine");
    _datas.erase(std::remove_if(_datas.begin(), _datas.end(), [refKey, refValue](const std::unordered_map<std::string, std::string> &data) {
        return data.at(refKey) == refValue;
    }), _datas.end());
}

void Papaya::updateData(const std::string &refKey, const std::string &refValue, const std::string &key, const std::string &value)
{
    _checkKeys({refKey, key}, "Papaya::updateData");
    for (auto &data : _datas) {
        if (data.at(refKey) == refValue) {
            data[key] = value;
            return;
        }
    }
}

void Papaya::updateKey(const std::string &refKey, const std::string &newKey)
{
    _checkKeys({refKey}, "Papaya::updateKey");
    for (auto &data : _datas) {
        data[newKey] = data[refKey];
        data.erase(refKey);
    }
    _keys.erase(std::remove(_keys.begin(), _keys.end(), refKey), _keys.end());
}

void Papaya::updateLine(const std::string &refKey, const std::string &refValue, const std::vector<std::string> &data)
{
    _checkKeys({refKey}, "Papaya::updateLine");
    for (auto &d : _datas) {
        if (d.at(refKey) == refValue) {
            for (std::size_t i = 0; i < data.size(); i++)
                d[_keys[i]] = data[i];
            return;
        }
    }
}

void Papaya::save() const
{
    auto papayaPath = _buildPath();
    std::ofstream file(papayaPath);
    if (!file.is_open())
        throw PapayaError("Failed to open file for saving", "Papaya::save");
    for (size_t i = 0; i < _keys.size(); ++i) {
        file << _keys[i];
        if (i < _keys.size() - 1) file << ",";
    }
    file << "\n";
    for (const auto &data : _datas) {
        for (size_t i = 0; i < _keys.size(); ++i) {
            const auto &key = _keys[i];
            auto it = data.find(key);
            if (it != data.end()) file << it->second;
            if (i < _keys.size() - 1) file << ",";
        }
        file << "\n";
    }
    file.close();
}


void Papaya::view() const
{
    for (auto const &data : _datas) {
        for (std::size_t i = 0; i < _keys.size(); i++) {
            std::cout << _keys[i] << ": [" << data.at(_keys[i]) << "]";
            if (i + 1 < _keys.size())
                std::cout << " | ";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}
