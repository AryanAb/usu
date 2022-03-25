#pragma once

#include "DFA.h"

#include <string>
#include <memory>

namespace usu
{
	class Expr
	{
	public:
		virtual void print() = 0;
	};

	class AssignExpr : public Expr
	{
	public:
		AssignExpr(std::string name, std::unique_ptr<Expr> expr);
		void print();
	private:
		std::string name;
		std::unique_ptr<Expr> expr;
	};

	class BinExp : public Expr
	{
	public:
		BinExp(std::unique_ptr<Expr> left, DFA::Token op, std::unique_ptr<Expr> right);
		void print();
	private:
		std::unique_ptr<Expr> left;
		DFA::Token op;
		std::unique_ptr<Expr> right;
	};
	
	class IfExpr : public Expr
	{
	public:
		IfExpr(std::unique_ptr<Expr> condition, std::unique_ptr<Expr> ifBlock, std::unique_ptr<Expr> elseBlock);
		void print();
	private:
		std::unique_ptr<Expr> condition;
		std::unique_ptr<Expr> ifBlock;
		std::unique_ptr<Expr> elseBlock;
	};
};
