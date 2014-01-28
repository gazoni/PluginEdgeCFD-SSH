#include "runedgecfd.h"
#include <QtGui/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	runEdgeCFD w;
	w.show();
	w.setFixedSize(w.size());
	return a.exec();
}
