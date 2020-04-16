// Code your testbench here.
// Uncomment the next line for SystemC modules.
#include <systemc.h>
using namespace std;

class slave_if:public sc_interface
{
	public:
  slave_if(){};
  	virtual void write(unsigned int addr , unsigned int data) = 0;
  	virtual unsigned int read(unsigned int addr) = 0;
};


SC_MODULE(slave) , public slave_if
{
  	int arr[10];
  	sc_export<slave_if> slave_if1;
	void write(unsigned int addr , unsigned int data)
    {
    		arr[addr] = data;
    }
  	unsigned int read(unsigned int addr)
    {
    		return arr[addr];
    }
  
  	SC_CTOR(slave)
    {
    	slave_if1.bind(*this);
    }
};

SC_MODULE(master)
{
	sc_in<bool>  clk;
  	sc_port<slave_if> my_port;
  	unsigned int read_data;
  	int i = 0; 
  	void behaviour()
    {
      for(i = 0 ; i<10 ; i++){
        	my_port->write(i,i*10);
          	read_data = my_port->read(i);
          	cout<<"Data is :-->"<< read_data<<endl;	
      }
    }
  	
  	SC_CTOR(master)
    {
    	SC_THREAD(behaviour);
      	sensitive << clk.pos();
    }
};


int sc_main(int argc , char* argv[])
{
	sc_clock clk("clk" , 5 , SC_NS);
  	master m("m");
  	slave s("s");
  	m.clk(clk);
  	m.my_port(s);
  	sc_start();
  	return 0;
}

