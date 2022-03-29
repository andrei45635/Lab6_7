#include <iostream>
#include "UI.h"

using std::cin;
using std::cout;

void UI::startUI() {
	while (true) {
		cout << "1. Adauga oferte\n2. Printeaza oferte\n3. Populeaza cu 4 oferte\n4. Sterge oferte\n5. Modifica oferte\n6. Cauta oferte\n0. Exit\nIntroduceti comanda: ";
		int cmd = 0;
		cin >> cmd;
		if (cmd == 0) {
			cout << "Bye bye!\n";
			break;
		}
		else if (cmd == 1) {
			string denum;
			string dest;
			string type;
			double price;
			cout << "Introduceti denumirea ofertei: ";
			cin >> denum;
			cout << "Introduceti destinatia ofertei: ";
			cin >> dest;
			cout << "Introduceti tipul ofertei: ";
			cin >> type;
			cout << "Introduceti pretul ofertei: ";
			cin >> price;
			try {
				serv.addServiceOffer(denum, dest, type, price);
				cout << "Oferta adaugata cu succes!\n";
			}
			catch (RepoException& msg) {
				msg.getMessage();
			}
		}
		else if (cmd == 2) {
			const auto& offers = serv.getAllService();
			int pos = 0;
				for (const auto& ofr : offers) {
					cout << pos <<") Denumirea ofertei este : " << ofr.getDenumire() << ", destinatia este : " << ofr.getDestinatie() << ", tipul este : " << ofr.getType() << ", iar pretul este : " << ofr.getPrice() << std::endl;	
					pos++;
			}
		}
		else if (cmd == 3) {
			serv.addServiceOffer("Familie", "Kiev", "Roadtrip", 69);
			serv.addServiceOffer("Familie", "Odesa", "Voiaj", 100);
			serv.addServiceOffer("Business", "Moscova", "Zbor", 129);
			serv.addServiceOffer("Business", "Petrograd", "Tren", 420);
			cout << "Populat cu succes!\n";
		}
		else if (cmd == 4) {
			int pos;
			cout << "Introduceti pozitia elementului pe care doriti sa il stergeti: ";
			cin >> pos;
			serv.deleteServiceOffer(pos);
			cout << "Oferta " << pos << " a fost stearsa cu succes!\n";
		}
		else if (cmd == 5) {
			int pos;
			cout << "Introduceti pozitia elementului pe care doriti sa il modificati: ";
			cin >> pos;
			string new_denum;
			string new_dest;
			string new_type;
			double new_price;
			cout << "Introduceti noua denumire a ofertei: ";
			cin >> new_denum;
			cout << "Introduceti noua destinatie a ofertei: ";
			cin >> new_dest;
			cout << "Introduceti noul tip al ofertei: ";
			cin >> new_type;
			cout << "Introduceti noul pret al ofertei: ";
			cin >> new_price;
			serv.modifyServiceOffer(pos, new_denum, new_dest, new_type, new_price);
			cout << "Oferta " << pos << " a fost modificata cu succes!\n";
		}
		else if (cmd == 6) {
			int pos;
			cout << "Introduceti pozitia elementului pe care doriti sa il cautati: ";
			cin >> pos;
			const auto& found = serv.findOfferService(pos);
			cout << "Oferta cautata este: " << pos << ") Denumirea ofertei este : " << found.getDenumire() << ", destinatia este : " << found.getDestinatie() << ", tipul este : " << found.getType() << ", iar pretul este : " << found.getPrice() << std::endl;
		}
	}
}