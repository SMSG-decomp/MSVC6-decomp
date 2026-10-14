long __imp_load__LoadTypeLib_8(wchar_t *szFile,void **pptlib)

{
  code *UNRECOVERED_JUMPTABLE;
  long lVar1;
  
  UNRECOVERED_JUMPTABLE = __delayLoadHelper(&__DELAY_IMPORT_DESCRIPTOR_OLEAUT32,&LoadTypeLib_exref);
  lVar1 = (*UNRECOVERED_JUMPTABLE)();
  return lVar1;
}

