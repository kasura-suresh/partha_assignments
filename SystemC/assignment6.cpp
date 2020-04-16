// Code your testbench here
// or browse Examples
#include<systemc.h>
class slave_write_if : public sc_interface
{
  	public:
	virtual void write(unsigned int addr , unsigned int data) = 0;
};
class slave_read_if : public sc_interface
{
  	public:
	virtual void  read(unsigned int addr , unsigned int& data) = 0;
};

SC_MODULE(master)
{
  	sc_in<bool> clk;
	sc_port<slave_write_if> mslave;
  	int i = 0;
  	void behaviour()
    {
      while(true)
      {
        wait();
        mslave->write(i,i*10);
        i++;
      }
    }
  	SC_CTOR(master)
    {
    	SC_THREAD(behaviour);
      	sensitive << clk.pos();
      	dont_initialize();
    }
};

SC_MODULE(slave)
{
	sc_port<slave_read_if> sslave;
  	unsigned int data_read;
  	int i = 0;
  	void behaviour()
    {
      sslave->read(i,data_read);
      cout << sc_time_stamp() << " in index " << i << " is : " << data_read << endl;
      ++i;
    }
  
  	SC_CTOR(slave)
    {
    	SC_METHOD(behaviour);
      	sensitive << sslave;
      	dont_initialize();
    }
};

class primitive_chenel : public sc_prim_channel , public slave_write_if , public slave_read_if
{
	public:
  	sc_event ev;
  	int* arr = (int*)malloc(sizeof(int));
  	void write(unsigned int addr , unsigned int data)
    {
      arr[addr]=data;
      cout << sc_time_stamp() << " The data " << data << " is write at index " << addr << endl;
      ++addr;
      arr=(int*)realloc(arr,(addr+1)*sizeof(int));
      request_update();
    }
  	void  read(unsigned int addr , unsigned int& data)
    {
  		data = arr[addr];  
    }
  	void update()
    {
    	ev.notify(SC_ZERO_TIME);
  	}
  	const sc_event& default_event() const
    { 
      return ev; 
    }
};

int sc_main(int argc, char* argv[])
{
  	sc_clock clk("clk",5,SC_NS);
	master m("m");
  	slave s("s");
  	primitive_chenel primechenel;
  	m.clk(clk);
  	m.mslave(primechenel);
  	s.sslave(primechenel);
  	sc_start(50,SC_NS);
  	return 0;
}



