int main() {

    Agency agency("RealEstate");
    HouseAdvertisment* h1 = new HouseAdvertisment(200, 100000, 3);
    HouseAdvertisment* h2 = new HouseAdvertisment(150, 85000, 2);
    ApartmentAdvertisment* a1 = new ApartmentAdvertisment(60, 50000, 7);
    ApartmentAdvertisment* a2 = new ApartmentAdvertisment(80, 70000, 3);
    ApartmentAdvertisment* a3 = new ApartmentAdvertisment(45, 30000, 5);
    agency.AddAdvertisment(h1);
    agency.AddAdvertisment(h2);
    agency.AddAdvertisment(a1);
    agency.AddAdvertisment(a2);
    agency.AddAdvertisment(a3);

    agency.PrintOffers(100, 1000);
    agency.PrintOffers(50, 99000);

    return 0;

}
