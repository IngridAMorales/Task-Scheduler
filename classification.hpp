class classification
{
	public:

		virtual ~classification() {}
		virtual std::string label () const = 0;
}

class work:public classification {}
{
        public:

		~work() {}	
		std::string label ();
}

class school:public classification {}
{
        public:
		
		~school() {}
		std::string label ();
}

class personal:public classification {}
{
        public:	

		~personal() {}
		std::string label (;
}
