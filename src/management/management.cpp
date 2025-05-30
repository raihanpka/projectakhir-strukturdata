#include "management.hpp"
#include <iostream>
#include <string>
#include <iomanip>
#include <limits>

void ManagementSystem::muatDariFile() {
    // Menggunakan getter non-const untuk mengakses data
    FileIO::muatJadwal(jadwalManager.getDaftarJadwal(), "data/jadwal.csv");
    FileIO::muatTiket(tiketManager.getMutableDaftarPemesanan(), tiketManager.getMutableKursiTerpesan(), "data/pemesanan.csv");
    FileIO::muatantrean(tiketManager.getMutableantrean(), "data/antrean.csv");
}

void ManagementSystem::simpanKeFile() const {
    // Menggunakan getter const karena kita hanya membaca data
    FileIO::simpanJadwal(jadwalManager.getJadwal(), "data/jadwal.csv");
    FileIO::simpanTiket(tiketManager.getDaftarPemesanan(), "data/pemesanan.csv");
    FileIO::simpanantrean(tiketManager.getantreanPesanan(), "data/antrean.csv");
}

// Constructor untuk ManagementSystem
// Getter untuk UserContext, JadwalManager, dan TiketManager
UserContext& ManagementSystem::getUser() { 
    return user; 
}

// 
JadwalManager& ManagementSystem::getJadwalManager() { 
    return jadwalManager; 
}

TiketManager& ManagementSystem::getTiketManager() { 
    return tiketManager; 
}
