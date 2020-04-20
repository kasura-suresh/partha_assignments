// Code your testbench here.
// Uncomment the next line for SystemC modules.
#include <systemc.h>
#include <stdlib.h>
class slave_if : public sc_interface
{
  public:
	virtual void write(int data) = 0;
  	virtual void read() = 0;
};

SC_MODULE(Host)
{
 	sc_in<bool> scl;
  	sc_in<bool> sda;
  	sc_in<bool> rw;
	sc_port<slave_if> host_port;
  	int val;
  	void behaviour()
    {
    	if(scl == 1 && sda == 0 && rw == 0)
        {
          	val = rand()%50;
        	host_port->write(val);
        }
      	else if(scl == 1 && sda == 0 && rw == 1)
        {
        	host_port->read();
        }
    }
  SC_CTOR(Host)
  {
  	SC_METHOD(behaviour);
    sensitive << scl << sda << rw;
  }
  	
};

SC_MODULE(Master),public slave_if
{
	sc_in<bool> clk;
  	sc_out<bool> scl;
  	sc_out<bool> sda;
  	sc_out<bool> rw;
  	sc_fifo_out<int> master_write_fifo;
  	sc_fifo_in<int> master_read_fifo;
  	int i = 0,data_get,val,no_bits = 8;
  	Host my_host;
  void write(int data)
  {
      while(no_bits!=0)
      {
          sda = data & 1;
          wait(SC_ZERO_TIME);
          master_write_fifo.write(sda);
          no_bits++;
      }
  }
  
  void read()
  {
      while(i!=8)
      {
        master_read_fifo.read(val);
        data_get = data_get + (val*pow(2,i));
        /*master_read_fifo.read(val);
        cout<<"value:->"<<val<<endl;*/
        i++;
      }
       cout<<"my data:-->"<<data_get;
  }
  
  SC_CTOR(Master):my_host("my_host")
  {
    my_host.scl(scl);
    my_host.sda(sda);
    my_host.rw(rw);
  }
};

SC_MODULE(Slave)
{
	sc_inout<bool> scl ;
  	sc_inout<bool> sda ;
  	sc_inout<bool> rw ;
  	
  	Master slave_master;
  
  	SC_CTOR(Slave) : slave_master("slave_master")
    {
    	slave_master.scl(scl);
      	slave_master.sda(sda);
      	slave_master.rw(rw);
    }
  	
};

int sc_main(int argc , char* argv[])
{
  sc_clock clk("clk",1,SC_NS);
  sc_signal<bool> scl;
  sc_signal<bool> sda;
  sc_signal<bool> rw;
  sc_fifo<int> main_fifo;
  Master master("master");
  master.clk(clk);
  master.master_write_fifo(main_fifo);
  master.master_read_fifo(main_fifo);
  Slave slave("slave");
  scl.write(1);
  sda.write(0);
  rw.write(0);
  slave.scl(scl);
  slave.sda(sda);
  slave.rw(rw);
  
  sc_start();
  return 0;
}
