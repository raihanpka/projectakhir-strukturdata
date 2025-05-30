#pragma once

#include "stack.hpp"
#include "queue.hpp"
#include "data.hpp"
#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <iostream>

class TiketManager {
private:
    Stack<Pemesanan> konfirmasiPemesanan;
    Queue<Pemesanan> antreanPemesanan;
    std::vector<Pemesanan> daftarPemesanan;
    std::unordered_map<std::string, std::unordered_set<std::string>> kursiTerpesan;
    std::unordered_map<std::string, std::string> kodeKeNamaKereta;

public:
    std::string generatePNR() const;
    std::string generateBangku() const;
    std::vector<Jadwal> tampilkanPilihanJadwal(const std::vector<Jadwal>& daftar, const std::string& field, std::string& hasilPilihan);
    bool isSeatAvailable(const std::string& kodeJadwal, const std::string& seat) const;
    std::string cariJadwalByPesanan(
        const std::string& asal,
        const std::string& tujuan,
        const std::string& kereta,
        const std::string& tanggal
    ) const;
    void tampilkanJadwalByKode(const std::string& kodeJadwal) const;
    void cekantreanPesanan() const;
    void prosesantreanPesanan();
    void tambahKeantrean(const Pemesanan& pemesanan);
    void tampilkanTiketByPNR(const std::string& pnr) const;

    // Getters untuk akses baca saja (const)
    const std::vector<Pemesanan>& getDaftarPemesanan() const;
    const std::unordered_map<std::string, std::unordered_set<std::string>>& getKursiTerpesan() const;
    const Queue<Pemesanan>& getantreanPesanan() const;

    // Getters untuk akses modifikasi (non-const)
    std::vector<Pemesanan>& getMutableDaftarPemesanan();
    std::unordered_map<std::string, std::unordered_set<std::string>>& getMutableKursiTerpesan();
    Queue<Pemesanan>& getMutableantrean();
};
