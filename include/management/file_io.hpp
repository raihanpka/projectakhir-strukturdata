#pragma once

#include "jadwal.hpp"
#include "tiket.hpp"
#include <string>

class FileIO {
public:
    static void simpanJadwal(const std::vector<Jadwal>& jadwalList, const std::string& path);
    static void muatJadwal(std::vector<Jadwal>& jadwalList, const std::string& path);

    static void simpanTiket(const std::vector<Pemesanan>& tiketList, const std::string& path);
    static void muatTiket(std::vector<Pemesanan>& daftarPemesanan,
                      std::unordered_map<std::string, std::unordered_set<std::string>>& kursiTerpesan,
                      const std::string& path);

    static void simpanantrean(const Queue<Pemesanan>& antreanList, const std::string& path);
    static void muatantrean(Queue<Pemesanan>& antreanList, const std::string& path);
};
