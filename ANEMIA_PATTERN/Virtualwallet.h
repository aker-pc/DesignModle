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

	void pay(double money);				// ֧��
	void withDrawal(double money);		// ����
	void transfer(double money, bool isIn);		// ת��
	
	void getTrans();			// ��ѯ��ˮ
	double getCash();			// ��ѯ���

private:
	void genTransItem(double money, TransactionType type);	// �Զ��ɳ���ˮ

	double _cash;		// ��ǰ�ֽ����
	std::vector<VituralWalletTrans> _trans;		// ������ˮ��¼
};

#endif // !__source__