/*=========================================================================

  Library:   CTK

  Copyright (c) PerkLab 2013

  Licensed under the Apache License, Version 2.0 (the "License");
  you may not use this file except in compliance with the License.
  You may obtain a copy of the License at

      http://www.apache.org/licenses/LICENSE-2.0.txt

  Unless required by applicable law or agreed to in writing, software
  distributed under the License is distributed on an "AS IS" BASIS,
  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
  See the License for the specific language governing permissions and
  limitations under the License.

=========================================================================*/

#ifndef __ctkDICOMDisplayedFieldGeneratorAbstractRule_h
#define __ctkDICOMDisplayedFieldGeneratorAbstractRule_h

// Qt includes
#include <QMap>
#include <QStringList>

// DCMTK includes
#include <dcmtk/dcmdata/dcdeftag.h>

#include "ctkDICOMCoreExport.h"

class ctkDICOMDatabase;

/// \ingroup DICOM_Core
///
/// Abstract base class for generating displayed fields from DICOM fields.
/// 
/// The displayed field generator classes need to be registered in \sa ctkDICOMDisplayedFieldGenerator
/// so that the rules it defines are taken into account when generating the displayed fields.
/// 
class CTK_DICOM_CORE_EXPORT ctkDICOMDisplayedFieldGeneratorAbstractRule
{
public:
  virtual ~ctkDICOMDisplayedFieldGeneratorAbstractRule(){}

  /// Generate displayed fields for a certain instance based on its cached tags
  /// Each rule plugin has the chance to fill any field in the series, study, and patient fields.
  /// The way these generated fields will be used is defined by \sa mergeDisplayedFieldsForInstance
  virtual void getDisplayedFieldsForInstance(const QMap<QString, QString> &cachedTagsForInstance, QMap<QString, QString> &displayedFieldsForCurrentSeries,
    QMap<QString, QString> &displayedFieldsForCurrentStudy, QMap<QString, QString> &displayedFieldsForCurrentPatient)=0;

  /// Define rules of merging initial database values with new values generated by the rule plugins
  /// Currently available options:
  /// - \sa mergeExpectSameValue Use the non-empty field value. If both initial and new are non-empty and different, then use the initial value
  /// - \sa mergeConcatenate Use the non-empty field value. If both initial and new are non-empty, then concatenate them using comma
  virtual void mergeDisplayedFieldsForInstance(
    const QMap<QString, QString> &initialFieldsSeries, const QMap<QString, QString> &initialFieldsStudy, const QMap<QString, QString> &initialFieldsPatient,
    const QMap<QString, QString> &newFieldsSeries, const QMap<QString, QString> &newFieldsStudy, const QMap<QString, QString> &newFieldsPatient,
    QMap<QString, QString> &mergedFieldsSeries, QMap<QString, QString> &mergedFieldsStudy, QMap<QString, QString> &mergedFieldsPatient,
    const QMap<QString, QString> &emptyFieldsSeries, const QMap<QString, QString> &emptyFieldsStudy, const QMap<QString, QString> &emptyFieldsPatient
    )=0;

  /// Specify list of DICOM tags required by the rule. These tags will be included in the tag cache
  virtual QStringList getRequiredDICOMTags()=0;

  /// Utility function to convert a DICOM tag enum to string
  static QString dicomTagToString(const DcmTagKey& tag)
  {    
    return QString("%1,%2").arg(tag.getGroup(),4,16,QLatin1Char('0')).arg(tag.getElement(),4,16,QLatin1Char('0'));
  }  

  /// Register placeholder strings that still mean that a given field can be considered empty.
  /// Used when merging the original database content with the displayed fields generated by the rules.
  /// Example: SeriesDescription -> Unnamed Series
  virtual void registerEmptyFieldNames(
    QMap<QString, QString> emptyFieldsSeries, QMap<QString, QString> emptyFieldsStudies, QMap<QString, QString> emptyFieldsPatients)=0;

  /// Utility function determining whether a given field is considered empty
  static bool isFieldEmpty(const QString &fieldName, const QMap<QString, QString> &fields, const QMap<QString, QString> &emptyValuesForEachField)
  {
    if (!fields.contains(fieldName))
    {
      // the field is not present
      return true;
    }
    if (fields[fieldName].isEmpty())
    {
      // the field is present, but empty
      return true;
    }
    if (emptyValuesForEachField[fieldName].contains(fields[fieldName]))
    {
      // the field is not empty, but contain a placeholder string (example: "No description") that means that the field is undefined
      return true;
    }
    // this field is non-empty
    return false;
  }

  /// Merge function that only uses the new value if the initial value is empty and vice versa
  static void mergeExpectSameValue(
    const QString &fieldName, const QMap<QString, QString> &initialFields, const QMap<QString, QString> &newFields,
    QMap<QString, QString> &mergedFields, const QMap<QString, QString> &emptyValuesForEachField )
  {
    if (isFieldEmpty(fieldName, newFields, emptyValuesForEachField))
    {
      // no new value is defined for this value, keep the initial value (if exists)
      if (!isFieldEmpty(fieldName, initialFields, emptyValuesForEachField))
      {
        mergedFields[fieldName]=initialFields[fieldName];
      }
      return;
    }
    if (isFieldEmpty(fieldName, initialFields, emptyValuesForEachField))
    {
      // no initial value is defined for this value, use just the new value (if exists)
      if (!isFieldEmpty(fieldName, newFields, emptyValuesForEachField))
      {
        mergedFields[fieldName]=newFields[fieldName];
      }
      return;
    }
    // both initial and new value are defined and they are different => just keep using the old value
    // TODO: log warning here, as this is not expected
    mergedFields[fieldName]=initialFields[fieldName];
  }

  /// Merge function that sets merged value as a concatenation of the initial and new values
  /// Individual values in the concatenation are separated by comma
  static void mergeConcatenate(
    const QString &fieldName, const QMap<QString, QString> &initialFields, const QMap<QString, QString> &newFields,
    QMap<QString, QString> &mergedFields, const QMap<QString, QString> &emptyValuesForEachField )
  {
    if (isFieldEmpty(fieldName, newFields, emptyValuesForEachField))
    {
      // no new value is defined for this value, keep the initial value (if exists)
      if (!isFieldEmpty(fieldName, initialFields, emptyValuesForEachField))
      {
        mergedFields[fieldName]=initialFields[fieldName];
      }
      return;
    }
    if (isFieldEmpty(fieldName, initialFields, emptyValuesForEachField))
    {
      // no initial value is defined for this value, use just the new value (if exists)
      if (!isFieldEmpty(fieldName, newFields, emptyValuesForEachField))
      {
        mergedFields[fieldName]=newFields[fieldName];
      }
      return;
    }
    if (initialFields[fieldName].contains(newFields[fieldName]))
    {
      // the field is already contained in the list, so no need to add it
      mergedFields[fieldName]=initialFields[fieldName];
      return;
    }
    // need to concatenate the new value to the initial
    mergedFields[fieldName]=initialFields[fieldName]+", "+newFields[fieldName];
  }

};

#endif
