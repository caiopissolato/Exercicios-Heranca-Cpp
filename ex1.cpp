#include <iostream>
#include <string>
#include <vector>

using namespace std;

class VeiculoAVenda{
    private: 
        string marca;
        string modelo;
        int ano;
        double precoDeVenda;

    public:
        VeiculoAVenda() : marca("nulo"), modelo("nulo"), ano(0), precoDeVenda(0.0){};

        string getMarca(){return this->marca;}
        string getModelo(){return this->modelo;}
        int getAno(){return this->ano;}
        double getPrecoVenda(){return this->precoDeVenda;}

        void setMarca(string marca){this->marca = marca;}
        void setModelo(string modelo){this->modelo = modelo;}
        void setAno(int ano){this->ano = ano;}
        void setPrecoVenda(double precoDeVenda){this->precoDeVenda = precoDeVenda;}

        virtual void mostraDados(){
            cout << "Marca: " << getMarca() << endl << "Modelo: " << getModelo() << endl << "Ano: " << getAno() << endl << "Preco de venda: " << getPrecoVenda() << endl << endl;
        }
};

class AutomovelAVenda : public VeiculoAVenda{
    private:
        double motor;
        bool cambio;
        int nPortas;

    public:
        //Construtor
        AutomovelAVenda() : VeiculoAVenda(), motor(0.0), cambio(true), nPortas(4){}; 

        double getMotor(){return this->motor;}
        bool getCambio(){return this->cambio;}
        int getnPortas(){return this->nPortas;}

        void setMotor(double motor){this->motor = motor;}
        void setCambio(bool cambio){this->cambio = cambio;}
        void setnPortas(int nPortas){this->nPortas = nPortas;}

        void mostraDados() override{
            if(getCambio() == true){
                cout << "Marca: " << getMarca() << endl << "Modelo: " << getModelo() << endl << "Ano: " << getAno() << endl << "Preco de venda: " << getPrecoVenda() << endl << "Motor: " << getMotor() << endl << "Cambio: Automatico" << endl << "Numero de portas: " << getnPortas() << endl << endl;
            } else {
                cout << "Marca: " << getMarca() << endl << "Modelo: " << getModelo() << endl << "Ano: " << getAno() << endl << "Preco de venda: " << getPrecoVenda() << endl << "Motor: " << getMotor() << endl << "Cambio: Manual" << endl << "Numero de portas: " << getnPortas() << endl << endl;
            }
        }
};

class MotocicletaAVenda : public VeiculoAVenda{
    private: 
        int cilindradas;

    public: 
        //Construtor
        MotocicletaAVenda() : VeiculoAVenda(), cilindradas(0){};

        int getCilindradas(){return this->cilindradas;}

        void setCilindradas(int cilindradas){this->cilindradas = cilindradas;}

        void mostraDados() override{
            cout << "Marca: " << getMarca() << endl << "Modelo: " << getModelo() << endl << "Ano: " << getAno() << endl << "Preco de venda: " << getPrecoVenda() << endl << "Cilindradas: " << getCilindradas() << endl << endl;
        }
};

int main(){
    AutomovelAVenda carro1;
    AutomovelAVenda carro2;

    MotocicletaAVenda moto1;
    MotocicletaAVenda moto2;

    carro1.setMarca("Honda");
    carro1.setModelo("City");
    carro1.setAno(2016);
    carro1.setPrecoVenda(35000);
    carro1.setMotor(1.5);
    carro1.setCambio(false);
    carro1.setnPortas(4);

    carro2.setMarca("Toyota");
    carro2.setModelo("Corolla");
    carro2.setAno(2020);
    carro2.setPrecoVenda(100000);
    carro2.setMotor(2.5);
    carro2.setCambio(true);
    carro2.setnPortas(4);

    carro1.mostraDados();
    carro2.mostraDados();

    moto1.setMarca("Honda");
    moto1.setModelo("Titan");
    moto1.setAno(2014);
    moto1.setPrecoVenda(7000);
    moto1.setCilindradas(150);

    moto2.setMarca("Honda");
    moto2.setModelo("Biz");
    moto2.setAno(2012);
    moto2.setPrecoVenda(3500);
    moto2.setCilindradas(100);

    moto1.mostraDados();
    moto2.mostraDados();

    double preco_total;

    vector<VeiculoAVenda*> veiculos;

    veiculos.push_back(&carro1);
    veiculos.push_back(&carro2);
    veiculos.push_back(&moto1);
    veiculos.push_back(&moto2);

    for(auto v : veiculos){
        preco_total += v->getPrecoVenda();
    }

    cout << "Somatoria dos precos: " << preco_total << endl;
}