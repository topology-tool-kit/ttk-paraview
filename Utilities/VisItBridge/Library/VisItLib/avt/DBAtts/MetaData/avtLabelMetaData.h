// Copyright (c) Lawrence Livermore National Security, LLC and other VisIt
// Project developers.  See the top-level LICENSE file for dates and other
// details.  No copyright assignment is required to contribute to VisIt.

#ifndef AVTLABELMETADATA_H
#define AVTLABELMETADATA_H
#include <dbatts_exports.h>
#include <avtVarMetaData.h>


// ****************************************************************************
// Class: avtLabelMetaData
//
// Purpose:
//    Contains label metadata attributes
//
// Notes:      Autogenerated by xml2atts.
//
// Programmer: xml2atts
// Creation:   omitted
//
// Modifications:
//
// ****************************************************************************

class DBATTS_API avtLabelMetaData : public avtVarMetaData
{
public:
    // These constructors are for objects of this class
    avtLabelMetaData();
    avtLabelMetaData(const avtLabelMetaData &obj);
protected:
    // These constructors are for objects derived from this class
    avtLabelMetaData(private_tmfs_t tmfs);
    avtLabelMetaData(const avtLabelMetaData &obj, private_tmfs_t tmfs);
public:
    virtual ~avtLabelMetaData();

    virtual avtLabelMetaData& operator = (const avtLabelMetaData &obj);
    virtual bool operator == (const avtLabelMetaData &obj) const;
    virtual bool operator != (const avtLabelMetaData &obj) const;
private:
    void Init();
    void Copy(const avtLabelMetaData &obj);
public:

    virtual const std::string TypeName() const;
    virtual bool CopyAttributes(const AttributeGroup *);
    virtual AttributeSubject *CreateCompatible(const std::string &) const;
    virtual AttributeSubject *NewInstance(bool) const;

    // Property selection methods
    virtual void SelectAll();


    // Keyframing methods
    virtual std::string               GetFieldName(int index) const;
    virtual AttributeGroup::FieldType GetFieldType(int index) const;
    virtual std::string               GetFieldTypeName(int index) const;
    virtual bool                      FieldsEqual(int index, const AttributeGroup *rhs) const;

    // User-defined methods
    avtLabelMetaData(const std::string &, const std::string &, avtCentering);


private:
    // Static class format string for type map.
    static const char *TypeMapFormatString;
    static const private_tmfs_t TmfsStruct;
};
#define AVTLABELMETADATA_TMFS AVTVARMETADATA_TMFS ""

#endif
