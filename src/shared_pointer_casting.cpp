boost::shared_ptr<Base> b(new Base());
boost::shared_ptr<Derived> d = boost::static_pointer_cast<Derived>(b);