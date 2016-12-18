#ifndef __COMMAND_CLASS__
#define __COMMAND_CLASS__

#include "composite.h"

class Command {
	protected:
		Base* root;
	
	public:
		Command() { };
		double execute() {
			return root->evaluate();
		};
		Base* get_root() {
			return root;
		};
};

class OpCommand : public Command {
	//OpCommand Code Here
	public:
	OpCommand(double a) {
	    Base* op = new Op(a);
	    root = op;
	}
	double execute(){
		
		return root->evaluate();
		
	}
	
	Base* get_root(){
	    return root;
	}
	
};

class AddCommand : public Command {
	//AddCommand Code Here
	public:
	AddCommand(Command* a, double b)
	{
	    Base* right = new Op(b);
		root = new Add(a->get_root(), right);
	}
	// AddCommand(Base* a){
	    
	// }
	
	
	double execute(){
	    return root->evaluate();
	}
	
	Base* get_root()
	{
		return root;
	}
};

class SubCommand : public Command {
	//SubCommand Code Here
	public:
	SubCommand(Command* left, double a)
	{
		Base* op = new Op(a);
		
		root = new Sub(left->get_root(), op);
	}
	double execute() {
		return root->evaluate();
		
	}
	
	Base* get_root()
	{
		return root;
	}
};

class MultCommand : public Command {
	//MultCommand Code Here
	public:
	MultCommand(Command* left, double a){
	    Base* op = new Op(a);
		root = new Mult(left->get_root(), op);
	}
		double execute() {
			return root->evaluate();
			
		}
	
		Base* get_root()
	{
		return root;
	}
};

class SqrCommand : public Command {
	//SqrCommand Code Here
	public:
	SqrCommand(Command* a){
		Base* sqr = new Sqr(a->get_root());
		root = sqr;
		
	}
	double execute() {
		return root->evaluate();
		
	}
	
		Base* get_root()
	{
		return root;
	}
};

#endif //__COMMAND_CLASS__
