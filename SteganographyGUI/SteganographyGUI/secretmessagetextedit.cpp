#include "secretmessagetextedit.hpp"

SecretMessageTextEdit::SecretMessageTextEdit(QWidget * parent) : QTextEdit(parent) {
	
}

SecretMessageTextEdit::~SecretMessageTextEdit() {
	
}

void SecretMessageTextEdit::sendTextSlot(void)
{
	emit sendTextSignal(QString(toPlainText()));
}

void SecretMessageTextEdit::sendUpdateSlot(void)
{
	emit sendUpdateSignal(QString(toPlainText()));
}
