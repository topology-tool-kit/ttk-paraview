set(SOURCES
  avtMiliFileFormat.C
  avtMiliMetaData.C
  avtMiliOptions.C
  MiliPluginInfo.C
  MiliCommonPluginInfo.C
  MiliEnginePluginInfo.C
  )

ADD_VISIT_READER(VisItMiliReader "1.0"
  VISIT_READER_TYPE "MTMD"
  VISIT_READER_NAME "avtMiliFileFormat"
  VISIT_READER_USES_OPTIONS ON
  SERVER_SOURCES ${SOURCES}
  )
