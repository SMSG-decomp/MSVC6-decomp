long __imp_load__CoInitialize_4(void *pvReserved)

{
  code *UNRECOVERED_JUMPTABLE;
  long lVar1;
  
  UNRECOVERED_JUMPTABLE = __delayLoadHelper(&__DELAY_IMPORT_DESCRIPTOR_ole32,&CoInitialize_exref);
  lVar1 = (*UNRECOVERED_JUMPTABLE)();
  return lVar1;
}

