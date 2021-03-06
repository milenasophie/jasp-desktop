//
// Copyright (C) 2013-2020 University of Amsterdam
//
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU Affero General Public License as
// published by the Free Software Foundation, either version 3 of the
// License, or (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU Affero General Public License for more details.
//
// You should have received a copy of the GNU Affero General Public
// License along with this program.  If not, see
// <http://www.gnu.org/licenses/>.
//

#ifndef LISTMODELLABELVALUETERMS_H
#define LISTMODELLABELVALUETERMS_H

#include "listmodeltermsavailable.h"

class ListModelLabelValueTerms : public ListModelTermsAvailable
{
	Q_OBJECT
public:
	ListModelLabelValueTerms(QMLListView* listView);

	QVariant					data(const QModelIndex &index, int role = Qt::DisplayRole)	const override;

	void						readModelProperty(QMLListView* item)						override;

	std::vector<std::string>	getValues();
	QString						getValue(const QString& label);
	QString						getLabel(const QString& value);
	int							getIndexOfValue(const QString& value);

protected:

	QMap<QString, QString>		_valueToLabelMap;
	QMap<QString, QString>		_labelToValueMap;

};

#endif // LISTMODELLABELVALUETERMS_H
