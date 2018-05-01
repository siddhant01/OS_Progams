//reader and writers problems
//here instead of locking the file we use resource counter

//readers
void read()
{
	Lock(counter_mutex) //function
	{
		while(resource_counter == -1)
			Wait(counter_mutex, read_phase);
		resource_counter++;
	}
	//read data....
	Lock(counter_mutex) //function
	{
		resource_counter--;
		if(resource_counter == 0)
			Signal(write_phase);
	}
}

//writer
void write()
{
	Lock(counter_mutex)
	{
		while(resource_mutex !=0)
			Wait(counter_mutex, write_phase);
		resource_counter = -1;
	}
	//write data....
	Lock(counter_mutex)
	{
		resource_counter = 0;
	}
	Broadcast(read_phase);
	Signal(write_phase);
}
