/*=============================================================================

  Library: CTK

  Copyright (c) German Cancer Research Center,
    Division of Medical and Biological Informatics

  Licensed under the Apache License, Version 2.0 (the "License");
  you may not use this file except in compliance with the License.
  You may obtain a copy of the License at

    http://www.apache.org/licenses/LICENSE-2.0

  Unless required by applicable law or agreed to in writing, software
  distributed under the License is distributed on an "AS IS" BASIS,
  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
  See the License for the specific language governing permissions and
  limitations under the License.

=============================================================================*/


#ifndef CTKDICOMHOSTSERVER_H
#define CTKDICOMHOSTSERVER_H

#include <QScopedPointer>

#include <org_commontk_dah_host_Export.h>

struct ctkDicomHostInterface;
class ctkDicomHostServerPrivate;

class org_commontk_dah_host_EXPORT ctkDicomHostServer
{

public:

  ctkDicomHostServer(ctkDicomHostInterface* hostInterface, int port, QString path);
  virtual ~ctkDicomHostServer();

private:

  Q_DECLARE_PRIVATE(ctkDicomHostServer)
  const QScopedPointer<ctkDicomHostServerPrivate> d_ptr;
};

#endif // CTKDICOMHOSTSERVER_H
