#include "Expressions.h"
#include "Exception.h"
#include "Messages.h"

#include <iostream>

namespace usu
{
	AssignExpr::AssignExpr(std::string name, std::unique_ptr<Expr> expr) : name{name}, expr{std::move(expr)}
	{}

	void AssignExpr::print()
	{
		std::cout << name << " := ";
		expr->print();
	}
	

	BinExp::BinExp(std::unique_ptr<Expr> left, DFA::Token op, std::unique_ptr<Expr> right) : left{std::move(left)}, op{op}, right{std::move(right)}
	{}

	void BinExp::print()
	{
		left->print();
		switch (op)
		{
		case DFA::Token::PLUS:
			std::cout << " + ";
			break;
		case DFA::Token::SUB:
			std::cout << " - ";
			break;
		case DFA::Token::MULT:
			std::cout << " * ";
			break;
		case DFA::Token::DIV:
			std::cout << " / ";
			break;
		case DFA::Token::MOD:
			std::cout << " % ";
			break;
		default:
			throw Exception("parsing", Messages::error("Encountered invalid token in BinExp"));
		}
		right->print();
	}

	
	IfExpr::IfExpr(std::unique_ptr<Expr> condition, std::unique_ptr<Expr> ifBlock, std::unique_ptr<Expr> elseBlock) :
		condition{std::move(condition)}, ifBlock{std::move(ifBlock)}, elseBlock{std::move(elseBlock)}
	{}

	void IfExpr::print()
	{
		condition->print();
		ifBlock->print();
		elseBlock->print();
	}
};
