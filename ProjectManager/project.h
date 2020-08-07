#pragma once

#include "page.h"

class Project : public PageMetaData
{
	static const QString m_path_to_project_meta_data;
	static const QString m_path_to_src;
	static const QString m_path_to_target_meta;

	QString m_name;
	QString m_path_to_project;
	std::vector<std::shared_ptr<Page>> m_pages;

public:
	Project(const QString&, const QString&);
	virtual ~Project();

	void setName(const QString&);
	std::shared_ptr<Page> addPage(const QString&);

	QString name() const;
	QString path() const;

	size_t size() const;
	std::shared_ptr<Page> getPage(size_t i) const;
	std::shared_ptr<Page> operator[](size_t) const;

	bool isOutDated() const;
	void updateMetaData() const;
	void saveMeta() const;
	void loadFromMeta();

	QString filePath(const QString&);

	void addFile(const QString&, const QByteArray&);
	void rmFile(const QString&);

	void addDirectory(const QString&);

private:
	virtual void dumpToFile(QFile&) const override;
};

