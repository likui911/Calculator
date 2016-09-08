#include "stdafx.h"
#include "Calculator.h"

Calculator::Calculator():m_lastOperator(Calculator::CalcOp::None)
	, m_currentState(Calculator::CalcState::Start)
{
}

void Calculator::reset()
{
	m_lastOperand_1 = 0;
	m_lastOperand_2 = 0;
	m_lastOperator = Calculator::CalcOp::None;
	m_currentState = Calculator::CalcState::Start;
	m_lastResult = 0;
}

double Calculator::getResult()
{
	if (this->m_lastOperator == Calculator::CalcOp::Add)
	{
		m_lastResult = m_lastOperand_1 + m_lastOperand_2;
	}
	else if (this->m_lastOperator == Calculator::CalcOp::Substract)
	{
		m_lastResult = m_lastOperand_1 - m_lastOperand_2;
	}
	else if (this->m_lastOperator == Calculator::CalcOp::Multiply)
	{
		m_lastResult = m_lastOperand_1 * m_lastOperand_2;
	}
	else if (this->m_lastOperator == Calculator::CalcOp::Divide)
	{
		if (fabs(m_lastOperand_2) <= 0.00000000000000000)
		{
			throw CalculatorException("Infinity",CalculatorException::ExceptionType::DividedByZero);
		}
		m_lastResult = m_lastOperand_1 / m_lastOperand_2;
	}
	return m_lastResult;
}

Calculator::CalcState Calculator::getCurrentState()
{
	return m_currentState;
}

void Calculator::setCurrentState(Calculator::CalcState state)
{
	m_currentState = state;
}

void Calculator::setOperand_1(double operand)
{
	m_lastOperand_1 = operand;
}

void Calculator::setOperand_2(double operand)
{
	m_lastOperand_2 = operand;
}

void Calculator::setOperator(Calculator::CalcOp op)
{
	m_lastOperator = op;
}

double Calculator::getOperand_1()
{
	return m_lastOperand_1;
}

double Calculator::getOperand_2()
{
	return m_lastOperand_2;
}

Calculator::CalcOp Calculator::getOperator()
{
	return m_lastOperator;
}