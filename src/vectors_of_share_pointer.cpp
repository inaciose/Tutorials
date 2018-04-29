// vectirs of shared pointers
    KDL::Rotation R;
    KDL::Vector V;
    
    R.RPY(1,2,3);
    V.x(4);
    V.y(5);
    V.z(6);

    std::vector<boost::shared_ptr<KDL::Frame> > vector_kdl_ptr;
    vector_kdl_ptr.push_back( boost::shared_ptr< KDL::Frame >(new KDL::Frame(R,V) )  );
    
    
    R.RPY(10,20,30);
    V.x(40);
    V.y(50);
    V.z(60);
    vector_kdl_ptr.push_back( boost::shared_ptr< KDL::Frame >(new KDL::Frame(R,V) )  );
    
    std::cout<<vector_kdl_ptr.at(1)->p.x()  <<std::endl;
    std::cout<<vector_kdl_ptr.at(1)->p.y()  <<std::endl;
    std::cout<<vector_kdl_ptr.at(1)->p.z()  <<std::endl;