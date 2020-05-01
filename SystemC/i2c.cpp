/************************************
	i2c protocol
    Author - Partha Pratim Dey
    Date - 23/04/2020
*************************************/

#include <systemc.h>
#include <stdlib.h>
#include <iostream>
using namespace std;
class slave_if : public sc_interface
{
  public:
	virtual void write(int data) = 0;
  	virtual void read() = 0;
};

SC_MODULE(Host)
{
  	sc_in<bool> rw;
	sc_port<slave_if> host_port;
  	int val;
  	void behaviour()
    {
          	//val = rand()%50;
      		val = 23;
      		cout<<"Data in host : "<<val<<endl;
        	host_port->write(val);
        	host_port->read();
    }
  SC_CTOR(Host)
  {
    cout<<"iam host"<<endl;
  	SC_THREAD(behaviour);  // i'm not able to declear as a method process 
    //sensitive << rw;
    //dont_initialize();
  }
  	
};
enum states {START , READ , WRITE , STOP};
SC_MODULE(Master),public slave_if
{
	sc_in<bool> clk;
  	sc_out<bool> scl;
  	sc_inout<bool> sda;
  	sc_in<bool> ack;
  	sc_inout<bool> rw;
  	sc_fifo_out<int> master_write_fifo;
  	sc_fifo_in<int> master_read_fifo;
  	int i = 0,data_get=0,s_data = 0,val,no_bits = 8,no_bits1 = 8;
  	states current_state = START;
  	sc_export<slave_if> master_export ;
  
  void write(int data)
  {
      s_data = data;
      cout<<"data receved from host: "<<data<<endl;
      while(no_bits!=0)
      {
          sda = data & 1;
          data = data >> 1;
          wait(SC_ZERO_TIME);
          cout<<"@ "<<sc_time_stamp()<<" my sda:-->"<<sda<<endl;
          master_write_fifo.write(sda);
          no_bits--;
          
  		 
      }
    
  }
  
  void read()
  {
      while(i!=8)
      {
        master_read_fifo.read(val);
        data_get = data_get + (val*pow(2,i));
        i++;
      }
       cout<<"my data:-->"<<data_get<<endl;
  }
  
  void fsm()
  {
    switch(current_state)
    {
    	case START:
      		cout<<"i am in start"<<endl;
        	scl = 1;
      		sda = 0;
      		current_state = WRITE ;
      		break;
        case WRITE:
      		//cout<<"s_data:-->"<<s_data<<endl;
    		scl = 1;
      		rw = 0;
     		while(no_bits1 != 0){
            cout<<"s_data:-->"<<s_data<<endl;
      		sda = s_data & 1; 
      		s_data = s_data >> 1;
            next_trigger(SC_ZERO_TIME);
            cout<<"SDA :-->"<<sda<<endl;
            no_bits1--;
      		}
      		if(ack == 1)
      			current_state = READ;
      		break;
      	case READ:
      		cout<<"i am in read"<<endl;
    		scl = 1;
      		sda = 0;
      		rw = 1;
      		current_state = STOP;
      		break;
      	case STOP:
      		cout<<"i am in stop"<<endl;
    		scl = 1;
      		sda = 1;
			break;	
    }
  }
  
  SC_CTOR(Master)
  {
    
    cout<<"iam master"<<endl;
    SC_METHOD(fsm);
    sensitive << clk.pos();
    master_export.bind(*this) ;
  }
};

SC_MODULE(Slave)
{
  	sc_in<bool> clk;
	sc_in<bool> scl ;
  	sc_inout<bool> sda ;
  	sc_in<bool> rw ;
  	sc_inout<bool> ack;
  	sc_fifo_in<int> slave_read;
  	sc_fifo_out<int> slave_write;
  	int val,i = 0;
  	
  	void logic()
    {
    	//wait(SC_ZERO_TIME);
      	cout<<"Iam inside slave logic"<<endl;
      	if(rw == 0)
        {
          	cout<<"This works for rw = 0" << endl;
        	slave_write.write(sda);
          	slave_read.read(val);
          	cout<<"@"<<sc_time_stamp()<<" data receved:-->"<<val<<endl;
         	//ack = 1;
        }
      	else if(rw == 1)
        {
          	cout<<"This works for rw = 1"<<endl;
        	slave_read.read(val);
          	cout<<"@"<<sc_time_stamp()<<"data out:-->"<<val<<endl;
        }
    }
  	
  
  	SC_CTOR(Slave)
    {
      cout<<"iam slave"<<endl;
      	SC_THREAD(logic);
      	sensitive << clk.pos();
      	dont_initialize();
    }
  	
};

int sc_main(int argc , char* argv[])
{
  sc_clock clk("clk",1,SC_NS);
  sc_signal<bool> scl , rw , ack;
  sc_signal<bool , SC_MANY_WRITERS > sda;
  /*scl.write(1);
  sda.write(0);
  rw.write(0);*/
  sc_fifo<int>master_fifo;
  sc_fifo<int>slave_fifo;
  Master master("master");
  Host host("host");
  Slave slave("slave");
  master.clk(clk);
  master.scl(scl);
  master.sda(sda);
  master.ack(ack);
  master.rw(rw);
  master.master_write_fifo(master_fifo);
  master.master_read_fifo(master_fifo);
  
  //host.clk(clk);
  host.rw(rw);
  host.host_port(master.master_export);
  
  slave.clk(clk);
  slave.scl(scl);
  slave.sda(sda);
  slave.rw(rw);
  slave.ack(ack);
  slave.slave_read(slave_fifo);
  slave.slave_write(slave_fifo);
  
  sc_trace_file* Tf;
  Tf = sc_create_vcd_trace_file("traces");
  
  sc_trace(Tf, clk , "clk");
  sc_trace(Tf, scl , "SCL" );
  sc_trace(Tf, sda , "SDA");
  sc_trace(Tf, rw , "RW");
  sc_trace(Tf, ack , "ACK");
  sc_start(10,SC_NS);
  sc_close_vcd_trace_file(Tf);
  return 0;
}
