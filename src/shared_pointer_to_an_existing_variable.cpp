int *a=new int;
boost::shared_ptr<int> a_ptr(a);



int a=9;
boost::shared_ptr<int> a_ptr=boost::make_shared(a);