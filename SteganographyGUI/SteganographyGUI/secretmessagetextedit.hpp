#pragma once
#include <QTextEdit>

class SecretMessageTextEdit : public QTextEdit {
	Q_OBJECT

public:
	SecretMessageTextEdit(QWidget * parent = Q_NULLPTR);
	~SecretMessageTextEdit();

public slots:
	void sendTextSlot(void);
	void sendUpdateSlot(void);

signals: 
	void sendTextSignal(QString);
	void sendUpdateSignal(QString);

private:
	
};
