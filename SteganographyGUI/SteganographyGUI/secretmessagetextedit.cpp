#include "secretmessagetextedit.hpp"

SecretMessageTextEdit::SecretMessageTextEdit(QWidget * parent) : QTextEdit(parent) {
	
}

SecretMessageTextEdit::~SecretMessageTextEdit() {
	
}

void SecretMessageTextEdit::sendTextSlot(void)
{
	// this lets the main window know to try to encode the message
	emit sendTextSignal(QString(toPlainText()));
}

void SecretMessageTextEdit::sendUpdateSlot(void)
{
	// this lets the main window know to update the character count
	emit sendUpdateSignal(QString(toPlainText()));
}
