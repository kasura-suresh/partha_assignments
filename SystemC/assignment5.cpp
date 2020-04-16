// Code your testbench here
// or browse Examples
// Code your testbench here.
// Uncomment the next line for SystemC modules.
#include <systemc.h>
using namespace std;
class slave_if:public sc_interface
{
	public:
  	virtual void write(unsigned int addr , unsigned int data) = 0;
  	virtual void read(unsigned int addr, unsigned int& data) = 0;
};

class peripheral_if:public sc_interface
{
	public:
  	virtual void write(unsigned int addr , unsigned int data) = 0;
  	virtual unsigned int read(unsigned int addr) = 0;
};

SC_MODULE(peripheral),public peripheral_if
{
  int arr[10];
  sc_export<peripheral_if> my_peri;
  
  void write(unsigned int addr , unsigned int data)
    {
    		arr[addr] = data;
    }
  unsigned int read(unsigned int addr)
    {
    		return arr[addr];
    }
  SC_CTOR(peripheral)
  {
  	my_peri.bind(*this);
  }
	
};

SC_MODULE(slave) , public slave_if
{
  	unsigned int data;
  	sc_export<slave_if> slave_if1;
  	sc_port<peripheral_if> my_peripheral;
	void write(unsigned int addr , unsigned int data)
    {
    		my_peripheral->write(addr,data);
    }
   void read(unsigned int addr,unsigned int& data)
    {
    		data = my_peripheral->read(addr);
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
          	my_port->read(i,read_data);
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
  	peripheral p("p");
  	m.clk(clk);
  	m.my_port(s);
  	s.my_peripheral(p);
  	sc_start();
  	return 0;
}

