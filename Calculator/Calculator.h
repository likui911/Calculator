
#include <string>
#include <exception>

class CalculatorException :public std::exception
{
public:
	enum class ExceptionType :char { None = 0, DividedByZero };
	CalculatorException(std::string textWhat, ExceptionType exceptionType) :
		m_textWhat(textWhat), m_exceptionType(exceptionType){}

	virtual const char* what() const noexcept
	{
		return m_textWhat.c_str();
	}

private:
	std::string m_textWhat ;
	ExceptionType m_exceptionType{ ExceptionType::None };
};


class Calculator
{
public:
	enum class CalcOp :char { Add, Substract, Multiply, Divide, Equal, Negate,None};
	enum class CalcState:char{Start,Operand_1,Negate_1,Operator,Operand_2,Negate_2,Error};

	Calculator();
	void reset();
	
	double getResult();

	CalcState getCurrentState();
	void setCurrentState(CalcState state);
	void setOperand_1(double operand);
	double getOperand_1();
	void setOperand_2(double operand);
	double getOperand_2();
	void setOperator(CalcOp op);
	CalcOp getOperator();

private:
	double m_lastOperand_1;
	double m_lastOperand_2;
	CalcOp m_lastOperator;
	double m_lastResult;
	CalcState m_currentState;
};

