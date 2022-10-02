#ifndef __Virtualwallet__
#define __Virtualwallet__

#include <iostream>
#include <vector>
#include <windows.h>

enum class TransactionType : int
{
	DEBIT,
	CREDIT,
	TRANSFER
};

class VituralWalletTrans {
public:
	VituralWalletTrans() {
		memset(this, 0, sizeof(VituralWalletTrans));
	};
	long id;
	long createTime;
	double balance;
	TransactionType type;
};

class VirturalWalletService {
public:
	VirturalWalletService(double cash = 10000.0) : _cash(cash) {}

	void pay(double money);				// 支付
	void withDrawal(double money);		// 提现
	void transfer(double money, bool isIn);		// 转账
	
	void getTrans();			// 查询流水
	double getCash();			// 查询余额

private:
	void genTransItem(double money, TransactionType type);	// 自动成成流水

	double _cash;		// 当前现金余额
	std::vector<VituralWalletTrans> _trans;		// 交易流水记录
};

#endif // !__source__