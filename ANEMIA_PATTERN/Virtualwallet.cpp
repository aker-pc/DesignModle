#include "Virtualwallet.h"

auto VirturalWalletService::genTransItem(double money, TransactionType type) -> void {
	VituralWalletTrans item;
	item.id = _trans.size();
	item.createTime = GetTickCount64();
	item.balance = money;
	item.type = type;
	_trans.push_back(item);
	return;
}

auto VirturalWalletService::pay(double money) -> void {
	_cash -= money;
	genTransItem(-money, TransactionType::CREDIT);
	return;
}

auto VirturalWalletService::withDrawal(double money) -> void {
	_cash += money;
	genTransItem(money, TransactionType::DEBIT);
	return;
}

auto VirturalWalletService::transfer(double money, bool isIn) -> void {
	isIn ? _cash += money : _cash -= money;
	isIn ? money = money : money = -money;
	genTransItem(money, TransactionType::TRANSFER);
	return;
}

auto VirturalWalletService::getTrans() -> void {
	std::cout << "||\tCreateTime\t||\tID\t||\tBalance\t||" << std::endl;
	for (const VituralWalletTrans& it : _trans) {
		std::cout << "||\t" << it.createTime << "\t||\t" << it.id << "\t||\t" << it.balance << "\t||" << std::endl;
	}
	return;
}

auto VirturalWalletService::getCash() -> double {
	std::cout << "Current wallet: " << _cash << std::endl;
	return _cash;
}

int main() {

	VirturalWalletService wallet;
	wallet.pay(1998);
	wallet.pay(2000);
	wallet.transfer(4000, true);
	wallet.withDrawal(3000);

	wallet.getCash();
	wallet.getTrans();

	return 0;
}