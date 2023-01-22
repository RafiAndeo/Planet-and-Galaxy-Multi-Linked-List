#include <iostream>
#include <fstream>

#include<iostream>
using namespace std;

#define info(g) (g)->info
#define next(g) (g)->next
#define info(p) (p)->info
#define next(p) (p)->next
#define nextPlanet(g) (g)->nextPlanet
#define first(list_galaxy) ((list_galaxy).first)
#define nil NULL

typedef struct elm_galaxy *adr_galaxy;
typedef struct elm_planet *adr_planet;

struct galaxy{
    string nama;
};

struct elm_planet{
    string info;
    adr_planet next;
};

struct elm_galaxy{
    galaxy info;
    adr_galaxy next;
    adr_planet nextPlanet;
};

struct mll{
    adr_galaxy first;
};

void create_list(mll &list_galaxy){
    first(list_galaxy) = nil;
}

void new_elm_galaxy(galaxy info, adr_galaxy &g){
    g = new elm_galaxy;
    next(g) = nil;
    nextPlanet(g) = nil;
    info(g).nama = info.nama;
}

void new_elm_planet(string info, adr_planet &p){
    p = new elm_planet;
    next(p) = nil;
    info(p) = info;
}

void insert_new_planet(mll &list_galaxy, adr_galaxy g, adr_planet p){
    adr_planet prec;
    if(nextPlanet(g) == nil){
        nextPlanet(g) = p;
    }else{
        prec = nextPlanet(g);
        while(next(prec) != nil){
            prec = next(prec);
        }
        next(prec) = p;
    }
}

void insert_last_galaxy(mll &list_galaxy, adr_galaxy g){
    if(first(list_galaxy) == nil){
        first(list_galaxy) = g;
    }else{
        adr_galaxy p = first(list_galaxy);
        while (next(p) != nil){
            p = next(p);
        }
        next(p) = g;
    }
}

void show_data_galaxy(mll list_galaxy){
    adr_planet p;
    adr_galaxy g;
    g = first(list_galaxy);
    while (g != nil){
        cout << info(g).nama << endl;
        p = nextPlanet(g);
        while (p != nil){
            cout << info(p) << " ";
            p = next(p);
        }
        cout << endl;
        g = next(g);
    }
}

int main()
{
    mll list_galaxy;
    adr_galaxy g, g1, g2;
    adr_planet p, q1, q2;
    galaxy s;
    int n, r;
    string z, p1, p2;

    create_list(list_galaxy);

    cout << "Masukkan banyak galaxy: ";
    cin >> n;
    for(int i=1;i<=n;i++){
        cout << "Masukkan nama galaxy ke " << i << ": ";
        cin >> s.nama;
        cout << "Masukkan banyak planet: ";
        cin >> r;
        new_elm_galaxy(s, g);
        insert_last_galaxy(list_galaxy, g);
        for(int y=1;y<=r;y++){
            cout << "Masukkan nama planet ke " << y << ": ";
            cin >> z;
            new_elm_planet(z, p);
            insert_new_planet(list_galaxy, g, p);
        }
    }
    show_data_galaxy(list_galaxy);
}

