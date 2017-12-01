#pragma once
#include <QObject>

class charRemainingLabel : public QObject 
{
	Q_OBJECT

public:
	charRemainingLabel(QWidget * parent = Q_NULLPTR);
	~charRemainingLabel();

public slots:
	void updateCharsRemaining(std::string);

private:
	
};
