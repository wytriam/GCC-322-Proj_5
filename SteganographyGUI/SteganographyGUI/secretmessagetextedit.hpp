#pragma once
#include <QTextEdit>

/*
	This class was used to promote the messagebox. 
	I mainly have it so I can send the contents of the messagebox to the MainWindow, 
	where the main window takes actions as appropriate. 
*/

class SecretMessageTextEdit : public QTextEdit {
	Q_OBJECT

public:
	SecretMessageTextEdit(QWidget * parent = Q_NULLPTR);
	~SecretMessageTextEdit();

public slots:
	// This is called when the Read button is pushed
	void sendTextSlot(void);
	// This is called whenever the contents are changed so the character count can be updated. 
	void sendUpdateSlot(void);

signals: 
	// This tells the main window the Read button has been pushed and the contents of the message box
	void sendTextSignal(QString);
	// This tells the main window the message box has been updated and the contents of the message box
	void sendUpdateSignal(QString);

private:
	
};
