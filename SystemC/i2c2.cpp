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
  	SC_THREAD(behaviour);
  }	
};

enum states {IDLE ,START ,ADDR, ACK, DATA ,NACK, STOP};

SC_MODULE(Master),public slave_if
{
	sc_out<bool> scl;
  	sc_inout<bool> sda;
  	sc_in<bool> clk;
  	states current_state = IDLE;
  	uint8_t addr = 125;
  	uint8_t addr1 = addr;
	int i_addr = 1,s_data,no_bits = 8,i_data = 1;
  	bool val;
  
   void write(int data)
  	{
      s_data = data;
      cout<<"data receved from host: "<<data<<endl;
      /*while(no_bits!=0)
      {
          sda = data & 1;
          data = data >> 1;
          wait(SC_ZERO_TIME);
          cout<<"@ "<<sc_time_stamp()<<" my sda:-->"<<sda<<endl;
          //master_write_fifo.write(sda);
          no_bits--;
  		 
      }*/
    
  }
  
  
   void read()
   {
       cout<<"my data:-->"<<s_data<<endl;
  }
  int s_data1 = s_data;
  void fsm()
  {
    //while(true){
    	//wait(1,SC_NS);
      	switch(current_state)
        {
        	case IDLE:
          		cout<<"In idle state"<<endl;
          		scl = 1 ;
          		sda = 1 ;
          		current_state = START;
          		break;
         	case START:
          		cout<<"In  start"<<endl;
         		scl = 1 ; 
          		sda = 0 ;
          		current_state = ADDR;
          		break;
          	case ADDR:
          		cout<<"In  address"<<endl;
          		scl = clk;
          		if(scl == 0)
                {
                	val = ((addr1 & (1<<7))>>7) & 1;
                  	sda = val;
                  	next_trigger(SC_ZERO_TIME);
                  	cout<<"adderss:------->"<<sda<<endl;
                  	addr1 = addr1 << 1;
                  	if(i_addr<9)
                	{
            		  current_state = ADDR;
                      cout<<"i_addr :-------->"<<i_addr<<endl;
                  	  i_addr++;
                  	break;
                	}
                  else
                  {
                	current_state = ACK;
                  	break;
                   }
                }
              else{
                break;
              }
          	case  ACK:
          		cout<<"In ack"<<endl;
          		scl = clk;
          		if(scl == 0)
                {
                	if(i_addr == 9)
               		{
                	if(sda == 0)
                    {
                    	current_state = DATA;
                      	break;
                    }
                  	else if(sda == 1)
                    {
                    	current_state = STOP; //its has to terminate the hole process
                      	break;
                    }
                }
                }
           case  DATA:
          		cout<<"In  data"<<endl;
          		scl = clk ; 
          		if(scl == 0)
                {
                  sda = s_data1 & (1<<7);
                  s_data1 = s_data1 << 1;
                  if(i_data < 9)
                  {
                      current_state = DATA;
                      break;
                  }
                  else
                  {
                      current_state = ACK;
                      break;
                  }
                }
          	case STOP:
          		cout<<"In  stop"<<endl;
          		if(scl)
          		sda = 1;
          		break;	
        }
    
  }
  
  SC_CTOR(Master)
  {
  	SC_METHOD(fsm);
    sensitive << clk;
  }
};

SC_MODULE(TB)
{
	sc_in<bool> clk;
  	sc_in<bool> scl;
  	sc_in<bool> sda;
  
  	void display()
    {
      if(clk == 1){
    	cout<<"clk : "<<clk<<endl;
      	cout<<"scl : "<<scl<<endl;
      	cout<<"sda : "<<sda<<endl;
      }
    }
  
  	SC_CTOR(TB)
    {
    	SC_METHOD(display);	
      	sensitive << clk;
    }
};

int sc_main(int argc , char* argv[])
{
	sc_clock clk("clk",1,SC_NS);
  	sc_signal<bool> scl,sda;
  	TB t("t");
  	t.clk(clk);
  	t.scl(scl);
  	t.sda(sda);
  	Master master("master");
  	master.clk(clk);
  	master.scl(scl);
  	master.sda(sda);
  	
  	sc_trace_file* Tf;
  	Tf = sc_create_vcd_trace_file("traces");
  	sc_trace(Tf, clk , "clk");
  	sc_trace(Tf,scl,"scl");
  	sc_trace(Tf,sda,"sda");
  	sc_start(20,SC_NS);
  	sc_close_vcd_trace_file(Tf);
  	return 0;
  	
  
  
  
}
