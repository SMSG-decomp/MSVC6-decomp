long __imp_load__CLSIDFromString_8(wchar_t *lpsz,void *pclsid)

{
  code *UNRECOVERED_JUMPTABLE;
  long lVar1;
  
  UNRECOVERED_JUMPTABLE = __delayLoadHelper(&__DELAY_IMPORT_DESCRIPTOR_ole32,&CLSIDFromString_exref)
  ;
  lVar1 = (*UNRECOVERED_JUMPTABLE)();
  return lVar1;
}

